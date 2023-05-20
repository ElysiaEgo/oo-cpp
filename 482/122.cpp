#include<iostream>
using namespace std;

class Television
{
    private:
    int number;
    int volume;
    int mode;
    int channel;
    static int tvNum;
    static int dvdNum;
    public:
    friend void remote(Television* tv, int mode, int deltaVolume, int channel);
    Television(int number, int mode, int channel)
    {
        this->number = number;
        this->mode = mode;
        this->channel = channel;
        this->volume = 50;
    }
    void print()
    {
        cout << "第" << this->number << "号电视机--"
        << (this->mode == 1 ? "TV" : "DVD") << "模式"
        << "--频道" << this->channel
        << "--音量" << this->volume << endl;
    }
    static void setTvNum(int num)
    {
        Television::tvNum = num;
    }
    static void printInfo()
    {
        cout << "播放电视的电视机数量为" << Television::tvNum << endl
        << "播放DVD的电视机数量为" << Television::dvdNum << endl;
    }
};

void remote(Television* tv, int mode, int deltaVolume, int channel)
{
    if (tv->mode != mode)
    {
        if (mode == 1)
        {
            tv->tvNum++, tv->dvdNum--;
        }
        else
        {
            tv->tvNum--, tv->dvdNum++;
        }
    }
    tv->mode = mode;
    if (mode == 1)
    {
        tv->channel = channel;
    }
    else
    {
        tv->channel = 99;
    }
    tv->volume += deltaVolume;
    if (tv->volume > 100) tv->volume = 100;
    if (tv->volume < 0) tv->volume = 0;
    tv->print();
}

int Television::tvNum = 0;
int Television::dvdNum = 0;

int main() {
    int num;
    cin >> num;
    Television::setTvNum(num);
    auto tvs = new Television*[num];
    for (int i = 0; i < num; i++)
    {
        tvs[i] = new Television(i + 1, 1, i + 1);
    }
    int times;
    cin >> times;
    while (times--)
    {
        int ind, mod, channel, vol;
        cin >> ind >> mod >> channel >> vol;
        remote(tvs[ind - 1], mod, vol, channel);
    }
    Television::printInfo();
    for (int i = 0; i < 10; i++)
    {
        delete tvs[i];
    }
    delete[] tvs;
    return 0;
}