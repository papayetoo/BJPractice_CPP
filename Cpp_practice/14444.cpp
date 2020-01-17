//    //
//    //  14444.cpp
//    //  Cpp_practice
//    //
//    //  Created by 최광현 on 2020/01/11.
//    //  Copyright © 2020 최광현. All rights reserved.
//    //
//
//    #include <iostream>
//    #include <string>
//    #include <algorithm>
//    #define MAXLENGTH 100000 * 2
//    using namespace std;
//
//    void manacher(string str, int arr[]);
//
//    int main(){
//        ios_base::sync_with_stdio(false);
//        cin.tie(0);
//
//        string str; cin >> str;
//        string buffer;
//        for(auto iter = str.begin(); iter != str.end(); ++iter){
//            buffer.append("#");
//            buffer += *iter;
//        }
//        buffer.append("#");
//        
//        int a[MAXLENGTH];
//        manacher(buffer, a);
//       
//        int ans = -1;
//        auto iter = max_element(a, a + buffer.length());
//        int idx = distance(&a[0], iter);
//        cout << *iter << endl;
//    //    for(int k = idx - a[idx]; k <= idx + a[idx] ; k++){
//    //        if(buffer[k] != '#') cout << buffer[k];
//    //    }
//    //    for(int i = 0; i < buffer.length();i++)
//    //        ans = max(ans, a[i]);
//        
//        
//        return 0;
//    }
//
//    void manacher(string str, int arr[]){
//        
//        int r = 0, p = 0;
//        for(int i = 0; i < str.length(); i++){
//            
//            if(i <= r){
//                arr[i] = min(r - i, arr[2 * p - i]);
//            }else
//                arr[i] = 0;
//            
//            while( i - arr[i] - 1 >= 0 && i + arr[i] + 1 < str.length() && str[i - arr[i] - 1] == str[i + arr[i] + 1])
//                arr[i]++;
//            
//            if(r < i + arr[i]){
//                r = i + arr[i];
//                p = i;
//            }
//        }
//    }
