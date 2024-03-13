#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define mp make_pair

using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

void color(vvi& g, int x, vi& vis, int& c1, int& c2) {
	c1 += 1;
	vis[x] = 1;
	for (int next : g[x]) {
		if (vis[next] == 0) {
			color(g, next, vis, c2, c1);
		}
	}
}

int din(vvi& m, vii& g, int a, int x) {
	if (a < 0)return 1000000;
	if (x >= g.size())return a;
	if (m[a][x] != -1)return m[a][x];
	int o1 = din(m, g, a, x + 1), o2 = din(m, g, a - g[x].first, x + 1), o3 = din(m, g, a - g[x].second, x + 1);

	return m[a][x] = min(o1, min(o2, o3));
}

bool r() {
	int n, p, a;
	cin >> n >> p >> a;
	if (!cin)return false;

	vvi g(n);
	int org, dest;
	for (int i = 0; i < p; ++i) {
		cin >> org>> dest;
		org--;
		dest--;
		g[org].push_back(dest);
		g[dest].push_back(org);
	}
	vi vis(n, 0);
	vii grupos;
	int sol = 0, c1, c2;

	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0) {
			c1 = 0; c2 = 0;
			color(g, i, vis, c1, c2);
			grupos.push_back(mp(c1, c2));
		}
	}

	vvi m(a + 1, vi(grupos.size(), -1));
	
	cout << a - din(m, grupos, a, 0) << '\n';

	return true;
}

int main() {
	while (r());
	return 0;
}