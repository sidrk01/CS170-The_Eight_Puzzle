#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "uifunctions.h"
using namespace std;


int main() {
    int user_choice = 0;

    cout << welcome; //Welcome prompt
    cin >> user_choice;

    switch(user_choice) { //First Choice
        case 2:
            puzzle_from_user();
            break;
        default:
            puzzle_from_defaults();
            break;
    }

    puzzle_print(user_puzzle); //prints contents of puzzle

    return 0;

}





