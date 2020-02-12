#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
bool check;

int main(){
    freopen("input.txt","r",stdin);
    cin>>N;
    while(N--){
        stack<int> st;
        check = true;
        string input;
        cin>>input;
        getchar();
        for(int i = 0 ; i < input.size() ; i++){
            char ch = getchar();
            cout<<ch<<endl;
            if(ch == '(')
                st.push(1);
            else if(ch == ')') {
                if(st.empty() || st.top() != 1){
                    check = false;
                    break;
                }else {
                    st.pop();
                }
            }
        }
        if(st.empty())
            check = false;

        cout<<(check ? "YES" : "NO" )<< endl;
    }
}