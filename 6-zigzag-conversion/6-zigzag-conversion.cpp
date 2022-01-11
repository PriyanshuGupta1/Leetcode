class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector <string> rows(min(numRows,int(s.size())));
        int row=0;
        bool down=0;
        if(numRows==1)
            return s;
        for(auto c:s)
        {
            rows[row]+=c;
            if(row==0 || row==numRows-1)
                down=!down;
             row+=down?1:-1;
        }
        string t;
        for(auto row:rows)
            t+=row;
        return t;
    }
};