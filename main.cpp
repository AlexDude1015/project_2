//
// Created by Alexander Li on 11/10/24.
//
#include "shared_libraries.h"

int main()
{
    const int ARRAY_SIZE = 4;
    std::unique_ptr<My_grade[]> grades = std::make_unique<My_grade[]>(ARRAY_SIZE);
    bool exit = false;
    bool enter_grade = false;

    while(!exit)
    {
        Option choice = Menu::print_main_menu();
        if (choice != Option::exit)
        {
            if(!enter_grade)
            {
                Menu::input_grades(grades, ARRAY_SIZE);
                enter_grade = true;
            }
            Menu::execute(choice, grades, ARRAY_SIZE);
            exit = Menu::if_exit();
        }
        else
        {
            exit = true;
        }
    }

    return 0;
}


