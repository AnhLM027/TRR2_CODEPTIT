#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define maxn 105
typedef long long ll;

const int INF = 1e9;

int n, st;
int parent[maxn], dist[maxn], a[maxn][maxn] = {};
vector<vector<int>> edge;

void Bellman_Ford() {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[st] = 0;
    for(int i = 1; i <= n - 1; i++) {
        for(vector<int> e : edge) {
            if(dist[e[1]] > dist[e[0]] + a[e[0]][e[1]]) {
                dist[e[1]] = dist[e[0]] + a[e[0]][e[1]];
                parent[e[1]] = e[0];
            }
        }
    }
}

int main() {
    cin >> n >> st;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] != 0) {
                edge.push_back({i, j});
            }
        }
    }
    
    Bellman_Ford();
    
    for(int i = 1; i <= n; i++) {
        cout << "K/c " << st << " -> " << i << " = ";
        if(dist[i] == INF) cout << "INF;" << endl;
        else {
            cout << dist[i] << ";        ";
            int u = i;
            if(u == st) cout << u << " <- ";

            while(u != st) {
                cout << u << " <- ";
                u = parent[u];
            } 
            cout << u << endl;
        }
    }
    return 0;
}