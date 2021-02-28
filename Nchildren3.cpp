#include <iostream>
#include <vector>
#include <string>
struct Node
{
    int data;
    std::vector<Node*> children;
};

int convertToNum(const char* &charArr)
{
    int charToNum = 0;

    while(isdigit(*charArr))
        {
            charToNum = (charToNum * 10) + (*charArr - '0');
            charArr++;
        }
        charArr--;
        return charToNum;
}

Node* createTreeHelper(Node* &root, const char* &inputTree) {
    int ch = convertToNum(inputTree);
    inputTree++;
    root->data = ch;

    if (*inputTree == '[')
        {
            inputTree++;

            while (*inputTree != ']')
                {
                    if (*inputTree == '(')
                        {
                            inputTree++;
                            Node *newChild = new Node();
                            createTreeHelper(newChild, inputTree);
                            root->children.push_back(newChild);
                        }
                    inputTree++;
                }
            inputTree++;
        }
    return root;
}

Node* createTree(std::string str)
{
    Node* tree = new Node();
    const char* strinput = str.c_str() +1;
   return createTreeHelper(tree, strinput);


}

void countGreaterNodesHelper(Node* root, int target, std::vector<int> &buff)
{
    if(root == nullptr)
        {
            return ;
        }


    if(root->data > target)
        {
            buff.push_back(root->data);
        }

    int size = root->children.size();
    for(int i = 0; i < size; i++)
        {
            countGreaterNodesHelper(root->children[i], target, buff);
        }
}

int countGreater(Node* root, int target)
{
    std::vector<int> buffer;
    countGreaterNodesHelper(root,target,buffer );
    return buffer.size();
}

int main()
{
    std::string stringTree = "(10[(4[(2)(6)])(3)(5[(9)(2)(7)])])";
    Node* root = createTree(stringTree);

    std::cout << countGreater(root, 5) << "\n";

    return 0;
}