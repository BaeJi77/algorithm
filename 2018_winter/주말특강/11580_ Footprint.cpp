#include <cstdio>

using namespace std;

int N,x,y;
int map[2004][2004];

// E는 동쪽, W는 서쪽, S는 남쪽, N은 북쪽

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    x=1000,y=1000;
    map[y][x] = 1;
    char c = getchar();
    for(int i = 0 ; i < N ; i++){
        char c = getchar();
        // printf("%c\n" , c);
        if(c == 'E'){
            x++;
            map[y][x] = 1;
        }else if(c == 'W'){
            x--;
            map[y][x] = 1;
        }else if(c == 'S'){
            y++;
            map[y][x] = 1;
        }else if(c == 'N'){
            y--;
            map[y][x] = 1;
        }
    }

    int cnt = 0;
    for(int i = 0 ; i <= 2000 ; i++){
        for(int j = 0 ; j <= 2000 ; j++){
            if(map[i][j] == 1)
                cnt++;
        }
    }
    printf("%d" , cnt);

    // for(int i = 980 ; i <= 1020 ; i++){
    //     for(int j = 980 ; j <= 1020 ; j++){
    //         printf("%d " , map[i][j]);
    //     }
    //     puts("");
    // }
}