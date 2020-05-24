#pragma once

class Greenhouse {
public:
    int water_level;
    float fertilizer_level;
    bool light;
    
    void refillWater();
    void refillFertilizer();
    float getFertilizerlevel();
    void lightOn();
};