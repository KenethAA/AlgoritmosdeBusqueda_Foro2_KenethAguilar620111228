#include <bits/stdc++.h>
using namespace std;

//AlgoritmoBusquedaBinaria
int binarySearch(int arr[], int lo, int hi, int x)
{
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

int main(void)
{
    int n = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 8;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        cout << "Element not found !!";
    }
    else cout << "Element found at index " << result;
    return 0;
}

//AlgoritmoBusquedaLineal
vector<int> search(int arr[], int n, int x) {
    vector<int>ans;
    // Traverse the array sequentially
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n = 9;
    int arr[] = {2, 4, 0, 1, 9, 2, 1, 2, 1};
    int x = 1;
    vector<int> res = search(arr, n, x);
    if (res.empty()) {
        cout << "Element not found!!";
    }
    else {
        cout << "Element found at ";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
}

//AlgoritmoBusquedaExponencial
int binarySearch(int arr[], int lo, int hi, int x)
{
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return binarySearch(arr, i / 2,
                        min(i, n - 1), x);
}

int main()
{
    int n = 11;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int x = 10;
    int result = exponentialSearch(arr, n, x);
    if (result == -1) {
        cout << "Element not found !!";
    }
    else cout << "Element found at index " << result;
    return 0;
}

//AlgoritmoporInterpolación
int interpolation_search(int arr[], int n, int X)
{
    int lo = 0;
    int hi = n - 1;
    int mid;

    while ((arr[hi] != arr[lo]) && (X >= arr[lo]) && (X <= arr[hi])) {
        mid = lo + ((X - arr[lo]) * (hi - lo) / (arr[hi] - arr[lo]));

        if (arr[mid] < X)
            lo = mid + 1;
        else if (X < arr[mid])
            hi = mid - 1;
        else
            return mid;
    }

    if (X == arr[lo])
        return lo ;
    else
        return -1;
}

int main(void)
{
    int n = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int result = interpolation_search(arr, n, x);
    if (result == -1) {
        cout << "Element not found !!";
    }
    else cout << "Element found at index " << result;
    return 0;
}
