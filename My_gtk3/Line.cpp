/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Line.hpp"

namespace My_gtk3 {

    Line::Line(Point p1, Point p2) {
        add(p1);
        add(p2);
        default_color();
    }

    void Line::draw(const Cairo::RefPtr<Cairo::Context>& cr, double width, double height) const {
        cr->set_line_width(1.0);
        cr->set_source_rgb(color().r, color().g, color().b);
    }

} // namespace My_gtk3