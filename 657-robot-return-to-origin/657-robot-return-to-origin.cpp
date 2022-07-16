class Solution {
public:
    
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.length();i++)
        {
            if(moves[i] == 'U')
                x--;
            else if( moves[i] == 'D')
                x++;
            else if( moves[i] == 'L')
                y--;
            else 
                y++;
        }
        return (x==0 && y==0) ? 1:0;
    }
};