#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K, ans;
vector<string> arr;

void sol(vector<int> nowVector, int idx, int k) {
    if(idx > 26 && k != 0)
        return;

    if(k == 0) {
        // 여기서 최대값 비교
        int cnt = 0;
        for(int i = 0 ; i < arr.size() ; i++) {
            bool isPoss = true;
            for(int j = 0 ; j < arr[i].size(); j++) {
                bool isReadable = false;
                for(int k = 0 ; k < nowVector.size() ; k++) {
                    if(arr[i][j] == (char)(nowVector[k] + 'a')) {
                        isReadable = true;
                        break;
                    }
                }

                if(!isReadable) {
                    isPoss = false;
                    break;
                }
            }

            if(isPoss) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    if(idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19)
        sol(nowVector, idx+1, k);
    else {
        sol(nowVector, idx+1, k);

        nowVector.push_back(idx);
        sol(nowVector, idx+1, k-1);
        nowVector.pop_back();
    }
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>K;
    if(K < 5) {
        cout<<"0";
        return 0;
    } else if(K == 26) {
        cout<<N;
        return 0;
    }
    // cout<<(char)('a' + 25);
    // anta tica
    vector<int> vt;
    vt.push_back('a' - 'a');
    vt.push_back('n' - 'a');
    vt.push_back('t' - 'a');
    vt.push_back('i' - 'a');
    vt.push_back('c' - 'a');

    // for(int i = 0 ; i <vt.size() ; i++)
    //     cout<<vt[i]<<" ";
    // puts("");

    for(int i = 0 ; i < N ; i++) {
        string temp;
        cin>>temp;
        arr.push_back(temp);
    }

    sol(vt, 1, K - 5);
    cout<<ans;
}