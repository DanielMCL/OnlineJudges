#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>

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

void inorden(int nodo, int p, vvi& m, bool derecha) {
    int n = sz(m[nodo]);
    bool padre = false;
    //cout << n << '\n';
    int aLaIzquierda = n / 2;
    if (derecha && n%2==0)aLaIzquierda--;
    for (int i = 0; i < aLaIzquierda; ++i) {
        if (m[nodo][i] == p) padre = true;
        else inorden(m[nodo][i], nodo, m, false);
    }
    if (padre) { 
        inorden(m[nodo][aLaIzquierda], nodo, m, false); 
        aLaIzquierda++;
    }
    cout << nodo << ' ';
    for (int i = aLaIzquierda; i < n; ++i) {
        if (m[nodo][i] != p) inorden(m[nodo][i], nodo, m, true);
    }
}

int main() {
    int n;
    cin >> n;
    int n1, n2;
    vvi m(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n - 1; ++i) {
        cin >> n1 >> n2;
        m[n1].push_back(n2);
        m[n2].push_back(n1);
    }

    int i = 0;
    n = sz(m[0]);
    while (i < n / 2) {
        //cout << m[0][i] <<'\n';
        //cout <<"nodo " << i << " iz: "<<m[0][i]<<'\n';
        inorden(m[0][i], 0, m, false);
        ++i;
    }
    cout << 0 << ' ';
    while (i < n) {
        //cout <<"nodo " << i << " der: "<<m[0][i]<<'\n';
        inorden(m[0][i], 0, m, true);
        ++i;
    }
    cout << '\n';

    return 0;
}