class TrieNode
{
public:
    TrieNode *child[2];
    
    TrieNode(){
        this->child[0] = NULL;
        this->child[1] = NULL;
    }   
};
class Solution 
{    
public:
    TrieNode *newNode;
    void insert(int x)
    {
        TrieNode *t = newNode;
        bitset<32> bs(x);   
        for(int j=31; j>=0; j--)
        {
            if(!t->child[bs[j]]) t->child[bs[j]] = new TrieNode();
            t = t->child[bs[j]];
        }    
    }
    int findMaximumXOR(vector<int>& nums) 
    {
        newNode = new TrieNode();
        for(auto &n : nums) insert(n);
        int ans=0;
        for(auto n : nums)
        {
            ans = max(ans, maxXOR(n));
        }
        return ans;
    }
    int maxXOR(int n)
    {
        TrieNode *t = newNode;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--)
        {
            if(t->child[!bs[j]]) ans += (1<<j), t = t->child[!bs[j]];
            else t = t->child[bs[j]];
        }
        return ans;
    }
};