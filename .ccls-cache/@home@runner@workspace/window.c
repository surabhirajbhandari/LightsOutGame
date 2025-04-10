#include "house.h"
#include <stdio.h>
/* Updates the graphics for the window @ coordinates (x, y) to match the
 * `state` array.
 *
 *   This function modifies the `house` array by updating the characters
 *   inside the window located at the zero indexed coordinates (x, y) to
 *   match the window's state in the `state` array.  If the window's
 *   state is 1, then the window is filled with the '#' character.
 *   Likewise, if the window's state is 0 in the `state` array, the
 *   window is filled with the ' ' character.
 *
 * Parameters:
 *   house -- pointer to characters representing the house
 *
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update_graphics (char *house, const int *state, int x, int y)
{
  char c = '#';
  if(*state == 0)
    c = ' ';
  int a;
  if (x == 0 && y == 0 ){
      for(a=563; a<=573; a++){
            house[a] = c;
        }
        for(a=632; a<=642; a++){
            house[a] = c;
        }
        for(a=701; a<=711; a++){
            house[a] = c;
        }
    }
    
    if (x == 1 && y == 0 ){ 
        for(a=581; a<=591; a++){
            house[a] = c;  
        }
        for(a=650; a<=660; a++){
            house[a] = c;
        }
        for(a=719; a<=729; a++){
            house[a] = c;
        }
    } 

    if (x == 2 && y == 0 ){
        for(a=599; a<=609; a++){
            house[a] = c;  
        }
        for(a=668; a<=678; a++){
            house[a] = c;
        }
        for(a=737; a<=747; a++){
            house[a] = c;
        }
    }

    if (x == 0 && y == 1 ){
        for(a=977; a<=987; a++){
            house[a] = c;  
        }
        for(a=1046; a<=1056; a++){
            house[a] = c;
        }
        for(a=1115; a<=1125; a++){
            house[a] = c;
        }
    }

    if (x == 1 && y == 1 ){
        for(a=995; a<=1005; a++){
            house[a] = c;  
        }
        for(a=1064; a<=1074; a++){
            house[a] = c;
        }
        for(a=1133; a<=1143; a++){
            house[a] = c;
        }
    }

    if (x == 2 && y == 1 ){
        for(a=1013; a<=1023; a++){
            house[a] = c;  
        }
        for(a=1082; a<=1092; a++){
            house[a] = c;
        }
        for(a=1151; a<=1161; a++){
            house[a] = c;
        }
    }

    if (x == 0 && y == 2 ){
        for(a=1391; a<=1401; a++){
            house[a] = c;  
        }
        for(a=1460; a<=1470; a++){
            house[a] = c;
        }
        for(a=1529; a<=1539; a++){
            house[a] = c;
        }
    }

    if (x == 1 && y == 2 ){
        for(a=1409; a<=1419; a++){
            house[a] = c;  
        }
        for(a=1478; a<=1488; a++){
            house[a] = c;
        }
        for(a=1547; a<=1557; a++){
            house[a] = c;
        }
    }

    if (x == 2 && y == 2 ){
        for(a=1427; a<=1437; a++){
            house[a] = c;  
        }
        for(a=1496; a<=1506; a++){
            house[a] = c;
        }
        for(a=1565; a<=1575; a++){
            house[a] = c;
        }
    }
 }

/* Toggles the state of the window @ coordinates (x, y) in the game
 * state array.
 *
 *   This function modifies the `state` array by toggling the value
 *   corresponding to the window at the provided coordinates (x, y).  If
 *   the current value is 1, then it will be toggled to 0.  Likewise, if
 *   the current value is 0, then it will be toggled to 1.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */

void window_toggle_state (int *state, int x, int y)
{
  int idx = 3*y + x;
  state[idx] = !state[idx];
}

