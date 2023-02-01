//
// Created by sidha on 1/31/2023.
//

#ifndef CS170_THE_EIGHT_PUZZLE_PROBLEM_H
#define CS170_THE_EIGHT_PUZZLE_PROBLEM_H
#include <bits/stdc++.h>
#include "uifunctions.h"

using namespace std;

class Problem {
private:
    int initial_state[N][N];
    int goal_state[N][N];

public:
    Problem(int puzzle[N][N], int goal[N][N]) { //constructor
        copy(&puzzle[0][0], &puzzle[0][0] + N * N, &initial_state[0][0]); //create initial state
        copy(&goal[0][0], &goal[0][0] + N * N, &goal_state[0][0]); //create initial state
    }
};
#endif //CS170_THE_EIGHT_PUZZLE_PROBLEM_H
