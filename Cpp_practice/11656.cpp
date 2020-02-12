//
//  11656.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str; cin >> str;
    set<string> postfix;
    postfix.insert(str);
    for(int i = 1; i < str.length(); i++){
        string sub(str.begin() + i, str.end());
        postfix.insert(sub);
    }
    
    for(auto iter = postfix.begin(); iter != postfix.end(); ++iter){
        cout << *iter << "\n";
    }
    return 0;
}
