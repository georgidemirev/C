#pragma once
#include <iostream>
using namespace std;

class Point2D {
private:

	double x;
	double y;

public:

	Point2D(double x = 0, double y = 0) :x(x), y(y) {};
	Point2D(const Point2D&);
	Point2D& operator=(const Point2D &);
	virtual ~Point2D() {};

	const double getX()const { return this->x; };
	const double getY()const { return this->y; };

	void setX(const double x) { this->x = x; };
	void setY(const double y) { this->y = y; };

	virtual double getDistanceTo(Point2D&); // not a const because of dynamic_cast
};

Point2D::Point2D(const Point2D &p)
{
	setX(p.getX());
	setY(p.getY());
}

Point2D & Point2D::operator=(const Point2D & p)
{
	setX(p.getX());
	setY(p.getY());
	return *this;
}

double Point2D::getDistanceTo(Point2D& p) {
	double distance = sqrt(pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2) * 1.0);
	return distance;
}

/////////////////////////////////////////////////////////////////////////////

class Point3D: public Point2D {
private:
	double z;
public:

	Point3D(int x = 0, int y = 0, int z = 0) :Point2D(x, y), z(z) {};
	Point3D(const Point3D&);
	Point3D& operator=(const Point3D&);
	virtual ~Point3D() {};
	
	const double getX()const { return Point2D::getX(); };
	const double getY()const { return Point2D::getY(); };
	const double getZ()const { return this->z; };

	void setX(const double x) { Point2D::setX(x); };
	void setY(const double y) { Point2D::setY(y); };
	void setZ(const double z) { this->z = z; };

	double getDistanceTo(Point2D&) override;// not a const because of dynamic_cast
};

Point3D::Point3D(const Point3D &p) :Point2D(p)
{
	setZ(p.getZ());
}

Point3D & Point3D::operator=(const Point3D & p)
{
	setX(p.getX());
	setY(p.getY());
	setZ(p.getZ());
	return *this;
}

double Point3D::getDistanceTo(Point2D & p)
{
	Point3D* castedP = dynamic_cast<Point3D*>(&p);
	if (castedP != nullptr) {
		double myDistance = sqrt(pow(getX() - p.getX(), 2.0) + pow(getY() - p.getY(), 2.0) + pow(getZ() - castedP->getZ(), 2.0));
		return myDistance;
	}
	else {
		double distance = sqrt(pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2) * 1.0);
		return distance;
	}
}
