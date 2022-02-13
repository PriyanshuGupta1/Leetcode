/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int top = topRight[0], right = topRight[1], bottom = bottomLeft[0], left = bottomLeft[1];
        if(left > right || bottom > top) return 0;
        int res = sea.hasShips(topRight, bottomLeft);
        if((top == bottom && left == right) || res == 0) return res;
        return countShips(sea,  {top, (left + right)/2}, {(bottom + top)/2+1, left} ) + 
			countShips(sea,  {top, right}, {(bottom + top)/2 + 1, (left +right) / 2 + 1} ) +
			countShips(sea,  {(top + bottom)/2, (left+right)/2}, {bottom, left } ) + 
			countShips(sea,  {(top + bottom)/2, right}, {bottom, (left+right)/2 + 1 }  );
    }
};