#include "allIncludes.h"

int main(int argc, char* args[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event* quitEvent = new SDL_Event();

    SDL_Texture* background = NULL;
    SDL_Rect backRect;
    SDL_Texture* actor = NULL;
    SDL_Rect actorRect;
    SDL_Texture* bullet = NULL;
    SDL_Rect bulletRect;

    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    //=== SDL inicialisation ===
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL can`t inicialize! SDL_Error: "
        << SDL_GetError() << endl;
        return 1;
    }
    //=== Create window ===
    window = SDL_CreateWindow("Maze 1.0.0", 100, 100, 600, 400, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Window can`t creat! SDL_Error: "
        << SDL_GetError() << endl;
        return 1;
    }
    //=== Create renderer ===
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        cout << "Renderer can`t created! SDL_Error: "
        << SDL_GetError() << endl;
        return 1;
    }

    //=== Load images ===
    background = IMG_LoadTexture(renderer, "background.png");
    if(background == NULL)
    {
        cout << "Couldn`t load background. SDL_image error: "
        << IMG_GetError() << endl;
    }

    backRect.h = 400;
    backRect.w = 600;
    backRect.x = 0;
    backRect.y = 0;

    actor = IMG_LoadTexture(renderer, "actor2.png");

    if(actor == NULL)
    {
        cout << "Couldn`t load actor. SDL_image error: "
        << IMG_GetError() << endl;
    }

    actorRect.h = 60;
    actorRect.w = 60;
    //actorRect.h = 40;
    //actorRect.w = 40;
    actorRect.x = 220;
    actorRect.y = 100;

    //(NULL, &actorRect, SDL_MapRGB(,255, 0, 0));

    bullet = IMG_LoadTexture(renderer, "actor2.png");

    if(bullet == NULL)
    {
        cout << "Couldn`t load bullet. SDL_image error: "
        << IMG_GetError() << endl;
    }

    srand(time(0));

    bulletRect.h = 40;
    bulletRect.w = 40;
    bulletRect.x = 580;
    bulletRect.y = 1 + rand() % 380;

    while(quitEvent->type != SDL_QUIT)
    {
        SDL_PollEvent(quitEvent);
        //SDL_PollEvent(moveEvent);
        /*if (quitEvent->type == SDL_KEYDOWN) {
            switch(quitEvent->key.keysym.sym)
            {
                case SDLK_w:
                    actorRect.y -= 2;
                    break;
                case SDLK_s:
                    actorRect.y +=2;
                    break;
                case SDLK_a:
                    actorRect.x -= 2;
                    break;
                case SDLK_d:
                    actorRect.x += 2;
                    break;
            }
        }*/
        if (keystates[SDL_SCANCODE_W] && actorRect.y > -actorRect.h / 4){actorRect.y -= 1;}
        if (keystates[SDL_SCANCODE_S] && actorRect.y < backRect.h - actorRect.h / 2){actorRect.y += 1;}
        if (keystates[SDL_SCANCODE_A] && actorRect.x > -actorRect.w / 2){actorRect.x -= 1;}
        if (keystates[SDL_SCANCODE_D] && actorRect.x < backRect.w - actorRect.w / 2){actorRect.x += 1;}

        if(bulletRect.x != 0){bulletRect.x -= 1;}
        else
            {bulletRect.x = 580;
            bulletRect.y = 1 + rand() % 380;}

        if(bulletRect.x < actorRect.x)
        {
            cout << bulletRect.x << " " << actorRect.x << endl;
            bulletRect.x = 580;
            bulletRect.y = 1 + rand() % 380;
        }

        if((bulletRect.x < actorRect.x + actorRect.w) &&
           (bulletRect.y < actorRect.y + actorRect.h) &&
           (bulletRect.y + bulletRect.h > actorRect.y))
        {
            SDL_DestroyTexture(actor);
            SDL_DestroyTexture(bullet);
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, background, NULL, &backRect);
        SDL_RenderCopy(renderer, actor, NULL, &actorRect);
        SDL_RenderCopy(renderer, bullet, NULL, &bulletRect);

        SDL_Delay(3);

        SDL_RenderPresent(renderer);
    }

    //== Free memory ===
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete quitEvent;
    return 0;
}
