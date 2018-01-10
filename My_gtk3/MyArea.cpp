/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cairomm/context.h>
#include "MyArea.hpp"
#include "Shape.hpp"


namespace My_gtk3 {

    MyArea::MyArea() {
        set_size_request(800, 600);
    }

    MyArea::~MyArea() { }

    void MyArea::add_shape(Shape* sh) {
        shapes.push_back(sh);
    }

    bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        Gtk::Allocation allocation = get_allocation();
        const int width = allocation.get_width();
        const int height = allocation.get_height();
        // std::cout << "(" << width << ", " << height << ")\n";

        // coordinates for the center of the window
        int midx, midy;
        midx = width / 2;
        midy = height / 2;

        std::cout << shapes.size() << " shapes to draw\n";
        for(Shape* sh : shapes) {
            sh -> draw(cr);
        }

        // cr->set_line_width(2.0);
        // draw red lines out from the center of the window
        // cr->set_source_rgb(0.8, 0.0, 0.0);
        // cr->move_to(0, 0);
        // cr->line_to(xc, yc);
        // cr->line_to(0, height);
        // cr->move_to(xc, yc);
        // cr->line_to(width, yc);
        // cr->stroke();

        return true;
    }

} // namespace My_gtk3
