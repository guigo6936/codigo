#include "variaveis.h"  

void atualiza_credito()
{
 int i;
 int ins;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 if (credito==0)
  {
   draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
  }
 else  
 if (credito>0)
  { 
     draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
        
         if (credito<10)
           {
            ins=207;
           } 
         else   
         if (credito<100)
           {
            ins=200;
           } 
         else   
         if (credito<1000)
           {
            ins=190;
           } 
         else   
         if (credito<10000)
          {
            ins=180;
          }  
         else   
         if (credito<100000)
           {
            ins=165;
           }
         else   
         if (credito<1000000)
           {
            ins=160;
           }
         else   
         if (credito<10000000)
           {
            ins=155;
           }
         itoa(credito,buff,10);
        draw_sprite(screen, imagens[46].dat, 160,22 );
        draw_sprite(screen, imagens[46].dat, 195,22 );
         for (i=0;i<10;i++)
            {
              if(buff[i]==48) draw_sprite(screen, NUM_CIMA[0], ins,23);
              if(buff[i]==49) draw_sprite(screen, NUM_CIMA[1], ins,23);
              if(buff[i]==50) draw_sprite(screen, NUM_CIMA[2], ins,23);
              if(buff[i]==51) draw_sprite(screen, NUM_CIMA[3], ins,23);
              if(buff[i]==52) draw_sprite(screen, NUM_CIMA[4], ins,23);
              if(buff[i]==53) draw_sprite(screen, NUM_CIMA[5], ins,23);
              if(buff[i]==54) draw_sprite(screen, NUM_CIMA[6], ins,23);
              if(buff[i]==55) draw_sprite(screen, NUM_CIMA[7], ins,23);
              if(buff[i]==56) draw_sprite(screen, NUM_CIMA[8], ins,23);      
              if(buff[i]==57) draw_sprite(screen, NUM_CIMA[9], ins,23);      
              ins=ins+20;
            }
   }
}

void atualiza_premio()
{
 draw_sprite(screen, imagens[46].dat, 440,22 );
 draw_sprite(screen, imagens[46].dat, 480,22 );
 int i;
 int inp;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 if(premio==0)
   {
    draw_sprite(screen, imagens[46].dat, 440,22 );
    draw_sprite(screen, imagens[46].dat, 480,22 );
   }
 else
 if(premio>0)
   {
         if (premio<10)
           {
            inp=490;
           } 
         else   
         if (premio<100)
           {
            inp=475;
           } 
         else   
         if (premio<1000)
           {
            inp=470;
           } 
         else   
         if (premio<10000)
          {
            inp=465;
          }  
         else   
         if (premio<100000)
           {
            inp=455;
           }
         else   
         if (premio<1000000)
           {
            inp=438;
           }
         itoa(premio,buff,10);
         for (i=0;i<6;i++)
            {
              if(buff[i]==48) draw_sprite(screen, NUM_CIMA[0], inp,23);
              if(buff[i]==49) draw_sprite(screen, NUM_CIMA[1], inp,23);
              if(buff[i]==50) draw_sprite(screen, NUM_CIMA[2], inp,23);
              if(buff[i]==51) draw_sprite(screen, NUM_CIMA[3], inp,23);
              if(buff[i]==52) draw_sprite(screen, NUM_CIMA[4], inp,23);
              if(buff[i]==53) draw_sprite(screen, NUM_CIMA[5], inp,23);
              if(buff[i]==54) draw_sprite(screen, NUM_CIMA[6], inp,23);
              if(buff[i]==55) draw_sprite(screen, NUM_CIMA[7], inp,23);
              if(buff[i]==56) draw_sprite(screen, NUM_CIMA[8], inp,23);      
              if(buff[i]==57) draw_sprite(screen, NUM_CIMA[9], inp,23);      
              inp=inp+20;
            }
   }
}
 
