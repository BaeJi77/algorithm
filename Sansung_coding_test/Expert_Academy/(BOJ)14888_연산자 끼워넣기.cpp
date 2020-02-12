#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int N,maxx,minn;
int arr[104];
bool visited[104];
vector<int> oper;
vector<int> temp;

int operateArray(){
    int ans = arr[0];
    for(int i = 0 ; i <= N-1 ; i++){
        if(temp[i] == 0) ans += arr[i+1];
        else if(temp[i] == 1) ans -= arr[i+1];
        else if(temp[i] == 2) ans *= arr[i+1];
        else if(temp[i] == 3) ans /= arr[i+1];
    }

    return ans;
}

void solve(int k) {
    if(k == N-1){
        //연산자 결과 더하기
        int result = operateArray();
        maxx = max(maxx, result);
        minn = min(minn, result);
        return;
    }
    
    for(int i = 0 ; i < N-1 ; i++){
        if(visited[i])
            continue;
        visited[i] = true;
        temp.push_back(oper[i]);
        solve(k+1);
        temp.pop_back();
        visited[i] = false;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &arr[i]);
    }
    maxx = -INF;
    minn = INF;
    for(int i = 0 ; i < 4 ; i++){
        int a;
        scanf("%d", &a);
        while(a--)
            oper.push_back(i);
    }
    solve(0);
    printf("%d\n", maxx);
    printf("%d\n", minn);
}