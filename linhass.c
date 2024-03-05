#include <allegro.h> 
#include <stdlib.h> 
#include "variaveis.h" 

void cria_linha1()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[0], 8,273 );     
    hline(screen, 57, 284, 746, makecol(43,  122, 64));
    hline(screen, 57, 285, 746, makecol(43,  122, 64));
    hline(screen, 57, 286, 746, makecol(43,  122, 64));
    hline(screen, 57, 287, 746, makecol(43,  122, 64));        
    hline(screen, 57, 288, 746, makecol(43,  122, 64));
    hline(screen, 57, 289, 746, makecol(43,  122, 64));


}

void cria_linha2()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[1], 8,153 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[1], 8,153 );  
    hline(screen, 57,  171, 746, makecol(249, 190, 9));
    hline(screen, 57,  172, 746, makecol(249, 190, 9));
    hline(screen, 57,  173, 746, makecol(249, 190, 9));
    hline(screen, 57,  174, 746, makecol(249, 190, 9));
    hline(screen, 57,  175, 746, makecol(249, 190, 9));
    hline(screen, 57,  176, 746, makecol(249, 190, 9));
}   

void cria_linha3()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[2], 8,387 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[2], 8,387 );  
    hline(screen, 57,  399, 746, makecol(177,48,108 ));
    hline(screen, 57,  400, 746, makecol(177,48,108 ));
    hline(screen, 57,  401, 746, makecol(177,48,108 ));
    hline(screen, 57,  402, 746, makecol(177,48,108 ));
    hline(screen, 57,  403, 746, makecol(177,48,108 ));
    hline(screen, 57,  404, 746, makecol(177,48,108 ));
}

void cria_linha4()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[3], 7,63 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[3], 7,63 );  
    line(screen, 55,90,405,440, makecol(216,37,32 ));
    line(screen, 55,91,405,441, makecol(216,37,32 ));
    line(screen, 55,92,405,442, makecol(216,37,32 ));
    line(screen, 55,93,405,443, makecol(216,37,32 ));
    line(screen, 55,94,405,444, makecol(216,37,32 ));
    line(screen, 55,95,405,445, makecol(216,37,32 ));
    line(screen, 55,96,405,446, makecol(216,37,32 ));
    line(screen, 755,90,405,440, makecol(216,37,32 ));
    line(screen, 755,91,405,441, makecol(216,37,32 ));
    line(screen, 755,92,405,442, makecol(216,37,32 ));
    line(screen, 755,93,405,443, makecol(216,37,32 ));
    line(screen, 755,94,405,444, makecol(216,37,32 ));
    line(screen, 755,95,405,445, makecol(216,37,32 ));
    line(screen, 755,96,405,446, makecol(216,37,32 ));
}

void cria_linha5()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[4], 7,474 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[4], 7,474 );  
    line(screen, 55,474,390,139, makecol(247,247,247 ));
    line(screen, 55,475,390,140, makecol(247,247,247 ));
    line(screen, 55,476,390,141, makecol(247,247,247 ));
    line(screen, 55,477,390,142, makecol(247,247,247 ));
    line(screen, 55,478,390,143, makecol(247,247,247 ));
    line(screen, 55,479,390,144, makecol(247,247,247 ));
    line(screen, 55,480,390,145, makecol(247,247,247 ));
    line(screen, 390,139,745,470, makecol(247,247,247 ));
    line(screen, 390,140,745,471, makecol(247,247,247 ));
    line(screen, 390,141,745,472, makecol(247,247,247 ));
    line(screen, 390,142,745,473, makecol(247,247,247 ));
    line(screen, 390,143,745,474, makecol(247,247,247 ));
    line(screen, 390,144,745,475, makecol(247,247,247 ));
    line(screen, 390,145,745,476, makecol(247,247,247 ));
}    

