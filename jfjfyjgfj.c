#include <gtk/gtk.h>
#include "game_logic.h"

// Function prototypes for private helper functions implemented at bottom of this file
static gint check_game_match(const gint lookup[][3], const gint len,
                            const gchar ch,  const char *gm_board, gint *win_blocks);
static gboolean game_board_full(const gchar *gm_board);

// Lookup tables for winning block combinations
const gint tbl_hor[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};	// Horizontal
const gint tbl_ver[3][3] = {{0, 3, 6}, {1, 4, 7}, {2, 5, 8}};	// Vertical
const gint tbl_diag[2][3] = {{0, 4, 8}, {2, 4, 6}};				// Diagonal

// Returns the state of the game as either busy, O won, X won or a tie
// Returns the winning block combination in win_blocks
game_state get_game_state(const gchar *gm_board, gint *win_blocks)
{
    game_state state = GM_BUSY;		// Start by assuming game is busy, not won or a tie
    gint result;					// A result of -1 means game is still busy
    
    // Determine if X won by checking for horizontal match, vertical match and diagonal match
    result = check_game_match(tbl_hor, 3, 'x', gm_board, win_blocks);
    if (result > -1) { return GM_X_WON; }
    result = check_game_match(tbl_ver, 3, 'x', gm_board, win_blocks);
    if (result > -1) { return GM_X_WON; }
    result = check_game_match(tbl_diag, 2, 'x', gm_board, win_blocks);
    if (result > -1) { return GM_X_WON; }
    // Determine if O won by checking for horizontal match, vertical match and diagonal match
    result = check_game_match(tbl_hor, 3, 'o', gm_board, win_blocks);
    if (result > -1) { return GM_O_WON; }
    result = check_game_match(tbl_ver, 3, 'o', gm_board, win_blocks);
    if (result > -1) { return GM_O_WON; }
    result = check_game_match(tbl_diag, 2, 'o', gm_board, win_blocks);
    if (result > -1) { return GM_O_WON; }
    
    // Check if game was a tie
    if (game_board_full(gm_board)) {
        state = GM_TIE;
    }
    
    return state;
}

// Checks the game board for a single match against a lookup table
static gint check_game_match(
							const gint lookup[][3],	// A pointer to one of the lookup tables
							const gint len,			// Number of sub-arrays in lookup table
                            const gchar ch,			// Character to look for (o or x)
                            const char *gm_board,	// Pointer to the game board array
                            gint *win_blocks)		// Returns winning blocks combination
{
    gint i, j;          // For loops to iterate through arrays
    gint count = 0;     // Tests for 3 matches
    
    for (i = 0; i < len; i++) {						// Go through each sub-array of lookup table
        count = 0;									// Reset match account
        for (j = 0; j < 3; j++) {					// Go through each element of sub-array
            if (ch == gm_board[lookup[i][j]]) {		// Did game board block match character? (o or x)
                win_blocks[j] = lookup[i][j];		// Save values from sub-array, if game is won then contains winning blocks
                count++;							// Keep track of number of matching blocks
                if (count == 3) {					// Did the player win the game?
                    return i;						// Return number > -1 to indicate game was won
                }
            }
        }
    }
    
    return -1;		// Game is a tie or still busy
}

// Determine if all blocks on the game board are full, used for determining if game is a tie
static gboolean game_board_full(const gchar *gm_board)
{
    int i;
    
    for (i = 0; i < 9; i++) {
        if (gm_board[i] == 0) {
            return FALSE;
        }
    }
    
    return TRUE;
}