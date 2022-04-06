#ifndef GAME_CONFIG_H
# define GAME_CONFIG_H

/***** Key binding for Linux. *****/
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_Q 113
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ESC 65307

/***** Window resolution. *****/
# define MAP_WIDTH_MAX 50
# define MAP_HEIGHT_MAX 32
# define GRID_SIZE 32

/***** Frame rate *****/
# define FPS 30.0
# define ANI_FRAME 4
# define ANI_SPEED 75

/***** Image file(.xpm) locations. *****/
/////* Object file*/////
# define XPM_FLOOR "./img/object/floor.xpm"
# define XPM_WALL "./img/object/wall.xpm"
# define XPM_DOT "./img/object/dot.xpm"
# define XPM_EXIT "./img/object/exit.xpm"

/////* Footer file*/////
# define XPM_MENU "./img/footer/menu.xpm"
# define XPM_TITLE "./img/footer/title.xpm"
# define XPM_LOGO "./img/footer/logo.xpm"

/////* Counter file directory (0-9.xpm)*/////
# define XPM_DIGIT "./img/counter/"

/////* Player file directory (0-9.xpm)*/////
# define XPM_P_UP "./img/player/up/"
# define XPM_P_DOWN "./img/player/down/"
# define XPM_P_LEFT "./img/player/left/"
# define XPM_P_RIGHT "./img/player/right/"

/////* Enemy file directory (0-9.xpm) */////
# define XPM_E_UP "./img/enemy/up/"
# define XPM_E_DOWN "./img/enemy/down/"
# define XPM_E_LEFT "./img/enemy/left/"
# define XPM_E_RIGHT "./img/enemy/right/"

#endif