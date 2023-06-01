#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>

using std::cout, std::cin, std::endl, std::vector, std::string, std::ifstream, std::ofstream;

class CTime
{
private:
    int mainTime[3];
    int milisecond;
public:
    CTime(string time)
    {
        int pos = 0;
        for (int i = 0; i < 3; i++)
        {
            cout << time.substr(pos, 2) << endl;
            mainTime[i] = atoi(time.substr(pos, 2).c_str());
            pos += 3;
        }
        cout << time.substr(pos + 1, 3) << endl;
        milisecond = atoi(time.substr(pos + 1, 3).c_str());
    }
    CTime(int hour, int minute, int second, int milisecond)
    {
        mainTime[0] = hour;
        mainTime[1] = minute;
        mainTime[2] = second;
        this->milisecond = milisecond;
    }
    CTime(const CTime& another)
    {
        for (int i = 0; i < 3; i++)
        {
            mainTime[i] = another.mainTime[i];
        }
        milisecond = another.milisecond;
    }
    void add(long deltaTime)
    {
        long time = toNum() + deltaTime;
        milisecond = time % 1000;
        time /= 1000;
        for (int i = 2; i >= 0; i--)
        {
            mainTime[i] = time % 60;
            time /= 60;
        }
    }
    long toNum()
    {
        long res = 0;
        for (int i = 0; i < 3; i++)
        {
            res += mainTime[i] * pow(60, 2 - i);
        }
        res *= 1000;
        res += milisecond;
        return res;
    }
    string toString()
    {
        string res = "";
        for (int i = 0; i < 3; i++)
        {
            res += std::to_string(mainTime[i]);
            if (i != 2)
            {
                res += ":";
            }
        }
        res += ",";
        res += std::to_string(milisecond);
        return res;
    }
};

class Subtitle
{
private:
    string id;
    vector<string> subs;
    CTime startTime;
    CTime endTime;
public:
    Subtitle(string id, CTime startTime, CTime endTime, vector<string> subs): startTime(startTime), endTime(endTime)
    {
        this->id = id;
        this->subs = subs;
    }
    void print()
    {
        cout << id << endl;
        cout << startTime.toString() << " --> " << endTime.toString() << endl;
        for (int i = 0; i < subs.size(); i++)
        {
            cout << subs[i] << endl;
        }
    }
    void add(long deltaTime)
    {
        startTime.add(deltaTime);
        endTime.add(deltaTime);
    }
    string toString()
    {
        string res = "";
        res += id;
        res += "\n";
        res += startTime.toString();
        res += " --> ";
        res += endTime.toString();
        res += "\n";
        for (int i = 0; i < subs.size(); i++)
        {
            res += subs[i];
            res += "\n";
        }
        res += "\n";
        return res;
    }
};

class Video
{
private:
    vector<Subtitle> subtitles;
public:
    Video() = default;
    void adjustSubtitle(long deltaTime)
    {
        for (int i = 0; i < subtitles.size(); i++)
        {
            subtitles[i].add(deltaTime);
        }
    }
    void readSubtitle(string path)
    {
        ifstream myfile(path);
        if (!myfile)
        {
            cout << "File not found" << endl;
            return;
        }
        string s;
        while (getline(myfile, s))
        {
            string id = s;
            getline(myfile, s);
            int hour1, minute1, second1, milisecond1, hour2, minute2, second2,  milisecond2;
            sscanf(s.c_str(), "%d:%d:%d,%d --> %d:%d:%d,%d", &hour1, &minute1, &second1, &milisecond1, &hour2, &minute2, &second2, &milisecond2);
            auto startTime = CTime(hour1, minute1, second1, milisecond1);
            auto endTime = CTime(hour2, minute2, second2, milisecond2);
            vector<string> subs;
            while (getline(myfile, s))
            {
                if (s.empty() || s == "\n" || s == "\r" || s == "\r\n" || myfile.eof())
                {
                    break;
                }
                subs.push_back(s);
            }
            Subtitle subtitle(id, startTime, endTime, subs);
            subtitles.push_back(subtitle);
        }
        myfile.close();
    }
    void writeSubtitle(string path)
    {
        ofstream myfile(path + ".adj.srt");
        for (int i = 0; i < subtitles.size(); i++)
        {
            myfile << subtitles[i].toString();
        }
        myfile.close();
    }
};

int main()
{
    Video vid = Video();
    vid.readSubtitle("./fireandice.srt");
    int delta;
    cout << "Enter delta: ";
    cin >> delta;
    vid.adjustSubtitle(delta);
    vid.writeSubtitle("./fireandice.srt");
}