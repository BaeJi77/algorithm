<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> add185c... 18.07.06
//#include <cstdio>
//#include <vector>
//#include <queue>
//using namespace std;
//
//priority_queue <int> pq;
//
//int cnt = 1;
//int n, m;
//vector <vector <int> > vt;
//int a, b ,seR, hanR,ADD;
//bool se[100010];
//bool han[100010];
//bool visited[100010];
//int aaa;
//
//void sedfs(int here) {
//    se[here] = true;
//    cnt++;
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if (se[there] == false) sedfs(there);
//    }
//}
//
//void handfs(int here) {
//    han[here] = true;
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if (han[there] == false) handfs(there);
//    }
//}
//
//void dfs(int here) {
//    visited[here] = true;
//    aaa++;
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if (visited[there] == false) dfs(there);
//    }
//}
//
//int main() {
//    scanf("%d %d", &n, &m);
//    vt.resize(n + 1);
//    while (m--)
//    {
//        scanf("%d %d", &a, &b);
//        vt[a].push_back(b);
//        vt[b].push_back(a);
//    }
//    
//    scanf("%d %d %d", &seR, &hanR, &ADD);
//    for (int i = 0; i < vt[seR].size(); i++)
//    {
//        se[seR] = true;
//        int here = vt[seR][i];
//        
//        if (se[here] == false) sedfs(here);
//    }
//    
//    for (int i = 0; i < vt[hanR].size(); i++)
//    {
//        int here = vt[hanR][i];
//        if (han[here] == false) handfs(here);
//    }
//    
//    for (int i = 0; i < vt.size(); i++) {
//        for (int j = 0; j < vt[i].size(); j++)
//        {
//            int here = vt[i][j];
//            if (se[here] == false && han[here] == false) dfs(here);
//            pq.push(aaa);
//            aaa = 0;
//        }
//    }
//    
//    while (ADD--)
//    {
//        cnt += pq.top();
//        pq.pop();
//    }
//    
//    printf("%d", cnt);
//    
//}
<<<<<<< HEAD

=======
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

priority_queue <int> pq;

int cnt = 1;
int n, m;
vector <vector <int> > vt;
int a, b ,seR, hanR,ADD;
bool se[100010];
bool han[100010];
bool visited[100010];
int aaa;

void sedfs(int here) {
    se[here] = true;
    cnt++;
    for (int i = 0; i < vt[here].size(); i++) {
        int there = vt[here][i];
        if (se[there] == false) sedfs(there);
    }
}

void handfs(int here) {
    han[here] = true;
    for (int i = 0; i < vt[here].size(); i++) {
        int there = vt[here][i];
        if (han[there] == false) handfs(there);
    }
}

void dfs(int here) {
    visited[here] = true;
    aaa++;
    for (int i = 0; i < vt[here].size(); i++) {
        int there = vt[here][i];
        if (visited[there] == false) dfs(there);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    vt.resize(n + 1);
    while (m--)
    {
        scanf("%d %d", &a, &b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    
    scanf("%d %d %d", &seR, &hanR, &ADD);
    for (int i = 0; i < vt[seR].size(); i++)
    {
        se[seR] = true;
        int here = vt[seR][i];
        
        if (se[here] == false) sedfs(here);
    }
    
    for (int i = 0; i < vt[hanR].size(); i++)
    {
        int here = vt[hanR][i];
        if (han[here] == false) handfs(here);
    }
    
    for (int i = 0; i < vt.size(); i++) {
        for (int j = 0; j < vt[i].size(); j++)
        {
            int here = vt[i][j];
            if (se[here] == false && han[here] == false) dfs(here);
            pq.push(aaa);
            aaa = 0;
        }
    }
    
    while (ADD--)
    {
        cnt += pq.top();
        pq.pop();
    }
    
    printf("%d", cnt);
    
}
>>>>>>> 69999cd... 18.05.29
=======

>>>>>>> add185c... 18.07.06
