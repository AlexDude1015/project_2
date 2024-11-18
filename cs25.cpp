//
// Created by Alexander Li on 11/16/24.
//
#include "shared_libraries.h"

namespace Cs25
{
    //Creates weights specifically for cs25
    Category build_weights(const Weight& weight)
    {
        switch(weight)
        {
            case Weight::tweet:
                return get_weights("Tweet");
            case Weight::class_activity:
                return get_weights("Class Activity");
            case Weight::project:
                return get_weights("Project");
            case Weight::homework:
                return get_weights("Homework");

            default: throw std::invalid_argument("Invalid weight");
        }
    }

    //Extracts weights from cs25_weights.txt
    Category get_weights(const std::string &target)
    {
        Category category;
        std::ifstream file("../cs25_weights.txt");

        //Checks if the file is open
        if (!file.is_open())
        {
            throw std::invalid_argument("Failed to open cs25_weights.txt");
        }

        //Extracts content
        std::string entry;
        while (std::getline(file, entry, ','))
        {
            if (entry == target)
            {
                std::string temp;
                category.name = entry;

                std::getline(file, temp, ',');
                category.value = std::stod(temp);

                std::getline(file, temp, ',');
                category.quantity = std::stod(temp);


                std::getline(file, temp, ',');
                category.projected_quantity = std::stod(temp);

                break;
            }
        }
        file.close();

        //Checks if the entries are correct
        if (category.name.empty())
        {
            std::stringstream error_stream;
            error_stream << "Weights not found for " << target;
            throw std::invalid_argument(error_stream.str());
        }

        return category;
    }



}