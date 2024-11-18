//
// Created by Alexander Li on 11/16/24.
//
#include "shared_libraries.h"

namespace Cs25
{
    //Creates weights specifically for cs25
    category build_weights(const Weight& weight)
    {
        switch(weight)
        {
            case Weight::tweet:
                return {"Tweet", 2, 10, 14};
            case Weight::class_activity:
                return {"Class Activity", 2, 30, 42};
            case Weight::project:
                return {"Project", 100, 2, 3};
            case Weight::homework:
                return {"Homework", 10, 2, 3};

            default: throw std::invalid_argument("Invalid weight");
        }
    }




}