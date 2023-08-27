#include "Coordinate_Math_2D.h"




Point::Point(double x, double y, Flow_Type flow)
{
	this->set_x(x);
	this->set_y(y);
	this->flow = flow;
	this->nodePoint = true;
}

Point::Point(double x, double y)
{
	this->set_x(x);
	this->set_y(y);
	this->nodePoint = false;
}

Point::Point(Point& p)
{
	this->set_x(p.get_x());
	this->set_y(p.get_y());
}

Point::Point()
{
}

Point::Point(ImVec2 v):Point(v.x, v.y)
{
	

}

double Point::displacement(Point p) const
{
	return sqrt(pow(this->get_x() - p.get_x(), 2) + pow(this->get_y() - p.get_y(), 2));
}




double Point::displacement_from_origin() const
{
	return sqrt(pow(this->get_x() - 0, 2) + pow(this->get_y() - 0, 2));
}

double Point::get_x() const
{
	return this->position[0];
}


double Point::get_y() const
{
	return this->position[1];
}

void Point::set_x(double x)
{
	this->position[0]=x;
}

void Point::set_y(double y)
{
	this->position[1] = y;
}

bool Point::to_above_of(Point p) const
{
	return this->get_y() >= p.get_y();
}

bool Point::to_below_of(Point p) const
{
	return !Point::to_above_of(p);
}

bool Point::to_right_of(Point p) const
{
	return this->get_x() >= p.get_x();
}

bool Point::to_left_of(Point p) const
{
	return !Point::to_right_of(p);
}

Flow_Type Point::get_flow_type() const
{
	return this->flow;
}

Point Point::operator+(Point p)
{
	return Point(this->get_x()+p.get_x(),this->get_y()+p.get_y());
}

Point Point::operator-(Point p)
{
	return Point(this->get_x() - p.get_x(), this->get_y() - p.get_y());
}



ImVec2 Point::Vec2()
{
	return ImVec2((float)this->get_x(),(float)this->get_y());
}











BezierCurveCubic::BezierCurveCubic(const Point& initial, const Point & final, float k1 , float k2)
{
	this->initial = initial;
	this->final = final;
	this->k1 = k1;
	this->k2 = k2;
}

Point BezierCurveCubic::linear_bezier_interpolation(Point initial, Point final, double t)
{
	double x = (1 - t) * initial.get_x() + t * final.get_x();
	double y = (1 - t) * initial.get_y() + t * final.get_y();
	return Point(x,y);
}

Point BezierCurveCubic::quadratic_bezier_interpolation(Point initial, Point between, Point final, double t)
{
	Point a = linear_bezier_interpolation(initial, between, t);
	Point b = linear_bezier_interpolation(between,final, t);
	Point result = linear_bezier_interpolation(a,b, t);

	return result;
}

Point BezierCurveCubic::cubic_bezier_interpolation(Point initial, Point initialCotrolPoint, Point finalControlPoint, Point final, double t)
{	
	Point a = quadratic_bezier_interpolation(initial, initialCotrolPoint, finalControlPoint, t);
	Point b = quadratic_bezier_interpolation(initialCotrolPoint, finalControlPoint, final, t);
	Point result = linear_bezier_interpolation(a, b, t);
	return result;
}




Point BezierCurveCubic::interpolate(double t)
{
	double delX, delY;
	double disp = this->initial.displacement(final);

	if (this->initial.to_above_of(final))
		delY = - disp * this->get_k2();
	else
		delY = disp * this->get_k2();

	if (this->initial.get_flow_type() == INPUT_PIN)
		delX = -disp * this->get_k1();
	else
		delX = disp * this->get_k1();

	Point delP(delX, delY);
	Point a = initial + delP;
	Point b = final - delP;
	return this->cubic_bezier_interpolation(this->initial, a, b, final, t);
}













double BezierCurveCubic::get_k1() const
{
	return this->k1;
}

double BezierCurveCubic::get_k2() const
{
	return this->k2;
}

Point BezierCurveCubic::get_initial() const
{
	return Point(this->initial.get_x(), this->initial.get_y());
}

Point BezierCurveCubic::get_final() const
{
	return Point(this->final.get_x(), this->final.get_y());
}

void BezierCurveCubic::set_k1(double k)
{
	this->k1 = k;
}

void BezierCurveCubic::set_k2(double k)
{
	this->k2 = k;
}

void BezierCurveCubic::set_initial(Point p)
{
	this->initial = p;
}

void BezierCurveCubic::set_final(Point p)
{
	this->final = p;
}


