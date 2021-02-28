#include <iostream>
#include <queue>
#include <vector>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr , Node* right = nullptr);
};

Node::Node(int data, Node *left, Node *right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

void printQue(std::queue<Node*> q)
{
    for(auto it = q.front(); !q.empty(); it++)
        {
            std::cout<<it->data<<" ";
            q.pop();
        }
}

void printArr(std::vector<int> arr)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
        {
            std::cout<<arr[i]<<" ";
        }
}


void BFS(Node* root)
{
    Node* current = nullptr;
    std::queue<Node* > q;
    q.push(root);
    int size = 0;
    int levelMax = INT_MIN;
    int level = 1;

    while(!q.empty())
        {
        size = q.size();
        level++;

            while(size > 0)
                {
                    current = q.front();


                    if(levelMax < level)
                        {
                            levelMax = level;

                        }

                    if(current->left != nullptr)
                        {
                            q.push(current->left);
                        }
                    if(current->right != nullptr)
                        {
                            q.push(current->right);
                        }

                    q.pop();
                    size--;
                }

        }
        std::cout<<levelMax;
}


void BFSprint(Node* root, int levelMax)
{

        Node* current;
        std::queue<Node* > q;
        q.push(root);
        int size = 0;
        int level = 0;
        int element;
        bool flag = false;
        if(flag)
            {
                printQue(q);
            }

        while(!q.empty())
            {

                size = q.size();
                level++;

                while(size > 0)
                    {
                        current = q.front();
                        if(level == levelMax)
                            {
                                printQue(q);
                            }


                        if(current->left != nullptr)
                            {
                                q.push(current->left);
                            }
                        if(current->right != nullptr)
                            {
                                q.push(current->right);
                            }
                            q.pop();
                            size--;
                    }

            }
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    BFS(root);
    std::cout<<std::endl;
    BFSprint(root, 3);
    //Izkarva nuli zashtoto e opashka NZ :D

    return 0;
}
