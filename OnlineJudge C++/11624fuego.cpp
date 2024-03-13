#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


pair<int, int> dir[4] = { {1,0},{-1,0},{0,1},{0 ,-1} };

pair<int, int> org;

queue<pair<int, int>> q;


bool dentro(int n, int m, int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(vector<vector<int>>& m) {
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (auto d : dir) {
            int x = p.first + d.first , y = p.second + d.second;
            int pasos = m[p.first][p.second] + 1;
            if (dentro(m.size(), m[0].size(), x, y) && pasos < m[x][y]) {
                m[x][y] = pasos;
                q.push(make_pair(x, y));
            }
        }
    }
}

int bfs2(vector<vector<int>>& m) {
    int n = m.size(), n2 = m[0].size();
    if (org.first == n - 1 || org.first == 0 || org.second == 0 || (org.second == n2 - 1))
        return 1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (auto d : dir) {
            int x = p.first + d.first, y = p.second + d.second;
            int pasos = m[p.first][p.second] + 1;
            if (dentro(m.size(), m[0].size(), x, y) && pasos < m[x][y]) {
                if (x == n - 1 || x == 0 || y == 0 || (y == n2 - 1)) {
                    return pasos + 1;
                }
                m[x][y] = pasos;
                q.push(make_pair(x, y));
            }
        }
    }
    return -1;
}

void resuelveCaso() {

    int r, c;
    cin >> r >> c;
    while(!q.empty())q.pop();

    vector<vector<int>> m(r, vector<int>(c, INT_MAX));
    char ch;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> ch;
            switch (ch) {
            case'#':
                m[i][j] = -1;
                break;
            case'J':
                org = make_pair(i, j);
                break;
            case 'F':
                m[i][j] = 0;
                q.push(make_pair(i, j));
                break;
            default: break;
            }
        }
    }
    bfs(m);
    q.push(org);
    m[org.first][org.second] = 0;
    int sol = bfs2(m);
    if (sol == -1)cout << "IMPOSSIBLE\n";
    else cout << sol << '\n';

}

int main()
{
    int n;
    cin >> n;
    while (n-- > 0) resuelveCaso();

    return 0;
}