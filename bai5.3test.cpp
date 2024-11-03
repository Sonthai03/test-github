#include <iostream>
#include <fstream>

using namespace std;

// Hàm để hiển thị ma trận
void hienThiMaTran(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm để tạo ma trận từ dữ liệu nhập từ bàn phím
int** taoMaTran(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }
    
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    return matrix;
}

// Hàm để ghi ma trận vào tệp tin
void ghiMaTranVaoTep(int** matrix, int n, int m) {
    ofstream outputFile("MATRIX.txt");
    if (outputFile.is_open()) {
        outputFile << n << " " << m << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                outputFile << matrix[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Da ghi ma tran vao file MATRIX.txt.\n";
    } else {
        cout << "Khong the mo file MATRIX.txt de ghi.\n";
    }
}

// Hàm để đọc ma trận từ tệp tin
int** docMaTranTuTep(int& rows, int& cols) {
    ifstream inputFile("MATRIX.txt");
    if (inputFile.is_open()) {
        inputFile >> rows >> cols;
        
        int** readMatrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            readMatrix[i] = new int[cols];
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                inputFile >> readMatrix[i][j];
            }
        }
        inputFile.close();
        
        cout << "Ma tran duoc doc tu file MATRIX.txt:\n";
        return readMatrix;
    } else {
        cout << "Khong the mo file MATRIX.txt de doc.\n";
        return nullptr;
    }
}

// Hàm để giải phóng bộ nhớ của ma trận
void giaiPhongBoNho(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n, m;
    
    // Nhập số dòng và số cột từ bàn phím
    cout << "Nhap so dong: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
    
    // Tạo ma trận từ dữ liệu nhập từ bàn phím
    int** matrix = taoMaTran(n, m);
    
    // Ghi ma trận vào tệp tin MATRIX.txt
    ghiMaTranVaoTep(matrix, n, m);
    
    // Đọc ma trận từ tệp MATRIX.txt và hiển thị lên màn hình
    int rows, cols;
    int** readMatrix = docMaTranTuTep(rows, cols);
    if (readMatrix != nullptr) {
        hienThiMaTran(readMatrix, rows, cols);
        
        // Giải phóng bộ nhớ
        giaiPhongBoNho(readMatrix, rows);
    }
    
    // Giải phóng bộ nhớ
    giaiPhongBoNho(matrix, n);
    
    return 0;
}
