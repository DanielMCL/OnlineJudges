#include<iostream>
#include<algorithm>
using namespace std;

void r() {
	int n;
	cin >> n;

	bool mas = false;
	int maxi = 0, curr = 0, ant = 0, act, dif;
	for (int i = 0; i < n; ++i) {
		cin >> act;
		dif = act - ant;
		if (dif > maxi0) {
			maxi = dif;
			mas = false;
			curr = maxi - 1;
		}
		else if (dif > curr) {
			mas = true;
		}
		else if (dif == curr) {
			curr -= 1;
		}
		ant = act;
	}

	if (mas)cout << maxi + 1 << '\n';
	else cout << maxi << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--)r();
	return 0;
}