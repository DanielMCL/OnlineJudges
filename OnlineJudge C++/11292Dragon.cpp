#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool r() {
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0)return false;
	vector<int>c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<int>k(m);
	for(int i = 0; i < m; ++i) {
		cin >> k[i];
	}
	sort(c.begin(), c.end());
	sort(k.begin(), k.end());
	int i = 0, j = 0, sol = 0;
	while (i < n && j < m) {
		while (j < m && c[i] > k[j])j++;
		if (j < m) {
			sol += k[j];
			i++;
			j++;
		}
	}
	if (i == n) {
		cout << sol << '\n';
	}
	else cout << "Loowater is doomed!\n";

	return true;
}

int main() {
	while (r());

	return 0;
}