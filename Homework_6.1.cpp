#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int random() {
    
    int a = (rand() % 100) +1;
    return(a);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    int m;
    int min = 101;
    int nmin;
    int mmin;
    cin >> n >> m;
    int **array = new int *[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = random();
            if (min > array[i][j]) {
                min = array[i][j];
                nmin = i;
                mmin = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = nmin; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = array[i + 1][j];

        }
    }
    
    for (int j = mmin; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            array[i][j] = array[i][j + 1];

        }
    }
    
    for (int i = 0; i < n; i++) {
        array[i][m - 1] = 0;
    }
    for (int i = 0; i < m; i++) {
        array[n-1][i] = 0;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete array[i];
    }
    delete array;

    return(0);
}