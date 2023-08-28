class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            int fr = q.front();
            q.pop();
            q.push(fr);
        }
    }
    
    int pop() {
        int fr = q.front();
        q.pop();
        return fr;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
