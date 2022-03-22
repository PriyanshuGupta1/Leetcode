class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector <bool> visited(arr.size(),false);
        queue <int> q;
        q.push(start);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            // cout<<i<<" ";
            if(arr[i]==0)
                return true;
            if(!visited[i])
            {
                visited[i]=true;
                if(i+arr[i]<arr.size())
                    q.push(i+arr[i]);
                if(i-arr[i]>=0)
                    q.push(i-arr[i]);
            }
        }
        return false;
    }
    
};