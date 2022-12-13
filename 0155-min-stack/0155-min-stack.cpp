class MinStack {
    private:
    multiset<int> min_st;
    stack<int> pop_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        pop_st.push(val);
        min_st.insert(val);
    }
    
    void pop() {

        min_st.erase(min_st.find(pop_st.top()));
       pop_st.pop();
            
    }
    
    int top() {
        return pop_st.top();
    }
    
    int getMin() {
        
        auto x=*min_st.begin();
        return x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */