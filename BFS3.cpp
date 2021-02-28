#include <iostream>
#include <vector>
#include <queue>

using namespace  std;

void printArr(std::vector<int> arr)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
}



struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void PrintPathHelper(Node* root, std::vector<int> arr)
{
    if(root == nullptr)
        {
            return;
        }
    arr.push_back(root->data);
    if(root->left == nullptr && root->right == nullptr)
        {
            printArr(arr);
            return;
        }

    PrintPathHelper(root->right, arr);
    PrintPathHelper(root->left, arr);
}

int sumTree(Node* root)
{
    if(root == nullptr)
        {
            return 0;
        }

        return root->data + sumTree(root->right) + sumTree(root->left);
}


void printPath(Node* root)
{
    vector<int> arr;
    PrintPathHelper(root, arr);
}

void findPathHelper(Node* root, int target, std::vector<int> arr)
{
    if(root == nullptr)
        {
            return;
        }
    arr.push_back(root->data);
    if(root->data == target)
        {
            printArr(arr);
            return;
        }


    findPathHelper(root->left, target, arr);
    findPathHelper(root->right, target, arr);

}


void findPath(Node* root, int target)
{
    std::vector<int> arr;
    findPathHelper(root, target, arr);
}


int findHeight(Node* root)
{
    if(root == nullptr)
        {
            return 0;
        }

        int leftSum = findHeight(root->left);
        int rightSum = findHeight((root->right));

        return 1 + max(leftSum, rightSum);
}


int findCount(Node* root)
{
    if(root == nullptr)
        {
            return 0;
        }

        return 1 + findCount(root->left) + findCount(root->right);
}

void findLongestSumHelper(Node* root, int buffer, int &maximum)
{
    if(root == nullptr)
        {
            if(buffer > maximum)
                {
                    maximum = buffer;
                }
                return;
        }
    buffer += root->data;

        findLongestSumHelper(root->left, buffer, maximum);
        findLongestSumHelper(root->right, buffer, maximum);


}

int findLongestSum(Node* root)
{
    int buffer = 0;
    int maximum = INT_MIN;
    findLongestSumHelper(root, buffer, maximum);
    cout<<maximum;
}

bool checkChildrenSum(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
        {
            Node* father = q.front();
            q.pop();
            if(father->left && father->right)
                {
                    if(!father->data == (father->left->data + father->right->data))
                        {
                            return false;
                        }
                    q.push(father->left);
                    q.push(father->right);
                }
            if(!father->left && father->right)
                {
                    if(father->data != father->right->data )
                        {
                            return false;
                        }
                    q.push(father->right);
                }
            if(father->left && !father->right)
                {
                    if(father->data != father->left->data )
                        {
                            return false;
                        }
                    q.push(father->left);
                }


        }
        return true;
}

bool checkSubTreeSum(Node* root)
{
    if(root == nullptr || (root->right == nullptr && root->left == nullptr))
        {
            return true;
        }
    if(root->data != sumTree(root->left) + sumTree(root->right))
        {
            return false;
        }

   return checkSubTreeSum(root->left) && checkSubTreeSum(root->right);
}

int main()
{

    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->left = new Node(7);

    Node* root1 = new Node(10);
    root1->left = new Node(8);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(5);
    root1->right->right = new Node(2);


    Node* root2 = new Node(30);
    root2->left = new Node(10);
    root2->left->left = new Node(4);
    root2->left->right = new Node(6);
    root2->right = new Node(5);
    root2->right->right = new Node(5);

    cout<<findHeight(root)<<endl;
    cout<<findCount(root)<<endl;
    printPath(root);
    findPath(root, 6);
    findLongestSum(root);
    cout<<endl;
    cout<<checkChildrenSum(root1);
    cout<<endl;
    cout<<checkSubTreeSum(root2);
    return 0;
}
