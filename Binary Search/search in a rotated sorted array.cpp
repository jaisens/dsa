//for finding the pivot element
int pivot(vector<int>& nums, int n){
    int s=0, e=n-1;
    int mid = s + (e-s)/2;

    //s<e and not s<=e because s=e is not needed to be checked
    while(s<e){
        if(nums[mid]>=nums[0]){ //this checks if it belongs in the first ascending series
            s = mid + 1;
        }
        else{ // this one is for the second one
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s; // s = e at the end of the loop
}
int binarysearch(vector<int> nums, int s, int e, int target){
    int mid = s +(e-s)/2;
    
    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid] > target){
            e = mid - 1;
            
        }
        else {
            s = mid +1;
        }
        mid = s + (e-s)/2;
        
    }
    return -1;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0, e=n-1;
        int p=pivot(nums, n);
        
        //checking which part does the target belong to so to make right binarysearch 
        if( target >= nums[p] && target <= nums[n-1]){
            
            return binarysearch(nums,p,e,target);
        }
        else {
            return binarysearch(nums , s , p-1, target );
        }
        
    }
};