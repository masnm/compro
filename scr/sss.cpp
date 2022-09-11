#include<bits/stdc++.h>

using namespace std;
 
int insertion_sort ( int arr[], int n )
{
	int ret = 0;
	for(int i=0;i<n;i++){
		int sortElement=arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				swap(arr[i],arr[j]);
			}
		}
		ret = sortElement;
	}
	return ret;
}
 
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
 
	int ans = insertion_sort(arr,n);
	cout << "Ans : " << ans << endl;
 
 
 
	return 0;
}
