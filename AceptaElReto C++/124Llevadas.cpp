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


bool r() {
	string a, b;
	cin >> a >> b;
	if (a == "0" && b == "0") return false;

	int sol = 0, llevada = 0, dif = sz(a) - sz(b);
	if (dif >= 0) {
		for (int i = sz(a); i >= dif; --i) {
			if (a[i] + b[i - dif] - 2 * '0' + llevada >= 10) {
				llevada = 1;
				sol++;
			}
			else llevada = 0;
		}
		while (dif > 0 && a[dif - 1] + llevada - '0' >= 10) {
			sol++;
			dif--;
		}
	}
	else {
		for (int i = sz(b); i >= -dif; --i) {
			if (a[i + dif] + b[i] - 2 * '0' + llevada >= 10) {
				llevada = 1;
				sol++;
			}
			else llevada = 0;
		}
		dif = -dif;
		while (dif > 0 && b[dif - 1] + llevada - '0' >= 10) {
			sol++;
			dif--;
		}
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (r());

	return 0;
}