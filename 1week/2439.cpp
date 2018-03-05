#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        unsigned int j=n;
        while(j>0){
            if(j>i+1){
                cout<<" ";
                j--;
            }else{
                cout<<"*";
                j--;
            }   
        }

        cout<<endl;
    }
    return 0;
}
