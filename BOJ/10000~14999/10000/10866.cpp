#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N;
deque<int> dq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0; i < N ; i++) {
        string q;
        cin>>q;
        if(q == "push_back") {
            int k;
            cin>>k;
            dq.push_back(k);
        } else if(q == "push_front") {
            int k;
            cin>>k;
            dq.push_front(k);
        } else if (q == "front") {
            if(dq.empty()) cout<<"-1\n";
            else cout<<dq.front()<<"\n";
        } else if (q == "back") {
            if(dq.empty()) cout<<"-1\n";
            else cout<<dq.back()<<"\n";
        } else if (q == "size") {
            cout<<dq.size()<<"\n";
        } else if (q == "empty") {
            cout<<dq.empty()<<"\n";
        } else if (q == "pop_front") {
            if(dq.empty()) cout<<"-1\n";
            else {
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        } else if (q == "pop_back") {
            if(dq.empty()) cout<<"-1\n";
            else {
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
        }
    }
}