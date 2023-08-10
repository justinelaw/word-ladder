#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "WordLadder.h"

WordLadder::WordLadder(const string &fileName) {
    ifstream inFS;
    string word;

    inFS.open(fileName);

    if (!inFS.is_open()){
        cout << "Could not open file" << endl;
        return;
    }

    while (inFS >> word) {
        if(word.length() == 5){
            dict.push_back(word);
        }
        else {
            cout << "More than 5 characters" << endl;
            return;
        }
    }

    inFS.close();

}


// void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
//     stack<string> userStack;
//     userStack.push(start);

//     queue<stack<string> > userQueue;
//     userQueue.push(userStack);

//     string compare = start;

//     //if start/end do not exist in dictionary output error and return
//     // if (isInDict(start,end)==false){
//     //     cout << "Does not exist in dictionary" << endl;
//     //     return;
//     // } 

//     while (!userQueue.empty()) {
//         ofstream outFS;
//         outFS.open(outputFile);

//         if (!outFS.is_open()) {
//             cout << "Output file did not open" << endl;
//             return;
//         }
        
//         outFS << start << endl;

//         for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
//             if (isOffByOne(userStack.top(), *iter) == true) {
//                 stack<string> newStack = userStack;
//                 // cout << newStack.top() << endl;
//                 newStack.push(*iter);

//                 // cout << "iter: " << *iter << endl;
//                 // cout << newStack.top() << endl;

//                 if(*iter == end) {
//                     outFS << end << endl;
//                     return;
//                 }
//                 outFS << newStack.top() << endl;
//                 userQueue.push(newStack);
//                 dict.remove(*iter);
//                 userStack = newStack;
//             }
//             userQueue.pop();
//         }
//         outFS.close();
//     }
// }

// bool WordLadder::isOffByOne(const string top, const string next) {
//     int charSame = 0;
//     string compare;

//     for (int i = 0; i < 5; ++i) {
//         compare = next;
//         if (top.at(i) == compare.at(i)) {
//             ++charSame;
//         }
//     }

//     if (charSame == 4) {
//         return true;
//     }

//     return false;
// }











void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    stack<string> userStack;
    userStack.push(start);

    queue<stack<string> > userQueue;
    userQueue.push(userStack);

    while (!userQueue.empty()) {
        for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
            if (isOffByOne(*iter, userQueue.front().top())) {
                if (*iter == end) {
                    ofstream outFS;
                    outFS.open(outputFile);
                    if (!outFS.is_open()) {
                        cout << "Could not open file" << endl;
                        return;
                    }
                    if (start == end) {
                        outFS << start << endl;
                        outFS.close();
                        return;
                    }
                    else {
                        while (!userStack.empty()){
                            outFS << userStack.top() << endl;
                            userStack.pop();
                        }

                        outFS.close();
                        return;
                    }
                }
                else {
                    stack<string> newStack = userStack;
                    userStack.push(*iter);
                    userQueue.push(newStack);
                    iter = dict.erase(iter);
                }
            }
        }

        userQueue.pop();
    }

    cout << "No word ladder exists for this word." << endl;
}

bool WordLadder::isOffByOne(const string top, const string next) {
    int charDiff = 0;

    for (int i = 0; i < 5; ++i) {
        if (top.at(i) != next.at(i)) {
            ++charDiff;
        }
    }

    if (charDiff <= 1) {
        return true;
    }

    return false;
}
