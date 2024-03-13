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

bool r() {
	int g, n;
	cin >> g;
	if (g == 20)return false;

	vi v(g + 1);
	for (int i = g; i >= 0; --i) {
		cin >> v[i];
	}
	cin >> n;

	double area = 0;

	double alt;

	for (int i = 0; i < n; ++i) {
		double x = i / (double)n;
		double aux = 1;
		alt = 0;
		for (int j = 0; j <= g; ++j) {
			alt += v[j] * aux;
			aux *= x;
		}
		alt = max(alt, 0.0);
		alt = min(alt, 1.0);
		area += alt * 1/(double)n;
	}
	//cout << area << '\n';
	if (area > 0.5005)cout << "CAIN\n";
	else if (area < 0.4995) cout << "ABEL\n";
	else cout << "JUSTO\n";

	return true;
}

int main() {
	while (r());

	return 0;
}