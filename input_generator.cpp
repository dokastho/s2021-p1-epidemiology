// authored by thomas dokas, dokastho@umich.edu
// 6/27/2021
// a basic script to write some input files, I'm sure it'll get progressively 
// more complicated as I need longer files

#include "input_generator.h"

using namespace std;

// lets say that mutations take place on charicteristic timescales of a week
void disease::date_helper(int delta) {
    day += delta;
    if (day > 30)
    {
        day -= 30;
        month++;
        if (month > 12)
        {
            month -= 12;
            year++;
        }
        
    }
    else if (day < 1)
    {
        day += 30;
        month--;
        if (month < 1)
        {
            month += 12;
            year--;
        }
    }
}

void disease::spread_and_mutate(string genome,vector<pair<string,string>> names, int &n) {
    //srand(rand());
    for (size_t i = 0; i < names.size(); i++)
    {
        int random_day = rand() % 7;
        date_helper(random_day);
        cout << month << "/" << day << "/" << year << " ";
        cout << names[i].first << " " << names[i].second << " ";
        cout << genome << "\n";
        date_helper(-1 * random_day);
        
        if (n == 0)
        {
            continue;
        }
        vector<pair<string,string>> newlyInfected;
        string mutant = genome;
        mutant[rand() % mutant.size()] = alpha[rand() % 4];
        for (int newPatient = 0; newPatient < rand() % 5; newPatient++)
        {
            newlyInfected.push_back({ names_list[rand() % names_list.size()] , names_list[rand() % names_list.size()] });
        }
        date_helper(7);
        n--;
        spread_and_mutate(mutant,newlyInfected, n);
        n++;
        date_helper(-7);
    }
}

int main(int argc, char** argv) {
    srand((uint32_t)time(0));
    int n = atoi(argv[1]); // generations of mutations
    size_t people = 6; // TODO: make number of people variable
    vector<pair<string,string>> names(people); 
    string genomeNought;
    disease eecs_flu;
    if (argc > 3)
    {
        cerr << "Invalid number of parameters\n";
        return 1;
    }
    

    srand(1);

    for (size_t i = 0; i < people; i++)
    {
        names[i] = { names_list[rand() % names_list.size()] , names_list[rand() % names_list.size()] };
    }
    
    for (size_t i = 0; i < 32; i++)
    {
        genomeNought.push_back(alpha[rand() % 4]);
    }
    
    eecs_flu.spread_and_mutate(genomeNought,names,n);
    return 0;
}

// TODO: fix days