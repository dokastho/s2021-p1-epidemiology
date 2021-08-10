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
    cout << "Most infectious superspreader:\t" << this->find_superspreader() << "\n";
    size_t mutations = this->mutation_count(), infections = infection_count();
    cout << "Number of mutations:\t\t" << mutations << "\n";
    cout << "Number of infections:\t\t" << infections << "\n";
    cout << "R nought:\t\t\t" << (double)infections / (double)mutations << "\n";
    cout << "Chance of mutation:\t\t" << (double)mutations / (double)infections * 100 << "%\n";
}

void disease_tracker::remove_first()
{
    person first = population.begin()->second.front();
    string gene = population.begin()->first;
    trace_and_remove(gene, first);
}

void disease_tracker::remove_worst()
{
    
}

void disease_tracker::trace_and_remove(string gene, person zeroth)
{
    string nextMutation = find_nearest(gene,false);
    if (nextMutation != "")
    {
        int buffer = 0;
        for (auto it = population[gene].begin(); it->name != zeroth.name; it++)
        {
            buffer += it->transmission;
        }
        
        for (int i = 0; i < buffer; i++)
        {
            trace_and_remove(nextMutation,population[nextMutation][i]);
        }
    }
    
    // remove the person
    // auto it = find_if(population[gene].begin(),population[gene].end(),[](const person first, const person second) { return first.name == second.name; });
    // comparison to past-the-end iterator redundant
    // iter_swap(*it,population[gene].end());
    // population[gene].pop_back();
}

size_t disease_tracker::distance_helper(string genome1, string genome2)
{
    size_t diff = 0;
    for (size_t i = 0; i < genome1.size(); i++)
    {
        if (genome1[i] != genome2[i])
        { diff++;
        }
        
    }
    return diff;
}

string disease_tracker::find_nearest(string mutant, bool pre) {
    size_t minDist = 1e6;
    string closest = "";
    for (size_t i = 0; i < gene_pool.size(); i++)
    {
        size_t dist = this->distance_helper(mutant,gene_pool[i]);
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

string disease_tracker::find_superspreader()
{
    // for (size_t gene = 0; gene < gene_pool.size(); gene++)
    // {
        
    // }
    return "foo";
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