#include <gtk-3.0/gtk/gtk.h>

static void
handle_error(GError *error)
{
    if (error != NULL)
    {

        g_print("Error: %s\n", error->message);
        g_clear_error(&error);
    }
}

int main(int argc, char *argv[])
{
    GtkWidget *window, *vbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    // animated gif
    GdkPixbufAnimation *pixbuf_animation = gdk_pixbuf_animation_new_from_file("/home/andre/Projects/giffer/kermit-dance.gif", NULL);

    GtkImage *gif = (GtkImage *)gtk_image_new();

    gtk_image_set_from_animation(gif, pixbuf_animation);

    gtk_box_pack_end((GtkBox *)vbox, (GtkWidget *)gif, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}