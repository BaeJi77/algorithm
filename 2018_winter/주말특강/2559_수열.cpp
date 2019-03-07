#include <cstdio>
#include <algorithm>

using namespace std;

int N,K,arr[100004];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" ,&N,&K);
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &arr[i]);
    }
    
    int psum = 0;
    for(int i = 0 ; i < K ; i++){
        psum += arr[i];
    }

    int ans = psum;
    for(int i = K ; i < N ; i++){
        psum = psum+arr[i]-arr[i-K];
        ans = max(ans, psum);
    }
    printf("%d\n", ans);
}