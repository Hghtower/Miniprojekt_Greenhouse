#pragma once

class Greenhouse {
public:  
    void refillWater(); //sets the water_level to a given integer value
    void refillFertilizer(); //sets the fertilizer_level to a given float value
    void lightOn(); //sets light to true

    int water_level;
    float fertilizer_level;
    bool light;
};