void atualiza_aposta()
{
 draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
 int i;
 int inm, vals;
 inm=0;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 vals = (valor_linha*aposta1);
 if(vals==0)
   { 
    draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
   }
 else   
 if(vals>0)
  { 
         if (vals<10)
           {
            inm=705;
           } 
         else   
         if (vals<100)
           {
            inm=695;
           } 
         else   
         if (vals<1000)
           {
            inm=685;
           } 
         draw_sprite(screen, imagens[46].dat, 678,22 );
         itoa(vals,buff,10);
         for (i=0;i<6;i++)
            {
              if(buff[i]==48) draw_sprite(screen, NUM_CIMA[0], inm,23);
              if(buff[i]==49) draw_sprite(screen, NUM_CIMA[1], inm,23);
              if(buff[i]==50) draw_sprite(screen, NUM_CIMA[2], inm,23);
              if(buff[i]==51) draw_sprite(screen, NUM_CIMA[3], inm,23);
              if(buff[i]==52) draw_sprite(screen, NUM_CIMA[4], inm,23);
              if(buff[i]==53) draw_sprite(screen, NUM_CIMA[5], inm,23);
              if(buff[i]==54) draw_sprite(screen, NUM_CIMA[6], inm,23);
              if(buff[i]==55) draw_sprite(screen, NUM_CIMA[7], inm,23);
              if(buff[i]==56) draw_sprite(screen, NUM_CIMA[8], inm,23);      
              if(buff[i]==57) draw_sprite(screen, NUM_CIMA[9], inm,23);      
              inm=inm+20;
            }
   }
}

void mostra_num() /* MOSTRA OS NUMEROS NA TELA*/
{
   if (aposta1<10)
     { 
       draw_sprite(screen, NUM_APOSTA[0], 608,64);    
       draw_sprite(screen, NUM_APOSTA[aposta1], 618,64);
     }
  else
   if (aposta1=10)
    {
       draw_sprite(screen, NUM_APOSTA[1], 608,64);    
       draw_sprite(screen, NUM_APOSTA[0], 618,64);    
    }     
}
void atualiza_pago()
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=124;
 itoa(pago,buff,10);
 if (premio>0)
   {
     draw_sprite(screen, imagens[116].dat, 124,64);
     for (i=0;i<12;i++)
        {
          if(buff[i]==48) draw_sprite(screen, NUM_PAGO[0], ini,72);
          if(buff[i]==49) draw_sprite(screen, NUM_PAGO[1], ini,72);
          if(buff[i]==50) draw_sprite(screen, NUM_PAGO[2], ini,72);
          if(buff[i]==51) draw_sprite(screen, NUM_PAGO[3], ini,72);
          if(buff[i]==52) draw_sprite(screen, NUM_PAGO[4], ini,72);
          if(buff[i]==53) draw_sprite(screen, NUM_PAGO[5], ini,72);
          if(buff[i]==54) draw_sprite(screen, NUM_PAGO[6], ini,72);
          if(buff[i]==55) draw_sprite(screen, NUM_PAGO[7], ini,72);
          if(buff[i]==56) draw_sprite(screen, NUM_PAGO[8], ini,72);      
          if(buff[i]==57) draw_sprite(screen, NUM_PAGO[9], ini,72);      
          ini=ini+11;        
        }
   }
}

void mostra_ganhos()
{
int i;
if (premio>0)
  {
   pr_premic_p  = pr_premic_p + premio;
   /*grava_parametros_c();  */
  } 
pago=0;
atualiza_premio(); 
rest(1000);
pago=pago+premio;
atualiza_pago();  
credito=credito+premio;
atualiza_credito(); 
play_sample (sones[33].dat, 255, 128, 1000, 0);  
play_sample (sones[33].dat, 255, 128, 1000, 0);  
play_sample (sones[33].dat, 255, 128, 1000, 0);  
premio=0;
atualiza_premio(); 
pago=0;
rest(100);
}

void mostra_descredito()
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }   
 ini=400;
 itoa(credito,buff,10);
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(screen, NUM_PRETO_B[0], ini, 420);
      if(buff[i]==49) draw_sprite(screen, NUM_PRETO_B[1], ini,420);
      if(buff[i]==50) draw_sprite(screen, NUM_PRETO_B[2], ini,420);
      if(buff[i]==51) draw_sprite(screen, NUM_PRETO_B[3], ini,420);
      if(buff[i]==52) draw_sprite(screen, NUM_PRETO_B[4], ini,420);
      if(buff[i]==53) draw_sprite(screen, NUM_PRETO_B[5], ini,420);
      if(buff[i]==54) draw_sprite(screen, NUM_PRETO_B[6], ini,420);
      if(buff[i]==55) draw_sprite(screen, NUM_PRETO_B[7], ini,420);
      if(buff[i]==56) draw_sprite(screen, NUM_PRETO_B[8], ini,420);      
      if(buff[i]==57) draw_sprite(screen, NUM_PRETO_B[9], ini,420);      
      ini=ini+25;
    }
}

