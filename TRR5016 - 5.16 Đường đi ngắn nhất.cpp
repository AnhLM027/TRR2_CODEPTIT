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

int n;
int a[maxn][maxn] = {};
int parent[maxn][maxn];

void Floyd() {
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i][k] != INF && a[k][j] != INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0 || a[i][j] == 10000) a[i][j] = INF;
            else parent[i][j] = i;
        }
    }
    
    Floyd();
    
    int max_d = 0;
    vector<int> res;

    for(int v = 1; v <= n; v++) {
        for(int t = 1; t <= n; t++) {
            if (v != t && a[v][t] != INF && a[v][t] > max_d){
                vector<int> path;
                for(int tmp = t; tmp != v; tmp = parent[v][tmp]) {
                    path.push_back(tmp);
                }
                path.push_back(v);
                reverse(path.begin(), path.end());
                res = path;
                max_d = a[v][t];
			} 
        }
    }

    if(max_d == 0) cout << 0;
    else {
        int l = res.size();
        cout << res[0] << " " << res[l - 1] << " " << a[res[0]][res[l - 1]] << endl;
        for(int x : res) cout << x << " ";
    }
    return 0;
}