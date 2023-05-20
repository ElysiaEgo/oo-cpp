#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

class Point {
	double x, y;
public:
	Point() {
		this->x = 0, this->y = 0;
		cout << "Constructor." << endl;
	}
	Point(double _x, double _y) {
		this->x = _x, this->y = _y;
		cout << "Constructor." << endl;
	}

	void setXY(double _x, double _y) { this->x = _x, this->y = _y; }
	void setX(double _x) { this->x = _x; }
	void setY(double _y) { this->y = _y; }
	double getDisTo(const Point& point) {
		return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
	}
	~Point() {
		cout << "Distructor." << endl;
	}
};

struct Distance {
	double dis;
	int a;
	int b;
};

int main()
{
	int num;
	cin >> num;
	while (num--) {
		int t;
		cin >> t;
		Point* p = new Point[t];
		Distance* arr = new Distance[t*t];
		for (int i = 0; i < t; i++) {
			double x, y;
			cin >> x >> y;
			p[i].setXY(x, y);
		}
		int offset = 0;
		for (int i = 0; i < t - 1; i++) {
			for (int j = i + 1; j < t; j++) {
				arr[offset] = { p[i].getDisTo(p[j]), i, j };
				offset++;
			}
		}
		sort(arr, arr + t*t, [](Distance& a, Distance& b) -> bool {
			return a.dis > b.dis;
			});
		cout << "The longeset distance is " << fixed << setprecision(2) << arr[0].dis << ",between p[" << arr[0].a << "] and p[" << arr[0].b << "]." << endl;
		delete[] p;
	}
	return 0;
}