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

class Fenwick {
	vi ft;

public:
	Fenwick(int n) { ft.assign(n + 1, 0); }
	
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret += ft[b]; b -= (b & -b);
		}
		return ret;
	}

	void add(int pos, int val) {
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos);
		}
	}

	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}

	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};

bool r(int numCaso) {
	int n;
	cin >> n;
	if (n == 0)return false;

	Fenwick f(n);
	int aux;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		f.add(i + 1, aux);
	}

	cout << "Case " << numCaso << ":\n";
	string s; int x, y, r;
	cin >> s;
	while (s != "END") {
		if (s == "S") {
			cin >> x >> r;
			f.setValue(x, r);
		}
		else if (s == "M") {
			cin >> x >> y;
			cout << f.getSum(y) - f.getSum(x - 1) << '\n';
		}
		cin >> s;
	}
	cout << '\n';
	return true;
}

int main() {
	int cont = 1;
	while (r(cont++));

	return 0;
}