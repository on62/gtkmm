/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Image.hpp"
#include <gdkmm/general.h> // set_source_pixbuf()

namespace My_gtk3 {

    Image::Image(std::string img_path, Point tl, double rr) {
        add(tl);
        image = Gdk::Pixbuf::create_from_file(img_path);
        to_fill = false;
        default_color();
    }

    void Image::draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->save();
        Gdk::Cairo::set_source_pixbuf(cr, image, point(0).x, point(0).y);
        cr->paint_with_alpha(0.9);
        cr->restore();
    }

} // namespace My_gtk3
