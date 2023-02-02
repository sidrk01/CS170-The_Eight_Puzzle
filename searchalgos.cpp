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
    unsigned int frontier_size = 0;
    unsigned int size_nodes = 0;

    frontier.push(head); //initialize the frontier using initial state of problem
    while(!frontier.empty()){ //loop do
        if(frontier.empty()){
            cout << "Unable to perform search." << endl;
            return;
        }

        if (frontier_size < frontier.size())
            frontier_size = frontier.size();
        Node temp = frontier.top();
        frontier.pop(); //choose a leaf node and remove it from the frontier

        if(first){ //CAN BE MODIFIED*****
            explored_set.insert(temp.state); //First leaf node in explored set
            first = false;
        }

        if(temp.goal_test()){ //if a node contains a goal state then return the corresponding solution
            cout << "GOAL!!!" << endl;
            temp.print_result(); //prints output of search
            cout << nodes_expand << size_nodes << " nodes." << endl;
            cout << node_queue_max << frontier_size << endl;
            cout << node_goal_depth << temp.depth << endl;
        return;
        }

        if (frontier_size > 1) {//expand the chosen node
            cout << "The best state to expand with g(n) = " << temp.g_cost  << " and h(n) = " << temp.h_cost << " is..." << endl;
        }

        temp.print_result();
        cout <<"expanding this node..." << endl;
        list = expand(temp); //expand the chosen node

        cout << endl << "Start List:" << endl;
        for (unsigned i = 0; i < list.size(); i++){
            list.at(i).print_result();
            cout << endl;
        }
        cout << endl << "End List:" << endl;

        for (const auto & i : list){ //adding resulting nodes to the frontier
            frontier.push(i);
        }
        size_nodes += 1;
    }
}

//helper function
vector<Node> SearchAlgos::expand(Node& curr) {
    vector<Node> list;
    return list; //returns list of explored temp Nodes
}


