class Solution {
public:
    int furthestBuilding(vector<int>& A, int bricks, int ladders) {
        multiset<int> s;
        for (int i = 0; i < A.size() - 1; i++) {
            int d = A[i + 1] - A[i];
            if (d > 0)
                s.insert(A[i + 1] - A[i]);
            if (s.size() > ladders) {
                bricks -= *s.begin();
                s.erase(s.begin());
                if (bricks < 0) return i;
            }
        }
        return A.size() - 1;
    }
};