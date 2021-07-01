// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#ifndef EPI_H
#define EPI_H

#include <vector>
#include <iostream>

using namespace std;

struct person {
    int id,transmission;
    tm date;
    string name;
    person(int id_in, tm date_in, string name_in) : 
            id(id_in), date(date_in), name(name_in){};
};

class disease_tracker {
    vector<person> population;
    vector<vector<size_t>> memo;
    public:
    disease_tracker(vector<person> &ppl_in) : population(ppl_in) {
        memo.resize(ppl_in.size());
        for (size_t i = 0; i < ppl_in.size(); i++)
        {
            memo[i].resize(i,0);
        }
    }

    int distance_helper(string genome1, string genome2);
    
    int distance_matrix(person &p1, person &p2);
};
#endif