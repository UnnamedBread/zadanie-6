#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int random() {
    int a = (rand() % 100) + 1;
    return(a);
}
void random_array(int** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = random();
        }
    }
}

void print_array(int** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void composition(int** array1, int** array2, int** array3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    cin >> n;

    int** array1 = new int* [n];
    for (int i = 0; i < n; i++) {
        array1[i] = new int[n];
    }
    int** array2 = new int* [n];
    for (int i = 0; i < n; i++) {
        array2[i] = new int[n];
    }

    int** array3 = new int* [n];
    for (int i = 0; i < n; i++) {
        array3[i] = new int[n];
    }

    random_array(array1, n);

    random_array(array2, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array3[i][j] = 0;
        }
    }
    
    composition(array1, array2, array3, n);

    print_array(array1, n);
    cout << endl;
    print_array(array2, n);
    cout << endl;
    print_array(array3, n);

    for (int i = 0; i < n; i++) {
        delete array1[i];
    }
    delete array1;
    for (int i = 0; i < n; i++) {
        delete array2[i];
    }
    delete array2;

    for (int i = 0; i < n; i++) {
        delete array3[i];
    }
    delete array3;
    return(0);
}