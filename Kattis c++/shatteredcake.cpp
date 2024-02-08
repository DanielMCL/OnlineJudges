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
	ll w;
	ll n, sol = 0;
	cin >> w >> n;
	ll we, le;
	for (int i = 0; i < n; ++i) {
		cin >> we >> le;
		sol += le * we;
	}
	cout << sol / w << '\n';

	return 0;
}