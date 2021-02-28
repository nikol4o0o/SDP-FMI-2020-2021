#include <iostream>
#include <queue>
#include <vector>
#include <string>


struct Node
{
    int data;
    std::vector<Node*> children;
};


int convertToInt(const char* &arr)
{
    int num = 0;

    while(isdigit(*arr))
        {
            num = (num*10) + (*arr - '0');
            arr++;
        }
        arr--;
    return  num;
}

Node* createTreeHelper(Node* &root, const char* &arr)
{
    int data = convertToInt(arr);
    root->data = data;
    arr++;

    if(*arr == '[')
        {
            arr++;
            while(*arr != ']')
                {
                    if(*arr == '(')
                        {
                            arr++;
                            Node* child = new Node();
                            createTreeHelper(child, arr);
                            root->children.push_back(child);
                        }
                        arr++;
                }
                arr++;
        }
    return root;
}


Node* createTree(std::string& input)
{
    Node* root = new Node();
    const char* arr = input.c_str() + 1;
    return createTreeHelper(root, arr);
}


void printVector(std::vector<Node*> arr)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
        {
            std::cout<<arr[i]->data<<" ";
        }
}

void BFS(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    int size;
    int level;
    Node* current = nullptr;
    int childrenSize = 0;
    std::vector<Node*> leaves;


    while(!q.empty())
        {
            size = q.size();
            level++;

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    childrenSize = current->children.size();
                    if(childrenSize == 0)
                        {
                            leaves.push_back(current);
                        }
                    else
                        {
                            std::cout<<"Node: "<<current->data<<"  Number ot children: "<<childrenSize<<std::endl;
                            std::cout<<"Level: "<<level;
                            std::cout<<"  children:";
                            printVector(current->children);
                            std::cout<<std::endl;
                            for(auto it = current->children.begin(); it != current->children.end(); it++)
                                {
                                    q.push(*it);
                                }
                        }

                }

        }

        printVector(leaves);
}
int main() {
        std::string input = "(10[(4[(9)(7)])(2)(5[(3)(4)(6)])(8)])";
        Node* root = createTree(input);

        BFS(root);

    return 0;
}
