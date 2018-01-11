/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Open_polyline.hpp"

namespace My_gtk3 {

        void Open_polyline::add(Point p) {
            Shape::add(p);
        }

    void Open_polyline::draw(const Cairo::RefPtr<Cairo::Context>& cr, double width, double height) const {
        int np = number_of_points();
        if(np < 2)
            return;

        cr->set_line_width(1.0);
        cr->set_source_rgb(color().r, color().g, color().b);

        cr->move_to(point(0).x, point(0).y);
        for(int i = 1; i < np; ++i )
            cr->line_to(point(i).x, point(i).y);
        cr->stroke();
    }

} // namespace My_gtk3