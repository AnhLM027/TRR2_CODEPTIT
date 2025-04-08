#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;


int check(vector<int> cnt) {
	int count = 0;
	for(int x : cnt) count += x & 1;
	if(count == 0) return 1;
	else if(count == 2) return 2;
	return 0;
}

void DFS(vector<vector<int>> dske, int u, vector<bool>& vis) {
    vis[u] = true;
    for(int v : dske[u]) {
        if(!vis[v]) DFS(dske, v, vis);
    }
}

bool tplt(vector<vector<int>>& dske, int& V) {
    int cnt = 0;
    vector<bool> vis(V + 1, false);
    for(int i = 1; i <= V; i++) {
        if(!vis[i]) {
            DFS(dske, i, vis);
            cnt++;
        }
    }
    return cnt == 1;
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
    //fstream cin("CT.in", ios::in);
    //fstream cout("CT.out", ios::out);
	int k; cin >> k;
	if(k == 1) {
		int V, E; cin >> V >> E;
        vector<vector<int>> dske(V + 1);
		vector<int> cnt(V + 1);
		for(int i = 0; i < E; i++) {
			int x, y; cin >> x >> y;
			cnt[x]++;
			cnt[y]++;
            dske[x].push_back(y);
            dske[y].push_back(x);
		}
        if(!tplt(dske, V)) {
            cout << "0";
            return 0;
        }
		cout << check(cnt) << endl;
	}
	else if(k == 2) {
		int V, E, u; cin >> V >> E >> u;
        vector<vector<int>> dske(V + 1);
        vector<vector<bool>> used(V + 1, vector<bool>(V + 1, false));
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