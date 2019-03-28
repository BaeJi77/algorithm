#include <cstdio>
#include <algorithm>

using namespace std;

int N,M,game[1001],vote[1001],ans[1001];

bool comp(const int &a, const int &b){
    return a > b;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N,&M);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &game[i]);
    }

    for(int i = 0 ; i < M ; i++){
        scanf("%d", &vote[i]);
    }

    // sort(game, game+N, comp);
    for(int i = 0 ; i < M ; i++){
        int value = vote[i];
        for(int j = 0 ; j < N ; j++){
            if(value < game[j])
                continue;
            // printf("%d %d %d\n" , value, j, game[j]);
            ans[j]++;
            break;
        }
    }
    
    int maxx = -1;
    int maxIdx = -1;
    for(int i = 0 ; i < N ; i++){
        if(maxx < ans[i]){
            maxx = max(maxx, ans[i]);
            maxIdx = i;
        }
    }
        
    printf("%d", maxIdx+1);
}