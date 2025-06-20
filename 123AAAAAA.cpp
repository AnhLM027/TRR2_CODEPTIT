#include<bits/stdc++.h>
using namespace std;
#define ll long long


int n,m,u;
vector<set<int>> ke(1005);
int c[105] = {};
bool vis[105] = {};
vector<int> ans;


int check(){
	int dem=0;
	for(int i=1;i<=n;i++){
		dem+=c[i] & 1;
	}
	if(dem==0) return 1;
	else if(dem ==2) return 2;
	return 0;
}

int cntDfs = 0;

void dfs(int v){
	vis[v]=true;
    cntDfs++;
    
	for(int x:ke[v]){
		if(!vis[x]){
			dfs(x);
		}
	}
}
int tplt(){
    memset(vis, false, sizeof vis);
	dfs(1);
    if(cntDfs < n) return 0;
	return check();
}
void euler(){
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int x=st.top();
		if(!ke[x].empty()){
			int y=*ke[x].begin();
			st.push(y);
			ke[x].erase(y);
			ke[y].erase(x);
		}
		else {
			st.pop();
			ans.push_back(x);
		}
	}
}
int main(){

	int t; cin>>t;
	if(t==1){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			ke[x].insert(y);
			ke[y].insert(x);
			c[x]++;
			c[y]++; 
		}
		cout << tplt();
	} 
	else if(t==2){
		cin>>n>>m>>u;
        for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			ke[x].insert(y);
			ke[y].insert(x);
		} 
		euler();
		reverse(ans.begin(),ans.end());
		for(int x: ans) cout<<x<<" ";
		
	}
 }