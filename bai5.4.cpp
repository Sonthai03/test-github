#include <iostream>
#include <fstream>

using namespace std;

void nhap(double *a, int &n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> *(a + i);
	}
}

void taofile(double *a, int n)
{
	ofstream file("dathuc.txt");
	file << n << endl;
	for(int i = 0; i < n; i++)
	{
		file << a[i];
		if(i != n - 1)
		{
			file << " ";
		}
	}
	
	file << endl;
	
	file << a[0];
	for(int i = 1; i < n; i++)
	{
		file << "+" << "x" << i;
	}
	file << endl;
	
	file.close();
	
	cout << "file da duoc tao! \n";
}

void docfile()
{
	ifstream input("dathuc.txt");
	if(!input)
	{
		cout << "khong the mo file!\n";
		return;
	}
	string dong;
	while(getline(input, dong))
	{
		cout << dong << endl;
	}
	
	input.close();
}

int main()
{
	int n; 
	cout << "nhap so phan tu cua mang: "; cin >> n;
	double *a = new double[n];
	nhap(a, n);
	taofile(a, n);
	docfile();
	
	delete [] a;
	
	return 0;
	
}

