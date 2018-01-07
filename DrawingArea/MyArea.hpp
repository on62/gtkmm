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

#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea {
public:
    MyArea();
    virtual ~MyArea();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};


#endif /* MYAREA_HPP */

