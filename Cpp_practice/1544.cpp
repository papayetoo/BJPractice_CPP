//
//  1544.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//  싸이클 단어

#include <iostream>
#include <string>
#include <memory>
#include <set>
using namespace std;

void makeCycleWords(string str, set<string>& cycleSet);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    unique_ptr<string []> words(new string[n]);
    set<string> cycleSet;
    //  단어 입력 받음.
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(cycleSet.find(words[i]) == cycleSet.end()){
            makeCycleWords(words[i], cycleSet);
            count++;
        }
    }
    cout << count;
    
    return 0;
}

void makeCycleWords(string str, set<string>& cycleSet){
    
    cycleSet.insert(str);
    for(int i = 1; i < str.length(); i++){
        string newPre(str.begin() + i, str.end());
        string newPos(str.begin(), str.begin() + i);
        cycleSet.insert(newPre+newPos);
    }
    
}
