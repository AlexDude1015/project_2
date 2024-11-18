//
// Created by Alexander Li on 11/16/24.
//

#ifndef MY_GRADE_H
#define MY_GRADE_H
#include "shared_libraries.h"

struct my_grade
{
    //Assignment category
    category category;
    //The current aggregate graded points of a category
    double current_points = -1;
    //The maximum graded points that could be earned
    double max_points = -1;
};

#endif //MY_GRADE_H
