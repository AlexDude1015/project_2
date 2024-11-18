//
// Created by Alexander Li on 11/17/24.
//
#include "shared_libraries.h"

namespace Sub_menu
{
    void print_required_assignment_scores_for_ungraded_assignments(const std::unique_ptr<my_grade[]>& grades, int const SIZE)
    {
        double ratio = Calculate::get_required_ratio_for_ungraded_assignments(grades, SIZE, 0.9);
        std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << "║ To get an A, this is the average score you will need for all your      ║\n";
        std::cout << "║ ungraded assignments:                                                  ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        for (int i = 0; i < SIZE; i++)
        {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2) << grades[i].category.name << ": " << ratio * grades[i].category.value << "/" << grades[i].category.value;
            std::cout << "║ " << std::left << std::setw(71) << stream.str() << "║" <<  std::endl;
        }

    }

    void print_required_assignment_scores_for_future_assignments(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double ratio = Calculate::get_required_ratio_for_future_assignments(grades, SIZE, 0.9);
        std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << "║ To get an A, this is the average score you will need for all your      ║\n";
        std::cout << "║ ungraded and future assignments:                                       ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        for (int i = 0; i < SIZE; i++)
        {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2) << grades[i].category.name << ": " << ratio * grades[i].category.value << "/" << grades[i].category.value;
            std::cout << "║ " << std::left << std::setw(71) << stream.str() << "║" <<  std::endl;
        }
    }

    void print_current_grade(const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << "║ Grades Entered:                                                        ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        for (int i = 0; i < SIZE; i++)
        {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2) <<  grades[i].category.name << ": " << grades[i].current_points << "/" << grades[i].max_points;
            std::cout << "║ " << std::setw(72) << stream.str() << "║\n";
        }
        std::ostringstream final_grade;
        final_grade << std::fixed << std::setprecision(2) << "Current grade: " << Calculate::get_current_grade(grades, SIZE) << "%";
        std::cout << "║ " << std::setw(72) << final_grade.str() << "║\n";
    }

    void print_more_info()
    {
        std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << "║ Definitions                                                            ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        std::cout << "║ Ungraded assignments is the work that has been turned in but remains   ║\n";
        std::cout << "║ ungraded                                                               ║\n";
        std::cout << "║                                                                        ║\n";
        std::cout << "║ Projected assignments are assignments that might be issued in the      ║\n";
        std::cout << "║ future. It estimates that based on a the rate of previous tweets,      ║\n";
        std::cout << "║ class activities, projects, and homework.                              ║\n";
        std::cout << "║                                                                        ║\n";
    }
}




