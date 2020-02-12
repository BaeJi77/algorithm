#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

#define MAX 20000
using namespace std;

int v,e,in[MAX+4],out[MAX+4];
bool visited[MAX+4];
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > scc;
vector<vector<int> > scv;
stack<int> st;

void dfs(int here){
    visited[here] = true;
    for(auto there : vt[here]){
        if(visited[there] == false)
            dfs(there);
    }
    st.push(here);
}

void mscc(int here , int cnt){
    visited[here] = true;
    scc[cnt].push_back(here);
    for(auto there : rvt[here]){
        if(visited[there] == false)
            mscc(there,cnt);
    }
}

void init(){
    vt.clear();
    rvt.clear();
    scc.clear();
    scv.clear();
    memset(visited,0,sizeof(visited));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d" , &t);
    while(t--){
        init();
        scanf("%d %d" , &v,&e);
        vt.resize(v+1);
        rvt.resize(v+1);
        scc.resize(v+1);
        for(int i = 0 ; i < e ; i++){
            int a,b;
            scanf("%d %d" , &a,&b);
            vt[a].push_back(b);
            rvt[b].push_back(a);
        }

        for(int i = 0 ; i < v ; i++){
            if(visited[i] == false)
                dfs(i);
        }

        int cnt=0;
        memset(visited,0,sizeof(visited));
        for(int i = 0 ; i < v ; i++){
            int top = st.top();
            st.pop();
            if(visited[top] == true)
                continue;
            scc.resize(++cnt);
            mscc(top , cnt-1);
        }
        
        for(int i = 0 ; i < v ; i++){
            for(auto j : vt[i]){
                if(scc[i] != scc[j]){
                    out[i]++;
                    in[j]++;
                }
            }
        }

        int outNumber=0,inNumber=0;
        for(int i = 0 ; i < scc.size() ; i++){
            if(out[i] == 0) outNumber++;
            if(in[i] == 0) inNumber++;
        }
        
        printf("%d\n" , max(outNumber,inNumber));
    }
}