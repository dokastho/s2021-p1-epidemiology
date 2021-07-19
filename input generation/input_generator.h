#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>

using namespace std;

const vector<string> names_list = {"Tony","Jimmy","Perez","Michael","Chris","John","Sergio",
                            "Philip","David","Paul","Mark","James","Andrew","Stuart",
                            "Gary","Kevin","Charles","Peter","Darren","George","Kenneth",
                            "Allan","Simon","Adam","Bill","Jack","Thomas","Brian",
                            "Bob","Dylan","Felix","Liam","Elijah","William","Ben","Mia",
                            "Isabella","Eve","Sophia","Emma","Ava","Harper","Lucas","Alex",
                            "Charlotte","Riley","Lily","Ella","Gianna","Chloe","Alana","Ethan",
                            "Carter","Mason","Muhammad","Sebastian","Logan","Leo","Dan","Mia",
                            "Wallace","Jayden","Jordan","Aaran","Aaliyah","Avery"};
const string alpha = "augc";

class disease {
    int month, day, year;
    public:

    disease() : month(1),day(1),year(2021) {
        srand((uint32_t)time(0));
    };

    void date_helper(int delta);

    void spread_and_mutate(string genome,vector<pair<string,string>> names, int &n);


};
#endif