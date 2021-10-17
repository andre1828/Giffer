#include <gtk/gtk.h>
#include <gtk-4.0/gdk/gdk.h>
#include <stdio.h>

static void
print_hello(GtkWidget *widget,
            gpointer data)
{
    g_print("Hello World\n");
}

static void
activate(GtkApplication *app,
         gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    button = gtk_button_new_with_label("Hello World");
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(button, GTK_ALIGN_CENTER);

    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
    // g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    gtk_window_set_child(GTK_WINDOW(window), button);

    // use pixbuf to display gif
    GdkPixbufAnimation *pb = gdk_pixbuf_animation_new_from_file("/home/andre/Projects/giffer/kermit-dance.gif", NULL);

    GtkImage *gif = (GtkImage *)gtk_image_new();

    gtk_image_set_from_pixbuf(gif, pb);

    printf("is gif null: %d \n", gif == NULL);

    // gtk_video_set_autoplay(gif, TRUE);

    gtk_window_set_child(GTK_WINDOW(window), GTK_WIDGET(gif));

    gtk_widget_show(window);
}

int main(int argc,
         char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

// #include <gtk-4.0/gtk/gtk.h>

// int main(int argc, char *argv[])
// {
//     int status;
//     GtkWidget *window;
//     GtkWidget *button;
//     GtkWidget *wv;
//     GtkApplication *app;

//     app = gtk_application_new("bla.ble.bli", G_APPLICATION_FLAGS_NONE);

//     window = gtk_application_window_new(app);

//     button = gtk_button_new_with_label("bla");

//     gtk_window_set_child(GTK_WINDOW(window), button);

//     // set window to be borderless
//     // gtk_window_set_decorated((GtkWindow *)window, FALSE);

//     gtk_widget_show(window);

//     status = g_application_run(G_APPLICATION(app), argc, argv);

//     return status;
// }
