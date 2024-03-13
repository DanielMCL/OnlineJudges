#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include<queue>
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

int extendedEuclidRec(int a, int b, ll& u, ll& v) {
	if (!b) {
		u = 1;
		v = 0;
		return a;
	}
	int r = extendedEuclidRec(b, a % b, u, v);
	int uAux = v;
	int vAux = u - (a / b) * v;
	u = uAux;
	v = vAux;
	return r;
}

bool r() {
	int n;
	cin >> n;
	if (n == 0)return false;

	ll c1, n1, c2, n2, mcd, x, y;
	cin >> c1 >> n1 >> c2 >> n2;

	mcd = extendedEuclidRec(n1, n2, x, y);
	
	if (n % mcd != 0) {
		cout << "failed\n";
		return true;
	}


	x = x * n / mcd;
	y = y * n / mcd;
	
	if (c2*n1 > c1*n2) {		
		double lambda = -y * (double)mcd / (double)n1;
		int k = ceil(lambda);
		x -= k * n2 / mcd;
		y += k * n1 / mcd;
	}
	else {
		double lambda = -x * (double)mcd /(double) n2;
		int k = ceil(lambda);
		x += k * n2 / mcd;
		y -= k * n1 / mcd;
	}

	if(x <0 || y<0) {
		cout << "failed\n";
		return true;
	}

	/*while (y >= 0) {
		cost = x * c1 + y * c2;
		if (cost < minC) {
			minC = cost;
			sol1 = x;
			sol2 = y;
		}
		x += n2 / mcd;
		y -= n1 / mcd;
	}
	x = xOrg; y = yOrg;
	while (x >= 0) {
		cost = x * c1 + y * c2;
		if (cost < minC) {
			minC = cost;
			sol1 = x;
			sol2 = y;
		}
		x -= n2 / mcd;
		y += n1 / mcd;
	}*/

	cout << x << ' ' << y << '\n';

	return true;
}

int main() {
	while (r());

	return 0;
}