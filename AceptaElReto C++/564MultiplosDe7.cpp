#include<iostream>
using namespace std;


void r() {
	int n; 
	cin >> n;

	cout << n / 3 << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--) { r(); }


	return 0;
}