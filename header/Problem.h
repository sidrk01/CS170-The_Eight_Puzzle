//
// Created by sidha on 1/31/2023.
//

#ifndef CS170_THE_EIGHT_PUZZLE_PROBLEM_H
#define CS170_THE_EIGHT_PUZZLE_PROBLEM_H
#include <bits/stdc++.h>
const int n=3;
#include <iostream>
#include <cstdlib>
using namespace std;

class Problem {

public:
    int initial_state[n][n];
    int goal_state[n][n];

    Problem(int puzzle[n][n], int goal[n][n]) { //constructor
        copy(&puzzle[0][0], &puzzle[0][0] + n * n, &initial_state[0][0]); //create initial state
        copy(&goal[0][0], &goal[0][0] + n * n, &goal_state[0][0]); //create initial state
    }
};
#endif //CS170_THE_EIGHT_PUZZLE_PROBLEM_H
