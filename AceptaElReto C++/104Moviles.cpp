#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<numeric>
#include <string>

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

pair<bool,int> fun() {
	int pi, pd, di, dd;
	cin >> pi >> di >> pd >> dd;
	bool ans = true ;
	if (pi == 0) {
		auto f = fun();
		ans = ans && f.first;
		pi = f.second;
	}
	if (pd == 0) {
		auto f = fun();
		ans = ans && f.first;
		pd = f.second;
	}
	ans = ans && (pi * di == pd * dd);
	return mp(ans, pi + pd);
}

bool r() {
	int pi, pd, di, dd;
	cin >> pi >> di >> pd >> dd;
	if (di == 0 && dd == 0 && pi == 0 && pd == 0)return false;
	bool ans = true;
	if (pi == 0) {
		auto f = fun();
		ans = ans && f.first;
		pi = f.second;
	}
	if (pd == 0) {
		auto f = fun();
		ans = ans && f.first;
		pd = f.second;
	}
	ans = ans && (pi * di == pd * dd);
	//cout << pi << ' ' << pd << '\n';
	if (ans)cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while (r());

	return 0;
}