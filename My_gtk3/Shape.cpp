/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Shape.hpp"


namespace My_gtk3 {

    void Shape::draw(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        cr->save();
        cr->set_line_width(1.0);
        cr->set_source_rgb(color().r, color().g, color().b);

        // std::cout << width << height;
        draw_specific(cr, area, width, height);

        cr->restore();
    }

    Shape::Shape()
        : to_fill{false}
    {
        default_color();
    }

    Shape::Shape(std::initializer_list<Point> lst)
        : to_fill{false}
    {
        for(Point p : lst)
            add(p);
        default_color();
    }

    void Shape::add(Point p) {
        points.push_back(p);
    }

    void Shape::move(double xx, double yy) {
        // std::cout << "moving\n";
        for(Point& p : points) {
            p.x += xx;
            p.y += yy;
        }
    }

    void Shape::set_point(int i, Point p) {
        if(i < 0 || (int)points.size() < i + 1)
            throw std::out_of_range("Point index is out of range");
        points[i] = p;
    }

    Point Shape::point(int i) const {
        if(i < 0 || (int)points.size() < i + 1)
            throw std::out_of_range("Point index is out of range");
        return points[i];
    }

    int Shape::number_of_points() const {
        return points.size();
    }

    void Shape::set_color(double rr, double gg, double bb) {
        the_color.r = rr;
        the_color.g = gg;
        the_color.b = bb;
    }

    void Shape::set_color(const Color_rgb& new_color) {
        the_color.r = new_color.r;
        the_color.g = new_color.g;
        the_color.b = new_color.b;
    }

    void Shape::default_color() {
        the_color.r = 0.0;
        the_color.g = 0.0;
        the_color.b = 0.0;
    }

    Color_rgb Shape::color() const {
        return the_color;
    }

    void Shape::fill(bool ff) {
        to_fill = ff;
    }

} // namespace My_gtk3
