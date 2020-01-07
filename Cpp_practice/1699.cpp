////
////  1699.cpp
////  Cpp_practice
////
////  Created by 최광현 on 2020/01/06.
////  Copyright © 2020 최광현. All rights reserved.
////
//
//#include <iostream>
//#include <cmath>
//#include <climits>
//#define MAX 100001
//using namespace std;
//
//int solution(int n);
//
//int main(){
//    
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    
//    int n; cin >> n;
//    
//    cout << solution(n);
//}
//
//int solution(int n){
//    
//    int dp[MAX];
//    fill(dp, dp+MAX, 0);
//    
//    dp[1] = 1;
//    dp[2] = 2;
//    
//    for(int i = 3; i <= n; i++){
//        float rootVal = sqrt(i);
//        int fl = floor(rootVal); int temp = INT_MAX;
//        if(rootVal - fl != 0){
//            int square;
//            for(int j = 1 ;  j <= fl; j++){
//                square = j * j;
//                temp = min(temp, dp[square] + dp[i - square]);
//            }
//            dp[i] = temp;
//        }
//        else if(rootVal - fl == 0)
//            dp[i] = 1;
//    }
//    
//    return dp[n];
//}
