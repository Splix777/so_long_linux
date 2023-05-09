#include "so_long.h"

int valid_argv(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (file[i - 1] == 'r' && file[i - 2] == 'e'
        && file[i - 3] == 'b' && file[i - 4] == '.')
        return (1);
    ft_printf("Error: Invalid File Extension, use .ber file!\n");
    return (0);
}

int valid_map(t_game *game)
{
    int i;

    ft_printf("Validating Map...\n");
    i = 0;
    game->collectible = 0;
    game->exit = 0;
    game->player = 0;
    if (is_rectangle(game))
        i++;
    if (has_walls(game))
        i++;
    if (has_pec(game))
        i++;
    if (correct_format(game))
        i++;
    if (i == 4)
    {
        ft_printf("All Checks OK!\n");
        return (1);
    }
    return (0);
}

int is_rectangle(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j])
            j++;
        if (i == 0)
            game->map_width = j;
        else if (j != game->map_width)
        {
            ft_printf("Error: Map is not a Rectangle!\n");
            return (0);
        }
        i++;
    }
    ft_printf("It's a Rectangle.\n");
    game->map_height = i;
    return (1);
}

int has_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (i == 0 || i == game->map_height - 1)
            {
                if (game->map[i][j] != '1')
                {
                    ft_printf("Error: Map has no Walls!\n");
                    return (0);
                }
            }
            else if (j == 0 || j == game->map_width - 1)
            {
                if (game->map[i][j] != '1')
                {
                    ft_printf("Error: Map has no Walls!\n");
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    ft_printf("Yup, it has walls!\n");
    return (1);
}

int has_pec(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
                game->player++;
            }
            else if (game->map[i][j] == 'E')
                game->exit++;
            else if (game->map[i][j] == 'C')
                game->collectible++;
            j++;
        }
        i++;
    }
    if (game->player == 1 && game->exit >= 1 && game->collectible > 0)
    {
        ft_printf("Found Player, Exit and Collectibles!\n");
        return (1);
    }
    ft_printf("Error: Map has no Player, Exit, or Collectibles!\n");
    return (0);
}

int correct_format(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] != '0' && game->map[i][j] != '1'
                && game->map[i][j] != 'C' && game->map[i][j] != 'E'
                    && game->map[i][j] != 'P')
            {
                ft_printf("Error: Map has invalid characters!\n");
                return (0);
            }
            j++;
        }
        i++;
    }
    ft_printf("Its the correct format...\n");
    return (1);
}