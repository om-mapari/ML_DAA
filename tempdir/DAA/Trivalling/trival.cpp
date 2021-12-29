#include <bits/stdc++.h>
using namespace std;

// number of total nodes
#define N 5
#define INF INT_MAX

class Node
{
public:
    vector<pair<int, int>> path; // store edge
    int matrix_reduced[N][N];    // stores the reduced matrix
    int cost;                    // stores the lower bound
    int vertex;                  // stores the current city number
    int level;                   // stores the total number of cities visited so far
};

Node *newNode(int matrix_parent[N][N], vector<pair<int, int>> const &path, int level, int i, int j)
{
    Node *node = new Node;
    node->path = path;
    if (level != 0){
        // add a current edge to the path
        node->path.push_back(make_pair(i, j));
    }
    // copy data from the parent node to the current node
    memcpy(node->matrix_reduced, matrix_parent,
           sizeof node->matrix_reduced);

    // Change all entries of row `i` and column `j` to `INFINITY`
    // skip for the root node        
    for (int k = 0; level != 0 && k < N; k++)
    {
        node->matrix_reduced[i][k] = INF; // set outgoing edges for the city `i` to `INFINITY`
        node->matrix_reduced[k][j] = INF; // set incoming edges to city `j` to `INFINITY`
    }

    // Set `(j, 0)` to `INFINITY`
    // here start node is 0
    node->matrix_reduced[j][0] = INF;

    node->level = level;// set number of cities visited so far
    node->vertex = j; // assign current city number
    return node;
}

// Function to reduce each row so that there must be at least one zero in each row
void reduce_row(int matrix_reduced[N][N], int row[N])
{
    fill_n(row, N, INF); // initialize row array to `INFINITY`

    // `row[i]` contains minimum in row `i`
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < row[i])
                row[i] = matrix_reduced[i][j];

    // reduce the minimum value from each element in each row
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && row[i] != INF)
                matrix_reduced[i][j] -= row[i];
}

// Function to reduce each column so that there must be at least one zero
// in each column
void reduce_column(int matrix_reduced[N][N], int col[N])
{
    fill_n(col, N, INF); // initialize all elements of array `col` with `INFINITY`

    // `col[j]` contains minimum in col `j`
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < col[j])
                col[j] = matrix_reduced[i][j];

    // reduce the minimum value from each element in each column
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && col[j] != INF)
                matrix_reduced[i][j] -= col[j];
}

// Function to get the lower bound on the path starting at the current minimum node
int cost_calculation(int matrix_reduced[N][N])
{
    int cost = 0; // initialize cost to 0

    int row[N]; // Row Reduction
    reduce_row(matrix_reduced, row);

    int col[N]; // Column Reduction
    reduce_column(matrix_reduced, col);

    // the total expected cost is the sum of all reductions
    for (int i = 0; i < N; i++)
        cost += (row[i] != INT_MAX) ? row[i] : 0,
            cost += (col[i] != INT_MAX) ? col[i] : 0;

    return cost;
}

// Function to print list of cities visited following least cost
void printPath(vector<pair<int, int>> const &list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list[i].first + 1 << " -> "
             << list[i].second + 1 << endl;
}

class comp // Comparison object to be used to order the heap
{
public:
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

// main fun
int solve(int adjacensyMatrix[N][N])
{
    // Create a priority queue to store live nodes of the search tree
    priority_queue<Node *, std::vector<Node *>, comp> pq;
    vector<pair<int, int>> v;

    // create a root node and calculate its cost.
    // The TSP starts from the first city, i.e., node 0
    Node *root = newNode(adjacensyMatrix, v, 0, -1, 0);

    // get the lower bound of the path starting at node 0
    root->cost = cost_calculation(root->matrix_reduced);

    // Add root to the list of live nodes
    pq.push(root);

    // Finds a live node with the least cost, adds its children to the list of
    // live nodes, and finally deletes it from the list
    while (!pq.empty())
    {
        // Find a live node with the least estimated cost
        Node *min = pq.top();
        pq.pop();         // The found node is deleted from the list of live nodes
        int i = min->vertex; // `i` stores the current city number
        
        // if all cities are visited
        if (min->level == N - 1)
        {
            min->path.push_back(make_pair(i, 0)); // return to starting city
            printPath(min->path); // print list of cities visited
            return min->cost; // return min cost
        }

        // do for each child of min
        // `(i, j)` forms an edge in a space tree
        for (int j = 0; j < N; j++)
        {
            if (min->matrix_reduced[i][j] != INF)
            {
                // create a child node and calculate its cost
                Node *child = newNode(min->matrix_reduced, min->path,
                                      min->level + 1, i, j);

                /* Cost of the child =
                cost of the parent node + cost of the edge(i, j) + lower bound of the path starting at node j
                */
                child->cost = min->cost + min->matrix_reduced[i][j] + cost_calculation(child->matrix_reduced);
                
                // Add a child to the list of live nodes
                pq.push(child);
            }
        }
        // free node as we have already stored edges `(i, j)` in vector.
        // So no need for a parent node while printing the solution.
        delete min;
    }
}

int main()
{

    // cost matrix for traveling salesman problem.
    int adjacensyMatrix[N][N] =
        {
            {INF, 20, 30, 10, 11},
            {15, INF, 16, 4, 2},
            {3, 5, INF, 2, 4},
            {19, 6, 18, INF, 3},
            {16, 4, 7, 16, INF}};

    cout << "\nCost is " << solve(adjacensyMatrix);

    return 0;
}
