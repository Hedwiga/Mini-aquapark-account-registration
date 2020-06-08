/*
 * Filename: daily.cpp
 */
#include "daily.h"

void Daily::setTime() {
    QTime tempStart(10, 0);
    QTime tempEnd(16, 0);
    start = tempStart;
    end = tempEnd;
}

void Daily::setPrice() {
    price = 800;
}

Daily::Workout Daily::definePlan() const {
    Workout curPlan;
    QDate curDate = QDate::currentDate();
    int curYear = curDate.year();
    int clientYear = this->getBday().year();
    int age = curYear - clientYear;
    if(age < 18) {
        curPlan = Kid;
    }
    else if(age < 60) {
        curPlan = Adult;
    }
    else {
        curPlan = Old;
    }
    return curPlan;
}

Daily::Daily() {
    plan = None;
    setTime();
    setPrice();
}
Daily::Daily(const QString &theName, const QDate &theBday)
    : Membership(theName, theBday)
{
    plan = definePlan();
    setTime();
    setPrice();
}

Daily::Workout Daily::getPlan() const {
    return plan;
}
