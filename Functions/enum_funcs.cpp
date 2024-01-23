#include <iostream>
#include "enum_classes.h"


std::string_view month_to_string(Month month) {
    switch (month) {
        using enum Month;
        case Jan : return "January";
        case Feb : return "February";
        case Mar : return "March";
        case Apr : return "April";
        case May : return "May";
        case Jun : return "June";
        case Jul : return "July";
        case Aug : return "August";
        case Sep : return "September";
        case Nov : return "November";
        case Dec : return "December";
    }
}