#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
    //cout << vertex << endl;
    //Take action on vertex after entering the vertex
    current_cc.push_back(vertex);
    vis[vertex]=true;
    for(int child:g[vertex]){
        //cout << "Parent: " << vertex << " Child: " << child << endl;
        //Take action on child before entering the child node
        if(vis[child]) continue;
        dfs(child);
        //Take action on child after exiting the child node
    }
}

bool dfs_loop(int vertex,int parent){
    bool isLoop=false;
    vis[vertex]=true;
    vis[vertex]=true;
    for(int child:g[vertex]){
        if(vis[child] && child==parent) continue;
        if(vis[child]) return true;
        isLoop|=dfs_loop(child,vertex);
    }
    return isLoop;
}

int main(){
   int n,e; cin >> n >> e;
   for(int i=0;i<e;i++){
       int x,y; cin >> x >> y;
       g[x].push_back(y);
       g[y].push_back(x);
   }
   int ct=0;
   for(int i=1;i<=n;i++){
       if(vis[i]) continue;
       current_cc.clear();
        dfs(i); ct++;
       cc.push_back(current_cc);
   }
   //cout << ct << endl;
   cout << cc.size() << endl;
   for(auto c_cc:cc){
    for(int vertex:c_cc){
        cout << vertex << " ";
    } cout << endl;
   }
   bool isLoop=false;
   for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    if(dfs_loop(i,0)){
        isLoop=true;
        break;
    }
   }
   cout << "Loop Exists : " << isLoop << endl;
}