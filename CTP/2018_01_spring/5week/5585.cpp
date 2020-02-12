#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int rest;

string str;
int sum;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	rest=1000-n;

	while(rest!=0){
		if(rest>=500){
			int num500=0;
			num500 = rest/500;
			sum+=num500;
			rest = rest%500;
		}else if(rest>=100&&rest<500){
			int num100=0;
			num100 = rest/100;
			sum+=num100;
			rest = rest%100;
		}else if(rest>=50&&rest<100){
			int num50=0;
			num50 = rest/50;
			sum+=num50;
			rest = rest%50;
		}else if(rest>=10&&rest<50){
			int num10=0;
			num10 = rest/10;
			sum+=num10;
			rest = rest%10;
		}else if(rest>=5&&rest<10){
			int num5=0;
			num5 = rest/5;
			sum+=num5;
			rest = rest%5;
		}else if(rest>=1&&rest<5){
			int num1=0;
			num1 = rest/1;
			sum+=num1;
			rest = rest%1;
		}else{
			cout<<"오바야~"<<endl;
		}
	}

	cout<<sum;
}