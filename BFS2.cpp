#include <iostream>
#include <string>
#include <queue>


struct Node
{
    double data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


/*void makeSentences(Node* root)
{
    std::queue<Node*> q;
    int size;
    q.push(root);
    int level = 0;
    std::string levelSentence = "";
    Node* current = nullptr;

    while(!q.empty())
        {
            size = q.size();
            level++;
            levelSentence = " ";

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    levelSentence += current->data + " ";

                    if(current->left != nullptr)
                        {
                            q.push(current->left);
                        }

                    if(current->right != nullptr)
                        {
                            q.push(current->right);
                        }
                }
                std::cout<<levelSentence<<std::endl;
        }

}
*/

void maxSumLevel(Node* root)
{
    std::queue<Node*> q;
    Node* current = nullptr;
    q.push(root);
    int size;
    int sum = 0;
    int level = 0;
    int levelMax;
    int maxSum = INT_MIN;

    while(!q.empty())
    {
        int size =q.size();
        int sum = 0;
        level++;

        while(size > 0)
            {
                current = q.front();
                q.pop();

                sum += current->data;
                size--;

                if (sum > maxSum)
                    {
                        maxSum = sum;
                        levelMax = level;
                    }

                if (current->left != nullptr)
                    {
                        q.push(current->left);
                    }

                if (current->right != nullptr)
                    {
                        q.push(current->right);
                    }
            }
    }
    std::cout<<"Sum: "<<maxSum<<" Level: "<< levelMax<<std::endl;
}


void sumAverages(Node* root)
{
    std::queue<Node* > q;
    q.push(root);
    Node* current = nullptr;
    int size = 0;
    int delSize = 0;
    double currSum = 0;
    double averageSum = 0;

    while(!q.empty())
        {
            size = q.size();
            delSize = q.size();
            currSum = 0;

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    currSum += current->data;
                    size--;


                    if (current->left != nullptr)
                        {
                            q.push(current->left);
                        }

                    if (current->right != nullptr)
                        {
                            q.push(current->right);
                        }
                }

                averageSum += (currSum/delSize);
                delSize = 0;
        }
        std::cout<<averageSum;
}

int main() {
    /*Node* root = new Node("trees");
    root->left = new Node("binary");
    root->left->left = new Node("they");
    root->left->left->left = new Node("they");
    root->left->right = new Node("are");
    root->left->left->right = new Node("have");
    root->left->right->left = new Node("at");
    root->right = new Node("trees");
    root->right->right = new Node("cool");
    root->right->right->right = new Node("children");
    root->right->left = new Node("very");
    root->right->left->left = new Node("most");
    root->right->left->right = new Node("two");
     */

   // makeSentences(root);

    Node* root = new Node(9);
    root->left = new Node(5);
    root->left->left = new Node(8);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right->left = new Node(9);

    maxSumLevel(root);
    std::cout<<std::endl;
    sumAverages(root);

return 0;
}
