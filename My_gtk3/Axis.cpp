/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Axis.hpp"


namespace My_gtk3 {

    Axis::Axis(Orientation d, Point xy, int length, int number_of_notches, std::string lbl)
        : label{lbl, xy,  "Source Code Pro", Pango::WEIGHT_NORMAL}
    {
        if(length < 0) throw std::runtime_error("bad axis length");
        switch(d) {
        case Axis::x:
        {
            notches.add(xy, Point{xy.x + length, xy.y});    // axis line
            if(0 < number_of_notches) {                     // add notches
                double dist = (double)length / (double)number_of_notches;
                double x = xy.x + dist;
                for(int i = 0; i < number_of_notches; ++i) {
                    notches.add(Point{x, xy.y}, Point{x, xy.y - 5});
                    x += dist;
                }
            }
            label.move(length / 3, xy.y + 20);              // label under the line
            break;
        }
        case Axis::y:
        {
            notches.add(xy, Point{xy.x, xy.y - length});    // a y-axis goes up
            if(0 < number_of_notches) {                     // add notches
                double dist = (double)length / (double)number_of_notches;
                double y = xy.y - dist;
                for(int i = 0; i < number_of_notches; ++i) {
                    notches.add(Point{xy.x, y}, Point{xy.x + 5, y});
                    y -= dist;
                }
            }
            label.move(xy.x - 10, xy.y - length - 10);      // label at top
            break;
        }
        case Axis::z:
            throw std::runtime_error("z axis not implemented");
        }
    }

    void Axis::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        label.draw_specific(cr, area, width, height);       // use Axis color
        notches.draw_specific(cr, area, width, height);     // use Axis color
    }

} // namespace My_gtk3
