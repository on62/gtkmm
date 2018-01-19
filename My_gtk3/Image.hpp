/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Image.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 12, 2018, 10:45 PM
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP


#include <gtkmm/drawingarea.h>
#include "Shape.hpp"

namespace My_gtk3 {

    class Image : public Shape {
    public:
        Image(std::string img_path, Point tl, double rr);
        using Shape::set_color;
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const override;
    private:
        Glib::RefPtr<Gdk::Pixbuf> image;
    };

} // namespace My_gtk3


#endif /* IMAGE_HPP */
