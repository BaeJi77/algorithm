#include <cstdio>
#include <algorithm>


using namespace std;

const int INF = 987654321;
int N,arr[20004];

int main(){
    freopen("input.txt", "r" ,stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N; i++){
        scanf("%d" , &arr[i]);
    }

    sort(arr,arr+N);
    int minn = INF;
    int ans = -1;
    for(int i = 0 ; i  < N ; i++){
        int sum = 0;
        for(int j = 0 ; j < N ; j++){
            sum += abs(arr[i]-arr[j]);
        }
        if(minn > sum){
            minn = sum;
            ans = arr[i];
        }
    }
    printf("%d\n" , ans);
}