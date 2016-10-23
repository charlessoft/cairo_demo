//
// Created by charles on 16/10/21.
//

#include <stdio.h>
#include <cairo.h>
#include <math.h>

struct point {
    int x;
    int y;
};

static void
draw_round_rectangle (cairo_t * cr,
                      double x, double y,
                      double width, double height, double r)
{
    cairo_move_to (cr, x + r, y);
    cairo_line_to (cr, x + width - r, y);

    cairo_move_to (cr, x + width, y + r);
    cairo_line_to (cr, x + width, y + height - r);

    cairo_move_to (cr, x + width - r, y + height);
    cairo_line_to (cr, x + r, y + height);

    cairo_move_to (cr, x, y + height - r);
    cairo_line_to (cr, x, y + r);

    cairo_arc (cr, x + r, y + r, r, 3.14, 3 * 3.14 / 2.0);
    cairo_arc (cr, x + width - r, y + r, r, 3 * 3.14 / 2, 2 * 3.14);
    cairo_arc (cr, x + width - r, y + height - r, r, 0, 3.14 / 2);
    cairo_arc (cr, x + r, y + height - r, r, 3.14 / 2, 3.14);
}

int test_arc(int canve_nwidth, int canve_nheight) {
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, canve_nwidth, canve_nheight);
    cairo_t *cr = cairo_create(surface);
//    cairo_t *cr;

//    cr = gdk_cairo_create (widget->window);

    cairo_set_source_rgba (cr, 0, 0, 0, 1);

    static const double dashed1[] = { 4.0, 1.0 };
    static int len1 = sizeof (dashed1) / sizeof (dashed1[0]);


    static const double dashed2[] = { 4.0, 10.0, 4.0 };
    static int len2 = sizeof (dashed2) / sizeof (dashed2[0]);

    static const double dashed3[] = { 1.0 };

    cairo_set_line_width (cr, 1.5);

    cairo_set_dash (cr, dashed1, len1, 0);

    cairo_move_to (cr, 40, 60);
    cairo_line_to (cr, 360, 60);
    cairo_stroke (cr);

    cairo_set_dash (cr, dashed2, len2, 10);
    int ndash_count = cairo_get_dash_count(cr);
    printf("ndash_count=%d",ndash_count);

    cairo_move_to (cr, 40, 120);
    cairo_line_to (cr, 360, 120);
    cairo_stroke (cr);

    cairo_set_dash (cr, dashed3, 1, 0);


    cairo_move_to (cr, 40, 180);
    cairo_line_to (cr, 360, 180);
    cairo_stroke (cr);




    //
    cairo_set_source_rgba (cr, 0, 0, 0, 1);
    cairo_set_line_width (cr, 10);

    cairo_set_line_cap (cr, CAIRO_LINE_CAP_BUTT);
    cairo_move_to (cr, 40, 60);
    cairo_line_to (cr, 360, 60);
    cairo_stroke (cr);

    cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
    cairo_move_to (cr, 40, 150);
    cairo_line_to (cr, 360, 150);
    cairo_stroke (cr);

    cairo_set_line_cap (cr, CAIRO_LINE_CAP_SQUARE);
    cairo_move_to (cr, 40, 240);
    cairo_line_to (cr, 360, 240);
    cairo_stroke (cr);
//
    cairo_set_line_width (cr, 1.5);

    cairo_move_to (cr, 40, 40);
    cairo_line_to (cr, 40, 260);
    cairo_stroke (cr);
//
    cairo_move_to (cr, 360, 40);
    cairo_line_to (cr, 360, 260);
    cairo_stroke (cr);

    cairo_move_to (cr, 365, 40);
    cairo_line_to (cr, 365, 260);
    cairo_stroke (cr);




    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, "dash.png");
    cairo_surface_destroy(surface);
    return 0;
}

int main(int argc, const char *argv[]) {

    int canve_nwidth = 600;
    int canve_nheight = 400;
    test_arc(canve_nwidth, canve_nheight);

}

double MIN(int canve_nwidth, int canve_nheight) {
    return 0;
}