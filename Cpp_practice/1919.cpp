//
//  1919.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#define ALPHA 26
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string firstWord, secondWord;
    cin >> firstWord >> secondWord;
    
    int firstAlpha[ALPHA];  fill(firstAlpha, firstAlpha + ALPHA, 0);
    for(int i = 0; i < firstWord.length(); i++)
        firstAlpha[ firstWord[i] - 'a']++;
    
    int secondAlpha[ALPHA]; fill(secondAlpha, secondAlpha + ALPHA, 0);
    for(int i = 0; i < secondWord.length(); i++)
        secondAlpha[ secondWord[i] - 'a']++;
    
    int anagram[ALPHA]; fill(anagram, anagram + ALPHA, 0);
    for(int i = 0; i < ALPHA; i++)
        anagram[i] = min(firstAlpha[i], secondAlpha[i]);
    
    int eraseCount = 0;
    for(int i = 0; i < ALPHA; i++){
        while ( firstAlpha[i] > anagram[i]){
            firstAlpha[i]--;
            eraseCount++;
        }
        
        while( secondAlpha[i] > anagram[i]){
            secondAlpha[i]--;
            eraseCount++;
        }
    }
    cout << eraseCount;
    
    return 0;
}
