#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>

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
	int n;
	cin >> n;
	ll a;
	vll v(3, 0), sol(3);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		v[(i + 1) % 3] += a;
	}
	ll b;
	for (int i = 0; i < n; ++i) {
		cin >> b;
		sol[(i + 1) % 3] += b * v[0];
		sol[(i + 2) % 3] += b * v[1];
		sol[(i + 3) % 3] += b * v[2];
	}

	cout << sol[0] << ' ' << sol[1] << ' ' <<  sol[2] << '\n';

	return 0;
}