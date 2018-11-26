#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

#define MAX 10000
using namespace std;

int v, e;
bool visited[MAX+4];
stack<int> st;
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > ssc;

void dfs(int here){
    visited[here] = true;
    for(auto there : vt[here]){
        if(visited[there] == false)
            dfs(there);
    }
    st.push(here);
}

void makeSSC(int here,int cnt){
    visited[here] = true;
    ssc[cnt].push_back(here);
    for(auto there : rvt[here]){
        if(visited[there] == false)
            makeSSC(there,cnt);
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    scanf("%d %d", &v, &e);
    vt.resize(v + 1);
    rvt.resize(v + 1);
    ssc.resize(v+1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vt[a].push_back(b);
        rvt[b].push_back(a);
    }

    for(int i = 0 ; i < v ; i++){
        if(visited[i] == false)
            dfs(i);
    }
    
    int cnt = 0;
    memset(visited,0,sizeof(visited));
    for(int i = 0 ; i < v ; i++){
        int sttop = st.top();
        st.pop();
        if(visited[sttop] == true) continue;
        ssc.resize(++cnt);
        makeSSC(sttop,cnt-1);
    }

    for(int i = 0 ; i < cnt ; i++){
        sort(ssc[i].begin(),ssc[i].end());
    }
    sort(ssc.begin(),ssc.end());
    // reverse(ssc.begin(),ssc.end());
    printf("%d\n",cnt);
    for(int i = 0 ; i < cnt ; i++){
        for(int j = 0 ; j < ssc[i].size() ; j++){
            printf("%d ", ssc[i][j]);
        }
        printf("-1\n");
    }
}
