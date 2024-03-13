#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include<queue>
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
	if (!cin)return 0;

	int sol = 1, div = 1;

	int mod = div % n;
	while (mod != 0) {
		sol++;
		div = mod * 10 + 1;
		mod = div % n;
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (r());

	return 0;
}