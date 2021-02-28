#include <iostream>
#include <queue>
#include <string>

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

void insertElement(Node* &root, std::string command, double data)
{
    if(root == nullptr)
        {
            root = new Node(data);
            return;
        }
    Node* current = root;
    int size = command.size() - 1;
    for(int i = 0; i < size; i++)
        {
            if(command[i] == 'L')
                {
                    current = current->left;
                }

            if(command[i] == 'R')
                {
                    current = current->right;
                }

            if(current == nullptr)
                {
                    return;
                }
        }
    if(command[size] == 'L')
        {
            current->left = new Node(data);
        }

    if(command[size] == 'R')
        {
            current->right = new Node(data);
        }
}

int findHeight(Node* root)
{
    if(root == nullptr)
        {
            return 0;
        }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);

}

bool findIfEqual(Node* root)
{
    if(root == nullptr)
        {
            return true;
        }

    if(root->left != nullptr && root->right != nullptr && (root->data != root->left->data + root->right->data))
        {
            return false;
        }

    if(root->left != nullptr && root->right == nullptr  && (root->data != root->left->data))
        {
            return false;
        }

    if(root->right != nullptr && root->left == nullptr  && (root->data != root->right->data))
        {
            return false;
        }

    return findIfEqual(root->left) && findIfEqual(root->right);

}


int findLevel(Node* root, int target)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int level = 0;
    int size;

    while(!q.empty())
        {
            size = q.size();
            level++;

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    if(target == current->data)
                        {
                            return  level;
                        }

                    if(current->left != nullptr)
                        {
                            q.push(current->left);
                        }

                    if(current->right != nullptr)
                        {
                            q.push(current->right);
                        }

                }
        }
}


int findSum(Node* root)
{
    if(root == nullptr)
        {
            return 0;
        }

    return root->data + findSum(root->left) + findSum(root->right);
}

int findCountInner(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int innerCount = 0;
    int size;
    bool flag1, flag2;

    while(!q.empty())
        {
            size = q.size();

            while(size > 0)
                {
                    flag1 = false;
                    flag2 = false;
                    current = q.front();
                    q.pop();
                    size--;

                    if(current->left != nullptr)
                        {
                            flag1 = true;
                            q.push(current->left);
                        }

                    if(current->right != nullptr)
                        {
                            flag2 = true;
                        }

                    if(flag1&&flag1)
                        {
                            innerCount++;
                            q.push(current->right);
                        }

                }
        }
        return innerCount;//vadim koren
}

void printArr(std::vector<int> arr)
{
    int size = arr.size();
    for(int i = 0; i < size;i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
}

void findAllPathsHelper(Node* root, std::vector<int> arr, int sum, int &maxSum)
{
    if(root == nullptr)
        {
            return;
        }

    sum+= root->data;

    if(sum > maxSum)
        {
            maxSum = sum;
        }
    findAllPathsHelper(root->left, arr,sum, maxSum);
    findAllPathsHelper(root->right, arr, sum, maxSum);



}

void findAllPaths(Node* root)
{
    std::vector<int> arr;
    int sum = 0;
    int maxSum = INT_MIN;
    findAllPathsHelper(root, arr, sum, maxSum);
    std::cout<<maxSum<<std::endl;
}

bool check(Node* root)
{
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }

    if(root->data != (findSum(root->left) + findSum(root->right)))
        {
            return false;
        }

        return check(root->left) && check(root->right);

}

bool isArrSymetr(std::vector<int> arr)
{
    int size = arr.size();
    if(size == 1)
        {
            return true;
        }
    for(int i = 0; i < size/2; i++)
        {
            if(arr[i] != arr[size - i- 1])
                {
                    return false;
                }
        }
    return true;
}

bool parallelTreeBFSHelper(Node* root1, Node* root2)
{
    if(root1 == nullptr && root2 == nullptr)
        {
            return true;
        }

    if(root1 && root2 && root1->data == root2->data)
        return parallelTreeBFSHelper(root1->left, root2->right) && parallelTreeBFSHelper(root2->left, root1->right);


    return false;
}

bool parallelTreeBFS(Node* root)
{
    return parallelTreeBFSHelper(root, root);
}


int main()
{
    Node* root = new Node(8);
    insertElement(root, "L",3 );
    insertElement(root, "LL",9 );
    insertElement(root, "LR",6 );
    insertElement(root, "LRL",4 );
    insertElement(root, "LRR",11 );
    insertElement(root, "R",2 );
    insertElement(root, "RR",5 );
    insertElement(root, "RL",7 );

    Node* root1 = new Node(8);
    insertElement(root1, "L",3 );
    insertElement(root1, "LL",3 );
    insertElement(root1, "R",5 );
    insertElement(root1, "RL",4 );
    insertElement(root1, "RR",1 );

    Node* root2 = new Node(30);
    insertElement(root2, "L",10 );
    insertElement(root2, "LL",4 );
    insertElement(root2, "LR",6 );
    insertElement(root2, "R",5);
    insertElement(root2, "RR",5 );

    Node* root3 = new Node(30);
    insertElement(root3, "L",1 );
    insertElement(root3, "LL",2 );
    insertElement(root3, "LR",6 );
    insertElement(root3, "R",1);
    insertElement(root3, "RR",2 );
    insertElement(root3, "RL",6);




    std::cout<<findLevel(root, 7)<<std::endl;
    std::cout<<findSum(root)<<std::endl;
    std::cout<<findCountInner(root)<<std::endl;
    findAllPaths(root);
    std::cout << "Hello, World!" << std::endl;
    std::cout<<findIfEqual(root1)<<std::endl;
    std::cout<<check(root2)<<std::endl;
    std::cout<<parallelTreeBFS(root3)<<std::endl;
    return 0;
}
