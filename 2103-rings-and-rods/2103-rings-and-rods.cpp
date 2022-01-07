class Solution {
public:
    int countPoints(string rings) 
    {
        int rods[10] = {};
        for (int i = 0; i < rings.size(); i += 2) 
        {
            int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
            rods[rings[i + 1] - '0'] |= color;
        }
        return count(begin(rods), end(rods), 7);
    }
};