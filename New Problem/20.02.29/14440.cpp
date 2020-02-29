#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<vector<ll> >  matrix;

const long mod = 100;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

matrix power(const matrix &A, int n){
	if(n == 1) return A;
	matrix T = power(A, n/2);
	T = T * T;
	if(n%2) T = T * A;
	return T;
}

ll x,y,a0,a1,n;

int main() {
    scanf("%d %d %d %d %d", &x, &y, &a0, &a1, &n);
    
    if(n == 0) {
        printf("%02d", a0);
        return 0;
    }
    if(n == 1) {
        printf("%02d", a1);
        return 0;
    }
    
    matrix product = {{x, y}, {1, 0}};
    matrix M = power(product, n - 1);
    
    printf("%02d", (M[0][0] * a1 + M[0][1] * a0) % 100);
}
