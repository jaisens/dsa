class Solution {
public:
    int binarysearch(vector<int>& nums, int target, string s){
        
        int left = 0;
        int right = nums.size() - 1;
        
        int ans = -1;
        while(left<=right){
            
            int mid = left + (right - left)/2;
            
            if(nums[mid] == target){
                // store the last value occurance of the target and go left or right till the lowest 
                // index for the element is found
                ans = mid;
                //for checking if it is first occurrence or last

                if(s == "first"){
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //implementing both index search at the same time
        return {binarysearch(nums,target,"first"),binarysearch(nums,target,"second")};
    }