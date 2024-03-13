#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<numeric>
#include <string>
#include<cmath>
#include <bitset>

using namespace std;
using ii = pair<int, int>;
using vi = vector <int>;
using vvi = vector <vi>;
using vii = vector <ii>;
using vvii = vector <vii>;
using vb = vector <bool>;
using vvb = vector <vb>;
using ll = long long int;
using vll = vector <ll>;

#define sz(x) (int)(x.size())
#define fi first
#define se second
#define mp make_pair

int const MAX = 1e9;
int const MAX_P = 4e4;

bitset<MAX_P + 1> bs; // #include <bitset>
vector<ll> primes; // unsigned int
void sieve() {
	bs.set(); // De momento, todos son primos
	bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
	for (ll i = 2; i <= MAX_P; ++i) {
		if (bs[i]) {
			// El actual es primo. Tiramos sus
			for (ll j = i * i; j <= MAX_P; j += i)
				bs[j] = 0; // i*i en el for ¡Cuidado con el rango!
			primes.push_back(i);
		} // if es primo
	} // for
}




bool r() {
	int n;
	cin >> n;
	if (n == 0) return false;

	/*vi fact;
	int ind = 1, i = n;
	while (primes[ind] * primes[ind] <= i) { // ¡Mucho mejor que sqrt!
		while (!(i % primes[ind])) {
			fact.push_back(primes[ind]);
			i /= primes[ind];
		}
		++ind;
	}
	if (i != 1)
		fact.push_back(i);*/

	int div = 2, sol = 1;
	while (div * div <= n) {
		if (n % div == 0) sol = div;
		++div;
	}

	cout << n / sol << '\n';

	return true;
}

int main() {
	//sieve();
	
	while (r());

	return 0;
}