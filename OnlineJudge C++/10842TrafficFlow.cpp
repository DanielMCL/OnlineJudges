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


vector<vector<char>> tab;



void r(int numCaso) {
	int n, m;
	cin >> n >> m;

	vvi ady(n);
	vector<pair<int, ii>> roads;
	int org, dest, cap;
	for (int i = 0; i < m; ++i) {
		cin >> org >> dest >> cap;
		roads.push_back(mp(cap, mp(org, dest)));
	}


}

int main() {
	int n, cont = 0;
	cin >> n;
	while (n--)r(cont++);

	return 0;
}