/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_message.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:27:32 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 01:27:32 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MESSAGE_H
# define GAME_MESSAGE_H

/***** Game title *****/
# define WINDOW_TITLE "So Long"

/***** Error message *****/
# define ERR_ARGS "Invalid arguments."
# define ERR_FILE_NAME "Invalid filename."

# define ERR_MAP_EMPTY "Map is empty."
# define ERR_MAP_SIZE "Map size is too large."
# define ERR_MAP_FMT "Map is not rectangle."
# define ERR_MAP_OBJ "Map has unknown object."
# define ERR_MAP_COLL "Map has no collectibles."
# define ERR_MAP_EXIT "Map has no exits."
# define ERR_MAP_WALL "Map is not enclosed by wall."
# define ERR_NO_PLAYER "There is no players."
# define ERR_IMG_SIZE "XPM image size is wrong."
# define ERR_FILE_FMT "Invalid image file format."
# define ERR_NOT_PLAYABLE "This map is unplayable."
# define ERR_FILE_READ "Fail to read file."
# define ERR_MEMORY "Memory Error."

/***** End message *****/
# define WIN_GAME "---Congratulations! you are win.---\n"
# define LOSE_GAME "---Oops! you lose, Good luck.---\n"
# define EXIT_GAME "---See you, please play again.---\n"

#endif