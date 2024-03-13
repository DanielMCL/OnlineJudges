#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int numDirs = 4;
const pair<int, int> dir[numDirs] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2) {
	return { p1.first + p2.first, p1.second + p2.second };
}

void vuelta(vector<vector<char>>& m, int& sol, int pasos, pair<int ,int> p, pair<int, int> t) {
	switch (m[p.first][p.second]) {
	case 'T':
		sol = min(sol, pasos);
		break;
	case '.':
		if (pasos + abs(p.first - t.first) + abs(p.second - t.second) < sol) {
			m[p.first][p.second] = '#';
			for (int i = 0; i < numDirs; ++i)
				vuelta(m, sol, pasos + 1, p + dir[i], t);
			m[p.first][p.second] = '.';
		}
		else
			cout << '*';
	}
}

bool mejorCamino(vector<vector<char>>& m, int entrada, int& sol, pair<int, int> t) {
	sol = 1E6;
	m[m.size() - 1][entrada] = '#';
	vuelta(m, sol, 1, { m.size() - 2 , entrada}, t);
	m[m.size() - 1][entrada] = '.';
	if (sol == 1E6)
		return false;
	return true;
}

int avanza(vector<vector<char>>& m, pair<int, int> entrada, int di, pair<int, int> p, int pasos) {
	if (p == entrada)
		return 0;
	if (m[p.first][p.second] == 'T')
		return pasos;
	while (m[(p + dir[di]).first][(p + dir[di]).second] == '#') {
		di = (di + 1) % 4;
	}
	avanza(m, entrada, (di + 3) % 4, p + dir[di], pasos + 1);
}

bool derecha(vector<vector<char>>& m, int entrada, int& sol) {
	if (m[m.size() - 2][entrada] == '#')return false;
	sol = avanza(m, { m.size() - 1, entrada }, 1, { m.size() - 2 , entrada }, 1);
	if (sol == 0)
		return false;
	return true;
}

bool resuelveCaso() {
	int a, b;
	cin >> b >> a;
	if (!cin)return false;
	vector<vector<char>> m(a, vector<char>(b));

	pair<int, int> t;
	for (int i = 0; i < a - 1; ++i)
		for (int j = 0; j < b; ++j) {
			cin >> m[i][j];
			if (m[i][j] == 'T')
				t = { i, j };
		}

	int entrada;
	for (int j = 0; j < b; ++j) {
		cin >> m[a - 1][j];
		if (m[a - 1][j] == '.')
			entrada = j;
		else if (m[a - 1][j] == 'T') {
			cout << "IGUAL" << '\n';
			return true;
		}
	}

	int corto, der;
	if (!mejorCamino(m, entrada, corto, t)) {
		cout << "IMPOSIBLE" << '\n';
		return true;
	}
	else if (!derecha(m, entrada, der)) {
		cout << "INF";
	}
	else if (der == corto)
		cout << "IGUAL";
	else
		cout << der - corto;

	cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}