//
//  7568.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/04.
//  Copyright © 2020 최광현. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#define MAX 50
//
//using namespace std;
//
//typedef struct BasicInfo{
//    int weight;
//    int height;
//}Info;
//
//int main(){
//    
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    
//    int n;
//    cin >> n;
//    
//    Info arr[MAX];
//    for(int i = 0; i < n; i++){
//        cin >> arr[i].weight >> arr[i].height;
//    }
//    
//    cout << "Test 2 \n";
//    cout << "what's the difference between commit and push?\n";
//    
//    for(int i = 0; i < n; i++){
//        int same = 0, bigger = 0, lower = 0;
//        int j = (i + 1) % n;
//        while(j% n != i){
//            if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
//                bigger++;
//            else if(arr[i].weight > arr[j].weight && arr[i].height > arr[j].height)
//                lower++;
//            else
//                same++;
//            j = (j + 1) % n;
//        }
//        cout << n - lower - same << " ";
//    }
//    
//    return 0;
//}
