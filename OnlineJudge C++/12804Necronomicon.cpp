#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

int TOC = 0;
int HUN = 1;
int N_V = 2;

int l;

void dfs(int u, vector<int>& estado, vector<vector<int>>& adj, bool& posible, bool& bucle) {
	estado[u] = TOC;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == l)
			posible = true;
		else if (estado[v] == TOC) 
			bucle = true;
		else if (estado[v] == N_V)
			dfs(v, estado, adj, posible, bucle);
		if (posible && bucle) break;
	}
	estado[u] = HUN;
}

void r() {
	cin >> l;
	vector<vector<int>> adj(l);
	char c;
	int aux;
	for (int i = 0; i < l; ++i) {
		cin >> c;
		switch (c)
		{
		case 'A':
			adj[i].push_back(i + 1);
			break;
		case 'C':
			adj[i].push_back(i + 1);
		case 'J':
			cin >> aux;
			adj[i].push_back(aux - 1);
			break;
		default:
			break;
		}
	}

	vector<int> estado(l, N_V);
	bool posible = false, bucle = false;
	dfs(0, estado, adj, posible, bucle);

	if (!posible) cout << "NEVER\n";
	else if (bucle) cout << "SOMETIMES\n";
	else cout << "ALWAYS\n";


}

int main() {
	int n;
	cin >> n;
	while (n--)r();

	return 0;
}