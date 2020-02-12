//
//  12015.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/04.
//  Copyright © 2020 최광현. All rights reserved.
//  가장 긴 증가하는 수열(LIS) 알고리즘

#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

struct LIS{
    int length;
    int max;
};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int numOfInput; cin >> numOfInput;
    
    int input[MAX];
    for(int i = 0; i < numOfInput; i++)
        cin >> input[i];
    
    vector<int> lisVec;
    lisVec.push_back(input[0]);
    int answer = 1;
    for(int i = 1; i < numOfInput; i++){
        
        if(lisVec.back() < input[i]){
            lisVec.push_back(input[i]);
            answer++;
        }else{
            auto iter = lower_bound(lisVec.begin(), lisVec.end(), input[i]);
            //lower_bound 함수는 value 값보다 작지 않은 iterator를 반환함.
            // vector : 2 4, input : 1 이면
            // 처음 2의 위치를 반환함.
            *iter = input[i];
        }
    }
    
    for(int e : lisVec)
        cout << e << " ";
    cout << "\n";
    
    cout << answer ;
    
    
    return 0;
}
