#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;
int N,S[24][24];

//1. 두개 팀으로 나눠서 선택 
//2. 두 팀이 정상적으로 둘로 나눴졌는지 확인
//3. 두 팀의 점수 차이를 계산
//4. 더 작은 것을 계속 비교하면 리턴함.

int cal(int team[]){
    int cnt[] = {0, 0};
    for(int i = 0 ; i < N ; i++){
        cnt[team[i]]++;
    }

    if(cnt[0] != cnt[1])
        return INF;

    int score[] = {0,0};
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i != j && team[i] == team[j]){
                score[team[i]] += S[i][j];
            }
        }
    }

    return abs(score[0] - score[1]);
}

int teamChoice(int cur, int team[]) {
    if(cur == N)
        return cal(team);

    int ret = INF;
    team[cur] = 0;
    ret = min(ret, teamChoice(cur+1, team));
    team[cur] = -1;

    team[cur] = 1;
    ret = min(ret, teamChoice(cur+1, team));
    team[cur] = -1;

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d", &S[i][j]);
        }
    }

    int team[21];
    int ans = teamChoice(0, team);
    printf("%d\n", ans);
}