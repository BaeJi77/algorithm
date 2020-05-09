#include <iostream>
using namespace std;

long long ll;

int main() {
	int n;
	cin>>n;//몇개를 받을지 결정
	while(n--) {
        int a, b;
        cin>>a>>b;
        int k = 1;
        for(int i = 0 ; i < b; ++i) {
            k *= a;
            k %= 10;
        }
        
        if(k == 0) cout<<"10";
        else cout<<k;
        cout<<"\n";
    }
}