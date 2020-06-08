/*
 * Filename: classic.cpp
 */
#include "classic.h"

void Classic::setTime() {
    QTime tempStart(16, 0);
    QTime tempEnd(22, 0);
    start = tempStart;
    end = tempEnd;
}

void Classic::setPrice() {
    price = 1000;
}

Classic::Classic() : Membership() {
    teammates = 4;
    setTime();
    setPrice();
}

Classic::Classic(const QString &theName, const QDate &theBday, int amount)
    : Membership(theName, theBday)
{
    teammates = amount;
    setTime();
    setPrice();
}

int Classic::getAmount() const {
    return teammates;
}
