#include "Actor.h"

#include "../allIncludes.h"

Actor::Actor()
{
    //ctor
}

Actor::Actor(SDL_Renderer* renderer, const char* image, int height, int width, int x, int y)
{
    this->texture = NULL;
    this->texture = IMG_LoadTexture(renderer, image);
    if(this->texture == NULL)
    {
        cout << "Could not load actor`s image. SDL_image error:" <<
        IMG_GetError() << endl;
    }
    this->rect.h = height;
    this->rect.w = width;
    this->rect.x = x;
    this->rect.y = y;
}

Actor::~Actor()
{
    //dtor
}

void Actor::MoveUp()
{
    this->rect.y -= 1;
}

void Actor::MoveDown()
{
    this->rect.y += 1;
}

void Actor::MoveLeft()
{
    this->rect.x -= 1;
}

void Actor::MoveRight()
{
    this->rect.x += 1;
}
