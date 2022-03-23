class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps=0;
        while(target>startValue)
        {
            if(target%2==0)
                target/=2;
            else
                target++;
            steps++;
        }
        return steps+startValue-target;
    }
};