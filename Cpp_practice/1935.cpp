//
//  1935.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/09.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <stack>
#define MAX 26
using namespace std;

void eval(stack<double>& stc, char op);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int alpha[MAX]; fill(alpha, alpha + MAX, 0);
    int num; cin >> num;
    string str; cin >> str;
    for(int i = 0; i < num ; i++){
        cin >> alpha[i];
    }
    
    stack<double> stc;
    for(int i = 0; i < str.length() ; i++){
        if(isalpha(str[i]))
            stc.push(alpha[ str[i] - 'A' ]);
        else{
            eval(stc, str[i]);
        }
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    double result = stc.top();
    stc.pop();
    cout << result ;
    
    return 0;
}

void eval(stack<double>& stc, char op){
    double result = 0;
    double b = stc.top(); stc.pop();
    double a = stc.top(); stc.pop();
    if(op == '+')
        result = a + b;
    else if(op == '-')
        result = a - b;
    else if(op == '*')
        result = a * b;
    else if(op == '/')
        result = a / b;
    stc.push(result);
}
