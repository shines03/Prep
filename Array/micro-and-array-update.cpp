#include<bits/stdc++.h>
using namespace std;
int microAndArrayUpdate(int arr[], int n, int k){
	int mini = arr[0];
	for(int i=1;i<n;i++)
		mini = min(arr[i],mini);
	return max(0,k-mini);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<microAndArrayUpdate(arr,n,k)<<endl;
	}
	return 0;
}
