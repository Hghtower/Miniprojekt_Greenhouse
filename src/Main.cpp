#include <Greenhouse.h>
#include <Plants.h>
#include <TomatoPlant.h>
#include <CucumberPlant.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <stdlib.h>

int days = 30; //temp

int main (int argc, char const *argv[]) {
    std::cout << "Greenhouse simulation starting..." << '\n';

    srand(time(NULL));

    Greenhouse Storage;
    Storage.refillWater(); 
    Storage.refillFertilizer();
    Storage.lightOn();

    //Input plants
    TomatoPlant tom1;
    TomatoPlant tom2;
    CucumberPlant cuc1;

    //Input number of days to simulate
    std::cout << "Input number of days to simulate: " << '\n';
    std::cin >> days;

    //Create plant objects
    std::vector<Plants*> ThePlants;
    ThePlants.push_back(&tom1);
    ThePlants.push_back(&tom2);
    ThePlants.push_back(&cuc1);

    //Simulate
    simulateTime();

    //Print results

    return 0;
}

void simulateTime(Greenhouse &t, Plants* &y) {
    for (int i = days; i == 0; i--) {
        growFruit(Greenhouse &t, Plants* &y);
    };
};

void growFruit(Greenhouse &t, Plants* &y) {
    if ((t.water_level >= y.water_usage) && (t.fertilizer_level >= y.fertilizer_usage) && (t.light)) {
        int Chance = rand() % 100 + 1;
        if(Chance <= 20) {
            y.num_fruits++;
        };
    };
};