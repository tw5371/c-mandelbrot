#include <SFML/Graphics.h>
#include <stdio.h>
#include <time.h>
#include "render.h"
int main(void) {
    printf("Mandelbrot Set Renderer\nIteration count (values over 1000 may take multiple seconds to render) >> ");
    unsigned int iter;
    scanf("%u",&iter);
    printf("Initializing window...\n");
    sfRenderWindow* win = sfRenderWindow_create((sfVideoMode){1200,800},"Mandelbrot Set Renderer",sfClose,0);
    clock_t start = clock();
    printf("Rendering Mandelbrot...\n");
    sfImage* buffer = RenderMandelbrot(iter,(sfVector2f){-2,1},(sfVector2i){1200,800});
    clock_t end = clock() - start;
    printf("Rendered Mandelbrot in %.2lf seconds with %u iterations\nDisplaying window...\n",(double)end/CLOCKS_PER_SEC,iter);
    sfSprite* bufferdisp = sfSprite_create();
    sfSprite_setTexture(bufferdisp,sfTexture_createFromImage(buffer,0),1);
    sfSprite_setPosition(bufferdisp,(sfVector2f){0,0});
    sfEvent ev;
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win,&ev)) {
            switch (ev.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(win);
                    return 0;
            }
        }
        sfRenderWindow_clear(win,sfBlack);
        sfRenderWindow_drawSprite(win,bufferdisp,0);
        sfRenderWindow_display(win);
    }
    return 1;
}