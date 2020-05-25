#pragma once

#include "Plants.h"

class TomatoPlant: public Plants 
{
 private:
    int water_usage = 1;
    float fertilizer_usage = 0.1;
    int max_fruit = 10;
 public:
    
    int getNumFruit();
    int getWaterUsage();
    float getFertilizerUsage();
    int getMaxFruit();
};