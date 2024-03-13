#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>
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

struct UF {
	vi p;
	int num;
	UF(int n) : p(n, 0), num(n) {
		for (int i = 0; i < n; ++i)p[i] = i;
	}
	int find(int x) {
		return (x == p[x]) ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		int i = find(x), j = find(y);
		if (i == j)return;
		p[i] = j;
		--num;
	}
};

double dist(pair<int, int> p1, pair<int, int> p2) {
	return sqrt((p1.first - p2.first)* (p1.first - p2.first) + (p1.second - p2.second)* (p1.second - p2.second));
}

void r() {
	int s, p;
	cin >> s >> p;
	vector<ii> v(p);

	for (int i = 0; i < p; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	vector<pair<double, ii>> ady;

	for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j) {
			if(i!=j)
				ady.push_back(mp(dist(v[i], v[j]), mp(i, j)));
		}
	sort(ady.begin(), ady.end());

	UF uf(p);
	double d = 0;
	for (auto ar : ady) {
		if (uf.find(ar.second.first) != uf.find(ar.second.second)) {
			uf.merge(ar.second.first, ar.second.second);
			d = max(d, ar.first);
			if (uf.num <= s)break;
		}
	}
	cout << setprecision(2) << fixed << d << '\n';
}

int main() {

	int n;
	cin >> n;
	while (n--)r();
	return 0;
}