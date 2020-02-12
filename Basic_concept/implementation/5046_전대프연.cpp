#include <cstdio>
#include <algorithm>


const int INF = 987654321;
int N,B,H,W;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d %d %d", &N,&B,&H,&W);
    int minn = INF;
    for(int i = 0 ; i < H ; i++){
        int cost = 0;
        int totalPrice = INF;
        scanf("%d", &cost);
        
        for(int j = 0 ; j < W ; j++){
            int temp;
            scanf("%d", &temp);
            if(temp >= N)
                totalPrice = N * cost;
        }
        // printf("%d %d\n", cost, totalPrice);
        if(totalPrice <= B){
            minn = std::min(minn, totalPrice);
        }
    }
    if(minn == INF){
        printf("stay home");
    }else{
        printf("%d", minn);
    }
}