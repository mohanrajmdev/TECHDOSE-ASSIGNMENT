class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int sum=nums[i]+nums[j];
                int left=j+1;
                int right=n-1;
                //---------------binary search
                while(left<=right){
                    vector<int>t;
                    int mid=left+(right-left)/2; //finding the mid element
                    //-----------answer found . so inserting it into array(vector)
                    if(sum+nums[mid]==0){
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[mid]);
                        res.push_back(t);
                        break;
                    }
                    //-----------------------------
                    if(nums[mid]+sum<0){ // current mid is not enough increasing the range
                        left=mid+1;
                    }
                    else{ // current mid is high . so searching among smallest range elements
                        right=mid-1;
                    }
                }
                //--------------------------------
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                } 
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};