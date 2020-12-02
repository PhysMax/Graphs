

#include<iostream>
#include<queue>
#include<stack>

#include"AdjList.h"

GraphL::GraphL() {}
void GraphL::addEdge(int i, int j) {
    auto it = adj_list.find(i);
    if (it != adj_list.end()) {
        it->second.insert(j);
    } else {
        set<int> edges;
        edges.insert(j);
        adj_list.insert({i, edges});
    }
}

void GraphL::addEdge(int i, int j) {
    adj_list[i].insert(j);
    adj_list[j].insert(i);
    vertexes++;
}

void GraphL::removeEdge(int i, int j) {
    adj_list[i].erase(j);
    adj_list[j].erase(i);
    vertexes--;
}

bool GraphL::isEdge(int i, int j) {
    return adj_list[i].count(j) || adj_list[j].count(i);
}

void GraphL:: print() {
    for (auto it = adj_list.begin(); it !=adj_list.end(); it++) {
        std::cout << it->first <<" : ";
        for (auto is : it->second) {
            std::cout <<is <<", ";
        }
        std::cout << std::endl;
    }
}


void GraphL::bfs(int start) {
    if (!vertexes || start >= vertexes) return;

    std::vector<bool> used(vertexes, false);
    std::queue<int> q;
    int cur;
    q.push(start);
    used[start] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        std::cout << cur << ' ';
        
        for (auto i : adj_list[cur]) {
            if (!used[i]) {
                q.push(i);
                used[i] = true;
            }
        }
    }
}

void GraphL::dfs() {
    if (!vertexes) return;
    std::vector<bool> used(vertexes, false);
    std::stack<int> st;
    int cur;
    st.push(0);

    while (!st.empty()) {
        cur = st.top();
        st.pop();
        if (!used[cur]) {
            std::cout << cur << ' ';
            used[cur] = true;

        }
        for (auto i : adj_list[cur]) {
            if (!used[i]) {
                st.push(i);
            }
        }
    }
}