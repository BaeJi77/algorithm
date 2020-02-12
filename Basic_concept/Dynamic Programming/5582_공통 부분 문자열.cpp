#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 4000;

string A;
string B;
int cache[MAX+4][MAX+4][2];

int func(int aidx, int bidx, int conti) {
    if(aidx == A.size() || bidx == B.size())
        return 0;
    
    int& ret = cache[aidx][bidx][conti];
    if(ret != -1)
        return ret;
    
    if(conti == 0){
        ret = max(func(aidx+1, bidx, 0), func(aidx, bidx+1, 0));
        if(A[aidx] == B[bidx])
            ret = max(ret, func(aidx+1, bidx+1, 1) + 1);
    }else {
        if(A[aidx] != B[bidx])
            ret = 0;
        else
            ret = func(aidx+1, bidx+1, 1) + 1;
    }

    return ret;
}


int main() {
    freopen("input.txt","r",stdin);
    cin>>A>>B;
    memset(cache,-1,sizeof(cache));
    cout<<func(0,0,0);
}