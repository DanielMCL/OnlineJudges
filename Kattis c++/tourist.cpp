#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

#define mp make_pair
#define Max(x,y,z,t) max(x, max(y, max(z, t)))

void r() { 
	int h, w;
	cin >> w >> h;

	vector<vector<char>> m(h + 1,vector<char>(w + 1));

	for (int i = 1; i < h + 1; ++i)
		for (int j = 1; j < w + 1; ++j)
			cin >> m[i][j];

	int f1, f2, p;

	vector<vector<vector<int>>> din(h + 1, vector<vector<int>>(h + 1, vector<int>(h+w, -100000)));

	if (m[1][1] == '*')
		din[1][1][0] = 1;
	else
		din[1][1][0] = 0;


	int suma;
	for (int i = 1; i < h + w - 1; ++i)
		for (int j = 1; j < min(h + 1, i + 2); ++j)
			for (int k = 1; k < min(h + 1, i + 2); ++k) {
				if (i - j + 1 < w && i - k + 1 < w && m[j][i - j + 2] != '#' && m[k][i - k + 2] != '#') {
					if (j == k) {
						din[j][k][i] = Max(din[j][k][i - 1], din[j][k - 1][i - 1],
							din[j - 1][k][i - 1], din[j - 1][k - 1][i - 1]) + (m[j][i - j + 2] == '*' ? 1 : 0);
					}
					else {
						din[j][k][i] = Max(din[j][k][i - 1], din[j][k - 1][i - 1],
							din[j - 1][k][i - 1], din[j - 1][k - 1][i - 1]) +
							(m[j][i - j + 2] == '*' ? 1 : 0) + (m[k][i - k + 2] == '*' ? 1 : 0);
					}
				}
			}
	
	cout << din[h][h][h + w - 2] << '\n';
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		r();
	}

	return 0;
}