/* Toggles the state and, correspondingly, updates the graphics for the
 * window @ coordinates (x, y).
 *
 *   Given the zero indexed coordinates (x, y) of a window, this
 *   function ensures that the corresponding element in the game state
 *   array is toggled appropriately and that the graphics corresponding
 *   to that window are updated appropriately to reflect the new state.
 *
 *   Hint: call other functions you have written to make this easier.
 *
 * Parameters:
 *   state -- pointer to the game state array
 *
 *   house -- pointer to characters representing the house
 *
 *       x -- the horizontal coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the left column and 2 being the right column)
 *
 *       y -- the vertical coordinate of the window for which the
 *            state will be updated (zero indexed, with 0 being
 *            the top row and 2 being the bottom row)
 */
void window_update (int *state, char *house, int x, int y)
{
  window_toggle_state (state, x, y);
  int idx = 3*y + x;
  window_update_graphics (house, state + idx, x, y);
}

/* Toggles the lights based on the user's window selection.
 *
 *   Given the user's choice of window number, this function updates the
 *   corresponding window's (or windows') state and graphics, as
 *   necessary.
 *
 *   Hints:
 *     -- A primary job of this function will be to convert the choice
 *        of the user into the zero indexed (x, y) coordinates of a
 *        window.
 *
 *     -- Converting between `choice` and the (x, y) coordinates will
 *        probably be easier if you internally number the windows
 *        starting at zero (i.e. 0 thru 8 instead of 1 thru 9).
 *
 *     -- This function will need to call one other function
 *        (perhaps multiple times).
 *
 *   For Step 2, this function will only toggle the window
 *   corresponding to the user's selection.
 *
 *   For Step 3, this function will toggle the selected window
 *   and its neighbors (as described above in the instructions).
 *
 * Parameters:
 *    state -- pointer to the game state array
 *
 *    house -- pointer to characters representing the house
 *
 *   choice -- integer corresponding to the user's window selection
 *             (an integer value within the range 1 to 9)
 */

void window_toggle (int *state, char *house, int choice)
{ 
  int x;
  int y;

  if (choice == 1 ){
    x = 0; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 0;
    window_update ( state, house, x, y);
    x = 0; y = 1;
    window_update ( state, house, x, y);
  }

  else if (choice == 2 ){
    x = 0; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 1;
    window_update ( state, house, x, y);
    x = 2; y = 0;
    window_update ( state, house, x, y);
  }

  else if (choice == 3 ){
    x = 1; y = 0;
    window_update ( state, house, x, y);
    x = 2; y = 0;
    window_update ( state, house, x, y);
    x = 2; y = 1;
    window_update ( state, house, x, y);
  }

  else if (choice == 4 ){
    x = 0; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 1;
    window_update ( state, house, x, y);
    x = 0; y = 1;
    window_update ( state, house, x, y);
    x = 0; y = 2;
    window_update ( state, house, x, y);
  }

  else if (choice == 5 ){
    x = 1; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 1;
    window_update ( state, house, x, y);
    x = 0; y = 1;
    window_update ( state, house, x, y);
    x = 2; y = 1;
    window_update ( state, house, x, y);
    x = 1; y = 2;
    window_update ( state, house, x, y);
  }

  else if (choice == 6 ){
    x = 2; y = 1;
    window_update ( state, house, x, y);
    x = 2; y = 0;
    window_update ( state, house, x, y);
    x = 1; y = 1;
    window_update ( state, house, x, y);
    x = 2; y = 2;
    window_update ( state, house, x, y);
  }

  else if (choice == 7 ){
    x = 0; y = 2;
    window_update ( state, house, x, y);
    x = 0; y = 1;
    window_update ( state, house, x, y);
    x = 1; y = 2;
    window_update ( state, house, x, y);
  }

  else if (choice == 8 ){
    x = 2; y = 2;
    window_update ( state, house, x, y);
    x = 0; y = 2;
    window_update ( state, house, x, y);
    x = 1; y = 2;
    window_update ( state, house, x, y);
    x = 1; y = 1;
    window_update ( state, house, x, y);
  }

  else if (choice == 9){
    x = 2; y = 2;
    window_update ( state, house, x, y);
    x = 1; y = 2;
    window_update ( state, house, x, y);
    x = 2; y = 1;
    window_update ( state, house, x, y);
  } 
}