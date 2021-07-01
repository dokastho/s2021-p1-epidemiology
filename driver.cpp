// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#include "epi-fxs.h"
#include <iomanip>

int main() {
    vector<person> eecs_students;
    string firstName, lastName, genome;
    tm date;
    char dash;
    while (cin >> get_time(&date,"%m/%d/%Y") >> firstName >> lastName >> genome)
    {
        string name = firstName + lastName;
        person p(id,date,name,genome);
    }
    
    disease_tracker eecs_flu_tracker;
    return 0;
}