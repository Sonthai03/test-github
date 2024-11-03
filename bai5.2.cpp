#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream file1("FILE1.txt");
	file1 << "7 2 \n"
			 "1 2 3 1\n"
			 "2 2 4 1\n"
			 "3 3 5 1\n";
			 
	file1.close();
	
	ofstream file2("FILE2.txt");
	file2 << "4 1 1 2\n"
		  	 "5 2 2 2\n"
		  	 "6 3 3 2\n"
		  	 "7 4 4 2\n";
		  	 
	file2.close();
	
	ifstream input1("FILE1.txt");
	ifstream input2("FILE2.txt");
	ofstream output("FILE3.txt");
	
	string dong;
	
	while(getline(input1, dong))
	{
		output << dong << '\n';
	}
	while (getline(input2, dong))
	{
		output << dong << '\n';
	}
	
	input1.close();
	input2.close();
	output.close();
	
	ifstream file3("FILE3.txt");
	cout << "file3 sau khi ghep noi dung cua file 1 va 2 la: " << endl;
	while(getline(file3, dong))
	{
		cout << dong << endl;
	}				   		  	 
	file3.close();
	
	return 0;
}