#pragma once
#include <iostream>

class Greenhouse {
private:
    int waterlevel;
    int remainWater;
    float fertilizerlevel;
    bool light;
    
public:
    void setNewWaterLevel();
    float getWater() {
        return waterlevel;
    };
    float getFertilizerlevel() {
        return fertilizerlevel;
    };
};

void setNewWaterLevel(int Waterlevel, int remainWater) {
    Waterlevel = 180 - remainWater;
}