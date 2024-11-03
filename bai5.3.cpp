#include <iostream>
#include <fstream>

using namespace std;

void hienThiMaTran(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int** taoMatran(int n, int m) {
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    return a;
}

void GhimaTranvaotep(int** a, int n, int m) {
    ofstream output("MaTrix.txt");
    output << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output << a[i][j] << " ";
        }
        output << endl;
    }

    output.close();

    cout << "Da ghi ma tran vao file MaTrix.txt" << endl;
}

int** Docmatran(int& n, int& m) {
    ifstream input("MaTrix.txt");
    input >> n >> m;

    int** docmatran = new int*[n];
    for (int i = 0; i < n; i++) {
        docmatran[i] = new int[m];
        for (int j = 0; j < m; j++) {
            input >> docmatran[i][j];
        }
    }
    input.close();
    cout << "Ma tran da duoc doc tu tep MaTrix.txt\n";

    return docmatran;
}

void Giaiphong(int** a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int main() {
    int n, m;

    cout << "Nhap so dong: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;

    int** matran = taoMatran(n, m);

    GhimaTranvaotep(matran, n, m);

    int rows, cols;
    int** docmatran = Docmatran(rows, cols);
	hienThiMaTran(docmatran, rows, cols);
	
    Giaiphong(docmatran, rows);
    Giaiphong(matran, n);

    return 0;
}
