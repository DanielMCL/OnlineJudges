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


void dijkstra(int s, vi& dist, vvii adjList) {
    dist.assign(adjList.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({ 0, s });
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto a : adjList[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({ dist[a.second], a.second });
            }
        }
    }
}

struct ord {
    bool operator()(pair<ii, int> p1, pair<ii, int> p2) {
        return p1.second > p2.second;
    }
};

void r() {
    int n, m, s, t, p;
    cin >> n >> m >> s >> t >> p;
    s--; t--;
    vvii g(n), gInv(n);
    vector<pair<ii,int>> a(m);
    int org, dest, c;
    for (int i = 0; i < m; ++i) {
        cin >> org >> dest >> c;
        org--; dest--;
        a[i].first = mp(org, dest);
        a[i].second = c;
        g[org].push_back(mp(c, dest));
        gInv[dest].push_back(mp(c, org));
    }
    
    vi distS(n), distT(n);
    dijkstra(s, distS, g);
    dijkstra(t, distT, gInv);

    sort(a.begin(), a.end(), ord());

    int i = 0;
    bool sol = false;
    while (!sol && i < a.size()) {
        if (distS[a[i].first.first] + distT[a[i].first.second] + a[i].second <= p) {
            cout << a[i].second << '\n';
            sol = true;
        }
        i++;
    }
    if (!sol) {
        cout << -1 << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)r();

    return 0;
}