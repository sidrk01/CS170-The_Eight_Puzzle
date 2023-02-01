//
// Created by sidha on 2/1/2023.
//

#include "Node.h"

Node::Node(){ //initialize with empty values
    state = "";
    g_cost = 0;
    h_cost = 0;
    depth = 0;
}

Node::Node(Node *prev){ //initialize with previous Node
    this->state = prev->state;
    this->g_cost = prev->g_cost;
    this->h_cost = prev->h_cost;
    this->depth = prev->depth;
    copy(&prev->puzzle[0][0],&prev->puzzle[0][0] + N*N,&this->puzzle[0][0]); //copies over puzzle
}

Node::Node(Problem p){ //creates initial and goal state
    state = puzzle_string(p.initial_state);
    g_cost = 0;
    h_cost = 0;
    depth = 0;
    copy(&p.initial_state[0][0],&p.initial_state[0][0] + N*N,&this->puzzle[0][0]);
    copy(&p.goal_state[0][0],&p.goal_state[0][0] + N*N,&this->goal[0][0]);
}

string Node::puzzle_string(int puzzle_node[N][N]) {
    string puzzle_out;
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            puzzle_out.push_back(puzzle_node[i][j] + 48); //appends character-by-character to string
        }
    }
    return puzzle_out;
}

bool Node::goal_test() {
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (puzzle[i][j] != goal[i][j])
                return false; //tile doesn't match goal
        }
    }
    return true;
}

bool Node::detect_space(int& row, int& col){
    for (unsigned i = 0; i < N; i++){
        for (unsigned j = 0; j < N; j++){
            if (puzzle[i][j] == 0){
                row = i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

