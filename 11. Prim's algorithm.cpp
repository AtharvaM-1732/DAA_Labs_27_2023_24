#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 10
#define TEMP 0
#define PREM 1
#define infinity 9999
#define NIL -1

struct edge {
    int u;
    int v;
};

int n;
int adj[MAX][MAX];
int pred[MAX];
int length[MAX];
int status[MAX]; // Added declaration for status array

void create_graph();
void make_tree(int r, struct edge tree[MAX]);
int min_temp();

int main() {
    int wt_tree = 0;
    int i, root;
    struct edge tree[MAX];
    create_graph();

    cout << "Enter the root vertex: ";
    cin >> root;

    make_tree(root, tree);

    cout << "Edges to be included in spanning tree are :\n";

    for (i = 1; i <= n - 1; i++) {
        cout << tree[i].u << "->" << tree[i].v << endl;
        wt_tree += adj[tree[i].u][tree[i].v];
    }

    cout << "Weight of spanning tree is: " << wt_tree << endl;
}

void make_tree(int r, struct edge tree[MAX]) {
    int current, i;
    int count = 0; // No. of vertices in tree
    for (i = 0; i < n; i++) {
        pred[i] = NIL;
        length[i] = infinity;
        status[i] = TEMP; // Initialize status array
    }
    length[r] = 0; // Make length of root vertex 0

    while (1) {
        current = min_temp();

        if (current == NIL) {
            if (count == n - 1)
                return;
            else {
                cout << "Graph is not connected, no spanning tree is possible\n";
                exit(1);
            }
        }

        status[current] = PREM; // Make the current vertex permanent

        if (current != r) {
            count++;
            tree[count].u = pred[current];
            tree[count].v = current;
        }

        for (int i = 0; i < n; i++)
            if (adj[current][i] && adj[current][i] < length[i]) {
                pred[i] = current;
                length[i] = adj[current][i];
            }
    }
}

int min_temp() {
    int i;
    int min = infinity;
    int k = -1;
    for (i = 0; i < n; i++) {
        if (status[i] == TEMP && length[i] < min) {
            min = length[i];
            k = i;
        }
    }
    return k;
}

void create_graph() {
    int i, max_edges, origin, destin, wt;
    cout << "Enter number of vertices: ";
    cin >> n;
    max_edges = n * (n - 1) / 2;

    for (i = 0; i < n; i++) // Initialize adjacency matrix
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (i = 1; i <= max_edges; i++) {
        cout << "Enter edge (-1 -1 to exit) " << i << ": ";
        cin >> origin >> destin;

        if (origin == -1 && destin == -1)
            break;

        cout << "Enter weight for this edge: ";
        cin >> wt;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            cout << "Invalid Edge";
        } else {
            adj[origin][destin] = wt;
            adj[destin][origin] = wt;
        }
    }
}
