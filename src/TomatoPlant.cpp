#include <TomatoPlant.h>

void TomatoPlant::growFruit() {
    if (num_fruits < max_fruit) {
        num_fruits++;
    }
}
int TomatoPlant::getNumFruit() {
    return num_fruits;
}
int TomatoPlant::getWaterUsage() {
    return water_usage;
}
float TomatoPlant::getFertilizerUsage() {
    return fertilizer_usage;
}
int TomatoPlant::getMaxFruit(){
    return max_fruit;
}