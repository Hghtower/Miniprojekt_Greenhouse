#pragma once
#include <Plants.h>

class CucumberPlant: public Plants {
public:
    int water_usage = 2;
    float fertilizer_usage = {0.2};
    int max_fruit = 8;
    int num_fruits = 0;
};