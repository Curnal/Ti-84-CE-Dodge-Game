/*
 *--------------------------------------
 * Program Name: TETRIS
 * Author: LanguageArtsGrade#6949
 * License:
 * Description: Practice C gfx.
 *--------------------------------------
*/

#include <tice.h>
#include <graphx.h>
#include <stdlib.h>
#include <keypadc.h>
#include "gfx/gfx.h"


#define START_X ((LCD_WIDTH - shape_width) / 2)
#define START_Y ((LCD_HEIGHT - shape_height) / 2)

gfx_UninitedSprite(background, shape_width, shape_height);

void DrawSprite(int x, int y);
void PrintCentered(const char *str);
void PrintText(int8_t xpos, int8_t ypos, const char *text);


int main(void)
{
    int i;


    gfx_Begin();

    PrintCentered("DODGE THE CIRCLES || LanguageArtsGrade");

    while (!os_GetCSC());
    os_ClrHome();


    background->width = shape_width;
    background->height = shape_height;

    int x = START_X;
    int y = START_Y;

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_FillScreen(1);
    gfx_SetTransparentColor(0);
    gfx_SetDrawBuffer();

    for (i = 0; i < 5; ++i)
    {

        gfx_Sprite_NoClip(bgcirc,randInt(0, 320 - bgcirc_width),randInt(0, 240 - bgcirc_height));
    }


    gfx_GetSprite(background, x, y);
    DrawSprite(x, y);

    gfx_BlitBuffer();



    gfx_End();

    do
        {
            kb_key_t arrows;

            /* Scan the keypad to update kb_Data */
            kb_Scan();

            /* Get the arrow key statuses */
            arrows = kb_Data[7];

            /* Check if any arrows are pressed */
            if (arrows)
            {
                /* Do different directions depending on the keypress */
                if (arrows & kb_Right)
                {
                    x += 2;
                }
                if (arrows & kb_Left)
                {
                    x -= 2;
                }
                if (arrows & kb_Down)
                {
                    y += 2;
                }
                if (arrows & kb_Up)
                {
                    y -= 2;
                }

                /* Render the sprite */
                DrawSprite(x, y);

                /* Copy the buffer to the screen */
                /* Same as gfx_Blit(gfx_buffer) */
                gfx_BlitBuffer();
            }

        } while (kb_Data[6] != kb_Clear);

    return 0;
}

void PrintCentered(const char *str)
{
    gfx_PrintStringXY(str,
                      (LCD_WIDTH - gfx_GetStringWidth(str)) / 2,
                      (LCD_HEIGHT - 8) / 2);
}

void PrintText(int8_t xpos, int8_t ypos, const char *text)
{
    os_SetCursorPos(ypos, xpos);
    os_PutStrFull(text);
}

void DrawSprite(int x, int y)
{
    static int oldX = START_X;
    static int oldY = START_Y;

    /* Render the original background */
    gfx_Sprite(background, oldX, oldY);

    /* Get the background behind the sprite */
    gfx_GetSprite(background, x, y);

    /* Render the sprite */
    gfx_TransparentSprite(shape, x, y);

    oldX = x;
    oldY = y;
}


