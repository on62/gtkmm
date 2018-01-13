/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Circle.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 12, 2018, 6:57 PM
 */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <gtkmm/drawingarea.h>
#include "Shape.hpp"

namespace My_gtk3 {

    class Circle : public Shape {
    public:
        Circle(double cx, double cy, double rr);
        Circle(Point cc, double rr);
        void draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
    private:
        double radius;
    };

} // namespace My_gtk3

#endif /* CIRCLE_HPP */

