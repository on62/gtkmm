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
#include <cmath>
#include <complex>
#include <initializer_list>
#include "MyArea.hpp"
#include "Shape.hpp"
#include "Lines.hpp"
#include "Grid.hpp"
#include "Open_polyline.hpp"
#include "Closed_polyline.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"
#include "Circle.hpp"
#include "Ellipse.hpp"
#include "Image.hpp"
#include "Function.hpp"
#include "Axis.hpp"


using namespace My_gtk3;

/* factorial(n) ; n! */
int fac(int n) {
    int r = 1;
    while(n > 1) {
        r *= n;
        --n;
    }
    return r;
}

/* The nth term of series */
double term(double x, int n) {
    return std::pow(x, n) / fac(n);
}

/**/
double expe(double x, int n) {
    double sum = 0;
    for(int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

int expN_number_of_terms = 10;
double expN(double x) {
    return expe(x, expN_number_of_terms);
}


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
    l1.add(Point{10, 20}, Point{400, 450});
    l1.add(Point{500, 20}, Point{40, 450});
    l1.set_color(0.0, 0.7, 0.3);
    area.add_shape(l1);

    Grid g1(4, 3);
    g1.set_color(0.0, 0.0, 0.8);
    area.add_shape(g1);

    Text t1{"Hello World", Point{30, 20}, "Source Code Pro", Pango::WEIGHT_NORMAL};
    t1.set_color(0.9, 0.9, 0.0); // yellow
    t1.move(100.0, 50.0);
    t1.get_text_height(area);
    area.add_shape(t1);
    t1.get_text_width(area);

    Image img1{"fract0.png", Point{400.0, 300.0}, 100.0};
    area.add_shape(img1);

    Open_polyline opl1{
        {100, 100},
        {150, 200},
        {250, 250},
        {300, 200}};
    opl1.set_color(0.8, 0.0, 0.0);
    area.add_shape(opl1);

    Closed_polyline cpl1{
        {100, 150},
        {150, 250},
        {250, 300},
        {300, 250}};
    cpl1.set_color(0.8, 0.5, 0.1);
    area.add_shape(cpl1);

    Rectangle rc00{Point{150.0, 100.0}, 200.0, 100.0};
    Rectangle rc11{Point{50.0, 50.0}, Point{250.0, 150.0}};
    Rectangle rc12{Point{50.0, 150.0}, Point{250.0, 250.0}};
    Rectangle rc21{Point{250.0, 50.0}, 200.0, 100.0};
    Rectangle rc22{Point{250.0, 150.0}, 200.0, 100.0};

    rc00.set_color(0.9, 0.9, 0.0);      // yellow
    rc11.set_color(0.0, 0.0, 1.0);      // blue
    rc12.set_color(1.0, 0.0, 0.0);      // red
    rc21.set_color(0.0, 1.0, 0.0);      // green
    rc22.set_color(0.0, 0.0, 0.0);      // white

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

    Circle circ1{Point{340, 430}, 25};
    circ1.set_color(0.1, 0.7, 0.2);
    circ1.fill(true);
    area.add_shape(circ1);

    Ellipse el1{Point{400, 330}, 50, 42};
    el1.set_color(0.1, 0.6, 0.5);
    el1.fill(true);
    area.add_shape(el1);

    for(int i = 0; i < 40; ++i) {
        for(int j = 0; j < 40; ++j) {
            Rectangle* sh = new Rectangle{Point{i * 18.0, j * 14.0}, 18.0, 14.0};
            sh->set_color(j/40.0, i/40.0, 0.4);
            sh->fill(true);
            area.add_unnamed_shape(sh);
        }
    }

    Function f1{std::cos, -10, 10, Point{0.5, 0.5}};
    f1.set_color(0.1, 0.5, 0.9);
    area.add_shape(f1);

    Function f2{one, -100, 100, Point{0.5, 0.7}};
    f2.set_color(0.9, 0.5, 0.3);
    area.add_shape(f2);

    Function f3{slope, -20, 20, Point{0.5, 0.3}};
    f3.set_color(0.1, 0.9, 0.9);
    area.add_shape(f3);

    Function f4{sloping_cos, -20, 20, Point{0.5, 0.3}};
    f4.set_color(0.8, 0.9, 0.9);
    area.add_shape(f4);

    Function f5{square, -10, 10, Point{0.3, 0.3}};
    f5.set_color(1.8, 0.2, 0.1);
    area.add_shape(f5);

    Function f6{std::sqrt, 0, 30, Point{0.2, 0.7}};
    f6.set_color(0.1, 0.9, 0.2);
    area.add_shape(f6);

    Function f7{std::log, 0.000001, 30, Point{0.1, 0.8}};
    f7.set_color(1, 0, 0);
    area.add_shape(f7);

    Function f8{std::exp, -10, 10, Point{0.2, 0.8}};
    f8.set_color(1, 0, 0);
    area.add_shape(f8);

    Function f9{ [](double x) { return std::exp(x) + std::sin(x); }, -10, 10, Point{0.5, 0.8}, 100, 25, 25};
    f9.set_color(1, 0, 0);
    area.add_shape(f9);

    Function f10{ [](double x)->double { return slope(x) + std::sin(x); }, -20, 20, Point{0.5, 0.5}};
    f10.set_color(0, 1, 0);
    area.add_shape(f10);

    */

    Axis xx{Axis::x, Point{0.5, 0.5}, 0.9, 50, "x axis"};
    xx.set_color(1, 1, 0.1);
    area.add_shape(xx);

    Axis yy{Axis::y, Point{0.5, 0.5}, 0.9, 50, "y axis"};
    yy.set_color(1, 1, 0.5);
    area.add_shape(yy);

    Function real_exp{std::exp, -10, 10, Point{0.5, 0.5}, 100, 50, 1};
    real_exp.set_color(0.1, 0.5, 1.0);
    area.add_shape(real_exp);

    int maxN = 18;
    for(int n = 0; n < maxN; ++n) {
        expN_number_of_terms = n;
        Function* fn = new Function{expN, -10, 10, Point{0.5, 0.5}, 100, 50, 1};
        fn->set_color((double)expN_number_of_terms / (double)maxN, (double)(maxN - expN_number_of_terms) / (double)maxN, 0.1);
        area.add_unnamed_shape(fn);
    }


    win.add(area);
    area.show();

    return app->run(win);
}
