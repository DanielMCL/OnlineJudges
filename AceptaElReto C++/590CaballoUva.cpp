#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool resuelveCaso() {
	int n, u;
	cin >> n >> u;
	if (n == 0 && u == 0)return false;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int i = 0, j = 0, minim = 2E9, suma = 0;
	while (i < v.size() && j <= v.size()) {
		if (suma >= u) {
			minim = min(minim, suma);
			suma -= v[i];
			++i;
		}
		else {
			if (j < v.size())
				suma += v[j];
			++j;
		}
	}

	if (minim != 2E9)
		cout << minim << '\n';
	else
		cout << "IMPOSIBLE" << '\n';
	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}