void mostra_leitura_pb(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }   
 ini=ialtura;
 itoa(mvalor,buff,10);
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(buffer, NUM_PRETO_B[0], ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_PRETO_B[1], ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_PRETO_B[2], ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_PRETO_B[3], ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_PRETO_B[4], ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_PRETO_B[5], ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_PRETO_B[6], ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_PRETO_B[7], ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_PRETO_B[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(buffer, NUM_PRETO_B[9], ini,itopo);      
      ini=ini+25;
    }
}

void mostra_leitura_ac(float mvalor,int ialtura)
{
 int i;
 int ini;

 if (ialtura == 90 ) draw_sprite(screen, imagens[48].dat, 70,526 );
 if (ialtura == 335) draw_sprite(screen, imagens[48].dat, 320,525 );
 if (ialtura == 590) draw_sprite(screen, imagens[48].dat, 575,526 );

 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }   
 mvalor = mvalor /100;
 ini=ialtura;
 sprintf(buff,"%5.2f",mvalor);
 for (i=0;i<15;i++)
    {
      if((aposta1 * valor_linha) >39 )
         {
           if(buff[i]==48) draw_sprite(screen, NUM_CIMA[0], ini,528);
           if(buff[i]==49) draw_sprite(screen, NUM_CIMA[1], ini,528);
           if(buff[i]==50) draw_sprite(screen, NUM_CIMA[2], ini,528);
           if(buff[i]==51) draw_sprite(screen, NUM_CIMA[3], ini,528);
           if(buff[i]==52) draw_sprite(screen, NUM_CIMA[4], ini,528);
           if(buff[i]==53) draw_sprite(screen, NUM_CIMA[5], ini,528);
           if(buff[i]==54) draw_sprite(screen, NUM_CIMA[6], ini,528);
           if(buff[i]==55) draw_sprite(screen, NUM_CIMA[7], ini,528);
           if(buff[i]==56) draw_sprite(screen, NUM_CIMA[8], ini,528);
           if(buff[i]==57) draw_sprite(screen, NUM_CIMA[9], ini,528);
           if(buff[i]==46) draw_sprite(screen, NUM_CIMA[11], ini,542);
          }
      else     
      if((aposta1 * valor_linha) <40 )
         {
           if(buff[i]==48) draw_sprite(screen, NUM_ACUMULADO[0], ini,528);
           if(buff[i]==49) draw_sprite(screen, NUM_ACUMULADO[1], ini,528);
           if(buff[i]==50) draw_sprite(screen, NUM_ACUMULADO[2], ini,528);
           if(buff[i]==51) draw_sprite(screen, NUM_ACUMULADO[3], ini,528);
           if(buff[i]==52) draw_sprite(screen, NUM_ACUMULADO[4], ini,528);
           if(buff[i]==53) draw_sprite(screen, NUM_ACUMULADO[5], ini,528);
           if(buff[i]==54) draw_sprite(screen, NUM_ACUMULADO[6], ini,528);
           if(buff[i]==55) draw_sprite(screen, NUM_ACUMULADO[7], ini,528);
           if(buff[i]==56) draw_sprite(screen, NUM_ACUMULADO[8], ini,528);
           if(buff[i]==57) draw_sprite(screen, NUM_ACUMULADO[9], ini,528);
           if(buff[i]==46) draw_sprite(screen, NUM_ACUMULADO[10], ini,542);
          }
      if(buff[i]==46)
         ini=ini+13;
      if(buff[i]!=46)
         ini=ini+20;
    }
}

void atualiza_roleta(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
     for (i=0;i<12;i++)
        {
          if(buff[i]==48) draw_sprite(screen, NUM_BRANCO_P[0], ini,itopo);
          if(buff[i]==49) draw_sprite(screen, NUM_BRANCO_P[1], ini,itopo);
          if(buff[i]==50) draw_sprite(screen, NUM_BRANCO_P[2], ini,itopo);
          if(buff[i]==51) draw_sprite(screen, NUM_BRANCO_P[3], ini,itopo);
          if(buff[i]==52) draw_sprite(screen, NUM_BRANCO_P[4], ini,itopo);
          if(buff[i]==53) draw_sprite(screen, NUM_BRANCO_P[5], ini,itopo);
          if(buff[i]==54) draw_sprite(screen, NUM_BRANCO_P[6], ini,itopo);
          if(buff[i]==55) draw_sprite(screen, NUM_BRANCO_P[7], ini,itopo);
          if(buff[i]==56) draw_sprite(screen, NUM_BRANCO_P[8], ini,itopo);      
          if(buff[i]==57) draw_sprite(screen, NUM_BRANCO_P[9], ini,itopo);      
          ini=ini+20;
        }
}

