#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int day;
	int totalKorea;
	int totalMath;
	int dailykorea;
	int dailyMath;
	int koreaDay;
	int mathDay;

	cin>>day>>totalKorea>>totalMath>>dailykorea>>dailyMath;

	if(totalKorea%dailykorea!=0){
		koreaDay = totalKorea/dailykorea+1;
	}else{
		koreaDay = totalKorea/dailykorea;
	}

	if(totalMath%dailyMath!=0){
		mathDay = totalMath/dailyMath+1;
	}else{
		mathDay = totalMath/dailyMath;
	}

	if(koreaDay>=mathDay){
		cout<<day-koreaDay;
	}else{
		cout<<day-mathDay;
	}

}