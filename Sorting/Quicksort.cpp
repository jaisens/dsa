#include <bits/stdc++.h> 
int partition(vector<int>& arr, int s, int e){

    // do not use 0th element
    int pivot = arr[s];

    // count of elements smaller than pivot
    int count=0;

    // start from s+1;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotindex = s + count;
    swap(arr[s],arr[s+count]);

    int i=s, j=e;

    while(i < pivotindex && j > pivotindex){
        // put equal to here
        while(arr[i] <= arr[pivotindex]){
            i++;
        }
        while(arr[j] >  arr[pivotindex]){
            j--;
        }

        if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotindex;
}
void solve(vector<int>& arr, int s, int e){

    if(s >= e)
        return;

    int p = partition(arr,s,e);
    solve(arr,s,p-1);
    solve(arr,p+1,e);
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    solve(arr,0,arr.size()-1);
    return arr;
}
