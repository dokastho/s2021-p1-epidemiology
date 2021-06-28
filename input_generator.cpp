// authored by thomas dokas, dokastho@umich.edu
// 6/27/2021
// a basic script to write some input files, I'm sure it'll get progressively 
// more complicated as I need longer files

#include <iostream>
#include <vector>

using namespace std;

const vector<string> names_list = {"Tony","Jimmy","Perez","Michael","Chris","John","Sergio",
                            "Philip","David","Paul","Mark","James","Andrew","Stuart",
                            "Gary","Kevin","Charles","Peter","Darren","George","Kenneth",
                            "Allan","Simon","Adam"};
const string alpha = "augc";
int month = 1, day = 1, year = 2021;

// lets say that mutations take place on charicteristic timescales of a week
void date_helper() {
    int infectDay = day + rand() % 7;
    day += infectDay;
    if (day > 30)
    {
        day = day % 30;
        month++;
        if (month > 12)
        {
            month = month % 12;
            year++;
            cout << month << "/" << day << "/" << year << " ";
            month += 11;
            year--;
        }
        else
        {
            cout << month << "/" << day << "/" << year << " ";
            day += (30 - infectDay);
            month--;
        }
    }
    else
    {
        cout << month << "/" << day << "/" << year << " ";
        day -= infectDay;
    }
}

void disease_helper(string genome,vector<pair<string,string>> names, int &n) {
    if (n <= 0)
    {
        return;
    }
    
    vector<pair<string,string>> newlyInfected;
    for (size_t i = 0; i < names.size(); i++)
    {
        date_helper();
        cout << names[i].first << " " << names[i].second << " ";
        cout << genome << "\n";
        string mutant = genome;
        mutant[rand() % mutant.size()] = alpha[rand() % 4];
        day += 7;
        for (size_t newPatient = 0; newPatient < rand() % 3; newPatient++)
        {
            newlyInfected.push_back({ names_list[rand() % names_list.size()] , names_list[rand() % names_list.size()] });
        }
        disease_helper(mutant,newlyInfected, n);
    }
    n--;
}

int main(int argc, char** argv) {
    int n = atoi(argv[1]); // generations of mutations
    int people = 4; // TODO: make number of people variable
    vector<pair<string,string>> names(people); 
    string genomeNought;

    for (size_t i = 0; i < people; i++)
    {
        names.push_back({ names_list[rand() % names_list.size()] , names_list[rand() % names_list.size()] });
    }
    
    for (size_t i = 0; i < 32; i++)
    {
        genomeNought.push_back(alpha[rand() % 4]);
    }
    
    disease_helper(genomeNought,names,n);
    return 0;
}