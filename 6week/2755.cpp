#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int T;
string str;
int score;;
string grade;
double sum;
double gradeSum;
double Rounding( double x, int digit )
{
	return ( floor( (x) * pow( float(10), digit ) + 0.5f ) / pow( float(10), digit ) );
}


int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d" , &T);
	for(int i = 0 ; i < T ; i++){
		cin>>str>>score>>grade;
		double temp=0;
		gradeSum += score;
		if(grade == "A+"){
			sum+= 4.3*score;
		}else if(grade == "A0"){
			sum+= 4.0*score;
		}else if(grade == "A-"){
			sum+= 3.7*score;
		}else if(grade == "B+"){
			sum+= 3.3*score;
		}else if(grade == "B0"){
			sum+= 3.0*score;
		}else if(grade == "B-"){
			sum+= 2.7*score;
		}else if(grade == "C+"){
			sum+= 2.3*score;
		}else if(grade == "C0"){
			sum+= 2.0*score;
		}else if(grade == "C-"){
			sum+= 1.7*score;
		}else if(grade == "D+"){
			sum+= 1.3*score;
		}else if(grade == "D0"){
			sum+= 1.0*score;
		}else if(grade == "D-"){
			sum+= 0.7*score;
		}
	}
	cout << fixed;
	cout.precision(2);
	printf("%.2f" , Rounding(sum/gradeSum , 3) );

}	