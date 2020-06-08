/*
 * Filename: mainwindow.h
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "membership.h"
#include "premium.h"
#include "daily.h"
#include "classic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum Types { NoneType, ClassicType, DailyType, PremiumType, AmountOfTypes };
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cancel_clicked();

    void on_create_clicked();

    void on_name_textChanged(const QString &arg1);

    void on_date_userDateChanged(const QDate &date);
    void typeChosen();

private:
    enum {Client, AmountOfAccounts};
    Membership * basic[AmountOfAccounts];
    Types type;
    QString name;
    QDate date;
    double price;
    int amount;
    Daily::Workout plan;

    bool isCorrectDate;
    bool isChosenType;
    bool isCorrectName;
    bool checkName(const QString & name) const;
    void defineType();
    void changeBasic();
    void refresh() const;
    void fillTable() const;
    void fillPrice() const;
    void fillTime() const;
    void fillAmount() const;
    void fillPlan() const;
    void showSuccess() const;
    void showFailure();
    void highlightIncorrect(QWidget * widget) const;
    void highlightCorrect(QWidget * widget) const;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
