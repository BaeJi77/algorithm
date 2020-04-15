#include <iostream>
#include <vector>
using namespace std;

class SparseArray {
  private:
  vector<int> arr;
  int length = 0;
  
  public:
  SparseArray(vector<int> pre) {
    int inputLength = pre.size();
    for(int i = 0 ; i < inputLength ; i++) {
        if(pre[i] != 0) {
            arr.push_back(pre[i]);
        }
    }
    length = arr.size();
  }

  int get(int idx) {
      if(length <= idx) return -1;
      return arr.at(idx);
  }

  int set(int idx, int newValue) {
      if (length <= idx) return -1;
      arr[idx] = newValue;
      return 1;
  }
};

// To execute C++, please define "int main()"
int main() {
  vector<int> vt;
  vt.push_back(0);
  vt.push_back(1);
  vt.push_back(0);
  vt.push_back(2);
  vt.push_back(0);
  SparseArray sa(vt);
  cout<<sa.get(0)<<endl;
  cout<<sa.get(1)<<endl;
  cout<<sa.get(2)<<endl;
  cout<<sa.get(3)<<endl;
  cout<<sa.set(0, 5)<<endl;
  cout<<sa.get(0)<<endl;
  return 0;
}
