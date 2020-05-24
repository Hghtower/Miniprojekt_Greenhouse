#pragma once
#include <Plants.h>

class TomatoPlant: public Plants {
public:
    int water_usage = 1;
    float fertilizer_usage = {0.1};
    int max_fruit = 10;
};