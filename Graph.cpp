#include <iostream>
#include <queue>
#include <vector>
#include <list>

template <class T>
struct Node
{
    T data;
    int id;

    Node(T data, int id)
    {
        this->data = data;
        this->id = id;
    }

    bool operator==(const Node& other)
    {
        return this->data == other.data && this->id == other.id;
    }

};

template <class T>
class Graph
{
private:
    std::list<Node<T>>* adjList;
    int currentID;
    int size;

public:
    Graph(int size)
    {
        this->currentID = 0;
        this->size = size;
        this->adjList = new std::list<Node<T>>[size];
    }

    void addNode(int data)
    {
        Node<T> newNode(data, currentID);
        this->adjList[currentID].push_back(newNode);
        currentID++;
    }

    void addEdge(const Node<T>& from, const Node<T>& to)
    {
        this->adjList[from.id].push_back(to);
    }


    void BFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for(int i = 0; i < size; i++)
            {
                visited[i] = false;
            }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;

        while(!q.empty())
            {
                Node<T> current = q.front();
                q.pop();

                std::cout<<current.data<<" ";

                for(auto it = adjList[current.id].begin(); it != adjList[current.id].end(); it++)
                    {
                        if(visited[it->id] == false)
                            {
                                q.push(*it);
                                visited[it->id] = true;

                            }
                    }

            }
        delete [] visited;
    }

    void DFSHelper(const Node<T> start, bool* &visited)
    {
        std::cout<<start.data<<" ";
        visited[start.id] = true;

        for(auto it = adjList[start.id].begin(); it != adjList[start.id].end(); it++)
            {
                if(!visited[it->id])
                    {
                        visited[it->id] = true;
                        DFSHelper((*it), visited);
                    }

            }

    }

    void DFS(const Node<T>& start)
    {
        bool* visited = new bool[size];
        for(int i = 0; i < size; i++)
            {
                visited[i] = false;
            }

            DFSHelper(start, visited);
    }

    bool hasPath(const Node<T> &start, const Node<T> &end)
    {
        bool *visited = new bool[size];
        for(int i = 0; i < size; i++)
            {
                visited[i] = false;
            }
        std::queue<Node<T>> q;
        q.push(start);
        visited[start.id] = true;

        while(!q.empty())
            {
                Node<T> current = q.front();
                q.pop();

                for(auto it = adjList[current.id].begin(); it != adjList[current.id].end(); it++)
                    {
                        if(*it == end)
                            {
                                return true;
                            }
                        if(!visited[it->id])
                            {
                                visited[it->id] = true;
                                q.push(*it);
                            }
                    }


            }
        return false;
    }


    void allPaths(const Node<T> & start, const Node<T> &end)
    {
        std::queue<std::vector<Node<T> > > q;
        std::vector<Node<T>> path;
        path.push_back(start);
        q.push(path);

        while(!q.empty())
            {
                path = q.front();
                q.pop();

                Node<T> current = path[path.size() - 1];

                if(current == end)
                    {
                        int size = path.size();
                        for(int i = 0; i < size; i++)
                            {
                                std::cout<<path[i].data<<" ";
                            }
                            std::cout<<std::endl;
                    }

                for(auto it = adjList[current.id].begin(); it != adjList[current.id].end(); it++)
                    {
                        if(isNotVisited(*it, path))
                            {
                                std::vector<Node<T>> newPath(path);
                                newPath.push_back(*it);
                                q.push(newPath);
                            }
                    }


            }
    }


    bool isNotVisited(const Node<T>& node, std::vector<Node<T>> vec)
    {
        int size1 = vec.size();
        for (int i = 0; i < size1; ++i)
            {
                if(vec[i] == node)
                    {
                        return false;
                    }
            }
        return true;
    }
};

int main() {
    Graph<int> graph(4);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(5);

    Node<int> v1(1,0), v2(2,1), v3(3,2), v4(5,3);

    graph.addEdge(v1, v2);
    graph.addEdge(v1,v3);
    graph.addEdge(v2, v3);
    graph.addEdge(v3,v1);
    //graph.addEdge(v3,v4);

    graph.BFS(v2);
    std::cout<<"\n";
    graph.DFS(v2);
     std::cout<<graph.hasPath(v1, v4);
    std::cout<<"\n";
    graph.allPaths(v1,v3);

    return 0;
}
