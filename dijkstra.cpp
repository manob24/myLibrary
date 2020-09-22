struct Node
{
    int at, cost;
    Node(int _at, int _cost){
        at = _at;
        cost = _cost;
    }
};

bool operator<(Node A, Node B){
    return A.cost>B.cost;
}

struct Edge
{
    int v,w;
    Edge(pair<int,int>edge){
        v = edge.ff;
        w = edge.ss;
    }
};

vector<Edge>adj[102];
priority_queue<Node>PQ;
int dist[102];
int n;

void dijkstra(int s){
    for(int i = 1; i<=n; ++i){
        dist[i]=inf;
    }
    dist[s]=0;
    PQ.push(Node(s,0));

    while(!PQ.empty()){
        Node u = PQ.top();
        PQ.pop();
        // if(u.cost == dist[u.at]){
            for(Edge e : adj[u.at]){
                if(dist[e.v]>u.cost + e.w){
                    dist[e.v]= u.cost+e.w;
                    PQ.push(Node(e.v,dist[e.v]));
                }
            }
        // }
    }
}
