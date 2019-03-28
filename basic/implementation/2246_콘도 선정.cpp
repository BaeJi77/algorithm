#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int D[10001], C[10001];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d", &D[i], &C[i]);
    }

    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        bool flag = 0;
        for(int j = 0 ; j < N ; j++){
            if(i == j)
                continue;
            
            if(D[i] > D[j]){
                if(C[i] >= C[j]){
                    flag = 1;
                    break;
                }
            }
            if(C[i] > C[j]){
                if(D[i] >= D[j]){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0)
            cnt++;
    }
    printf("%d", cnt);
}