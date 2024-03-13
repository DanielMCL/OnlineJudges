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

string s;
vi v(13);

bool r() {
	cin >> s;
	if (s == "0")return false;
	
	if (s.size() > 8) {

		for (int i = 0; i < 13; ++i) {
			if (i < 13 - sz(s))
				v[i] = 0;
			else v[i] = s[i - 13 + sz(s)] - '0';
		}

		int cod = 0;
		for (int i = 0; i < 12; ++i) {
			if (i % 2 != 0)cod += v[i] * 3;
			else cod += v[i];
		}
		int rest = cod % 10;

		if (rest != 0) rest = 10 - rest;

		if (rest == v[12]) {
			if (v[0] == 0)
				cout << "SI EEUU\n";
			else if (v[0] == 5 && v[1] == 0)
				cout << "SI Inglaterra\n";
			else if (v[0] == 3 && v[1] == 8 && v[2] == 0)
				cout << "SI Bulgaria\n";
			else if (v[0] == 5 && v[1] == 3 && v[2] == 9)
				cout << "SI Irlanda\n";
			else if (v[0] == 5 && v[1] == 6 && v[2] == 0)
				cout << "SI Portugal\n";
			else if (v[0] == 7 && v[1] == 0)
				cout << "SI Noruega\n";
			else if (v[0] == 7 && v[1] == 5 && v[2] == 9)
				cout << "SI Venezuela\n";
			else if (v[0] == 8 && v[1] == 5 && v[2] == 0)
				cout << "SI Cuba\n";
			else if (v[0] == 8 && v[1] == 9 && v[2] == 0)
				cout << "SI India\n";
			else
				cout << "SI Desconocido\n";
		}
		else cout << "NO\n";
	}
	else {

		for (int i = 0; i < 8; ++i) {
			if (i < 8 - sz(s))
				v[i] = 0;
			else v[i] = s[i - 8 + sz(s)] - '0';
		}

		int cod = 0;
		for (int i = 0; i < 7; ++i) {
			if (i % 2 == 0)cod += v[i] * 3;
			else cod += v[i];
		}
		int rest = cod % 10;

		if (rest != 0) rest = 10 - rest;

		if (rest == v[7])cout << "SI\n";
		else cout << "NO\n";
	}

	return true;
}

int main() {
	while (r());

	return 0;
}