////
////  11053.cpp
////  Cpp_practice
////
////  Created by 최광현 on 2020/02/03.
////  Copyright © 2020 최광현. All rights reserved.
////
//
//#include <iostream>
//#include <memory>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    
//    int arrSize; cin >> arrSize;
//    unique_ptr<int []> arr(new int [arrSize]);
//    for(int i = 0; i < arrSize ; i++)
//        cin >> arr[i];
//    
//    unique_ptr<int []> dp(new int [arrSize]);
//    fill(dp.get(), dp.get() + arrSize, 0);
//    dp[0] = 1;
//    
//    for(int i = 1; i < arrSize ; i++){
//        
//        int dpMax = 0;
////        for(int j = 0; j < i ; j++){
////
////            if(dpMax < dp[j] && arr[i] > arr[j]){
////                dpMax = dp[j];
////            }
////
////        }
//        int j = i - 1;
//        while ( j >= 0 ){
//            if(arr[i] < arr[j]){
//                dp[i] = dp[j];
//                break;
//            }
//            j--;
//        }
//        
//        if(!j)
//            dp[i] = 1;
//    }
//   
//    for(int i = 0; i < arrSize ; i++)
//        cout << dp[i] << " ";
//    cout << "\n";
//    
////    int answer = *max_element(dp.get(), dp.get() + arrSize);
////    cout << answer;
//    
//    return 0;
//}
