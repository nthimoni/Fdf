/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:52:14 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/23 00:59:54 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTES_H
# define CONSTANTES_H

# include <math.h>

# define W_TITLE "FDF"
# define W_WIDTH 1300
# define W_HEIGHT 900

# ifdef FR_S // MAP FRANCE BLEU / ROUGE
#  define X_SC 1
#  define Y_SC 1
#  define Z_SC 0.09
# elif defined M_42 // PURPLE / ORANGE
#  define X_SC 50
#  define Y_SC 50
#  define Z_SC 10
# endif

# define CAM_SPEED 20
# define ROT_DIV 40
# define SCALE_SPEED 0.1f
# define MAX_ZOOM 200
# define EX_SPEED 0.3f

# define HEXA_B "0123456789abcdef"

#endif
