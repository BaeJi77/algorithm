#include <iostream>
#include <vector>

using namespace std;

class stack {
    private:
        vector<int> arr;
        int index = -1;

    public:
        stack() {}

        void push(int value) {
            arr.push_back(value);
            index++;
        }

        int top() {
            if(index == -1) return -1;
            return arr[index];
        }

        int size() {
            return arr.size();
        }
        
        int pop() {
            if(index == -1) return -1;
            int ret = arr[index];
            arr.pop_back();
            index--;
            return ret;
        }
};

int main() {
    stack* st = new stack();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);

    int lenght = st->size();
    for(int i = 0 ; i < lenght ; i++) {
        cout<<st->pop()<<endl;
    }
}