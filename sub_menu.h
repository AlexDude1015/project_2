//
// Created by Alexander Li on 11/17/24.
//

#ifndef SUB_MENU_H
#define SUB_MENU_H
#include "shared_libraries.h"

namespace Sub_menu
{
    void print_required_assignment_scores_for_future_assignments(const std::unique_ptr<my_grade[]>& grades, int SIZE);
    void print_required_assignment_scores_for_ungraded_assignments(const std::unique_ptr<my_grade[]>& grades, int SIZE);
    void print_current_grade(const std::unique_ptr<my_grade[]>& grades, int SIZE);
    void print_more_info();
}


#endif //SUB_MENU_H
