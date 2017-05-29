#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Node
{
  public:
    Node *left = NULL;
    Node *right = NULL;
    int value;
};

Node **createNodesFromString(string line)
{
    int i = 0;
    int j = 0;
    string subString;
    int value;
    cout << "STRING BEING USED IS: " << line << endl;
    int length = line.length();
    cout << "STRING LENGTH: " << length << endl;
    Node **nodes = new Node *[(length + 1) / 3];
    while (true)
    {
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        subString = line.substr(i, 2);
        cout << subString << endl;
        istringstream buffer(subString);
        buffer >> value;

        Node *node = new Node();
        node->value = value;
        nodes[j] = node;

        j++;
        i += 3;
        if (j == (length+1)/3) break;
    }

    return nodes;
}

void matchNodes(Node **nodes1, Node **nodes2, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "CURRENT ITERATION FOR MATCHING: " << i << endl;
        cout << "CURRENT NODES IS: " << nodes1[i]->value << endl;
        cout << "LEFT:" << nodes2[i]-> value << " RIGHT: " << nodes2[i+1] -> value << endl;
        nodes1[i]->left = nodes2[i];
        nodes1[i]->right = nodes2[i + 1];
    }
}



int RecursiveTraverse(Node *node, int max)
{

    if (node->left == NULL || node->right == NULL)
        return node->value;

    int left = RecursiveTraverse(node->left, max);
    int right = RecursiveTraverse(node->right, max);
    
    
    if (left > right)
        max = left;
    else if (right >= left)
        max = right;
        
    max += node->value;

    return max;
}

int main()
{
    ifstream inFile;
    string line1;
    string line2;
    inFile.open("numbers.txt");
    Node *root;
    if (inFile.is_open())
    {
        getline(inFile, line1);
            Node **nodes1 = createNodesFromString(line1);
        while ((getline(inFile, line2)))
        {
            Node **nodes2 = createNodesFromString(line2);
            int size  = (line1.length() + 1) / 3;
            if (size == 1) root = nodes1[0];
            matchNodes(nodes1, nodes2, size);
            line1 = line2;
            Node **ptr = nodes1; 
            nodes1 = nodes2;
            delete [] ptr;
        }
    }

    int max = RecursiveTraverse(root, 0);
    cout << "MAX = " << max;
    return 0;
}
