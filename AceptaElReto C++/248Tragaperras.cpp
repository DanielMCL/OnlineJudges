#include<iostream>
using namespace std;

bool r() {
	int n;
	cin >> n;
	if (n == 0)return false;

	int p, sol = 0, curr = 0, ini = 0, total = 0;

	for (int i = 0; i < n; ++i) {
		cin >> p;
		curr += p;
		total += p;
		if (curr > sol) sol = curr;
		if (total > ini) ini = total;
		else if (curr < 0) curr = 0;
	}

	if (curr + ini > sol) sol = curr + ini;

	cout << sol << '\n';

	return true;
}

int main() {
	while (r());
	return 0;
}