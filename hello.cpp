#include <minisat/core/Solver.h>
#include <iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<sstream>
using namespace std;
class CNF
{
	int N; //number of variables
	int M; //number of clouses
	vector<list<int>> Clauselist;
	vector<int> Solution;
	int Issatisfiable;
public:
	void ReadCNFfromFile(string filename);
	void WriteCNFtoFile();
	void SolveMinisat();
	void NotDIMACSFormat();

};
void CNF::ReadCNFfromFile(string filename)
{
	char ch;
	int i=0,v;
	string line;
	ifstream input;
	//input.open(filename);
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
			Clauselist = vector<list<int>> (M);
			Solution = vector<int> (N);
			continue;
		}
		else
		{
			stringstream iss(line);
			while(iss>>v)
			{
				Clauselist[i].push_back(v);
				cout<<v<<"\t";
			}
		}
		i++;
	}
	if((--i)!=M)
	{
		NotDIMACSFormat();
		cout<<"\n\tThe number of clauses is not sound";
	}
}
void CNF::NotDIMACSFormat()
{
	cout<<"\nError:\n\tThe input file is not DIMACS format\n";
}
int main()
{
	using Minisat::mkLit;
	using Minisat::lbool;
	CNF c;
	c.NotDIMACSFormat();
	//ifstream input;
	//input.open("Data.dat");

	Minisat::Solver solver;



	//Minisat::Solver
	//Create variable
	
	auto A = solver.newVar();
	auto B = solver.newVar();
	auto C = solver.newVar();

	//Create the clauses
	solver.addClause(mkLit(A), mkLit(B), mkLit(C));
	solver.addClause(~mkLit(A), mkLit(B), mkLit(C));
	solver.addClause(mkLit(A), ~mkLit(B), mkLit(C));
	solver.addClause(mkLit(A), mkLit(B), ~mkLit(C));
	auto sat = solver.solve();


	cout<<"Hello Hamed";

	 if (sat) {
        std::clog << "SAT\n"
                  << "Model found:\n";
        std::clog << "A := " << (solver.modelValue(A) == l_True) << '\n';
        std::clog << "B := " << (solver.modelValue(B) == l_True) << '\n';
        std::clog << "C := " << (solver.modelValue(C) == l_True) << '\n';
    } else {
        std::clog << "UNSAT\n";
		return 1;
	}
	return 0;
}