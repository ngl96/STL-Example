// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void task9(const list<int>& lst) {
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) { cout << *iter << ' '; }
    cout << endl;
}

void task10(const list<int>& lst) {
    for (int elem : lst) {
        cout << elem << ' ';
    }
    cout << endl;
}

void task11(const list<int>& lst) {
    for (auto iter = lst.begin(); iter != lst.end(); ++++iter) { cout << *iter << ' '; }
    cout << endl;
}

list<int>::const_iterator task12(const list<int>& lst, int item){
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == item) { return iter; }
    }
    return lst.end();
}

auto task13(const list<int>& lst, int item){
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter == item) { return iter; }
    }
    return lst.end();
}

bool isEven(int num){ return num % 2 == 0; }

class IsEvenFunctor {
public:
    bool operator()(int num){ return num % 2 == 0; }
};

template <class T,class U>
T ourFind(T start,T stop, U item){
//    cout << "ourFind Function:" << endl;
    for (T iter = start; iter != stop; iter ++) {
        if (*iter == item) { return iter; }
    }
    return stop;
}

bool inVec(const vector<string>& vec, string word) {
    for (string elem : vec) {
        if (elem == word) { return true; }
    }
    return false;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec{3,1,30,45,12,8};
    for (int elem : vec) { cout << elem << ' '; }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> li(vec.begin(),vec.end());
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(),vec.end());
    for (int elem : vec) { cout << elem << ' '; }
    cout << endl;
    for (int elem : li) { cout << elem << ' '; }
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (int i = 0; i < vec.size(); i+=2) { cout << vec[i] << ' '; }
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    //for (int i = 0; i < list.size(); i+=2) { cout << vec[i] << ' '; }
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); i+=2) { cout << *i << ' '; }
    // When using iterators, it gives you the values, not an index to put into the vector.
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator i = li.begin(); i != li.end(); ++++i) { cout << *i << ' '; }
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    li.sort();
    for (list<int>::iterator i = li.begin(); i != li.end(); ++i) { cout << *i << ' '; }
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    task9(li);
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    task10(li);
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    task11(li);
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << *(task12(li, 8)) << endl;
    cout << *(task12(li, 234)) << endl;
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << *(task13(li, 8)) << endl;
    cout << *(task13(li, 234)) << endl;
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << *(find(li.begin(),li.end(), 8)) << endl;
    cout << *(find(li.begin(),li.end(), 23)) << endl;
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    cout << *(find_if(li.begin(),li.end(),isEven)) << endl;
    cout << *(find_if(vec.begin(),vec.end(),isEven)) << endl;
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    IsEvenFunctor f;
    cout << *(find_if(li.begin(),li.end(),f)) << endl;
    cout << *(find_if(vec.begin(),vec.end(),f)) << endl;
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello" << endl; } ();
    cout << *(find_if(li.begin(),li.end(),[] (int num) { return num % 2 == 0; } )) << endl;
    cout << *(find_if(vec.begin(),vec.end(),[] (int num) { return num % 2 == 0; } )) << endl;

    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[6];
    copy(li.begin(),li.end(),arr);
    for (int elem : arr) { cout << elem << ' '; }
    cout << endl;
    
    cout << *(find(arr,arr+6, 8)) << endl;
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    cout << *(ourFind(li.begin(),li.end(),8)) << endl;
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    cout << *(ourFind(vec.begin(),vec.end(),8)) << endl;
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> vec2;
    ifstream ifs;
    ifs.open("pooh-nopunc.txt");
    string word;
    while (ifs >> word){
        if (ourFind(vec2.begin(),vec2.end(),word) == vec2.end()) { vec2.push_back(word); }
    }
    ifs.close();
    for (string elem : vec2) { cout << elem << ' ';}
    cout << endl;
    cout << vec2.size();
    cout << endl;
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> set;
    ifstream ifs2;
    ifs2.open("pooh-nopunc.txt");
    string word2;
    while (ifs2 >> word2){
        set.insert(word2);
    }
    ifs2.close();
//    for (string elem : set) { cout << elem << ' '; }
//    cout << endl;
//    cout << set.size();
//    cout << endl;
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    ifstream ifs3;
    ifs3.open("pooh-nopunc.txt");
    string word3;
    int count = 0;
    while (ifs3 >> word3){
        wordMap[word3].push_back(count);
        ++count;
    }
    ifs3.close();
    
    for (auto it : wordMap) {
        cout << "Key: " << it.first << " Indicies: ";
        for (int item : it.second) { cout << item << ' '; }
    }
    cout << endl;
    cout << "=======\n";
}
