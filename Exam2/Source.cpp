
//I affirm that all code given below was written solely by me, Husam Ghanim, and that any 
//help I received adhered to the rules stated for this exam.


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Runner.h"

using namespace std;


vector <Runner> sort(vector<Runner> v)     //sorts the vector in an an ascending order
{
	
	for (unsigned int i = 0; i < v.size(); i++)
	{
		for (unsigned int j = i; j < v.size(); j++)
		{
			if (v[j]>v[i])
			{
				Runner temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}

		}
	}
	return v;
}

	

int main()
{
	ifstream fin;
	string first, last, line;
	vector<Runner> v;
	int pace;
	string file="registrants.txt";
	

	fin.open(file);    //opens names list
	if (fin.fail())		// checks if open is successful
	{
		cout << "Can't open file." << endl;
		return 0;
	}

	

	while (!fin.eof())		//reads names and paces and stors them in an object vector.
	{
		fin >> first >> last >> pace;
		 v.push_back( Runner(first, last, pace));	
	}
	
	
	ofstream fwhite,fyellow,fgreen,forange,fblue,flilac,fred; 
	v= sort(v); //sends vector to sort function 
	

	for (unsigned int i = 0; i < v.size(); i++)	//reads from vector and assigns a color to each runner according to pace
	{
		if (v[i].getPace() >= 0 && v[i].getPace() <= 360)
		{
			fwhite.open("white.txt", ios::out | ios::app);
			if (fwhite.fail())
			{
				cout << "Problem happened in white." << endl;

				return 0;
			}
			fwhite << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			fwhite.close();
		}
		else if (v[i].getPace() >= 361 && v[i].getPace() <= 420)
		{
			fyellow.open("yellow.txt", ios::out | ios::app);
			if (fyellow.fail())
			{
				cout << "Problem happened in yellow." << endl;
				return 0;
			}
			fyellow << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			fyellow.close();
		}
		else if (v[i].getPace() >= 421 && v[i].getPace() <= 480)
		{
			fgreen.open("green.txt", ios::out | ios::app);
			if (fgreen.fail())
			{
				cout << "Problem happened in green." << endl;
				return 0;
			}
			fgreen << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			fgreen.close();
		}
		else if (v[i].getPace() >= 481 && v[i].getPace() <= 540)
		{
			forange.open("orange.txt", ios::out | ios::app);
			if (forange.fail())
			{
				cout << "Problem happened in orange." << endl;
				return 0;
			}
			forange << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			forange.close();
		}
		else if (v[i].getPace() >= 541 && v[i].getPace() <= 600)
		{
			fblue.open("blue.txt", ios::out | ios::app);
			if (fblue.fail())
			{
				cout << "Problem happened in blue." << endl;
				return 0;
			}
		fblue << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			fblue.close();
		}
		else if (v[i].getPace() >= 601 && v[i].getPace() <= 720)
		{
			flilac.open("lilac.txt", ios::out | ios::app);
			if (flilac.fail())
			{
				cout << "Problem happened in lilac." << endl;
				return 0;
			}
			flilac << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			flilac.close();
		}
		else if (v[i].getPace() >= 721 && v[i].getPace() <= 1200)
		{
			fred.open("red.txt", ios::out | ios::app);
			if (fred.fail())
			{
				cout << "Problem happened in red." << endl;
				return 0;
			}
			fred << v[i].getFirstName() << " " << v[i].getLastName() << " " << v[i].getPace() << endl;
			fred.close();
		}
		else
			cout << "Not in the list" << endl;
	}

	string fileToView;
	ifstream openFile;
	char choice;
	
	cout << "Enter the name of the file you want to view: ";    //prompts the user to enter the name of the file s/he wants to view
	cin >> fileToView;
	openFile.open(fileToView);

	if (openFile.fail())
	{
		cout << "Can't open file." << endl;
		return 0;
	}

	while (!openFile.eof())
	{
		openFile >> first >> last >> pace;
		cout << first << " " << last << " " << pace << endl;
	}
	openFile.close();
	cout << endl;
	cout << "Do you want to view another file? Y/N ";  //asks if the user wants to view another file and runs it in a loop till the uswer chooses no
	cin >> choice;

	while ((choice != 'N' && choice == 'Y') || (choice != 'n' && choice == 'y'))
	{
		cout << "Enter the name of the file you want to view: ";
		cin >> fileToView;
		openFile.open(fileToView);
		
		if (openFile.fail())
		{
			cout << "Can't open file." << endl;
			return 0;
		}
		while (!openFile.eof())
		{
			openFile >> first >> last >> pace;
			cout << first << " " << last << " " << pace << endl;
		}
		openFile.close();
		cout << endl;
		cout << "Do you want to view another file? Y/N";
		cin >> choice;
	}
	
	cout << "Would you like to clear the files? Y/N ";  //if the user wants to clear the files from content
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		ofstream del;
		del.open("white.txt");
			del.close();
		del.open("yellow.txt");
			del.close();
		del.open("green.txt");
			del.close();
		del.open("orange.txt");
			del.close();
		del.open("blue.txt");
			del.close();
		del.open("lilac.txt");
			del.close();
		del.open("red.txt");
			del.close();
	}

	

	return 0;
}