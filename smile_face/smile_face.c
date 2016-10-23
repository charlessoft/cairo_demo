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

int test_arc(int canve_nwidth, int canve_nheight) {
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, canve_nwidth, canve_nheight);
    cairo_t *cr = cairo_create(surface);
    cairo_set_line_width(cr, 1.0);

    cairo_set_source_rgb(cr, 0.69, 0.19, 0);

// 填充圆形
    cairo_arc(cr, canve_nwidth / 2, canve_nheight / 2,
              (canve_nwidth < canve_nheight ? canve_nwidth : canve_nheight) / 2 - 10, 0,
              2 * M_PI);

    cairo_fill(cr);

    cairo_set_source_rgb(cr, 0.3, 0.5, 1);
    double angle1 = 0 * (M_PI / 180.0);
    double angle2 = 2*M_PI;//360.0 * (M_PI / 180.0);
    //face

//    cairo_save(cr);
//    cairo_scale(cr, 1, 0.7); //椭圆

    cairo_arc(cr, canve_nwidth / 2, canve_nheight / 2, canve_nheight / 2, angle1, angle2);

//    cairo_restore(cr);

    //eyes
    struct point left_eye_pt = {
            .x = canve_nwidth / 7 * 3,
            .y = canve_nheight / 3
    };
    struct point right_eye_pt = {
            .x =  canve_nwidth / 7 * 4,
            .y = canve_nheight / 3
    };

    //mouth
    struct point mouth_pt = {
            .x = canve_nwidth / 2,
            .y=canve_nheight / 7 * 5
    };


    cairo_move_to(cr, left_eye_pt.x, left_eye_pt.y);
    cairo_arc(cr, left_eye_pt.x, left_eye_pt.y, canve_nheight / 10, angle1, angle2);

    cairo_move_to(cr, right_eye_pt.x, right_eye_pt.y);
    cairo_arc(cr, right_eye_pt.x, right_eye_pt.y, canve_nheight / 10, angle1, angle2);

    //mouth
    cairo_move_to(cr, mouth_pt.x, mouth_pt.y);
    cairo_arc(cr, mouth_pt.x, mouth_pt.y, canve_nheight / 10, angle1, M_PI / 180.0 * 180);

    cairo_stroke(cr);

    cairo_destroy(cr);
    cairo_surface_write_to_png(surface, "smile_face.png");
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