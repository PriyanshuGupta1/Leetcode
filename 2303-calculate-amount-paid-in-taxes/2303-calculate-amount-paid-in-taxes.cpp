class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax=0;
        for(int i=0;i<brackets.size();i++)
        {
            int m=0;
            if(i>0) 
                m=brackets[i][0]-brackets[i-1][0];
            else
                m=brackets[i][0];
            if(income>=brackets[i][0])    
                tax+=m/100.0*brackets[i][1]*100.0/100.0;
            else
            {
                if(i>0) 
                     m=income-brackets[i-1][0];
                else
                     m=income;
                tax+=m/100.0*brackets[i][1]*100.0/100.0;
                break;
            }
        }
        return tax;
    }
};