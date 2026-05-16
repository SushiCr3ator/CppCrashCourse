#include <iostream>

//Standard Library Template STLs
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <set>
#include <map>

#include "hashingExample.h"

//Filehandling & Hashing in an external class

//create one for iterator using list as well since its the best example i have with help of erase()
using namespace std;
//open class Queue to have details explanation for class & List for "private" example
/*HINT! syntax for class is as follows:
 * class Name { public: ... };
 * dont forget the ';' at the end!!!
 */
class Queue {// class organizes code withing a file
public: // makes everything under this accessible to this/ other file to use
        // alternatively "private: " only allows the class itself to have access to whats under it

    void createQueue(queue<int> &q) {// initializes the first instance of queue to exist
        q.push(21);
        q.push(33);
        q.push(477);
        q.push(5);
        q.push(1);
    }
    void emptyQueue(queue<int> &q) {// empty() is used for statements to check if the queue is empty
        q.empty() ? cout << "queue is not empty!" << endl : cout << "queue is empty!" << endl;
    }
    void playQueue() {// you can play around this function too to try out the other ways for Queue
        queue<int> q;
        createQueue(q);
        int max = q.size()-1;   // can be replaced with just using empty() but used size() as example
        for (int i = 0; i <= max; i++) {
            cout << q.front() << endl;
            q.pop();
        }
        emptyQueue(q);
        q.pop();
        emptyQueue(q);
    }

};
class Deque {
public:
    void createDeque(deque<int> &d) { // should return {322, 2, 12, 4, 55}
        d.push_back(12);
        d.push_front(2);
        d.push_front(322);
        d.push_back(4);
        d.push_back(55);
    }
    void playDeque() {
        deque<int> d;
        createDeque(d);
        int max = d.size()-1;
        for (int i = 0; i <= max; i++) {
            cout << d[i] << endl;   // deque has random access so u can just search or edit with position '[pos]'
        }
        while (!d.empty()) {// checks if deque is empty
            d.pop_front();  // this can also work the otherway with pop_back()
            cout << "after deletion: " << endl;
            for (int i = 0; i <= d.size(); i++) {
                cout << d[i] << endl;
            }
        }
    }
};
class Vector {
public:
    void createVector(vector<int> &v) { // {6,1,2,7,3,8,4,5}
        v.push_back(1); //theres NO push_front for vector!!!
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        //alternative ways to insert
        v.insert(v.begin(), 6); // another way to insert something into vector
        v.insert(v.begin()+3, 7); // u can also add elements in between using begin() + n
        v.insert(v.end()-2, 8); // or end()- n
    }
    void playVector() {
        vector<int> v;
        createVector(v);
        int max = v.size()-1;
        for (int i = 0; i <= max; i++) {
            cout << v[i] << endl;   // like prior STLs u can use front()/ back() if need be OR alternatively '.at(pos)'
        }
        while (!v.empty()) {
            v.pop_back();   // NO pop_front()!!! Alternatively u can use .clear() to delete everything
            cout << "after deletion: " << endl;
            for (int i = 0; i <= v.size(); i++) {
                cout << v[i] << endl;
            }
        }
    }
};
class List {
private:    // as seen in this example only class list has access for the variable size
    int size;   //which also means that u can use the same variable name for other classes without worrying about it calling this
public:
    void createList(list<int> &l) {
        for (int i = 1; i <= size; i++) {
            l.push_back(i);
        }
    }
    void playList() {
        list<int> l;
        cout << "please give a valid maximum size for list\n";
        cin >> size;
        createList(l);
        cout << l.size() << endl;
        while (!l.empty()) {
            cout << l.front() << endl;
            l.pop_front();
        }
    }
};
class Set {
private:
    int size;
    int num = 5;
    set<int> s;
public:
    void createSet(set<int> &s) { // unlike other STLs this is used to sort and delete all duplicates
        s.insert(5);
        s.insert(1);
        s.insert(4);
        s.insert(2);
        s.insert(3);
        s.insert(6);
        s.insert(6);
    }
    void playSet() {// doesnt actually work yet will look into tis in the future
        const bool is_in = s.contains(num);
        (is_in) ? cout << "there is an instance of " << num << endl: cout << "there is NOT an instance of " << num << endl;
    }
};
class Map {
private:
    map<int, string> m;
public:
    void createMap(map<int, string> &m) {
        m.insert(make_pair(1, "one"));
        m.insert(make_pair(2, "two"));
        m.insert(make_pair(3, "three"));
        m.insert(make_pair(4, "four"));
        m.insert(make_pair(5, "five"));
        m.insert(make_pair(6, "six"));
        m.insert(make_pair(7, "seven"));
    }
    void playMap() {
        createMap(m);
        int max = m.size()-1;
        for (int i = 0; i <= max; i++) {
            cout << m[i] << endl;   // uses key <int> to return element <string>
        }
    }
};


int main() {
    Queue q;
    Deque d;
    Vector v;
    List l;
    Set s;
    Map m;
    HashingExample he;
    he.hashedPassword();
    return 0;
}