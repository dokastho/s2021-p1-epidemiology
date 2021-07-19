// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#include "epi-fxs.h"
#include <iomanip>

int main() {
    unordered_map<string,vector<person>> eecsStudents;
    set<string> eecsFluMutations;
    string firstName, lastName, genome;
    date timepoint;
    char dash = '/';
    while (cin >> timepoint.m >> dash >> timepoint.d >> dash >> timepoint.y >> firstName >> lastName >> genome)
    {
        string name = firstName + " " + lastName;
        person p(timepoint,name);
        eecsStudents[genome].push_back(p);
        eecsFluMutations.insert(genome);
    }
    if (eecsFluMutations.size() == 0)
    {
        cerr << "Invalid input file\n";
        return 1;
    }
    
    vector<string> vec(eecsFluMutations.begin(),eecsFluMutations.end());

    disease_tracker eecs_flu_tracker(eecsStudents,vec);
    eecs_flu_tracker.compute_stats();
    
    return 0;
}

// todo
// how it'd change when worst, first person is removed
// how many people get infected
// worst mutation (the one with the most infections). for now list genome and # of cases
// number of mutations
// r nought