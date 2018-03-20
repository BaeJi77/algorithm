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
	int num=n;
	
	while(n--){
		cin>>grade;

		if(grade>Max){
			Max=grade;
		}
		Good.push_back(grade);
	}
	for(int i=0;i<num;i++){
		// cout<<Good[i]<<endl;
		Good[i]=(Good[i]/Max)*100;
		cout<<Good[i]<<endl;
	}
	for(int i=0;i<num;i++){
		sum=sum+Good[i];
	}
	cout.precision(2);
	cout<<sum/num;
}