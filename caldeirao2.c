#include <stdlib.h> 
#include <allegro.h> 
#include "variaveis.h" 

void bonus_abobora2();  
void bonus_caldeirao2()
{  

  int iv, i=0, icald=0, conf_b, b_multi_cald=0, play_1=0;
  play_sample (sones[9].dat, 255, 128, 1000, 1);
      draw_sprite(buffer, imagens[141].dat, 0,0 ); 

  b_multi_cald = valor_b_abobora * aposta1;
  if(b_multi_cald==0)b_multi_cald=1;
  
  while (i==0)
     {
      clear(buffer); 
      draw_sprite(buffer, imagens[141].dat, 0,0 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO2[icald], 54, 118 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO2[icald], 204,118 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO2[icald], 354,118 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO2[icald], 504,118 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO2[icald], 654,118 ); 
         
      atualiza_roleta1(premio,       623, 527);           

      blit(buffer,screen,0,0,0,0,800,600);    
      icald++;
        

      if (key[KEY_Y])
         {
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;
            
         conf_b=CAL_CALD3[0][VAL_CALDEIRAO2[iv][0]];
          for(i=0;i<12;i++)
             {
              clear(buffer); 
  	      draw_sprite(buffer, imagens[141].dat, 0,0 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  54,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO3[i], 54, 118 );
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 

          
              atualiza_roleta1(premio,       623, 527);                                        
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );              
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 54, 118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 
            draw_sprite(screen, IMG_VAL_CALDEIRAO2[VAL_CALDEIRAO2[iv][0]],  54,335 );
           atualiza_roleta1(premio,       623, 527);                                        
           play_sample (sones[10].dat, 255, 128, 1000, 0);
           rest(700);
           i=1;
         }    
            
      if (key[KEY_J])
         {
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD3[0][VAL_CALDEIRAO2[iv][1]];
          for(i=0;i<12;i++)
             {
              clear(buffer); 
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  54, 118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO3[i], 204,118 );
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  654,118 ); 
              atualiza_roleta1(premio,       623, 527);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );             
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 54, 118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 
           draw_sprite(screen, IMG_VAL_CALDEIRAO2[VAL_CALDEIRAO2[iv][1]], 204,335 );                            
           atualiza_roleta1(premio,       623, 527);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    

      if (key[KEY_H])
         {
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD3[0][VAL_CALDEIRAO2[iv][2]];
          for(i=0;i<12;i++)
             {
              clear(buffer); 
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   54,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO3[i], 354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],  654,118 ); 
              atualiza_roleta1(premio,       623, 527);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );             
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 54, 118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 
           draw_sprite(screen, IMG_VAL_CALDEIRAO2[VAL_CALDEIRAO2[iv][2]], 354,335 );                            
           atualiza_roleta1(premio,       623, 527);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_M])
         {
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD3[0][VAL_CALDEIRAO2[iv][3]];
          for(i=0;i<12;i++)
             {
              clear(buffer); 
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   54, 118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO3[i],  504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   654,118 ); 
              atualiza_roleta1(premio,       623, 527);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 54, 118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 
           draw_sprite(screen, IMG_VAL_CALDEIRAO2[VAL_CALDEIRAO2[iv][3]], 504,335 );                            
           atualiza_roleta1(premio,       623, 527);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_N])
         {
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD3[0][VAL_CALDEIRAO2[iv][4]];
          for(i=0;i<12;i++)
             {
              clear(buffer); 
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );                 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],    54,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   204,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   354,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   504,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO2[1],   654,118 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO3[i],  654,118 ); 
              atualiza_roleta1(premio,       623, 527);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
  	   draw_sprite(buffer, imagens[141].dat, 0,0 );              
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 54, 118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 204,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 354,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 504,118 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO2[1], 654,118 ); 
           draw_sprite(screen, IMG_VAL_CALDEIRAO2[VAL_CALDEIRAO2[iv][4]], 654,335 );                            
           atualiza_roleta1(premio,       623, 527);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);
  
           rest(700);
           i=1;  
         }    

      if (icald==72) 
         icald=0;
        
        rest(10);  
     }  

   if (conf_b==0)
      {
      
      }
  else 
     {
        conf_b =  conf_b * b_multi_cald;
        stop_sample (sones[9].dat);
        premio=premio*conf_b;
        int mostra=0;              
        for (i=0;i<5;i++)
           {
            play_sample (sones[12].dat, 255, 128, 1000, 0);           
            if (mostra==0)
        play_sample (sones[33].dat, 255, 128, 1000, 0);
        atualiza_roleta1(premio,       623, 527);                                               
        rest(2000);        
       
            mostra++;
            
            if (mostra==2) mostra=0;    
           
           rest(300);
           }
           

        play_sample (sones[33].dat, 255, 128, 1000, 0);
        atualiza_roleta1(premio,       623, 527);                                               
        rest(2000);        
        atualiza_roleta1(premio,       623, 527);                                               
        rest(2000);   
        atualiza_roleta1(premio,       623, 527);                                               
        rest(2000);   
/*
        draw_sprite(screen, imagens[85].dat, 0,0 ); 
        draw_sprite(screen, imagens[62].dat, 70,70 );
        atualiza_slots();
        mostra_num(); 
        atualiza_credito();
        atualiza_aposta();             
        itabela=0;
        icon_tabela=0;
        mostra_leitura_ac(ac_atual_3, 90);
        mostra_leitura_ac(ac_atual_2, 335);
        mostra_leitura_ac(ac_atual_1, 590);    
        atualiza_premio();
        mostra_ganhos();                
        grava_valor_c();
        blefe_bonus=0;   
        */
     }
}



