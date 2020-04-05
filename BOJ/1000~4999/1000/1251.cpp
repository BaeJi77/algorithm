#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
string in;
set<string> st;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>in;
    N = in.size();

    for(int i = 1 ; i < N - 1 ; i++) {
        for(int j = i + 1 ; j < N  ; j++) {
            string temp = in.substr(0, i);
            string temp2 = in.substr(i, j - i);
            string temp3 = in.substr(j, N);
            // cout<<i<<" "<<j<<" "<<N<<endl;
            // cout<<temp<<" "<<temp2<<" "<<temp3<<"\n";
            // reverse()
            reverse(temp.begin(), temp.end());
            reverse(temp2.begin(), temp2.end());
            reverse(temp3.begin(), temp3.end());
            
            // cout<<temp<<" "<<temp2<<" "<<temp3<<"\n";
            string mergeString = temp + temp2 + temp3;
            st.insert(mergeString);
        }
    }

    cout<<*st.begin()<<"\n";
}