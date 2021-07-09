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

int disease_tracker::distance_matrix(person &p1, person &p2)
{
    int low = min(p1.id,p2.id), high = max(p1.id,p2.id);
    if (memo[low][high] != 0)
    {
        memo[low][high] = distance_helper(p1.sequence,p2.sequence);
    }
    return memo[low][high];
}

// want to make the memo based on genome ID's, want to make genome ID's short