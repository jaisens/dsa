class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index){
        if(index >= days.size())
            return 0;
        
        //1 day ticket
        // index +1 directly because the current day is already covered
        // index+1 is correct because on a particular day ticket for that day can be brought
        // and hence can index can be increased
        int option1 = costs[0] + solve(days,costs,index+1);

        //7 day ticket
        int i;
        // index has constant value increase i till the 7 days are reached days[index] + 7 is used
        // is days[i] 
        for(i = index; i<days.size() && days[i] < days[index] + 7; i++);
        
        //if 7 day ticket is chosen then the index reached is sent to recursive
        int option2 = costs[1] + solve(days,costs,i);

        //30 day ticket
        for(i = index; i<days.size() && days[i] < days[index]+30; i++);

        int option3 = costs[2] + solve(days,costs,i);

        int ans = min(option1,min(option2,option3));
        return ans;
    }
    int solvemem(vector<int>& days, vector<int>& costs,int index,vector<int>& dp){
        if(index >= days.size())
            return 0;
        
        if(dp[index] != -1) return dp[index];

        //1 day ticket
        int option1 = costs[0] + solvemem(days,costs,index+1,dp);

        //7 day ticket
        int i;
        for(i = index; i<days.size() && days[i] < days[index] + 7; i++);
        
        //if 7 day ticket is chosen then the index reached is sent to recursive
        int option2 = costs[1] + solvemem(days,costs,i,dp);

        //30 day ticket
        for(i = index; i<days.size() && days[i] < days[index]+30; i++);

        int option3 = costs[2] + solvemem(days,costs,i,dp);

        dp[index] = min(option1,min(option2,option3));
        return dp[index];
    }
    int solvetab(vector<int>& days, vector<int>& costs,int index){
        vector<int> dp(days.size()+1,INT_MAX);

        dp[days.size()] = 0;

        for(int k=days.size()-1; k>=0; k--){
            int option1 = costs[0] + dp[k+1];

            //7 day ticket
            int i;
            for(i = k; i<days.size() && days[i] < days[k] + 7; i++);
            
            //if 7 day ticket is chosen then the index reached is sent to recursive
            int option2 = costs[1] + dp[i];

            //30 day ticket
            for(i = k; i<days.size() && days[i] < days[k]+30; i++);

            int option3 = costs[2] + dp[i];

            dp[k] = min(option1,min(option2,option3));
        }

        return dp[0];

    }
    int spaceoptimization(vector<int>& days, vector<int>& costs) {
        
        //not int_max because cost of day will be added
        int ans = 0;

        queue<pair<int,int>> week;  //<day,cost>
        queue<pair<int,int>> month;

        for(auto day :  days){
            
            //case if we reach a day after buying a weekly ticket like we bought the ticket at 2nd 
            //day then we can remove all the days before 9
            //difference between days is not constant i.e 1 
            //while loop is before push so it evaluating the prev element

            while(week.size() > 0 && week.front().first + 7 <= day ){
                week.pop();
            }

            while(month.size() > 0 && month.front().first + 30 <= day){
                month.pop();
            }

            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));

            ans = min(ans+costs[0], min(week.front().second, month.front().second));

            //taking example of weekly 
            //the fist element stays till 7 + first elemt doest not come and that is front 
            // and it remains front till the 7 th day from first elemet does not come
            //and value of the first element is checked for any day in ans min
            //when 7th day comes all other elements are removed and the next element becomes the top 
            //and from their the costs are checked
            
        }

        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solve(days,costs,0);
        // vector<int> dp(days.size()+1,-1);
        // return solvemem(days,costs,0,dp);
        return solvetab(days,costs,0);
    }
};