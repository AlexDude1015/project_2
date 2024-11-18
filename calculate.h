//
// Created by Alexander Li on 11/16/24.
//

#ifndef CALCULATE_H
#define CALCULATE_H
#include "shared_libraries.h"

//Math calculation functions
namespace Calculate
{
    double get_current_grade(const std::unique_ptr<My_grade[]>& grades, int SIZE);
    double add_all_earned_points(const std::unique_ptr<My_grade[]>& grades, int SIZE);
    double add_all_available_points(const std::unique_ptr<My_grade[]>& grades, int SIZE);
    double add_all_projected_available_points(const std::unique_ptr<My_grade[]>& grades, int SIZE);
    double get_required_ratio_for_future_assignments(const std::unique_ptr<My_grade[]>& grades, int SIZE, double letter_grade);
    double add_all_ungraded_available_points(const std::unique_ptr<My_grade[]>& grades, int SIZE);
    double get_required_ratio_for_ungraded_assignments(const std::unique_ptr<My_grade[]>& grades, int SIZE, double letter_grade);

}

#endif //CALCULATE_H
