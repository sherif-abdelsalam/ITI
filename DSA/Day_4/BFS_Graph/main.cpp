#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 11;
int adj[N][N];
bool vis[N];



vector<int> bfs() {
    queue<int> q;
    int start = 1;
    q.push(start);
    vis[start] = true;

    vector<int> res;
    res.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child = 0; child < N; child++) {
            if (adj[node][child] == 1 && !vis[child]) {
                vis[child] = true;
                q.push(child);
                res.push_back(child);
            }
        }
    }
    return res;
}

vector<int> dfsPath;

void dfs(int node) {
    vis[node] = true;
    dfsPath.push_back(node);
    for (int child = 0; child < N; child++) {
        if (adj[node][child] == 1 && !vis[child]) {
            dfs(child);
        }
    }
}

int main() {

    int edges[][2] = {
        {1, 4}, {1, 2}, {4, 3}, {3, 2}, {3, 10}, {3, 9},
        {2, 5}, {2, 7}, {2, 8}, {5, 6}, {5, 7}, {5, 8}, {7, 8}
    };

    int edgesSize = 13;

    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        adj[from][to] = 1;
        adj[to][from] = 1;
    }

//
//     vector<int>path = bfs();
//     for (int i = 0; i < path.size() -1; i++) cout<<path[i]<<" -> ";
//     cout<<path[path.size() -1]<<endl;

    dfs(1);
    for (int i = 0; i < dfsPath.size() - 1; i++)
        cout << dfsPath[i] << " -> ";
    cout << dfsPath.back() << endl;

    return 0;
}
