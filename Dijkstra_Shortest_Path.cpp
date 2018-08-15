#include <bits/stdc++.h>
#include <fstream>
#define MAXV 100000
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

int main(){

    Graph *g = new Graph(false);
    int parent[MAXV + 1];
    int distance[MAXV + 1];
    int start = 1;
    
    ifstream in("dijkstra_test.txt");
    ofstream out("dijkstra_out.txt");
    int id1, id2, weight;
	
    while(in >> id1 >> id2 >> weight)
    {
	g->insert_edge(id1, id2, weight, false);
    }

    dijkstra_shortest_path(g, parent, distance, start);
    
    //print_shortest_path(6, parent);
    
    for(int i = 1; i < (MAXV + 1); i ++)
        if(distance[i] != std::numeric_limits<int>::max())
            out << start << '\t' << i << '\t' << distance[i] << endl;

    delete g;
    return 0;
}
