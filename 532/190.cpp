#include<iostream>
#include<string>

using namespace std;

class CXGraph
{
private:
    int n;
public:
    CXGraph(int n)
    {
        this->n = n;
    }
    friend ostream& operator<<(ostream& out, const CXGraph& xGraph);
    friend CXGraph operator++(CXGraph& xGraph);
    friend CXGraph operator--(CXGraph& xGraph);
    friend CXGraph operator++(CXGraph& xGraph, int);
    friend CXGraph operator--(CXGraph& xGraph, int);
};

ostream& operator<<(ostream& out, const CXGraph& xGraph)
{
    int i, j;
    for (i = 0; i < xGraph.n; i++)
    {
        for (j = 0; j < xGraph.n; j++)
        {
            if (j >= i && j < xGraph.n - i || j <= i && j >= xGraph.n - i - 1)
            {
                cout << "X";
            }
            else
            {
                if (j < xGraph.n - i - 1)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return out;
}

CXGraph operator++(CXGraph& xGraph)
{
    if (xGraph.n < 21)
    {
        xGraph.n += 2;
    }
    return xGraph;
}

CXGraph operator--(CXGraph& xGraph)
{
    if (xGraph.n > 1)
    {
        xGraph.n -= 2;
    }
    return xGraph;
}

CXGraph operator++(CXGraph& xGraph, int)
{
    CXGraph temp(xGraph.n);
    if (xGraph.n < 21)
    {
        xGraph.n += 2;
    }
    return temp;
}

CXGraph operator--(CXGraph& xGraph, int)
{
    CXGraph temp(xGraph.n);
    if (xGraph.n > 1)
    {
        xGraph.n -= 2;
    }
    return temp;
}

int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}