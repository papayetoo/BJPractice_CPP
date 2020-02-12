//
//  2804.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 26
#define MAXLENGTH 30
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string first, second;
    cin >> first >> second;

    char result[MAXLENGTH][MAXLENGTH]; fill(&result[0][0], &result[0][0] + MAXLENGTH * MAXLENGTH, '.');
    
    int firstIndex = 0;
    int printRow = 0;
    char sameChar;
    while(firstIndex < first.length()){
        auto iter = find(second.begin(), second.end(), first[firstIndex]);
        sameChar = *iter;
        if(iter != second.end()){
            printRow = distance(second.begin(), iter);
            break;
        }
        firstIndex++;
    }
    
    
    int secondIndex = 0;
    int printCol = 0;
    auto iter = find(first.begin(), first.end(), sameChar);
    printCol = distance(first.begin(), iter);
    
    for(int i = 0; i < second.length(); i++){
        result[i][printCol] = second[i];
    }
    
    for(int i = 0; i < first.length(); i++){
        result[printRow][i] = first[i];
    }
    
    for(int i = 0; i < second.length(); i++){
        for(int j = 0; j < first.length(); j++)
            cout << result[i][j];
        cout << "\n";
    }
        
    
    return 0;
}
