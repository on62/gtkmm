/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Closed_polyline.hpp"


namespace My_gtk3 {

    void Closed_polyline::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area,  double width, double height) const {
        int np = number_of_points();
        if(np < 2)
            return;
        Open_polyline::draw_specific(cr, area, width, height);      // draw the open polyline part
        cr->move_to(point(np-1).x, point(np-1).y);
        cr->line_to(point(0).x, point(0).y);        // draw closing line
        cr->stroke();
    }

} // namespace My_gtk3