void cria_linha6()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[5], 7,121 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[5], 7,121 );  
    hline(screen, 55, 131, 220, makecol(228, 129, 20));
    hline(screen, 55, 132, 220, makecol(228, 129, 20));
    hline(screen, 55, 133, 220, makecol(228, 129, 20));
    hline(screen, 55, 134, 220, makecol(228, 129, 20));
    hline(screen, 55, 135, 220, makecol(228, 129, 20));
    hline(screen, 55, 136, 220, makecol(228, 129, 20));
    line(screen, 220, 131,555,466, makecol(228, 129, 20));
    line(screen, 220, 132,555,467, makecol(228, 129, 20));
    line(screen, 220, 133,555,468, makecol(228, 129, 20));
    line(screen, 220, 134,555,469, makecol(228, 129, 20));
    line(screen, 220, 135,555,470, makecol(228, 129, 20));
    line(screen, 220, 136,555,471, makecol(228, 129, 20));
    line(screen, 220, 137,555,472, makecol(228, 129, 20));
    hline(screen, 555, 467, 745, makecol(228, 129, 20));
    hline(screen, 555, 468, 745, makecol(228, 129, 20));
    hline(screen, 555, 469, 745, makecol(228, 129, 20));
    hline(screen, 555, 470, 745, makecol(228, 129, 20));
    hline(screen, 555, 471, 745, makecol(228, 129, 20));
    hline(screen, 555, 472, 745, makecol(228, 129, 20));
}

void cria_linha7()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[6], 7,430 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[6], 7,430 );  
    hline(screen, 55, 441, 220, makecol(214, 138, 175));
    hline(screen, 55, 442, 220, makecol(214, 138, 175));
    hline(screen, 55, 443, 220, makecol(214, 138, 175));
    hline(screen, 55, 444, 220, makecol(214, 138, 175));
    hline(screen, 55, 445, 220, makecol(214, 138, 175));
    hline(screen, 55, 446, 220, makecol(214, 138, 175));
    line(screen, 220, 439,555,105, makecol(214, 138, 175));
    line(screen, 220, 440,555,106, makecol(214, 138, 175));
    line(screen, 220, 441,555,107, makecol(214, 138, 175));
    line(screen, 220, 442,555,108, makecol(214, 138, 175));
    line(screen, 220, 443,555,109, makecol(214, 138, 175));
    line(screen, 220, 444,555,110, makecol(214, 138, 175));
    line(screen, 220, 445,555,111, makecol(214, 138, 175));
    line(screen, 220, 446,555,112, makecol(214, 138, 175));
    hline(screen, 555, 105, 745, makecol(214, 138, 175));
    hline(screen, 555, 106, 745, makecol(214, 138, 175));
    hline(screen, 555, 107, 745, makecol(214, 138, 175));
    hline(screen, 555, 108, 745, makecol(214, 138, 175));
    hline(screen, 555, 109, 745, makecol(214, 138, 175));
    hline(screen, 555, 110, 745, makecol(214, 138, 175));
}

