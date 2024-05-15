#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 100
#define infinity 999
#define NIL -1
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
int Distance[MAX];
int pred[MAX];

void create_graph();
void BF_traversal();
void BFS(int v);
int queue[MAX];
int front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main() {
    int u, v, i, count, path[MAX];
    create_graph();
    BF_traversal();

    while (true) {
        cout << "Enter destination vertex (-1 to quit): ";
        cin >> v;

        if (v == -1)
            break;

        if (v < 0 || v >= n) {
            cout << "Destination vertex does not exist\n";
            continue;
        }

        count = 0;

        if (Distance[v] == infinity) {
            cout << "No path from start vertex to destination vertex\n";
            continue;
        } else
            cout << "Shortest distance is " << Distance[v] << endl;


        // Store the full path in the array path

        while (v != NIL) {
            count++;
            path[count] = v;
            u = pred[v];
            v = u;
        }
        cout << "Shortest path is: ";
        for (i = count; i >= 1; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
} //end of main

void create_graph() {
    int i, max_edges, origin, destin;
    cout << "Enter the number of vertices: ";
    cin >> n;

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        cout << "Enter edge " << i << " (enter -1 -1 to finish): ";
        cin >> origin >> destin;

        if (origin == -1 && destin == -1)
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            cout << "Invalid edge! Please enter again." << endl;
            i--;
        } else {
            adj[origin][destin] = 1; // Marking the existence of edge from origin to destin
        }
    }
}


void BF_traversal() {
    int v;

    for (v = 0; v < n; v++) {
        state[v] = initial;
        pred[v] = NIL;
        Distance[v] = infinity;
    }

    cout << "Enter the starting vertex for BFS: ";
    cin >> v;

    BFS(v);
    cout << endl;
}

void BFS(int v) {
    int i;
    insert_queue(v);
    state[v] = waiting;
    Distance[v] = 0;
    pred[v] = NIL;

    while (!isEmpty_queue()) {
        v = delete_queue();
        state[v] = visited;

        for (i = 0; i < n; i++) {
            //check for adjacent unvisited vertices
            if (adj[v][i] != 0 && state[i] == initial) {
                insert_queue(i);
                state[i] = waiting;
                pred[i] = v;
                Distance[i] = Distance[v] + 1;
            }
        }
    }
}

void insert_queue(int vertex) {
    if (rear == MAX - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int delete_queue() {
    int delete_item;
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

int isEmpty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

//Output
/*
Enter the number of vertices: 9
Enter edge 1 (enter -1 -1 to finish): 0 3
Enter edge 2 (enter -1 -1 to finish): 0 1
Enter edge 3 (enter -1 -1 to finish): 1 4
Enter edge 4 (enter -1 -1 to finish): 0 4
Enter edge 5 (enter -1 -1 to finish): 1 2
Enter edge 6 (enter -1 -1 to finish): 3 4
Enter edge 7 (enter -1 -1 to finish): 4 5
Enter edge 8 (enter -1 -1 to finish): 3 6
Enter edge 9 (enter -1 -1 to finish): 6 4
Enter edge 10 (enter -1 -1 to finish): 6 7
Enter edge 11 (enter -1 -1 to finish): 4 7
Enter edge 12 (enter -1 -1 to finish): 7 5
Enter edge 13 (enter -1 -1 to finish): 7 8
Enter edge 14 (enter -1 -1 to finish): 2 5
Enter edge 15 (enter -1 -1 to finish): -1 -1
Enter the starting vertex for BFS: 0

Enter destination vertex (-1 to quit): 4
Shortest distance is 1
Shortest path is: 0 4 
Enter destination vertex (-1 to quit): 7
Shortest distance is 2
Shortest path is: 0 4 7 
Enter destination vertex (-1 to quit): 8
Shortest distance is 3
Shortest path is: 0 4 7 8 
Enter destination vertex (-1 to quit): -1
*/
