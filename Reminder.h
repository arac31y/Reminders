/*
 * Reminder.h
 *
 *      Author: aracelyalvarenga
 */

#ifndef REMINDER_H_
#define REMINDER_H_
#include <iostream>
using namespace std;
#include "Date.h"

class Reminder {
public:
    Date date;
    string text;

    Reminder(Date new_date, string new_text);
};

#endif /* REMINDER_H_ */
