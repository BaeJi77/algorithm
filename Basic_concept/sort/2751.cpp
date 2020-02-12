#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int number;

int main(){
	freopen("input.txt", "r", stdin);
	vector<int> arr;

	cin>>n;
	for(int i;i<n;i++){
		cin>>number;
		arr.push_back(number);
	}

	sort(arr.begin(),arr.end());

	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}