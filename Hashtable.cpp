#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z' )|| (c >= 'A' && c <= 'Z' );
}

void addPepople(const std::string &lineRead, std::unordered_map<std::string, int> & mentionedPeople)
{
    std::string name;
    int size = lineRead.size();
    for(int i = 0; i < size; i++)
        {
            if(lineRead[i] == '@')
                {
                    i++;
                    while(isLetter(lineRead[i]))
                        {
                            name+=lineRead[i];
                            i++;
                        }
                        mentionedPeople[name]++;
                        name = "";
                }
        }


}

void readFromFile(std::string fileName, std::unordered_map<std::string, int> &mentionedPeople)
{
    std::ifstream inputFile(fileName);

    if(!inputFile.is_open())
        {
            std::cout<<"Error during the opening"<<std::endl;
            return;
        }
    std::string lineRead;
    while(std::getline(inputFile, lineRead))
        {
            addPepople(lineRead, mentionedPeople);
        }

    inputFile.close();
}

void generateVector(std::string str, std::unordered_map<std::string, int> &vector)
{
    int size = str.size();
    std::string wordToken;
    for(int i = 0; i < size-1; i++)
        {
            wordToken = str.substr(i, 2);
            vector[wordToken]++;
        }

}


void sumVector(std::unordered_map<std::string, int> &vector)
{
    int sum = 0;

    for(auto it = vector.begin(); it != vector.end(); it++)
        {
            std::cout<<it->first<<"  "<<it->second<<std::endl;
            sum+=(it->second)*(it->second);
        }

        std::cout<<sqrt(sum);
}

int main() {

    std::unordered_map<std::string, int> mentioned;

    readFromFile("Doc.txt",mentioned);

    std::string name;
    std::cout<<"Enter word"<<std::endl;
    std::cin>>name;

    /*if(mentioned.find(name) != mentioned.end())
        {
            std::cout<<name<<" is mentioned: "<<mentioned[name]<<" times"<<std::endl;
        }
    else
        {
            std::cout<<"Not mentioned"<<std::endl;
        }
*/

    std::unordered_map<std::string, int> vector;
    generateVector(name, vector);
    sumVector(vector);
    return 0;
}
