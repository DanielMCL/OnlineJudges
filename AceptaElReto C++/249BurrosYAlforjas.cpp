#include<iostream>
#include<vector>
using namespace std;

void r() {
	int n, b;
	cin >> b >> n;

	vector<bool> v(200001, false);
	int p, sol = 0;

	for (int i = 0; i < n; ++i) {
		cin >> p;
		if (v[p]) {
			v[p] = false;
			sol++;
		}
		else
			v[p] = true;
	}

	if (sol > b)sol = b;
	cout << sol << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--) { r(); }
	return 0;
}