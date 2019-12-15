#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s="12 19 17 20";
	stringstream iss(s);
	int a;
	while(iss>>a)
		cout<<a<<"\t";

	cout<<"\nError:\n\tThe input file is not DIMACS format";
	return 0;
}