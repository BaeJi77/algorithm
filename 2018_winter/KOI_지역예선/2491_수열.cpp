#include <cstdio>
#include <algorithm>

using namespace std;

int N,a[100004];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &a[i]);
        // printf("%d\n" , a[i]);
    }   
    int kMAX = 0;
    int tempCnt=0;
    for(int i = 0 ; i < N-1 ; i++){
        if(a[i] <= a[i+1]){
            tempCnt++;
        }
        else{
            tempCnt=0;
        }
        kMAX = max(kMAX,tempCnt);    
    }

    int bMax = 0;
    tempCnt=0;
    for(int i = N-1 ; i >= 1 ; i--){
        if(a[i] <= a[i-1]){
            tempCnt++;
        }
        else{
            tempCnt=0;
        }
        bMax = max(bMax,tempCnt);    
    }

    int mmax = max(kMAX, bMax);
    printf("%d" , mmax+1);
}