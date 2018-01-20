/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Function.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 19, 2018, 11:59 PM
 */

#ifndef FUNCTION_HPP
#define FUNCTION_HPP


#include <gtkmm/drawingarea.h>
#include <cmath>
#include "Shape.hpp"

namespace My_gtk3 {

    typedef double Fct(double);

    class Function : public Shape {
        // the function parameters are not stored

    public:
        Function(Fct f, double r1, double r2, Point oxy, int count = 100, double xscale = 25, double yscale = 25);
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;

    private:
        Point orig;
    };


    // define some functions to use:
    double one(double x);
    double slope(double x);
    double sloping_cos(double x);
    double square(double x);


} // namespace My_gtk3

#endif /* FUNCTION_HPP */
