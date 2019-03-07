#include <cstdio>

using namespace std;

int N,X;
int map[24][24];

//낮은 곳에서 높은 곳으로
//높은 곳에서 낮은 곳으로

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d" , &t);
    for(int tc = 1 ; tc < t ; tc++){
        scanf("%d %d" , &N, &X);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                scanf("%d" , &map[i][j]);
            }
        }
        

        printf("#%d %d" , tc , 1);
    }
}