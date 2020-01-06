//
//  1068.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/05.
//  Copyright © 2020 최광현. All rights reserved.
//
//
//#include <iostream>
//#define MAX 50
//using namespace std;
//
//struct Node{
//    int parent;
//    int child_count = 0;
//};
//
//void change(Node* node, int size, int delNum);
//
//int main(){
//
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n; cin >> n;
//
//    Node node[MAX];
//
//    for(int i =0; i < n; i++){
//        cin >> node[i].parent;
//    }
//    for(int i = 0; i < n; i++){
//        if(node[i].parent != -1)
//            node[node[i].parent].child_count++;
//    }
//
//    int delNum; cin >> delNum;
//    change(node, n, delNum);
//
//    int count = 0;
//    for(int i = 0; i < n; i++){
//        if(node[i].parent != -2 && node[i].child_count == 0)
//            count++;
//    }
//    cout << count << endl;
//
//}
//
//void change(Node* node, int size, int delNum){
//
//
//    node[node[delNum].parent].child_count--;
//    node[delNum].parent = -2;
//    for(int i = 0; i < size; i++){
//        if(node[i].parent == delNum)
//            change(node, size, i);
//    }
//
//}
