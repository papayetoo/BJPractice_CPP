//
//  1213.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/18.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ALPHA 26

using namespace std;

void permutation(string& str, int depth, vector<string>& v){
    
    if(depth == str.length()){
//        cout << str << endl;
        v.push_back(str);
        return;
    }
    
    for(int i = depth; i < str.length(); i++){
        swap(str[i], str[depth]);
        permutation(str, depth + 1, v);
        swap(str[i], str[depth]);
    }
    
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
//    string rev;
//    do{
//        rev = "";
//        copy(str.rbegin(), str.rend(), back_inserter(rev));
//        if(!rev.compare(str)) {
//            cout << "Answer : " << rev << "\n";
//            break;
//        }
//    } while( next_permutation(str.begin(), str.end()));

    
    int alphaCount[ALPHA]; fill(alphaCount, alphaCount + ALPHA, 0);
    for(int i = 0; i < str.length(); i++){
        alphaCount[str[i] - 'A']++;
    }
    
    string result = "";
    long oddCount = count_if(alphaCount, alphaCount + ALPHA, [](int value){
        return value % 2 == 1;
    });
    
    if (oddCount > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    auto odd_iter = find_if(begin(alphaCount), end(alphaCount), [](int value){
        if(value > 0 && value % 2 == 1) return true;
        else return false;
    });
    
    for(int i = 0; i < ALPHA; i++){
        if(alphaCount[i]){
            string added(alphaCount[i]/2, i + 'A');
            result += added;
            
            if(alphaCount[i] % 2 == 0)
                alphaCount[i] /= 2;
            else{
                alphaCount[i] /= 2;
                alphaCount[i]++;
            }
        }
    }
    if(odd_iter != end(alphaCount)){
        int odd_index = distance(alphaCount, odd_iter);
        result += (char) (odd_index + 'A');
        alphaCount[odd_index]--;
    }
    for(int i = ALPHA - 1; i >= 0 ; i --){
        if(alphaCount[i]){
            string added(alphaCount[i], i + 'A');
            result += added;
            alphaCount[i] = 0;
        }
    }
    
    string rev(result.rbegin(), result.rend());
    cout << result ;
    
    return 0;
}
