#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#define WIDTH     500
#define HEIGHT    30

#define COL       0
#define ROW       0

/* App ID: https://wiki.gnome.org/HowDoI/ChooseApplicationID */
const char app_id[] = "Add.gtk";

/* Signals */
const char activate_signal[] = "activate";
const char clicked_signal[]  = "clicked";
const char destroy_signal[]  = "destroy";

/* Labels */
const char window_title[]    = "ADD Two";
const char add_label[]       = "ADD";
const char res_label[]       = "Result:";

/* Global vars to be accessed by both main and the callback function */
static GtkWidget *num_1, *num_2, *res;

static void add_two(GtkWidget* calculate, gpointer data);
static void activate (GtkApplication* app, gpointer user_data);

/* 
  COMPILE WITH: 
    gcc add_num.c -o add_num `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
  
  OR
    gcc $( pkg-config --cflags gtk+-3.0 ) -o add_num add_num.c $( pkg-config --libs gtk+-3.0 )
  
  RUN WITH:
    ./add_num
*/
int main(int argc, char **argv){
    GtkApplication *app;
    int status;
    app = gtk_application_new (app_id, G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, activate_signal, G_CALLBACK (activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref (app);

    return status;
}

// The showroom for the application
static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget *window, *grid, *add;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), window_title);
  gtk_window_set_default_size (GTK_WINDOW (window), WIDTH, HEIGHT);
  g_signal_connect(window, destroy_signal, G_CALLBACK(gtk_main_quit), NULL);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  num_1 = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), num_1, COL+0, ROW, 1, 1);

  num_2 = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), num_2, COL+1, ROW, 1, 1);

  add = gtk_button_new_with_label(add_label);
  g_signal_connect(add, clicked_signal, G_CALLBACK(add_two), NULL);
  gtk_grid_attach(GTK_GRID(grid), add, COL+2, ROW, 1, 1);

  res = gtk_label_new(res_label);
  gtk_grid_attach(GTK_GRID(grid), res, COL+3, ROW, 1, 1);

  gtk_widget_show_all(window);

}

// Callback function to the ADD button 
static void add_two(GtkWidget* calculate, gpointer data){
    int _num_1 = atoi((char*)gtk_entry_get_text(GTK_ENTRY(num_1)));
    int _num_2 = atoi((char*)gtk_entry_get_text(GTK_ENTRY(num_2)));

    char buf[32];
    sprintf(buf, "%s %d", res_label, (_num_1+_num_2));

    gtk_label_set_text(GTK_LABEL(res), buf);
}