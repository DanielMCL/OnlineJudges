#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <set>
#include <algorithm>
#include<queue>
#include<iomanip>
#include <tuple>
#include <cassert>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1000000;

#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;


struct comparador {
    bool operator()(pair<int, vi> p1, pair<int, vi> p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
    }
};


priority_queue<pair<int, vi>, vector<pair<int, vi>>, comparador> q;

int d2 = 0, solucion = 0;
int limites[3];
vvb vis;

void actualizarD2(int d, int coste, vi& v) {
    for (int i = 0; i < 3; ++i) {
        if (v[i] <= d && v[i] > d2) {
            d2 = v[i];
            solucion = coste;
        }
    }
}

vi pasar(vi& v, int i, int j, int &delta) {
    vi next = v;
    if (v[i] > 0 && v[j] < limites[j]) {
        delta = min(v[i], limites[j] - v[j]);
        next[i] -= delta;
        next[j] += delta;
    }
    return next;
}

int dijkstra(int d) {
    int sol = -1;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        vi v = p.second; int cost = p.first;
        if (!vis[v[0]][v[1]]) {
            vis[v[0]][v[1]] = true;
            actualizarD2(d, cost, v);
            if (d == d2) {
                break;
            }
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (i != j) {
                        int delta;
                        vi next = pasar(v, i, j, delta);
                        if (!vis[next[0]][next[1]]) {
                            q.push(mp(cost + delta, next));
                        }
                    }
        }
    }
    return sol;
}

void resuelveCaso() {
    d2 = 0;
    solucion = 0;
    while (!q.empty())q.pop();

    int d;
    cin >> limites[0] >> limites[1] >> limites[2] >> d;

    vis.assign(limites[0] + 1, vb(limites[1] + 1, false));

    vi aux; aux.push_back(0); aux.push_back(0); aux.push_back(limites[2]);
    q.push(mp(0, aux));

    dijkstra(d);

    cout << solucion << ' ' << d2 << '\n';
}

int main()
{
    int n;
    cin >> n;
    while (n-- > 0) resuelveCaso();

    return 0;
}