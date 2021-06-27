// authored by thomas dokas, dokastho@umich.edu
// 6/27/2021
// a basic script to write some input files, I'm sure it'll get progressively 
// more complicated as I need longer files

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int n = atoi(argv[1]); // number of lines of input

    vector<string> names = {"Tony","Jimmy","Perez","Michael","Chris","John","Sergio",
                            "Philip","David","Paul","Mark","James","Andrew","Stuart",
                            "Gary","Kevin","Charles","Peter","Darren","George","Kenneth",
                            "Allan","Simon","Adam"};
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    for (size_t i = 0; i < n; i++)
    {
        // dates
        cout << rand() % 12 + 1 << "/" << rand() % 28 + 1 << "/";
        cout << rand() % 2 + 2020 << " ";

        // names
        cout << names[rand() % names.size()] << " ";
        cout << names[rand() % names.size()] << " ";

        // disease string sequence
        for (size_t j = 0; j < 32; j++)
        {
            cout << alpha[rand() % alpha.size()];
        }
        cout << "\n";
    }
    return 0;
}