#include <Greenhouse.h>
#include <Plants.h>
#include <TomatoPlant.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int days = 0;
Greenhouse Storage;
std::vector<TomatoPlant> ThePlants;

bool growFruit(std::vector<TomatoPlant> &ThePlants);
void simulateTime(std::vector<TomatoPlant> &ThePlants);

int main (int argc, char const *argv[]) {
    std::cout << "Greenhouse simulation starting..." << '\n';

    //Set random 
    srand(time(NULL));

    //Refill tank
    Storage.refillWater(); 
    Storage.refillFertilizer();
    Storage.lightOn();

    //Input plants
    TomatoPlant tomato1;
    TomatoPlant tomato2;
    TomatoPlant tomato3;

    //Input number of days to simulate
    std::cout << "Input number of days to simulate: " << '\n';
    std::cin >> days;

    //Create plant objects
    ThePlants.push_back(tomato1);
    ThePlants.push_back(tomato2);
    ThePlants.push_back(tomato3);

    //Simulate
    simulateTime(ThePlants);

    return 0;
}

void simulateTime(std::vector<TomatoPlant> &ThePlants ) {
    int elapsed_days = 0;
    for (int i = 0; i < days; i++) {
        std::cout << "Day " << i + 1 << " of " << days << '\n';
        elapsed_days++;
        if (!growFruit(ThePlants)) {
            break;
        }
    }
    std::cout << elapsed_days << " days have elapsed. The total number of tomatoes on the plants are: " << '\n';
    for (auto i : ThePlants) {
        Sleep(100);
        std::cout << i.num_fruits << " tomatoes" << '\n';
    }
}

bool growFruit(std::vector<TomatoPlant> &ThePlants) {
    for (int i = 0; i < ThePlants.size(); i++)
    {
        Sleep(300);
        if ((Storage.water_level >= ThePlants[i].water_usage) && (Storage.fertilizer_level >= ThePlants[i].fertilizer_usage) && (Storage.light)) {
            int Chance = rand() % 100 + 1;
            if ((Chance <= 20) && (ThePlants[i].num_fruits < ThePlants[i].max_fruit)) {
                ThePlants[i].num_fruits++;
                std::cout << "Tomato plant " << i + 1 << " grew a tomato! It now has a total of " << ThePlants[i].num_fruits << " tomatoes" << '\n';
            }
        }
        Storage.water_level -= ThePlants[i].water_usage;
        Storage.fertilizer_level -= ThePlants[i].fertilizer_usage;
        if (Storage.water_level < ThePlants[i].water_usage) {
            std::cout << "There is not enough water in the tank to grow tomatoes!" << '\n';
            return false;
        }
        if (Storage.fertilizer_level < ThePlants[i].fertilizer_usage) {
            std::cout << "There is not enough fertlizer in the tank to grow tomatoes!" << '\n';
            return false;
        }
    }
    return true;
}