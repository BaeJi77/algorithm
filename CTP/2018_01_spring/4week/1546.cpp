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
<<<<<<< HEAD
<<<<<<< HEAD
	int num=n;
	
=======
	cout.precision(2);
>>>>>>> bd884f8... 18.03.20 commit
=======
	int num=n;
	
>>>>>>> ecb026a... 18.03.20
	while(n--){
		cin>>grade;

		if(grade>Max){
			Max=grade;
		}
		Good.push_back(grade);
	}
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
	for(int i=0;i<n;i++){
=======
	for(int i=0;i<num;i++){
		// cout<<Good[i]<<endl;
		Good[i]=(Good[i]/Max)*100;
>>>>>>> ecb026a... 18.03.20
		cout<<Good[i]<<endl;
	}
<<<<<<< HEAD
	cout<<sum;
>>>>>>> bd884f8... 18.03.20 commit
=======
	for(int i=0;i<num;i++){
		sum=sum+Good[i];
	}
	cout.precision(2);
	cout<<sum/num;
>>>>>>> ecb026a... 18.03.20
}