void cria_linha8()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[7], 7,201 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[7], 7,201 );  
    hline(screen, 57, 225, 82, makecol(198, 168, 104));
    hline(screen, 57, 226, 82, makecol(198, 168, 104));
    hline(screen, 57, 227, 82, makecol(198, 168, 104));
    hline(screen, 57, 228, 82, makecol(198, 168, 104));
    hline(screen, 57, 229, 82, makecol(198, 168, 104));
    hline(screen, 57, 230, 82, makecol(198, 168, 104));
    line(screen, 82, 225,313,456, makecol(198, 168, 104));
    line(screen, 82, 226,313,457, makecol(198, 168, 104));
    line(screen, 82, 227,313,458, makecol(198, 168, 104));
    line(screen, 82, 228,313,459, makecol(198, 168, 104));
    line(screen, 82, 229,313,460, makecol(198, 168, 104));
    line(screen, 82, 230,313,461, makecol(198, 168, 104));
    line(screen, 82, 231,313,462, makecol(198, 168, 104));
    hline(screen, 313, 457, 489, makecol(198, 168, 104));
    hline(screen, 313, 458, 489, makecol(198, 168, 104));
    hline(screen, 313, 459, 489, makecol(198, 168, 104));
    hline(screen, 313, 460, 489, makecol(198, 168, 104));
    hline(screen, 313, 461, 489, makecol(198, 168, 104));
    hline(screen, 313, 462, 489, makecol(198, 168, 104));
    line(screen, 489, 456, 720,225, makecol(198, 168, 104));
    line(screen, 489, 457, 720,226, makecol(198, 168, 104));
    line(screen, 489, 458, 720,227, makecol(198, 168, 104));
    line(screen, 489, 459, 720,228, makecol(198, 168, 104));
    line(screen, 489, 460, 720,229, makecol(198, 168, 104));
    line(screen, 489, 461, 720,230, makecol(198, 168, 104));
    line(screen, 489, 462, 720,231, makecol(198, 168, 104));
    hline(screen, 720, 225, 745, makecol(198, 168, 104));
    hline(screen, 720, 226, 745, makecol(198, 168, 104));
    hline(screen, 720, 227, 745, makecol(198, 168, 104));
    hline(screen, 720, 228, 745, makecol(198, 168, 104));
    hline(screen, 720, 229, 745, makecol(198, 168, 104));
    hline(screen, 720, 230, 745, makecol(198, 168, 104));
}
void cria_linha9()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[8], 7,340 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[8], 7,340 );  
    hline(screen, 57, 345, 82, makecol(8,93,160));
    hline(screen, 57, 346, 82, makecol(8,93,160));
    hline(screen, 57, 347, 82, makecol(8,93,160));
    hline(screen, 57, 348, 82, makecol(8,93,160));
    hline(screen, 57, 349, 82, makecol(8,93,160));
    hline(screen, 57, 350, 82, makecol(8,93,160));
    line(screen, 82, 345, 295, 133, makecol(8,93,160));
    line(screen, 82, 346, 295, 134, makecol(8,93,160));
    line(screen, 82, 347, 295, 135, makecol(8,93,160));
    line(screen, 82, 348, 295, 136, makecol(8,93,160));
    line(screen, 82, 349, 295, 137, makecol(8,93,160));
    line(screen, 82, 349, 295, 138, makecol(8,93,160));
    line(screen, 82, 350, 295, 139, makecol(8,93,160));
    hline(screen, 295, 133, 504, makecol(8,93,160));
    hline(screen, 295, 134, 504, makecol(8,93,160));
    hline(screen, 295, 135, 504, makecol(8,93,160));
    hline(screen, 295, 136, 504, makecol(8,93,160));
    hline(screen, 295, 137, 504, makecol(8,93,160));
    hline(screen, 295, 138, 504, makecol(8,93,160));
    line(screen, 504, 133, 716, 345, makecol(8,93,160));
    line(screen, 504, 134, 716, 346, makecol(8,93,160));
    line(screen, 504, 135, 716, 347, makecol(8,93,160));
    line(screen, 504, 136, 716, 348, makecol(8,93,160));
    line(screen, 504, 137, 716, 349, makecol(8,93,160));
    line(screen, 504, 138, 716, 350, makecol(8,93,160));
    line(screen, 504, 139, 716, 351, makecol(8,93,160));
    hline(screen, 716, 346, 745, makecol(8,93,160));
    hline(screen, 716, 347, 745, makecol(8,93,160));
    hline(screen, 716, 348, 745, makecol(8,93,160));
    hline(screen, 716, 349, 745, makecol(8,93,160));
    hline(screen, 716, 350, 745, makecol(8,93,160));
    hline(screen, 716, 351, 745, makecol(8,93,160));
}

void cria_linha10()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[9], 7,312 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[9], 7,312 );  
    hline(screen, 57, 326, 82, makecol(153, 194, 209));
    hline(screen, 57, 327, 82, makecol(153, 194, 209));
    hline(screen, 57, 328, 82, makecol(153, 194, 209));
    hline(screen, 57, 329, 82, makecol(153, 194, 209));
    hline(screen, 57, 330, 82, makecol(153, 194, 209));
    hline(screen, 57, 331, 82, makecol(153, 194, 209));
    line(screen, 82, 325,277,130, makecol(153, 194, 209));
    line(screen, 82, 326,277,131, makecol(153, 194, 209));
    line(screen, 82, 327,277,132, makecol(153, 194, 209));
    line(screen, 82, 328,277,133, makecol(153, 194, 209));
    line(screen, 82, 329,277,134, makecol(153, 194, 209));
    line(screen, 82, 330,277,135, makecol(153, 194, 209));
    line(screen, 82, 331,277,136, makecol(153, 194, 209));
    line(screen, 277, 131,565,420, makecol(153, 194, 209));
    line(screen, 277, 132,565,421, makecol(153, 194, 209));
    line(screen, 277, 133,565,422, makecol(153, 194, 209));
    line(screen, 277, 134,565,423, makecol(153, 194, 209));
    line(screen, 277, 135,565,424, makecol(153, 194, 209));
    line(screen, 277, 136,565,425, makecol(153, 194, 209));
    line(screen, 277, 137,565,426, makecol(153, 194, 209));
    line(screen, 565, 420,745,240, makecol(153, 194, 209));
    line(screen, 565, 421,745,241, makecol(153, 194, 209));
    line(screen, 565, 422,745,242, makecol(153, 194, 209));
    line(screen, 565, 423,745,243, makecol(153, 194, 209));
    line(screen, 565, 424,745,244, makecol(153, 194, 209));
    line(screen, 565, 425,745,245, makecol(153, 194, 209));
    line(screen, 565, 426,745,246, makecol(153, 194, 209));
}

