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
	int n, cm = -1, cm2, aux = 0;
	cin >> n;
	if (n == 0)return false;
	vvi m(n, vi(n));
	vi v(n * n + 1, 0);
	bool diab = true, esot = true;
	for (int i = 0; i < n; ++i) {
		aux = 0;
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
			aux += m[i][j];
			if (m[i][j] <= n * n && v[m[i][j]] == 0)v[m[i][j]] += 1;
			else esot = false;
		}
		if (cm != -1 && aux != cm)diab = false;
		else cm = aux;
	}
	if (diab) {
		aux = 0;
		for (int i = 0; i < n; ++i) {
			aux += m[i][i];
		}
		if (aux != cm)diab = false;
		aux = 0;
		for (int i = 0; i < n; ++i) {
			aux += m[i][n - i - 1];
		}
		if (aux != cm)diab = false;
		for (int i = 0; i < n && diab; ++i) {
			aux = 0;
			for (int j = 0; j < n && diab; ++j) {
				aux += m[j][i];
			}
			if (aux != cm)diab = false;
		}
		if (4 * cm % n != 0)esot = false;
		if (esot) {
			cm2 = 4 * cm / n;
			aux = 0;
			aux = m[0][0] + m[0][n - 1] + m[n - 1][n - 1] + m[n - 1][0];
			if (aux != cm2)esot = false;
			if (esot && n % 2 != 0) {
				aux = m[0][n/2] + m[n/2][0] + m[n - 1][n/2] + m[n/2][n-1];
				if (aux != cm2)esot = false;
				if (cm2 != m[n / 2][n / 2] * 4)esot = false;
			}
			else if (esot) {
				aux = m[0][n / 2] + m[n / 2][0] + m[n - 1][n / 2] + m[n / 2][n - 1] + m[0][n / 2 - 1] + m[n / 2 - 1][0] + m[n - 1][n / 2 - 1] + m[n / 2 - 1][n - 1];
				if (aux != cm2 * 2)esot = false;
				aux = m[n / 2][n / 2] + m[n / 2 - 1][n / 2] + m[n / 2][n / 2 - 1] + m[n / 2 - 1][n / 2 - 1];
				if (aux != cm2)esot = false;
			}
		}
	}
	
	if (!diab)
		cout << "NO";
	else if (!esot)
		cout << "DIABOLICO";
	else cout << "ESOTERICO";
	cout << '\n';
	return true;
}

int main() {
	while (r());

	return 0;
}