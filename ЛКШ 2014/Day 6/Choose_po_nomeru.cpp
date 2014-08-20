#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define pb push_back
#define pop pop_back

typedef long long ll;

using namespace std;

int main() {
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    vector<vector<int> > d(n + 1, vector<int> (n + 1));
    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][i] = 1;
        for (int j = 1; j < i; j++) {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    ++m;
    int toadd = 1;

    vector<int> a;
    int i = n, j = k;
    while (int(a.size()) < k) {
        if (d[i - 1][j - 1] >= m) {
            a.pb(toadd);
            --i;
            --j;
        } else {
            m -= d[i - 1][j - 1];
            --i;
        }
        toadd++;
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }
}