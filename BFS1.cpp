#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Node
{
    std::string data;
    Node* left;
    Node* right;

    Node(std::string data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void insertData(Node* &root, std::string strPath, std::string data)
{
    if(root == nullptr)
        {
            root = new Node(data);
            return;
        }

    Node* currentRoot = root;
    int size = strPath.size() - 1;
    for(int i = 0; i < size; i++)
        {
            if(strPath[i] == 'L')
                {
                    currentRoot = currentRoot->left;
                }

            if(strPath[i] == 'R')
                {
                    currentRoot = currentRoot->right;
                }
            if(currentRoot == nullptr)
                {
                    return;
                }

        }

    if(strPath[size] == 'L')
        {
            Node* newRoot = new Node(data);
            currentRoot->left = newRoot;
        }

    if(strPath[size] == 'R')
        {
            Node* newRoot = new Node(data);
            currentRoot->right = newRoot;
        }
}

void BFSSentece(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    int level = 0;
    std::string sentence = "";
    Node* currentRoot = nullptr;
    while(!q.empty())
        {
            int size = q.size();
            level++;

            while(size > 0)
                {
                    currentRoot = q.front();
                    q.pop();
                    size--;

                    sentence+= currentRoot->data + " ";
                    if(currentRoot->left != nullptr)
                        {
                            q.push(currentRoot->left);
                        }

                    if(currentRoot->right != nullptr)
                        {
                            q.push(currentRoot->right);
                        }

                }
                std::cout<<sentence<<" "<<level<<std::endl;
        }


}



int main() {
    Node* root = nullptr;
    insertData(root, "", "tree");
    insertData(root, "L", "binary");
    insertData(root, "LL", "they");
    insertData(root, "LLL", "they");
    insertData(root, "LLR", "have");
    insertData(root, "LR", "are");
    insertData(root, "LRR", "at");
    insertData(root, "R", "trees");
    insertData(root, "RL", "very");
    insertData(root, "RLL", "most");
    insertData(root, "RLR", "two");
    insertData(root, "RR", "cool");
    insertData(root, "RRR", "children");

    BFSSentece(root);
    return 0;
}
