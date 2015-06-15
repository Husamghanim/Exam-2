//I affirm that all code given below was written solely by me, Husam Ghanim, and that any 
//help I received adhered to the rules stated for this exam.


#ifndef RUNNER_H
#define RUNNER_H
#include <string>
using namespace std;

class Runner
{
public:
	Runner(string,string,int);
	string getFirstName();
	string getLastName();
	int getPace();
	friend bool operator<(Runner, Runner);
	friend bool operator<=(Runner, Runner);
	friend bool operator==(Runner, Runner);
	friend bool operator!=(Runner, Runner);
	friend bool operator>=(Runner, Runner);
	friend bool operator>(Runner, Runner);
private:
	string firstname;
	string lastname;
	int pace;
};

#endif