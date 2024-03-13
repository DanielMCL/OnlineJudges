#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include<queue>
#include<iomanip>
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

//using T = double;
//bool lt(double a, double b) { return a - EPS < b; };
//bool eq(double a, double b) { return fabs(a - b) < EPS; }

using T = int;
//bool lt(int a, int b) { return a < b; }
//bool eq(int a, int b) { return a == b; }

struct pt {
	T x, y;
	pt operator+(pt p) const { return { x + p.x, y + p.y }; }
	pt operator-(pt p) const { return { x - p.x, y - p.y }; }
	pt operator*(T d) const { return { x * d, y * d }; }
	pt operator/(T d) const { return { x / d, y / d }; } // only for floating-point

	bool operator==(pt o) const { return x == o.x && y == o.y; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator<(pt o) const { // sort points lexicographically
		if (x == o.x) return y < o.y;
		return x < o.x;
	}
};

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// positivo/cero/negativo: c a la izquieda/sobre/derecha de a-b
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

bool ccw(pt p, pt q, pt r) {
	return orient(p, q, r) > 0;
}

vector<pt> convexHull(vector<pt>& P) {
	int n = int(P.size()), k = 0;
	vector<pt> H(2 * n);
	sort(P.begin(), P.end());
	// build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	// build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

void r() {
	int l, n;
	cin >> l >> n;
	
	vector<pt> nails(n), convex;
	for (int i = 0; i < n; ++i) {
		cin >> nails[i].x >> nails[i].y;
	}
	convex = convexHull(nails);
	int m = convex.size();
	double length = 0;
	for (int i = 0; i < m - 1; ++i) {
		length += dist(convex[i], convex[i + 1]);
	}
	if (l > length) {
		cout << setprecision(5) << fixed << (double)l << '\n';
	}
	else cout << setprecision(5) << fixed << length << '\n';

}

int main() {
	int n;
	cin >> n;
	while (n--)r();

	return 0;
}