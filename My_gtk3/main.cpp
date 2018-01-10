/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 9, 2018, 1:54 AM
 */


#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "MyArea.hpp"
#include "Lines.hpp"

using namespace My_gtk3;

/*
 *
 */
int main(int argc, char** argv) {

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window win;
    win.set_title("Cairo Drawing Area");
    win.set_size_request(800, 600);
    // win.set_border_width(10);

   MyArea area;

   Lines l1;
   l1.add(Point{10,20}, Point{400, 450});
   l1.add(Point{500,20}, Point{40, 450});
   area.add_shape(&l1);

   win.add(area);
   area.show();

   return app->run(win);
}