void atualiza_roleta1(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
     for (i=0;i<12;i++)
        {
          if(buff[i]==48) draw_sprite(buffer, NUM_BRANCO_P[0], ini,itopo);
          if(buff[i]==49) draw_sprite(buffer, NUM_BRANCO_P[1], ini,itopo);
          if(buff[i]==50) draw_sprite(buffer, NUM_BRANCO_P[2], ini,itopo);
          if(buff[i]==51) draw_sprite(buffer, NUM_BRANCO_P[3], ini,itopo);
          if(buff[i]==52) draw_sprite(buffer, NUM_BRANCO_P[4], ini,itopo);
          if(buff[i]==53) draw_sprite(buffer, NUM_BRANCO_P[5], ini,itopo);
          if(buff[i]==54) draw_sprite(buffer, NUM_BRANCO_P[6], ini,itopo);
          if(buff[i]==55) draw_sprite(buffer, NUM_BRANCO_P[7], ini,itopo);
          if(buff[i]==56) draw_sprite(buffer, NUM_BRANCO_P[8], ini,itopo);      
          if(buff[i]==57) draw_sprite(buffer, NUM_BRANCO_P[9], ini,itopo);      
          ini=ini+20;
        }
}

void atualiza_morango(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 if(mvalor<10)
   ini=ini+60;
 else  
 if(mvalor<100) 
   ini=ini+55; 
 else
 if(mvalor<1000)
   ini=ini+50;
 else
 if(mvalor<10000)
   ini=ialtura;

 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(buffer, NUM_BRANCO_P1[0], ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_BRANCO_P1[1], ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_BRANCO_P1[2], ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_BRANCO_P1[3], ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_BRANCO_P1[4], ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_BRANCO_P1[5], ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_BRANCO_P1[6], ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_BRANCO_P1[7], ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_BRANCO_P1[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(buffer, NUM_BRANCO_P1[9], ini,itopo);      
      ini=ini+23;
    }
}

void atualiza_caldeirao(int mvalor,int ialtura, int itopo)
{
 draw_sprite(screen, imagens[116].dat, ialtura,itopo);
 draw_sprite(screen, imagens[116].dat, ialtura+5,itopo);
 draw_sprite(screen, imagens[116].dat, ialtura+9,itopo);
 draw_sprite(screen, imagens[116].dat, ialtura+12,itopo);
 draw_sprite(screen, imagens[116].dat, ialtura+30,itopo); 
 draw_sprite(screen, imagens[116].dat, ialtura,itopo+3);
 draw_sprite(screen, imagens[116].dat, ialtura+5,itopo+3);
 draw_sprite(screen, imagens[116].dat, ialtura+9,itopo+3);
 draw_sprite(screen, imagens[116].dat, ialtura+12,itopo+3);
 draw_sprite(screen, imagens[116].dat, ialtura+30,itopo+3);
 draw_sprite(screen, imagens[116].dat, ialtura+42,itopo);
 draw_sprite(screen, imagens[116].dat, ialtura+42,itopo+3);
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
 if  (mvalor>0) 
   {
     for (i=0;i<12;i++)
        {
          if(buff[i]==48) draw_sprite(screen, NUM_BRANCO_P[0], ini,itopo);
          if(buff[i]==49) draw_sprite(screen, NUM_BRANCO_P[1], ini,itopo);
          if(buff[i]==50) draw_sprite(screen, NUM_BRANCO_P[2], ini,itopo);
          if(buff[i]==51) draw_sprite(screen, NUM_BRANCO_P[3], ini,itopo);
          if(buff[i]==52) draw_sprite(screen, NUM_BRANCO_P[4], ini,itopo);
          if(buff[i]==53) draw_sprite(screen, NUM_BRANCO_P[5], ini,itopo);
          if(buff[i]==54) draw_sprite(screen, NUM_BRANCO_P[6], ini,itopo);
          if(buff[i]==55) draw_sprite(screen, NUM_BRANCO_P[7], ini,itopo);
          if(buff[i]==56) draw_sprite(screen, NUM_BRANCO_P[8], ini,itopo);      
          if(buff[i]==57) draw_sprite(screen, NUM_BRANCO_P[9], ini,itopo);      
          ini=ini+20;
        }
     }
  else
    {
     draw_sprite(screen, imagens[116].dat, ialtura,itopo);
     draw_sprite(screen, imagens[116].dat, ialtura+5,itopo);
     draw_sprite(screen, imagens[116].dat, ialtura+9,itopo);
     draw_sprite(screen, imagens[116].dat, ialtura+12,itopo);
     draw_sprite(screen, imagens[116].dat, ialtura+30,itopo); 
     draw_sprite(screen, imagens[116].dat, ialtura,itopo+3);
     draw_sprite(screen, imagens[116].dat, ialtura+5,itopo+3);
     draw_sprite(screen, imagens[116].dat, ialtura+9,itopo+3);
     draw_sprite(screen, imagens[116].dat, ialtura+12,itopo+3);
     draw_sprite(screen, imagens[116].dat, ialtura+30,itopo+3);
    }      
}

void atualiza_sinuca(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
     for (i=0;i<12;i++)
        {
          if(buff[i]==48) draw_sprite(buffer, NUM_CINUCA[0], ini,itopo);
          if(buff[i]==49) draw_sprite(buffer, NUM_CINUCA[1], ini,itopo);
          if(buff[i]==50) draw_sprite(buffer, NUM_CINUCA[2], ini,itopo);
          if(buff[i]==51) draw_sprite(buffer, NUM_CINUCA[3], ini,itopo);
          if(buff[i]==52) draw_sprite(buffer, NUM_CINUCA[4], ini,itopo);
          if(buff[i]==53) draw_sprite(buffer, NUM_CINUCA[5], ini,itopo);
          if(buff[i]==54) draw_sprite(buffer, NUM_CINUCA[6], ini,itopo);
          if(buff[i]==55) draw_sprite(buffer, NUM_CINUCA[7], ini,itopo);
          if(buff[i]==56) draw_sprite(buffer, NUM_CINUCA[8], ini,itopo);      
          if(buff[i]==57) draw_sprite(buffer, NUM_CINUCA[9], ini,itopo);      
          ini=ini+33;  
        }
}


void mostra_ac_grande(float mvalor,int ialtura, int itops)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }   
 mvalor = mvalor /100;
 ini=ialtura;
 sprintf(buff,"%5.2f",mvalor);
 for (i=0;i<15;i++)
    {
       if(buff[i]==48) draw_sprite(screen, NUM_CIMA[0], ini,itops);
       if(buff[i]==49) draw_sprite(screen, NUM_CIMA[1], ini,itops);
       if(buff[i]==50) draw_sprite(screen, NUM_CIMA[2], ini,itops);
       if(buff[i]==51) draw_sprite(screen, NUM_CIMA[3], ini,itops);
       if(buff[i]==52) draw_sprite(screen, NUM_CIMA[4], ini,itops);
       if(buff[i]==53) draw_sprite(screen, NUM_CIMA[5], ini,itops);
       if(buff[i]==54) draw_sprite(screen, NUM_CIMA[6], ini,itops);
       if(buff[i]==55) draw_sprite(screen, NUM_CIMA[7], ini,itops);
       if(buff[i]==56) draw_sprite(screen, NUM_CIMA[8], ini,itops);
       if(buff[i]==57) draw_sprite(screen, NUM_CIMA[9], ini,itops);
       if(buff[i]==46) draw_sprite(screen, NUM_CIMA[11],ini,itops+14);
      if(buff[i]==46)
         ini=ini+13;
      if(buff[i]!=46)
         ini=ini+20;
    }
}


