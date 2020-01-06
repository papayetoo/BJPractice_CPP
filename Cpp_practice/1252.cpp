    //
    //  1252.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/01/06.
    //  Copyright © 2020 최광현. All rights reserved.
    //

#include <iostream>
#include <bitset>
#include <string>
#define MAX 83

using namespace std;

string solution(string longer, string shorter);

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a = "", b= "";
    for(int i = 0; i < 60; i++){
        a += "1";
        if(i%5 == 0)
            b += "0";
        else
            b += "1";
    }
    
    cout << a << " " << b << endl;
    
    cout << "My answer : ";
    if(a.length() >= b.length())
        cout << solution(a, b)<<"\n";
    else
        cout << solution(b, a)<<"\n";
    
    bitset<MAX> bitA(a);
    bitset<MAX> bitB(b);
    unsigned long long numA = bitA.to_ullong();
    unsigned long long numB = bitB.to_ullong();
    unsigned long long result = numA + numB;
    
    bitset<MAX> bitResult(result);
    cout << "Correct: ";
    if(!result)
        cout << 0 << "\n";
    else{
        int i = MAX - 1;
        while(!bitResult[i]){
            i--;
        }
        for(; i>=0;i--){
            cout << bitResult[i];
        }
        cout << "\n";
    }
    
    string resultStr = bitResult.to_string();
    return 0;
}

string solution(string longer, string shorter){
    
    string result = "";
    int carry = 0;
    
    size_t llength = longer.length();
    size_t slength = shorter.length();
    
    if(llength > slength){
        for(size_t j = 0; j < llength - slength; j++){
            shorter.insert(shorter.begin(), '0');
        }
    }
    
    for(int i = llength - 1; i >= 0; i--){
        
        if(longer[i] == '1' && shorter[i] == '1')
        {
            if(!carry)
            {
                result.insert(result.begin(), '0');
                carry  = 1;
            }
            else{
                result.insert(result.begin(), '1');
                carry = 1;
            }
        }else if(longer[i] == '1' && shorter[i] == '0'){
            if(!carry)
                result.insert(result.begin(), '1');
            else{
                result.insert(result.begin(), '0');
                carry = 1;
            }
        }else if(longer[i] == '0' && shorter[i] == '1'){
            if(!carry)
                result.insert(result.begin(), '1');
            else{
                result.insert(result.begin(), '0');
                carry = 1;
            }
        }else{
            if(!carry)
                result.insert(result.begin(), '0');
            else{
                result.insert(result.begin(), '1');
                carry = 0;
            }
        }
    }
    
    if(result.length() < 80 && carry)
        result.insert(result.begin(), '1');
    
    return result;
}
