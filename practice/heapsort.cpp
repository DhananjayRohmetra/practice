#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    if (2 * i + 1 < n && arr[largest] < arr[2 * i + 1])
    {
        largest = 2 * i + 1;
    }
    if (2 * i + 2 < n && arr[largest] < arr[2 * i + 2])
    {
        largest = 2 * i + 2;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}