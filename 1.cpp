#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX_SIZE = 100; 

class Stack {
  private:
    int arr[MAX_SIZE]; 
    int top; 
  public:
    Stack() {
      top = -1; 
    }

    bool push(int x) {
      if (top == MAX_SIZE - 1) {
        cout << "Error: stack overflow\n";
        return false;
      } else {
        top++;
        arr[top] = x;
        cout << x << " pushed to stack\n";
        return true;
      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Error: stack underflow\n";
        return 0;
      } else {
        int x = arr[top];
        top--;
        return x;
      }
    }

    bool isEmpty() {
      return (top == -1);
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return arr[top];
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        for (int i = top; i >= 0; i--) {
          cout << arr[i] << " ";
        }
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack stack;
  stack.push(8);
  stack.push(10);
  stack.push(5);
  stack.push(11);
  stack.push(15);
  stack.push(23);
  stack.push(6);
  stack.push(18);
  stack.push(20);
  stack.push(17);
  stack.Display();
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  stack.Display();
  stack.push(4);
  stack.push(30);
  stack.push(3);
  stack.push(1);
  stack.Display();    
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<microseconds>(end_time - start_time);
  cout << "Execution time: " << execution_time.count() << " us" << endl;
  return 0;
}
