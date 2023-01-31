#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "uifunctions.h"
using namespace std;


int main() {
    int user_puzzle[N][N];

    string row_one, row_two, row_three;
    cout << welcome;
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
    puzzle_print(user_puzzle); //prints contents of puzzle

    return 0;
}





