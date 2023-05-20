#include <iostream>
#include <cstring>

using namespace std;

struct Reseller {
    char *name;
    char *termainl;
    char *op;
    char *issuers;
    char *validity;
    char *cardNumber;
    char *tradeTime;
    char *costs;
};

int main() {
    int times;
    cin >> times;
    Reseller* sellers = new Reseller[times];
    for (int i = 0; i < times; i++) {
        char *name = new char[30];
        char *termainl = new char[30];
        char *op = new char[30];
        char *issuers = new char[30];
        char *validity = new char[30];
        char *cardNumber = new char[30];
        char *tradeTime = new char[30];
        char *costs = new char[30];
        cin >> name >> termainl >> op >> issuers >> validity >> cardNumber >> tradeTime >> costs;
        int length = strlen(cardNumber);
        for (int j = 0; j < length; j++) {
            if (j < 4 || length - j < 5) continue;
            cardNumber[j] = '*';
        }
        sellers[i] = Reseller {
            name,
            termainl,
            op,
            issuers,
            validity,
            cardNumber,
            tradeTime,
            costs
        };
    }
    for (int i = 0; i < times; i++) {
        cout << "Name: " << sellers[i].name << endl;
        cout << "Terminal: " << sellers[i].termainl << " operator: " << sellers[i].op << endl;
        cout << "Card Issuers: " << sellers[i].issuers << " Validity: " << sellers[i].validity << endl;
        cout << "CardNumber: " << sellers[i].cardNumber << endl;
        cout << "Traded: " << sellers[i].tradeTime << endl;
        cout << "Costs: $" << sellers[i].costs << endl;
        if (i != times - 1) cout << endl;
    }
}