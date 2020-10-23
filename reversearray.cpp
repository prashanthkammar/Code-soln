// reverse an array in place

#include <iostream>
using namespace std;

void reverse(int *a, int n)
{
    int front = 0, back = n - 1;
    while (front < back)
    {
        swap(a[front], a[back]);
        front++;
        back--;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    reverse(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}