<<<<<<< HEAD
<<<<<<< HEAD
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXX 10000010

using namespace std;

int m,d,sum;
int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
=======
#include <iostream>
#include <string>
=======
#include <cstdio>
#include <algorithm>
>>>>>>> 87d98ca... 18.03.25
#include <vector>
#define MAXX 10000010

using namespace std;

<<<<<<< HEAD
int n;
string str;
>>>>>>> 46dfa63... 18.03.23
=======
int m,d,sum;
int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
>>>>>>> 87d98ca... 18.03.25


int main(){
	freopen("input.txt", "r", stdin);

<<<<<<< HEAD
<<<<<<< HEAD
	scanf("%d %d" , &m,&d);
	for(int i = 1 ; i < m ; i++){
		sum+=arr[i-1];
	}
	sum+=d;

	switch(sum%7){
		case 0:
		printf("SUN\n");
		break;

		case 1:
		printf("MON\n");
		break;

		case 2:
		printf("TUE\n");
		break;

		case 3:
		printf("WED\n");
		break;

		case 4:
		printf("THU\n");
		break;

		case 5:
		printf("FRI\n");
		break;

		case 6:
		printf("SAT\n");
		break;

	}
}


=======
	cin>>n;
	if(n<=100&&n>=90){
		cout<<"A";
	}else if(n<90&&n>=80){
		cout<<"B";
	}else if(n<80&&n>=70){
		cout<<"C";
	}else if(n<70&&n>=60){
		cout<<"D";
	}else{
		cout<<"F";
	}
}
>>>>>>> 46dfa63... 18.03.23
=======
	scanf("%d %d" , &m,&d);
	for(int i = 1 ; i < m ; i++){
		sum+=arr[i-1];
	}
	sum+=d;

	switch(sum%7){
		case 0:
		printf("SUN\n");
		break;

		case 1:
		printf("MON\n");
		break;

		case 2:
		printf("TUE\n");
		break;

		case 3:
		printf("WED\n");
		break;

		case 4:
		printf("THU\n");
		break;

		case 5:
		printf("FRI\n");
		break;

		case 6:
		printf("SAT\n");
		break;

	}
}


>>>>>>> 87d98ca... 18.03.25
