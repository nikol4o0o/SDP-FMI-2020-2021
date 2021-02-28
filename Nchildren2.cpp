#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Node
{
    int data;
    std::vector<Node*> children;

};


int convertToInt(const char* &arr)
{
    int elem = 0;
    while(isdigit(*arr))
        {
            elem = (elem*10) + (*arr - '0');
            arr++;
        }
        arr--;
    return elem;
}


Node* constructTreeHelper(Node* &root, const char* &arr)
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
                            Node* newChild = new Node();
                            constructTreeHelper(newChild, arr);
                            root->children.push_back(newChild);
                        }
                    arr++;
                }
                arr++;
        }
    return root;
}

Node* constructTree(std::string& str)
{
    Node* root = new Node();
    const char* arr = str.c_str() + 1;
    return constructTreeHelper(root, arr);
}

int sumOfNodes(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int size;
    int sum = 0;

    while(!q.empty())
        {
            size = q.size();


            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    sum += current->data;

                    for(auto it = current->children.begin(); it != current->children.end(); it++)
                        {
                            q.push(*it);
                        }

                }
        }

    return sum;

}

int countBigger(Node* root, int target)
{
    std::queue<Node*> q;
    q.push(root);
    int size;
    int counter = 0;
    Node* current = nullptr;

    while(!q.empty())
        {

            size = q.size();

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    if(current->data > target)
                        {
                            counter++;
                        }


                    for(auto it = current->children.begin(); it != current->children.end(); it++)
                        {
                            q.push(*it);
                        }

                }
        }
    return counter;
}


void findNodeWithBiggestSum(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int size = 0;
    int currentsum = 0;
    int finalsum = 0;
    Node* Tempnode = nullptr;
    Node* finalNode = nullptr;

    while(!q.empty())
        {
            size = q.size();

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    if(currentsum > finalsum)
                        {
                            finalNode = Tempnode;
                            finalsum = currentsum;
                        }
                    currentsum = 0;


                    for(auto it = current->children.begin(); it != current->children.end(); it++)
                        {
                            Tempnode = current;
                            currentsum = currentsum + (*it)->data;
                            q.push(*it);
                        }

                }
        }
    std::cout<<finalNode->data;
}
void hasOccurence(Node* root, int target)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int size;
    int counter = 0;


    while(!q.empty())
        {
            size = q.size();

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;

                    if(current->data == target)
                        {
                            counter++;
                        }

                    for(auto it = current->children.begin(); it != current->children.end(); it++)
                        {
                            q.push(*it);
                        }
                }
        }

        if(counter != 0)
            {
                std::cout<<"The element: "<<target<<" is in the tree "<<counter<<" times!"<<std::endl;
            }
        else
            {
                std::cout<<"There is no such element in the tree!"<<std::endl;
            }
}

std::vector<int> generateArr(int size)
{
    std::vector<int> arrNew;
    int delim;
    for(int i = 0; i < size; i++)
        {
            if(i == 0)
                {
                    delim = 1;
                    arrNew.push_back(delim);
                }
            else
                {
                    delim += 2;
                    arrNew.push_back(delim);
                }

        }

    return arrNew;
}

bool arrCheck(std::vector<int> arr1, std::vector<int> arr2)
{
    sort(arr1.begin(), arr1.end());
    bool result;
    result = (arr1 == arr2);
    return  result;


}

std::vector<int> collectdatafromTree(Node* root)
{
    std::queue<Node*> q;
    q.push(root);
    Node* current = nullptr;
    int size;
    std::vector<int> vector;
    vector.push_back(root->data);

    while(!q.empty())
        {
            size = q.size();

            while(size > 0)
                {
                    current = q.front();
                    q.pop();
                    size--;


                    for(auto it = current->children.begin(); it != current->children.end(); it++)
                        {
                            vector.push_back((*it)->data);
                            q.push(*it);

                        }
                }
        }
    return vector;
}


bool funkciqta(Node* root)
{
    std::vector<int> arr1;
    std::vector<int> arr2;
    arr1 = collectdatafromTree(root);
    int size = arr1.size();
    arr2 = generateArr(size);
   return arrCheck(arr1, arr2);

}

int main() {

   // std::string str = "(10[(4[(2)(6)])(3)(5[(9)(2)(7)])])";
    std::string str1 = "(1[(3)(5)(7)(9)])";
   // Node* root = constructTree(str);
    Node* root1 = constructTree(str1);

    //std::cout<<sumOfNodes(root)<<std::endl;
  //  std::cout<<countBigger(root, 6)<<std::endl;
    //findNodeWithBiggestSum(root);
    std::cout<<std::endl;
   // hasOccurence(root, 5);
    std::cout<<funkciqta(root1);



}
