//filedisp.cpp
//This program takes the output of filecnt.cpp and displays the information the user want to see based on their input.

#include<iostream>

using namespace std;

//main function
int main(int argc, char** argv)
{
	//String to store output of fileent.cpp
	string data;
	//String stores user option
	string option = argv[1];
	getline(cin, data);
	int index;
	
	//Depending on user option extract part of string
	if(option == "-d")
	{
		index = data.find(".");
		data = data.substr(0,index+1);
	}
	else if(option == "-f")
	{
		index = data.find(".");
		data = data.substr(index+2);
		index = data.find(".");
		data = data.substr(0,index+1);
	}
	else if(option == "-b")
	{
		index = data.find(".");
		data = data.substr(index+1);
		index = data.find(".");
		data = data.substr(index+1);
		data = data.substr(1);
	}
	
	//Print the information for the user.
	cout << data << endl;

    	return 0;
}