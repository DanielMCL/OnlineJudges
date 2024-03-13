#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int toN(vector<char>& v) {
	int n = 0, p = 1;
	for (int i = 7; i > -1; --i) {
		n += (v[i] - '0') * p;
		p = p * 10;
	}
	return n;
}

int rest(char c) {
	switch (c)
	{
	case 'T':
		return 0;
	case 'R':
		return 1;
	case 'W':
		return 2;
	case 'A':
		return 3;
	case 'G':
		return 4;
	case 'M':
		return 5;
	case 'Y':
		return 6;
	case 'F':
		return 7;
	case 'P':
		return 8;
	case 'D':
		return 9;
	case 'X':
		return 10;
	case 'B':
		return 11;
	case 'N':
		return 12;
	case 'J':
		return 13;
	case 'Z':
		return 14;
	case 'S':
		return 15;
	case 'Q':
		return 16;
	case 'V':
		return 17;
	case 'H':
		return 18;
	case 'L':
		return 19;
	case 'C':
		return 20;
	case 'K':
		return 21;
	case 'E':
		return 22;
	default:
		break;
	}
}

void vu(vector<int>& f, int p, int letra, int& resto, int& sol) {
	if (p < f.size()) {
		vu(f, p + 1, letra, resto, sol);
		int aux = resto;
		for (int i = 1; i < 10; ++i) {
			resto = (resto + f[p]) % 23;
			if (resto == letra) sol++;
			vu(f, p + 1, letra, resto, sol);
		}
		resto = aux;
	}
}

void r() {
	char aux;
	vector<char> v(8);
	vector<int> f;
	for (int i = 0; i < 8; ++i) {
		cin >> aux;
		if (aux == '?') {
			v[i] = '0';
			f.push_back(7 - i);
		}
		else v[i] = aux;
	}

	vector<int> f2(f.size());

	int p = 1, c = f.size()-1;
	for (int i = 0;c!=-1 && i < 8; ++i) {
		if (f[c] == i) {
			f2[c] = p % 23;
			--c;
		}
		p = p * 10;
	}

	int resto = toN(v) % 23;
	cin >> aux;
	int letra = rest(aux);

	int sol = 0;
	if (letra == resto)sol = 1;

	vu(f2, 0, letra, resto, sol);

	cout << sol << '\n';
}

int main() {
	int n;
	cin >> n;
	while (n--) { r(); }
	return 0;
}