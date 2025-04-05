//============================================================================
// Name        : Reminders.cpp
// Author      : Aracely
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Date.h"
using namespace std;
#include "Reminder.h"
Date date_from_string(string date_str);
bool is_leap_year(int year);
void showOptions(vector<string> options);
string getOption(vector<string> options);
bool contains(vector<string> options, string s);



int main() {
    ifstream file("storage.txt");
    string option = "";
    //while (option != "exit"){
//        cout << "View Reminders" << "\n";
//        cout << "Add a Reminder" << "\n";
//        cout << "Remove a Reminder" << "\n";
//    }
    vector<string> options;
    options.push_back("View Reminders");
    options.push_back("Add a Reminder");
    options.push_back("Remove a Reminder");
    options.push_back("Exit");

    cout << "Reminders App" << "\n\n";
    cout << "These are your options: " << "\n";
    showOptions(options);

    while (option != "Exit"){
        option = getOption(options);
        if (option == "View Reminders"){
            //print contents of storage.txt
            ifstream file("storage.txt");
            string str;
            while (getline(file, str)){
                //reminders.push_back();
                cout << str << "\n";

            }
            file.close();


        }
        if (option == "Add a Reminder"){
            cout << "Enter a day for the reminder (mm/dd/yyyy): ";
            char input[256];
            cin.getline (input, 256);
            string date_str(input);
            Date date = date_from_string(date_str);
            //cout << date.as_string();
            cout << "Enter text for the reminder: ";
            char reminder_text[256];
            cin.getline (reminder_text, 256);
            string reminder_str(reminder_text);
            Reminder new_reminder(date, reminder_str);
            //store text file as vector in reminders
            vector<Reminder> current_reminders;
            ifstream file("storage.txt");
            string str;
            int index = 0;


            while (getline(file, str)){
                string line_date_str = str.substr(0,10);
                string line_reminder_str = str.substr(12);
                Date line_date = date_from_string(line_date_str);
                Reminder line_reminder(line_date, line_reminder_str);
                current_reminders.push_back(line_reminder);
                if(date.days_since_2021() >= line_date.days_since_2021()){
                    index++;
                    //https://thispointer.com/c-how-to-insert-element-in-vector-at-specific-position-vectorinsert-examples/

                }
            }
            file.close();

            current_reminders.insert(current_reminders.begin()+ index, new_reminder);

            ofstream file2;
            file2.open("storage.txt");
            for(Reminder r : current_reminders){
                string new_line = r.date.as_string() + ": " + r.text;
                file2 << new_line <<  "\n";
            }
            file2.close();
        }
        if(option == "Remove a Reminder"){
            ifstream file("storage.txt");
            string str;
            int counter = 1;
            vector<string> oldReminders;
            while (getline(file, str)){
                oldReminders.push_back(str);
                cout<< counter << ". " << str << "\n";
                counter ++;

            }
            file.close();
            cout << "Which reminder would you like to remove? If not, type 0 : " ;
            int choice;
            char option[256];
            cin.getline (option, 256);
            choice = stoi(option);
            while(choice >= counter || choice < 0){
                cout << "Must be a number between 0 and " << counter - 1 << ". Try again: ";
                char option[256];
                cin.getline (option, 256);
                choice = stoi(option);
            }
            if(choice > 0){
                cout << oldReminders[choice - 1] << "\n";
                cout << "Are you sure you want to delete this reminder? ";
                char option[256];
                cin.getline (option, 256);
                if(string(option) == "yes"){
                    oldReminders.erase(oldReminders.begin() + choice - 1);
                    ofstream file2("storage.txt");
                    for (string s: oldReminders){
                        file2 << s << "\n";
                    }
                    file2.close();
                }else{
                    cout << "No reminders removed" << "\n";
                }
            }else{
                cout << "No reminders removed" << "\n";
            }
        }

    }
}

//return date from a string.
Date date_from_string(string date_str){
    string month_str = date_str.substr(0,2);
    string day_str = date_str.substr(3, 2);
    string year_str = date_str.substr(6, 4);

    int month = stoi(month_str);
    int day = stoi(day_str);
    int year = stoi(year_str);

    return Date(month, day, year);

}




bool is_leap_year(int year){
    //year = leap year if multiple 4, except multiple of 100, aren't multiple of 400
    return (year % 4 == 0) && (year % 100 !=  0 || year % 400 == 0);

}
void showOptions(vector<string> options) {
  for (string option : options) {
    // cout option
    cout << option << "\n";
  }
}

// a function which determines if a given item is contained in the given vector
bool contains(vector<string> options, string s) {
  // should return true if s in options, false otherwise
  // hint: use a for loop
  for(string option : options){
    if(option == s){
      return true;
    }
  }
  return false;
}

// a function which takes a vector of options and asks what the player wants to do and doesn't return the option until the player selects one of the given options
string getOption(vector<string> options) {
  // Hint: use a while loop
  cout << "> ";
  // string option;
  char option[256];
  cin.getline (option, 256);


  while(!contains(options, option)) {
    cout << option << " is not an option, your options are \n";
    showOptions(options);
    cout << "> ";
   // char option[256];
    //cin.ignore(10000, '\n');
    cin.getline (option, 256);

  }
  return option;
}
