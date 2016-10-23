#include <math.h>
#include <cairo.h>

cairo_surface_t *surface1;
cairo_surface_t *surface2;
cairo_surface_t *surface3;
cairo_surface_t *surface4;

static void
create_surfaces ()
{
    surface1 = cairo_image_surface_create_from_png ("Image_1.png");
    surface2 = cairo_image_surface_create_from_png ("Image_2.png");
//    surface3 = cairo_image_surface_create_from_png ("03.png");
//    surface4 =
//            cairo_image_surface_create_from_png ("04.png");
}

static void
destroy_surfaces ()
{

    cairo_surface_destroy (surface1);
    cairo_surface_destroy (surface2);
//    cairo_surface_destroy (surface3);
//    cairo_surface_destroy (surface4);
}

static void
show_two_image()
{
    cairo_t *cr;

    cairo_pattern_t *pattern1;
    cairo_pattern_t *pattern2;
    cairo_pattern_t *pattern3;
    cairo_pattern_t *pattern4;


    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 1024,768);
    cr = cairo_create(surface);

    int width, height;


    pattern1 = cairo_pattern_create_for_surface (surface1);
    pattern2 = cairo_pattern_create_for_surface (surface2);
//    pattern3 = cairo_pattern_create_for_surface (surface3);
//    pattern4 = cairo_pattern_create_for_surface (surface4);


    cairo_set_source (cr, pattern1);
    cairo_pattern_set_extend (cairo_get_source (cr),
                              CAIRO_EXTEND_REFLECT);
    cairo_rectangle (cr,21.935118,8.508533,21.935118+31.743002,8.508533+31.743004);
    cairo_fill (cr);

    cairo_set_source (cr, pattern2);
    cairo_pattern_set_extend (cairo_get_source (cr),
                              CAIRO_EXTEND_REPEAT);
    cairo_rectangle (cr,57.058395,10.317886,57.058395+31.037598,10.317886+27.510601);
    //cairo_arc (cr, 200, 70, 50, 0, 2 * M_PI);
    cairo_fill (cr);

//    cairo_set_source (cr, pattern3);
//    cairo_pattern_set_extend (cairo_get_source (cr),
//                              CAIRO_EXTEND_REPEAT);
//    cairo_rectangle (cr, 20, 140, 100, 100);
//    cairo_fill (cr);
//
//    cairo_set_source (cr, pattern4);
//    cairo_pattern_set_extend (cairo_get_source (cr),
//                              CAIRO_EXTEND_REPEAT);
//    cairo_rectangle (cr, 150, 140, 100, 100);
//    cairo_fill (cr);

    cairo_pattern_destroy (pattern1);
    cairo_pattern_destroy (pattern2);
//    cairo_pattern_destroy (pattern3);
//    cairo_pattern_destroy (pattern4);

    cairo_destroy (cr);

    cairo_surface_write_to_png(surface,"image.png");
    cairo_surface_destroy(surface);


}

int
main (int argc, char *argv[])
{

    create_surfaces ();
    show_two_image();

    return 0;
}
