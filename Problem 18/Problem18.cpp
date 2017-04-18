#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Node
{
  public:
    Node *left;
    Node *right;
    int value;
};

Node* createNodesFromString(string line)
{
    int i = 0;
    int j = 0;
    string subString;
    int value;
    Node *nodes = new Node[line.length()/3];
    cout << "LENGTH " << line.length() << endl;
    while (i < line.length()-2)
    {
        subString = line.substr(i, 2);
        cout << subString << endl;
        istringstream buffer(subString);
        buffer >> value;

        Node node;
        node.value = value;
        nodes[j] = node;
        
        j++;
        i+=3;
    }
    
    return nodes;
}

void matchNodes(Node *& nodes1, Node *& nodes2) {
    int size = sizeof(nodes1) / sizeof(Node);
    for (int i; i<size; i++) {
        nodes1[i].left = &nodes2[i];
        nodes1[i].right = &nodes2[i+1];
    }
}

int main()
{
    ifstream inFile;
    string line1;
    string line2;
    inFile.open("C:\\Users\\Titas\\Google Drive\\ProgrammingLanguages\\Project Euler\\Problem 18\\numbers.txt");
    if (inFile.is_open())
    {
        getline(inFile, line1);
        while ((getline(inFile, line2)))
        {
           Node *nodes1, *nodes2;
           nodes1 = createNodesFromString(line1);
           nodes2 = createNodesFromString(line2);
           Node *ptr = nodes1;
           nodes1 = nodes2;
           delete[] ptr;
        }
        
    }
    // todo: need a reference to the root and then we need to define a recursive function to return the max.
    return 0;
}
