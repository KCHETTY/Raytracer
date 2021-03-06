/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 15:53:11 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//TODO
//hook up malloc NULL errors
//free all mallocs
//cone
//cylinder
//sphere




#include "rtv1.h"


int		main(int argc, char **argv)
{

	t_glob		g;

//	g.spheres = 0;
	g.type = 0;
	g.cam_read = 0;
	if (argc == 2)
	{
		get_scene(&g, argv[1]);

		t_obj_list *ptr = g.head;
		printf("T-spe: %p\n", ptr);
		printf("g.head %p\n", g.head);

		printf("PRINTLIST:\n");
	while (ptr->next != NULL)
	{
		printf("origx %f, origy %f origz: %f radius: %f material: %i\n",ptr->sphere.origin.x, ptr->sphere.origin.y, ptr->sphere.origin.z, ptr->sphere.radius, ptr->sphere.material);
		printf("lightx %f, lighty %f, lightz: %f, r: %f, g: %f, b: %f\n",ptr->light.origin.x, ptr->light.origin.y, ptr->light.origin.z, ptr->light.intensity.r, ptr->light.intensity.g, ptr->light.intensity.b);
		printf("diffuseR %f, diffuseG %f, diffuseB %f, reflection: %f\n\n",ptr->material.diffuse.r, ptr->material.diffuse.g, ptr->material.diffuse.b, ptr->material.reflection);
		ptr = ptr->next;
	}
		/*printf("CAMERA VALUES:\n");
		printf("Origin - \n x: %d\n y: %d\n z: %d\n", g.cam.orig_x, 
				g.cam.orig_y, g.cam.orig_z);
		printf("Direction - \n x: %d\n y: %d\n z: %d\n", g.cam.dir_x, 
				g.cam.dir_y, g.cam.dir_z);
		printf("FOV: %f\n", g.cam.fov);
*/
		g.env.mlx = mlx_init();
		g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "RTv1");
	
		render(&g);
		mlx_hook(g.env.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
		mlx_loop(g.env.mlx);
	}
	else
		error(2);
	return (0);
}
