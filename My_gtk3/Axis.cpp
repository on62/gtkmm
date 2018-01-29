/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Axis.hpp"


namespace My_gtk3 {

    Axis::Axis(Orientation d, Point mid, double len, int num_of_notches, std::string lbl)
        : orientation_xyz{d}, middle{mid}, length{len}, number_of_notches{num_of_notches}, label_text{lbl}
    {
        if(length < 0)
            throw std::runtime_error("bad axis length");
    }


    void Axis::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        double mx = middle.x * width;
        double my = middle.y * height;

        Text label{label_text, Point{0, 0},  "Source Code Pro", Pango::WEIGHT_NORMAL};
        int label_height, label_width;
        label.get_text_pixel_size(area, label_width, label_height);

        Lines notches;
        switch(orientation_xyz) {
        case Axis::x:
        {
            double axis_length = length * width;
            double left_x = mx - axis_length / 2;
            double right_x = left_x + axis_length;
            notches.add(Point{left_x,my}, Point{right_x, my});                  // axis line
            if(0 < number_of_notches) {                                         // add notches
                double dist = (double)axis_length / (double)number_of_notches;
                double notch_x = left_x + dist;
                for(int i = 0; i < number_of_notches; ++i) {
                    notches.add(Point{notch_x, my}, Point{notch_x, my - 5});
                    notch_x += dist;
                }
            }
            label.move((right_x - label_width), my);                            // label under the line
            break;
        }
        case Axis::y:
        {
            double axis_length = length * height;
            double top_y = my - axis_length / 2;
            double bottom_y = top_y + axis_length;
            notches.add(Point{mx, top_y}, Point{mx, bottom_y});                 // a y-axis goes up
            if(0 < number_of_notches) {                                         // add notches
                double dist = (double)axis_length / (double)number_of_notches;
                double notch_y = top_y + dist;
                for(int i = 0; i < number_of_notches; ++i) {
                    notches.add(Point{mx, notch_y}, Point{mx + 5, notch_y});
                    notch_y += dist;
                }
            }
            label.move((double)(mx - label_width - 5), top_y);                  // label at top
            break;
        }
        case Axis::z:
            throw std::runtime_error("z axis not implemented");
        }




        label.draw_specific(cr, area, width, height);       // use Axis color
        notches.draw_specific(cr, area, width, height);     // use Axis color
    }

} // namespace My_gtk3
