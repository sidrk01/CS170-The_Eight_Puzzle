//
// Created by sidha on 1/30/2023.
//
#ifndef CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H
#define CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H

#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 3;
int user_puzzle[N][N];

const string welcome = "Welcome to Sid's  8 puzzle solver. Type '1' to use a default puzzle. or '2' to enter your own puzzle.\n";
const string puzzle_enter = "Enter your puzzle, use a zero to represent the blank\n";
const string invalid = "An invalid response has been entered. Default is selected.\n";
const string algo = "Enter your choice of algorithm\n[1] Uniform Cost Search.\n[2] A* with the Misplaced Tile heuristic.\n[3] A* with the Euclidean distance heuristic.\n";
const string default_choice = "Select the desired level of spice for your puzzle.\n[1] No Spice\n[2] Lite Mild\n[3] Mild\n[4] Medium\n[5] HOT\n[6] Extra HOT\n[7] REAPER\n[8] EMERGENCY ROOM\n";

//one move [1]
const int no_spice[N][N] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 0,}};

//three moves [2]
const int lite_mild[N][N] = {{1, 2, 0},
                             {4, 5, 3},
                             {7, 8, 6,}};

//six moves [3]
const int mild[N][N] = {{1, 2, 0},
                        {4, 5, 3},
                        {7, 8, 6,}};

//9 moves [4]
const int medium[N][N] = {{0, 1, 2},
                          {4, 5, 3},
                          {7, 8, 6,}};

//15 moves [5]
const int hot[N][N] = {{7, 2, 5},
                       {3, 1, 0},
                       {6, 4, 8,}};

//31 moves
const int extra_hot[N][N] = {{8, 6, 7},
                             {2, 5, 4},
                             {3, 0, 1,}};

//868 moves
const int reaper[N][N] = {{8, 7, 1},
                          {6, 0, 2},
                          {5, 4, 3,}};

//don't attempt to solve
const int emergency_room[N][N] = {{1, 2, 3},
                                  {4, 5, 6},
                                  {8, 7, 0,}};

//Creates puzzle from default options
void puzzle_from_defaults(){
    cout << default_choice; // default select prompt

    int user_select;
    string  spice_select = "Lite Mild";
    cin >> user_select;


switch (user_select) {
    case 1:
        copy(&no_spice[0][0], &no_spice[0][0] + N * N, &user_puzzle[0][0]); //2D array copy
        spice_select = "No Spice";
        break;
    case 2:
        copy(&lite_mild[0][0], &lite_mild[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "Lite Mild";
        break;
    case 3:
        copy(&mild[0][0], &mild[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "Mild";
        break;
    case 4:
        copy(&medium[0][0], &medium[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "Medium";
        break;
    case 5:
        copy(&hot[0][0], &hot[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "HOT";
        break;
    case 6:
        copy(&extra_hot[0][0], &extra_hot[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "Extra HOT";
        break;
    case 7:
        copy(&reaper[0][0], &reaper[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "REAPER";
        break;
    case 8:
        copy(&emergency_room[0][0], &emergency_room[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "EMERGENCY ROOM";
        break;
    default:
        cout << invalid;
        copy(&lite_mild[0][0], &lite_mild[0][0] + N * N, &user_puzzle[0][0]);
        spice_select = "Lite Mild";
        break;

}
    cout << "You have chosen:" + spice_select + ". Good Luck!" << endl; //User is notified of choice;
}

//Creates puzzle from user-inputs (option "2")
void puzzle_from_user(){
    string row_one, row_two, row_three;
    cout << puzzle_enter;
    cout << "Enter the first row, use space or tabs between numbers:";
    getline(cin, row_one);
    cout << "Enter the second row, use space or tabs between numbers:";
    getline(cin, row_two);
    cout << "Enter the third  row, use space or tabs between numbers:";
    getline(cin, row_three);

//adds user inputs to puzzle but removes the spaces
    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            if (i == 0) {
                remove(row_one.begin(), row_one.end(), ' ');
                user_puzzle[i][j] =  static_cast<unsigned char>(row_one[j]) - 48; //char to int conversion with offset
            } else if (i == 1) {
                remove(row_two.begin(), row_two.end(), ' ');
                user_puzzle[i][j] = static_cast<unsigned char>(row_two[j]) - 48;
            } else if (i == 2) {
                remove(row_three.begin(), row_three.end(), ' ');
                user_puzzle[i][j] = static_cast<unsigned char>(row_three[j]) - 48;
            }
        }
    }
}

//detects instance of empty space
bool detect_space(int puzzle[N][N], int&column, int&row){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (puzzle[i][j] == 0){
                row = i;
                column=j;
                return true;
            }
        }
    }
    return false;
}


//prints contents of user puzzle
void puzzle_print(int puzzle[N][N]){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (puzzle[i][j] != 0)
                cout << puzzle[i][j];
            else
                cout << '*';

            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
}


#endif //CS170_THE_EIGHT_PUZZLE_UIFUNCTIONS_H
