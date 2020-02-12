//
//  2079.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/18.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;

bool isPalindrome(string& str, int start, int end){

    int move = 0;
    while(1){
        if(str[start + move] != str[end - move])    return false;
        move++;
        if( start + move >= end - move)
            break;
    }
    
    return true;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
    vector<string> result;
    
    unique_ptr<int []> dp(new int[str.length()]);
    for(int i = 0; i < str.length(); i++){
        if(isPalindrome(str, 0, i)){
            dp[i] = 1;
            continue;
        }else{
            
            int minimalno = 0;
            for(int j = 0; j < i; j++){
                if(isPalindrome(str, j + 1, i) && (!minimalno || dp[j] < minimalno))
                    minimalno = dp[j];
            }
            
            dp[i] = minimalno + 1;
        }
    }
    
    cout << dp[str.length() -1];
    
    return 0;
}
