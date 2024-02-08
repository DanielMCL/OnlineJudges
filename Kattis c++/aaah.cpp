#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

#define mp make_pair
#define Max(x,y,z,t) max(x, max(y, max(z, t)))

int main() {
	string s1, s2;
	cin >> s1>>s2;

	if (s1.length() < s2.length())
		cout << "no\n";
	else
		cout << "go\n";

	return 0;
}