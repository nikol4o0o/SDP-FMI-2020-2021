#include <iostream>


using namespace std;
struct Node
{
    Node* next;
    Node* prev;
    int data;

    Node(int data, Node* next = nullptr, Node* prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

};

int findMinMax(Node* &first)
{
    Node* current = first;
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    while(current != nullptr)
        {
            if(current->data > maximum)
                {
                    maximum = current->data;
                }
            if(current->data < minimum)
                {
                    minimum = current->data;
                }
                current = current->next;
        }

        int target = maximum - minimum;
    return target;
}

void pushBack(Node* &first, int data)
{

    Node* newNode = new Node(data);
    if(first == nullptr)
        {
            first = newNode;
        }
        else
        {
            Node *curr = first;
            while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
            curr->next = newNode;
            newNode->prev = curr;
        }
}

void printNode(Node* &first)
{
    Node* current = first;
    if(current == nullptr)
        {
            return;
        }
    else
        {
            while(current != nullptr)
                {
                    cout<<current->data<<endl;
                    current = current->next;
                }
        }
}

void deleteAverage(Node* &first)
{
    Node* current = first;
    Node* holder = nullptr;
    if (first == nullptr || first->next == nullptr || first->next->next == nullptr)
        {
            return;
        }


    while(current->next->next != nullptr)
        {
            holder = current->next;
            if(current->data == (current->next->next->data + current->next->data)/2)
                {
                    if(current == first)
                        {
                            current->next->prev = nullptr;
                            first = current->next;
                        }
                    else
                        {
                            current->next->prev = current->prev;
                            current->prev = current->next;

                        }
                   delete current;
                }
            current = holder;
        }
}

void deleteSum(Node* &first)
{
    int target = findMinMax(first);
    Node* current = first;
    Node* holder = nullptr;
    if(first == nullptr)
        {
            return;
        }
        else
        {
            while(current != nullptr)
                {
                    holder = current->next;
                    if(current->data == target)
                        {
                            if(current == first)
                                {
                                    current->next->prev = nullptr;
                                    first = current->next;
                                }
                                else if(current->next == nullptr)
                                {
                                    current->prev->next = nullptr;
                                }
                            else
                                {
                                    current->next->prev = current->prev;
                                    current->prev = current->next;

                                }
                            delete current;
                        }
                    current = holder;
                }
        }
}

int main()
{
    Node* list = nullptr;
    pushBack(list, 1);
    pushBack(list, 2);
    pushBack(list, 0);
    pushBack(list, 4);
    printNode(list);
    //deleteAverage(list);
    deleteSum(list);
    printNode(list);

    return 0;
}
