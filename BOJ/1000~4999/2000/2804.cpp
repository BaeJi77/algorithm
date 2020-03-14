#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>a>>b;
    int aIdx, bIdx;
    bool found = false;
    for(int i = 0 ; i < a.size() ; i++) {
        for(int j = 0 ; j < b.size() ; j++) {
            if(a[i] == b[j]) {
                aIdx = i;
                bIdx = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    for(int i = 0 ; i < b.size() ; i++) {
        if(i == bIdx) {
            for(int j = 0 ; j < a.size(); j++) {
                cout<<a[j];
            }
        } else {
            for(int j = 0 ; j < a.size(); j++) {
                if(j == aIdx) cout<<b[i];
                else cout<<'.';
            }
        }
        cout<<"\n";
    }
}