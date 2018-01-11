/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Open_polyline.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 11, 2018, 1:10 AM
 */

#ifndef OPEN_POLYLINE_HPP
#define OPEN_POLYLINE_HPP


#include <gtkmm/drawingarea.h>
#include "Shape.hpp"


namespace My_gtk3 {

    class Open_polyline : public Shape {

    public:
        using Shape::Shape;         // use Shape's constructors

        using Shape::set_color;

        void add(Point p);
        void draw(const Cairo::RefPtr<Cairo::Context>& cr, double width, double height) const override;

    };

} // namespace My_gtk3


#endif /* OPEN_POLYLINE_HPP */

