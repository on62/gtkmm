/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 7, 2018, 6:01 PM
 */

#include "MyArea.hpp"
#include <gtkmm/application.h>
#include <gtkmm/window.h>

int main(int argc, char** argv)
{
   auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window win;
    win.set_title("DrawingArea");
    win.set_size_request(300, 600);
    win.set_border_width(10);

   MyArea area;
   win.add(area);
   area.show();

   return app->run(win);
}
