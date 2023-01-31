//
// Created by sidha on 1/30/2023.
//
#ifndef CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H
#define CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H

#include <iostream>
#include <cstdlib>
using namespace std;


const int N = 3;

const string welcome = "Welcome to Sid's 8 puzzle solver. Type '1' to use a default puzzle. or '2' to enter your own puzzle.\n";
const string puzzle_enter = "Enter your puzzle, use a zero to represent the blank\n";
//const string invalid = "An invalid response has been entered. Please try again.\n";
const string algo = "Enter your choice of algorithm\n[1] Uniform Cost Search.\n[2] A* with the Misplaced Tile heuristic.\n[3] A* with the Euclidean distance heuristic.\n";


//detects instance of empty space
bool detect_space(int user_puzzle[N][N], int&column, int&row){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (user_puzzle[i][j] == 0){
                row = i;
                column=j;
                return true;
            }
        }
    }
    return false;
}


//prints contents of user puzzle
void puzzle_print(int user_puzzle[N][N]){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (user_puzzle[i][j] != 0)
                cout << user_puzzle[i][j];
            else
                cout << '*';

            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
}

#endif //CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H
