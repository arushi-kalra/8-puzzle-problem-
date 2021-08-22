#include <bits/stdc++.h>
#define N 3
using namespace std;

class Node
{
  public:
    int board[N][N];
    int g, h, i, j;
    Node *parent;

    Node(int board[N][N])
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                this->board[i][j] = board[i][j];

        markindex();
        h = manDist(board);
        g = 0;
        parent = NULL;
    }

    int score()
    {
        return g + h;
    }

    void markindex()
    {
        for (int k = 0; k < N; k++)
            for (int l = 0; l < N; l++)
                if (board[k][l] == 0)
                {
                    i = k;
                    j = l;
                    return;
                }
    }

    bool operator==(Node current)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (this->board[i][j] != current.board[i][j])
                    return false;
        return true;
    }

    int manDist(int mat[N][N])
    {
        int dist = 0;
        int corr_i, corr_j;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] != 0)
                {
                    corr_i = (mat[i][j] - 1) / N;
                    corr_j = (mat[i][j] - 1) % N;
                    dist += abs(corr_i - i) + abs(corr_j - j);
                }
            }
        }

        return dist;
    }

    void display()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

class Solver
{
  public:
    vector<Node> open_list;
    vector<Node> closed_list;
    int index;

    bool isSafe(int i, int j)
    {
        if (i >= 0 && i < N && j >= 0 && j < N)
            return true;
        else
            return false;
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    bool inClosedList(Node current)
    {
        for (int i = 0; i < closed_list.size(); i++)
        {
            if (closed_list[i] == current)
                return true;
        }
        return false;
    }

    bool inOpenList(Node current)
    {
        for (int i = 0; i < open_list.size(); i++)
        {
            if (open_list[i] == current)
                return true;
        }
        return false;
    }

    Node min()
    {
        int min = INT_MAX;
        Node temp = open_list[0];
        for (int i = 0; i < open_list.size(); i++)
        {
            if (open_list[i].score() < min)
            {
                min = open_list[i].score();
                temp = open_list[i];
                index = i;
            }
        }
        return temp;
    }

    vector<Node> nextNode(Node current)
    {
        vector<Node> possible_nodes;
        int board[N][N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = current.board[i][j];

        int i = current.i;
        int j = current.j;

        if (isSafe(i + 1, j))
        {
            swap(&board[i][j], &board[i + 1][j]);
            Node newnode(board);
            newnode.g = current.g + 1;
            newnode.parent = &current;
            possible_nodes.push_back(newnode);
            swap(&board[i][j], &board[i + 1][j]);
        }

        if (isSafe(i - 1, j))
        {
            swap(&board[i][j], &board[i - 1][j]);
            Node newnode(board);
            newnode.g = current.g + 1;
            newnode.parent = &current;
            possible_nodes.push_back(newnode);
            swap(&board[i][j], &board[i - 1][j]);
        }

        if (isSafe(i, j + 1))
        {
            swap(&board[i][j], &board[i][j + 1]);
            Node newnode(board);
            newnode.g = current.g + 1;
            newnode.parent = &current;
            possible_nodes.push_back(newnode);
            swap(&board[i][j], &board[i][j + 1]);
        }

        if (isSafe(i, j - 1))
        {
            swap(&board[i][j], &board[i][j - 1]);
            Node newnode(board);
            newnode.g = current.g + 1;
            newnode.parent = &current;
            possible_nodes.push_back(newnode);
            swap(&board[i][j], &board[i][j - 1]);
        }

        return possible_nodes;
    }

    void a_star(int board[N][N])
    {
        Node start(board);
        open_list.push_back(start);

        while (!open_list.empty())
        {
            Node current = min();

            if (current.h == 0)
            {
                cout << "Reacher Goal State" << endl;
                return;
            }

            open_list.erase(open_list.begin() + index);
            closed_list.push_back(current);

            vector<Node> possible_nodes = nextNode(current);

            for (int i = 0; i < possible_nodes.size(); i++)
            {
                if (inClosedList(possible_nodes[i]))
                    continue;

                if (!inOpenList(possible_nodes[i]))
                    open_list.push_back(possible_nodes[i]);

                else
                {
                    auto actual_node = find(open_list.begin(), open_list.end(), possible_nodes[i]);

                    if (possible_nodes[i].g < actual_node->g)
                    {
                        actual_node->g = possible_nodes[i].g;
                        actual_node->parent = possible_nodes[i].parent;
                    }
                }
            }
        }
    }
};

int main()
{
    int puzzle[N][N] = {{1, 8, 2},
                        {0, 4, 3},
                        {7, 6, 5}};
    Solver s;
    s.a_star(puzzle);
}