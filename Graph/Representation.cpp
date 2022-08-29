#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10; int graph1[N][N];
vector<pair<int,int>> graph2[N];
//number of vertices N & number of edges M are given
int main(){
    int n,m; cin >> n >> m;
    /* space complexity is concerning for this approach 
    for(int i=0;i<m;i++){
        int v1,v2; cin >> v1 >> v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
        for(int i=0;i<m;i++){
        int v1,v2,weight; cin >> v1 >> v2 >> weight;
        graph[v1][v2]=weight;
        graph[v2][v1]=weight;
    }*/
    //adjacency list - > space complexity enhanced : O(v+e)
    for(int i=0;i<m;i++){
        int v1,v2,wt; cin >> v1 >> v2 >> wt;
        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }
    /*for(int child:graph2[i]){
        if(child==j) {
            cout << child.second << endl;
        }
    }*/
}
