#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	vector <int> vec;
	vec.push_back(1);
	vec.push_back(10);
	vec.push_back(12);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(2);

	for(int i=0;i<vec.size()-1;i++){
		for(int j=1;j<vec.size()-i;j++){
			if(vec[j-1]>vec[j]){
				swap(vec[j-1],vec[j]);
			}
		}
	}

	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<endl;
	}
}
