#pragma once
#include <vector>
#include <math.h>
#include "imgui.h"



 enum Flow_Type {
	INPUT_PIN,
	OUTPUT_PIN
};



class Point {
public:
	Point(double x, double y, Flow_Type);
	Point(double x, double y);
	Point(Point&);
	Point();
	Point(ImVec2);
	double			displacement(Point) const;
	double			displacement_from_origin() const;
	double			get_x() const;
	double			get_y() const;
	void			set_x(double x);
	void			set_y(double y);

	bool			to_above_of(Point) const;
	bool			to_below_of(Point) const;
	bool			to_right_of(Point) const;
	bool			to_left_of(Point) const;
	Flow_Type		get_flow_type() const;
	
	Point			operator+(Point);
	Point			operator-(Point);
	ImVec2			Vec2();

private:
	std::vector<double> position{ 0,0 };
	Flow_Type flow = INPUT_PIN;
	bool nodePoint  = false;
};



class Line {
public:

private:
	double slope{};
	double intercept{};
};


class BezierCurveCubic {
public:
	BezierCurveCubic(const Point& initial, const Point & final, float k1 = 0.4, float k2 = 0.01);
	Point		linear_bezier_interpolation(Point initial, Point final, double t);
	Point		quadratic_bezier_interpolation(Point initial, Point between, Point final, double t);
	Point		cubic_bezier_interpolation(Point initial, Point initialCotrolPoint, Point finalControlPoint, Point final, double t);
	Point		interpolate(double t);



	double		get_k1() const;
	double		get_k2() const;
	Point		get_initial() const;
	Point		get_final() const;
	



	void		set_k1(double);
	void		set_k2(double);
	void		set_initial( Point);
	void		set_final(Point);
	

private:
	Point initial;
	Point final;
	double k1{0.4};
	double k2{0.01};
	

};

