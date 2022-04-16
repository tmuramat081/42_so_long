/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:27:26 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 01:27:26 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONFIG_H
# define GAME_CONFIG_H

/***** Key binding for Mac. *****/
# ifdef KEYCODE_MAC
#  define KEY_A 0
#  define KEY_D 1
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_Q 12
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_ESC 53
# else
/***** Key binding for Linux. *****/
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_Q 113
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_ESC 65307
# endif

/***** Window resolution. *****/
# define MAP_WIDTH_MAX 128
# define MAP_HEIGHT_MAX 32
# define GRID_SIZE 32

/***** Animation *****/
# define FPS_MAX 30
# define NUM_FRAMES 8
# define LTD_FRAMES 2
# define MOVE_DURATION 0.3

/**** Enemy ****/
# define ENEMY_LEVEL 1

/***** Image file(.xpm) locations. *****/
/////* Object image file */////
# define XPM_BACK "./img/object/back.xpm"
# define XPM_WALL "./img/object/wall.xpm"
# define XPM_COLLECT "./img/object/collect.xpm"
# define XPM_EXIT "./img/object/exit.xpm"

/////* Footer image file */////
# define XPM_MENU "./img/footer/menu.xpm"
# define XPM_TITLE "./img/footer/title.xpm"
# define XPM_LOGO "./img/footer/logo.xpm"

/////* Counter image file directory (0-9.xpm)*/////
# define XPM_DIGIT "./img/counter/"

/////* Player image file directory (0-9.xpm)*/////
# define XPM_PLAYER_UP "./img/player/up/"
# define XPM_PLAYER_DOWN "./img/player/down/"
# define XPM_PLAYER_LEFT "./img/player/left/"
# define XPM_PLAYER_RIGHT "./img/player/right/"

/////* Enemy image file directory (0-9.xpm) */////
# define XPM_ENEMY_L_UP "./img/enemy_l/up/"
# define XPM_ENEMY_L_DOWN "./img/enemy_l/down/"
# define XPM_ENEMY_L_LEFT "./img/enemy_l/left/"
# define XPM_ENEMY_L_RIGHT "./img/enemy_l/right/"

# define XPM_ENEMY_S_UP "./img/enemy_s/up/"
# define XPM_ENEMY_S_DOWN "./img/enemy_s/down/"
# define XPM_ENEMY_S_LEFT "./img/enemy_s/left/"
# define XPM_ENEMY_S_RIGHT "./img/enemy_s/right/"
#endif