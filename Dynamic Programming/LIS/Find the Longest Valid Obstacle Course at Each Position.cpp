class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();

        vector<int> ans(n,1), lis;
        // lis = at each index (i+1) length of lis present with list[i] as last element of that subsequence 
        // so we find the element index by upperbound because we want to put the element after the prev smaller element 
        // so use upperbound for obstacles[i] and put it in right place so that the elements of lis remain smallest 
        // the lis may not be the correct order but length will be correct

        for(int i=0; i<n; i++){
            int idxtoinsert = upper_bound(lis.begin(),lis.end(),obstacles[i]) - lis.begin();

            if(idxtoinsert == lis.size()){
                lis.push_back(obstacles[i]);
            }
            else{
                lis[idxtoinsert] = obstacles[i];
            }
            ans[i] = idxtoinsert+1;
        }

        return ans;
    }
};

// make a lis array
// find where the element can be put in this lis array using binary serach upperbound
// if the index is at last then push back 
// else put it in that position and size till that position that is idxtoinsert+1 is the size
