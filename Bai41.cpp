#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;

#define maxn 1005

int n, st, a[maxn][maxn];

void Euler_Cycle(){
    vector<int> res;
    stack<int> stk;
    stk.push(st);
    while(!stk.empty()){
        int u = stk.top();
        bool check = true;
        for(int v = 1; v <= n; v++){
            if(a[u][v]){
                check = false;
                stk.push(v);
                a[u][v] = a[v][u] = 0;
                break;
            }
        }
        if(check){
            stk.pop();
            res.push_back(u);
        }
    }
    reverse(begin(res), end(res));
    for(auto x : res){
        cout << x << " ";
    }
}

int main(){
    cin >> n >> st;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    Euler_Cycle();
}