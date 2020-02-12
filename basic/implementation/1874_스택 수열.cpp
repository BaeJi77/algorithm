#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int MAX = 1e5;
vector<char> ans;
stack<int> st;

int N;
int order[MAX+1];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &order[i]);
    }

    int idx = 0;
    int insertNumber = 1;
    while(1){
        if(st.empty() || st.top() != order[idx]){
            st.push(insertNumber);
            ans.push_back('+');
            insertNumber++;
        }
        if(st.top() == order[idx]){
                idx++;
                st.pop();
                ans.push_back('-');
        }

        if(insertNumber > N)
            break;
    }

    while(!st.empty() && st.top() == order[idx]){
        ans.push_back('-');
        idx++;
        st.pop();
    }

    if(!st.empty()){
        printf("NO");
    }else{
        for(int i = 0 ; i < ans.size(); i++)
            printf("%c\n", ans[i]);
    }
}