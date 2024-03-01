#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Stack {
private:
    int* arr = nullptr;
    int size;
    int top = -1;

public:
    Stack(int val) {
        size = val;
        arr = new int[size];
    }

    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void push(int val) {
        assert(!isFull());
        arr[++top] = val;
    }

    int pop() {
        assert(!isEmpty());
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
};

int score(string& str) {
    Stack st(str.length());
    st.push(0);

    for (char c : str) {
        if (c == '(') {
            st.push(0);
        } else {
            int last = st.peek();
            st.pop();

            int score = (last == 0) ? 1 : 2 * last;    

            int parent_score = st.peek() + score;
            st.pop();
            st.push(parent_score);
        }
    }
    return st.peek();
}

int main() {
    string str = "(()(()))(()(()))";
    Stack st(str.length());
    assert(!st.isFull());

    cout << "Final Score: " << score(str) << endl;
    
    return 0;
}
