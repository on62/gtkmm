/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Rectangle.hpp"


namespace My_gtk3 {

    Rectangle::Rectangle(Point tl, double ww, double hh)
        : w{ww}, h{hh}
    {
            is_valid();
            add(tl);
            default_color();
            to_fill = false;
    }

    Rectangle::Rectangle(Point tl, Point rb)
        : w{rb.x - tl.x}, h{rb.y - tl.y}
    {
            is_valid();
            add(tl);
            default_color();
            to_fill = false;
    }

    void Rectangle::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->move_to(point(0).x, point(0).y);
        cr->line_to(point(0).x+w, point(0).y);
        cr->line_to(point(0).x+w, point(0).y+h);
        cr->line_to(point(0).x, point(0).y+h);
        cr->line_to(point(0).x, point(0).y);
        if(to_fill) {
            cr->set_fill_rule(Cairo::FillRule::FILL_RULE_EVEN_ODD);
            cr->fill_preserve();
        }
        cr->stroke();
    }

    bool Rectangle::is_valid() {
        if(h <= 0)
            h = 10;
        if(w <= 0)
            w = 0;
        return true;
    }

} // namespace My_gtk3
