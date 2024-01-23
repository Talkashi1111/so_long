/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <tkashi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:41:33 by tkashi            #+#    #+#             */
/*   Updated: 2024/01/22 21:55:42 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <sys/wait.h>//for instruments
# include <unistd.h>//for sleep
# include <sys/time.h>
# include <time.h>
# include "get_next_line.h"

# define WINDOW_WIDTH 64
# define WINDOW_HEIGHT 64
# define FALSE	0
# define TRUE	1
# define MAX_TRIES 100
# define ENEMY_RADIUS 3
# define FRAME_RATE_MS 15
# define MUSHROOM_IMGS 4

# ifdef __linux__
#  define OS_LINUX		TRUE
#  define KEY_LEFT	 	65361
#  define KEY_RIGHT		65363
#  define KEY_DOWN		65364
#  define KEY_UP		65362
#  define KEY_ESC		65307
# elif __APPLE__
#  define OS_LINUX		FALSE
#  define KEY_LEFT		123
#  define KEY_RIGHT		124
#  define KEY_DOWN		125
#  define KEY_UP		126
#  define KEY_ESC		53
# endif

# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# define WALL_PATH "xpms/wall_70.xpm"
# define BACKGROUND_PATH "xpms/background_linux_70.xpm"
# define PLAYER_DOWN "xpms/standing_man_linux.xpm"
# define PLAYER_UP "xpms/bob_up_70.xpm"
# define PLAYER_LEFT "xpms/walking_left_linux.xpm"
# define PLAYER_RIGHT "xpms/walking_right_linux.xpm"
# define GATE_CLOSE "xpms/gate_close_linux.xpm"
# define GATE_OPEN "xpms/gate_open_linux.xpm"
# define COUNTER_PATH "xpms/background_try.xpm"
# define YOU_WON "xpms/you_won.xpm"
# define YOU_LOSE "xpms/you_lose.xpm"
# define GATE_CLOSE_PLAYER "xpms/close_gate_p_70.xpm"
# define GATE_OPEN_PLAYER "xpms/exit_open_p_70.xpm"
# define ENEMY_PATH "xpms/standing_enemy_linux.xpm"
# define ENEMY_LEFT "xpms/enemy_walking_left_linux.xpm"
# define ENEMY_RIGHT "xpms/enemy_walking_right_linux.xpm"
# define ARREST "xpms/arresting_70.xpm"
# define MUSHROOM_0 "xpms/mushroom1_fix_71.xpm"
# define MUSHROOM_1 "xpms/mushroom_1_70.xpm"
# define MUSHROOM_2 "xpms/mushroom_2_70.xpm"
# define MUSHROOM_3 "xpms/mushroom_3_70.xpm"
# define FILE_EXT ".ber"

typedef struct s_coord {
	int	row;
	int	col;
}				t_coord;

typedef struct s_dfs
{
	int		found_exit;
	int		found_collectibles;
	char	**visited;
}				t_dfs_vars;

enum {
	OK,
	MLX_ERROR,
	IMAGE_ERROR,
	ARG_ERROR,
	MAP_ERROR,
	ALLOC_ERROR,
};

enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	DIRS,
};

typedef struct s_vars {
	int			map_height;
	int			map_width;
	int			n_collect;
	int			n_enemies;
	t_coord		player;
	t_coord		player_last;
	t_coord		exit;
	t_coord		*collectibles;
	t_coord		*enemies;
	int			*enemy_dir;
	int			collected;
	int			moves;
	void		*wall;
	void		*background;
	void		*player_down;
	void		*player_up;
	void		*player_left;
	void		*player_right;
	void		*gate_open_with_man;
	void		*gate_close_with_man;
	void		*mushrooms[MUSHROOM_IMGS];
	void		*gate_close;
	void		*gate_open;
	void		*stats_background;
	void		*you_won;
	void		*you_lose;
	void		*enemy_path;
	void		*enemy_left;
	void		*enemy_right;
	void		*arrest;
	long long	last_measured_ms;
	int			frame_count;
	int			wall_width;
	int			wall_height;
	int			you_won_width;
	int			you_won_height;
	int			you_lose_width;
	int			you_lose_height;
	void		*mlx;
	void		*win;
	char		**map;
}						t_vars;

int			ft_strlen_int(const char *s);
void		ft_error(const char *msg);
int			counting_lines(int fd);
char		**parse_map(char *path, int *map_height);
int			is_chars_valid(t_vars *vars);
int			is_rect(char **mat, int map_height, int *map_width);
void		free_map(t_vars *vars);
int			read_line(char **matrix, int *map_height, int fd);
void		dfs(t_vars *vars, int row, int col, t_dfs_vars *dfs_vars);
int			is_surrounded_by_walls(char **mat, int map_height, int map_width);
char		**create_visited(int map_height, int map_width);
void		free_visited(char **visited, int map_height);
void		free_matrix(char **matrix, int n);
int			is_solvable(t_vars *vars);
void		alloc_map(char *path, t_vars *vars);
int			ft_close(t_vars *vars);
int			check_extension(char *file_name);
void		ft_error(const char *msg);
void		ft_print_usage(char *prog_name);
int			prepare_game(t_vars *vars);
int			load_images(t_vars *vars);
void		init_vars(t_vars *vars);
int			key_release(int keycode, t_vars *vars);
int			key_press(int keycode, t_vars *vars);
int			key_up_down(t_vars *vars, int commend);
int			key_left_right(t_vars *vars, int commend);
int			valid_move(t_vars *vars, int keycode);
void		ft_put_exit(t_vars *vars, int row, int col);
void		render_move(t_vars *vars, int keycode);
void		ft_show_counter(t_vars *vars);
int			update_frame(t_vars *vars);
int			end_game(t_vars *vars);
void		ft_put_you_lose(t_vars *vars);
void		ft_put_you_won(t_vars *vars);
void		get_next_move(int dir, int *row, int *col);
void		render_enemy(t_vars *vars, int enemy);
void		move_enemy(t_vars *vars, int enemy);
int			init_enemies(t_vars *vars);
int			init_mlx_window(t_vars *vars);
void		destroy_images(t_vars *vars);
long long	current_time_ms(void);
void		move(t_vars *vars, int keycode);
void		render_player_image(t_vars *vars, int keycode, int x, int y);
int			has_close_players_or_enemies(t_vars *vars, int row, int col);
int			init_game(char *map_path, t_vars *vars);
int			error_mlx_and_map(char *map_path, t_vars *vars);
void		destroy_mlx_display(t_vars *vars);
int			prepare_game_error(t_vars *vars);
int			handle_invalid_character_error(void);
int			handle_multiple_exit_error(void);

# ifdef __APPLE__

int			mlx_loop_end(void *mlx_ptr);
int			mlx_destroy_display(void *mlx_ptr);
# endif

#endif