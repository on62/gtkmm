/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Rectangle.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 11, 2018, 5:30 PM
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include <gtkmm/drawingarea.h>
#include "Shape.hpp"


namespace My_gtk3 {

    class Rectangle : public Shape {
    public:
        Rectangle(Point tl, double ww, double hh);
        Rectangle(Point tl, Point rb);
        using Shape::set_color;
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
    private:
        bool is_valid();
        double h;      // height
        double w;      // width
    };

} // namespace My_gtk3


#endif /* RECTANGLE_HPP */
