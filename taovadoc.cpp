#include <iostream>
#include <fstream>

using namespace std;

void nhap(float a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

void docfile(char *t)
{
	ifstream f(t, ios::in );
	char s[100];
	
	cout << endl << "===== Doc File ======" << endl << endl;
	
	while (!f.eof())
	{
		f.getline(s, 100);
		cout << s << endl;
	};
	
	cout << endl << "===== Ket Thuc =====" << endl << endl;
}

void taofile(float *a, int n, char *t)
{
	ofstream f(t, ios::out);
	f << n << endl;
	
	for(int i = 0; i < n; i++)
	{
		f << a[i] << " x" << i;
		if(i < n - 1) f << " + ";
		
	}
	f.close();
	cout << "file da duoc tao!" << endl;
}

int main()
{
	int n;
	cout << " nhap n: ";
	cin >> n;
	float *a = new float[n];
	
	nhap(a, n);
	
	taofile(a, n, "console.txt");
	docfile("anhtenlagi.txt");
	
	delete [] a;
	return 0;
	
}