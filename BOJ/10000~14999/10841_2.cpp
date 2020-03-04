#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Person{
	public : 
	int age;
    int time;
	string name;

	Person(string name , int time, int age){
		this->name = name;
		this->age = age;
        this->time = time;
	}
};

bool operator <(const Person &a, const Person &b){
    if(a.age != b.age)
        return a.age < b.age;
    return a.time < b.time;
}

int n;
vector<Person> vt;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
	
	cin>>n;
	for(int i = 0 ; i < n ; i++){
        int age;
        string name;
		cin>>age>>name;
		vt.push_back(Person(name,i,age));
	}
	sort(vt.begin() , vt.end());
	for(int i = 0 ; i < n ; i ++){
		cout<<vt[i].age<<" "<<vt[i].name<<"\n";
	}
}


