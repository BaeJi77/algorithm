#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int grade;
int Max=0;
double sum;


int main(){
	freopen("input.txt", "r", stdin);
	vector<int> Good;

	cin>>n;
	cout.precision(2);
	while(n--){
		cin>>grade;

		if(grade>Max){
			Max=grade;
		}
		Good.push_back(grade);
	}
	for(int i=0;i<n;i++){
		cout<<Good[i]<<endl;
		sum+=(Good[i]/Max)*100;
	}
	cout<<sum;
}