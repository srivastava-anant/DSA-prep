class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        // Constructor must be closed here
    }
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();   
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    } // ✅ Push function closed once here
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

