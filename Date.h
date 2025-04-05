/*
 * Date.h
 *
 *      Author: aracelyalvarenga
 */
#include <string>


#ifndef DATE_H_
#define DATE_H_

class Date {
    public:
    int month;
    int day;
    int year;

    Date(int month, int day, int year);
    int days_since_2021();

    std::string as_string();
};

#endif /* DATE_H_ */
