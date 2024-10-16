#include "CollegeFootballRS.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compareValue(Team t1, Team t2)
{
    return (t1.get_value() < t2.get_value());
}

void printTeam(Team t, int index) {
    index += 1;
    cout << index << ". " << t.get_name() << " | " << t.get_conference() << " | " << t.get_wins() << "-" << t.get_losses() << " | Rating: " << t.get_value() << endl;
}

void reverseVector(vector<Team>& v) {
    reverse(v.begin(), v.end());
}

int main() {
    //Open CSV file
    ifstream file("College Football RS 2024 Week 7 - Sheet1.csv");

    //Variable declarations
    string line, name, conf;
    int wins, losses;
    float winpercentage, oppg, dppg, sos;
    vector<Team> teams;

    //Verify file opened correctly
    if (file.is_open()) {
        //Read in data
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, conf, ',');
            ss >> wins;
            ss.ignore(1);
            ss >> losses;
            ss.ignore(1);
            ss >> winpercentage;
            ss.ignore(1);
            ss >> oppg;
            ss.ignore(1);
            ss >> dppg;
            ss.ignore(1);
            ss >> sos;
            ss.ignore(1);

            //Construct Team object and add it to the vector
            teams.emplace_back(name, conf, wins, losses, winpercentage, oppg, dppg, sos);
        }
        file.close();
    }
    else {
        cout << "ERROR: Unable to open file." << endl;
        return 1;
    }

    sort(teams.begin(), teams.end(), compareValue);
    reverseVector(teams);
    
    //print the sorted vector in a nicely formatted way
    for (int i = 0; i < teams.size(); i++) {
        printTeam(teams[i], i);
    }

    return 0;
}