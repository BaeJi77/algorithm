#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1e6;

int N, M;
char in[MAX+1];
vector<int> vt;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    getchar();
    for(int i = 0 ; i < M ; i++) {
        char a = getchar();
        in[i] = a;
    }
    
    // 한번에 쭉보고 연속적으로 있는 IOI 패턴을 찾음.
    bool conti = false;
    int contiNumber = 0;
    for(int i = 0 ; i < M-2 ; i++) {
        if(in[i] == 'I') {
            if(in[i+1] == 'O' && in[i+2] == 'I') {
                conti = true;
                contiNumber++;
                i++; // for문에서 어차피 ++ 해줌 => 2칸 점프
            } else {
                conti = false;
                vt.push_back(contiNumber);
                contiNumber = 0;
            }
        }
    }
    if(conti)
        vt.push_back(contiNumber);

    int ans = 0;
    for(int i = 0 ; i < vt.size() ; i++) {
        if(N == 1) 
            ans += vt[i];
        else {
            if(N > vt[i])
                continue;
            if(N == vt[i])
                ans++;
            if(N < vt[i])
                ans += (vt[i] - N + 1);
        }
    }

    printf("%d", ans);
}