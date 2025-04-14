#include <bits/stdc++.h>
using namespace std;

#define maxn 105

vector<vector<int>> a(maxn, vector<int>(maxn));
vector<set<int>> dske(maxn);
vector<vector<int>> res;
vector<int> path;
vector<bool> vis(maxn, false);

int V, u;
int MIN = INT_MAX;
int sum = 0;

void Hamilton(int i) {
    for(int j = 1; j <= V; j++) {
        if(!vis[j] && a[path[i - 1]][j] != 10000 && a[path[i - 1]][j]) {
            vis[j] = true;
            path.push_back(j);
            sum += a[path[i - 1]][j];
            // for(int x : path) cout << x << " ";
            // cout << endl;

            if(i == V + 1) {
                if(path[1] == path[i]) {
                    if(sum < MIN) {
                        res.push_back(path);
                        MIN = sum;
                    }
                }
            }
            else if(i <= V) Hamilton(i + 1);
            sum -= a[path[i - 1]][j];
            path.pop_back();
            vis[j] = false;
        }
    }
}

int main() {
    // freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);
    cin >> V >> u;
    
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) cin >> a[i][j];
    }

    path.push_back(0);
    path.push_back(u);
    
    Hamilton(2);
    
    if(res.size() > 0) {
        cout << MIN << endl;
        int l = res.size() - 1;
        for(int i = 1; i < res[l].size(); i++) cout << res[l][i] << " ";
    }
    else cout << "0" << endl;
    return 0;
}