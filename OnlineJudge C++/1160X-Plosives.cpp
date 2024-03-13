#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
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

struct Uf {
	vector<int> p;
	int num;
	Uf(int n) :p(n, 0), num(n) {
		for (int i = 0; i < n; ++i)p[i] = i;
	}
	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}
	void merge(int x, int y) {
		int i = find(x), j = find(y);
		if (i == j)return;
		p[i] = j;
		num--;
	}
};

bool r() {
	int x, y;
	cin >> x >> y;
	if (!cin)return false;

	Uf uf(1e5 + 1);
	vector<bool> ap(1e5 + 1, false);

	uf.merge(x, y);
	ap[x] = ap[y] = true;

	int sol = 0;
	cin >> x;
	while (x != -1) {
		cin >> y;
		if (uf.find(x) == uf.find(y)) sol++;
		else uf.merge(x, y);
		cin >> x;
	}

	cout << sol << '\n';
	return true;
}

int main() {
	while (r());
	return 0;
}
