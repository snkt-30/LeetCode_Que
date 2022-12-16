class MyQueue {
    private:
    stack<int> main,helper;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
        main.push(x);
    }
    
    int pop() {
        int ans=0;
        while(!main.empty())
        {
            int x=main.top();
            main.pop();
            helper.push(x);
        }
        ans=helper.top();
        helper.pop();
        while(!helper.empty())
        {
            int x=helper.top();
            helper.pop();
            main.push(x);
        }
        return ans;
    }
    
    int peek() {
        int ans=0;
        while(!main.empty())
        {
            int x=main.top();
            main.pop();
            helper.push(x);
        }
        ans=helper.top();
        while(!helper.empty())
        {
            int x=helper.top();
            helper.pop();
            main.push(x);
        }
        return ans;
    }
    
    bool empty() {
        
        return main.empty();
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