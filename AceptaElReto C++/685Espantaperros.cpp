#include<iostream>
#include<vector>
using namespace std;

bool r() {
	int x, y, i, j;
	cin >> x >> y >> i >> j;
	if (x == 0 && y == 0 && i == 0 && j == 0)return false;

	if (x == i || y == j || x + y == i + j || x - y == i - j) {
		cout << "SI\n";
	}
	else cout << "NO\n";

	return true;
}

int main() {
	while (r());
	return 0;
}