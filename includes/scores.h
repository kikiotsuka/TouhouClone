#ifndef SCORES_H
#define SCORES_H

#include "meta.h"
#include <fstream>

class Scores {
private:
    unsigned long long scores[4];
    void write_score();

    Scores();
    Scores(Scores const&); //dont implement
    void operator=(Scores const&); //dont implement
public:
    static Scores& get_instance();
    unsigned long long* get_scores();
    void read_score();
    void update_score(unsigned long long scores[]);
    void reset_scores();
};

#endif // SCORES_H