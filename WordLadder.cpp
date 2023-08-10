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
//     ofstream outFS;
//     outFS.open(outputFile);

//     if (!outFS.is_open()) {
//         cout << "Output file did not open" << endl;
//         return;
//     }

// //    while (!userQueue.empty()) {
// //         outFS << start << endl;

// //         for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
// //             if (isOffByOne(userStack.top(), *iter) == true) {
// //                 stack<string> newStack = userStack;
// //                 // cout << newStack.top() << endl;
// //                 newStack.push(*iter);

// //                 // cout << "iter: " << *iter << endl;
// //                 // cout << newStack.top() << endl;

// //                 if(*iter == end) {
// //                     outFS << end << endl;
// //                     return;
// //                 }
// //                 else {
// //                     outFS << newStack.top() << endl;
// //                     userQueue.push(newStack);
// //                     dict.remove(*iter);
// //                     userStack = newStack;
// //                 }
// //             }
// //             userQueue.pop();
// //         }
// //     }
// //     outFS.close();
// // }

// // bool WordLadder::isOffByOne(const string top, const string next) {
// //     int charSame = 0;
// //     string compare;

// //     for (int i = 0; i < 5; ++i) {
// //         compare = next;
// //         if (top.at(i) == compare.at(i)) {
// //             ++charSame;
// //         }
// //     }

//     if (charSame == 4) {
//         return true;
//     }

//     return false;
// }

// void WordLadder::PrintLadder() {
//     for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
//         cout << *iter << " " << endl;
//     }
// }

// bool WordLadder::isInDict(const string start, const string end){
//     for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter){
//         if (start == *iter){
//             for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter){
                
//             }
//         }
//     }
// }
// string WordLadder::getDictWord(int wordLoc) {
//     string word = dict.begin();

//     for (int i = 0; i <= wordLoc; ++i) {
//         if (i == wordLoc) {
//             return word;
//         }
//         ++dict;
//     }
// }

// void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
//     stack<string> stack1;
//     stack1.push(start);

//     queue<stack<T>> queue1;
//     queue1.enqueue(stack1);

//     string word;

//     while (!queue1.empty()) {
//         word = start;
        
//         for (list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter){
//             string top = stack1.top();
//             if (isOffByOne(top, *iter){
//                 stack<string> newStack = stack1;
//                 newStack.push(*iter);
//                 if (getDictWord != end)){
//                     queue1.enqueue(newStack);
//                     dict.remove(getDictWord(i));
//                 }
//             }
//             queue1.dequeue();
//             stack1 = newStack;
//         }
//     }
// }


void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    stack<string> userStack;
    userStack.push(start);

    queue<stack<string> > userQueue;
    userQueue.push(userStack);

    while (!userQueue.empty()) {
        for (list<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
            if (isOffByOne(*i, userQueue.front().top())) {
                if (*i == end) {
                    ofstream outFS;
                    outFS.open(outputFile);
                    if (!outFS.is_open()) {
                        cout << "Could not open file" << endl;
                        return;
                    }
                    if (start == end) {
                        outFS << start << endl;
                        return;
                    }
                    else {
                        stack<string> output, tempS;
                        tempS = userQueue.front();
                        while (!tempS.empty()) {
                            output.push(tempS.top());
                            tempS.pop();
                        }
                        while (!output.empty()) {
                            outFS << output.top() << " ";
                            output.pop();
                        }

                        outFS << *i << endl;

                        outFS.close();
                        return;
                    }
                }
                else {
                    stack<string> temp = userQueue.front();
                    temp.push(*i);
                    userQueue.push(temp);
                    i = dict.erase(i);
                }
            }
        }

        userQueue.pop();
    }

    ofstream outFS;
    outFS.open(outputFile);
    if(!outFS.is_open()) {
        cout << "Failed to open output file" << endl;
        return;
    }

    outFS << "No Word Ladder Found." << endl;

    outFS.close();
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
