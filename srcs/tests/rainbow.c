/*
** #include "../../include/minirt.h"
** 
** typedef struct	s_projectile
** {
** 	t_tuple		pos;
** 	t_tuple		vel;
** }				t_projectile;
** 
** typedef struct	s_env
** {
** 	t_tuple		gravity;
** 	t_tuple		wind;
** }				t_env;
** 
** static t_projectile	tick(t_env env, t_projectile proj)
** {
** 		t_projectile new;
** 
** 		new.pos = add_tuple(proj.pos, proj.vel);
** 		new.vel = add_tuple(proj.vel, env.gravity);
** 		new.vel = add_tuple(new.vel, env.wind);
** 		return (new);
** }
** 
** void  projectile_test(char *times)
** {
** 	t_mlx	mlx;
** 	int		max_x;
** 	int		max_y;
** 
** 	max_x = 1650;
** 	max_y = 960;
** 
** 	mlx.mlx = mlx_init();
** 	mlx.win = mlx_new_window(mlx.mlx, max_x, max_y, "TestProj");
** 	mlx.img = mlx_new_image(mlx.mlx, max_x, max_y);
** 	mlx.address = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_leng, &mlx.endian);
** 
** 	t_projectile	p;
** 	t_env			e;
** 	int	x;
** 	int	y;
** 
** 	p.pos = create_tuple(0, 1, 0, 1);
** 	p.vel = scalar_x_tuple(normalize_v(create_tuple(1, 1, 0, 0)), ft_atof(times));
** 	e.gravity = create_tuple(0, -0.1, 0, 0);
** 	e.wind = create_tuple(-0.01, 0, 0, 0);
** 	printf("POS INICIAL -> X: %lf, Y: %lf, Z: %lf", p.pos.x, p.pos.y, p.pos.z);
** 	printf("VEL INICIAL -> X: %lf, Y: %lf, Z: %lf\n", p.vel.x, p.vel.y, p.vel.z);
** 
** 	while (p.pos.y > 0)
** 	{
** 		x = (int)p.pos.x;
** 		y = max_y - (int)p.pos.y;
** 
** 		if (y <= max_y && x <= max_x && x >= 0 && y >= 0)
** 		{
** 			printf("X: %d, Y: %d\n", x, y);
** 
** 			//vermelho
** 			ft_pixelput(&mlx, x, y - 53, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 52, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 51, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 50, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 49, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 48, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 47, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 46, create_trgb(0, 255, 0, 0));
** 			ft_pixelput(&mlx, x, y - 45, create_trgb(0, 255, 0, 0));
** 			//laranja
** 			ft_pixelput(&mlx, x, y - 44, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 43, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 42, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 41, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 40, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 39, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 38, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 37, create_trgb(0, 255, 128, 0));
** 			ft_pixelput(&mlx, x, y - 36, create_trgb(0, 255, 128, 0));
** 			//amarelo
** 			ft_pixelput(&mlx, x, y - 35, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 34, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 33, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 32, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 31, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 30, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 29, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 28, create_trgb(0, 255, 255, 0));
** 			ft_pixelput(&mlx, x, y - 27, create_trgb(0, 255, 255, 0));
** 			//verde
** 			ft_pixelput(&mlx, x, y - 26, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 25, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 24, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 23, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 22, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 21, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 20, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 19, create_trgb(0, 0, 255, 0));
** 			ft_pixelput(&mlx, x, y - 18, create_trgb(0, 0, 255, 0));
** 			//azul
** 			ft_pixelput(&mlx, x, y - 17, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 16, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 15, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 14, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 13, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 12, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 11, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 10, create_trgb(0, 0, 0, 255));
** 			ft_pixelput(&mlx, x, y - 9, create_trgb(0, 0, 0, 255));
** 			//roxo
** 			ft_pixelput(&mlx, x, y - 8, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 7, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 6, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 5, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 4, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 3, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 2, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y - 1, create_trgb(0, 127, 0, 255));
** 			ft_pixelput(&mlx, x, y, create_trgb(0, 127, 0, 255));
** 		}
** 
** 		p = tick(e, p);
** 	}
** 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
** 	mlx_key_hook(mlx.win, close_wndw, &mlx);
** 	mlx_loop(mlx.mlx);
** }
*/