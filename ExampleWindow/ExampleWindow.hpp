/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ExampleWindow.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 8, 2018, 4:06 PM
 */

#ifndef EXAMPLEWINDOW_HPP
#define EXAMPLEWINDOW_HPP


#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/checkbutton.h>
#include "MyArea.hpp"

class ExampleWindow : public Gtk::Window {
public:
    ExampleWindow();
    virtual ~ExampleWindow();

protected:
    //Signal handlers:
    void on_button_toggled();

private:
    Gtk::Grid m_Container;
    MyArea m_Area_Lines;
    Gtk::CheckButton m_Button_FixLines;
};


#endif /* EXAMPLEWINDOW_HPP */

