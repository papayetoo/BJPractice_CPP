//#include <iostream>
//#include <memory>
//#include <algorithm>
//#include <queue>
//
//#define MAX 2999990
//using namespace std;
//
//struct adjNode{
//    int to = -1;
//    int weight = 0;
//    adjNode* next = NULL;
//}node;
//
//typedef struct edgeInfo{
//    int from;
//    int to;
//    int weight;
//}edge;
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    
//    int v, e, startNode; cin >> v >> e >> startNode;
//    unique_ptr<adjNode* []> adjList(new adjNode* [v]);
//    for(int i = 0; i < v; i++){
//        adjList[i] = new adjNode;
//    }
//    unique_ptr<edge []> edges(new edge [e]);
//    unique_ptr<int []> dist(new int[v]);
//    unique_ptr<int []> visited(new int[v]);
//    fill(dist.get(), dist.get() + v, MAX);
//    fill(visited.get(), visited.get() + v, 0);
////  배열에서 0부터 시작하기 때문에 startNode -1
//    dist[startNode - 1] = 0;
//    
//    
//    for(int i = 0 ; i < e; i++){
//        int fromIndex, toIndex, weight; cin>> fromIndex >> toIndex >> weight;
//        if(fromIndex == startNode)
//            dist[toIndex - 1] = min(dist[toIndex - 1], weight);
//        edges[i].from = fromIndex - 1; edges[i].to = toIndex - 1; edges[i].weight = weight;
//    }
//    
//    sort(edges.get(), edges.get() + e, [](edge a, edge b){
//        return a.weight < b.weight;
//    });
//    
//    for(int i = 0; i < e; i++){
//        adjNode* cur = adjList[edges[i].from];
//        adjNode* newNode = new adjNode;
//        newNode->to= edges[i].to; newNode->weight = edges[i].weight;
//        while(cur->next){
//            cur = cur->next;
//        }
//        cur->next = newNode;
//    }
//   
//    priority_queue< pair<int, pair <int, int> > > pq;
//    pq.push({startNode - 1, {startNode -1, 0}});
//    visited[startNode - 1] = 1;
//    int k = startNode - 1;
//    while(!pq.empty()){
//        pair<int, int> top = pq.top();
//        int to = top.first; int weight = top.second;
//        pq.pop();
//        adjNode* cur = adjList[k];
//        while(cur->next){
//            if(cur->to == -1)
//                break;
//            pq.push({cur->to, cur->weight});
//            visited[cur->to] = 1;
//            cur = cur ->next;
//        }
//        
//    }
//
//    for(int i = 0; i < v; i++){
//        if(dist[i] < MAX)
//            cout << dist[i] << "\n";
//        else
//            cout << "INF\n";
//    }
//    
//    return 0;
//}
