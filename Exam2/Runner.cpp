//I affirm that all code given below was written solely by me, Husam Ghanim, and that any 
//help I received adhered to the rules stated for this exam.



#include "Runner.h"

Runner::Runner(string first,string last, int p)
{
	firstname = first;
	lastname = last;
	pace = p;
}
string Runner::getFirstName()
{
	return firstname;
}
string Runner::getLastName()
{
	return lastname;
}
int Runner::getPace()
{
	return pace;
}
bool operator<(Runner r1, Runner r2)
{
	return ( r1.pace< r2.pace);
}
bool operator<=(Runner r1, Runner r2)
{
	return (r1.pace <= r2.pace);
}
bool operator==(Runner r1, Runner r2)
{
	return (r1.pace == r2.pace);
}bool operator!=(Runner r1, Runner r2)
{
	return (r1.pace != r2.pace);
}
bool operator>=(Runner r1, Runner r2)
{
	return (r1.pace >= r2.pace);
}
bool operator>(Runner r1, Runner r2)
{
	return (r1.pace > r2.pace);
}