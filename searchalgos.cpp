//
// Created by sidha on 2/1/2023.
//
#include "searchalgos.h"

SearchAlgos::SearchAlgos(Problem problem, int num) {
    p = &problem;
    this->algo_choice = n;
}

void SearchAlgos::graph_search() {
    Node head(*p);
    vector<Node> list; //list of expanded Nodes
    bool first = true;
    unsigned int frontier_size = frontier.size();
    unsigned int size_nodes = 0;

    frontier.push(head); //initialize the frontier using initial state of problem

    while(!frontier.empty()){ //loop do
        if(frontier.empty()){
            cout << "Unable to perform search." << endl;
            return;
        }

        //CHANGE
        if (frontier_size < frontier.size())
            frontier_size = frontier.size();

        Node temp = frontier.top();

        frontier.pop(); //choose a leaf node and remove it from the frontier

        if(first){ //CAN BE MODIFIED*****
            explored_set.insert(temp.state); //First leaf node in explored set
            first = false;
        }

        if(temp.goal_test()){ //if a node contains a goal state then return the corresponding solution
            temp.print_result(); //prints output of search
            cout << "GOAL!!!" << endl;
            cout << nodes_expand << size_nodes << " nodes." << endl;
            cout << node_queue_max << frontier_size << endl;
            cout << node_goal_depth << temp.depth << endl;
        return;
        }

        /*
        if (frontier_size > 1) {//expand the chosen node
            cout << "The best state to expand with g(n) = " << temp.g_cost  << " and h(n) = " << temp.h_cost << " is..." << endl;
        }

        temp.print_result();
        cout <<"expanding this node..." << endl << endl;
        */

        list = expand(temp); //expand the chosen node

        // DEBUG: OUTPUTS
        /*
        cout << endl << "Start List:" << endl;
        for (unsigned i = 0; i < list.size(); i++){
            list.at(i).print_result();
            cout << list.at(i).g_cost << endl;
        }
        cout << "End List:" << endl;
       */

        for (auto & i : list){ //adding resulting nodes to the frontier
            frontier.push(i);
        }
        size_nodes += 1;
    }
}

//helper function
vector<Node> SearchAlgos::expand(Node& curr) {
    int row = 0;
    int col = 0;
    curr.detect_space(row, col); //identifies row/col values of space
    vector<Node> list;

    for (unsigned i = 0; i < 4; i++){ //determines possible moves for puzzle (up to four)
        //slide_up
        if (row > 0){ //space can be moved up
            if (i == 0){ //each move allowed only once
                Node temp(curr); //initialize temp Node with Node*
                temp.slide_up(); //slides space up

                if (explored_set.count(temp.state) == 0) {// Node is not present in explored set
                    temp.g_cost += 1; // moves += 1
                    temp.depth += 1; // increased depth by 1
                    temp.set_heuristic(algo_choice); //setting h(n) value
                    list.push_back(temp); //inserted into return list of nodes
                    explored_set.insert(temp.state); //now added to explored set
                }
            }
        }
        //slide_down
        if (row < 2){ //space can be moved down
            if (i == 1){ //must be following iteration
                Node temp(curr);
                temp.slide_down();

                if (explored_set.count(temp.state) == 0){
                    temp.g_cost += 1;
                    temp.depth += 1;
                    temp.set_heuristic(algo_choice);
                    list.push_back(temp);
                    explored_set.insert(temp.state);
                }
            }
        }
        //slide_left
        if (col > 0){ //space can be moved left
            if (i == 2){
                Node temp(curr);
                temp.slide_left();

                if(explored_set.count(temp.state) == 0){
                 temp.g_cost++;
                 temp.depth++;
                 temp.set_heuristic(algo_choice);
                 list.push_back(temp);
                 explored_set.insert(temp.state);
                }
            }
        }
        //slide_right
        if(col < 2){ //space can be moved left
            if (i == 3){
                Node temp(curr);
                temp.slide_right();

                if(explored_set.count(temp.state) == 0){
                    temp.g_cost++;
                    temp.depth++;
                    temp.set_heuristic(algo_choice);
                    list.push_back(temp);
                    explored_set.insert(temp.state);
                }
            }
        }
    }

    /*DEBUG******************
    cout << "Start of List:" << endl;
    for (unsigned i =0; i < list.size(); i++){
       list.at(i).print_result();
       cout << endl;
    }
    cout << "End of List" << endl;
*/
    return list; //returns list of explored temp Nodes
}


