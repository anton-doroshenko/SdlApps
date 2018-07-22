#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int SCR_WIDTH = 640;
const int SCR_HEIGHT = 480;

int main()
{
    cout << "Test" << endl;
    SDL_Window* window = NULL;
    SDL_Surface* scrSurface = NULL;
    SDL_Texture *tex = NULL;
    SDL_Renderer *ren = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << endl;
    }
    else
    {
        window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        }
        else
        {
            ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(ren == NULL)
            {
                cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
            }
            else
            {
                scrSurface = SDL_GetWindowSurface(window);
                scrSurface = SDL_LoadBMP("p.bmp");
                SDL_UpdateWindowSurface(window);
                if (scrSurface == NULL)
                {
                    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
                }
                else
                {
                    tex = SDL_CreateTextureFromSurface(ren, scrSurface);
                    SDL_FreeSurface(scrSurface);
                    if(tex == NULL)
                    {
                        cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
                    }
                }
            }
            for(int i = 0; i < 3; i++)
            {
                SDL_RenderClear(ren);
                SDL_RenderCopy(ren, tex, NULL, NULL);
                SDL_RenderPresent(ren);
                //scrSurface = SDL_GetWindowSurface(window);
                //SDL_FillRect(scrSurface, NULL, SDL_MapRGB(scrSurface->format, 0x1F, 0x2F, 0x3F));
                //SDL_UpdateWindowSurface(window);
                SDL_Delay(1000);
            }
        }
    }
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
