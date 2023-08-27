#pragma once
#include <vector>
#include <math.h>
#include "imgui.h"





class Point {
public:
	Point(double x, double y);
	Point(Point&);
	const Point(Point&);
	Point() = default;
	
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


	ImVec2			Vec2();
	void			make_input();
	void			make_output();

private:
	std::vector<double> position{ 0,0 };
	bool input;
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
	bool		is_input() const;
	bool		is_output() const;



	void		set_k1(double);
	void		set_k2(double);
	void		set_initial( Point);
	void		set_final(Point);
	

private:
	Point initial;
	Point final;
	float k1{0.4};
	float k2{0.01};
	

};

