/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector <vector <int>> mat(m,vector <int> (n,-1));
        int currI=0,currJ=n;
        int startingRow=0,startingColoumn=0,endingRow=m-1,endingColoumn=n-1;
        cout<<head->val;
        while(true && startingRow<=endingRow && startingColoumn<=endingColoumn)
        {
            
            for(int j=startingColoumn;j<=endingColoumn;j++)
            {
                if(head!=NULL)
                {
                    mat[startingRow][j]=head->val;
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            for(int i=startingRow+1;i<=endingRow;i++)
            {
                if(head!=NULL)
                {
                    mat[i][endingColoumn]=head->val;
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            for(int j=endingColoumn-1;j>=startingColoumn;j--)
            {
                if(head!=NULL)
                {
                    mat[endingRow][j]=head->val;
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            for(int i=endingRow-1;i>=startingRow+1;i--)
            {
                if(head!=NULL)
                {
                    mat[i][startingColoumn]=head->val;
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            startingRow++;
            startingColoumn++;
            endingRow--;
            endingColoumn--;
        }
        return mat;
    }
};
// 3
// 5
// [3,0,2,6,8,1,7,9,4,2,5,5,0]
// 1
// 4
// [0,1,2]
// 8
// 7
// [405,341,910,645,954,915,447,924,263,350,472,1,481,972,807,970,898,525,318,620,21,922,231,192,659,976,153,130,273,997,889,488,528,832,768,444,894,682,116,569,305,112,259,810,898,831,675,165,224,367,959,783,477,974]