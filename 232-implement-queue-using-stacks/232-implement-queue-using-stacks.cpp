class MyQueue {
private:
    stack <int> st1,st2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int top=st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    int peek() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int top;
        if(!st2.empty())
            top=st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    bool empty() {
        if(st1.empty()==true)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// queue 1 2 3 4
// stack follows LIFO
// queue Follows FIFO
// stack-1 1 2 3 4->top
// stack-2 4 3 2->top
// stack-1 2 3 4 5 6
