//
// Created by gold1 on 14.05.2026.
//

#ifndef CPPCRASHCOURSE_HASHINGEXAMPLE_H
#define CPPCRASHCOURSE_HASHINGEXAMPLE_H
#include <fstream>
#include <iostream>
#include <map>

#include "./assets/hashing.h"

using namespace std;
class HashingExample {
    private:
        string givenPass,lineBuffer;
        map<string, string> hashTable;
        string occurrence,passName;
    public:
    void updateMap() {
        ifstream File("../assets/hibp-min-10000000-count.txt");  // opens file
        if (!File.is_open()) {  // checks if file is really open
            cout<<"Error opening file"<<endl;
            return;
        }

        while (getline(File,lineBuffer) ) { // gets line from File
            passName = lineBuffer.substr(0, 40);    // set first 40 letters to passName
            occurrence = lineBuffer.substr(41, lineBuffer.size());  // and the rest in occurrence
            hashTable[passName] = occurrence;   // put it into a map
        }
        cout << "Database loaded successfully into map!" << endl;
        File.close();
    }
    string checkPass(string pass) {
        string hashedPass = sha1_hex_upper(pass);   // hashes the given password
        auto it = hashTable.find(hashedPass);   // makes an itterator
        if (it != hashTable.end()) {    // checks till the end of table for the given hashed Password
            string ans = it->second;    // another way to say it.second
            return ans + " occurrences found";  // adds an extra string to the original
        }
        return "No entry/occurrence found";
    }
    void hashedPassword() {
        updateMap();
        cout << "Please give a password you want to check: "<< endl;
        cin >> givenPass;
        cout << "Given hashed Password is: " << sha1_hex_upper(givenPass)<< endl;
        cout << "There is "<< checkPass(givenPass) << " for the password: " << givenPass << endl;
    }
};


#endif //CPPCRASHCOURSE_HASHINGEXAMPLE_H
