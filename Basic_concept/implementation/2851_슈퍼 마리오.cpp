#include <cstdio>
#include <cstdlib>

using namespace std;

int arr[11];

int main(){
    freopen("input.txt","r",stdin);
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d", &arr[i]);
    }

    int score = 0;
    for(int i = 0 ; i < 10 ; i++){
        int newScore = score + arr[i];
        int diff = abs(100 - score);
        int newDiff = abs(100 - newScore);
        if(diff >= newDiff){
            score = newScore;
        }else{
            break;
        }
    }

    printf("%d", score);
}