#include<bits/stdc++.h>
using namespace std;
string p[10005];
bool cmp(const string& a, const string& b) {
        for (int i = 0; i < (int)a.size() && i < (int)b.size(); i++) {
                if (a[i] == b[i]) continue;
                else if (a[i] < b[i]) return true;
                else return false;
        }
        return true;
}
bool is_ok(int n) {
        int k, j;
        for (int i = 0; i < n - 1; i++) {
                for (k = 0, j = i + 1; k < p[i].size() && k < p[j].size(); k++) if (p[i][k] != p[j][k]) break;
                if ((k >= p[i].size()) || (k >= p[j].size())) return false;
        }
        return true;
}
int main() {
        ios::sync_with_stdio(false);
        int n, case_num;
        cin >> case_num;
        while (case_num--) {
                cin >> n;
                for (int i = 0; i < n; i++) {
                    p[i].clear();
                    cin >> p[i];
                }
                sort(p, p + n);
                if (is_ok(n)) cout << "YES" << endl;
                else cout << "NO" << endl;
        }
}