#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;
#define maxn 105

int check(vector<int> cnt) {
	int count = 0;
	for(int x : cnt) count += x & 1;
	if(count == 0) return 1;
	else if(count == 2) return 2;
	return 0;
}

int cntDfs = 0;

void DFS(vector<vector<int>> dske, int u, vector<bool>& vis) {
    vis[u] = true;
    cntDfs++;
    for(int v : dske[u]) {
        if(!vis[v]) DFS(dske, v, vis);
    }
}

int checkEuler(vector<vector<int>>& dske, int& V, vector<int>& cnt) {
    vector<bool> vis(maxn, false);
    DFS(dske, 1, vis);
    if(cntDfs < V) return 0;

    return check(cnt);
}

void Euler(int u, vector<vector<int>>& dske, vector<vector<bool>>& used, vector<int>& path) {
    for(int i = 0; i < dske[u].size(); ++i) {
        int v = dske[u][i];
        if(!used[u][v]) {
            used[u][v] = used[v][u] = true;
            Euler(v, dske, used, path);
        }
    }
    path.push_back(u);
}


int main() {
    // fstream cin("CT.INP", ios::in);
    // fstream cout("CT.OUT", ios::out);
	int k; cin >> k;
	if(k == 1) {
		int V, E; cin >> V >> E;
        vector<vector<int>> dske(maxn);
		vector<int> cnt(maxn);
		for(int i = 0; i < E; i++) {
			int x, y; cin >> x >> y;
			cnt[x]++;
			cnt[y]++;
            dske[x].push_back(y);
            dske[y].push_back(x);
		}
		cout << checkEuler(dske, V, cnt) << endl;
	}
	else if(k == 2) {
		int V, E, u; cin >> V >> E >> u;
        vector<vector<int>> dske(maxn);
        vector<vector<bool>> used(maxn, vector<bool>(maxn, false));
        for (int i = 0; i < E; i++) {
            int x, y; cin >> x >> y;
            dske[x].push_back(y);
            dske[y].push_back(x);
        }
        for(int i = 1; i <= V; i++) {
            sort(dske[i].begin(), dske[i].end());
        }
        vector<int> path;
        Euler(u, dske, used, path);
        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
	}
	return 0;
}