void cria_linha11()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[10], 750,362 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[10], 750,362 );  
    line(screen, 550, 163,745,360, makecol(177, 48, 108));
    line(screen, 550, 164,745,361, makecol(177, 48, 108));
    line(screen, 550, 165,745,362, makecol(177, 48, 108));
    line(screen, 550, 166,745,363, makecol(177, 48, 108));
    line(screen, 550, 167,745,364, makecol(177, 48, 108));
    line(screen, 550, 168,745,365, makecol(177, 48, 108));
    line(screen, 550, 169,745,366, makecol(177, 48, 108));
    line(screen, 280, 453,550,163, makecol(177, 48, 108));
    line(screen, 280, 454,550,164, makecol(177, 48, 108));
    line(screen, 280, 455,550,165, makecol(177, 48, 108));
    line(screen, 280, 456,550,166, makecol(177, 48, 108));
    line(screen, 280, 457,550,167, makecol(177, 48, 108));
    line(screen, 280, 458,550,168, makecol(177, 48, 108));
    line(screen, 280, 459,550,169, makecol(177, 48, 108));
    hline(screen, 57, 255, 82, makecol(177, 48, 108));
    hline(screen, 57, 256, 82, makecol(177, 48, 108));
    hline(screen, 57, 257, 82, makecol(177, 48, 108));
    hline(screen, 57, 258, 82, makecol(177, 48, 108));
    hline(screen, 57, 259, 82, makecol(177, 48, 108));
    hline(screen, 57, 260, 82, makecol(177, 48, 108));
    line(screen, 82, 255,280,453, makecol(177, 48, 108));
    line(screen, 82, 256,280,454, makecol(177, 48, 108));
    line(screen, 82, 257,280,455, makecol(177, 48, 108));
    line(screen, 82, 258,280,456, makecol(177, 48, 108));
    line(screen, 82, 259,280,457, makecol(177, 48, 108));
    line(screen, 82, 260,280,458, makecol(177, 48, 108));
    line(screen, 82, 261,280,459, makecol(177, 48, 108));
}

void cria_linha12()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[11], 750,102 );  
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[11], 750,102 );  
    hline(screen, 420, 108, 747, makecol(228, 129, 20));    
    hline(screen, 420, 109, 747, makecol(228, 129, 20));
    hline(screen, 420, 110, 747, makecol(228, 129, 20));
    hline(screen, 420, 111, 747, makecol(228, 129, 20));
    hline(screen, 420, 112, 747, makecol(228, 129, 20));
    hline(screen, 420, 113, 747, makecol(228, 129, 20));
    line(screen, 57, 470,420,108, makecol(228, 129, 20));
    line(screen, 57, 471,420,109, makecol(228, 129, 20));
    line(screen, 57, 472,420,110, makecol(228, 129, 20));
    line(screen, 57, 473,420,111, makecol(228, 129, 20));
    line(screen, 57, 474,420,112, makecol(228, 129, 20));
    line(screen, 57, 475,420,113, makecol(228, 129, 20));
    line(screen, 57, 476,420,114, makecol(228, 129, 20));
}

void cria_linha13()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[12], 750,436 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[12], 750,436 );
    hline(screen, 420, 452, 747, makecol(8, 93, 160));    
    hline(screen, 420, 453, 747, makecol(8, 93, 160));
    hline(screen, 420, 454, 747, makecol(8, 93, 160));
    hline(screen, 420, 455, 747, makecol(8, 93, 160));
    hline(screen, 420, 456, 747, makecol(8, 93, 160));
    hline(screen, 420, 457, 747, makecol(8, 93, 160));
    line(screen, 57, 91,420,452, makecol(8, 93, 160));
    line(screen, 57, 92,420,453, makecol(8, 93, 160));
    line(screen, 57, 93,420,454, makecol(8, 93, 160));
    line(screen, 57, 94,420,455, makecol(8, 93, 160));
    line(screen, 57, 95,420,456, makecol(8, 93, 160));
    line(screen, 57, 96,420,457, makecol(8, 93, 160));
    line(screen, 57, 97,420,457, makecol(8, 93, 160));
}

