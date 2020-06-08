/*
 * Filename: mainwindow.cpp
 */
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    basic[Client] = nullptr;
    type = NoneType;
    name = "No Name";
    QDate tempDate;
    date = tempDate;
    amount = 0;
    price = 0;
    isChosenType = isCorrectDate = isCorrectName = false;
    QCheckBox * typeAccount[AmountOfTypes - 1] = {ui->classic, ui->daily, ui->premium };
    for(int i = 0; i < AmountOfTypes - 1; ++i)
        connect(typeAccount[i], SIGNAL(toggled(bool)), this, SLOT(typeChosen()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_name_textChanged(const QString &theName) {
    QString temp = theName;
    isCorrectName = checkName(theName);
    if(isCorrectName) {
        name = theName;
        highlightCorrect(ui->name);
    }
    else {
        highlightIncorrect(ui->name);
    }
}
void MainWindow::on_date_userDateChanged(const QDate &theDate) {
    date = theDate;
    highlightCorrect(ui->date);
}

void MainWindow::typeChosen() {
    isChosenType = true;
    defineType();
    changeBasic();
    refresh();
    highlightCorrect(ui->membership);
}
void MainWindow::on_cancel_clicked() {
    close();
}

void MainWindow::on_create_clicked() {
    if(isChosenType && isCorrectName && isChosenType) {
        showSuccess();
        close();
    }
    else {
        if(!isChosenType) {
           highlightIncorrect(ui->membership);
        }
        if(!isCorrectName) {
            highlightIncorrect(ui->name);
        }
        if(!isCorrectName) {
            highlightIncorrect(ui->date);
        }
    }
}

void MainWindow::changeBasic() {
    switch(type) {
     case ClassicType: {
        Classic * classic = new Classic(name, date);
        amount = classic->getAmount();
        basic[Client] = classic;
        break;
     }
     case DailyType: {
        Daily * daily = new Daily(name, date);
        plan = daily->getPlan();
        basic[Client] = daily;
        break;
     }
     case PremiumType: {
        Premium * premium = new Premium(name, date);
        amount = premium->getAmount();
        plan = premium->getPlan();
        basic[Client] = premium;
        break;
     }
     default:
        break;
     }
}

void MainWindow::refresh() const {
    fillTable();
    fillPrice();
    fillTime();
    fillPlan();
    fillAmount();
}

void MainWindow::fillTable() const {
    QTableWidgetItem * aerobics = new QTableWidgetItem;
    QTableWidgetItem * polo = new QTableWidgetItem;
    switch(type) {
    case ClassicType:
        aerobics->setText("Ні");
        polo->setText("Так");
        break;
    case DailyType:
        polo->setText("Ні");
        aerobics->setText("Так");
        break;
    case PremiumType:
        polo->setText("Так");
        aerobics->setText("Так");
        break;
    default:
        break;
    }
    ui->table->setItem(0, 0, aerobics);
    ui->table->setItem(0, 1, polo);

}

void MainWindow::fillPrice() const {
    QString priceString;
    double tempPrice = basic[Client]->getPrice();
    priceString = QString::number(tempPrice) + " грн";
    ui->price->setText(priceString);
}

void MainWindow::fillTime() const {
    QString timeString;
    QTime tempStart;
    QTime tempEnd;
    basic[Client]->getTime(tempStart, tempEnd);
    timeString = tempStart.toString("hh.mm") + " - " + tempEnd.toString("hh.mm");
    ui->time->setText(timeString);
}

void MainWindow::fillAmount() const {
    QString amountString = "-";
    if(dynamic_cast<Classic *>(basic[Client])) {
        amountString = QString::number(amount);
    }
    ui->team->setText(amountString);
}

void MainWindow::fillPlan() const {
    QString planString = "-";
    if(dynamic_cast<Daily *>(basic[Client])) {
        switch(plan) {
        case Daily::Kid:
            planString = "Дитячий";
            break;
        case Daily::Adult:
            planString = "Дорослий";
            break;
        case Daily::Old:
            planString = "Пенсійний";
            break;
        default:
            planString = "-";
            break;
        }
    }
    ui->plan->setText(planString);
}

void MainWindow::showSuccess() const {
    QMessageBox box;
    QDate today = QDate::currentDate();
    QDate tomorrow = today.addDays(1);
    QIcon icon("theater.png");
    QPixmap image("snorkeling.png", "PNG", Qt::ColorOnly);
    box.setWindowIcon(icon);
    box.setIconPixmap(image);
    box.setWindowTitle("Абонемент створено");
    box.setText("Чекаємо на вас " + tomorrow.toString("dddd MMMM d"));
    box.exec();

}

void MainWindow::highlightIncorrect(QWidget *widget) const {
    widget->setStyleSheet("font: 12pt \"Segoe UI\";"
                          "background-color: rgb(255, 170, 127);");
}

void MainWindow::highlightCorrect(QWidget *widget) const {
    widget->setStyleSheet("font: 12pt \"Segoe UI\";"
                          "background-color: rgb(170, 255, 127);");
}

bool MainWindow::checkName(const QString &name) const {
    QString temp = name;
    QStringList fullName = temp.split(' ', QString::SkipEmptyParts);
    const int amountOfNames = 3;

    if(fullName.size() != amountOfNames)
        return false;
    if(temp.isEmpty())
        return false;
    for(int i = 0; i < temp.length(); ++i) {
        if(!temp[i].isLetter() && temp[i] != '-' && !temp[i].isSpace()) {
            return false;
        }
    }
    return true;
}

void MainWindow::defineType() {
    if(ui->classic->isChecked()) {
        type = ClassicType;
    }
    else if(ui->daily->isChecked()) {
        type = DailyType;
    }
    else {
        type = PremiumType;
    }
}


