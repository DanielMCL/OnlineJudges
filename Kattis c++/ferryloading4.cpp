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

void r() {
	int l, m;
	cin >> l >> m;
	vi left;
	vi right;
	l = l * 100;
	int c;
	string side;
	for (int i = 0; i < m; ++i) {
		cin >> c >> side;
		if (side == "left")
			left.push_back(c);
		else
			right.push_back(c);
	}
	int sol = 0;
	int i = 0, j = 0, ocup;
	while (i < left.size() || j < right.size()) {
		ocup = 0;
		if (i < left.size()) {
			while (i < left.size() && ocup + left[i] < l) {
				ocup += left[i];
				++i;
			}
		}
		if (j < right.size() || i < left.size())
			sol = sol + 2;
		else
			sol++;
		ocup = 0;
		if (j < right.size()) {
			while (j < right.size() &&	ocup + right[j] < l) {
				ocup += right[j];
				++j;
			}
		}
	}
	cout << sol << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)r();

	return 0;
}