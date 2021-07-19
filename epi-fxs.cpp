// authored by thomas dokas, dokastho@umich.edu
// 6/26/2021
#include "epi-fxs.h"

void disease_tracker::compute_stats()
{
    // cout << disease_art;
    string line(64,'=');
    cout << "Disease Statistics:\n" << line << "\n";
    cout << "Original genome sequence:\t" << gene_pool.front() << "\n";
    cout << "Most infectious sequence:\t" << this->find_most_infectious() << "\n";
    cout << "Number of mutations:\t\t" << this->mutation_count() << "\n";
    cout << "Number of infections:\t\t" << this->infection_count() << "\n";
    cout << "R nought:\t\t\t" << this->r_nought() << "\n";
}

size_t disease_tracker::distance_helper(string genome1, string genome2)
{
    size_t diff = 0;
    for (size_t i = 0; i < genome1.size(); i++)
    {
        if (genome1[i] != genome2[i])
        {
            diff++;
        }
        
    }
    return diff;
}

size_t disease_tracker::distance_matrix(string genome1, string genome2)
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
    size_t minDist = 1e6;
    string closest;
    for (size_t i = 0; i < gene_pool.size(); i++)
    {
        size_t dist = this->distance_matrix(mutant,gene_pool[i]);
        if (dist < minDist)
        {
            if (pre)
            {
                if (population[mutant].front().timepoint < population[gene_pool[i]].back().timepoint)
                {
                    minDist = dist;
                    closest = gene_pool[i];
                }
            }
            else
            {
                if (population[gene_pool[i]].back().timepoint < population[mutant].front().timepoint)
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

string disease_tracker::find_most_infectious() {
    string worstMutation;
    size_t maxCases = 0;
    for (size_t gene = 0; gene < gene_pool.size(); gene++)
    {
        for (size_t host = 0; host < population[gene_pool[gene]].size(); host++)
        {
            if (population[gene_pool[gene]].size() > maxCases)
            {
                maxCases = population[gene_pool[gene]].size();
                worstMutation = gene_pool[gene];
            }
        }
    }
    // wouldn't the nearests include the ones that mutate from it?
    // find the people to remove based on the number of transmissions
    // after the person in question, then skip over that number in the
    // next mutation
    // how would I know which mutation came before and which came after
    // use dates


    return worstMutation;
}

size_t disease_tracker::mutation_count()
{
    return gene_pool.size();
}

size_t disease_tracker::infection_count()
{
    size_t infections = 0;
    for (size_t genome = 0; genome < gene_pool.size(); genome++)
    {
        infections += population[gene_pool[genome]].size();
    }
    return infections;
}

double disease_tracker::r_nought()
{
    return (double)this->infection_count() / (double)gene_pool.size();
}