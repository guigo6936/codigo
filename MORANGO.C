#include <allegro.h> 
#include <stdlib.h> 
#include "variaveis.h" 


void credita_s_tempo_m ()
{
    if(key[KEY_1] && ta_c_credito !=1 ){tecla_credito=1;ta_c_credito=1; _ani_s_credito=2800;}
    if(key[KEY_2] && ta_c_credito !=1){tecla_credito=2;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_3] && ta_c_credito !=1){tecla_credito=3;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_4] && ta_c_credito !=1){tecla_credito=4;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_5] && ta_c_credito !=1){tecla_credito=5;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_6] && ta_c_credito !=1){tecla_credito=6;ta_c_credito=1;  _ani_s_credito=2800;}
}

void marca_amarela(int quadrado);
void bonus_morando()  
{

 play_sample (sones[7].dat, 255, 128, 1000, 1);
 clear(buffer);
 conta_morango=0;
 int VER_MORANGO[16], VAL_MORANGO[12];
 int iprinc,i=0, ios=0, ip=0, im=1, val_morang, val_conta_m=0, b_multi_cald=0, play_1=0;

  b_multi_cald = valor_b_abobora * aposta1;
  if(b_multi_cald==0)b_multi_cald=1;
 
 for (i=0;i<15;i++)
     {
     VER_MORANGO[i]=0;
     }

 for (i=0;i<12;i++)
     {
     VAL_MORANGO[i]=0;
     }

 iprinc=0;     
 im=0;
 while (iprinc==0)
   {
     clear(buffer);
     draw_sprite(buffer, imagens[94].dat, 0,0 ); 


     if (key[KEY_B])
        { 
           if (VER_MORANGO[conta_morango]==0)
              {
                im++;                   
                   if((((pr_entrada_p-pr_saida_p)-credito-premio)) < 2000)
                     val_morang=VALORES_MORANGO[rand() % 30];
                   else
                   if((((pr_entrada_p-pr_saida_p)-credito-premio)) > 1999)
                     val_morang=VALORES_MORANGO[rand() % 100];
                   else  
                   if(b_multi_cald > 4)
                     val_morang=VALORES_MORANGO[rand() % 30];
                   else
                   if(b_multi_cald < 5)
                     val_morang=VALORES_MORANGO[rand() % 100];

                    
                    if (val_morang>99) val_morang=10;
                    
                   if(val_morang==0 && im <6)val_morang= 5 + rand()%18;
                     
                   if(val_morang==0 && im >5)im=12;
                   
                   if (im>11) val_morang=0;
                      
                    if (val_morang>0)
                       {
                            val_conta_m=val_conta_m+(val_morang*b_multi_cald);
                            VAL_MORANGO[conta_morango]=(val_morang);
                            play_sample (sones[17].dat, 255, 128, 1000, 0);        
                            stop_sample (sones[7].dat);
                            for (ip=0;ip<12;ip++)
                              {
                                 clear(buffer);
                                 draw_sprite(buffer, imagens[94].dat, 0,0 );
                                 for (i=0;i<12;i++)
                                   {
                                     if (VER_MORANGO[i]==0)
                                         draw_sprite(buffer, ANIMA_MORANGO1[ios], P_MORANG[i][0],P_MORANG[i][1] ); 
                                     else  
                                        {
                                          draw_sprite(buffer, ANIMA_MORANGO2[11], P_MORANG[i][0],P_MORANG[i][1] ); 
                                          atualiza_morango(CALD_BRUXA[i] * b_multi_cald, P_MORANG[i][0]+2, P_MORANG[i][1]+45 ); 
                                        }  
                 
                                   }
                                 VER_MORANGO[conta_morango]=1;
                                 draw_sprite(buffer, ANIMA_MORANGO2[ip], P_MORANG[conta_morango][0],P_MORANG[conta_morango][1] );         
                                 atualiza_roleta1(credito,150, 15);     
                                 atualiza_roleta1(premio+val_conta_m, 410, 15);     
                                 atualiza_roleta1(b_multi_cald, 660, 15);     
                                 blit(buffer,screen,0,0,0,0,800,600);    
                                 rest(50);
                              }  
                           play_sample (sones[7].dat, 255, 128, 1000, 1);   
                        }
                    else
                       {
                         blefe_bonus=0;
                         iprinc=1;
                         rest(1000);
                         stop_sample (sones[7].dat);   
                         play_sample (sones[15].dat, 255, 128, 1000, 0);                               
                          for (i=0;i<12;i++)
                               {
                                draw_sprite(screen, ANIMA_MORANGO3[i], P_MORANG[conta_morango][0],P_MORANG[conta_morango][1] ); 
                                rest(100);
             
                               }
                             VER_MORANGO[conta_morango]=1;
                             atualiza_roleta1(credito,150, 15);     
                             atualiza_roleta1(premio+val_conta_m, 410, 15);     
                             atualiza_roleta1(b_multi_cald, 660, 15);     
                             rest(50);

                       }           
               conta_morango++;
               if (conta_morango==12)conta_morango=0;
               i=0;
               rest(50);
             }
        }
        
        
     for (i=0;i<12;i++)
        {
          if (VER_MORANGO[i]==0)
              draw_sprite(buffer, ANIMA_MORANGO1[ios], P_MORANG[i][0],P_MORANG[i][1] ); 
          else  
            {
              draw_sprite(buffer, ANIMA_MORANGO2[11], P_MORANG[i][0],P_MORANG[i][1] ); 
              atualiza_morango(CALD_BRUXA[i] * b_multi_cald, P_MORANG[i][0]+2, P_MORANG[i][1]+45 ); 
            }  
        }
      i=0;  
     
     if (key[KEY_Y] || key[KEY_J] || key[KEY_H] || key[KEY_M] || key[KEY_N] || key[KEY_T] || key[KEY_V] || key[KEY_F] || key[KEY_G])
        {
          conta_morango++;         
          if (conta_morango==12)conta_morango=0;
          play_sample (sones[31].dat, 255, 128, 1000, 0);          
          rest(450);             
        }
        
        
     if (blefe_bonus>0)
        {   
         marca_amarela(conta_morango);
         atualiza_roleta1(credito,150, 15);     
         atualiza_roleta1(premio+val_conta_m, 410, 15);     
         atualiza_roleta1(b_multi_cald, 660, 15);     
    
         blit(buffer,screen,0,0,0,0,800,600);    
         ios++;
         if (ios==12) ios=0;
        } 

   }  
    clear(buffer);
    stop_sample (sones[7].dat);   
    premio=premio+val_conta_m;
    val_conta_m=0;
    rest(2000);
} 

