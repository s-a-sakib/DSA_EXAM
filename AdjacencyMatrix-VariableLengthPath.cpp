#include <bits/stdc++.h>
#define M 100

int matrix[M][M] , mult[M][M] = {0}, vertex;
using namespace std;

void multiplicationOfMatrix(int matrix[M][M], int mult[M][M]){
    
    int temp[M][M] = {0};

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            for (int k = 0; k < vertex; k++) {
                temp[i][j] += (matrix[i][k] * mult[k][j]);
            }
        }
    }
    for(int i = 0 ; i < vertex; i++) {
        for(int j = 0 ; j < vertex; j++) {
            mult[i][j] = temp[i][j];
        }
    }
}

void displayMatrix(int temp[M][M]){
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

void paths(){
    for(int i = 0 ; i < vertex; i++) {
        for(int j = 0 ; j < vertex; j++) {
            cout <<"V" << '[' <<i + 1<< ']' << "===>" << "V" <<'[' << j + 1<< ']' << "  :  " << mult[i][j] << endl;
        }
    }
}


int main() {
    cin >> vertex;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cin >> matrix[i][j];
            mult[i][j] = matrix[i][j];
        }
    }

    cout<<"Number of paths of length 1:\n";
    // multiplicationOfMatrix(matrix, mult);
    paths();

    cout<<"Number of paths of length 2:\n";
    multiplicationOfMatrix(matrix, mult);
    paths();

    // multiplicationOfMatrix(matrix, mult);
    // paths();

    
    return 0;
}