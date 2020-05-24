#include <Greenhouse.h>
#include <Plants.h>
#include <TomatoPlant.h>
#include <CucumberPlant.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <stdlib.h>

int days = 0;
Greenhouse Storage;
std::vector<Plants*> ThePlants;

void growFruit(std::vector<Plants*> &ThePlants);
void simulateTime(std::vector<Plants*> &ThePlants);

int main (int argc, char const *argv[]) {
    std::cout << "Greenhouse simulation starting..." << '\n';

    srand(time(NULL));

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
    /*std::vector<Plants*> ThePlants;*/
    ThePlants.push_back(new TomatoPlant);
    ThePlants.push_back(new TomatoPlant);
    ThePlants.push_back(new CucumberPlant);

    //Simulate
    simulateTime(ThePlants);

    //Print results

    return 0;
}

void simulateTime(std::vector<Plants*> &ThePlants ) {
    for (int i = 0; i < days; i++) {
        growFruit(ThePlants);
    }
}

void growFruit(std::vector<Plants*> &ThePlants) {
    for (int i = 0; i < ThePlants.size(); i++)
    {
        if (Storage.light) {
            int Chance = rand() % 100 + 1;
            if(Chance <= 100) {
                std::cout << ThePlants[i]->water_usage << '\n';
            }
        }
    }
    
/*
    if ((Storage.water_level >= ThePlants[].water_usage) && (Storage.fertilizer_level >= y.fertilizer_usage) && (Storage.light)) {
        int Chance = rand() % 100 + 1;
        if(Chance <= 20) {
            y.num_fruits++;
        }
    }
*/
}