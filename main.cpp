#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <fstream>
#include <unordered_map>

//Sburkal sym vhoda, no pak stroi durvoto po razlichen nachin, inache drugite dve finkcii si rabotqt kakto se ochakva
//Izvinqvan se za sburkanoto postroqvane na durvoto, misleh che nie si izbirame nachin :) :) :)

struct WordNode
{
    std::string data;
    std::vector<WordNode*> children;
};


bool isLetter(char c)
        {
            return (c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z');
        }
void lowerString(std::string& arr)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
        {
            if(isLetter(arr[i]))
                {
                   arr[i]= tolower(arr[i]);
                }
            if(arr[i] == '!' || arr[i] == '?' || arr[i] =='.' || arr[i] == ',')
                {
                    arr[i] = ' ';
                }
        }
}


std::string returnData(const char* &arr)
{
    std::string current;
    while(isLetter(*arr))
        {
            current+=*arr;
            arr++;
        }
        arr--;
    return current;
}



WordNode* createTreeHelper(WordNode* &root, const char* &arr)
{
    std::string data = returnData(arr);
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
                            WordNode* newNode = new WordNode();
                            createTreeHelper(newNode, arr);
                            root->children.push_back(newNode);
                        }
                    arr++;
                }
                arr++;
        }
    return root;
}

WordNode* createTree(const std::string& input)
{
    WordNode* root = new WordNode();
    const char* arr = input.c_str() + 1;
    root = createTreeHelper(root, arr);
    return root;
}

void printArr(std::vector<WordNode*> arr)
{
    int size = arr.size();
    for(int i = 0; i < size; i++)
        {
            std::cout<<arr[i]->data<<" ";
        }
}

void printStack(std::stack<WordNode*> st)
{
    while(!st.empty())
        {
            std::cout<<st.top()->data<<" ";
            st.pop();
        }
}

void printReverse(WordNode* root)
{
    std::queue<WordNode*> q;
    std::stack<WordNode* > st;
    int size = 0;
    q.push(root);
    st.push(root);
    WordNode* current = nullptr;

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
                            q.push(*it);
                            st.push(*it);

                        }

                }

        }
    printStack(st);
}

void printLargestLevel(WordNode* root)
{
    std::queue<WordNode* > q;
    q.push(root);
    int size = 0;
    WordNode* current = nullptr;
    int childrenSize = 0;
    int maxChildrenSize = INT_MIN;
    WordNode* currentMaxNode = nullptr;

    while(!q.empty())
        {
            size = q.size();

            while(size > 0)
                {
                   current = q.front();
                   q.pop();
                   size--;
                   childrenSize = current->children.size();

                   if(childrenSize > maxChildrenSize)
                       {
                           maxChildrenSize = childrenSize;
                            currentMaxNode = current;
                       }


                   for(auto it = current->children.begin(); it != current->children.end(); it++)
                       {
                           q.push(*it);
                       }
                }
        }
    printArr(currentMaxNode->children);
}

void fillTable(std::unordered_map<std::string, int> &words, std::string str)
{
    lowerString(str);
    std::string word;
    for(int i = 0; i < str.size(); i++)
        {
            while(isLetter(str[i]))
                {
                    word+= str[i];
                    i++;
                }
                if(str[i] == ' ')
                    {
                        words[word]++;
                        word = "";
                    }
                else
                    {
                        words[word]++;
                    }
        }


}

void equalWords(std::string str1, std::string str2)
{
    std::unordered_map<std::string, int> words;
    fillTable(words, str1);
    fillTable(words, str2);

    for(auto it = words.begin(); it != words.end(); it++)
        {
            if(it->second >= 2)
                {
                    std::cout<<it->first<<" ";
                }
        }

}


int main()
{
    std::string wordInput = "(king[(are[(you)])(you)(glad[(are)(king)])])";
    WordNode* root = createTree(wordInput);
    printReverse(root);
    std::cout<<std::endl;
    printLargestLevel(root);
    std::cout<<std::endl;
    std::string str = "Hello, World Duck Roger";
    std::string str2 = "Hello, duck roger";
    std::unordered_map<std::string, int> words;
    equalWords(str, str2);





    return 0;
}





