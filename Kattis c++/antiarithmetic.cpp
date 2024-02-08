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

bool r() {
	int n;
	cin >> n;
	if (n == 0)return false;

	char c;
	cin >> c;
	vi v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	bool sol = true;
	int delta;
	for (int i = 0; i < n; ++i) {
		vi deltas(2 * n, 0);
		for (int j = 0; j < i; ++j) {		
			delta = v[i] - v[j];
			deltas[delta + n] = 1;
		}
		for (int j = i + 1; j < n; ++j) {
			delta = v[j] - v[i];
			if (deltas[delta + n] == 1) {
				sol = false;
				break;
			}
		}
	}

	if (sol)cout << "yes";
	else cout << "no";
	cout << '\n';

	return true;
}

int main() {
	while (r());


	return 0;
}