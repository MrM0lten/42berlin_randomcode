#include "fdf.h"

void	rotate_x(float *y, float *z, float alpha)
{

	float temp_y;
    float temp_z;

	temp_y = *y;
    temp_z = *z;
    *y = temp_y * cos(alpha) + temp_z * (-sin(alpha));
    *z = temp_y * sin(alpha) + temp_z * cos(alpha);
}

void	rotate_y(float *x, float *z, float beta)
{

	float temp_x;
    float temp_z;

	temp_x = *x;
    temp_z = *z;
    *x = temp_x * cos(beta) + temp_z * sin(beta);
    *z = temp_x * (-sin(beta)) + temp_z * cos(beta);
}

void	rotate_z(float *x, float *y, float gamma)
{

	float temp_x;
    float temp_y;

	temp_y = *y;
    temp_x = *x;
    *x = temp_x * cos(gamma) + temp_y * (-sin(gamma));
    *y = temp_x * sin(gamma) + temp_y * cos(gamma);
}


// does all the interesting transformation and projections with the endresult of a 2d projected point
p3 project(p3 p,t_prog *prog)
{
	rotate_x(&p.y,&p.z,prog->rot.x);
    rotate_y(&p.x,&p.z,prog->rot.y);
    rotate_z(&p.x,&p.y,prog->rot.z);
	iso(&p.x, &p.y, p.z);

	// scale into view
	p.x += 1.0f;
	p.y += 1.0f;
	p.x *= 0.5f * (float)X_SIZE / 2;
	p.y *= 0.5f * (float)Y_SIZE / 2;

	return (p);
}
