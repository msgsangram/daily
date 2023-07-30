class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;

        for(int i=0; i<n; i++){
         
         if(cnt1==0 && el2!=v[i]){
             cnt1++;
             el1=v[i];  
         }
         else if(cnt2==0 && el1!=v[i]){
             cnt2++;
             el2=v[i];
         }else if(el2==v[i]){
             cnt2++;
         }
         else if(el1==v[i]){
             cnt1++;
         }else{
             cnt1--;
             cnt2--;
         }

        }
        vector<int> ls;
        int c1=0, c2=0;
        for(int i=0; i<n; i++){
            if(el1==v[i]) c1++;
            if(el2==v[i]) c2++;
        }
        if(c1>(n/3)) ls.push_back(el1);
        if(c2>(n/3)) ls.push_back(el2);
        return ls;
    }
};
