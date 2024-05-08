// #include <bits/stdc++.h>
// using namespace std;
// #define N 3

// struct Node
// {
//     Node* parent;
//     int mat[N][N];
//     int x, y;
//     int cost;
//     int level;
// };

// int printMatrix(int mat[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             cout << mat[i][j] << " ";
//         cout << endl;
//     }
// }

// Node* newNode(int mat[N][N], int x, int y, int newX,
//             int newY, int level, Node* parent)
// {
//     Node* node = new Node;
//     node->parent = parent;
//     memcpy(node->mat, mat, sizeof node->mat);

//     swap(node->mat[x][y], node->mat[newX][newY]);

//     node->cost = INT_MAX;
//     node->level = level;
//     node->x = newX;
//     node->y = newY;

//     return node;
// }

// int calculateCost(int initial[N][N], int final[N][N])
// {
//     int count = 0;
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             if (initial[i][j] && initial[i][j] != final[i][j])
//                 count++;
//     return count;
// }

// int isSafe(int x, int y)
// {
//     return (x >= 0 && x < N && y >= 0 && y < N);
// }

// void printPath(Node* root)
// {
//     if (root == NULL)
//         return;
//     printPath(root->parent);
//     printMatrix(root->mat);

//     cout << "f: " << root->cost + root->level << " | ";
//     cout << "g: " << root->level <<" | h: "<<root->cost<< endl;
// }

// struct comp
// {
//     bool operator()(const Node* lhs, const Node* rhs) const
//     {
//         return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
//     }
// };
// int row[] = {1, 0, -1, 0};
// int col[] = {0, -1, 0, 1};

// void solve(int initial[N][N], int x, int y,
//         int final[N][N])
// {
//     priority_queue<Node*, std::vector<Node*>, comp> pq;
//     Node* root = newNode(initial, x, y, x, y, 0, NULL);
//     root->cost = calculateCost(initial, final);
//     pq.push(root);

//     while (!pq.empty())
//     {
//         Node* min = pq.top();
//         pq.pop();

//         if (min->cost == 0)
//         {
//             printPath(min);
//             return;
//         }

//         printMatrix(min->mat);
//         cout << "f: " << min->cost + min->level << " | ";
//         cout << "g: " << min->level <<" | h: "<<root->cost<< endl;

//         for (int i = 0; i < 4; i++)
//         {
//             if (isSafe(min->x + row[i], min->y + col[i]))
//             {
//                 Node* child = newNode(min->mat, min->x,
//                             min->y, min->x + row[i],
//                             min->y + col[i],
//                             min->level + 1, min);
//                 child->cost = calculateCost(child->mat, final);
//                 pq.push(child);
//             }
//         }
//     }
// }

// int main()
// {
//     int initial[N][N] =
//     {
//         {1, 2, 3},
//         {5, 6, 0},
//         {7, 8, 4}
//     };
//     int final[N][N] =
//     {
//         {1, 2, 3},
//         {5, 8, 6},
//         {0, 7, 4}
//     };
//     int x = 1, y = 2;

//     solve(initial, x, y, final);

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define N 3

struct Node{
    Node* parent;
    int mat[N][N];
    int x, y;
    int level;
    int cost;
};

int calculatecost(int initial[N][N], int final[N][N]){
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(initial[i][j] && initial[i][j]!=final[i][j]){
                count++;
            }
        }
    }
    return count;
}

void printmatrix(int mat[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool issafe(int x, int y){
    return(x>=0 && x<N && y>=0 && y<N);
}

Node* newNode(int mat[N][N], int x, int y, int nx, int ny, int level, Node* parent){
    Node* node = new Node;
    node->parent = parent;

    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[nx][ny]);
    node->cost = INT_MAX;
    node->level = level;
    node->x = nx;
    node->y = ny;

    return node;
}

struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const{
        return (lhs->level+lhs->cost)>(rhs->level+rhs->cost);
    }
};

void printpath(Node* root){
    if(root==NULL){
        return;
    }
    printpath(root->parent);
    printmatrix(root->mat);

    cout<<"f: "<<root->level+root->cost<<" | g: "<<root->level<<" | h: "<<root->cost<<endl;
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};
void solve(int initial[N][N], int final[N][N], int x, int y){
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculatecost(root->mat, final);
    priority_queue<Node*, vector<Node*>, comp>pq;

    pq.push(root);

    while(!pq.empty()){
        Node* min = pq.top();
        pq.pop();

        if(min->cost==0){
            printpath(min);
            return;
        }
        printmatrix(min->mat);

    cout<<"f: "<<min->level+min->cost<<" | g: "<<min->level<<" | h: "<<min->cost<<endl;


        for(int i=0; i<4; i++){
            if(issafe(min->x+row[i], min->y+col[i])){
                Node* child = newNode(min->mat, min->x, min->y, min->x+row[i], min->y+col[i], min->level+1, min);
                child->cost = calculatecost(child->mat, final);
                pq.push(child);
            }
        }
    }
}



int main()
{
    int initial[N][N] =
    {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };
    int final[N][N] =
    {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };
    int x = 1, y = 2;

    solve(initial, final, x, y);

    return 0;
}