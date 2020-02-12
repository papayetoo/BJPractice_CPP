//
//  2941.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
    
    int index = 0;
    int wordCount = 0;
    while(index < str.length()){
        
        if( index + 1 < str.length() && (!str.substr(index, 2).compare("c-") || !str.substr(index, 2).compare("c=")))
        {
            index += 2;
            wordCount++;
            continue;
        }
        
        else if( index + 2 < str.length() && (!str.substr(index, 3).compare("dz=")))
        {
            index += 3;
            wordCount++;
            continue;
        }
        
        else if( index + 1 < str.length() && (!str.substr(index, 2).compare("d-"))){
            index += 2;
            wordCount++;
            continue;
        }
        
        else if( index + 1 < str.length() && (!str.substr(index, 2).compare("lj"))){
            index += 2;
            wordCount++;
            continue;
        }
        
        else if( index + 1 < str.length() && (!str.substr(index, 2).compare("nj"))){
            index += 2;
            wordCount++;
            continue;
        }
        
        else if( index + 1 < str.length() && (!str.substr(index, 2).compare("s="))){
            index += 2;
            wordCount++;
            continue;
        }
        
        else if( index + 1 < str.length() && (!str.substr(index, 2).compare("z="))){
            index += 2;
            wordCount++;
            continue;
        }
        else{
            index ++;
            wordCount++;
        }
    }
    
    cout << wordCount ;
    
    return 0;
}
