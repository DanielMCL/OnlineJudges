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

void f(int i) {
	switch (i) {
	case -1:
		cout << "MARTES ";
		break;
	case 0:
		cout << "MIERCOLES ";
		break;
	case 1:
		cout << "JUEVES ";
		break;
	case 2:
		cout << "VIERNES ";
		break;
	case 3:
		cout << "SABADO ";
		break;
	case 4:
		cout << "DOMINGO ";
		break;
	}
}

bool r() {
	double m;
	cin >> m;
	if (m == -1)return false;

	vector<double> v(7);
	bool emMax = false, emMin = false;
	double max = m, min = m, total = m;
	int indMax = -1, indMin = -1;

	for (int i = 0; i < 5; ++i) {
		cin >> v[i];
		total += v[i];
		if (v[i] == max) {
			emMax = true;
		}
		if (v[i] == min) {
			emMin = true;
		}
		if (v[i] > max) {
			indMax = i;
			max = v[i];
			emMax = false;
		}
		if(v[i]<min) {
			indMin = i;
			min = v[i];
			emMin = false;
		}
	}

	if (emMax)cout << "EMPATE ";
	else f(indMax);
	if (emMin)cout << "EMPATE ";
	else f(indMin);
	if (v[4] > total / 6)cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while (r());

	return 0;
}