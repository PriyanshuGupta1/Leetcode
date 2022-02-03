class Solution {
public:
    //Approach 2 Using Binary Search
    //Time complexity: O(log(M*N))
    //Space Complexity : O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int totalElements=r*c-1;
        if(r==0)
            return false;
        int left=0,right=totalElements;
        int middleElement,middleIndex;
        while(left<=right)
        {
            middleIndex=(left+right)/2;
            middleElement=matrix[middleIndex/c][middleIndex%c];
            if(target==middleElement)
                return true;
            else
            {
                if(target<middleElement)
                    right=middleIndex-1;
                else
                    left=middleIndex+1;
            }
        }
        return false;
    }
             
};
//     //Approach 1 
//     Time Complexity: O(M+N) (where N is number of rows whereas M is no of coloumns)
//     Space Complexity : O(1)
//     bool searchMatrix(vector<vector<int>>& matrix, int target) 
//     {
//         int rowToSearch=-1;
//         for(int i=0;i<matrix.size();i++)    
//         {
//             rowToSearch=i;
//             if(matrix[i][0]>target)
//             {
//                 i--;
//                 rowToSearch=i; //trying to find a row head whose value is greater than the target
//                 break;
//             }
//             if(matrix[i][0]==target) //if its present in the head we will return the value as true i.e found
//                 return true;
//         }
//         if(rowToSearch<0)
//             return false;
//         for(int j=0;j<matrix[0].size();j++)
//         {
//             if(matrix[rowToSearch][j]==target)//the value is found in that row
//                 return true;
//         }
//         return false; //if the value is not found throughout
//     }
// };