#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void ApplymergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;

        ApplymergeSort(arr, low, mid);
        ApplymergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    vector<int> mergeSort(vector<int> &arr) {
        ApplymergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};

int main() {
    vector<int> arr = {9, 3, 7, 1, 6, 2, 8};

    clock_t start = clock();

    Solution s;
    s.mergeSort(arr);

    clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Time taken by Merge Sort: " 
         << time_taken << " seconds" << endl;

    return 0;
}