void num_amarelo(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(buffer, NUM_AMARELO[0], ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_AMARELO[1], ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_AMARELO[2], ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_AMARELO[3], ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_AMARELO[4], ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_AMARELO[5], ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_AMARELO[6], ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_AMARELO[7], ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_AMARELO[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(buffer, NUM_AMARELO[9], ini,itopo);      
      if(buff[i]==46) draw_sprite(buffer, NUM_AMARELO[10], ini,itopo);      
      if(buff[i]==44) draw_sprite(buffer, NUM_AMARELO[11], ini,itopo);      
      if(buff[i]==45) draw_sprite(buffer, NUM_AMARELO[14], ini,itopo);
      ini=ini+16;
    }
}


void num_azul(int mvalor,int ialtura, int itopo, int tipo)
{

 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }

 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
  
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(buffer, NUM_AZUL[0], ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_AZUL[1], ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_AZUL[2], ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_AZUL[3], ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_AZUL[4], ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_AZUL[5], ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_AZUL[6], ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_AZUL[7], ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_AZUL[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(buffer, NUM_AZUL[9], ini,itopo);      
      if(buff[i]==46) draw_sprite(buffer, NUM_AZUL[10], ini,itopo);      
      if(buff[i]==44) draw_sprite(buffer, NUM_AZUL[11], ini,itopo);      
      if(buff[i]==45) draw_sprite(buffer, NUM_AZUL[14], ini,itopo);      
      ini=ini+16;    
    }
   if (tipo==1) draw_sprite(buffer, NUM_AZUL[13], ini-160,itopo);
}


void mostra_desc(float mvalor,int ialtura, int itopo)
{

 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }   

 mvalor = mvalor /100;
 ini=ialtura;
 sprintf(buff,"%5.2f",mvalor);

 for (i=0;i<15;i++)
    {
  
      if(buff[i]==48) draw_sprite(buffer, NUM_VERDE[0],  ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_VERDE[1],  ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_VERDE[2],  ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_VERDE[3],  ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_VERDE[4],  ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_VERDE[5],  ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_VERDE[6],  ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_VERDE[7],  ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_VERDE[8],  ini,itopo);
      if(buff[i]==57) draw_sprite(buffer, NUM_VERDE[9],  ini,itopo);
      if(buff[i]==46) draw_sprite(buffer, NUM_VERDE[10], ini,itopo);
 
      if(buff[i]==46)
         ini=ini+20;

      if(buff[i]!=46)
         ini=ini+45;
    }
}

