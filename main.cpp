Project-A---Problem-8.4---Heily-Cabrera
Write a program that reads in sec01/babynames.txt and produces two files, boynames.txt and girlnames.txt, separating the data for the boys and girls.
// Programmer: Heily Cabrera 
// Tester: Audrey Tapia 
// Group Project A // 
/***** Members *****/ 
/ Ashley Jacobson / 
/ Giannfranco Brance / 
/ Audrey Tapia / 
/ Heily Cabrera Guerrero/

#include <iostream>
#include <fstream>
#include <string>   
#include <sstream>  
#include <cctype>

using namespace std; 

int main()
{
  string iName =  "sec01/babynames.txt";
  string oBoyName = "boynames.txt";
  string oGirlName = "girlnames.txt";
  string line;
  int lineNum = 0;

ifstream inputFile(iName);
if (!inputFile.is_open()) 
{
        cerr << "Couldn't open iName file" << endl;
        return 1;
}

ofstream boyFile(oBoyName);
    if (!boyFile.is_open()) 
    {
        cerr << "Couldn't open oBoyName file" << endl;
        return 1;
    }

ofstream girlFile(oGirlName);
    if (!girlFile.is_open()) 
    {
        cerr << "Couldn't open oGirlName file" << endl;
        return 1;
    }

while (getline(inputFile, line)) 
{
        lineNum++; 

        if (line.empty()) 
        {
            continue;
        }

        istringstream iss(line);
        int rank;           
        string name;   
        char gender;    
        int count;          

        if (!(iss >> rank >> name >> gender >> count)) {
            std::cerr << "Couldn't parse line " << lineNum
                      << line << endl;
            continue;
        }

        if (gender == 'M') {
            boyFile << line << endl; 
        } else if (gender == 'F') {
            girlFile << line << endl; 
        } else {
            cerr << "Unknown gender '" << gender << lineNum
                      << line << endl;
        }
    }

    
    inputFile.close();
    boyFile.close();
    girlFile.close();


    return 0; 
}
