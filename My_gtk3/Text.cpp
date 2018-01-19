/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Text.hpp"


namespace My_gtk3 {

    Text::Text(std::string msg)
        : message{msg}, font_family{"Monospace"}, font_weight{Pango::WEIGHT_BOLD}
    {
        add(Point{0.0, 0.0});
        default_color();
        to_fill = false;
    }

    Text::Text(std::string msg, Point tl)
        : message{msg}, font_family{"Monospace"}, font_weight{Pango::WEIGHT_BOLD}
    {
        add(tl);
        default_color();
        to_fill = false;
    }

    Text::Text(std::string msg, Point tl, std::string ffamily, Pango::Weight fweight)
        : message{msg}, font_family{ffamily}, font_weight{fweight}
    {
        add(tl);
        default_color();
        to_fill = false;
    }

    void Text::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        Pango::FontDescription font;
        font.set_family("Monospace");
        font.set_weight(Pango::WEIGHT_BOLD);
        auto layout = area.create_pango_layout(message);
        layout->set_font_description(font);
        /*
        int text_width;
        int text_height;
        layout->get_pixel_size(text_width, text_height);    //get the text dimensions (updates variables by reference)
        */
        cr->move_to(point(0).x, point(0).y);                // Position the text
        layout->show_in_cairo_context(cr);
    }


} // namespace My_gtk3
