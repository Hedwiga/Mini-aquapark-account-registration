/*
 * Filename: premium.cpp
 */
#include "premium.h"

void Premium::setTime(){
    QTime tempStart(10, 0);
    QTime tempEnd(22, 0);
    start = tempStart;
    end = tempEnd;
}

void Premium::setPrice() {
    price = 1200;
}

Premium::Premium() : Membership(), Classic(), Daily() {
   setTime();
   setPrice();
}

Premium::Premium(const QString &theName, const QDate &theBday, int amount)
    : Membership(theName, theBday), Classic(theName, theBday, amount),
      Daily(theName, theBday)
{
    setTime();
    setPrice();
}
