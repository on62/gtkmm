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
        cr->move_to(point(0).x, point(0).y);                // Position the text
        Glib::RefPtr<Pango::Layout> layout = create_layout(area);
        layout->show_in_cairo_context(cr);
    }

    void Text::get_text_pixel_size(Gtk::Widget& gtkw, int& text_width, int& text_height) const {
            //get the text dimensions (updates variables by reference)
            create_layout(gtkw)->get_pixel_size(text_width, text_height);
            // std::cout << "\t(" << text_width << " ," << text_height << ")\n";
    }

    Glib::RefPtr<Pango::Layout> Text::create_layout(Gtk::Widget& gtkw) const {
        Pango::FontDescription font;
        font.set_family(font_family);
        font.set_weight(font_weight);
        Glib::RefPtr<Pango::Layout> layout = gtkw.create_pango_layout(message);
        layout->set_font_description(font);
        return layout;
    }

} // namespace My_gtk3
