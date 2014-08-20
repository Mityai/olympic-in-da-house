#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

using namespace std;
         
#define mp make_pair
#define fi first
#define se second

typedef long long ll;

const double eps = 1e-7;
const int INF = 123456789;
const int MAXN = 100000;

bool cmp(int n, pair<int, int> p) {
 	return n < p.fi;
}

bool cmp_pos(pair<int, int> p1, pair<int, int> p2) {
 	return p1.se < p2.se;
}

int main() {
	#if __APPLE__
		freopen("input.txt", "r", stdin);
	#else
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif

	int x = 1, y = 7;
	x += y *= 3;
	cout << x << endl;
}
