/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cairomm/context.h>
#include "Lines.hpp"
#include "Shape.hpp"


namespace My_gtk3 {

    Lines::Lines() {
        default_color();
    }

    Lines::Lines(std::initializer_list<std::pair<Point, Point>> lst) {  // initialize from a list of points
        for(auto p : lst)
            add(p.first, p.second);
        default_color();
    }

    void Lines::draw(const Cairo::RefPtr<Cairo::Context>& cr, double width, double height) const {

        cr->set_line_width(1.0);
        cr->set_source_rgb(color().r, color().g, color().b);

        for (int i = 1; i < number_of_points(); i += 2) {
            cr->move_to(point(i-1).x, point(i-1).y);
            cr->line_to(point(i).x, point(i).y);
            cr->stroke();
        }
    }

    void Lines::add(Point p1, Point p2) {                               // add a line
        Shape::add(p1);
        Shape::add(p2);
    }

} // namespace My_gtk3
