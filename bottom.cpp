
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st, int count, int size,int ele) {
    // Base case
    if (st.empty()) {
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();

    // Recursive call
    solve(st, count + 1, size,ele);
    
    st.push(num);
}

void insertbottom(stack<int>& st, int N,int ele) {
    int count = 0;
    solve(st, count, N, ele );
}

void printStack(stack<int>& st) {
    stack<int> tempStack;

    // Copy elements to temporary stack while printing
    while (!st.empty()) {
        int element = st.top();
        st.pop();
        cout << element << " ";
        tempStack.push(element);
    }

    cout << endl;

    // Restore elements to the original stack
    while (!tempStack.empty()) {
        int element = tempStack.top();
        tempStack.pop();
        st.push(element);
    }
}

int main() {
    stack<int> st;
    
    int ele =40;

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(29);
    st.push(36);

   
    
    int N = st.size();

     cout << "Stack elements: ";

    printStack(st);


    insertbottom(st, N, ele);
     cout << "Stack elements after inserting  element at bottom : ";

    printStack(st);

    return 0;
}
