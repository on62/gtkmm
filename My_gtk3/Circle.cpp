/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Circle.hpp"


namespace My_gtk3 {

    Circle::Circle(double cx, double cy, double rr)
        : radius{rr}
    {
        to_fill = false;
        add(Point{cx, cy});
        default_color();
    }

    Circle::Circle(Point cc, double rr)
        : radius{rr}
    {
        to_fill = false;
        add(cc);
        default_color();
    }

    void Circle::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->arc(point(0).x, point(0).y, radius, 0.0, 2 * M_PI);
        if(to_fill) {
            cr->set_fill_rule(Cairo::FillRule::FILL_RULE_EVEN_ODD);
            cr->fill_preserve();
        }
        cr->stroke();
    }

} // namespace My_gtk3
