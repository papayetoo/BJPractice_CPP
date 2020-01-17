//
//  11724.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/16.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Node{
    int conneted;
    Node* next = NULL;
};


void dfs(Node** nodes, int* visited, int current){
    //Node 구조체를 이용해 구현한 dfs
    Node* currentHead = nodes[current]->next;
    //nodes[current]는 헤드 부분이기 때문에 connected의 값이 저장되지 않음.
    //그래서 currentHead 부분을 nodes[current]->next로 옮김.
    
    while(currentHead){
        //currentHead가 NULL이 아닌 동안
        if(!visited[currentHead->conneted]){
            //아직 방문하지 않은 다른 노드가 있다면
            //visted를 1로 설정하고, 그 노드에 대해서 dfs 실행
            visited[currentHead->conneted] = 1;
            dfs(nodes, visited, currentHead->conneted);
        }
        //인접리스트에서 다른 노드로 계속 진행.
        currentHead = currentHead -> next;
    }
    
}

void dfs(vector< vector<int> >& adjList, int* visited, int current){
    //벡터를 이용한 인접리스트의 구현.
    //adjList[i]는 i번 node에 인접한 노드들을 벡터로 저장하고 있음을 의미.
    vector<int> curVec = adjList[current];
    for(int i = 0; i < curVec.size(); i++){
        if(!visited[curVec[i]]){
            // adjList[current]에 인접한 노드 중 curVec[i]
            // visited[curVec[i]]는 0인 노드에 대해서
            // visited[curVec[i]]를 1로 설정하고 dfs를 실행.
            visited[curVec[i]] = 1;
            dfs(adjList, visited, curVec[i]);
        }
    }
         
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector< vector<int> > adjList(n + 1);
    //벡터로 인접리스트 구현. 단 인덱스를 1부터 사용하기 위해 n + 1 크기의 벡터 선언.

    Node** nodes = new Node*[n + 1];
    for(int i = 1; i <= n ; i++)
        nodes[i] = new Node;
    //Node 구조체 인접리스트 구현.
    
    
    int* visited = new int[n + 1];
    fill(visited + 1, visited + n + 1, 0);
    //visited 배열의 초기화.
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        //무방향 그래프 이므로 양쪽으로 연결되 있음을 표시
        Node* vNode = new Node;
        vNode->conneted = v;

        Node* uNode = new Node;
        uNode->conneted = u;

        Node* uCur = nodes[u];
        Node* vCur = nodes[v];

        //새로운 노드를 추가할 때 맨 뒤에 추가하면 오류가 발생
        //맨 앞에 추가하도록 하면 시간 초과 오류 발생하지 않음.
        //이는 문제의 제약 조건에서 연결요소를 찾는 것이기 때문에
        //dfs나 bfs에서 오름차순/내림차순 언급이 없기 때문에 가능.
        Node* temp;
        if(uCur->next){
            temp = uCur->next;
            uNode->next = temp;
        }
        uCur->next = vNode;
        
        if(vCur->next){
            temp = vCur->next;
            vNode->next = temp;
        }
        vCur->next = uNode;
    }
    
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(nodes, visited, i);
            //연결요소를 세는 것은 결국 dfs 또는 bfs를 몇 번 호출하는 문제인가로 귀결.
            count++;
        }
    }
    cout<<  count;
    
    delete[] visited;
    for(int i = 0; i <= n; i++)
        delete[] nodes[i];
    delete[] nodes;
    
    return 0;
}
