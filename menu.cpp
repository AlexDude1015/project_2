//
// Created by Alexander Li on 11/16/24.
//

#include "shared_libraries.h"

namespace Menu
{
    //Prints the main menu and returns the user's choice
    Option print_main_menu()
    {
        int choice;
        std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        std::cout << "║ Grade Calculator                                                       ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        std::cout << "║ This program calculates the minimum grades that your future            ║\n";
        std::cout << "║ assignments need to be to get the grade you want.                      ║\n";
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        std::cout << "║ 1) View minimum average grade of my ungraded assignments               ║\n";
        std::cout << "║ 2) View minimum average grade of all future assignments                ║\n";
        std::cout << "║ 3) View current grade                                                  ║\n";
        std::cout << "║ 4) More info                                                           ║\n";
        std::cout << "║ 5) Exit                                                                ║\n";
        std::cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
        std::cout << "Choose an option (enter a number): \n";
        std::cin >> choice;
        std::cin.ignore();
        return int_to_option(choice);
    }

    //Receives a menu option and executes the proper functions.
    void execute(const Option& option, const std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        switch (option)
        {
            case Option::view_ungraded_requirement:
                Sub_menu::print_required_assignment_scores_for_ungraded_assignments(grades, SIZE);
                break;
            case Option::view_projected_requirement:
                Sub_menu::print_required_assignment_scores_for_future_assignments(grades, SIZE);
                break;
            case Option::view_current_grade:
                Sub_menu::print_current_grade(grades, SIZE);
                break;
            case Option::more_info:
                Sub_menu::print_more_info();
                break;
            default:
                throw std::invalid_argument("Invalid option");
        }
    }

    //Converts an integer to the scoped enum Option
    Option int_to_option(const int choice)
    {
        switch (choice)
        {
            case 1:
                return Option::view_ungraded_requirement;
            case 2:
                return Option::view_projected_requirement;
            case 3:
                return Option::view_current_grade;
            case 4:
                return Option::more_info;
            case 5:
                return Option::exit;
            default:
                throw std::invalid_argument("Invalid option");
        }
    }



    //Prompts users to input their current grades, and stores them in a unique pointer array
    void input_grades(std::unique_ptr<my_grade[]>& grades, const int SIZE)
    {
        double earned_grade;
        double max_grade;
        Weight weight = tweet;
        std::vector<std::string> weight_names = {"Tweets", "Class Activities", "Projects", "Homework Assignments"};

        for (int i = 0; i < SIZE; i++)
        {
            //Gets tweet score
            std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
            std::ostringstream stream;
            stream << " How many points did you receive from all of your " << weight_names[i] << "?";
            std::cout << "║" << std::left << std::setw(72) << stream.str() << "║\n";
            std::cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
            std::cout << "Enter your points: ";
            std::cin >> earned_grade;
            std::cin.ignore();

            std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
            std::cout << "║ What was the maximum points you could have received?                   ║\n";
            std::cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
            std::cout << "Enter the max: ";
            std::cin >> max_grade;
            std::cin.ignore();

            grades[weight + i] = {Cs25::build_weights(static_cast<Weight>(weight + i)), earned_grade, max_grade};
        }
    }

    //Asks if the user wants to return to menu or exit. Used for every sub menu.
    bool if_exit()
    {
        int choice;
        std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
        std::cout << "║ 1) Back to menu                                                        ║\n";
        std::cout << "║ 2) Exit                                                                ║\n";
        std::cout << "╚════════════════════════════════════════════════════════════════════════╝\n";

        while(true)
        {
            std::cout << "Choose an option: ";
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1)
            {
                return false;
            }
            if (choice == 2)
            {
                return true;
            }
            else
            {
                std::cout << "Invalid choice, please try again.";
            }
        }


        /*Lets user decide letter grade, but everyone wants an A so it's useless
         double input_desired_letter_grade()
        {
            char letter_grade;
            std::cout << std::endl;
            std::cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
            std::cout << "║ What letter grade would you like?                                      ║\n";
            std::cout << "╠════════════════════════════════════════════════════════════════════════╣\n";
            std::cout << "║ A                                                                      ║\n";
            std::cout << "║ B                                                                      ║\n";
            std::cout << "║ C                                                                      ║\n";
            std::cout << "║ D                                                                      ║\n";
            std::cout << "║ F                                                                      ║\n";
            std::cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
            std::cout << " Enter your choice: ";
            std::cin >> letter_grade;
            std::cin.ignore();


            switch (letter_grade)
            {
                case 'A':
                    case 'a':
                return 0.9;

                case 'B':
                    case 'b':
                return 0.8;

                case 'C':
                    case 'c':
                return 0.7;

                case 'D':
                    case 'd':
                return 0.6;

                case 'F':
                    case 'f':
                return 0.5;

                default: throw std::invalid_argument("Invalid letter grade");
            }
        }
        */

    }
}
