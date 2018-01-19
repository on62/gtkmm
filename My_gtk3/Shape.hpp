/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Shape.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 8, 2018, 11:13 PM
 */

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <gtkmm/drawingarea.h>
#include "Point.hpp"
#include "Color_rgb.hpp"


namespace My_gtk3 {

    class Shape {

    public:
        void draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const;
        virtual void move(double x, double y);
        void set_color(double rr, double gg, double bb);    // change color
        void set_color(const Color_rgb& new_color);         // change color
        void default_color();
        Color_rgb color() const;                            // get color
        void fill(bool ff);                                 // fill / un-fill
        Shape(const Shape&) = delete;                       // prevent copying
        Shape& operator=(const Shape&) = delete;
        virtual ~Shape() {}
        Point point(int i) const;
        int number_of_points() const;
        bool to_fill;                               // fill shape ?
    protected:
        Shape();
        Shape(std::initializer_list<Point> lst);    // add() the Points to this
        virtual void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const =0;
        void add(Point p);                          // add p to points
        void set_point(int i, Point p);             // points[i] = p;
    private:
        std::vector<Point> points;                  // not used by all shapes
        Color_rgb the_color;
    };

} // namespace My_gtk3

#endif /* SHAPE_HPP */
