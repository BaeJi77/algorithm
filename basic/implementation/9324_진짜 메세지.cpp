#include <cstdio>
#include <iostream>

using namespace std;

int N;


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        string str;
        cin>>str;
        bool isOk = true;
        int check[26] = {0,};
        int conti[26] = {0,};
        // 3개 있는데 하나 더 없는 경우
        //무조건 3번째 등장할때 하나가 더 나와야되는군
        for(int j = 0 ; j < str.size() ; j++){
            char now = str[j];
            // printf("%c", now);
            check[now - 'A']++;
            if(check[now - 'A'] % 3 == 0 && str[j+1] == now){
                j++;
            }else if(check[now - 'A'] % 3 == 0){
                isOk = false;
                break;
            }
        }
        if(isOk)
            printf("OK\n");
        else
            printf("FAKE\n");
    }
}