#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc == 2)
    {
        game.map = load_map(argv[1]);
        if (valid_argv(argv[1]) && valid_map(&game))
        {
            ft_printf("Map is Valid!\n");
            load_game(&game);
            play_game(&game);
            mlx_loop(game.mlx);
        }
        else
        {
            ft_printf("Error: Invalid Map Format!\n");
            if (game.map)
            {
                ft_printf("Freeing Map...\n");
                free_arr(game.map);
            }
            return (0);
        }
    }
    else
    {
        ft_printf("Error: Invalid Number of Arguments!\n");
        return (0);
    }
    return (0);
}



