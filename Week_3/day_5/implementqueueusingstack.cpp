#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

    void move() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        move();
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        move();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl; // 1
    cout << "Pop: " << q.pop() << endl;    // 1
    cout << "Front: " << q.peek() << endl; // 2

    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}