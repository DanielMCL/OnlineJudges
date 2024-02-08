#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


int main(){
	int n, k, a;
	cin >> n >> k;
	unordered_map<int, int> m;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		m[a]++;
	}
	for (auto e: m) {
		v.push_back(e.second);
	}
	sort(v.begin(), v.end(), greater<int>());

	int i = 1;
	while (i < v.size() && k > 0) {
		if (k >= i && v[0] > v[i]) {
			k -= i;
			--v[0];
		}
		else
			++i;
	}
	if (k >= v.size() - 1 && v[0] > v[v.size() - 1]) {
		k -= (v.size() - 1);
		--v[0];
	}
	while (k >= v.size()) {
		k -= v.size();
		--v[0];
	}

	cout << v[0] << '\n';

	return 0;
}