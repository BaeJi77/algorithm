//https://www.acmicpc.net/problem/2607

/*
- 같은 단어                  -> 알파벳 개수 차이 없음
- 알파벳 하나 추가 또는 제거     -> 알파벳 개수 1개 차이나는 경우 1개
- 알파벳 하나 변경             -> 알파벳 개수 1개 차이나는 경우 2개 & 전체 길이 동일
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N,ans;
int letter[26];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    string a;
    getchar();
    getline(cin,a);
    for(int i = 0 ; i < a.length() ; i++){
        letter[a[i]-'A']++;
    }

    for(int i = 0 ; i < N-1 ; i++){
        string k;
        getline(cin,k);
        int temp[26] = {0,};
        int cnt = 0;

        for(int j = 0 ; j < k.length() ; j++){
            temp[k[j]-'A']++;
        }

        for(int j = 0 ; j < 26 ; j++){
            int difnum = abs(letter[j] - temp[j]);

            if(difnum == 1) {
                cnt++;
            } else if(difnum > 1) 
                cnt=100;
        }  
        if(cnt < 2 || (cnt == 2 && a.length()==k.length()))
            ans++;
    }
    printf("%d\n" ,ans);
}