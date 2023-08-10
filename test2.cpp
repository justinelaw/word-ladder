#include <iostream>
#include <list>
#include <stack>
//template<class T>
#include <queue>


using namespace std;

int main(){
    list<int> myList;
    //cout << *myList.begin();
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);

    queue<stack> myQueue;
    myQueue.push(myStack);

    cout << myQueue.front();

    return 0;
}