#include <iostream>
#include <string.h>
#include <queue>
#include <stdlib.h> /* free */
using namespace std;

struct Node
{
    int value = -1;
    Node *left = NULL;
    Node *right = NULL;

    Node(int value) : value(value), left(NULL), right(NULL) {}
};

void print_tree(Node *root)
{
    //use bfs
    queue<Node *> nodeQueue;
    nodeQueue.push(root);

    bool space = false;
    while (!nodeQueue.empty())
    {
        //don't print space in end of line
        //otherwise you will get Presentation error
        if (space)
            printf(" ");
        space = true;

        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();

        printf("%d", currentNode->value);
        if (currentNode->left != NULL)
            nodeQueue.push(currentNode->left);
        if (currentNode->right != NULL)
            nodeQueue.push(currentNode->right);
    }
    printf("\n");
}

bool is_valid(Node *root)
{
    if (root == NULL)
        return true;
    if (root->value == -1)
        return false;

    bool hasValue = is_valid(root->left) && is_valid(root->right);
    return hasValue;
}

void free_tree(Node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

int main()
{
    //init
    Node *tree = NULL;
    bool notComplete = false;

    string node_str;
    while (cin >> node_str)
    {
        if (node_str == "()")
        {
            if (notComplete || !is_valid(tree))
                printf("not complete\n");
            else
                print_tree(tree);

            //init
            free_tree(tree);
            tree = NULL;
            notComplete = false;
            continue;
        }
        if (notComplete)
            continue;

        if (tree == NULL)
            tree = new Node(-1);

        //get node value
        int value = 0;
        int index;
        for (index = 1; node_str[index] != ','; ++index)
        {
            value = value * 10 + node_str[index] - '0';
        }

        //get node position
        Node *curNode = tree;
        for (++index; node_str[index] != ')'; ++index)
        {
            if (node_str[index] == 'L')
            {
                if (curNode->left == NULL)
                    curNode->left = new Node(-1);
                curNode = curNode->left;
            }
            else if (node_str[index] == 'R')
            {
                if (curNode->right == NULL)
                    curNode->right = new Node(-1);
                curNode = curNode->right;
            }
        }

        //put in tree
        if (curNode->value == -1)
            curNode->value = value;
        else
            notComplete = true;
    }
    return 0;
}
