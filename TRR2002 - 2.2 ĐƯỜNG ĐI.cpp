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

#define maxn 105


int n, st, en, cnt = 0;
int a[maxn][maxn] = {}, path[maxn] = {};
bool vis[maxn] = {};

int cnt2() {
    int count = 0;

    for (int k = 1; k <= n; k++){
        if(a[st][k] && a[k][en]){
            count++;
        }
    }

    return count;
}

bool found = false;
vector<int> parent(105, -1);

void BFS() {
    queue<int> qe;
    qe.push(st);
    
    vis[st] = true;

    while(!qe.empty()) {
        int curr = qe.front(); qe.pop();
        
        if(curr == en) {
            found = true;
            break;
        }
        
        for (int i = 1; i <= n; i++){
            if(a[curr][i] && !vis[i]){
                vis[i] = true;
                parent[i] = curr;
                qe.push(i);
            }
        }
    }
}

int main() {
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int k; cin >> k;
    cin >> n >> st >> en;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if(k == 1) {
        cout << cnt2() << endl;
    }
    else {
        BFS();
        if(!found) cout << "0" << endl;
        else {
            vector<int> path;
            int cur = en;

            do {
                path.push_back(cur);
                cur = parent[cur];
            } while(cur != -1);

            reverse(path.begin(), path.end());

            for (int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }
        }
    }
    return 0;
}