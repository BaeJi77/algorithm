#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> vt;

int findMaxOne(int arr[], int cur, int choice, int sum){
    if(choice == 3){
        return sum%10;
    }else if(cur == 5){
        return -100;
    }

    int ret = max(findMaxOne(arr, cur+1, choice, sum), findMaxOne(arr, cur+1, choice+1, sum+arr[cur]));
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N; i++){
        int arr[5];
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d" , &arr[j]);
        }
        vt.push_back(findMaxOne(arr, 0, 0, 0));
    }

    int maxx = -1;
    int idx = -1;
    for(int i = 0 ; i < N ; i++){
        if(maxx <= vt[i]){
            maxx = vt[i];
            idx = i;
        }
    }
    printf("%d\n" , idx+1);
}