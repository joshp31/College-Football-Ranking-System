#ifndef COLLEGEFOOTBALLRS_H
#define COLLEGEFOOTBALLRS_H

#include <iostream>
using namespace std;

class Team {
    private:
        string name;
        string conference;
        int wins;
        int losses;
        float winpercentage;
        float oppg;
        float dppg;
        float sos;

        float value;

    public:
        //Constructor
        Team(string teamname, string conf, int w, int l, float wperc, float offppg, float defppg, float str_of_sched) {
            name = teamname;
            conference = conf;
            wins = w;
            losses = l;
            winpercentage = wperc;
            oppg = offppg;
            dppg = defppg;
            sos = str_of_sched;
            
            value = (winpercentage * 100) + (sos * 2) + (oppg - dppg);
        }

        //getters
        string get_name() {
            return name;
        }

        string get_conference() {
            return conference;
        }
        
        int get_wins() {
            return wins;
        }

        int get_losses() {
            return losses;
        }

        float get_value() {
            return value;
        }
};

#endif
