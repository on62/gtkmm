/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Grid.hpp"


namespace My_gtk3 {

    Grid::Grid()
        : cols{10}, rows{10}
    {
            is_valid();
            default_color();
            to_fill = false;
    }

    Grid::Grid(int ncols, int nrows)
        : cols{ncols}, rows{nrows}
    {
            is_valid();
            default_color();
            to_fill = false;
    }

    void Grid::draw_specific(const Cairo::RefPtr<Cairo::Context>& cr, Gtk::DrawingArea& area, double width, double height) const {
        double x_step = width / cols;
        double y_step = height / rows;
        for(double x = 0.0; x < width; x += x_step) {
            cr->move_to(x, 0.0);
            cr->line_to(x, height);
        }
        for(double y = 0.0; y < height; y += y_step) {
            cr->move_to(0.0, y);
            cr->line_to(width, y);
        }
        cr->stroke();
    }

    void Grid::set_cols(int new_cols) {
        cols = new_cols;
        is_valid();
    }

    void Grid::set_rows(int new_rows) {
        rows = new_rows;
        is_valid();
    }

    bool Grid::is_valid() {
        if(cols <= 0)
            cols = 10;
        if(rows <= 0)
            rows = 10;
        return true;
    }

} // namespace My_gtk3
