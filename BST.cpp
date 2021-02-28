#include <iostream>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

    Node(int data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void insertData(Node* &root, int data)
{
    if(root == nullptr)
        {
            Node* newNode = new Node(data);
            root = newNode;
            return;
        }
    if(data < root->data)
        {
            insertData(root->left, data);
        }
    if(data >= root->data)
        {
            insertData(root->right, data);
        }
}

Node* getMinElement(Node* root)
{
    Node* current = root;
    while(current->left == nullptr && current->right == nullptr)
        {
            current = current->left;
        }
    return current;
}

Node* deleteByNode(Node* root, int data)
{
    if(root == nullptr)
        {
            return nullptr;
        }
    if(data < root->data)
        {
            root->left = deleteByNode(root->left, data);
        }
    if(data > root->data)
        {
            root->right = deleteByNode(root->right, data);
        }

    else
        {
            if(root->left == nullptr)
                {
                    Node* nodeTodel = root->right;
                    delete root;
                    return nodeTodel;
                }
            if(root->right == nullptr)
                {
                    Node* nodeTodel = root->left;
                    delete root;
                    return  nodeTodel;
                }

                Node* minNode = getMinElement(root->right);
                root->data = minNode->data;
                root->right = deleteByNode(root->right, minNode->data);
        }
        return root;
}

Node* findAncestor(Node* root, int data1, int data2)
{
    if(root == nullptr)
        {
            return nullptr;
        }

    if(data1<root->data && data2<root->data)
        {
            root = findAncestor(root->left, data1, data2);
        }

    if(data1 > root->data && data2 > root->data)
        {
            root = findAncestor(root->right, data1, data2);
        }

    return root;
}

int main()
{
    Node* tree = nullptr;
    insertData(tree, 6);
    insertData(tree, 4);
    insertData(tree, 1);
    insertData(tree, 2);
    insertData(tree, 3);
    insertData(tree, 5);
    insertData(tree, 9);
    insertData(tree, 8);
    insertData(tree, 7);

    Node* lanc = findAncestor(tree, 1, 5);
    cout<<lanc->data<<endl;

    return 0;
}
