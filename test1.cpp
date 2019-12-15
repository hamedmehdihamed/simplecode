#include<minisat/core/Solver.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<sstream>
using namespace std;
void printvector(vector<list<int>> c);
int main()
{
	int M,N,v,i=0;
	char ch;
	string line;
	vector<list<int>> cloouselist;
	ifstream input;
	input.open("Data.dat");
	
	while(getline(input,line))
	{
		stringstream iss(line);
		iss>>ch;
		if(ch=='c')
			continue;
		else if(ch=='p')
		{
			iss>>N>>M;
			cout<<"N = "<<N<<" M = "<<M<<endl;
			cloouselist = vector<list<int>> (M);
			continue;
		}
		else
		{
			stringstream iss(line);
			while(iss>>v)
			{
				cloouselist[i].push_back(v);
				cout<<v<<"\t";
			}
		}
		cout<<endl;
		i++;
	}
	/*
	for(int i = 0; i<cloouselist.size(); i++)
    {
        for(auto j = cloouselist[i].begin(); j != cloouselist[i].end(); j++)
        {
            cout<<*j<<" "; //adjList[i][j] doesnt work

        }
        cout<<endl;
    }
	*/
	printvector(cloouselist);
	cout<<"\nThe number of clauses is : "<<i-1<<endl;


	return 0;
}
void printvector(vector<list<int>> c)
{
	for(int i = 0; i<c.size(); i++)
    {
        for(auto j = c[i].begin(); j != c[i].end(); j++)
        {
            cout<<*j<<" "; //adjList[i][j] doesnt work

        }
        cout<<endl;
    }
}