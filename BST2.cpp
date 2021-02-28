#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left=left;
        this->right = right;
    }
};


void insert(Node* &root, int data)
{
    if(root == nullptr)
        {
            root = new Node(data);
            return;
        }

    if(data < root->data)
        {
            insert(root->left, data);
        }
    if(data >= root->data)
        {
            insert(root->right, data);
        }
}

void sumHelper(Node* &root, int &sum)
{
    if(root == nullptr)
        {
            return;
        }

    sumHelper(root->right, sum);
    sum += root->data;
    root->data = sum;
    sumHelper(root->left, sum);

}

void sumBST(Node*& root)
{
    int sum = 0;
    sumHelper(root, sum);
    return;
}

void collect(Node* root, vector<int> &arr)
{
    if(root == nullptr)
        {
            return;
        }

    collect(root->left, arr);
    arr.push_back(root->data);
    collect(root->right, arr);
}



void createBST(Node* & root, vector<int> &arr)
{
    if(root == nullptr)
        {
            return;
        }

    createBST(root->left, arr);
    root->data = arr.back();
    arr.pop_back();
    createBST(root->right, arr);

}

void sortArr(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
}

bool isBST

int main() {
    vector<int> arr;
    Node* tree = nullptr;
    insert(tree, 1);
    insert(tree, 6);
    insert(tree, 4);
    insert(tree, 7);
    insert(tree, 2);

    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->left = new Node(10);




    collect(root, arr);
    sortArr(arr);
    createBST(root, arr);

    return 0;
}
