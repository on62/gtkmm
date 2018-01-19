/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ellipse.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 12, 2018, 9:18 PM
 */

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP


#include <gtkmm/drawingarea.h>
#include "Circle.hpp"

namespace My_gtk3 {

    class Ellipse : public Circle {
    public:
        Ellipse(double cx, double cy, double rw, double rh);
        Ellipse(Point cc, double rw, double rh);
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
    private:
        double radius_w;
        double radius_h;
    };

} // namespace My_gtk3

#endif /* ELLIPSE_HPP */
