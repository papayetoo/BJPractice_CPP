
//  7568.cpp
//  Cpp_practice

//  Created by 최광현 on 2020/01/04.
//  Copyright © 2020 최광현. All rights reserved.


#include <iostream>
#include <algorithm>
#define MAX 50

using namespace std;

typedef struct BasicInfo{
   int weight;
   int height;
}Info;

int main(){
   
   cin.tie(0);
   ios::sync_with_stdio(false);
   
   int n;
   cin >> n;
   
   Info arr[MAX];
   for(int i = 0; i < n; i++){
       cin >> arr[i].weight >> arr[i].height;
   }
   
   for(int i = 0; i < n; i++){
       int same = 0, bigger = 0, lower = 0;
       int j = (i + 1) % n;
       while(j% n != i){
          //arr[i]를 보다 큰 arr[j]를 만나면 bigger++
           if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
               bigger++;
          //arr[i]보다 weight과 height 모두 작을 때 lower++
           else if(arr[i].weight > arr[j].weight && arr[i].height > arr[j].height)
               lower++;
           else
               same++;
           j = (j + 1) % n;
       }
      //등수 계산은 전체 n에서 작거나 같은 것을 빼면 출력 가능.
       cout << n - lower - same << " ";
   }
   
   return 0;
}
