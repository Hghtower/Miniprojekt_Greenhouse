#pragma once

class Greenhouse {
public:  
    void refillWater();
    void refillFertilizer();
    float getFertilizerlevel();
    void lightOn();

    int water_level;
    float fertilizer_level;
    bool light;
};