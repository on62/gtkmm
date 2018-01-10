/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MyArea.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 7, 2018, 5:57 PM
 */

#ifndef MYAREA_HPP
#define MYAREA_HPP


#include <vector>
#include <gtkmm/drawingarea.h>
#include "Lines.hpp"


namespace My_gtk3 {

    class MyArea : public Gtk::DrawingArea {

    public:
        MyArea();
        virtual ~MyArea();

        void add_shape(Shape* sh);

    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override; //Override default signal handler:

    private:
        std::vector<Shape*> shapes;

    };

} // namespace My_gtk3

#endif /* MYAREA_HPP */
