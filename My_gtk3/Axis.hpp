/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Axis.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 20, 2018, 11:36 PM
 */

#ifndef AXIS_HPP
#define AXIS_HPP


#include <gtkmm/drawingarea.h>
#include "Shape.hpp"
#include "Text.hpp"
#include "Lines.hpp"


namespace My_gtk3 {

    class Axis : public Shape {
    public:
        enum Orientation { x, y, z };
        Axis(Gtk::Widget& gtkw, Orientation d, Point xy, int len, int number_of_notches = 0, std::string lbl = "");
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
        using Shape::set_color;
    private:
        int length;
        Text label;
        Lines notches;
    };

} // namespace My_gtk3

#endif /* AXIS_HPP */

