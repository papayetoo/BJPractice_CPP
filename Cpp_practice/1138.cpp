//
//  1138.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/12.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#define MAX 10
using namespace std;

void solution(vector<int> heightList, int shorter[MAX]);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int shorter[MAX];
    fill(shorter, shorter + MAX, 0);
    
    vector<int> heightList;
    for(int i = 0; i < n; i++){
        cin >> shorter[i];
        heightList.emplace_back(i + 1);
    }
    
    solution(heightList, shorter);
    return 0;
}

void solution(vector<int> heightList, int shorter[MAX]){
    
    int size = heightList.size();
    do{
        int count = 0;
        for( int i = 0 ; i < size ; i++){
            int correct = shorter[i];
            int height = i + 1;
            //  키(height)는 1부터 시작하기 때문에 1을 더해준다.
            auto findIter = find(heightList.begin(), heightList.end(), height);
            // vector에서 값이 height인 iterator를 찾는다
            int longerCount = count_if(heightList.begin(), findIter, [=](int hValue){
                return hValue > height;
            });
            // vector에서 벡터의 처음과 위에서 찾은 반복자 사이에서 height 값보다 큰 것이 몇 개인지 센다.
            
            if (longerCount == correct) // 주어진 입력과 같다면 count를 증가시킨다.
                count++;
            else
                break;
        }
        
        if(count == size){
            // 입력으로 받은 것과 같다면 정답이므로 해당 순열의 리스트를 출력하고 종료한다.
            for(int e : heightList){
                cout << e << " ";
            }
            break;
        }
    } while (next_permutation(heightList.begin(), heightList.end()));
    
}
