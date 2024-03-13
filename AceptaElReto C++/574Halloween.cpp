/*
Daniel María Carreño López

t= n
Coste= O(n)
*/

#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;

long long int longitudes(int n, vector<long long int>& v) {
	long long int aux;
	if (n == 1) {
		v.push_back(3);
		return 3;
	}
	else {
		aux = longitudes(n - 1, v) * 2 + n + 2;
		v.push_back(aux);
		return aux;
	}
}

long long int halloween(long long int n, long long int k, vector<long long int> v, bool inversion = false) {
	if (n==1){
		if (inversion) return 4 - k;
		return k;
	}
	if (k <= v[n - 2])
		return halloween(n - 1, k, v, inversion);
	if (k <= v[n - 2] + n + 2) {
		if (k == v[n - 2] + 1) {
			if (inversion)return 3;
			return 1;
		}
		if (k == v[n - 2] + n + 2) {
			if (inversion)return 1;
			return 3;
		}
		return 2;
	}
	return halloween(n - 1, v[n - 1] - k + 1, v, !inversion);
}

bool resuelveCaso() {
	long long int n, k;
	cin >> n >> k;
	if (!cin)return false;
	vector<long long int> v;
	longitudes(n, v);

	switch (halloween(n, k, v)) {
	case 1:
		cout << 'B';
		break;
	case 2:
		cout << 'U';
		break;
	case 3:
		cout << 'H';
		break;
	}
	cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}