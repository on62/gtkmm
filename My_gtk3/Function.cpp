/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Function.hpp"


namespace My_gtk3 {

    // graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at oxy
    // x coordinates are scaled by xscale and y coordinates scaled by yscale
    Function::Function(Fct f, double r1, double r2, Point oxy, int count, double xscale, double yscale) {
        if(r2-r1 <= 0) throw std::runtime_error("bad graphing range");
        if(count <= 0) throw std::runtime_error("non - positive graphing count");
        orig = oxy;
        double dist = (r2-r1) / count;
        double r = r1;
        for(int i = 0; i < count; ++i) {
            add(Point{r * xscale, f(r) * yscale});
            r += dist;
        }
    }

    // exact copy of Open_polyline::draw_specific()
    void Function::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        int np = number_of_points();
        if(np < 2)
            return;
        double ox = orig.x * width;
        double oy = orig.y * height;
        cr->set_line_width(3.0);
        cr->move_to(ox + point(0).x, oy - point(0).y);
        for(int i = 1; i < np; ++i )
            cr->line_to(ox + point(i).x, oy - point(i).y);
        cr->stroke();
    }



    double one(double x) {
        return 1.0;
    }

    double slope(double x) {
        return x / 2.0;
    }

    double sloping_cos(double x) {
        return std::cos(x)+slope(x);
    }

    double square(double x) {
        return x * x;
    }

} // namespace My_gtk3
