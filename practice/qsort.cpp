#include <bits/stdc++.h>
using namespace std;
int findpartition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void q_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = findpartition(arr, low, high);
        q_sort(arr, low, partition - 1);
        q_sort(arr, partition + 1, high);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    q_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
