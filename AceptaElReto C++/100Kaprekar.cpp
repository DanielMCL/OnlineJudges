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

int asc(int n) {
	vi d(4); int r = 0;
	for (int i = 0; i < 4; ++i) {
		d[i] = n % 10;
		n /= 10;
	}
	sort(d.begin(), d.end(), greater <int>());
	for (int i = 3; i >=0; --i) {
		r *= 10;
		r += d[i];
	}
	return r;
}


int des(int n) {
	vi d(4); int r = 0;
	for (int i = 0; i < 4; ++i) {
		d[i] = n % 10;
		n /= 10;
	}
	sort(d.begin(), d.end(), greater <int>());
	for (int i = 0; i < 4; ++i) {
		r *= 10;
		r += d[i];
	}
	return r;
}

void r() {
	int n, d;
	cin >> n;
	int cont = 0;
	while (cont < 8 && n != 6174) {
		d = des(n);
		n = asc(n);
		//cout << n << '\n' << d << '\n';
		n = d - n;
		++cont;
	}

	cout << cont << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--)r();

	return 0;
}