//
// Created by Olga on 10/11/2020.
//

#ifndef GRAPHS_ADJMATRIX_H
#define GRAPHS_ADJMATRIX_H

#include <vector>
using namespace std;

class Graph {
    vector<vector<bool>> adj_matrix;
    int vertexCount;
public:
    Graph(int count);
    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    bool isEdge(int i, int j);
    void print();
    int get_size() {return vertexCount;}
    void bfs(int start);
    void dfs();
    ~Graph();
};











#endif //GRAPHS_ADJMATRIX_H
