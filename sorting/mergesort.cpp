#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high){
  int n1 = mid-low+1;
  int n2 = high - mid;
  int arr1[n1], arr2[n2];

  //Copying the elememts in tow halfs before merging them
  for(int i=0;i<n1;i++){
    arr1[i] = arr[low+i];
  }
  for(int i=0;i<n2;i++){
    arr2[i] = arr[mid+1+i];
  }

  //merging two halfs in the main Array
  int i=0;
  int j=0;
  int k=low;
  while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
      arr[k++]=arr1[i++];
    }
    else{
      arr[k++]=arr2[j++];
    }
  }
  while(i<n1){
    arr[k++]=arr1[i++];
  }
  while(j<n2){
    arr[k++]=arr2[j++];
  }
}
void mergeSort(int arr[], int low, int high){
  if(low == high){
    return;
  }
  int mid = (low+high)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1,high);
  merge(arr, low, mid, high);
}
void printArr(int arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Array before soring: ";
  printArr(arr,n);
  mergeSort(arr,0,n-1);
  cout<<"Array after sorting: ";
  printArr(arr,n);
  return 0;
}
