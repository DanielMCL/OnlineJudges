#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, pos, cont = 0;
	cin >> n >> pos >> m;
	--pos;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	vector<bool>b(n, false);

	while (0 <= pos && pos < n && !b[pos] && v[pos] != m) {
		b[pos] = true;
		pos += v[pos];
		++cont;
	}

	if (0 > pos)
		cout << "left" << '\n';
	else if (pos >= n)
		cout << "right" << '\n';
	else if (v[pos] == m)
		cout << "magic" << '\n';
	else
		cout << "cycle" << '\n';
	cout << cont << '\n';

	return 0;
}