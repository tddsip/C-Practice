#include<iostream>
#include<math.h>
#include"MyPoint.h"

using namespace std;

MyPoint::MyPoint(){
	this->mPosX ;
	this->mPosY ;
}
MyPoint::MyPoint(int X, int Y) {
	this->mPosX = X;
	this->mPosY = Y;
}
 void MyPoint::SetX(int X) {
	 this->mPosX = X;
}
 void MyPoint::SetY(int Y) {
	 this->mPosY = Y;
 }
 int MyPoint::GetX() {
	 return this->mPosX;
 }
 int MyPoint::GetY() {
	 return this->mPosY;
 }
void MyPoint::Display() {
	cout << "Possition : X = " << this->mPosX << endl;
	cout << "Possition : Y = " << this->mPosY << endl;
}
float MyPoint::Distance(MyPoint p) {
	return sqrt(pow((p.GetX() - this->mPosX), 2) + pow((p.GetY() - this->mPosY), 2));
}

int main()
{
	MyPoint *point1 = new MyPoint(40, 40);
	MyPoint *point2 = new MyPoint(95, 80);
	cout << "distance 2 point =  " << point1->Distance(*point2) << endl;
	system("pause");
	return 0;
}
