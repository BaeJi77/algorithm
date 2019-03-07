#include <cstdio>
#include <stack>

using namespace std;

int N,a[500004],order[500004];
stack<pair<int,int> > st;
stack<int> ist;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&a[i]);
    }

    st.push(make_pair(N-1,a[N-1]));
    for(int i = N-2 ; i >= 0 ; i--){
        stack<int> temp;
        if(st.empty())
            st.push(make_pair(i,a[i]));
        else if(st.top().second > a[i]){
            st.push(make_pair(i,a[i]));
        }else{
            while(st.empty() == false && st.top().second <= a[i]){
                order[st.top().first] = i+1;
                st.pop();
            }
            st.push(make_pair(i,a[i]));
        }
    }

    for(int i = 0 ; i < N ; i++){
        printf("%d " , order[i]);
    }
}