#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student{
    string name;
    int korean;
    int english;
    int math;
};

struct cmp {
    bool operator() (student a, student b) {
        if(a.korean != b.korean)
            return a.korean > b.korean;
        else {
            if(a.english != b.english)
                return a.english < b.english;
            else {
                if(a.math != b.math)
                    return a.math > b.math;
                else 
                    return a.name < b.name;
            }
        }
    }
};

int N;
priority_queue <student, vector<student>, cmp > pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i = 0 ; i < N ; i++) {
        string name;
        int a,b,c;
        cin>>name>>a>>b>>c;
        student s = {name, a, b, c};
        pq.push(s);
    }

    vector<string> kk;
    for(int i = 0 ; i < N ; i++) {
        kk.push_back(pq.top().name);
        pq.pop();
    }

    for(int i = kk.size() - 1; i >= 0 ; i--)
        cout<<kk[i]<<"\n";
}