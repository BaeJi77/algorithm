#include <cstdio>

using namespace std;

int N, M;
char map[51][51];
char output[101][101];
int fy,fx;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1 ; i <= N ; i++){
        getchar();
        for(int j = 1 ; j <= M ; j++){
            scanf("%c", &map[i][j]);
            // printf("%c", map[i][j]);
        }
    }
    scanf("%d %d", &fy, &fx);
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            output[i][j] = map[i][j];
        }
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            output[i][2*M - j + 1] = map[i][j];
        }
    }

    

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M * 2 ; j++){
            output[2*N - i + 1][j] = output[i][j];
        }
    }

    for(int i = 1 ; i <= 2*N ; i++){
        for(int j = 1 ; j <= 2*M ; j++){
            if(fy == i && fx == j){
                if(output[i][j] == '.')
                    printf("#");
                else
                    printf(".");
            }else
                printf("%c", output[i][j]);
        }
        puts("");
    }
}