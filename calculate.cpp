//
// Created by Alexander Li on 11/16/24.
//
#include "shared_libraries.h"

namespace Calculate
{
    //Returns the user's grade percentage * 100
    double get_current_grade(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double total_earned = 0;
        double total_available = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total_earned += grades[i].current_points;
            total_available += grades[i].max_points;
        }
        return total_earned / total_available * 100;
    }

    //Returns the sum of your points across all categories of assignments
    double add_all_earned_points(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double total_earned = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total_earned += grades[i].current_points;
        }
        return total_earned;
    }

    //Returns the total points available across all categories of assignments
    double add_all_available_points(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double total_available = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total_available += grades[i].max_points;
        }
        return total_available;
    }

    //Returns the total projected points available across all categories of assignments
    double add_all_projected_available_points(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double total_available = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total_available += grades[i].category.projected_quantity * grades[i].category.value;
        }
        return total_available;
    }

    //Returns the total ungraded points available across all categories of assignments
    double add_all_ungraded_available_points(const std::unique_ptr<my_grade[]>& grades, int SIZE)
    {
        double total_ungraded = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total_ungraded += grades[i].category.quantity * grades[i].category.value;
        }
        return total_ungraded - add_all_available_points(grades, SIZE);
    }

    //Calculates the required score for subsequent assignments and returns a ratio. (Ratio * Max Pointers = Required Grade for A)
    double get_required_ratio_for_future_assignments(const std::unique_ptr<my_grade[]>& grades, const int SIZE, double letter_grade)
    {
        double earned_points = add_all_earned_points(grades, SIZE);
        double available_points = add_all_available_points(grades, SIZE);
        double projected_available_points = add_all_projected_available_points(grades, SIZE);
        return ((projected_available_points - available_points) * letter_grade - earned_points) / (projected_available_points - 2 * available_points);
    }

    //Calculates the required score for ungraded assignments and returns a ratio.
    double get_required_ratio_for_ungraded_assignments(const std::unique_ptr<my_grade[]>& grades, const int SIZE, double letter_grade)
    {
        double earned_points = add_all_earned_points(grades, SIZE);
        double available_points = add_all_available_points(grades, SIZE);
        double ungraded_points = add_all_ungraded_available_points(grades, SIZE);
        return ((ungraded_points - available_points) * letter_grade - earned_points) / (ungraded_points - 2 * available_points);
    }

}
