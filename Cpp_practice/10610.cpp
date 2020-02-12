    //
    //  10610.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/02/10.
    //  Copyright © 2020 최광현. All rights reserved.
    //  30 백준 10610 문제 (그리디 알고리즘)

    #include <iostream>
    #include <string>

    using namespace std;

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        string str; cin >> str;
        int arr[10]; fill(begin(arr), end(arr), 0);
        long long sum = 0;
        
        for(auto iter = str.begin(); iter != str.end() ; iter ++){
            int intValue = *iter - '0';
            arr[intValue]++;
            sum += intValue;
        }
        
        if (sum % 3 != 0 || arr[0] == 0){
            cout << -1 ;
            return 0;
        }
        string result = "";
        for(int i = 9; i >= 0; i--) {
            while (arr[i] > 0) {
                result += to_string(i);
                arr[i]--;
            }
        }
        cout << result ;
        return 0;
    }
