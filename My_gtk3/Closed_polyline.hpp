/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Closed_polyline.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 11, 2018, 5:02 PM
 */

#ifndef CLOSED_POLYLINE_HPP
#define CLOSED_POLYLINE_HPP


#include <gtkmm/drawingarea.h>
#include "Shape.hpp"
#include "Open_polyline.hpp"


namespace My_gtk3 {

    class Closed_polyline : public Open_polyline {
    public:
        using Open_polyline::Open_polyline;         // use Open_polyline's constructors
        void draw(const Cairo::RefPtr<Cairo::Context>& cr, double width, double height) const override;
    };

} // namespace My_gtk3

#endif /* CLOSED_POLYLINE_HPP */
