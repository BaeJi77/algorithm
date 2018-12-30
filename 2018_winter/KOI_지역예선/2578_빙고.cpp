//https://www.acmicpc.net/problem/2578


#include <cstdio>

using namespace std;

int map[5][5];

int bingo(){
    int line=0;
    for(int i = 0 ; i < 5 ; i++){
        int check=0;
        int check2=0;
        for(int j = 0 ; j < 5 ; j++){
            if(map[i][j]==-1)
                check++;
        }

        for(int j = 0 ; j < 5 ; j++){
            if(map[j][i]==-1)
                check2++;
        }

        if(check==5)
            line++;

        if(check2==5)
            line++;
    }

    int check=0;
    for(int i = 0 ; i < 5 ; i++){
        if(map[i][i] == -1)
            check++;
    }
    if(check==5)
        line++;
    
    check=0;
    for(int i = 0 ; i < 5 ; i++){
        if(map[i][4-i] == -1)
            check++;
    }
    if(check==5)
        line++;
    
    if(line>=3)
        return 1;
    else
        return 0;
}

int main(){
    freopen("input.txt","r",stdin);
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d" , &map[i][j]);
        }
    }

    for(int k = 0 ; k < 25 ; k++){
        int a;
        int line=0;
        scanf("%d" , &a);
        for(int i = 0 ; i < 5 ; i++){
           for(int j = 0 ; j < 5 ; j++){
                if(a==map[i][j])
                    map[i][j] = -1;
            }
        }

        if(bingo()){
            printf("%d" , k+1);
            break;
        }
    }
}