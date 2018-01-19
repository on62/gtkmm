/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Ellipse.hpp"


namespace My_gtk3 {

    Ellipse::Ellipse(double cx, double cy, double rw, double rh)
        : Circle(cx, cy, 0.0), radius_w{rw}, radius_h{rh}
    { }

    Ellipse::Ellipse(Point cc, double rw, double rh)
        : Circle(cc, 0.0), radius_w{rw}, radius_h{rh}
    { }


    void Ellipse::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->scale(1.0, radius_h / radius_w);
        cr->arc(point(0).x, point(0).y, radius_w, 0.0, 2 * M_PI);
        if(to_fill) {
            cr->set_fill_rule(Cairo::FillRule::FILL_RULE_EVEN_ODD);
            cr->fill_preserve();
        }
        cr->stroke();
    }

} // namespace My_gtk3
