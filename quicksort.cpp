#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    int partitionIndex(vector<int> &arr,int low,int high){
        int pivot = arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i]<= pivot && i<=high-1){
                i++;
            }
            while(arr[j]> pivot && j>=low+1){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    void qs(vector<int> &arr,int low,int high){
        if(low<high){
            int partition = partitionIndex(arr,low,high);
            qs(arr,partition+1,high);
            qs(arr,low,partition-1);
        }
    }
    vector<int> quickSort(vector<int>& arr) {
        qs(arr,0,arr.size()-1);
        return arr;
    }
};

int main() {

    vector<int> arr = {9, 3, 7, 1, 6, 2, 8};

    clock_t start = clock();   // start time

    Solution obj;
    obj.quickSort(arr);

    clock_t end = clock();     // end time

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    cout << "Time taken by Quick Sort: "
         << time_taken << " seconds" << endl;

    return 0;
}
