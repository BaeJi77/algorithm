#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> newList;

    newList.push_back(11);
    newList.push_back(12);
    newList.push_back(13);
    newList.push_back(14);
    newList.push_back(15);
    cout<<*newList.begin()<<endl;
    cout<<*newList.end()<<endl;

    for(auto val : newList) {
        cout<<val<<" ";
    }
    puts("");

    list<int> mergeList;
    mergeList.push_back(10);

    mergeList.merge(newList);
    // newList.merge(mergeList);

    for(auto val : mergeList) {
        cout<<val<<" ";
    }
    puts("");

    if(newList.empty())
        cout<<"newList empty\n";
}
