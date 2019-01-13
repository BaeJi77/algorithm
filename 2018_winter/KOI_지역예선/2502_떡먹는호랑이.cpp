#include <cstdio>
#include <cstring>

using namespace std;

int f[34],N,K,ansA,ansB;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N,&K);
    for(int i = 1 ; i < K/2 ; i++){
        f[1] = i;
        for(int j = i+1; j < K ; j++){
            f[2] = j;
            // memset(f,0,sizeof(f));
            for(int k = 3 ; k <= N ; k++){
                f[k] = f[k-1] + f[k-2];
            }
            if(f[N] == K){
                ansA = i;
                ansB = j;
                break;
            }
        }
        if(ansA != 0)
            break;
    }
    printf("%d\n%d\n" , ansA,ansB);
}