/*
 * Filename: membership.cpp
 */
#include "membership.h"

Membership::Membership() : bday() {
    name = "No name";
    price = 0;
}

Membership::Membership(const QString &theName, const QDate &theBday) : start(), end() {
    name = theName;
    bday = theBday;
    price = 0;
}

QString Membership::getName() const {
    return name;
}

QDate Membership::getBday() const {
    return bday;
}

void Membership::getTime(QTime & theStart, QTime & theEnd) const {
    theStart = start;
    theEnd = end;
}

double Membership::getPrice() const {
    return price;
}
