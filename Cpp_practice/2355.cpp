//
//  2355.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/16.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b; cin >> a >> b;
    long smaller = min(a,b);
    long bigger = max(a,b);
    long dist = bigger - smaller + 1;
    long result = dist * (smaller + bigger) / 2;
    cout << result;
    
    return 0;
}
