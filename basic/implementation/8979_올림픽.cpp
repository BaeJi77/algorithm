#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;

struct contury{
    int number;
    int gold;
    int silver;
    int bronze;
    int rank;  
};

contury arr[101];

bool comp(contury const &a, contury const &b){
    if(a.gold > b.gold)
        return a.gold > b.gold;
    else if(a.gold == b.gold && a.silver > b.silver)
        return a.silver > b.silver;
    else if(a.gold == b.gold && a.silver == b.silver && a.bronze > b.bronze)
        return a.bronze > b.bronze;
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; i++){
        int n, g, s, b;
        scanf("%d %d %d %d", &arr[i].number, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
    }

    sort(arr, arr+N, comp);
    int rank = 1;
    int gold = arr[0].gold;
    int silver = arr[0].silver;
    int bronze = arr[0].bronze;
    arr[0].rank = rank;

    for(int i = 0 ; i < N ; i++){
        if (arr[i].gold == gold && arr[i].silver == silver && arr[i].bronze == bronze) {

        } else {
            gold = arr[i].gold;
            silver = arr[i].silver;
            bronze = arr[i].bronze;
        }
        
        while(arr[i].gold == gold && arr[i].silver == silver && arr[i].bronze == bronze){
            arr[i].rank = rank;
            i++;
        }
        rank = i + 1;
        i--;
    }

    for(int i = 0 ; i < N ; i++){
        if(arr[i].number == K)
            printf("%d\n", arr[i].rank);
    }
}