void cria_linha14()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[13], 750,410 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[13], 750,410 );
    hline(screen, 700, 428, 746, makecol(153, 194, 209));
    hline(screen, 700, 429, 746, makecol(153, 194, 209));
    hline(screen, 700, 430, 746, makecol(153, 194, 209));
    hline(screen, 700, 431, 746, makecol(153, 194, 209));
    hline(screen, 700, 432, 746, makecol(153, 194, 209));
    hline(screen, 700, 433, 746, makecol(153, 194, 209));
    line(screen,  400, 128, 700,428, makecol(153, 194, 209));
    line(screen,  400, 129, 700,429, makecol(153, 194, 209));
    line(screen,  400, 130, 700,430, makecol(153, 194, 209));
    line(screen,  400, 131, 700,431, makecol(153, 194, 209));
    line(screen,  400, 132, 700,432, makecol(153, 194, 209));
    line(screen,  400, 133, 700,433, makecol(153, 194, 209));
    line(screen,  400, 134, 700,434, makecol(153, 194, 209));
    hline(screen, 57, 128, 400, makecol(153, 194, 209));
    hline(screen, 57, 129, 400, makecol(153, 194, 209));
    hline(screen, 57, 130, 400, makecol(153, 194, 209));
    hline(screen, 57, 131, 400, makecol(153, 194, 209));
    hline(screen, 57, 132, 400, makecol(153, 194, 209));
    hline(screen, 57, 132, 400, makecol(153, 194, 209));
}

void cria_linha15()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[14], 750,128 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[14], 750,128 );
    hline(screen, 700, 128, 746, makecol(249, 190, 9));
    hline(screen, 700, 129, 746, makecol(249, 190, 9));
    hline(screen, 700, 130, 746, makecol(249, 190, 9));
    hline(screen, 700, 131, 746, makecol(249, 190, 9));
    hline(screen, 700, 132, 746, makecol(249, 190, 9));
    hline(screen, 700, 133, 746, makecol(249, 190, 9));
    line(screen, 390,438,700,128, makecol(249, 190, 9));
    line(screen, 390,439,700,129, makecol(249, 190, 9));
    line(screen, 390,440,700,130, makecol(249, 190, 9));
    line(screen, 390,441,700,131, makecol(249, 190, 9));
    line(screen, 390,442,700,132, makecol(249, 190, 9));
    line(screen, 390,443,700,133, makecol(249, 190, 9));
    hline(screen, 57, 438, 390, makecol(249, 190, 9));
    hline(screen, 57, 439, 390, makecol(249, 190, 9));
    hline(screen, 57, 440, 390, makecol(249, 190, 9));
    hline(screen, 57, 441, 390, makecol(249, 190, 9));
    hline(screen, 57, 442, 390, makecol(249, 190, 9));
    hline(screen, 57, 443, 390, makecol(249, 190, 9));
}

void cria_linha16()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[15], 750,308 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[15], 750,308 );
    hline(screen, 700, 308, 746, makecol(43, 122, 64));
    hline(screen, 700, 309, 746, makecol(43, 122, 64));
    hline(screen, 700, 310, 746, makecol(43, 122, 64));
    hline(screen, 700, 311, 746, makecol(43, 122, 64));
    hline(screen, 700, 312, 746, makecol(43, 122, 64));
    hline(screen, 700, 313, 746, makecol(43, 122, 64));
    line(screen, 500,108,700,308, makecol(43, 122, 64));
    line(screen, 500,109,700,309, makecol(43, 122, 64));
    line(screen, 500,110,700,310, makecol(43, 122, 64));
    line(screen, 500,111,700,311, makecol(43, 122, 64));
    line(screen, 500,112,700,312, makecol(43, 122, 64));
    line(screen, 500,113,700,313, makecol(43, 122, 64));
    hline(screen, 57, 108, 500, makecol(43, 122, 64));
    hline(screen, 57, 109, 500, makecol(43, 122, 64));
    hline(screen, 57, 110, 500, makecol(43, 122, 64));
    hline(screen, 57, 111, 500, makecol(43, 122, 64));
    hline(screen, 57, 112, 500, makecol(43, 122, 64));
    hline(screen, 57, 113, 500, makecol(43, 122, 64));
}

