#include <iostream>
#include <random>
#include <chrono>
#include "AdjMatrix.h"
#include "AdjList.h"

double get_time(){
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}
void fill(Graph* adj_matrix) {
    for (auto i = 0; i < adj_matrix->get_size(); i++) {
        for(auto j = 0; j < adj_matrix->get_size(); j++) {
            int num = rand_uns(0, 20);
            if (num%2 == 0 && i!= j) {
                adj_matrix->addEdge(i, j);
            }
        }
    }
}
void fill(GraphL* adj_list, int vertCount) {
    for (auto i = 0; i < vertCount; i++) {
        for(auto j = 0; j < vertCount; j++) {
            int num = rand_uns(0, 20);
            if (num%2 == 0 && i!= j) {
                adj_list->addEdge(i, j);
            }
        }
    }
}

//convert -> Graph <->GraphL
std::map<int, std::set<int>> convertMtoL (vector<vector<bool>> &adj_matrix) {
    std::map<int, std::set<int>> adj_list;
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = i; j < adj_matrix.size(); j++) {
            if (adj_matrix[i][j]) {
                adj_list[i].insert(j);
                adj_list[j].insert(i);
            }
        }
    }
    return adj_list;
}

vector<vector<bool>> convertLtoM (std::map<int, std::set<int>> &adj_list) {
    vector<vector<bool>> adj_matrix (adj_list.size(), std::vector<bool> (adj_list.size(), false));
    for (auto i : adj_list) {
        for (auto j : i.second) {
            adj_matrix[i.first][j] = true;
            adj_matrix[j][i.first] = true;
        }
    }
    return adj_matrix;
}

vector<vector<char>> sea (int x, int y) {
    vector<vector<char>> islands(x, vector<char>(y, '0'));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            int  num = rand_uns(0, 100);
            if (num % 2 == 0) {
                islands[i][j] = '1';
            }
        }
    }
    return islands;
}

void print_sea (vector<vector<char>> &sea) {
    for (auto i :sea) {
        for (auto j : i) {
            cout << j <<", ";
        }
        cout << endl;
    }
}

//DONE
// Для обхода клетки вокруг
int columns[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int rows[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<vector<char>> &grid, std::vector<std::vector<bool>> &used, int row, int column) {
    int cur_col, cur_row;
    used[row][column] = true;
    for (int k = 0; k < 8; k++) {
        cur_col = column + columns[k];
        cur_row = row + rows[k];
        if (cur_col >= 0 && cur_col <= grid.size() - 1 && cur_row >= 0 && cur_row <= grid.size() - 1) {
            if (grid[cur_row][cur_col] != '0' && !used[cur_row][cur_col]) 
            dfs(grid, used, cur_row, cur_col);
        }
    }

}

int numIslands(vector<vector<char>> &grid){
    int N;
    vector<vector<bool>> used(grid.size(), std::vector<bool> (grid.size(), false));
    for(int i = 0; i++; i < grid.size()) {
        for(int j = 0; j++; j < grid.size()) {
            if(grid[i][j] == '1' && !used[i][j]) {
            //if(grid[i][j] != '0' && !used[i][j]) { 
                N++;
                dfs(grid, used, i, j);
            }
        }
    }
    return N;
}


vector<vector<char>>garden(int x) {
    vector<vector<char>> garden(x, vector<char>(x, 0)); // переписал на char, чтобы было проще использовать NumIslands 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            int num = rand_uns(0, 5);
            if (num > 3) {
                garden[i][j] = '0';
            }
            else if (num > 2) {
                garden[i][j] = '1';
            } else {
                garden[i][j] = num + '0';
            }
        }
    }
    return garden;
}

void print_garden (vector<vector<int>> &garden) {
    for (auto i : garden) {
        for (auto j : i) {
            cout << j <<" ";
        }
        cout <<endl;
    }
}

//TODO
int orangesRotting(vector<vector<char>> &grid) {
    if (numIslands(grid) > 1) return -1;
}

vector<vector<int>> gen_preq(int courses) {
    vector<vector<int>> list;
    set<pair<int, int>> c;
    int size = rand_uns(0, courses);
    for (int i = 0; i < size; i++) {
        vector<int> dep;
        int c1 = rand_uns(0, courses);
        int c2 = rand_uns(0, courses);
        if (c1 != c2) {
            c.insert(make_pair(c1,c2));
        }
    }
    for (auto it = c.begin(); it !=  c.end(); it++) {
        list.push_back(vector<int>{it->first, it->second});
    }
    for (auto i: list) {
        cout <<i[0] <<"--> "<<i[1] <<" ";
    }
    return list;
}

//TODO
bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    return true;
}



int main() {
    Graph* adj_matrix = new Graph(5);
    fill(adj_matrix);
    adj_matrix->print();
    adj_matrix->bfs(0);
    adj_matrix->bfs(1);
    adj_matrix->bfs(2);

    cout <<endl;
    GraphL* adj_list = new GraphL();
    fill(adj_list, 5);
    adj_list->print();
/*
    cout <<"Number of islands is" <<endl;
    vector<vector<char>> a = sea(5,5);
    cout <<endl;
    print_sea(a);
    cout <<numIslands(a)<< endl; //Количество островов в море?

    cout <<"Oranges" <<endl;
    vector<vector<int>> grid = garden(5);
    print_garden(grid);
    orangesRotting(grid);//За какое время созреют все фрукты? -1 если это невозможно

    cout <<"Course schedule" <<endl;
    int courses = rand_uns(1, 20);
    vector<vector<int>> prerequisites = gen_preq(courses);
    canFinish(courses, prerequisites); //Могу ли я закончить курс?
    std::cout << "" << std::endl;
    */
    return 0;
}
