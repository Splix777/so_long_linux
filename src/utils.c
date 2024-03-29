#include "so_long.h"

void    free_arr(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

char    **load_map(char *file)
{
    int     fd;
    char    *line;
    char    *tmp;
    char    **map;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    tmp = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        tmp = gnl_strjoin(tmp, line);
        free(line);
    }
    map = ft_split(tmp, '\n');
    free(tmp);
    close(fd);
    return (map);
}

void    display_moves(t_game *game)
{
    char *moves;

    moves = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, moves);
    free(moves);
}