void marca_amarela(int quadrado)
{
int i;

 for (i=0;i<4;i++)
   {
     rect(buffer, quad[quadrado][0]-i, quad[quadrado][1]-i, quad[quadrado][2]+i, quad[quadrado][3]+i, makecol(255, 204, 0));        
   } 
}


void bonus_morando_anima()
{
 credita_s_tempo_m();
 tempo=0;
 int i=0, is=0, ios=0;
 while (tempo<40)
   {
     credita_s_tempo_m();
     clear(buffer);
     credita_s_tempo_m();
     draw_sprite(buffer, imagens[94].dat, 0,0 ); 
     credita_s_tempo_m();
     
     if(tempo<20)
       {
         credita_s_tempo_m();
         for (i=0;i<12;i++)
           {
             credita_s_tempo_m();
             draw_sprite(buffer, ANIMA_MORANGO1[ios], P_MORANG[i][0],P_MORANG[i][1] );
             credita_s_tempo_m();
           } 
        }   
     else
        {
          for (i=0;i<12;i++)
            {
             credita_s_tempo_m();
             draw_sprite(buffer, ANIMA_MORANGO2[i], P_MORANG[5][0],P_MORANG[5][1] );
             credita_s_tempo_m();
             atualiza_morango(500, P_MORANG[5][0]-10, P_MORANG[5][1]+45 ); 
             credita_s_tempo_m();
            }  
         }   

     marca_amarela(5);
     credita_s_tempo_m();
     atualiza_roleta1(5000,150, 15);     
     credita_s_tempo_m();
     atualiza_roleta1(250, 410, 15);     
     credita_s_tempo_m();
     atualiza_roleta1(5, 660, 15);     
     credita_s_tempo_m();
     blit(buffer,screen,0,0,0,0,800,600);    
     credita_s_tempo_m();
     ios++;
     if (ios==12) ios=0;
     if(tecla_credito>0)tempo=50;

   }    
    credita_s_tempo_m();
    clear(buffer);
    credita_s_tempo_m();
    premio=0;
    credita_s_tempo_m();
    clear(screen); 
    credita_s_tempo_m();
    draw_sprite(screen, imagens[85].dat, 0,0 );
    credita_s_tempo_m();
    draw_sprite(screen, imagens[62].dat, 70,70 );
    credita_s_tempo_m();
    /*atualiza_slots();*/
    mostra_num();
    credita_s_tempo_m();
    atualiza_aposta();             
    credita_s_tempo_m();
    itabela=0;
    icon_tabela=0;
    credita_s_tempo_m();
    mostra_leitura_ac(ac_atual_3, 90);
    credita_s_tempo_m();
    mostra_leitura_ac(ac_atual_2, 335);
    credita_s_tempo_m();
    mostra_leitura_ac(ac_atual_1, 590);    
    credita_s_tempo_m();
    blefe_bonus=0;   
} 