void cria_linha17()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[16], 750,231 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[16], 750,231 );
    hline(screen, 700, 250, 746, makecol(214, 138, 175)); 
    hline(screen, 700, 251, 746, makecol(214, 138, 175));
    hline(screen, 700, 252, 746, makecol(214, 138, 175));
    hline(screen, 700, 253, 746, makecol(214, 138, 175));
    hline(screen, 700, 254, 746, makecol(214, 138, 175));
    hline(screen, 700, 255, 746, makecol(214, 138, 175));
    line(screen, 500,450,700,250, makecol(214, 138, 175));
    line(screen, 500,451,700,251, makecol(214, 138, 175));
    line(screen, 500,452,700,252, makecol(214, 138, 175));
    line(screen, 500,453,700,253, makecol(214, 138, 175));
    line(screen, 500,454,700,254, makecol(214, 138, 175));
    line(screen, 500,455,700,255, makecol(214, 138, 175));
    hline(screen, 57, 450, 500, makecol(214, 138, 175));
    hline(screen, 57, 451, 500, makecol(214, 138, 175));
    hline(screen, 57, 452, 500, makecol(214, 138, 175));
    hline(screen, 57, 453, 500, makecol(214, 138, 175));
    hline(screen, 57, 454, 500, makecol(214, 138, 175));
    hline(screen, 57, 455, 500, makecol(214, 138, 175));
}

void cria_linha18()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[17], 750,70 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[17], 750,70 );
    hline(screen, 280, 96, 746, makecol(247, 247, 247));
    hline(screen, 280, 97, 746, makecol(247, 247, 247));
    hline(screen, 280, 98, 746, makecol(247, 247, 247));
    hline(screen, 280, 99, 746, makecol(247, 247, 247));
    hline(screen, 280, 100, 746, makecol(247, 247, 247));
    hline(screen, 280, 101, 746, makecol(247, 247, 247));
    line(screen, 57,320,280,96, makecol(247, 247, 247));
    line(screen, 57,321,280,97, makecol(247, 247, 247));
    line(screen, 57,322,280,98, makecol(247, 247, 247));
    line(screen, 57,323,280,99, makecol(247, 247, 247));
    line(screen, 57,324,280,100, makecol(247, 247, 247));
    line(screen, 57,325,280,101, makecol(247, 247, 247));
    line(screen, 57,326,280,102, makecol(247, 247, 247));
}


void cria_linha19()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[18], 750,462 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[18], 750,462 );
    hline(screen, 280, 463, 746, makecol(216, 37, 32));
    hline(screen, 280, 464, 746, makecol(216, 37, 32));
    hline(screen, 280, 465, 746, makecol(216, 37, 32));
    hline(screen, 280, 466, 746, makecol(216, 37, 32));
    hline(screen, 280, 467, 746, makecol(216, 37, 32));
    hline(screen, 280, 468, 746, makecol(216, 37, 32));
    line(screen, 57,240,280,463, makecol(216, 37, 32));
    line(screen, 57,241,280,464, makecol(216, 37, 32));
    line(screen, 57,242,280,465, makecol(216, 37, 32));
    line(screen, 57,243,280,466, makecol(216, 37, 32));
    line(screen, 57,244,280,467, makecol(216, 37, 32));
    line(screen, 57,245,280,468, makecol(216, 37, 32));
    line(screen, 57,246,280,469, makecol(216, 37, 32));
}

