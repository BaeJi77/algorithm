#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vt;
    
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);
    vt.push_back(4);
    vt.push_back(5);

    for(auto val : vt)
        cout<<val<<" ";
    puts("\n");

    vector<int> newVt(vt);
    newVt.push_back(1);
    newVt.push_back(2);
    newVt.push_back(3);
    newVt.push_back(4);
    newVt.push_back(5);

    sort(newVt.begin(), newVt.end());
    for(auto val : newVt)
        cout<<val<<" ";
}
