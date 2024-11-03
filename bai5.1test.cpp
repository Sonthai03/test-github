#include <iostream>
#include <fstream>

using namespace std;

// Hàm tạo file mới
void createFile() {
  ofstream fout("FIRSTFILE.txt");

  fout << "Problem name: exp1Maximize\n";
  fout << "obj: x1 + 2 x2 + 3 x3 + x4\n";
  fout << "Subject To\n";
  fout << "c1: x2 - 3.5 x4 = 0\n";
  fout << "0 <= 1 <= 40\n";
  fout << "General x4\n";
  fout << "End\n";

  fout.close();
}

// Hàm đọc file và hiển thị nội dung ra màn hình
void readFile() {
  ifstream fin("FIRSTFILE.txt");

  if (fin.fail()) {
    cout << "Khong the mo file\n";
    return;
  }

  string line;
  while (getline(fin, line)) {
    cout << line << "\n";
  }

  fin.close();
}

int main() {
  createFile();
  readFile();

  return 0;
}

