#include<iostream>
using namespace std;

bool r() {
	int n;
	cin >> n;
	if (n == 0)return false;

	int ant, curr;
	cin >> ant;
	bool si = true;
	for (int i = 1; i < n; ++i) {
		cin >> curr;
		si = si && curr > ant;
		ant = curr;
	}
	if (si)
		cout << "SI";
	else
		cout << "NO";
	cout << '\n';

	return true;
}

int main() {
	while (r());
	return 0;
}