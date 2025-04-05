
/*
 * Date.cpp
 *
 *      Author: aracelyalvarenga
 */

#include "Date.h"
//#include "Reminders.cpp"
bool is_leap_year(int year);

Date::Date(int new_month, int new_day, int new_year)
: month(new_month), day(new_day), year(new_year) {

}

int Date::days_since_2021(){
    //returns days since 2021
    int days = 0;
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //for loop for years
    //countdown to days


    for (int y = 2021; y < year; y++){
        if (is_leap_year(y)){
            days += 366;
        }else{
            days += 365;
        }
    }
    for (int m = 1; m < month; m ++){
        if (m == 2 && is_leap_year(year)){
            days += 1;
        }
        days += month_days[m - 1];
    }
    days += day - 1;
    return days;
}

std::string Date::as_string(){
    std::string result = "";
    if (month < 10){
        result += "0";
    }
    result += std::to_string(month);

    result  += "/";

    if (day < 10){
        result += "0";
    }
    result += std::to_string(day);

    result += "/";

    result += std::to_string(year);

    return result;
}

