#pragma once
#ifndef my_point
#define my_point
class MyPoint {
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int, int);
	void Display();
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	float Distance(MyPoint);
};
#endif