#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "header/Problem.h"
#include "header/uifunctions.h"
#include "header/searchalgos.h"
using namespace std;


int main() {
    char user_opt = 'Y';
    int user_choice = 0;

    while (user_opt == 'Y') {
        cout << welcome; //Welcome prompt
        cin >> user_choice;
        cout << border;

        if (user_choice == 1)
            puzzle_from_defaults();
        else
            puzzle_from_user();
        puzzle_print(user_puzzle); //prints contents of puzzle

        cout << border; //neatly separates user inputs
        cout << algo; //allows for choice of algorithm
        cin >> user_choice;

        Problem problem(user_puzzle, goal_state); //creates problem to be solved
        SearchAlgos search(problem, user_choice);

        search.graph_search();
        cout << border;

        cout << proceed; //reset puzzle
        cin >> user_opt;
        cout << border;
    }

    return 0;
}





