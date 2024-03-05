#include <stdlib.h> 
#include <allegro.h> 
#include "variaveis.h" 

void credita_s_tempo_s ()
{
    if(key[KEY_1] && ta_c_credito !=1 ){tecla_credito=1;ta_c_credito=1; _ani_s_credito=2800;}
    if(key[KEY_2] && ta_c_credito !=1){tecla_credito=2;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_3] && ta_c_credito !=1){tecla_credito=3;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_4] && ta_c_credito !=1){tecla_credito=4;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_5] && ta_c_credito !=1){tecla_credito=5;ta_c_credito=1;  _ani_s_credito=2800;}
    if(key[KEY_6] && ta_c_credito !=1){tecla_credito=6;ta_c_credito=1;  _ani_s_credito=2800;}
}

void bonus_sinuca() 
{
 
 play_sample (sones[5].dat, 255, 128, 1000, 1);  
 int i_tacada=0, iv, i_rolo_sinuca=0,i_valor_ap=0, i_pula1=0, i_pula2=0, i_pula3=0, i=0, i_taco=0, i_mesa=0, i_monte=0;
 i_valor_ap = valor_b_abobora * aposta1;
 if(i_valor_ap==0)i_valor_ap=1;
 tempo=0;  
 int conta2000=0;
 while (i==0)
  {
    clear(buffer);  
    if(tempo==1)
      {
       conta2000++;
       tempo=0;
      } 

    if (conta2000>=3)
       {
        conta2000=0;
        i_tacada++;

        i_pula1++;
        if (i_pula1==11) i_pula1=0;

        i_pula2=i_pula1+1;
        if (i_pula2==11) i_pula2=0;

        i_pula3=i_pula2+1;
        if (i_pula3==11) i_pula3=0;

        i_mesa++;
        if(i_mesa==5) i_mesa=0;

        i_taco++;
        if(i_taco==16)i_taco=0;

        i_monte++;
        if(i_monte==16) i_monte=0;

       }
  
    if(i_tacada==25)
      {
      play_sample (sones[2].dat, 255, 128, 1000, 0);  
      i_tacada=0;
      }
      
    draw_sprite(buffer, imagens[97].dat, 0,0 );     
    draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula1], 100,400 );
    draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula2], 300,400 );
    draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula3], 500,400 );

    if(i_mesa==0)
      {
       draw_sprite(buffer, MESA_SINUCA[0], 630,110 );
       draw_sprite(buffer, BONECO_SINUCA[0], 5,110 );          
      } 
    else   
      {
       draw_sprite(buffer, MESA_SINUCA[1], 630,110 );
       draw_sprite(buffer, BONECO_SINUCA[1], 5,110 );          
      }       
       
    draw_sprite(buffer, TACO_SINUCA[i_taco], 450,145 );
    draw_sprite(buffer, EMP_BOLAS_SINUCA[i_monte], 250,150 );                    
       
    atualiza_sinuca(i_valor_ap,220,320);
    atualiza_sinuca(0,600,320);
    atualiza_sinuca(credito,220,550);
    blit(buffer,screen,0,0,0,0,800,600);      

    if(key[KEY_B])
      {
        if((((pr_entrada_p-pr_saida_p)-credito)) < 3000)
          iv = rand()%2;
        else
        if((((pr_entrada_p-pr_saida_p)-credito)) > 2999)
          iv = rand()%9;
       else
       if(i_valor_ap > 4)
          iv = rand()%3;
       else
       if(i_valor_ap < 4)
          iv = rand()%9;
       
       stop_sample(sones[5].dat);
       play_sample (sones[4].dat, 255, 128, 1000, 0);         
       play_sample (sones[6].dat, 255, 128, 1000, 1);  
       int IO=0;
       for (i=0;i<91;i++)
          {

            draw_sprite(buffer, imagens[97].dat, 0,0 );     
           
             if (i>29)
                draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][2]][IO], 500,400 );
            else
               draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 500,400 );
                                       
            if (i>59)
                draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][1]][IO], 300,400 );            
            else
               draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 300,400 );

            if (i>89)
                draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][0]][IO], 100,400 );
            else
               draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 100,400 );


            draw_sprite(buffer, MESA_SINUCA[0], 630,110 );
            draw_sprite(buffer, BONECO_SINUCA[0], 5,110 );          
            draw_sprite(buffer, TACO_SINUCA[i_taco], 450,145 );
            draw_sprite(buffer, EMP_BOLAS_SINUCA[i_monte], 250,150 );                    
            atualiza_sinuca(i_valor_ap,220,320);
            atualiza_sinuca(0,600,320);
            atualiza_sinuca(credito,220,550);

            i_rolo_sinuca++;
            if(i_rolo_sinuca==11)i_rolo_sinuca=0;

            blit(buffer,screen,0,0,0,0,800,600);   
            rest(45);
            IO++;
            if(IO>5)IO=0;
               
          }
        i=1;
        stop_sample(sones[6].dat);
        rest(1000);
      }
  }
 premio=premio+(VAL_SINUCA[iv][3]*i_valor_ap); 
 draw_sprite(buffer, imagens[97].dat, 0,0 );     
 draw_sprite(buffer, MESA_SINUCA[0], 630,110 );
 draw_sprite(buffer, BONECO_SINUCA[0], 5,110 );          
 draw_sprite(buffer, TACO_SINUCA[i_taco], 450,145 );
 draw_sprite(buffer, EMP_BOLAS_SINUCA[i_monte], 250,150 );                    
 draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][2]][1], 500,400 );
 draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][1]][1], 300,400 );
 draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][0]][1], 100,400 );
 atualiza_sinuca(i_valor_ap,220,320);
 atualiza_sinuca(credito,220,550);
 atualiza_sinuca(premio,600,320);        
 play_sample (sones[32].dat, 255, 128, 1000, 0);           
 blit(buffer,screen,0,0,0,0,800,600);   
 rest(2000);
}



