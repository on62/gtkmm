/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 8, 2018, 4:08 PM
 */


#include "ExampleWindow.hpp"
#include <gtkmm/application.h>

/*
 *
 */
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    ExampleWindow window;

    //Shows the window and returns when it is closed.
    return app->run(window);
}