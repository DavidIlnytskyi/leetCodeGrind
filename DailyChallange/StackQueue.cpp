/*
 https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29
 */
class MyQueue {
private:
    stack<int> popStack;
    stack<int> pushStack;
public:
    MyQueue() {

    }

    void push(int x) {
        pushStack.push(x);
    }

    int pop() {
        if(!popStack.empty()){
            int ret = popStack.top();
            popStack.pop();
            return ret;

        } else if (!pushStack.empty()){
            while(!pushStack.empty()){
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            int ret = popStack.top();
            popStack.pop();
            return ret;
        }
        return -1;
    }

    int peek() {
        if (!popStack.empty()) {
            return popStack.top();
        } else if (!pushStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            if (!popStack.empty()) {
                return popStack.top();
            }
        }
        // Handle the case when both stacks are empty
        return -1;
    }


    bool empty() {
        return popStack.empty() && pushStack.empty();
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