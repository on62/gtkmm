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
        to_fill = false;
    }

    void Line::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->move_to(point(0).x, point(0).y);
        cr->line_to(point(1).x, point(1).y);
        cr->stroke();
 }

} // namespace My_gtk3