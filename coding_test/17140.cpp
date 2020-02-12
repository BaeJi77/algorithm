#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int R, C, K;
int rmax, cmax;
int arr[201][201];

priority_queue <pair<int, int> > goodPQ;
bool flag;
int ans = -1;
map<int, int>::iterator it;

priority_queue<pair<int , int> > arraySort (map<int, int> mp) {
    priority_queue<pair<int, int> > pq;
    for(it = mp.begin() ; it != mp.end(); it++) {
        pq.push(make_pair(-it->second, -it->first));
    }
    return pq;
}

int row() {
    int leng = -1;
    for(int i = 0 ; i < rmax ; i++) {
        map<int, int> mp;
        for(int j = 0 ; j < cmax ; j++ ) {
            if(arr[i][j] != 0)
                mp[arr[i][j]]++;
        }

        goodPQ = arraySort(mp);

        int k = 0;
        int pqSize = goodPQ.size();
        for(int j = 0 ; j < pqSize; j++) {
            pair<int, int> now = goodPQ.top();
            goodPQ.pop();
            arr[i][k] = -now.second;
            arr[i][k+1] = -now.first;
            // cout<<arr[i][k]<<" "<<arr[i][k+1]<<" ";
            k += 2;
            if(k > 100) 
                break;
        }
        // cout<<endl;
        for(int j = k ; j < 200 ; j++)
            arr[i][j] = 0;
        leng = max(leng, k);
    }
    return leng;
}

int column() {
    int leng = -1;
    for(int i = 0 ; i < cmax ; i++) {
        map<int, int> mp;
        for(int j = 0 ; j < rmax ; j++ ) {
            mp[arr[j][i]]++;
        }

        goodPQ = arraySort(mp);

        int k = 0;
        int pqSize = goodPQ.size();
        for(int j = 0 ; j < pqSize; j++) {
            pair<int, int> now = goodPQ.top();
            goodPQ.pop();
            arr[k][i] = -now.second;
            arr[k+1][i] = -now.first;
            k += 2;
            if(k > 100) 
                break;
        }
        for(int j = k ; j < 201 ; j++)
            arr[j][i] = 0;

        leng = max(leng, k);
    }
    return leng;
}

void print() {
    for(int i = 0 ; i < rmax; i++) {
        for(int j = 0 ; j < cmax; j++ ){
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0 ; i < 3; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            scanf("%d", &arr[i][j]);
        } 
    }
    rmax = 3;
    cmax = 3;


    for(int i = 0 ; i < 100; i++) {
        // cout<<i<<"번째 연산"<<endl;;
        // print();
        if(arr[R-1][C-1] == K) {
            ans = i;
            break;
        }
        
        if(rmax >= cmax) {
            // R연산
            cmax = row();
        } else {
            // C연산
            rmax = column();
        }
        // cout<<rmax<<" "<<cmax<<endl;
        // cout<<"연산이후"<<endl;
        // print();
    }
    
    printf("%d", ans);
}