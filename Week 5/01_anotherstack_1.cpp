#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
    int size;
    int* array;
    int added_elements;
public:
    Stack(int _size) {
        size = _size;
        array = new int[size];
        added_elements = 0;
    }

    bool push(int x) {
        if (isFull())
            return false;

        for (int i = added_elements; i > 0; --i)
            array[i] = array[i - 1];
        array[0] = x;
        ++added_elements;
        return true;
    }

    bool pop(int &result) {
        if (isEmpty())
            return false;
        result = array[0];
        for (int i = 0; i < added_elements - 1; ++i)
            array[i] = array[i + 1];
        --added_elements;
        return true;
    }

    int peek() {
        if (isEmpty())
            return -1; 
        return array[0];
    }

    bool isFull() {
        return added_elements == size;
    }

    bool isEmpty() {
        return added_elements == 0;
    }

    void display() {
        for (int i = 0; i < added_elements; ++i)
            cout << array[i] << " ";
        cout << "\n";
    }

    ~Stack() {
        delete[] array;
    }
};

int main() {
    Stack stk(3);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.display();

    cout << "Peek: " << stk.peek() << endl;

    int popped_element;
    if (stk.pop(popped_element)) {
        cout << "Popped Element: " << popped_element << endl;
    }
    else {
        cout << "Failed to pop an element. Stack is empty." << endl;
    }

    return 0;
}
