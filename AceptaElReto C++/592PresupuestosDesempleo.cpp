#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool resuelveCaso() {
	long long int d, n, suma = 0;
	cin >> d >> n;
	if (!cin)return false;

	vector<long long int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		suma += v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	v.push_back(0);

	if (suma > d) {
		long long int des = 0, i = -1, cont = 0;
		while (des < suma - d) {
			++cont;
			++i;
			des += (v[i] - v[i + 1]) * cont;
		}
		des -= (v[i] - v[i + 1]) * cont;
		cout << int(v[i] - double(suma - d - des) / cont) << '\n';
	}
	else
		cout << v[0] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}