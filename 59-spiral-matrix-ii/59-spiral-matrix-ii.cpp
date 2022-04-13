class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector <int> > v(n,vector <int> (n,0));
        int num=0, starting_row=0,ending_row=n-1,starting_coloumn=0,ending_coloumn=n-1,flag=0;
        while(n*n>num)
        {
            for(int i=starting_row;i<=ending_row && flag==0;i++)
            {
                if(i==starting_row)
                {
                    for(int j=starting_coloumn;j<=ending_coloumn;j++)
                    {
                        num++;
                        v[i][j]=num;
                        if(num==n*n)
                            flag=1;
                    }    
                }
                if(i!=starting_row && i!=ending_coloumn && flag==0)
                {
                    num++;
                    v[i][ending_coloumn]=num;
                    if(num==n*n)
                            flag=1;
                }
                if(i==ending_row)
                {
                    for(int j=ending_coloumn;j>=starting_coloumn && flag==0;j--)
                    {
                        num++;
                        v[i][j]=num;
                        if(num==n*n)
                            flag=1;
                    }
                }
            }    
            for(int i=ending_row-1;i>starting_row && flag==0;i--)
            {
                num++;
                v[i][starting_coloumn]=num;
                if(num==n*n)
                    flag=1;
            }
            starting_row++;
            ending_row--;
            ending_coloumn--;
            starting_coloumn++;
        }
        return v;
    }
};