class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int element;

        for(int i=0; i<n; i++){
            if(cnt==0){
                element=nums[i];
                cnt=1;
            }
            else if(element==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0; i<n; i++){
            if(nums[i]==element) cnt1++;
        }
        if(cnt1>(n/2)) return element;
        return -1;
    
    }
       

};
