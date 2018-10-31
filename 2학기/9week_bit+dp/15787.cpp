// https://www.acmicpc.net/problem/15787
// 기차가 은하수를 건너면

#include <stdio.h>
#include <set>

#define MAX 100000

using namespace std;

set<int> st;
int trail[MAX+4], N,M;


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &N,&M);
    for(int i = 0 ; i < M ; i++){
        int q;
        scanf("%d" , &q);
        if(q == 1 || q == 2){
            int a,b;
            scanf("%d %d" , &a,&b);
            if(q == 1)
                trail[a] |= (b<<1);
            else 
                trail[a] &= ~(b<<1);
        }else{
            int a;
            scanf("%d" ,&a);
            if(q == 3){
                int last = (1<<20);
                trail[a] &= ~(last);
                trail[a] = trail[a]<<1;
            }else if(q == 4){
                int first = 2;
                trail[a] &= ~(first);
                trail[a] = trail[a]>>1;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        st.insert(trail[i]);
    }

    printf("%d" , st.size());
}