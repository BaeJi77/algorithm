#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, M;
char map[30][30];
set <string> st;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    for(int i = 0 ; i < N ; i++) {
        string str = "";
        for(int j = 0 ; j < M ; j++) {
            if(map[i][j] == '#') {
                if(str.size() >= 2) {
                    st.insert(str);
                }
                str = "";
            } else 
                str.push_back(map[i][j]);
        }
        if(str != "" && str.size() >= 2) 
            st.insert(str);
    }

    for(int i = 0 ; i < M ; i++) {
        string str = "";
        for(int j = 0 ; j < N ; j++) {
            if(map[j][i] == '#') {
                if(str.size() >= 2) {
                    st.insert(str);
                }
                str = "";
            } else 
                str.push_back(map[j][i]);
        }
        if(str != "" && str.size() >= 2) 
            st.insert(str);
    }

    cout<<*st.begin()<<endl;
}