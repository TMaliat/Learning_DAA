#include<bits/stdc++.h>
using namespace std;


const int INF = 1000000007; // weight INF means there is no EDGE

struct EDGE {
	int w ;
	int to ;

};


int main() {
	int n;
	cin >> n;
	vector<vector<int>> adj; // adjacency matrix of graph
	int weight = 0;
	vector<bool> selected(n, false);
	vector<EDGE> min_e(n);
	min_e[0].w = 0;

	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
				v = j;
		}

		if (min_e[v].w == INF) {
			cout << "No MST!" << endl;
			exit(0);
		}

		selected[v] = true;
		weight += min_e[v].w;
		if (min_e[v].to != -1)
			cout << v << " " << min_e[v].to << endl;

		for (int to = 0; to < n; ++to) {
			if (adj[v][to] < min_e[to].w)
				min_e[to] = {adj[v][to], v};
		}
	}

	cout << weight << endl;
}