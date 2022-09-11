#include <iostream>
#include<vector>
 using namespace std;

class passenger{
 	public:
 	explicit passenger(string name, int classes, int time_of_stay );
 	friend  void class_decider(passenger &pass, string name, int classes, int time_of_stay );
 		int timer_of_stay();
 		 virtual int amount();
 		void print();
 		 ~passenger();
	private:
            friend void include_passenger();
			string Name;
			int  clas;
			int time_of_stays;
			int amounts;
			passenger* passengers;

 };

int virtualViaPointer(passenger * baseClassPtr );

class executive_passenger : public passenger
{
 	public:
 		explicit executive_passenger(string name, int classes, int time_of_stay );
		int amount() override;
	private:
		string name;
		int  amounts;
};


class normal_passenger : public passenger{
	public :
		explicit normal_passenger(string name, int classes, int time_of_stay );
		int amount() override;
	private:
		string name;
		int time;
		int amounts;
};

class economic_passenger: public passenger{
	public :
	   explicit economic_passenger(string name, int classes, int time_of_stay );
		int amount() override;
	private:
		string name;
		int time;
		 int  amounts;
};

 class classerror{};

 passenger::passenger(string name, int classes, int time_of_stay ){
 try{

 if(classes<0 || classes>3 ) throw classerror();
	Name= name;
 	clas= classes;
 	time_of_stays= time_of_stay;
}
catch(classerror){
	cout<<"error"<<endl;
}

}
int passenger::timer_of_stay(){
	return time_of_stays;
}

 void passenger::print(){
 	cout<<"passenger" <<this->Name << "of class" <<this->clas << "that paid a total sum of "<< this->amounts << "is sheduled already"<<endl;
 }
int passenger::amount(){
    cout<< "wahala oooo"<<endl;
 	return 0;
 }
 passenger::~passenger(){
 cout<< "delete the object abeg"<<endl;
 }
int economic_passenger::amount(){
	cout<<" economical passenger entered"<<endl;
    int y =passenger::timer_of_stay();
   // int y =1;
   int  z= 10000 * y;
	return z;
}
int normal_passenger::amount(){
    cout<<" normal passenger entered"<<endl;
    int y =passenger::timer_of_stay();
    //int y= 1;
   int  z= 1000 * y;
	return z;
}
int executive_passenger::amount(){
cout<<" executive passenger entered"<<endl;
    int y =passenger::timer_of_stay();
   int  z= 20000 * y;
	return z;
}
normal_passenger::normal_passenger(string name, int classes, int time_of_stay ):passenger( name,classes,time_of_stay ){

}

executive_passenger::executive_passenger(string name, int classes, int time_of_stay ):passenger( name,classes,time_of_stay ){

}


economic_passenger::economic_passenger(string name, int classes, int time_of_stay ):passenger( name,classes,time_of_stay ){

}
void class_decider(passenger &pass, string name, int classes, int time_of_stay ){
    vector<passenger *> passengers(3);
    passengers[0] = new normal_passenger( name,classes,time_of_stay );
    passengers[1]= new economic_passenger( name,classes,time_of_stay );
    passengers[2]= new executive_passenger( name,classes,time_of_stay );
   // int counters = 0;
    cout<<"pass.clas="<< pass.clas<<endl;
   /* for( passenger* passege: passengers){
        if(pass.clas== counters){
          int x= virtualViaPointer(passege);
          pass.amounts= x;
        }
        c
        ounters= counters + 1;
    }*/
    passenger* passege = passengers[pass.clas];
    int x= virtualViaPointer(passege);
    pass.amounts= x;
}

int virtualViaPointer(passenger * passege )
{
    int x = passege->amount();
     return x;
 //cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void include_passenger(passenger &pas;)
