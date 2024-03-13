#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
const double EPS = 1e-9;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;


struct UFDS {
	vector<int> p;
	int numSets;
	UFDS(int n) : p(n, 0), numSets(n) {
		for (int i = 0; i < n; ++i) p[i] = i;
	}
	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		int i = find(x), j = find(y);
		if (i == j) return;
		p[i] = j;
		--numSets;
	}
};

void r(int numCaso) {
	int n, r, Q;
	cin >> n >> r;


	vector<pair<int, ii>>roads; 

	int a, b, l;
	for (int i = 0; i < r; ++i) {
		cin >> a >> b >> l;
		roads.push_back(mp(l,mp(a - 1, b - 1)));
	}

	sort(roads.begin(), roads.end());
	vvii ady(n);
	UFDS uf(n);
	int minRoad = INT_MAX;
	for (auto r : roads) {
		int org = r.second.first, dest = r.second.second;
		if (uf.find(org) != uf.find(dest)) {
			uf.merge(org, dest);
			ady[org].push_back(mp(dest, r.first));
			ady[dest].push_back(mp(org, r.first));
			minRoad = min(minRoad, r.first);
			if (uf.numSets == 1) break;
		}
	}


	cin >> Q;
	int k, t, sol = 0;
	cout << "Case " << numCaso << '\n';
	for (int i = 0; i < Q; ++i) {
		cin >> k >> t; k--; t--;
		queue<ii> q;
		q.push(mp(k, 0));
		vi vis(n, false);
		vis[k] = true;
		while (!q.empty()) {
			ii x = q.front(); q.pop();
			if (x.first == t) {
				sol = x.second;
				break;
			}
			for (auto next : ady[x.first]) {
				if (!vis[next.first]) {
					vis[next.first] = true;
					q.push(mp(next.first, max(x.second, next.second)));
				}
			}
		}
		cout << sol << "\n\n";
	}
}

int main() {
	int n, cont = 1;
	cin >> n;
	while (n--)r(cont++);

	return 0;
}