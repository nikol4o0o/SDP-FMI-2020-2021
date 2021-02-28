#include <iostream>
#include <map>

void printAllDiff(int arr[], int size)
{
    int index = 0;
    std::map<int, int> members;
    for(int i = 0; i < size; i++)
        {
            if(members.find(arr[i]) != members.end())
                {
                    members[arr[i]]++;
                }
                else
                {
                    members[arr[i]] = 1;
                }

        }

    for(std::map<int, int >::const_iterator it = members.begin();it != members.end(); ++it)
    {
        std::cout<<it->first<<std::endl;
    }
}

int main() {
    int arr[] = {1,2,2,3,4,5,5};
    std::cout << "Hello, World!" << std::endl;
    printAllDiff(arr, 7);


    return 0;
}
