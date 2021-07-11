// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#include "epi-fxs.h"
#include <iomanip>

int main() {
    unordered_map<string,vector<person>> eecsStudents;
    vector<string> eecsFluMutations;
    string firstName, lastName, genome;
    tm date;
    while (cin >> get_time(&date,"%m/%d/%Y") >> firstName >> lastName >> genome)
    {
        string name = firstName + lastName;
        person p(date,name);
        eecsStudents[genome].push_back(p);
        eecsFluMutations.push_back(genome);
    }
    
    disease_tracker eecs_flu_tracker(eecsStudents,eecsFluMutations);
    return 0;
}

// todo
// moving average r nought
// how it'd change when worst, first person is removed
// how many people get infected
// other stats