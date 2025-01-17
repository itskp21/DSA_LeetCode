class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        mainStack.push(val);
        minStack.push(std::min(val, minStack.top()));
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1;
    }
    
    int getMin() {
        return minStack.top();
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