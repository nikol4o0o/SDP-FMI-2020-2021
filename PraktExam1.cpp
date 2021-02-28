#include <iostream>
#include <string>

struct Node
{
    std::string data;
    Node* next;
    Node* prev;

    Node(std::string data, Node* next = nullptr, Node* prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};


void pushBack(Node* &first, std::string data)
{
    Node* curr = first;
    Node* newNode = new Node(data);
    if(first == nullptr)
        {
            first = newNode;
        }
    else
        {
            while(curr->next != nullptr)
                {
                    curr = curr->next;
                }
                curr->next = newNode;
            newNode->prev = curr;
        }
}

void printList(Node* first)
{
    if(first == nullptr)
        {
            return;
        }
        Node* curr = first;
    while(curr != nullptr)
        {
            std::cout<<curr->data<<" ";
            curr = curr->next;
        }
}

void checkFor(Node* &first)
{
    Node* current = first;
    Node* holder = nullptr;
    if(first== nullptr)
        {
            return;
        }

    while(current->next != nullptr)
        {
            holder = current->next;
            if(current == first && (current->data.back() == current->next->data.front()))
                {
                    current->next->prev = nullptr;
                    current->next = nullptr;
                    first = holder;
                    current = holder;
                    continue;
                }
            if(current != first && (current->data.front() == current->prev->data.back()) && (current->next->data.front() == current->data.back())  )
                {
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    delete current;
                    current = holder->next;
                }
            if(current->next == nullptr && (current->prev->data.back() == current->data.front()))
                {
                    current->prev->next = nullptr;
                    delete current;
                }

            else
                {
                    current = holder;
                }


        }
}


int main() {

    Node* list = nullptr;
    Node* list1 = nullptr;
    //pushBack(list, "dog");
    pushBack(list, "dog");
    pushBack(list, "cat");
    pushBack(list, "tacco");
    pushBack(list, "owl");
    pushBack(list, "lemon");

    pushBack(list1, "radar");
    pushBack(list1, "razer");
    pushBack(list1, "raper");
    pushBack(list1, "racer");

    //printList(list);
    checkFor(list);
    checkFor(list1);
    printList(list);
    std::cout<<std::endl;
    printList(list1);
    return 0;
}
