#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define mp make_pair

using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

bool r() {
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 0)return false;

	char c;
	int suma = 0;
	bool dentro = false;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cin >> c;
			switch (c) {
			case'/':
			case'\\':
				suma += 1;
				dentro = !dentro;
				break;
			case '.':
				if (dentro)suma += 2;
				break;
			}
		}
	}

	cout << suma / 2 << '\n';

	return true;
}

int main() {
	while (r());
	return 0;
}