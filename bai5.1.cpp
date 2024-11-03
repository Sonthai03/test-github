#include <iostream>
#include <fstream>

using namespace std;

void taofile()
{
	ofstream f("fISTFILE.txt");
		f << "Problem name: exp1Maximize \n";
		f << "obj: x1 + 2 x2 + 3 x3 + x4 \n";
		f  << "Subject To: \n";
		f << "c1: x2 - 3.5 x4 = 0 \n";
		f << "General x4\n";
		f << "end\n";
		 
	f.close(); 
}

void docfile()
{
	ifstream f("fISTFILE.txt");
	
	if(f.fail())
	{
		cout <<" khong the mo file! \n";
		return;
	}
	string son;
	while (getline(f, son))
	{
		cout << son << endl;
	};
	
	f.close();
}

int main() 
{
	taofile();
	docfile();
	
	return 0;
}