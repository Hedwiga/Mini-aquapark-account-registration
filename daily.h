/*
 * Filename: daily.h
 */

#ifndef DAILY_H
#define DAILY_H

#include "membership.h"

class Daily : virtual public Membership
{
public:
    enum Workout { None, Kid, Adult, Old };
protected:
    virtual void setTime();
    virtual void setPrice();
private:
    Workout plan;
    Workout definePlan() const;
public:
    Daily();
    virtual ~Daily() {};
    Daily(const QString &theName, const QDate &theBday);
    Workout getPlan() const;
};

#endif // DAILY_H
