#include <stack>
#include <cstdio>

using namespace std;

int main() {
    int k;
    stack<int> st;
    scanf("%d", &k);
    for(int i = 0 ; i < k ; ++i ) {
        int q;
        scanf("%d", &q);
        if(q == 0) st.pop();
        else st.push(q);
    }
    
    int ans = 0;
    int stackSize = st.size();
    for(int i = 0 ; i < stackSize ; ++i) {
        ans += st.top();
        st.pop();
    }    
    printf("%d", ans);
}