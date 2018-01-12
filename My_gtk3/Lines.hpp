/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lines.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 10, 2018, 12:47 PM
 */

#ifndef LINES_HPP
#define LINES_HPP

#include <initializer_list>
#include <algorithm>
#include <gtkmm/drawingarea.h>
#include "Shape.hpp"


namespace My_gtk3 {

    class Lines : public Shape {
    public:
        Lines();
        Lines(std::initializer_list<std::pair<Point, Point>> lst);  // initialize from a list of points
        void draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
        void add(Point p1, Point p2);                               // add a line
    };

} // namespace My_gtk3

#endif /* LINES_HPP */
