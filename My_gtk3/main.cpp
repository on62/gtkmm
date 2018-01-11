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
#include "Shape.hpp"
#include "Lines.hpp"
#include "Grid.hpp"
#include "Open_polyline.hpp"


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

   Grid g1(4, 3);
   g1.set_color(0.0, 0.0, 0.8);
   area.add_shape(&g1);

   Open_polyline opl1{{100, 100}, {150, 200}, {250, 250}, {300, 200}};
   opl1.set_color(0.8, 0.0, 0.0);
   area.add_shape(&opl1);


   win.add(area);
   area.show();

   return app->run(win);
}
