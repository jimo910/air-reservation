// register a passenger for a trip
// checkout if someone registered and in which class
// check through all members to be sure which one is due to go home
/*
1.list of passengers
2. an array of list of passengers in each class.
3.
*/
#include<iostream>
#include"air.h"
#include<vector>
#include<list>
using namespace std;
int main(){
cout <<" input your name, class, and no of year to stay"<<endl;
string name; int clas; int time_of;
cin>>name>>clas>> time_of;

passenger passengers(name, clas, time_of);
class_decider(passengers,name,clas, time_of);
passengers.print();
}
