#include <bits/stdc++.h>
using namespace std;
int **A, *mins, n, r, i_th, dist;
bool *cols;
vector<vector<int> > routes;
stack<int> temp_route;
void planning(unsigned x) {
	if (!x) {
		if (routes[i_th].size() == 2) {
			mins[i_th] =
					A[routes[i_th][0]][routes[i_th][1]] == 0 ?
							mins[i_th] : A[routes[i_th][0]][routes[i_th][1]];
		} else {
			dist = 0;
			temp_route.push(routes[i_th][0]);
//			printf("\nvua push vao: %d", routes[i_th][0]);
			planning(routes[i_th][0]);
			temp_route.pop();
		}
	} else
		for (unsigned i = 1; i < routes[i_th].size() - 1; i++) {
			unsigned next = routes[i_th][i];
			if (x != next && A[x][next] != 0 && cols[next]
					&& mins[i_th] > dist + A[x][next]) {
				cols[next] = false;
				dist += A[x][next];
//				printf("\nvua push vao: %d", next);
//				printf("\ndist=%d", dist);
				temp_route.push(next);
				if (temp_route.size() < routes[i_th].size() - 1) {
					planning(next);
					cols[next] = true;
					dist -= A[x][next];
					temp_route.pop();
				} else {
					if (A[next][routes[i_th].back()] != 0) {
						mins[i_th] =
								mins[i_th]
										< dist + A[next][routes[i_th].back()] ?
										mins[i_th] :
										dist + A[next][routes[i_th].back()];
					}
					cols[next] = true;
					dist -= A[x][next];
					temp_route.pop();
				}
			}
		}
}
void initialize() {
	int temp;
	string s;
	cin >> n >> r;
	cols = new bool[n + 1];
	for (int i = 1; i < n + 1; i++)
		cols[i] = true;
	mins = new int[r + 1];
	for (int i = 1; i < r + 1; i++)
		mins[i] = 1000;
	A = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		A[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			if (!i)
				A[i][j] = 1;
			else if (!j)
				A[i][j] = 0;
			else
				scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < r + 1; i++)
		routes.push_back(vector<int>());
	getline(cin, s);
	for (int i = 1; i < r + 1; i++) {
		getline(cin, s);
//		printf("\n%s", s.c_str());
		istringstream is(s);
		while (is >> temp)
			routes[i].push_back(temp);
	}
}
signed main() {
	initialize();
	for (i_th = 1; i_th < r + 1; i_th++)
		planning(0);
	for (i_th = 1; i_th < r + 1; i_th++)
		if (mins[i_th] != 1000)
			printf("%d\n", mins[i_th]);
		else
			printf("0\n");
}

