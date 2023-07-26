
#include <bits/stdc++.h>
using namespace std;


long long merge(long long* arr, int low, int mid, int high){
    int cnt=0;
    int left=low;
    int right=mid+1;
    vector<int> ans;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            ans.push_back(arr[left]);
            left++;
        }else{
            ans.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        ans.push_back(arr[left]);
        left++;
    }
     while(right<=high){
        ans.push_back(arr[right]);
        right++;
    }
     for (int i = low; i <= high; i++) {
        arr[i] = ans[i - low];
    }
    return cnt;
}

long long mergeSort(long long* arr, int low, int high) {
  int cnt = 0;
  int mid = (low + high) / 2;
  if (low == high)
    return cnt;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid + 1, high);
  cnt += merge(arr, low, mid, high);
  return cnt;
}

long long getInversions( long long *arr, int n) {
  return {mergeSort(arr, 0, n - 1)};
}
