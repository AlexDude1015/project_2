//
// Created by Alexander Li on 11/16/24.
//

#ifndef MENU_H
#define MENU_H
#include "options.h"

namespace Menu
{

    Option print_main_menu();
    Option int_to_option(int choice);
    void input_grades(std::unique_ptr<my_grade[]>& grades, int SIZE);
    void execute(const Option& option, const std::unique_ptr<my_grade[]>& grades, int SIZE);
    bool if_exit();
    //double input_desired_letter_grade();
}

#endif //MENU_H
