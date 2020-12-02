#include<iostream>
#include<queue>
#include<stack>
#include<set>

#include"AdjMatrix.h"


Graph::Graph(int count):vertexCount(count){
    adj_matrix.resize(count, vector<bool>(count, false));
};

void Graph::addEdge(int i, int j) {
    adj_matrix[i][j] = true;
    adj_matrix[j][i] = true;
}

void Graph::removeEdge(int i, int j) {}
bool Graph::isEdge(int i, int j) {
    return adj_matrix[j][i];
}

bool Graph::isEdge(int i, int j) {
    return adj_matrix[i][j] || adj_matrix[j][i];
}

void Graph::print() {
    for (auto i : adj_matrix) {
        for (auto j: i) {
            std::cout << j <<" ";
        }
        std::cout << endl;
    }
}

void Graph::bfs(int start) {
    queue <int> q;
    q.push(start);
    std::set <int> visited;
    std::cout << std::endl;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int element = q.front();
            visited.insert(element);
            q.pop();
            std::cout << element << " ";
            for (int k = 0; k < vertexCount; k++) {
                if (adj_matrix[element][k] && visited.find(k) == visited.end()) {
                    q.push(k);
                }
            }
        }
        std::cout <<endl;
    }
}

void Graph::dfs() {
    std::vector<bool> visited(vertexCount, false);
    std::stack<int> st;
    int cur;
    st.push(0);
    
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        if (!visited[cur]) {
            std::cout << cur << ' ';
            visited[cur] = true;

        }
        for (int i = 0; i < vertexCount; i++) {
            if (adj_matrix[cur][i] && !visited[i] ) {
                st.push(i);
            }
        }
    }
}