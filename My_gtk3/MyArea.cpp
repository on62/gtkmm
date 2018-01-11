/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "MyArea.hpp"


namespace My_gtk3 {

    MyArea::MyArea() {
        set_size_request(800, 600);
    }

    MyArea::~MyArea() {
        std::cout << unnamed_shapes.size() << " unnamed shapes to destroy\n";
        for(int i = 0; i < unnamed_shapes.size(); ++i)
            delete unnamed_shapes[i];
    }

    void MyArea::add_shape(Shape& sh) {
        shapes.push_back(&sh);
    }

    void MyArea::add_unnamed_shape(Shape* sh) {
        unnamed_shapes.push_back(sh);
    }

    void MyArea::put_on_top(Shape& sh) {
        for(int i = 0; i < shapes.size(); ++i) {
            if(shapes[i] == &sh) {
                shapes.erase(shapes.begin()+i);
                shapes.push_back(&sh);
            }
        }
    }

    void MyArea::move_to_bottom(Shape& sh) {
        for(int i = 0; i < shapes.size(); ++i) {
            if(shapes[i] == &sh) {
                shapes.erase(shapes.begin()+i);
                shapes.insert(shapes.begin(), &sh);
            }
        }
    }

    std::vector<Shape*>& MyArea::unnamed() {
        return unnamed_shapes;
    }

    bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        Gtk::Allocation allocation = get_allocation();
        const double width = (double)allocation.get_width();
        const double height = (double)allocation.get_height();
        // std::cout << "(" << width << ", " << height << ")\n";

        std::cout << shapes.size() << " shapes to draw\n";
        for(Shape* sh : shapes) {
            sh -> draw(cr, width, height);
        }

        std::cout << unnamed_shapes.size() << " unnamed shapes to draw\n";
        for(Shape* sh : unnamed_shapes) {
            sh -> draw(cr, width, height);
        }
        return true;
    }

} // namespace My_gtk3
