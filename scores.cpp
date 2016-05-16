#include "includes/scores.h"

Scores& Scores::get_instance() {
    static Scores instance;
    return instance;
}

unsigned long long* Scores::get_scores() {
    return scores;
}

Scores::Scores() {
    read_score();
}

void Scores::read_score() {
    std::ifstream fin(FSCORE.c_str());
    if (fin.good()) {
        for (int i = 0; i < 4; i++) {
            fin >> scores[i];
        }
    } else {
        reset_scores();
    }
}

void Scores::write_score() {
    std::ofstream fout(FSCORE.c_str());
    for (int i = 0; i < 4; i++) {
        fout << scores[i] << "\n";
    }
}

void Scores::update_score(unsigned long long scores[]) {
    for (int i = 0; i < 4; i++) {
        this->scores[i] = scores[i];
    }
    write_score();
}

void Scores::reset_scores() {
    for (int i = 0; i < 4; i++) {
        scores[i] = 0;
    }
    write_score();
}
