#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 1e5;

int N, M;
int na[MAX+1], ma[MAX+1];

int sol(int num) {
    int left = 0;
    int right = N;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(na[mid] == num)
            return 1;
        else if (na[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main () {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) 
        scanf("%d", &na[i]);
    sort(na, na+N);
    
    scanf("%d", &M);
    for(int i = 0 ; i < M ; i++) {
        int a;
        scanf("%d", &a);
        printf("%d\n", sol(a));
    }
}