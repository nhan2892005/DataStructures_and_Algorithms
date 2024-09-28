/*
Using queue, complete function bool isBipartite(vector<vector<int>> graph) to determine if a graph is bipartite or not (the graph can be disconnected).
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : graph[u]){
                    if(color[v] == 0){
                        color[v] = -color[u];
                        q.push(v);
                    }else if(color[v] == color[u]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j]) graph[i].push_back(j);
        }
    }

    isBipartite(graph) ? cout << "Yes" : cout << "No";
    return 0;
}