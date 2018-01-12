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
#include "Closed_polyline.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"


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

    /*
    Lines l1;
    l1.add(Point{10,20}, Point{400, 450});
    l1.add(Point{500,20}, Point{40, 450});
    area.add_shape(l1);

    Grid g1(4, 3);
    g1.set_color(0.0, 0.0, 0.8);
    area.add_shape(g1);

    Open_polyline opl1{{100, 100}, {150, 200}, {250, 250}, {300, 200}};
    opl1.set_color(0.8, 0.0, 0.0);
    area.add_shape(opl1);

    Closed_polyline cpl1{{100, 150}, {150, 250}, {250, 300}, {300, 250}};
    cpl1.set_color(0.8, 0.5, 0.1);
    area.add_shape(cpl1);

    Rectangle rc00{Point{150.0, 100.0}, 200.0, 100.0};
    Rectangle rc11{Point{50.0, 50.0}, Point{250.0, 150.0}};
    Rectangle rc12{Point{50.0, 150.0}, Point{250.0, 250.0}};
    Rectangle rc21{Point{250.0, 50.0}, 200.0, 100.0};
    Rectangle rc22{Point{250.0, 150.0}, 200.0, 100.0};

    rc00.set_color(0.9, 0.9, 0.0);   // yellow
    rc11.set_color(0.0, 0.0, 1.0);   // blue
    rc12.set_color(1.0, 0.0, 0.0);   //red
    rc21.set_color(0.0, 1.0, 0.0);   // green
    rc22.set_color(0.0, 0.0, 0.0);

    rc00.fill(true);
    rc11.fill(true);
    rc12.fill(true);
    rc21.fill(true);
    rc22.fill(false);

    area.add_shape(rc00);
    area.add_shape(rc11);
    area.add_shape(rc12);
    area.add_shape(rc21);
    area.add_shape(rc22);

    rc11.move(400.0, 0.0);
    rc11.set_color(1.0, 1.0, 1.0);

    area.put_on_top(rc00);
    area.move_to_bottom(rc21);
    */

    for(int i = 0; i < 40; ++i) {
        for(int j = 0; j < 40; ++j) {
            Rectangle* sh = new Rectangle{Point{i * 18.0, j * 14.0}, 18.0, 14.0};
            sh->set_color(j/40.0, i/40.0, 0.4);
            sh->fill(true);
            area.add_unnamed_shape(sh);
        }
    }

    Text t1{"Hello", Point{30,20}, "Source Code Pro", Pango::WEIGHT_NORMAL};
    area.add_shape(t1);
    t1.set_color(0.9, 0.9, 0.0);   // yellow

    t1.move(100.0, 50.0);

   win.add(area);
   area.show();

   return app->run(win);
}