void cria_linha20()
{
    if (i_TLinha==0) draw_sprite(screen, BMP_LINHAS[19], 750,152 );
    if (i_TLinha==1) draw_sprite(screen, BMP_LINHAS_P[19], 750,152 );
    hline(screen, 685, 160, 746, makecol(211, 109, 123));
    hline(screen, 685, 161, 746, makecol(211, 109, 123));
    hline(screen, 685, 162, 746, makecol(211, 109, 123));
    hline(screen, 685, 163, 746, makecol(211, 109, 123));
    hline(screen, 685, 164, 746, makecol(211, 109, 123));
    hline(screen, 685, 165, 746, makecol(211, 109, 123));
    line(screen, 520, 300,685,160, makecol(211, 109, 123));
    line(screen, 520, 301,685,161, makecol(211, 109, 123));
    line(screen, 520, 302,685,162, makecol(211, 109, 123));
    line(screen, 520, 303,685,163, makecol(211, 109, 123));
    line(screen, 520, 304,685,164, makecol(211, 109, 123));
    line(screen, 520, 305,685,165, makecol(211, 109, 123));
    line(screen, 520, 306,685,166, makecol(211, 109, 123));
    hline(screen, 58, 375, 130, makecol(211, 109, 123));
    hline(screen, 58, 376, 130, makecol(211, 109, 123));
    hline(screen, 58, 377, 130, makecol(211, 109, 123));
    hline(screen, 58, 378, 130, makecol(211, 109, 123));
    hline(screen, 58, 379, 130, makecol(211, 109, 123));
    hline(screen, 58, 380, 130, makecol(211, 109, 123));
    line(screen, 130, 375,240,300, makecol(211, 109, 123));
    line(screen, 130, 376,240,301, makecol(211, 109, 123));
    line(screen, 130, 377,240,302, makecol(211, 109, 123));
    line(screen, 130, 378,240,303, makecol(211, 109, 123));
    line(screen, 130, 379,240,304, makecol(211, 109, 123));
    line(screen, 130, 380,240,305, makecol(211, 109, 123));
    line(screen, 130, 381,240,306, makecol(211, 109, 123));
    hline(screen, 240, 300, 520, makecol(211, 109, 123));
    hline(screen, 240, 301, 520, makecol(211, 109, 123));
    hline(screen, 240, 302, 520, makecol(211, 109, 123));
    hline(screen, 240, 303, 520, makecol(211, 109, 123));
    hline(screen, 240, 304, 520, makecol(211, 109, 123));
    hline(screen, 240, 305, 520, makecol(211, 109, 123));
}

void cria_linha21()
{
    draw_sprite(screen, BMP_LINHAS[19], 750,152 ); 
    line(screen, 118,92,118,477, makecol(247,247,247 ));
    line(screen, 119,92,119,477, makecol(247,247,247 ));
    line(screen, 120,92,120,477, makecol(247,247,247 ));
    line(screen, 121,92,121,477, makecol(247,247,247 ));
    line(screen, 122,92,122,477, makecol(247,247,247 ));
}

void cria_linha22()
{
    draw_sprite(screen, BMP_LINHAS[19], 750,152 ); 
    line(screen, 256,92,256,477, makecol(247,247,247 ));
    line(screen, 257,92,257,477, makecol(247,247,247 ));
    line(screen, 258,92,258,477, makecol(247,247,247 ));
    line(screen, 259,92,259,477, makecol(247,247,247 ));
    line(screen, 260,92,260,477, makecol(247,247,247 ));
}


void cria_linha23()
{
    draw_sprite(screen, BMP_LINHAS[19], 750,152 ); 
    line(screen, 393,92,393,477, makecol(247,247,247 ));
    line(screen, 394,92,394,477, makecol(247,247,247 ));
    line(screen, 395,92,395,477, makecol(247,247,247 ));
    line(screen, 396,92,396,477, makecol(247,247,247 ));
    line(screen, 397,92,397,477, makecol(247,247,247 ));
}

void cria_linha24()
{
    draw_sprite(screen, BMP_LINHAS[19], 750,152 ); 
    line(screen, 531,92,531,477, makecol(247,247,247 ));
    line(screen, 532,92,532,477, makecol(247,247,247 ));
    line(screen, 533,92,533,477, makecol(247,247,247 ));
    line(screen, 534,92,534,477, makecol(247,247,247 ));
    line(screen, 535,92,535,477, makecol(247,247,247 ));
}

void cria_linha25()
{
    draw_sprite(screen, BMP_LINHAS[19], 750,152 ); 
    line(screen, 675,92,675,477, makecol(247,247,247 ));
    line(screen, 676,92,676,477, makecol(247,247,247 ));
    line(screen, 677,92,677,477, makecol(247,247,247 ));
    line(screen, 678,92,678,477, makecol(247,247,247 ));
    line(screen, 679,92,679,477, makecol(247,247,247 ));
}