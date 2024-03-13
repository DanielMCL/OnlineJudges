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

bool r() {
	ll aux, tot = 0;
	cin >> aux;
	if (aux == 0)return false;
	ll sol = aux;
	tot += aux;
	cin >> aux;
	while (aux != 0) {
		sol = __gcd(aux, sol);
		tot += aux;
		cin >> aux;
	}
	cout << tot / sol << '\n';

	return true;
}

int main() {
	while (r());

	return 0;
}