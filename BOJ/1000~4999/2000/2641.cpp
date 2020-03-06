#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> base;
vector<int> back_base;
vector<vector<int> > diff;
vector<int> ans;

bool checkSameThing(int direction, int whatIsCandidate,int firstIndex) {
    if(direction == 0) {
        for(int i = 0 ; i < N ; i++) {
            if(base[i] != diff[whatIsCandidate][(firstIndex + i) % N])
                return false;
        }
    } 

    if(direction == 1) {
        for(int i = 0 ; i < N ; i++) {
            if(back_base[i] != diff[whatIsCandidate][(firstIndex + i) % N])
                return false;
        }
    }

    return true;
}

int getReverseNumber (int number) {
    int ret;
    switch (number)
    {
        case 1:
            ret = 3;
            break;
        
        case 2:
            ret = 4;
            break;
        
        case 3:
            ret = 1;
            break;

        case 4:
            ret = 2;
            break;
        
        default:
            break;
    }
    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int a;
        scanf("%d", &a);
        base.push_back(a);
    }

    for(int i = N-1 ; i >= 0 ; i--) {
        back_base.push_back(getReverseNumber(base[i]));
    }

    scanf("%d", &M);
    diff.resize(M+1);
    for(int i = 0 ; i < M ; i++) {
        for(int j = 0 ; j < N ; j++) {
            int a;
            scanf("%d", &a);
            diff[i].push_back(a);
        }
    }

    for(int i = 0 ; i < M ; i++) {
        for(int j = 0 ; j < N ; j++) {
            if((base[0] == diff[i][j] && checkSameThing(0, i, j)) || (back_base[0] == diff[i][j] && checkSameThing(1, i, j))) {
                ans.push_back(i);
            }
        }
    }
    
    printf("%d\n", ans.size());
    for(int i = 0 ; i < ans.size() ; i++) {
        for (int j = 0 ; j < N ; j++) 
            printf("%d ", diff[ans[i]][j]);
        puts("");
    }
}