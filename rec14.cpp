//  Created by Nathanael Leyton on 12/13/18.
//  rec14


#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};
void listDisplay(const Node* headPtr){
    const Node* p = headPtr;
    while ( p != nullptr ) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
void listAddHead(Node*& headPtr, int data) { headPtr = new Node(data,headPtr); }

// Q1
bool evenBinary(int n) {
    if (n == 1) { return false; }
    if (n == 0) { return true; }
    bool isEven = evenBinary(n / 2);
    if (n % 2 == 0) {return isEven;}
    else {return !isEven;}
}
// Q2
Node* sumLists(Node* headPtr1, Node* headPtr2) {
    if (headPtr1 == nullptr && headPtr2 != nullptr) {
        return new Node((headPtr2->data),sumLists(nullptr,headPtr2->next));
    }
    if (headPtr2 == nullptr && headPtr1 != nullptr) {
        return new Node((headPtr1->data),sumLists(headPtr1->next,nullptr));
    }
    if (headPtr1 == nullptr && headPtr2 == nullptr) return nullptr;
    return new Node((headPtr1->data + headPtr2->data),sumLists(headPtr1->next,headPtr2->next));
}
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};
// Q3
int max(TNode* root) {
    if (root == nullptr) {
        return -1;
    }
    int maxL = max(root->left);
    int maxR = max(root->right);
    if (maxL >= maxR && maxL >= root->data) {return maxL;}
    if (maxR >= maxL && maxR >= root->data) {return maxR;}
    return root->data;
}
// Q4
bool palindrome(char arr[] , int size) {
    if (size >= 1) {return true;}
    if (arr[0] == arr[size - 1]) { return palindrome(arr + 1,size - 2);}
    else {return false;}
}
// Q5
int towers(int size,char start ,char target,char spare) {
    if (size == 1) { return 1; }
    int moves = towers(size - 1,start ,spare ,target);
    ++moves;
    moves += towers(size - 1,spare,target,start);
    return moves;
}
//Q6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}
             
int main() {
    cout << evenBinary(5) << endl;
    cout << evenBinary(3) << endl;
    cout << evenBinary(7) << endl;
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    listAddHead(list1, 5);
    listAddHead(list1, 3);
    listAddHead(list1, 1);
    listAddHead(list2, 2);
    listAddHead(list2, 7);
    Node* list3 = sumLists(list1,list2);
    listDisplay(list1);
    listDisplay(list2);
    listDisplay(list3);
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << max(&f) << endl;
    
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    cout << towers(1, 'a', 'b', 'c') << endl;
    cout << towers(2, 'a', 'b', 'c') << endl;
    cout << towers(3, 'a', 'b', 'c') << endl;
    cout << towers(4, 'a', 'b', 'c') << endl;
    cout << towers(5, 'a', 'b', 'c') << endl;
    cout << towers(6, 'a', 'b', 'c') << endl;
    cout << towers(7, 'a', 'b', 'c') << endl;
    cout << towers(8, 'a', 'b', 'c') << endl;
    cout << towers(9, 'a', 'b', 'c') << endl;
    cout << towers(10, 'a', 'b', 'c') << endl;
    
    mystery(2);
}





