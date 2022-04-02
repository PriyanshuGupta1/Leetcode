class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])   
                return (isPallindrome(s,i,j-1)|| isPallindrome(s,i+1,j));
            i++;j--;
        }
        return true;
    }
    bool isPallindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])   
                return false;
            i++;j--;
        }
        return true;
    }
};