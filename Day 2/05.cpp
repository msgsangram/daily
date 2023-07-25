//Find the Missing and Repeating Number
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // find sn & s2n
        long long sn=(n*(n+1))/2;
        long long s2n=(n*(n+1)*(2*n+1))/6;
        
        //calculate s1 and s2
        long long s1=0, s2=0;
        
        for(int i=0; i<n; i++){
            s1+=arr[i];
            s2+=(long long)arr[i]*(long long)arr[i];
        }
        //s1-sn=x-y and s2-s2n (x^2-y^2)
        long long v1=s1-sn;
        long long v2=s2-s2n;
        
        //find x+y
        v2=v2/v1;
        //find x & y
        long long x = (v1+v2)/2;
        long long y= x-v1;
        return{(int)x,(int)y};
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
