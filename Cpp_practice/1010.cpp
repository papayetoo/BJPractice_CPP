//
//  1010.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/03.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

unsigned long long combination(int west, int east);
void factorial();


unsigned long long fact[30];

int main(){
    
    int testcase; cin >> testcase;
    vector<unsigned long long> answers;
    factorial();
    
    for(int t = 0; t < testcase ; t++){
        int west, east;
        cin >> west >> east;
        answers.push_back(combination(west, east));
    }
    
    for(unsigned long long ans : answers){
        cout << ans << "\n";
    }
    
    return 0;
}

unsigned long long combination(int west, int east){
    // (east)C(west)
    if (!west || west == east)
        return 1;
    
    unsigned long long result = 1;
    if(east / 2 < west){
        return combination(east - west, east);
    }
    
    for(int i = east; i > east - west; i--){
        // 5C2 = 5 * 4 / fact(2)
        result *= i;
    }
    result /= fact[west];
    return result;
}

void factorial(){
    
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i = 2; i < 30; i++){
        fact[i] = i * fact[i - 1];
    }
        
}
