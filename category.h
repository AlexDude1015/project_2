//
// Created by Alexander Li on 11/16/24.
//

#ifndef CATEGORY_H
#define CATEGORY_H
#include "shared_libraries.h"

struct category
{
    //Name of the category
    std::string name;
    //The max points given for each assignment
    double value;
    //The amount of assignments of this type that have been issued
    double quantity;
    //The estimated amount of assignments by the end of the semester
    double projected_quantity;
};

#endif //CATEGORY_H
