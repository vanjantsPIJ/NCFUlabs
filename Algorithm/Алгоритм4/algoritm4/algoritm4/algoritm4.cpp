#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a[10];
    int n = 10;
    cout << "Введите значения массива:" << endl;
    for ( int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
    int counter = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (a[j]<a[i])
            {
                int tmp1 = a[i];
                int tmp2 = a[j];
                a[i] = tmp2;
                a[j] = tmp1;
                counter++;
            }
        }
    }
    cout << counter << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
}

void ShakerSort(int* a, int n) {
    int left, right, i;
    left = 0;
    right = n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        right--;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
}

void Sort(int* a, int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            counter++;
            int tmp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = tmp;
        }
    }
    cout << counter << endl;
}