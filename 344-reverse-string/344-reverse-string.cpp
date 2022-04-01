class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0,right=s.size();
        for(int i=left;i<right/2;i++)
            swap(s[i],s[s.size()-i-1]);
    }
};