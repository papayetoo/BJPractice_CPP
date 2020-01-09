//
//  1918.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/09.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int comingEval(char c);
int stackEval(char c);
void printToken(stack<char>& stc);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str; getline(cin, str);
    
    stack<char> stc;
    for(int i = 0; i < str.length() ; i++){
        char c = str[i];
        if(isalpha(c))
            cout << c;
        else{
            if(stc.empty()) stc.push(c);
            else{
                if(c != ')'){
                    int cEval = comingEval(c);
                    int stcEval = stackEval(stc.top());
                    while(cEval <= stcEval){
                        printToken(stc);
                        if(stc.empty()) break;
                        stcEval = stackEval(stc.top());
                    }
                    stc.push(c);
                }else{//rparen이 나왔을 때
                    while(stc.top() != '('){
                        printToken(stc);
                    }
                    stc.pop();
                    //lparen을 비우기 위해 한 번 더 pop
                }
            }
        }
    }
    
    while(!stc.empty()){
        printToken(stc);
    }

    return 0;
}

int comingEval(char c){
    
    if(c == '+' || c == '-')
        return 1;
    else if( c == '*' || c == '/')
        return 2;
    else if( c == '(')
        return 3;
    else
        return 4;
}

int stackEval(char c){
    
    if(c == '+' || c == '-')
        return 1;
    else if( c == '*' || c == '/')
        return 2;
    else if( c == '(')
        return -1;
    else // rparen 이 있을 때
        return 4;
}

void printToken(stack<char>& stc){
    
    if(stc.empty())
        return;
    
    char top = stc.top();
    if(top != ')' && top != '(')
        cout << top ;
    stc.pop();
}
