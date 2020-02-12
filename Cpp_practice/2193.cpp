//
//  2193.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/03.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#define MAX 100
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long dp[MAX];
    fill(&dp[0], &dp[0] + MAX, 0);
    
    
    int n; cin >> n;
    // 자릿수 입력 받음.
    
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i <= 90; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    
    return 0;
}
