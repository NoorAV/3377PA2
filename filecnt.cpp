//filecnt.cpp
//This program takes the list of directories and files in a directory and sorts them to find the number of directories, the number of files and the number of bytes they occupy.
//Alter program

#include<iostream>
#include<fstream>
#include "version.h"

using namespace std;

int main(int argc, char** argv)
{
	//Get list of files and directories and store
	string commandArg = argv[1];
	commandArg = "ls -l " + commandArg + " > data.txt";
	const char *command  = commandArg.c_str();
	system(command);

	int numDir = 0;
	int numFiles = 0;
	int totalBytes = 0;

	ifstream file("data.txt");
    	string str; 
    	while (getline(file, str))
    	{
    		if(str.at(1) == 'r')
		{
			if(str.at(0) == 'd')
			{
				numDir++;
			}
			else
			{
				numFiles++;
			}

			str = str.substr(28);
			string strBytes = "";
			for(int i = 0; i < 6; i++)
			{
				if(isdigit(str.at(i)))
				{
					strBytes = strBytes + str.at(i);
				}
			}
			int numBytes = stoi(strBytes);
			totalBytes = totalBytes + numBytes;
				
		}
    	}

	cout << "The total number of directories in directory " << argv[1] << " is: " << numDir << ". The total number of files in directory " << argv[1] << " is: " << numFiles << ". The total number of bytes occupied by all files in directory " << argv[1] << " is:  " << totalBytes << ".";
	version v;
	v.displayVersion();    	
	return 0;
}
