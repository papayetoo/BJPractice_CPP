////
////  11047.cpp
////  Cpp_practice
////
////  Created by 최광현 on 2020/01/05.
////  Copyright © 2020 최광현. All rights reserved.
////
//
//#include <iostream>
//#define MAXCOIN 10
//using namespace std;
//
//int solution(int arr[], int n, int price);
//
//int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    
//    int n, price;
//    cin >> n >> price;
//    
//    int coins[MAXCOIN];
//    for(int i = 0; i < n; i++){
//        cin >> coins[i];
//    }
//    
//    cout << solution(coins, n, price);
//
//    return 0;
//}
//
//int solution(int arr[], int n, int price){
//    
//    int ret = 0;
//    while(price > 0){
//        int seleted = 0;
//        for(int i = 0; i < n; i++){
//            if(arr[i] <= price)
//                seleted = max(seleted, arr[i]);
//        }
//        ret++;
//        price -= seleted;
//    }
//    
//    return ret;
//}
