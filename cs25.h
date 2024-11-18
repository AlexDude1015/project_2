//
// Created by Alexander Li on 11/16/24.
//

#ifndef CS25_H
#define CS25_H
#include "weight.h"

//Creates grading weights for different cs25 assignment categories
namespace Cs25
{
    Category build_weights(const Weight& weight);
    Category get_weights(const std::string &target);
}

#endif //CS25_H
