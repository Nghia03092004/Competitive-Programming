#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n;
int a[maxN], dist[maxN], ans[maxN];
vector<int> g[maxN];
queue<int> q;

void bfs(int x) {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v: g[u])
			if (dist[v] == -1) {
				q.push(v);
				dist[v] = dist[u] + 1;
			}
	}
	for (int i = 1; i <= n; i++)
		if (a[i] % 2 == x) ans[i] = dist[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i - a[i] >= 1) g[i - a[i]].push_back(i);
        if (i + a[i] <= n) g[i + a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2) {
            q.push(i);
            dist[i] = 0;
        } else dist[i] = -1;
    }
    bfs(0);

    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 0) {
            q.push(i);
            dist[i] = 0;
        } else dist[i] = -1;
    }
    bfs(1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}