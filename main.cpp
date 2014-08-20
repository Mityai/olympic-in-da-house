#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <climits>
#include <sstream>

typedef long long ll;

using namespace std;

const int MAXN = 200001;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
    
	return b ? gcd(b, a % b) : a;
}

struct TNode {
    int x, y;
    int left, right;
    
    int key_gcd;
};

int root = -1;
TNode tree[MAXN];
int amount[MAXN];

int getG(int node) {
	if (node == -1) {
		return 0;
	}
    
	return tree[node].key_gcd;
}

void relax(int node) {
	if (node == -1) {
		return;
	}
    
	int left = tree[node].left;
	int right = tree[node].right;
    
	tree[node].key_gcd = gcd(tree[node].x, gcd(getG(left), getG(right)));
}

void split(int node, int c, int &left, int &right) {
    if (node == -1) {
        left = right = -1;
        return;
    }
    
    if (tree[node].x <= c) {
        split(tree[node].right, c, left, right);
        tree[node].right = left;
        relax(tree[node].right);
        left = node;
    } else {
        split(tree[node].left, c, left, right);
        tree[node].left = right;
        relax(tree[node].left);
        right = node;
    }
}

int _merge(int left, int right) {
    if (left == -1) {
        return right;
    }
    
    if (right == -1) {
        return left;
    }
    
    if (tree[left].y < tree[right].y) {
        tree[left].right = _merge(tree[left].right, right);
        relax(tree[left].right);
        return left;
    } else {
        tree[right].left = _merge(left, tree[right].left);
        relax(tree[right].left);
        return right;
    }
}

int tc = 0;

int newNode(int x) {
    tree[tc].x = x;
    tree[tc].key_gcd = x;
    tree[tc].y = rand();
    tree[tc].left = -1;
    tree[tc].right = -1;
    
    return tc++;
}

void _insert(int node) {
    int left = -1, right = -1;
    split(root, tree[node].x, left, right);
    
    left = _merge(left, node);
    relax(left);
    root = _merge(left, right);
    relax(right);
}

void remove(int x) {
    int left = -1, right = -1;
    int A = -1, B = -1;
    split(root, x, left, right);
    
    B = right;
    
    split(left, x - 1, A, right);
    
    root = _merge(A, B);
    relax(root);
}

int getGCD(int L, int R) {
	int left = -1, right = -1;
	int A = -1, B = -1, C = -1;
	split(root, L - 1, left, right);
	A = left;
    
	split(right, R, B, C);
    
	int res = tree[B].key_gcd;
    
	root = _merge(A, B);
	relax(root);
	root = _merge(root, C);
	relax(root);
    
	return res;
}

bool _find(int node, int x) {
    if (node == -1) {
        return false;
    }
    
    if (tree[node].x < x) {
        if (tree[node].right == -1) {
            return false;
        }
        
        return _find(tree[node].right, x);
    } else if (tree[node].x > x) {
        if (tree[node].left == -1) {
            return false;
        }
        
        return _find(tree[node].left, x);
    }
    
    return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
}
