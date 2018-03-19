#include <iostream>
#include <string>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> 46dfa63... 18.03.23
=======
>>>>>>> 1ff6c3c... 18.05.08
#include <cstdio>
#include <algorithm>


using namespace std;

int n;
int num;
int arr[1100];
int sum;

<<<<<<< HEAD
<<<<<<< HEAD
=======
/**
* 정렬
* STL algorithm
*/


>>>>>>> 46dfa63... 18.03.23
=======
>>>>>>> 1ff6c3c... 18.05.08
int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d",&n);
	num = 1000-n;
	while(num!=0){
		if(num>=500){
			int num500=num/500;
			sum+=num500;
			num = num%500;
		}else if(num>=100&&num<500){
			int num100=num/100;
			sum+=num100;
			num = num%100;
		}else if(num>=50&&num<100){
			int num50=num/50;
			sum+=num50;
			num = num%50;
		}else if(num>=10&&num<50){
			int num10=num/10;
			sum+=num10;
			num = num%10;
		}else if(num>=5&&num<10){
			int num5=num/5;
			sum+=num5;
			num = num%5;
		}else if(num>=1&&num<5){
			int num1=num/1;
			sum+=num1;
			num = num%1;
		}
	}
	cout<<sum;
}