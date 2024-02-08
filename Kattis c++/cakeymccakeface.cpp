#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;
using ii = pair<int, int>;
using vi = vector <int>;
using vvi = vector <vi>;
using vii = vector <ii>;
using vvii = vector <vii>;
using vb = vector <bool>;
using vvb = vector <vb>;
using ll = long long int;
using vll = vector <ll>;

#define sz(x) (int)(x.size())
#define fi first
#define se second
#define mp make_pair

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<ll, ll> map;
	vll e(n);
	ll s;

	for (int i = 0; i < n; ++i)
		cin >> e[i];

	for (int i = 0; i < m; ++i) {
		cin >> s;
		for (int j = 0; j < n; ++j) {
			if (s - e[j] >= 0) {
				map[s - e[j]] += 1;
			}
		}
	}

	ll sol = 1000000000000, max = -1;
	for (auto elem : map) {
		if (elem.second > max || (elem.second == max && elem.first < sol)) {
			max = elem.second;
			sol = elem.first;
		}
	}

	if (sol == 1000000000000)sol = 0;

	cout << sol;

	return 0;
}