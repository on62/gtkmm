/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Rectangle.hpp"


namespace My_gtk3 {

    Rectangle::Rectangle(Point tl, double ww, double hh)
        : w{ww}, h{hh}, f{false}
    {
            is_valid();
            add(tl);
    }

    Rectangle::Rectangle(Point tl, Point rb)
        : w{rb.x - tl.x}, h{rb.y - tl.y}
    {
            is_valid();
            add(tl);
    }

    void Rectangle::draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->set_line_width(1.0);
        cr->set_source_rgb(color().r, color().g, color().b);
        cr->move_to(point(0).x, point(0).y);
        cr->line_to(point(0).x+w, point(0).y);
        cr->line_to(point(0).x+w, point(0).y+h);
        cr->line_to(point(0).x, point(0).y+h);
        cr->line_to(point(0).x, point(0).y);
        if(f) {
            cr->set_fill_rule(Cairo::FillRule::FILL_RULE_EVEN_ODD);
            cr->fill();
        }
        cr->stroke();
    }

    void Rectangle::fill(bool ff){
        f = ff;
    }


    bool Rectangle::is_valid() {
        if(h <= 0)
            h = 10;
        if(w <= 0)
            w = 0;
        return true;
    }

} // namespace My_gtk3
