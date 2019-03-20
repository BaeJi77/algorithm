#include <iostram>

using namespace std;

int n, T[21];

void function(int pos, vector<int> a, vector<int> b){
    if(pos == n){
        return;
    }

    a.push_back(pos);
    function(pos, a,b);
    a.pop_back();

    b.push_back(pos);
    function(pos,a,b);
    b.pop_back();
}

void func(int pos){
    if(pos == n){
        return;
    }

    T[pos] =0;
    func()
}

int main(){
    
}