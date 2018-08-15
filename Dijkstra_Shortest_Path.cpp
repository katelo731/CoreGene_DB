#include <bits/stdc++.h>
#include <fstream>
#define MAXV 1000000
using namespace std;

struct Node{
    int node;
    int weight;
    Node *next;
        
    Node(int node, int weight){
	this->node = node;
	this->weight = weight;
	this->next = NULL;
    }
};

class Graph{
    bool directed;
  public:
    Node *edges[MAXV + 1];
    Graph(bool directed);
    void insert_edge(int x, int y, int weight, bool directed);
    //void print();
};

Graph::Graph(bool directed){
    this->directed = directed;
    
    for(int i = 1; i < (MAXV + 1); i ++)
        this->edges[i] = NULL;
}

void Graph::insert_edge(int x, int y, int weight, bool directed){
    if(x > 0 && x < (MAXV + 1) && y > 0 && y < (MAXV + 1)){
        Node *edge = new Node(y, weight);
        edge->next = this->edges[x];
        this->edges[x] = edge;
        
        if(!directed)
            insert_edge(y, x, weight, true);
    }
}

/*
void Graph::print(){
    for(int v = 1; v < (MAXV + 1); v ++)
        if(this->edges[v] != NULL){
            cout << "Vertex " << v << " has neighbors: " << endl;
            Node *curr = this->edges[v];
            while(curr != NULL){
                cout << curr->node << endl;
                curr = curr->next;
            }
        }
}
*/

void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start){

    bool discovered[MAXV + 1];
    Node *curr;
    int v_curr;
    int v_neighbor;
    int weight;
    int smallest_dist;
	
    // initialize
    for(int i = 1; i < (MAXV + 1); i ++){
        discovered[i] = false;
        distance[i] = std::numeric_limits<int>::max();
        parent[i] = -1;
    }

    distance[start] = 0;
    v_curr = start;

    while(discovered[v_curr] == false){

        discovered[v_curr] = true;
        curr = g->edges[v_curr];

        while(curr != NULL){

            v_neighbor = curr->node;
            weight = curr->weight;

            if((distance[v_curr] + weight) < distance[v_neighbor]){
                distance[v_neighbor] = distance[v_curr] + weight;
                parent[v_neighbor] = v_curr;
            }
            curr = curr->next;
        }

        smallest_dist = std::numeric_limits<int>::max();
        for(int i = 1; i < (MAXV + 1); i ++)
            if(!discovered[i] && (distance[i] < smallest_dist)){
	        v_curr = i;
	        smallest_dist = distance[i];
            }
    }
}

/*
void print_shortest_path(int v, int parent[]){
    if(v > 0 && v < (MAXV + 1) && parent[v] != -1){
        cout << parent[v] << " ";
        print_shortest_path(parent[v], parent);
    }
}
*/

void print_distances(int start, int distance[]){
    for(int i = 1; i < (MAXV + 1); i ++)
        if(distance[i] != std::numeric_limits<int>::max())
            cout << "Shortest distance from " << start << " to " << i << " is: " << distance[i] << endl;
}

int main(){

    Graph *g = new Graph(false);
    int parent[MAXV + 1];
    int distance[MAXV + 1];
    int start = 1;
    bool directed = false;

    g->insert_edge(1, 2, 4, directed);
    g->insert_edge(1, 3, 1, directed);
    g->insert_edge(3, 2, 1, directed);
    g->insert_edge(3, 4, 5, directed);
    g->insert_edge(2, 4, 3, directed);
    g->insert_edge(2, 5, 1, directed);
    g->insert_edge(4, 5, 2, directed);
    g->insert_edge(4, 6, 2, directed);

    dijkstra_shortest_path(g, parent, distance, start);
    
    //print_shortest_path(6, parent);
    //cout << endl;
    print_distances(start, distance);

    delete g;
    return 0;
}
