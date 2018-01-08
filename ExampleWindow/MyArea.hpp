/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MyArea.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 8, 2018, 4:07 PM
 */

#ifndef MYAREA_HPP
#define MYAREA_HPP


#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea {
public:
    MyArea();
    virtual ~MyArea();

    void fix_lines(bool fix = true);
    void force_redraw();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    double m_fix;
};


#endif /* MYAREA_HPP */

