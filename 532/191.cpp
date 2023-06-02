#include <iostream>
#include <string>

using namespace std;

class CMoney
{
private:
    int yuan;
    int jiao;
    int fen;
public:
    friend ostream& operator<<(ostream& out, const CMoney& money);
    friend istream& operator>>(istream& in, CMoney& money);
    friend CMoney operator+(const CMoney& a, const CMoney& b);
    friend CMoney operator-(const CMoney& a, const CMoney& b);
};

ostream& operator<<(ostream& out, const CMoney& money)
{
    out << money.yuan << "元" << money.jiao << "角" << money.fen << "分";
    return out;
}

istream& operator>>(istream& in, CMoney& money)
{
    in >> money.yuan >> money.jiao >> money.fen;
    return in;
}

CMoney operator+(const CMoney& a, const CMoney& b)
{
    CMoney c;
    c.yuan = a.yuan + b.yuan;
    c.jiao = a.jiao + b.jiao;
    c.fen = a.fen + b.fen;
    if (c.fen >= 10)
    {
        c.fen -= 10;
        c.jiao++;
    }
    if (c.jiao >= 10)
    {
        c.jiao -= 10;
        c.yuan++;
    }
    return c;
}

CMoney operator-(const CMoney& a, const CMoney& b)
{
    CMoney c;
    c.yuan = a.yuan - b.yuan;
    c.jiao = a.jiao - b.jiao;
    c.fen = a.fen - b.fen;
    if (c.fen < 0)
    {
        c.fen += 10;
        c.jiao--;
    }
    if (c.jiao < 0)
    {
        c.jiao += 10;
        c.yuan--;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        CMoney a, b;
        string op;
        cin >> a;
        while (true) {
            cin >> op;
            if (op == "stop")
            {
                cout << a << endl;
                break;
            }
            cin >> b;
            if (op == "add")
            {
                a = a + b;
            }
            else if (op == "minus")
            {
                a = a - b;
            }
        }
    }
    return 0;
}