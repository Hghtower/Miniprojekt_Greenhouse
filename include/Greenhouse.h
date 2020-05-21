#pragma once
#include <iostream>

class Greenhouse {
private:
    int waterLevel;
    int remainWater;
    float fertilizerlevel;
    bool light;
    
public:
    void refillWater();
    int getWater();
    float getFertilizerlevel();
};