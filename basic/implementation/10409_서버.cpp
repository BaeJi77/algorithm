#include <cstdio>
#include <cstdlib>

using namespace std;

int N, arr[54],T;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &T);
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &arr[i]);
    }

    for(int i = 0 ; i < N ; i++){
        if(T - arr[i] >= 0){
            cnt++;
            T -= arr[i];
        }else{
            break;
        }
    }

    printf("%d", cnt);
}