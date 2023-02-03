//
// Created by sidha on 2/1/2023.
//

#ifndef CS170_THE_EIGHT_PUZZLE_NODE_H
#define CS170_THE_EIGHT_PUZZLE_NODE_H

#include "Problem.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int puzzle[n][n];
    int goal[n][n];

    int g_cost; //cost from initial state to node: g()
    int h_cost; //cost of heuristic function: h()
    int depth;
    string state; //unique ID for state

    //constructors
    Node();
    explicit Node (Node* prev);
    explicit Node(Problem p);

    //operators
    void slide_up();
    void slide_down();
    void slide_left();
    void slide_right();

    //helper functions
    static string puzzle_string(int puzzle_node[n][n]); //converts puzzle to string
    void print_result();
    bool detect_space(int& row, int& col); //finds the space in puzzle
    int total_cost() const; //g(n) + h(n)
    bool goal_test();
    void set_heuristic(int choice);
    int misplaced_tile(); //counts misplaced tiles
    int euclidean_distance(); //calcs euclidean distance
};


#endif //CS170_THE_EIGHT_PUZZLE_NODE_H
