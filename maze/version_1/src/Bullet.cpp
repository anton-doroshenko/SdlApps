#include "Bullet.h"

Bullet::Bullet(float start_x, float start_y, float start_dir, float start_speed)
{
    this->x = start_x;
    this->y = start_y;
    this->dir = start_dir;
    this->speed = start_speed;
}

Bullet::~Bullet()
{
    //dtor
}
