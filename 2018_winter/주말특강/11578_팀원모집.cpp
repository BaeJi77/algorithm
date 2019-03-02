#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 123456789

int N,M,num[14];

// int func(int index, int check, int part){
//     if(index == N){
//         return check == 1<<(N-1) ? part : MAX;
//     }

//     int ret = min(func(index+1, check, part) , func(index+1, check|num[index] , part+1));

//     return ret;
// }

//함수의 정의를 앞으로 내가 선택할 애들
int func(int idx, int state){
    if(idx == N){
        return state != 0 ? MAX : 0;
    }

    //state & ~num[idx]
    //state - num[idx] -> state에서 num[idx]의 차집합을 구한다.
    int x = func(idx +1 , state);
    int y = func(idx +1 , state & (~num[idx])) + 1;

    return min(x,y);
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &N,&M);
    for(int i = 0 ; i < M ; i++){
        int a;
        scanf("%d" , &a);
        for(int j = 0 ; j < a ; j++){
            int q;
            scanf("%d" , &q);
            num[i] |= 1<<(q-1);
        }
    }    

    int result = func(0,(1<<(N-1)));
    printf("%d" , result == MAX ? -1 : result);
}