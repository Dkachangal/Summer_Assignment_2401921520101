#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << minStack.getMin() << endl; 
    
    minStack.pop();
    
    cout << minStack.top() << endl;    
    cout << minStack.getMin() << endl; 

    return 0;
}