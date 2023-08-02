#include <bits/stdc++.h>
using namespace std;
short _temp, temp[10001] = { }, A[10001][1001] = { }, B[10001][1001] = { };
int n, k, m, u, v, w, cost = 0, _count = 0, pathmin = 1000000, _min = 1000000;
bool visited[10001] = { };
void networks(int x) {
	for (short i = 1; i <= temp[x]; i++) {
		short _next = A[x][i];
		int _cost = B[x][i];
		if (!visited[_next] && _min > cost + _cost + (k - _count) * pathmin) {
//			cout << "Tu dinh " << x << " di den dinh " << _next << endl;
			cost += _cost;
//			cout << " Cost= " << cost << endl;
			visited[_next] = true;
			if (_count++ < k)
				networks(_next);
			else {
				_min = cost;
//				cout << "  _min = " << _min << endl;
			}
			_count--;
			cost -= _cost;
			visited[_next] = false;
		}
	}
}
void initialize() {
	scanf("%d %d %d", &n, &k, &m);
	temp[0] = n;
	for (short i = 1; i <= n; i++)
		A[0][i] = i;
	while (m--) {
		scanf("%d %d %d", &u, &v, &w);
		pathmin = pathmin < w ? pathmin : w;
		_temp = ++temp[u];
		A[u][_temp] = v;
		B[u][_temp] = w;
		_temp = ++temp[v];
		A[v][_temp] = u;
		B[v][_temp] = w;
	}
//	cout << "pathmin=" << pathmin << endl;
//	for (int i = 1; i < n + 1; i++) {
//		for (int j = 0; j <= temp[i]; j++)
//			printf("%d ", A[i][j]);
//		cout << "\n";
//	}
//	cout << "\n";
//	for (int i = 1; i < n + 1; i++) {
//		for (int j = 0; j <= temp[i]; j++)
//			printf("%d ", B[i][j]);
//		cout << "\n";
//	}
}
int main() {
	initialize();
	networks(0);
	printf("%d", _min);
	return 0;
}