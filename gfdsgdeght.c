#include <gtk/gtk.h>
#include "game_logic.h"

// Structure for pointer access to widgets, but also keeping game variables here
typedef struct {
    GtkWidget *w_img[9];    	// Images in buttons hold blank, O or X
    GtkWidget *w_lbl_status;	// Status label
    gboolean turn;          	// Keeps track of turns - TRUE = O, FALSE = X
    gchar game_board[9];    	// Tracks game moves on board, maps board left to right, top to bottom
    game_state gm_state;    	// Game state: busy, O won, X won or tie
} app_widgets;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets     *widgets = g_slice_new(app_widgets);
    gchar           str_img[] = "img_0";    // For accessing images from Glade file

    widgets->turn = TRUE;       			// O turn (FALSE is X turn)
    widgets->gm_state = GM_BUSY;			// Game state is initially busy

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    
    // Get a pointer to each image
    for (gint i = 0; i < 9; i++) {
        str_img[4] = i + '0';
        widgets->w_img[i] = GTK_WIDGET(gtk_builder_get_object(builder, str_img));
        // Reset game board
        widgets->game_board[i] = 0;
    }
    // Get a pointer to the status label
    widgets->w_lbl_status = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_status"));
    
    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

// Button clicked handler function shared by all buttons in grid
void on_btn_clicked(GtkButton *button, app_widgets *app_wdgts)
{
    gint btn_num;       			// Number of button that was clicked
    gint winning_blocks[3] = {0};	// Numbers of blocks if 3 in row of same type
    
    if (app_wdgts->gm_state != GM_BUSY) {
        // Don't do anything if game is won or a tie
        return;
    }
    
    // Find the button that was clicked, by reading the wiget name
    // The name is a string "0" to "8", convert ASCII to int by subtracting '0'
    btn_num = gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';
    
    // Only service buttons that have not been clicked, i.e. contain 0 in game_board
    if (app_wdgts->game_board[btn_num] == 0) {
        // Set image in clicked button to O or X
        gtk_image_set_from_file(GTK_IMAGE(app_wdgts->w_img[btn_num]), app_wdgts->turn ? "res/o.png" : "res/x.png");
        // Track game move
        app_wdgts->game_board[btn_num] = app_wdgts->turn ? 'o' : 'x';
        
        // Find out if the game is won, a tie or still busy
        app_wdgts->gm_state = get_game_state(app_wdgts->game_board, winning_blocks);
        
        // O won the game, so mark the winning blocks with the O image with green background
        if (app_wdgts->gm_state == GM_O_WON) {
            for (int i = 0; i < 3; i++) {
                gtk_image_set_from_file(GTK_IMAGE(app_wdgts->w_img[winning_blocks[i]]), "res/o_win.png");
            }
            gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_status), "O Won!");
        }
        // X won the game, so mark the winning blocks with the X image with green background
        else if (app_wdgts->gm_state == GM_X_WON) {
            for (int i = 0; i < 3; i++) {
                gtk_image_set_from_file(GTK_IMAGE(app_wdgts->w_img[winning_blocks[i]]), "res/x_win.png");
            }
            gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_status), "X Won!");
        }
        // The game was a tie
        else if (app_wdgts->gm_state == GM_TIE) {
			gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_status), "The Game was a Tie!");
		}
        
        // Flag next players turn
        app_wdgts->turn = !app_wdgts->turn;
    }
}

// New Game button - reset the game
void on_btn_new_game_clicked(GtkButton *button,  app_widgets *app_wdgts)
{
	// Reset the game board
	for (int i = 0; i < 9; i++) {
		app_wdgts->game_board[i] = 0;
	}
	// Clear the button images by loading blank image
	for (int i = 0; i < 9; i++) {
		gtk_image_set_from_file(GTK_IMAGE(app_wdgts->w_img[i]), "res/blank.png");
	}
	// Reset the status message to the default text
	gtk_label_set_text(GTK_LABEL(app_wdgts->w_lbl_status), "Make a Move by Clicking a Block");
	
	// Game starts in the busy state
    app_wdgts->gm_state = GM_BUSY;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}