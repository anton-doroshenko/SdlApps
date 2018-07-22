#ifndef ACTOR_H
#define ACTOR_H

#include "../allIncludes.h"
class Actor
{
    public:
        Actor();
        Actor(SDL_Renderer* renderer, const char* image, int height, int width, int x, int y);
        virtual ~Actor();
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

    protected:

    private:
        SDL_Texture* texture;
        SDL_Rect rect;
};

#endif // ACTOR_H
