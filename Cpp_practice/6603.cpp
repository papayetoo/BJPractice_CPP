////
////  6603.cpp
////  Cpp_practice
////
////  Created by 최광현 on 2020/01/07.
////  Copyright © 2020 최광현. All rights reserved.
////
////  Backtracking 관련 문제
//#include <iostream>
//#include <vector>
//#define MAX 13
//
//using namespace std;
//
//void combination(vector<int> input, int index, int r, int* visited);
//
//int main(){
//    
//    int n; cin >> n;
//    vector< vector<int> > cases;
//    while(n){
//        vector<int> input;
//        int temp;
//        for(int i = 0; i < n; i++){
//            cin >> temp;
//            input.push_back(temp);
//        }
//        cases.push_back(input);
//        
//        cin >> n;
//    }
//    
//    for(int i = 0; i < cases.size(); i++){
//        int visited[MAX];
//        fill(visited, visited + MAX, 0);
//        combination(cases[i], 0, 6, visited);
//        cout << "\n";
//    }
//    
//    return 0;
//}
//
//void combination(vector<int> input, int index, int r, int* visited){
//    
//    if(r == 0){
//        for(int i = 0; i < input.size(); i++){
//            if(visited[i])
//                cout << input[i] << " ";
//        }
//        cout << "\n";
//    }
//    
//    for(int i = index ; i < input.size(); i++){
//        visited[i] = 1;
//        combination(input, i + 1, r - 1,visited);
//        visited[i] = 0;
//    }
//}
