//https://leetcode.com/problems/next-greater-element-i/
/* The next greater element of some element x in an array is the first greater element that is to the right of x in the 
same array.You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater 
element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        int n = nums2.size();
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--){ //starting from right because of pre processing needed to be done
            int curr = nums2[i];
            
            //nextsmallerelement does not have -1 condition because notinfg was smaller than -1 and here every eelement 
            //is greater than -1 hence 
            //for second condition convert to hindi and frame the logic
            while(s.top()!=-1 && curr >= s.top()){   //jisko chota rakhna hai usko >= ke right me
                s.pop();
            }
            mp[curr] = s.top();   //storing the biggest element
            s.push(curr);
        }
        
        int m = nums1.size();
        vector<int> ans(m);
        
        for(int i=0; i<m; i++){
            int temp = nums1[i];
            if(mp.find(temp) != mp.end())   //finding if element present
            {
                int element = mp[temp];
                //cout<<element<<endl;
                ans[i] = element;                         //pushing it to answer 
            }
        }
        return ans;
    }
};