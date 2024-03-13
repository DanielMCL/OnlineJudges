#include <iostream>
using namespace std;

void resuelveCaso() {
	long long int h, e, m;
	cin >> h >> e >> m;

	if (e * m < h)
		cout << "ENCENDIDOS";
	else if (e * m > h)
		cout << "HORAS";
	else
		cout << "AMBAS";
	cout << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		resuelveCaso();

	return 0;
}