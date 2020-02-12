#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;

int N,K,length;


struct person{
    int number;
    int reco;
    int time;
    // person(int number, int reco, int time){};
};

person arr[21];

void update(int number, int order){
    for(int i = 0 ; i < length ; i++){
        if(arr[i].number == number){
            arr[i].reco++;
            return;
        }
    }

    person p;
    p.number = number;
    p.reco = 1;
    p.time = order;

    if(N > length){
        arr[length] = p;
        length++;
        return;
    }

    int targetIdx = -1;
    int minValue = INF;
    for(int i = 0 ; i < length ; i++){
        if(arr[i].reco < minValue){
            minValue = arr[i].reco;
            targetIdx = i;
        }else if( arr[i].reco == minValue && arr[targetIdx].time > arr[i].time){ // 더 오래된 경우 값이 작으면 더 오래됨
            targetIdx = i;
        }
    }

    arr[targetIdx] = p;
}


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i = 0 ; i < K ; i++){
        int a;
        scanf("%d", &a);
        update(a, i);
    }
    
    vector<int> ans;
    for(int i = 0 ; i < N ; i++){
        ans.push_back(arr[i].number);
    }

    sort(ans.begin() , ans.end());
    for(int i = 0 ; i < length; i++)
        printf("%d ", ans[i]);
}