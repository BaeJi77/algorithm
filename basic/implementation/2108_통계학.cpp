#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;

int N;
int arr[500004];
pair<int, int> cnt[8004];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    double sum = 0;
    int maxx = -INF;
    int minn = INF;
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] < 0){
            cnt[arr[i]*(-1)+4000].first++;
            cnt[arr[i]*(-1)+4000].second = arr[i];
        }else{
            cnt[arr[i]].first++;
            cnt[arr[i]].second = arr[i];
        }
            
        maxx = max(maxx, arr[i]);
        minn = min(minn, arr[i]);
    }

    sort(cnt, cnt+N);
    vector<int> maxIndex;
    int cntMaxValue = -1;
    for(int i = 0 ; i <= 8000 ; i++){
        cntMaxValue = max(cntMaxValue ,cnt[i].first);
    }

    int maxCnt = 0;
    for(int i = 0 ; i <= 8000 ; i++){
        if(cntMaxValue == cnt[i].first){
            maxCnt++;
            maxIndex.push_back(cnt[i].second);
        }
    }

    sort(maxIndex.begin(), maxIndex.end());
    sort(arr, arr+N);
    
    int average = 0;
    if(sum < 0)
        average = sum / N - 0.5;
    else if(sum > 0)    
        average = sum / N + 0.5;
        
    printf("%d\n%d\n%d\n%d\n"
        , average
        , arr[N/2]
        , maxCnt == 1 ? maxIndex[0] : maxIndex[1] 
        , maxx - minn
    );
}