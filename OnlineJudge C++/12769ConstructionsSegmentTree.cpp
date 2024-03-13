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

class SegmentTree {
	vi st;
	vi lazy;
	int tam;

	void setLazyUpdate(int vertex, int value) {
		lazy[vertex] += value;
	}
	void pushLazyUpdate(int vertex, int l, int r) {
		st[vertex] += (r - l + 1) * lazy[vertex];
		if (l != r) {
			setLazyUpdate(2 * vertex, lazy[vertex]);
			setLazyUpdate(2 * vertex + 1, lazy[vertex]);
		}
		lazy[vertex] = 0;
	}

public:
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, 0);
		lazy.assign(4 * maxN + 10, 0);
		tam = maxN;
	}
	void build(int* values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(int* values, int p, int l, int r) {
		if (l == r) {
			st[p] = values[l];
			return;
		}
		int m = (l + r) / 2;
		build(values, 2 * p, l, m);
		build(values, 2 * p + 1, m + 1, r);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
	int query(int a, int b) {
		return query(1, 0, tam - 1, a, b);
	}
	int query(int vertex, int l, int r, int a, int b) {
		if(lazy[vertex]!=0) pushLazyUpdate(vertex, l, r);
		if (a > r || b < l)return 0;
		if (a <= l && b >= r) return st[vertex];
		int m = (l + r) / 2;
		return query(2 * vertex, l, m, a, b) + query(2 * vertex + 1, m + 1, r, a, b);
	}
	void update(int pos, int val) {
		update(1, 0, tam - 1, pos, val);
	}
	void update(int vertex, int l, int r, int pos, int val) {
		if (pos<l || pos >r) return;
		if (l == r) { st[vertex] = val; return; }
		int m = (l + r) / 2;
		update(2 * vertex, l, m, pos, val);
		update(2 * vertex + 1, m + 1, r, pos, val);
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
	}
	void updateRange(int a, int b, int val) {
		updateRange(1, 0, tam - 1, a, b, val);
	}
	void updateRange(int vertex, int l, int r, int a, int b, int val) {
		if (lazy[vertex] != 0) pushLazyUpdate(vertex, l, r);
		if (b < l || r < a)return;
		if (a <= l && r <= b) {
			setLazyUpdate(vertex, val);
			pushLazyUpdate(vertex, l, r);
			return;
		}
		int m = (l + r) / 2;
		updateRange(2 * vertex, l, m, a, b, val);
		updateRange(2 * vertex + 1, m + 1, r, a, b, val);
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
	}
};

bool r() {
	int t;
	cin >> t;
	if (t == 0) return false;

	SegmentTree st(100001);
	char c; int a, b, y;
	for (int i = 0; i < t; ++i) {
		cin >> c;
		if (c == 'B') {
			cin >> a >> b >> y;
			st.updateRange(a, b, y);
		}
		else if (c == 'Q') {
			cin >> a;
			cout << st.query(a, a) << '\n';
		}
	}

	return true;
}

int main() {
	while (r());

	return 0;
}