// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#ifndef EPI_H
#define EPI_H

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct person {
    int transmission;
    tm date;
    string name;
    person(tm date_in, string name_in) : 
           date(date_in), name(name_in), transmission(0){};
};

class disease_tracker {
    unordered_map<string,vector<person>> population;
    vector<string> gene_pool;
    vector<vector<size_t>> memo;
    public:
    disease_tracker(unordered_map<string,vector<person>> &ppl_in, vector<string> gene_pool_in) : 
    population(ppl_in), gene_pool(gene_pool_in) {
        memo.resize(gene_pool_in.size());
        for (size_t i = 0; i < ppl_in.size(); i++)
        {
            memo[i].resize(i,0);
        }
    }

    int distance_helper(string genome1, string genome2);
    
    int distance_matrix(string genome1, string genome2);

    string find_nearest(string mutant, bool pre);

    size_t mutation_popularity(string genome);

    string remove_max();

    bool dateComp(tm t1, tm t2);
};
#endif