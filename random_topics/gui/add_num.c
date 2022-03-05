#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#define COL 0
#define ROW 0

const char clicked_signal[] = "clicked";
const char destroy_signal[] = "destroy";

const char add_label[] = "ADD";
const char res_label[] = "Result:";

/* Global vars to be accessed by both main and the callback function */
static GtkWidget *num_1, *num_2, *res;

void add_two(GtkWidget* calculate, gpointer data);

/* 
  COMPILE WITH: 
    gcc add_num.c -o add_num.o `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
  
  RUN WITH:
    ./add_num.o
*/
int main(int argc, char *argv[]){
    GtkWidget *window, *grid, *add;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
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
    gtk_main();
    
    return 0;
}

// Callback function to the ADD button 
void add_two(GtkWidget* calculate, gpointer data){
    int _num_1 = atoi((char*)gtk_entry_get_text(GTK_ENTRY(num_1)));
    int _num_2 = atoi((char*)gtk_entry_get_text(GTK_ENTRY(num_2)));

    char buf[32];
    sprintf(buf, "%s %d", res_label, (_num_1+_num_2));

    gtk_label_set_text(GTK_LABEL(res), buf);
}