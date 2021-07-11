// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#include "epi-fxs.h"

int disease_tracker::distance_helper(string genome1, string genome2)
{
    int diff = 0;
    for (size_t i = 0; i < genome1.size(); i++)
    {
        if (genome1[i] != genome2[i])
        {
            diff++;
        }
        
    }
    return diff;
}

int disease_tracker::distance_matrix(string genome1, string genome2)
{
    int j = -1, k = -1;
    for (size_t i = 0; i < gene_pool.size(); i++)
    {
        if (gene_pool[i] == genome1)
        {
            j = (int)i;
        }
        else if (gene_pool[i] == genome2)
        {
            k = (int)i;
        }
        if ((j != -1) & (k != -1))
        {
            break;
        }
    }
    size_t low = min(j,k), high = max(j,k);
    if (memo[low][high] == 0)
    {
        memo[low][high] = distance_helper(genome1,genome2);
    }

    return memo[low][high];
}

string disease_tracker::find_nearest(string mutant, bool pre) {
    int minDist = 1e6;
    string closest;
    for (size_t i = 0; i < gene_pool.size(); i++)
    {
        int dist = this->distance_matrix(mutant,gene_pool[i]);
        if (dist < minDist)
        {
            if (pre)
            {
                if (population[mutant].front().date.tm_mday < population[gene_pool[i]].back().date.tm_mday)
                {
                    minDist = dist;
                    closest = gene_pool[i];
                }
            }
            else
            {
                if (population[gene_pool[i]].back().date.tm_mday < population[mutant].front().date.tm_mday)
                {
                    minDist = dist;
                    closest = gene_pool[i];
                }
            }
        }
    }

    // tally the case as a transmission
    if (!pre)
    {
        population[mutant].back().transmission++;
    }

    return closest;
}

size_t disease_tracker::mutation_popularity(string genome) {
    return population[genome].size();
}

string disease_tracker::remove_max() {
    string superspreader,genome;
    int maxCases = 0;
    for (size_t i = 0; i < gene_pool.size(); i++)
    {
        for (size_t j = 0; j < population[gene_pool[i]].size(); j++)
        {
            if (population[gene_pool[i]][j].transmission > maxCases)
            {
                maxCases = population[gene_pool[i]][j].transmission;
                superspreader = population[gene_pool[i]][j].name;
                genome = gene_pool[i];
            }
        }
    }
    // wouldn't the nearests include the ones that mutate from it?
    // find the people to remove based on the number of transmissions
    // after the person in question, then skip over that number in the
    // next mutation
    // how would I know which mutation came before and which came after
    // use dates


    return superspreader;
}

