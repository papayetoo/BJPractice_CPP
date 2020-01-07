#include <iostream>
#include <memory>
#include <algorithm>

#define MAX 2999990
using namespace std;

struct adjNode{
    int to = 0;
    int weight = 0;
    adjNode* next = NULL;
}node;

typedef struct edgeInfo{
    int from;
    int to;
    int weight;
}edge;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int v, e, startNode; cin >> v >> e >> startNode;
    unique_ptr<adjNode* []> adjList(new adjNode* [v]);
    for(int i = 0; i < v; i++){
        adjList[i] = new adjNode;
    }
    unique_ptr<edge []> edges(new edge [e]);
    unique_ptr<int []> dist(new int[v]);
    unique_ptr<int []> visited(new int[v]);
    fill(dist.get(), dist.get() + v, MAX);
    fill(visited.get(), visited.get() + v, 0);
//  배열에서 0부터 시작하기 때문에 startNode -1
    dist[startNode - 1] = 0;
    
    
    for(int i = 0 ; i < e; i++){
        int fromIndex, toIndex, weight; cin>> fromIndex >> toIndex >> weight;
        if(fromIndex == startNode)
            dist[toIndex - 1] = min(dist[toIndex - 1], weight);
        edges[i].from = fromIndex - 1; edges[i].to = toIndex - 1; edges[i].weight = weight;
    }
    
    sort(edges.get(), edges.get() + e, [](edge a, edge b){
        return a.weight < b.weight;
    });
    
    for(int i = 0; i < e; i++){
        adjNode* cur = adjList[edges[i].from];
        adjNode* newNode = new adjNode;
        newNode->to= edges[i].to; newNode->weight = edges[i].weight;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = newNode;
    }
    
    int count = 0;
    while(count < v){
        int temp = MAX;
        int seleted = -1;
        for(int i = 0; i < v; i++){
            if(!visited[i] && temp > dist[i]){
                temp = dist[i];
                seleted = i;
            }
        }
        if(seleted != -1){
            visited[seleted] = 1;
            adjNode* cur = adjList[seleted];
            while(cur){
                int to = cur->to; int weight = cur->weight;
                if(to)
                    dist[to] = min(dist[to], dist[seleted] + weight);
                cur = cur ->next;
            }
        }else
            break;
        count++;
    }

    for(int i = 0; i < v; i++){
        if(dist[i] < MAX)
            cout << dist[i] << "\n";
        else
            cout << "INF\n";
    }
    
    return 0;
}
