/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Grid.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on January 11, 2018, 1:09 AM
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <gtkmm/drawingarea.h>
#include "Shape.hpp"


namespace My_gtk3 {

    class Grid : public Shape {
    public:
        Grid();
        Grid(int ncols, int nrows);     // initialize columns and rows
        using Shape::set_color;
        void draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area,  double width, double height) const override;
        void set_cols(int new_cols);    // how many columns
        void set_rows(int new_rows);    // how many rows
    private:
        bool is_valid();
        int cols;
        int rows;
    };

} // namespace My_gtk3

#endif /* GRID_HPP */
