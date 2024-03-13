#include<iostream>
using namespace std;

void resuelveCaso() {
	int n;
	cin >> n;
	n = n / 100;
	cout << n << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--)resuelveCaso();

	return 0;
}