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
#include<cmath>

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

vb primo;

void criba(int n) {
	primo.assign(n, true);
	for (int i = 2; i < sqrt(n); ++i) {
		if (primo[i]) {
			int aux = i * 2;
			while (aux < n) {
				primo[aux] = false;
				aux += i;
			}
		}
	}
}

bool r() {
	int n, m, maxN = 0;
	cin >> n >> m;
	vi ms, ns;
	while (n != 0 || m != 0) {
		ms.push_back(m);
		ns.push_back(n);
		maxN = max(maxN, n);
		cin >> n >> m;
	}
	criba(maxN + 1);
	vi cuenta(maxN + 1, 0);
	int tot = 0;
	for (int i = 2; i < maxN; ++i) {
		if (primo[i])++tot;
		cuenta[i] = tot;
	}
	vi pot(6, 1);
	for (int i = 1; i < pot.size(); ++i) {
		pot[i] = 10 * pot[i - 1];
	}

	for (int i = 0; i < ms.size(); ++i) {
		double error = abs((double)cuenta[ns[i]] / (double)ns[i] - (1.0 / log(ns[i])));
		double margen = 1.0 / (double)pot[ms[i]];
		if (error < margen)cout << "Menor\n";
		else if (error > margen)cout << "Mayor\n";
		else cout << "Igual\n";
	}

	return true;
}

int main() {
	r();
	return 0;
}