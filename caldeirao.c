#include <stdlib.h> 
#include <allegro.h> 
#include "variaveis.h" 

void bonus_abobora();  
void bonus_caldeirao()
{  

  int iv, i=0, icald=0, conf_b, b_multi_cald=0, play_1=0;
  play_sample (sones[9].dat, 255, 128, 1000, 1);
  draw_sprite(buffer, imagens[86].dat, 0,0 ); 

  b_multi_cald = valor_b_abobora * aposta1;
  if(b_multi_cald==0)b_multi_cald=1;
  
  while (i==0)
     {
      clear(buffer); 
      draw_sprite(buffer, imagens[86].dat, 0,0 ); 
      draw_sprite(buffer, imagens[88].dat, 0,460 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO[icald], 25, 333 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO[icald], 175,333 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO[icald], 325,333 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO[icald], 475,333 ); 
      draw_sprite(buffer, ANIMA_CALDEIRAO[icald], 625,333 ); 
      atualiza_roleta1(b_multi_cald, 158, 470);           
      atualiza_roleta1(credito,      158, 515);           
      atualiza_roleta1(premio,       158, 560);           

      blit(buffer,screen,0,0,0,0,800,600);    
      icald++;
        

      if (key[KEY_Y])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;
            
         conf_b=CAL_CALD[0][VAL_CALDEIRAO[iv][0]];
          for(i=0;i<9;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, imagens[88].dat, 0,460 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  25,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO1[i], 25, 136 );
              draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,333 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, imagens[88].dat, 0,460 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 25, 110 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,333 );  
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][0]],  25,150 );
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][1]], 175,220 );
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][2]], 325,220 );
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][3]], 475,220 );
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][4]], 625,220 );
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);
           rest(700);
           i=1;
         }    
            
      if (key[KEY_J])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[0][VAL_CALDEIRAO[iv][1]];
          for(i=0;i<9;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, imagens[88].dat, 0,460 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  25, 333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  175,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO1[i], 175,135 );
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  325,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  475,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  625,333 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, imagens[88].dat, 0,460 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 25, 333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,110 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,333 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][1]], 175,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    

      if (key[KEY_H])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[0][VAL_CALDEIRAO[iv][2]];
          for(i=0;i<9;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, imagens[88].dat, 0,460 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   25,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  175,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  325,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO1[i], 325,135 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  475,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],  625,333 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, imagens[88].dat, 0,460 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 25, 333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,110 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,333 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][2]], 325,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_M])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[0][VAL_CALDEIRAO[iv][3]];
          for(i=0;i<9;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, imagens[88].dat, 0,460 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   25, 333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   175,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   325,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   475,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO1[i],  475,135 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   625,333 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, imagens[88].dat, 0,460 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 25, 333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,113 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,333 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][1]], 180,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][2]], 330,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][3]], 480,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][4]], 630,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_N])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[0][VAL_CALDEIRAO[iv][4]];
          for(i=0;i<9;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, imagens[88].dat, 0,460 );               
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],    25,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   175,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   325,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   475,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO[1],   625,333 ); 
              draw_sprite(buffer, ANIMA_CALDEIRAO1[i],  625,135 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);                                       
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, imagens[88].dat, 0,460 );               
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 25, 333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 175,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 325,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 475,333 ); 
           draw_sprite(buffer, ANIMA_CALDEIRAO[1], 625,113 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_CALDEIRAO[iv][4]], 625,150 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);                                       
           play_sample (sones[10].dat, 255, 128, 1000, 0);
  
           rest(700);
           i=1;  
         }    

      if (icald==15) 
         icald=0;
        
        rest(10);  
     }  

   if (conf_b==0)
      {
       stop_sample (sones[9].dat);   
       bonus_abobora();      
      }
  else 
     {
        conf_b =  conf_b * b_multi_cald;
        stop_sample (sones[9].dat);
        atualiza_caldeirao(premio, 158, 470);  
        int mostra=0;              
        for (i=0;i<5;i++)
           {
            play_sample (sones[12].dat, 255, 128, 1000, 0);           
            if (mostra==0)
              atualiza_caldeirao(conf_b, 158, 470);            
            else   
              atualiza_caldeirao(0, 158, 470);                       
              
            mostra++;
            
            if (mostra==2) mostra=0;    
           
           rest(300);
           }
           
        premio=premio+conf_b;
        atualiza_caldeirao(0, 158, 470);
        rest(1000);        
        play_sample (sones[33].dat, 255, 128, 1000, 0);
        atualiza_caldeirao(premio, 158, 560);                                               
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

void bonus_abobora()
{
  play_sample (sones[35].dat, 255, 128, 1000, 1);  
  int iv, i=0, icald=0, conf_b, b_multi_cald=0, play_1=0;
  draw_sprite(buffer, imagens[86].dat, 0,0 ); 


  b_multi_cald = valor_b_abobora * aposta1;
  if(b_multi_cald==0)b_multi_cald=1;  
  
  while (i==0)
     {
      clear(buffer); 
      draw_sprite(buffer, imagens[86].dat, 0,0 ); 
      draw_sprite(buffer, ANIMA_ABOBORA[icald], 25, 300 ); 

      icald++;
      if (icald==15) 
         icald=0;

      draw_sprite(buffer, ANIMA_ABOBORA[icald], 175,300 ); 

      icald++;
      if (icald==15) 
         icald=0;

      draw_sprite(buffer, ANIMA_ABOBORA[icald], 325,300 ); 

      icald++;
      if (icald==15)  
         icald=0;

      draw_sprite(buffer, ANIMA_ABOBORA[icald], 475,300 ); 

      icald++;
      if (icald==15) 
         icald=0;

      draw_sprite(buffer, ANIMA_ABOBORA[icald], 625,300 ); 
      atualiza_roleta1(b_multi_cald, 158, 470);           
      atualiza_roleta1(credito,      158, 515);           
      atualiza_roleta1(premio,       158, 560);           

      blit(buffer,screen,0,0,0,0,800,600);    
      

      if (key[KEY_Y])
         {
         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[1][VAL_ABOBORA[iv][0]];
         play_sample (sones[1].dat, 255, 128, 1000, 0);         
          for(i=0;i<48;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, ANIMA_ABOBORA1[i], 25, 110 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1], 175,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1], 475,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1], 625,300 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);           
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 25, 110 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 175,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 475,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 625,300 );  
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);           
           play_sample (sones[10].dat, 255, 128, 1000, 0);
           rest(700);
           i=1;
         }    
            
      if (key[KEY_J])
         {
         play_sample (sones[1].dat, 255, 128, 1000, 0);         

         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[1][VAL_ABOBORA[iv][1]];
          for(i=0;i<48;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  25,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA1[i], 175,110 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  325,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  475,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  625,300 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);           
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 25, 300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 175,110 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 475,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 625,300 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);           
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    

      if (key[KEY_H])
         {
         play_sample (sones[1].dat, 255, 128, 1000, 0);         

         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[1][VAL_ABOBORA[iv][2]];
          for(i=0;i<48;i++)
             {

              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],   25,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  175,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA1[i], 325,110 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  475,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  625,300 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);           
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 25, 300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 175,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 325,110 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 475,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 625,300 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);           
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_M])
         {
         play_sample (sones[1].dat, 255, 128, 1000, 0);         

         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[1][VAL_ABOBORA[iv][3]];
          for(i=0;i<48;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],   25,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  175,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA1[i],  475,110 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],  625,300 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);           
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 25, 300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 175,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 475,113 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 625,300 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,150 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,220 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);           
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    


      if (key[KEY_N])
         {
         play_sample (sones[1].dat, 255, 128, 1000, 0);         

         if((((pr_entrada_p-pr_saida_p)-credito)) < 2000)
            iv = 0;
         else
         if((((pr_entrada_p-pr_saida_p)-credito)) > 1999)
            iv = rand()%9;
         else   
         if(b_multi_cald > 6)
           iv = rand()%3;
         else   
         if(b_multi_cald > 4)
           iv = rand()%3;
         else   
         if(b_multi_cald < 5)
           iv = rand()%4;

         conf_b=CAL_CALD[1][VAL_ABOBORA[iv][4]];
          for(i=0;i<48;i++)
             {
              clear(buffer); 
              draw_sprite(buffer, imagens[86].dat, 0,0 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],    25,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],   175,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],   325,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA[1],   475,300 ); 
              draw_sprite(buffer, ANIMA_ABOBORA1[i],  625,110 ); 
              atualiza_roleta1(b_multi_cald, 158, 470);           
              atualiza_roleta1(credito,      158, 515);           
              atualiza_roleta1(premio,       158, 560);           
              blit(buffer,screen,0,0,0,0,800,600);                                
              rest(30);
             }
           draw_sprite(buffer, imagens[86].dat, 0,0 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 25, 300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 175,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 325,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 475,300 ); 
           draw_sprite(buffer, ANIMA_ABOBORA[1], 625,113 ); 
            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,220 );                            
           draw_sprite(screen, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,150 );                            
           atualiza_roleta1(b_multi_cald, 158, 470);           
           atualiza_roleta1(credito,      158, 515);           
           atualiza_roleta1(premio,       158, 560);           
           play_sample (sones[10].dat, 255, 128, 1000, 0);

           rest(700);
           i=1;
         }    
        
        rest(10);  
     }  

    stop_sample (sones[35].dat);   
    conf_b =  conf_b * b_multi_cald;
    premio=premio+conf_b;
    atualiza_caldeirao(premio, 158, 470);  
    int mostra=0;              
    for (i=0;i<5;i++)
       {
        play_sample (sones[12].dat, 255, 128, 1000, 0);           
        if (mostra==0)
          atualiza_caldeirao(conf_b, 158, 470);            
        else   
          atualiza_caldeirao(0, 158, 470);                       
          
        mostra++;
        
        if (mostra==2) mostra=0;    
       
       rest(300);
       }
        
    atualiza_caldeirao(0, 158, 470);
    rest(1000);        
    play_sample (sones[33].dat, 255, 128, 1000, 0);
    atualiza_caldeirao(premio, 158, 560);                                               
    rest(1000);
}

