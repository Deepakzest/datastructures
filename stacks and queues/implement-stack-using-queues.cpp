class MyStack {
public:
    queue<int> Q;

    MyStack() {}

    void push(int x) {
        Q.push(x);
        int n = Q.size();
        for(int i = 0; i < n - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }

    int pop() {
        int val = Q.front();
        Q.pop();
        return val;
    }

    int top() {
        return Q.front();
    }

    bool empty() {
        return Q.empty();
    }
};
