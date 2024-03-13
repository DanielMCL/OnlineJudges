#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

int rec(vector<vector<long long int>>& m, vector<vector<int>>& wind, int i, int a) {
	if (i == 0) {
		if (a == 0)return 0;
		else return INT_MAX / 2;
		
	}
	if (m[i][a] != -1) return m[i][a];

	m[i][a] = rec(m, wind, i - 1, a) - wind[i - 1][a] + 30;

	if (a > 0) {
		m[i][a] = min(m[i][a], (long long int)rec(m, wind, i - 1, a - 1) - wind[i - 1][a - 1] + 60);
	}
	if (a < 9) {
		m[i][a] = min(m[i][a], (long long int)rec(m, wind, i - 1, a + 1) - wind[i - 1][a + 1] + 20);
	}
	
	return m[i][a];
}

void r() {
	int x, d;
	cin >> x;
	d = x / 100;
	
	vector<vector<long long int>> m(d + 1, vector<long long int>(10, -1));
	vector<vector<int>> wind(d, vector<int>(10));
	for (int a = 9; a >= 0; --a) {
		for (int i = 0; i < d; ++i) {
			cin >> wind[i][a];
		}
	}

	cout << rec(m, wind, d, 0) << '\n' << '\n';
}

int main() {
	int n; 
	cin >> n;
	while (n--)r();

	return 0;
}