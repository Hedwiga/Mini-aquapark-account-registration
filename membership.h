/*
 * Filename: membership.h
 */

#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <QString>
#include <QStringList>
#include <QDate>

class Membership
{
private:
    QString name;
    QDate bday;
protected:
    double price;
    QTime start;
    QTime end;
    virtual void setTime() = 0;
    virtual void setPrice() = 0;
public:
    Membership();
    Membership(const QString & theName, const QDate & theBday);
    virtual ~Membership() {}
    void getTime(QTime & theStart, QTime & theEnd) const;
    QString getName() const;
    QDate getBday() const;
    double getPrice() const;
};

#endif // MEMBERSHIP_H
