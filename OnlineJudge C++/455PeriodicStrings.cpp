#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include<queue>
#include<iomanip>
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

void kmpPreprocess(vector<int>& b, string s, int m) { 
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && s[i] != s[j]) j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

void r() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> b(n + 1);
	kmpPreprocess(b, s, n);
	int l = n - b[n];
	if (n % l == 0)cout << l << '\n';
	else cout << n << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--)r();

	return 0;
}