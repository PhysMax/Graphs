//
// Created by Olga on 10/11/2020.
//

#ifndef GRAPHS_ADJLIST_H
#define GRAPHS_ADJLIST_H
#include <vector>
#include <map>
#include <set>
using namespace std;

class GraphL {
    map<int, set<int>> adj_list;
    int vertexes;
public:
    GraphL();
    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    bool isEdge(int i, int j);
    void print();
    void bfs(int start); 
    void dfs(); 
    ~GraphL();
};









#endif //GRAPHS_ADJLIST_H
