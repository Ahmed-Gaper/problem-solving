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

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
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
};

class Solution {
public:
    string reverseWord(string line) {
        Stack stack(line.size());
        line += ' ';
        string reversedWord;

        for (char c : line) {
            if (c == ' ') {
                while (!stack.isEmpty()) {
                    reversedWord += stack.pop();
                }
                reversedWord += ' ';
            } else {
                stack.push(c);
            }
        }

        return reversedWord;
    }
};

int reverse(int num) {
    Stack stack(25);
    while (num) {
        stack.push(num % 10);
        num /= 10;
    }

    int reversedNum = 0;
    int tens = 1;
    while (!stack.isEmpty()) {
        reversedNum = stack.pop() * tens + reversedNum;
        tens *= 10;
    }

    return reversedNum;
}

int main() {
    cout << reverse(1234) << endl;

    return 0;
}
