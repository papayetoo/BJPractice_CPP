//
//  2747.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/20.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#define MAX 46
using namespace std;

int fibonacci(const int num){
    int fib[MAX];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    
    for(int i = 3; i < MAX; i++){
        fib[i] = fib[i - 1 ] + fib[i - 2];
    }
    
    return fib[num];
}

int main(){
    int num; cin >> num;
    cout << fibonacci(num);
    return 0;
}
