#include <Greenhouse.h>
#include <Plants.h>
#include <TomatoPlant.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

//Initialize Greenhouse object Storage and vector ThePlants
Greenhouse Storage;
std::vector<TomatoPlant> ThePlants;

//Declare functions growFruit and simulateTime
bool growFruit(std::vector<TomatoPlant> &ThePlants);
void simulateTime(std::vector<TomatoPlant> &ThePlants);

//Main
int main (int argc, char const *argv[]) {
    std::cout << "Greenhouse simulation starting..." << '\n';

    //Initialize random number generator
    srand(time(NULL));

    //Refill tank
    Storage.refillWater(); 
    Storage.refillFertilizer();
    Storage.lightOn();

    //Input plants
    TomatoPlant tomato1;
    TomatoPlant tomato2;
    TomatoPlant tomato3;

    //Push plant objects to vector ThePlants
    ThePlants.push_back(tomato1);
    ThePlants.push_back(tomato2);
    ThePlants.push_back(tomato3);

    //Simulate
    simulateTime(ThePlants);

    return 0;
}

//Run function growFruit based on number of desired days
void simulateTime(std::vector<TomatoPlant> &ThePlants ) {
    //Define variables days and elapsed_days
    int days = 0;
    int elapsed_days = 0;
    //Input number of days to simulate
    std::cout << "Input number of days to simulate: " << '\n';
    std::cin >> days;
    //Call growFruit for every day
    for (int i = 0; i < days; i++) {
        std::cout << "Day " << i + 1 << " of " << days << '\n';
        elapsed_days++;
        if (!growFruit(ThePlants)) {
            break;
        }
    }
    std::cout << elapsed_days << " days have elapsed. The total number of tomatoes on the plants are: " << '\n';
    //Output the number of tomatoes in each tomato object
    for (auto i : ThePlants) {
        Sleep(100);
        std::cout << i.num_fruits << " tomatoes" << '\n';
    }
}

//Function growFruit returns true if cycle was completed succesfully, false if water_level or fertilizer_level are too low 
bool growFruit(std::vector<TomatoPlant> &ThePlants) {
    //for loop runs through all object in ThePlants
    for (int i = 0; i < ThePlants.size(); i++)
    {
        Sleep(300);
        //if statement check if water_level and fertilizer_level in Storage are larger than the current obeject in ThePlants,
        //and if light = true
        if ((Storage.water_level >= ThePlants[i].water_usage) && (Storage.fertilizer_level >= ThePlants[i].fertilizer_usage) && (Storage.light)) {
            //Chance creates a "mostly" random number between 0 and 100. If its between 0 and 20 (a 1/5 chance) and num_fruits != max_fruit,
            //1 is added to num_fruits
            int Chance = rand() % 100 + 1;
            if ((Chance <= 20) && (ThePlants[i].num_fruits < ThePlants[i].max_fruit)) {
                ThePlants[i].num_fruits++;
                std::cout << "Tomato plant " << i + 1 << " grew a tomato! It now has a total of " << ThePlants[i].num_fruits << " tomatoes" << '\n';
            }
        }
        //water_level and fertilizer_level are decreased by the amount of them that the plant object uses
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