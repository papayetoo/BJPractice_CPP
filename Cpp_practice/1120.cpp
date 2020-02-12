//
//  1120.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/12.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#define MAX 50
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    size_t aLength = a.length();
    size_t bLength = b.length();
    
    if(aLength == bLength){
        int whenSameLength = 0;
        for(int i = 0; i < aLength; i++){
            if (a[i] != b[i])
                whenSameLength++;
        }
        cout << whenSameLength;
        return 0;
    }
    
    vector<int> diffVec;
    int diff;
    for(int i = 0; i < bLength - aLength + 1; i++){
        diff = 0;
        for(int j = 0; j < aLength; j++){
            if(a[j] != b[i+j]) diff++;
        }
        diffVec.emplace_back(diff);
    }
    cout << *min_element(diffVec.begin(), diffVec.end());
    
    return 0;
}

