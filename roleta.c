#include <stdlib.h> 
#include <allegro.h> 
#include "variaveis.h" 

void bonus_roleta()
{   
  int icont=0, i=0, consta=0, ini_para=0, val_p=0, icatraca=0, is_ca=0, para=0, ips=2;

  play_sample (sones[24].dat, 255, 128, 1000, 1);

  icatraca = valor_b_abobora * aposta1;
  icatraca = icatraca * 10;
  if(icatraca==0)icatraca=10; 
  
  clear(buffer);
  draw_sprite(buffer, imagens[95].dat, 0,0 );     
  rotate_sprite(buffer, RODA_ROLETA, 28, 155, 0);
  draw_sprite(buffer, IMG_ROLETA[4], 235, 130);  
  atualiza_roleta1(icatraca,609, 356);
  atualiza_roleta1(credito,609, 401);
  atualiza_roleta1(premio,609, 450);
  blit(buffer,screen,0,0,0,0,800,600);
  
  if((((pr_entrada_p-pr_saida_p)-credito-premio)) < 2000)
    consta = 2 + (rand() % 10);
  else
  if((((pr_entrada_p-pr_saida_p)-credito-premio)) > 1999)
    consta = 8 + (rand() % 22);
  else
  if(valor_b_abobora * aposta1 > 4)
    consta = 4 + (rand() % 20);
  else
  if(valor_b_abobora * aposta1 < 4)
    consta = 8 + (rand() % 60);

  
  if (consta>24)
    {
     consta = 4 + (rand() % 10);
    }
  if (consta==0)
    {
     consta=5;
    }
    
  if (consta==1) consta=4;
  
  val_p = VALOR_ROLETA[consta];
  val_p = val_p +589;
     
  icont=-30000;
  icont=1;
  icont=0;
  rest(1000);
  ini_para=((val_p*70)/100);

      int_grampo=7;
      ips=7;
      i=0;
      clear(buffer);
      tempo=0;
      while(i < val_p)
        {
          clear(buffer);
          draw_sprite(buffer, imagens[95].dat, 0,0 );     
          play_sample (sones[28].dat, 255, 128, 1000, 0);  
           icont=icont-141000;
           icont=icont-1;
         
          rotate_sprite(buffer, RODA_ROLETA, 28, 155, icont);
          draw_sprite(buffer, IMG_ROLETA[int_grampo], 235, 130);  

          atualiza_roleta1(icatraca,609, 356);
          atualiza_roleta1(credito,609, 401);
          atualiza_roleta1(premio,609, 450);
          blit(buffer,screen,0,0,0,0,800,600);
          
          int_grampo--;
          if (int_grampo<1)
           {
           int_grampo=7;
           }
           
           if(i>350)
            {
             is_ca++;

             if(is_ca==10)
               {
                para++;
                ips=1;
                is_ca=0;
               } 
             rest(para);
            }
          i++;
        }      

    stop_sample (sones[24].dat);    
    play_sample (sones[32].dat, 255, 128, 1000, 0);  
    rest(1000);
    rotate_sprite(buffer, RODA_ROLETA, 28, 155, icont);
    draw_sprite(buffer, IMG_ROLETA[0], 235, 130);  
    atualiza_roleta1(icatraca,609, 356);
    atualiza_roleta1(credito,609, 401);
    premio=premio+(icatraca*consta);
    atualiza_roleta1(premio,609, 450);
    atualiza_roleta1(consta,680, 356);
    blit(buffer,screen,0,0,0,0,800,600);
       
    rest(2000);
}

