// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#ifndef EPI_H
#define EPI_H

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

// const string disease_art = 
// "              .\n"
// "           ,'/ \`.\n"
// "          |\/___\/|\n"
// "          \'\   /`/\n"
// "           `.\ /,'\n"
// "              |\n"
// "              |\n"
// "             |=|\n"
// "        /\  ,|=|.  /\\n"
// "    ,'`.  \/ |=| \/  ,'`.\n"
// "  ,'    `.|\ `-' /|,'    `.\n"
// ",'   .-._ \ `---' / _,-.   `.\n"
// "   ,'    `-`-._,-'-'    `.\n"
// "  '                       `\n";

struct date {
    int m,d,y;
    bool operator<(date rhs) {
        if (this->y < rhs.y)
        {
            return true;
        }
        else if (this->m < rhs.m)
        {
            return true;
        }
        else if (this->d < rhs.d)
        {
            return true;
        }
         return false;
    }
};
struct person {
    int transmission;
    date timepoint;
    string name;
    person(date date_in, string name_in) : 
           transmission(0), timepoint(date_in), name(name_in){};
};

class disease_tracker {
    unordered_map<string,vector<person>> population;
    vector<string> gene_pool;
    public:
    disease_tracker(unordered_map<string,vector<person>> &ppl_in, vector<string> gene_pool_in) : 
    population(ppl_in), gene_pool(gene_pool_in) {}

    void compute_stats();

    void remove_worst();

    void remove_first();

    void trace();

    size_t distance_helper(string genome1, string genome2);

    string find_nearest(string mutant, bool pre);

    string find_most_infectious();

    size_t mutation_popularity(string genome);

    size_t mutation_count();

    size_t infection_count();

    bool dateComp(date t1, date t2);

};
#endif