class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>0)
        {
            while(n>1)
            {
                if(n%3!=0)
                    return false;
                n=n/3;
            }    
        }
        else
            return false;
        return true;
    }
};