void num_amarelo_pr(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++) 
   {
     buff[i]=0;
   }
 mvalor = mvalor /100;
 ini=ialtura;
 sprintf(buff,"%5.2f",mvalor);
  
 for (i=0;i<15;i++)
    {

      if(buff[i]==48) draw_sprite(buffer, NUM_AMARELO[0], ini,itopo);
      if(buff[i]==49) draw_sprite(buffer, NUM_AMARELO[1], ini,itopo);
      if(buff[i]==50) draw_sprite(buffer, NUM_AMARELO[2], ini,itopo);
      if(buff[i]==51) draw_sprite(buffer, NUM_AMARELO[3], ini,itopo);
      if(buff[i]==52) draw_sprite(buffer, NUM_AMARELO[4], ini,itopo);
      if(buff[i]==53) draw_sprite(buffer, NUM_AMARELO[5], ini,itopo);
      if(buff[i]==54) draw_sprite(buffer, NUM_AMARELO[6], ini,itopo);
      if(buff[i]==55) draw_sprite(buffer, NUM_AMARELO[7], ini,itopo);
      if(buff[i]==56) draw_sprite(buffer, NUM_AMARELO[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(buffer, NUM_AMARELO[9], ini,itopo);      
      if(buff[i]==46) draw_sprite(buffer, NUM_AMARELO[10], ini,itopo);      
      if(buff[i]==44) draw_sprite(buffer, NUM_AMARELO[11], ini,itopo);      
      ini=ini+16;
    }
}

void num_amarelo_g(int mvalor,int ialtura, int itopo)
{
 int i;
 int ini;
 for (i=0;i<32;i++)
   {
     buff[i]=0;
   }
 ini=ialtura;
 itoa(mvalor,buff,10);
 if (mvalor<10)ini=ini+15;
 for (i=0;i<12;i++)
    {
      if(buff[i]==48) draw_sprite(screen, NUM_AMARELO[0], ini,itopo);
      if(buff[i]==49) draw_sprite(screen, NUM_AMARELO[1], ini,itopo);
      if(buff[i]==50) draw_sprite(screen, NUM_AMARELO[2], ini,itopo);
      if(buff[i]==51) draw_sprite(screen, NUM_AMARELO[3], ini,itopo);
      if(buff[i]==52) draw_sprite(screen, NUM_AMARELO[4], ini,itopo);
      if(buff[i]==53) draw_sprite(screen, NUM_AMARELO[5], ini,itopo);
      if(buff[i]==54) draw_sprite(screen, NUM_AMARELO[6], ini,itopo);
      if(buff[i]==55) draw_sprite(screen, NUM_AMARELO[7], ini,itopo);
      if(buff[i]==56) draw_sprite(screen, NUM_AMARELO[8], ini,itopo);      
      if(buff[i]==57) draw_sprite(screen, NUM_AMARELO[9], ini,itopo);      
//      if(buff[i]==46) draw_sprite(buffer, NUM_AMARELO[10], ini,itopo);      
//      if(buff[i]==44) draw_sprite(buffer, NUM_AMARELO[11], ini,itopo);      
//      if(buff[i]==45) draw_sprite(buffer, NUM_AMARELO[14], ini,itopo);
      ini=ini+16;
    }
}

