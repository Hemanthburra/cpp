#include<bits/stdc++.h>
using namespace std;


void selection_sort(int arr[],int n){ // selection sort time complexity O(N^2)
// finds the minimum in the array and swap with the ith element --> selection sort
    for (int i = 0 ; i <= n-2 ; i++){
        int mini = i;
        for (int j = i ; j <= n-1 ; j++){
            if (arr[j] < arr[mini]){
                mini = j;           // storing the index of the minimum element in the array
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;       // swapping the elements ith index and the minimum element index in the array
    }
}
 
void bubble_sort(int arr[],int n){ // bubble sort best TC:O(N)-->sorted already worst TC(N^2)
// push's the maximum element to the last by adjacent swaps
    for (int i = n-1 ; i >=0 ; i--){
        for (int j = 0 ; j < i  ; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        for (int i = 0 ; i < n ; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void insertion_sort(int arr[],int n){ // insertion sort best TC:O(N)-->sorted already worst TC:O(N^2)
// places the element in the correct place by swapping the current element with the before elements
    for (int i = 0 ; i < n ; i++){
        int j = i;
        while (j>0 and arr[j-1] > arr[j]){ // backtracks the array current element with the before elements the array
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

// merge sort sub function
void combine(vector<int>&arr,int low,int mid,int high){ // this funstion sorts the 2 parts and replace the elements in the original array
    vector<int>vpp;
    int left = low;
    int right = mid+1;
    while (left <= mid && right<= high){
        if (arr[left] < arr[right]){
            vpp.push_back(arr[left]);
            left++;
        }
        else{
            vpp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid){
        vpp.push_back(arr[left]);
        left++;
    }
    while (right <= high){
        vpp.push_back(arr[right]);
        right++;
    }
    for (int i = low ; i <= high ; i++){
        arr[i] = vpp[i-low];
    }
}
void merge_sort(vector<int>&arr,int low,int high){ // this function divides the array into parts
    if (low == high) return;
    int mid = (low+high)/2;
    // cout<<low<<" "<<mid<<" "<<high<<"merge"<<endl;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    combine(arr,low,mid,high);
}

int pivot(vector<int> &arr , int low , int high){ // quick_sort sub function
    int pivot_int = arr[low];
    int i = low , j = high;
    while ( i < j){
        while (arr[i] <= pivot_int && i <= high) i++; // finds the first greater element than pivot_int from first
        while (arr[j] > pivot_int && j >= low) j--; // finds the first lesser element that pivot_int from last
        if (i < j) swap(arr[i],arr[j]);     // by the finding the greater and lesser elements swap them
    }
    swap(arr[low],arr[j]);      // last position of the j is the position of the pivot_int
    return j;           // return the partition index to the quick_sort
    
}
void quick_sort(vector<int>&arr,int low,int high){ // TC : O(N*log N) SC:O(N)
    if (low < high){ // if low == high that means it is the single element in the array which is already sorted 
        int partition = pivot(arr,low,high);
        quick_sort(arr,low,partition-1); // divide the arr from to low 
        // to partition-1 bcz the partition index is already in correct place no need to change the partition index
        quick_sort(arr,partition+1,high); // divides the arr from partition+1 to high
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int>arr;
    for (int i = 0 ; i < n ; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    // insertion_sort(arr,n);
    quick_sort(arr,0,n-1);
    for (int i = 0 ; i < n ; i++) cout<<arr[i]<<" ";
    return 0;
}
