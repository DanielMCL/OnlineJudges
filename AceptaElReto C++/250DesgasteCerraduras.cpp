#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool r() {
	int n;
	cin >> n;
	if (n == 0)return false;

	vector<int> v(n);
	float p, veces = 0;
	int sol = 0;

	for (int i = 0; i < n; ++i) {
		cin >> p;
		v[i] = veces;
		veces += p;
	}

	int min = veces/2;
	for (int i = 0; i < n; ++i) {
		if (abs(veces / 2 - v[i]) < abs(min)) {
			min = veces / 2 - v[i];
			sol = i;
		}
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (r());
	return 0;
}