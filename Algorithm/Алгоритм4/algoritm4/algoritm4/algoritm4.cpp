#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a[10];
    int n = 10;
    cout << "Введите значения массива:" << endl;
    for ( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
  Sort(a, n);
  ShakerSort(a,n);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
}

void ShakerSort(int* a, int n) {
    int left, right, i;
    int counter = 0;
    left = 0;
    right = n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                counter++;
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                counter++;
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
