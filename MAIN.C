#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <dpmi.h>
#include <go32.h>
#include <dos.h>
#include <conio.h>
#include <allegro.h> 

#include "variaveis.h"
#include "linhass.c" 
#include "numeros.c" 
#include "roleta.c"
#include "sinuca.c"
#include "morango.c"
#include "caldeirao.c"
#include "caldeirao2.c"

#define MAX_X		800
#define MAX_Y		600 
#define V_MAX_X		0
#define V_MAX_Y		0

#define _LC 130
#define _LCS 137
#define _LD 145
#define _LDS 155
#define _LE 166
#define _LF 175
#define _LFS 185
#define _LG 195
#define _LGS 207
#define _LA 220
#define _LAS 235
#define _LB 245

#define _MC 260
#define _MCS 275
#define _MD 290
#define _MDS 311
#define _ME 333
#define _MF 350
#define _MFS 370
#define _MG 390
#define _MGS 415
#define _MA 440
#define _MAS 470
#define _MB 490

#define _HC 520

int notes[14] = {_MC, _MD, _MD, _ME, _MF, _MG, _LA, _LB, _LA, _LG, _LF, _LE, _LD, _LC};

char *serial_f;

int _pganhou[25];
int jog_cert[25] = {12,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
int cont_jog = 0;

char *getascii (unsigned short in_data [], unsigned short off_start, unsigned short off_end)
{
  static char ret_val [255];
  int loop, loop1;

  for (loop = off_start, loop1 = 0; loop <= off_end; loop++)
    {
      ret_val [loop1++] = (char) (in_data [loop] / 256);  /* Get High byte */
      ret_val [loop1++] = (char) (in_data [loop] % 256);  /* Get Low byte */
    }
  ret_val [loop1] = '\0';  /* Make sure it ends in a NULL character */
  return (ret_val);
}

void serial_flash(void)
{
unsigned short dd [256];   /* DiskData */
unsigned short dd_off;     /* DiskData offset */
unsigned short drive;      /* Loop variable */
unsigned long  wait_loop;  /* Timeout loop */
unsigned short base;       /* Base address of drive controller */
unsigned short in_val;

  for (drive = 0; drive < 2; drive++)  /* Loop through drives */
    {
      /* Get IDE Drive info */

      switch (drive / 2)
        {
        case 0: base = 0x1f0;
                break;
        case 1: base = 0x170;
                break;
        case 2: base = 0x1e8;
                break;
        case 3: base = 0x168;
                break;
        }

      /* Wait for controller not busy */
      wait_loop = 100000;
      while (--wait_loop > 0)
        {
        in_val = inp (base + 7);
        if (((in_val & 0x40) == 0x40) || ((in_val & 0x00) == 0x00))
           break;
        }

      if (wait_loop < 1)
        continue;

      outp (base + 6, ((drive % 2) == 0 ? 0xA0 : 0xB0)); /* Get Master/Slave drive */

      outp (base + 7, 0xEC);          /* Get drive info data */

      /* Wait for data ready */
      wait_loop = 100000;
      while (--wait_loop > 0)
        {
        in_val = inp (base + 7);
        if ((in_val & 0x48) == 0x48) /* drive ready and needs service */
          break;
        if ((in_val & 0x01) == 0x01) /* drive error */
          break;
        }

      if ((wait_loop < 1) || ((in_val & 0x01) == 0x01)) /* Timed Out or Error */
        continue;

      for (dd_off = 0; dd_off != 256; dd_off++) /* Read "sector" */
        dd [dd_off] = inpw (base);

      serial_f = getascii (dd, 10, 19);

    }
  
}

void credita_tempo (void)
{
    if(key[KEY_1] && ta_c_credito !=1 ){tecla_credito=1;ta_c_credito=1; _ani_s_credito=890;}
    if(key[KEY_2] && ta_c_credito !=1){tecla_credito=2;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_3] && ta_c_credito !=1){tecla_credito=3;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_4] && ta_c_credito !=1){tecla_credito=4;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_5] && ta_c_credito !=1){tecla_credito=5;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_6] && ta_c_credito !=1){tecla_credito=6;ta_c_credito=1;  _ani_s_credito=890;}
}
END_OF_FUNCTION(credita_tempo);

void incrementa_tempo (void)
{ 
    credita_tempo();
	tempo++;
    credita_tempo();
	animacao++;
    credita_tempo();
	credita_tempo();
    _Slots++;	
    credita_tempo();
    _ani_s_credito++;   
    credita_tempo();
    if(_ani_s_credito > 730 ){ _ani_s_credito=0; animacao=0; taanimando=0;}
    credita_tempo();
    if(_Slots==100)_Slots=50;
    credita_tempo();    
}
END_OF_FUNCTION(incrementa_tempo);


void credita_s_tempo ()
{
    if(key[KEY_1] && ta_c_credito !=1 ){tecla_credito=1;ta_c_credito=1; _ani_s_credito=890;}
    if(key[KEY_2] && ta_c_credito !=1){tecla_credito=2;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_3] && ta_c_credito !=1){tecla_credito=3;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_4] && ta_c_credito !=1){tecla_credito=4;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_5] && ta_c_credito !=1){tecla_credito=5;ta_c_credito=1;  _ani_s_credito=890;}
    if(key[KEY_6] && ta_c_credito !=1){tecla_credito=6;ta_c_credito=1;  _ani_s_credito=890;}
}

struct slots_machine {
int ca1, cb1, cc1, ca2, cb2, cc2, ca3, 
    cb3, cc3, ca4, cb4, cc4, ca5, cb5, cc5;
};             


struct slots_creditos {
int valor_c;        
};

void at_valor_c(void) 
{  
    struct slots_creditos x;
    fb = fopen("x02.dat", "rb");
    fread(&x, sizeof(struct slots_creditos), 1, fb);

    credito = x.valor_c;
    fclose(fb);
    
}

void GeraReg_credito(struct slots_creditos *p)
{
p->valor_c = credito;
}

void grava_valor_c(void)
{
    fb = fopen("x02.dat", "wb");
    struct slots_creditos *pp;
    struct slots_creditos x;
    GeraReg_credito(&x);
    fwrite(&x, sizeof(struct slots_creditos), 1, fb);    
    fclose(fb);
}


struct struct_parametros { 
int ac_max_1; 
int ac_min_1; 
int ac_atual_1; 
int ac_perc_1; 
int ac_max_2; 
int ac_min_2;  
int ac_atual_2; 
int ac_perc_2; 

int ac_max_3; 
int ac_min_3; 
int ac_atual_3; 
int ac_perc_3; 

int perc_ret; 
int cai_bonus; 
int pr_entrada; 
int pr_saida; 
int noteiro;
int ac_jogadas;
int pr_entrada_p; 
int pr_saida_p; 
int pr_jog; 
int pr_na; 
int pr_nb; 
int pr_nc; 
int pr_nd; 
int pr_ne; 
int pr_nf;
int pr_ng; 
int pr_jog_p; 
int pr_aposta_p; 
int pr_premic_p; 
int pr_ult_ent_p; 
int perc_ponto; 
int valor_comido;
int sald_t_acum;
int sald_s_acum;
int valor_com1;
int ser_mst;

}; 

void le_parametros(void)
{  
    struct struct_parametros x;
    fb = fopen("x03.dat", "rb");
    fread(&x, sizeof(struct struct_parametros), 1, fb);

    ac_max_1     = x.ac_max_1; 
    ac_min_1     = x.ac_min_1; 
    ac_atual_1   = x.ac_atual_1; 
    ac_perc_1    = x.ac_perc_1; 
    ac_max_2     = x.ac_max_2; 
    ac_min_2     = x.ac_min_2; 
    ac_atual_2   = x.ac_atual_2; 
    ac_perc_2    = x.ac_perc_2; 

    ac_max_3     = x.ac_max_3;
    ac_min_3     = x.ac_min_3;
    ac_atual_3   = x.ac_atual_3;
    ac_perc_3    = x.ac_perc_3;


    perc_ret     = x.perc_ret; 
    cai_bonus    = x.cai_bonus; 
    pr_entrada   = x.pr_entrada; 
    pr_saida     = x.pr_saida;     
    aj_noteiro   = x.noteiro;
    ac_jogadas   = x.ac_jogadas;
     
    pr_entrada_p = x.pr_entrada_p; 
    pr_saida_p   = x.pr_saida_p;     
    pr_jog       = x.pr_jog;         
    pr_na        = x.pr_na;         
    pr_nb        = x.pr_nb;             
    pr_nc        = x.pr_nc;             
    pr_nd        = x.pr_nd;          
    pr_ne        = x.pr_ne;             
    pr_nf        = x.pr_nf;          
    pr_ng        = x.pr_ng;         
                                
    pr_jog_p     = x.pr_jog_p;
    pr_aposta_p  = x.pr_aposta_p;
    pr_premic_p  = x.pr_premic_p;
    pr_ult_ent_p = x.pr_ult_ent_p;
    perc_ponto   = x.perc_ponto;
    valor_comido = x.valor_comido;
    sald_t_acum  = x.sald_t_acum;
    sald_s_acum  = x.sald_s_acum;
    valor_com1   = x.valor_com1;
    ser_mst      = x.ser_mst;
    fclose(fb);
}

void GeraReg_parametros(struct struct_parametros *p)
{
  
    p->ac_max_1   = ac_max_1; 
    p->ac_min_1   = ac_min_1; 
    p->ac_atual_1 = ac_atual_1; 
    p->ac_perc_1  = ac_perc_1; 
    p->ac_max_2   = ac_max_2; 
    p->ac_min_2   = ac_min_2; 
    p->ac_atual_2 = ac_atual_2; 
    p->ac_perc_2  = ac_perc_2; 

    p->ac_max_3   = ac_max_3; 
    p->ac_min_3   = ac_min_3; 
    p->ac_atual_3 = ac_atual_3; 
    p->ac_perc_3  = ac_perc_3; 

    p->perc_ret   = perc_ret; 
    p->cai_bonus  = cai_bonus; 
    p->pr_entrada = pr_entrada; 
    p->pr_saida   = pr_saida;       
    p->noteiro    = aj_noteiro;
    p->ac_jogadas = ac_jogadas;    
    p->pr_entrada_p = pr_entrada_p; 
    p->pr_saida_p   = pr_saida_p;     
    p->pr_jog       = pr_jog;         
    p->pr_na        = pr_na;         
    p->pr_nb        = pr_nb;             
    p->pr_nc        = pr_nc;             
    p->pr_nd        = pr_nd;         
    p->pr_ne        = pr_ne;             
    p->pr_nf        = pr_nf;         
    p->pr_ng        = pr_ng;                 
    p->pr_jog_p     = pr_jog_p;
    p->pr_aposta_p  = pr_aposta_p;
    p->pr_premic_p  = pr_premic_p;
    p->pr_ult_ent_p = pr_ult_ent_p;
    p->perc_ponto   = perc_ponto;    
    p->valor_comido = valor_comido;
    p->sald_t_acum  = sald_t_acum;
    p->sald_s_acum  = sald_s_acum;
    p->valor_com1   = valor_com1;
    p->ser_mst      = ser_mst;
}                 

void grava_parametros_c(void)
{
    fb = fopen("x03.dat", "wb");
    struct slots_creditos *pp;
    struct struct_parametros x;
    GeraReg_parametros(&x);
    fwrite(&x, sizeof(struct struct_parametros), 1, fb);
    fclose(fb);
}


void carrega_slots();
void inicializa();
void mostra_slots(void);
void Gera_slots_machine(struct slots_machine *p);
void roda_roleta();
void carrega_numeros(void);
void atualiza_slots(void);
void confere_linha(void);
void confere_premio(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5);
void confere_premio2(int _linha, int col1, int col2, int col3, int b1, int b2, int b3);
void confere_verde(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5);
void confere_verde2(int _linha, int col1, int col2, int col3,int a1, int a2, int a3);
void confere_amarelo(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5);
void confere_amarelo2(int _linha, int col1, int col2, int col3, int a1, int a2, int a3);
void inicia_jogar(void);
void bota_credito(void);
void menu_leitura(void);
void leitura(void);
void senha_leitura(void);
void configura_param(void);
void apresenta_acumulado(void);
void at_descredito(void);
void anima_sem_credito(void);
void roda_roleta_anima(void);
void leitura_testes(void);
void leitura_geral(void);
void bonus_abobora_anima(void);
void bonus_magic(void);
void ini_jogo(void);
void bonus_sinuca_anima(void);
void bonus_roleta_Anima(void);
void bonus_caldeirao2_anima(void);
void Linhas_Ace(void);
int main()
{

  allegro_init();
  install_timer();
  install_keyboard();
  set_color_depth(16);
  
  _pres_jogar = 0;
  _Sai_jogo = 0;  
  
  set_gfx_mode(GFX_AUTODETECT, 800, 600, 0, 0);
  rest(150);
  i_tem_som=0;

  install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL); 
  rest(150);
  
  int x;
  for(x = 0; x < 14; x ++) {
      sound(notes[x]);
      delay(100); /* NOTE! THIS CRASHES WINDOWS 98 SOMETIMES */
     }
    sound(0);
 

  textout(screen, font, "     ********** HALLOWEEN EX ESPECIAL ********** ",190, 280, 1500);
  textout(screen, font, "               CARREGANDO AGUARDE... ",200, 300, 1500);
  textout(screen, font, "Special Games - Vs1.00",20, 570, 1500);

  packfile_password("void123456"); 
  imagens = load_datafile("x01.dat");
  sones    = load_datafile("x04.dat"); 
  rest(100);
  
  blefe_bonus=0;
  descredito=0;
  itabela=0;
  icon_tabela=0;
  iconta_ganhou=0;
  ilinha = 0;
  taanimando=0;
  at_valor_c();

  i_TLinha=0;

  aposta1=1; 
  valor_linha =25;  
  premio=0; 
  automatico = 0;   
  bonus=0;
  pago=0;
  ta_c_credito=0;
  iparametros=0;
  vez_acumulado=0;
  int_grampo=4;
  GANHOU_ACUMULADO=0;
  
  _val_pr_valor = 500;
  _val_pr_bonus = 23;  

  slots_top[1]=93;   slots_top[2]=221;
  slots_top[3]=349;  slots_left[1]=57;
  slots_left[2]=198; slots_left[3]=339;
  slots_left[4]=479; slots_left[5]=617;        
   
  RODA_ROLETA=imagens[63].dat;
  RODA_MAGIC=imagens[139].dat;
  BITMAP *nahora;


       
  TEL_SENHA[0]=imagens[102].dat; TEL_SENHA[1]=imagens[103].dat;
  TEL_SENHA[2]=imagens[104].dat; TEL_SENHA[3]=imagens[105].dat;
  TEL_SENHA[4]=imagens[106].dat; TEL_SENHA[5]=imagens[107].dat;
  TEL_SENHA[6]=imagens[108].dat; TEL_SENHA[7]=imagens[109].dat;

    int con, con1;
    for(con=0;con<10;con++)
       {
         for(con1=0;con1<16;con1++)
            {
             PREMIOS[con][con1]=0;
            }
       }   
   
   int i, nuons;
   for(i=0;i<10;i++)
     {
      for(nuons=0;nuons<4;nuons++)
        {
         BONUS[i] [nuons];   
        }
     }

    BONUS[3][3]=4;

    BONUS[0][0]=3;

    BONUS[5][2]=1;

    BONUS[6][0]=2;
    BONUS[6][1]=2;
    BONUS[6][3]=2;
    
    BONUS[5][0]=1;
    BONUS[5][1]=1;
    BONUS[5][3]=1;

    blefe_bonus=0;

    PREMIOS[0][0]=2; /* FANTASMA   */
    PREMIOS[0][1]=5;        
    PREMIOS[0][2]=30;
    PREMIOS[0][3]=20;            

    PREMIOS[1][0]=5; /* FRANCKSTEIM*/
    PREMIOS[1][1]=7;        
    PREMIOS[1][2]=30; 
    PREMIOS[1][3]=20;           

    PREMIOS[2][0]=5; /* DRACULA*/
    PREMIOS[2][1]=30;        
    PREMIOS[2][2]=75; 
    PREMIOS[2][3]=50;           

    PREMIOS[3][0]=7; /* WHITCH*/
    PREMIOS[3][1]=100;        
    PREMIOS[3][2]=150; 
    PREMIOS[3][3]=75;            

    PREMIOS[4][0]=10; /* ESPANTALHO*/
    PREMIOS[4][1]=50;        
    PREMIOS[4][2]=200; 
    PREMIOS[4][3]=100;           

    PREMIOS[5][0]=0; /* CALDEIRAO*/
    PREMIOS[5][1]=0;        
    PREMIOS[5][2]=0;  
    PREMIOS[5][3]=0;          
    
    PREMIOS[6][0]=0; /* BRUXA VASSOURA*/
    PREMIOS[6][1]=0;        
    PREMIOS[6][2]=2000;  
    PREMIOS[6][3]=0;           
    
    PREMIOS[7][0]=250; /* BRUXA MAGIC*/
    PREMIOS[7][1]=500;
    PREMIOS[7][2]=2000;
    PREMIOS[7][3]=200;   

    PREMIOS[8][0]=250; /* CAO   */
    PREMIOS[8][1]=1000;
    PREMIOS[8][2]=2000;
    PREMIOS[8][3]=250;  

    PREMIOS[9][0]=200; /* ABOBORA*/
    PREMIOS[9][1]=500;        
    PREMIOS[9][2]=1000; 
    PREMIOS[9][3]=300;             
  
    /*  quadrados do morango */
    quad[0][0]=91;  quad[0][1]=95;  quad[0][2]=246; quad[0][3]=250;
    quad[1][0]=251; quad[1][1]=95;  quad[1][2]=405; quad[1][3]=250;
    quad[2][0]=410; quad[2][1]=95;  quad[2][2]=563; quad[2][3]=250;
    quad[3][0]=569; quad[3][1]=95;  quad[3][2]=722; quad[3][3]=250;
  
    quad[4][0]=91;  quad[4][1]=255; quad[4][2]=246; quad[4][3]=408;
    quad[5][0]=251; quad[5][1]=255; quad[5][2]=405; quad[5][3]=408;
    quad[6][0]=410; quad[6][1]=255; quad[6][2]=563; quad[6][3]=408;
    quad[7][0]=569; quad[7][1]=255; quad[7][2]=722; quad[7][3]=408;

    quad[8] [0]=91;  quad[8] [1]=414; quad[8] [2]=246; quad[8] [3]=567;
    quad[9] [0]=251; quad[9] [1]=414; quad[9] [2]=405; quad[9] [3]=567;
    quad[10][0]=410; quad[10][1]=414; quad[10][2]=563; quad[10][3]=567;
    quad[11][0]=569; quad[11][1]=414; quad[11][2]=722; quad[11][3]=567;    
    
    P_MORANG[0][0]=94;  P_MORANG[0][1]=98;      
    P_MORANG[1][0]=254; P_MORANG[1][1]=98; 
    P_MORANG[2][0]=412; P_MORANG[2][1]=98;  
    P_MORANG[3][0]=571; P_MORANG[3][1]=98;  
      
    P_MORANG[4][0]=94;  P_MORANG[4][1]=257;
    P_MORANG[5][0]=254; P_MORANG[5][1]=257; 
    P_MORANG[6][0]=412; P_MORANG[6][1]=257;  
    P_MORANG[7][0]=571; P_MORANG[7][1]=257;    
       
    P_MORANG[8][0]=94;   P_MORANG[8][1]=416;
    P_MORANG[9][0]=254;  P_MORANG[9][1]=416; 
    P_MORANG[10][0]=412; P_MORANG[10][1]=416;  
    P_MORANG[11][0]=571; P_MORANG[11][1]=416;  
  
   IMG_VAL_CALDEIRAO1[0]= imagens[11].dat;      
   IMG_VAL_CALDEIRAO1[1]= imagens[12].dat;
   IMG_VAL_CALDEIRAO1[2]= imagens[13].dat;
   IMG_VAL_CALDEIRAO1[3]= imagens[14].dat;
   IMG_VAL_CALDEIRAO1[4]= imagens[15].dat;
   IMG_VAL_CALDEIRAO1[5]= imagens[16].dat;
   IMG_VAL_CALDEIRAO1[6]= imagens[17].dat;
   IMG_VAL_CALDEIRAO1[7]= imagens[18].dat;    
   IMG_VAL_CALDEIRAO1[8]= imagens[114].dat;    
   
   IMG_VAL_CALDEIRAO2[0]= imagens[143].dat;      
   IMG_VAL_CALDEIRAO2[1]= imagens[144].dat;
   IMG_VAL_CALDEIRAO2[2]= imagens[145].dat;
   IMG_VAL_CALDEIRAO2[3]= imagens[146].dat;
   IMG_VAL_CALDEIRAO2[4]= imagens[147].dat;
   IMG_VAL_CALDEIRAO2[5]= imagens[148].dat;

   VAL_ABOBORA[0][0] =3; VAL_ABOBORA[0][1] =4; VAL_ABOBORA[0][2] =5; VAL_ABOBORA[0][3] =6; VAL_ABOBORA[0][4] =7;
   VAL_ABOBORA[1][0] =4; VAL_ABOBORA[1][1] =5; VAL_ABOBORA[1][2] =6; VAL_ABOBORA[1][3] =7; VAL_ABOBORA[1][4] =3;
   VAL_ABOBORA[2][0] =5; VAL_ABOBORA[2][1] =6; VAL_ABOBORA[2][2] =7; VAL_ABOBORA[2][3] =3; VAL_ABOBORA[2][4] =4;    
   VAL_ABOBORA[3][0] =6; VAL_ABOBORA[3][1] =7; VAL_ABOBORA[3][2] =3; VAL_ABOBORA[3][3] =4; VAL_ABOBORA[3][4] =5;       
   VAL_ABOBORA[4][0] =7; VAL_ABOBORA[4][1] =3; VAL_ABOBORA[4][2] =4; VAL_ABOBORA[4][3] =5; VAL_ABOBORA[4][4] =6; 
   VAL_ABOBORA[5][0] =7; VAL_ABOBORA[5][1] =5; VAL_ABOBORA[5][2] =6; VAL_ABOBORA[5][3] =3; VAL_ABOBORA[5][4] =4;
   VAL_ABOBORA[6][0] =3; VAL_ABOBORA[6][1] =5; VAL_ABOBORA[6][2] =6; VAL_ABOBORA[6][3] =7; VAL_ABOBORA[6][4] =4;
   VAL_ABOBORA[7][0] =6; VAL_ABOBORA[7][1] =7; VAL_ABOBORA[7][2] =3; VAL_ABOBORA[7][3] =4; VAL_ABOBORA[7][4] =5;       
   VAL_ABOBORA[8][0] =5; VAL_ABOBORA[8][1] =6; VAL_ABOBORA[8][2] =7; VAL_ABOBORA[8][3] =3; VAL_ABOBORA[8][4] =4;           
   VAL_ABOBORA[9][0] =3; VAL_ABOBORA[9][1] =4; VAL_ABOBORA[9][2] =5; VAL_ABOBORA[9][3] =6; VAL_ABOBORA[9][4] =7;   
   VAL_ABOBORA[10][0]=3; VAL_ABOBORA[10][1]=4; VAL_ABOBORA[10][2]=2; VAL_ABOBORA[10][3]=6; VAL_ABOBORA[10][4]=7;       
          
   VAL_CALDEIRAO[0][0] =0; VAL_CALDEIRAO[0][1] =1; VAL_CALDEIRAO[0][2] =2; VAL_CALDEIRAO[0][3] =3; VAL_CALDEIRAO[0][4] =8;
   VAL_CALDEIRAO[1][0] =1; VAL_CALDEIRAO[1][1] =2; VAL_CALDEIRAO[1][2] =3; VAL_CALDEIRAO[1][3] =8; VAL_CALDEIRAO[1][4] =0;
   VAL_CALDEIRAO[2][0] =2; VAL_CALDEIRAO[2][1] =3; VAL_CALDEIRAO[2][2] =8; VAL_CALDEIRAO[2][3] =0; VAL_CALDEIRAO[2][4] =1;    
   VAL_CALDEIRAO[3][0] =3; VAL_CALDEIRAO[3][1] =8; VAL_CALDEIRAO[3][2] =0; VAL_CALDEIRAO[3][3] =1; VAL_CALDEIRAO[3][4] =2;       
   VAL_CALDEIRAO[4][0] =8; VAL_CALDEIRAO[4][1] =0; VAL_CALDEIRAO[4][2] =1; VAL_CALDEIRAO[4][3] =2; VAL_CALDEIRAO[4][4] =3; 
   VAL_CALDEIRAO[5][0] =8; VAL_CALDEIRAO[5][1] =2; VAL_CALDEIRAO[5][2] =3; VAL_CALDEIRAO[5][3] =0; VAL_CALDEIRAO[5][4] =1;
   VAL_CALDEIRAO[6][0] =0; VAL_CALDEIRAO[6][1] =2; VAL_CALDEIRAO[6][2] =3; VAL_CALDEIRAO[6][3] =8; VAL_CALDEIRAO[6][4] =1;
   VAL_CALDEIRAO[7][0] =3; VAL_CALDEIRAO[7][1] =8; VAL_CALDEIRAO[7][2] =0; VAL_CALDEIRAO[7][3] =1; VAL_CALDEIRAO[7][4] =2;       
   VAL_CALDEIRAO[8][0] =2; VAL_CALDEIRAO[8][1] =3; VAL_CALDEIRAO[8][2] =8; VAL_CALDEIRAO[8][3] =0; VAL_CALDEIRAO[8][4] =1;           
   VAL_CALDEIRAO[9][0] =0; VAL_CALDEIRAO[9][1] =1; VAL_CALDEIRAO[9][2] =2; VAL_CALDEIRAO[9][3] =3; VAL_CALDEIRAO[9][4] =8;   
   VAL_CALDEIRAO[10][0]=0; VAL_CALDEIRAO[10][1]=1; VAL_CALDEIRAO[10][2]=2; VAL_CALDEIRAO[10][3]=3; VAL_CALDEIRAO[10][4]=8;       
  
   VAL_CALDEIRAO2[0][0] =0; VAL_CALDEIRAO2[0][1] =0; VAL_CALDEIRAO2[0][2] =0; VAL_CALDEIRAO2[0][3] =0; VAL_CALDEIRAO2[0][4] =0;
   VAL_CALDEIRAO2[1][0] =1; VAL_CALDEIRAO2[1][1] =1; VAL_CALDEIRAO2[1][2] =1; VAL_CALDEIRAO2[1][3] =1; VAL_CALDEIRAO2[1][4] =1;
   VAL_CALDEIRAO2[2][0] =2; VAL_CALDEIRAO2[2][1] =2; VAL_CALDEIRAO2[2][2] =2; VAL_CALDEIRAO2[2][3] =2; VAL_CALDEIRAO2[2][4] =2;
   VAL_CALDEIRAO2[3][0] =3; VAL_CALDEIRAO2[3][1] =3; VAL_CALDEIRAO2[3][2] =3; VAL_CALDEIRAO2[3][3] =3; VAL_CALDEIRAO2[3][4] =3;
   VAL_CALDEIRAO2[4][0] =4; VAL_CALDEIRAO2[4][1] =4; VAL_CALDEIRAO2[4][2] =4; VAL_CALDEIRAO2[4][3] =4; VAL_CALDEIRAO2[4][4] =4;
   VAL_CALDEIRAO2[5][0] =5; VAL_CALDEIRAO2[5][1] =5; VAL_CALDEIRAO2[5][2] =5; VAL_CALDEIRAO2[5][3] =5; VAL_CALDEIRAO2[5][4] =5;


   VAL_SINUCA[0][0] =0; VAL_SINUCA[0][1] =5; VAL_SINUCA[0][2] =2; VAL_SINUCA[0][3] =52;
   VAL_SINUCA[1][0] =0; VAL_SINUCA[1][1] =7; VAL_SINUCA[1][2] =3; VAL_SINUCA[1][3] =73;
   VAL_SINUCA[2][0] =0; VAL_SINUCA[2][1] =7; VAL_SINUCA[2][2] =6; VAL_SINUCA[2][3] =76;
   VAL_SINUCA[3][0] =0; VAL_SINUCA[3][1] =8; VAL_SINUCA[3][2] =8; VAL_SINUCA[3][3] =88;
   VAL_SINUCA[4][0] =0; VAL_SINUCA[4][1] =9; VAL_SINUCA[4][2] =1; VAL_SINUCA[4][3] =91;         
   VAL_SINUCA[5][0] =1; VAL_SINUCA[5][1] =0; VAL_SINUCA[5][2] =6; VAL_SINUCA[5][3] =106;
   VAL_SINUCA[6][0] =1; VAL_SINUCA[6][1] =1; VAL_SINUCA[6][2] =0; VAL_SINUCA[6][3] =110;
   VAL_SINUCA[7][0] =1; VAL_SINUCA[7][1] =3; VAL_SINUCA[7][2] =5; VAL_SINUCA[7][3] =135;
   VAL_SINUCA[8][0] =1; VAL_SINUCA[8][1] =5; VAL_SINUCA[8][2] =0; VAL_SINUCA[8][3] =150;
   VAL_SINUCA[9][0] =3; VAL_SINUCA[9][1] =2; VAL_SINUCA[9][2] =1; VAL_SINUCA[9][3] =321;         
   VAL_SINUCA[10][0]=4; VAL_SINUCA[10][1]=4; VAL_SINUCA[10][2]=6; VAL_SINUCA[10][3]=446;

   CAL_CALD[0][0]=50;
   CAL_CALD[0][1]=75;              
   CAL_CALD[0][2]=100;
   CAL_CALD[0][3]=150;
   CAL_CALD[0][8]=0;  

   CAL_CALD[1][3]=150;
   CAL_CALD[1][4]=200;
   CAL_CALD[1][5]=250;
   CAL_CALD[1][6]=500; 
   CAL_CALD[1][7]=1000;

   CAL_CALD3[0][0]=1;
   CAL_CALD3[0][1]=2;              
   CAL_CALD3[0][2]=3;
   CAL_CALD3[0][3]=4;
   CAL_CALD3[0][4]=5;  
   CAL_CALD3[0][5]=6;
  
   CALD_BRUXA[0]=2;
   CALD_BRUXA[1]=5;           
   CALD_BRUXA[2]=5;
   CALD_BRUXA[3]=2;
   CALD_BRUXA[4]=10;
   CALD_BRUXA[5]=50;
   CALD_BRUXA[6]=20;
   CALD_BRUXA[7]=100;
   CALD_BRUXA[8]=10;
   CALD_BRUXA[9]=50;
   CALD_BRUXA[10]=20;
   CALD_BRUXA[11]=100;
         
   int valsi;
   nuons =  0;
   valsi = 1;

   for(i=0;i<70;i++)
      DABONUS[i]=0; 
      
   DABONUS[33]=1;  
   DABONUS[25]=3;
   DABONUS[39]=5;
         
   for(i=0;i<100;i++)
     {
      if (nuons<7)     
         {
          VALORES_MORANGO[i]=(rand() % valsi);
          valsi=valsi+1;
          nuons++;
         }        
      else
        {
          VALORES_MORANGO[i]=0;
          valsi=valsi+3;
          nuons=0;
        }        

     }

   nuons=0;
   for(i=0;i<25;i++) 
     {
      VALOR_ROLETA[i]=nuons;
      nuons=nuons+5;
     }  
           
    nuons=25;
    for (i=0;i<20;i++)
      {  
       BMP_LINHAS[i] = imagens[nuons].dat;
       nuons++;
     }  

    nuons=118;
    for (i=0;i<20;i++)
      {  
       BMP_LINHAS_P[i] = imagens[nuons].dat;
       nuons++;
     }  


    BITMAP *bmp_cria_sub;
    int _i=0;
/*
    bmp_cria_sub = imagens[2].dat;
    for (i=0;i<9;i++)
      {  
       ANIMA_AC[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/9, bmp_cria_sub->h/1);
       _i=_i+41;
     }  
*/

    bmp_cria_sub = imagens[3].dat;
    _i=0;
    for (i=0;i<8;i++)
      {  
       ANIMA_DESC[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/8, bmp_cria_sub->h);
       _i=_i+208;
     }  

    bmp_cria_sub = imagens[6].dat;
    _i=0;
    for(con=0;con<12;con++)
       {
         BONECO_SENHA[con]= create_sub_bitmap(bmp_cria_sub, _i, 0, bmp_cria_sub->w/12, bmp_cria_sub ->h);
         _i=_i+334;        
       } 

    _i=0;
    bmp_cria_sub = imagens[8].dat;
    for (i=0;i<8;i++)
      {
       IMG_ROLETA[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/8, bmp_cria_sub->h/1);
       _i=_i+60;
      } 
   
    bmp_cria_sub = imagens[54].dat;
    _i=0;
    for (i=0;i<12;i++)
      {
        ANIMA_MORANGO1[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/25, bmp_cria_sub->h/1);
        _i=_i+150;
      }     
                
    bmp_cria_sub = imagens[54].dat;
    _i=1800;
    for (i=0;i<12;i++)
      {
        ANIMA_MORANGO2[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/25, bmp_cria_sub->h/1);
        _i=_i+150;
      }               

    bmp_cria_sub = imagens[55].dat;
    _i=0;
    for (i=0;i<12;i++)
      {
        ANIMA_MORANGO3[i]= create_sub_bitmap(bmp_cria_sub,    _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h/1);
        _i=_i+150;
      }
 
    bmp_cria_sub = imagens[19].dat;
    _i=0;
    for (i=0;i<16;i++)
      {
        ANIMA_CALDEIRAO[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/17, bmp_cria_sub->h/1);
        _i=_i+150;
      }


    bmp_cria_sub = imagens[20].dat;
    _i=0;
    for (i=0;i<9;i++)
      {
        ANIMA_CALDEIRAO1[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/9, bmp_cria_sub->h/1);
        _i=_i+150;
      }

    bmp_cria_sub = imagens[142].dat;
    _i=0;
    for (i=0;i<12;i++)
      {
        ANIMA_CALDEIRAO3[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h/1);
        _i=_i+128;
      }

    bmp_cria_sub = imagens[140].dat;
    _i=0;
    for (i=0;i<72;i++)
      {
        ANIMA_CALDEIRAO2[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/72, bmp_cria_sub->h/1);
        _i=_i+128;
      }

    bmp_cria_sub = imagens[0].dat;
    _i=0;
    for (i=0;i<15;i++)
      {
        ANIMA_ABOBORA[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/15, bmp_cria_sub->h/1);
        _i=_i+150;
      }
  
    bmp_cria_sub = imagens[1].dat;
    _i=0;
    for (i=0;i<48;i++)
      {
        ANIMA_ABOBORA1[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/37, bmp_cria_sub->h/1);
        _i=_i+150;
        if(i==37)_i=0;
      }  

    bmp_cria_sub = imagens[4].dat;
    _i=0;
    for (i=0;i<8;i++)
      {
        IMG_BONECO[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/8, bmp_cria_sub->h/1);
        _i=_i+303;
      }

    bmp_cria_sub = imagens[149].dat;
    _i=0;
    for (i=0;i<12;i++)
      {
        IMG_BONECO5[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h/1);
        _i=_i+200;
      }

    bmp_cria_sub = imagens[7].dat;
    _i=0;
    for (i=0;i<12;i++)
      {
        ANI_CAVER[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h);
        _i=_i+120;
      }


    bmp_cria_sub = imagens[5].dat;
    _i=0;
    for (i=0;i<8;i++)
      {
        IMG_CARRO[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/8, bmp_cria_sub->h/1);
        _i=_i+350;
      }

    bmp_cria_sub = imagens[9].dat;
    _i=0;
    for (i=0;i<15;i++)
      {
        NUM_PISCA[i]= create_sub_bitmap(bmp_cria_sub,   _i, 0, bmp_cria_sub->w/15, bmp_cria_sub->h/1);
        _i=_i+75;
      }

    _i=68;
    int cag, cest=0;
    for (i=0;i<10;i++)
      {
        bmp_cria_sub  = imagens[_i].dat;
        cest=0;
        for(cag=0;cag<6;cag++)
            {
             BOLAS_SINUCA[i][cag]= create_sub_bitmap(bmp_cria_sub,   cest, 0, bmp_cria_sub->w/6, bmp_cria_sub->h/1);
             cest=cest+135;             
            } 
        _i++;
      }
       
    i_img[0]= 110; i_img[1]= 220; i_img[2]= 330;
    i_img[3]= 450; i_img[4]= 560; i_img[5]= 680;
    i_img[6]= 790; i_img[7]= 900; i_img[8]= 1010;
    i_img[9]= 1130;

    VALOR_B[0]= 50;
    VALOR_B[1]= 100;
    VALOR_B[2]= 150;
    VALOR_B[3]= 200;
    VALOR_B[4]= 250;
    VALOR_B[5]= 300;
    VALOR_B[6]= 350;
    VALOR_B[7]= 400;
    VALOR_B[8]= 500; 
    VALOR_B[9]= 1000; 
   
    ft     = fopen("x05.dat", "rb");/*menor q 19*/
    fBonus = fopen("x06.dat", "rb");/* bonus*/
    fAlt   = fopen("x09.dat", "rb");/* paga valor alto*/
    fAc    = fopen("x08.dat", "rb"); /* acumulado*/
    fPag   = fopen("x07.dat", "rb");/* paga maior q 30 menor q 90 e maior q 2200 e menor q 8000*/
    fAc1   = fopen("x10.dat", "rb");/* paga o 3º acumulado */

    carrega_numeros();

    bmp_cria_sub = imagens[79].dat; /* ROLOS SINUCA*/
    _i=0;
    for (i=0;i<11;i++)
        {
         ROLOS_SINUCA[i]= create_sub_bitmap(bmp_cria_sub, _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h/1);
         _i=_i+135;
        }

    bmp_cria_sub  = imagens[53].dat;
    BMP_MSN[0]= create_sub_bitmap(bmp_cria_sub, 0, 0,  bmp_cria_sub->w/1, bmp_cria_sub->h/4);
    BMP_MSN[1]= create_sub_bitmap(bmp_cria_sub, 0, 24, bmp_cria_sub->w/1, bmp_cria_sub->h/4);
    BMP_MSN[2]= create_sub_bitmap(bmp_cria_sub, 0, 48, bmp_cria_sub->w/1, bmp_cria_sub->h/4);
    BMP_MSN[3]= create_sub_bitmap(bmp_cria_sub, 0, 72, bmp_cria_sub->w/1, bmp_cria_sub->h/4);

    bmp_cria_sub = imagens[78].dat; /* PULA SINUCA*/
    _i=0;
    for (i=0;i<11;i++)
        {
         PULA_BOLA_SINUCA[i]= create_sub_bitmap(bmp_cria_sub,     _i, 0, bmp_cria_sub->w/12, bmp_cria_sub->h/1);
         _i=_i+135;
        }
        
    bmp_cria_sub  = imagens[66].dat; /*TRIANGULO SINUCA*/
    _i=0;
    for (i=0;i<16;i++)
        {
         EMP_BOLAS_SINUCA[i]= create_sub_bitmap(bmp_cria_sub, _i, 0, bmp_cria_sub->w/16, bmp_cria_sub->h/1);
         _i=_i+117;
        }

    bmp_cria_sub  = imagens[80].dat; /*TACO SINUCA*/
    _i=0;
    for (i=0;i<16;i++)
        {
         TACO_SINUCA[i]= create_sub_bitmap(bmp_cria_sub,     _i, 0, bmp_cria_sub->w/16, bmp_cria_sub->h/1);
         _i=_i+143;
        }

    bmp_cria_sub  = imagens[67].dat; /*MESA SINUCA*/
    _i=0;
    for (i=0;i<6;i++)
        {
         MESA_SINUCA[i]= create_sub_bitmap(bmp_cria_sub,     _i, 0, bmp_cria_sub->w/6, bmp_cria_sub->h/1);
         _i=_i+156;
        }

    bmp_cria_sub  = imagens[65].dat; /*HOMEM SINUCA*/
    _i=0;
    for (i=0;i<6;i++)
        {
         BONECO_SINUCA[i]= create_sub_bitmap(bmp_cria_sub, _i, 0, bmp_cria_sub->w/6, bmp_cria_sub->h/1);
         _i=_i+130;
        }
    clear(screen); 

    le_parametros();
/*

    pr_entrada = 80000;  
    pr_saida   = 48000;
    credito    = 0;   
    ac_max_1   = 200000;
    ac_min_1   = 10000; 
    ac_perc_1  = 1; 
    ac_atual_1 = 100000; 
    ac_max_2   = 100000;
    ac_min_2   = 10000; 
    ac_perc_2  = 1; 
    ac_atual_2 = 50000; 

    ac_max_3   = 50000;
    ac_min_3   = 10000; 
    ac_perc_3  = 1; 
    ac_atual_3 = 10000; 

    perc_ret   = 2; 
    cai_bonus  = 0;
 
    pr_jog_p     = 1;
    pr_aposta_p  = 80000;
    pr_premic_p  = 48000;
    pr_ult_ent_p = 1; 
    pr_entrada_p = 80000;
    pr_saida_p   = 48000;
    perc_ponto   = 25;
    valor_comido = 300;
    sald_t_acum  = 1;
    sald_s_acum  = 1;
    valor_com1   = 100;
    ser_mst      = 12345612;
    grava_parametros_c();

*/

  buffer = create_bitmap( 800, 600 );
  carrega_slots();

/*  textout(screen, font, serial_f ,10, 40, 1000);  */
  

  if(ser_mst == 12345612)
    {
      ini_jogo();      
    }

  itaok=0;
  draw_sprite(screen, imagens[85].dat, 0,0 );
  draw_sprite(screen, imagens[62].dat, 70,70 );

  mostra_slots();

  draw_sprite(screen, NUM_PISCA[0], 670,60 );

  mostra_leitura_ac(ac_atual_3, 360);
  mostra_leitura_ac(ac_atual_2, 90);
  mostra_leitura_ac(ac_atual_1, 590);    
  Linhas_Ace();
  
  atualiza_credito();  
  atualiza_premio();
  atualiza_aposta();
  mostra_num();

  le_parametros();
  inicializa();

}END_OF_MAIN();


void inicializa()
{

    srand(time(NULL));   
    itaok      = 0;
    animacao   = 0;
    automatico = 0;
	tempo      = 0;
    blefe_bonus	= 0;
    
	LOCK_FUNCTION(credita_tempo);
	install_int(credita_tempo, 1);

	LOCK_VARIABLE(tempo);
	LOCK_VARIABLE(animacao);
	LOCK_VARIABLE(_Slots);
    LOCK_VARIABLE(_ani_s_credito);
	LOCK_FUNCTION(incrementa_tempo);
	install_int(incrementa_tempo, 50);

  while (!key[KEY_ESC])
   {
        
       if (GANHOU_ACUMULADO>0)
          {
           __conta_jogadas=0;
           valor_comido=0;
           valor_com1=0;
           __conta_bonus=0;
           automatico=0;
           if (GANHOU_ACUMULADO==1)
              {
                if(valor_linha * aposta1 > 49)
                  {
                     q_acum = ac_atual_1;
                     sald_s_acum = 0;
                     ac_atual_1=ac_min_1;                  
                     grava_parametros_c();
                     premio = premio + ac_atual_1;
                     apresenta_acumulado();
                  }
                else
                if(valor_linha * aposta1 < 50)
                  {
                     sald_s_acum = 0;
                     premio=premio+10000 * aposta1;
                     grava_parametros_c();
                  }

              }
           else     
           if (GANHOU_ACUMULADO==2)
              {
                if(valor_linha * aposta1 > 49)
                  {
                     q_acum = ac_atual_2;
                     sald_s_acum = 0;
                     ac_atual_2 = ac_min_2;
                     premio = premio + ac_atual_2;
                     grava_parametros_c();
                     apresenta_acumulado();
                  }
                else
                if(valor_linha * aposta1 < 50)
                  {
                     sald_s_acum = 0;
                     premio=premio+2000 * aposta1;
                     grava_parametros_c();
                  }
              }
           else     
           if (GANHOU_ACUMULADO==3)
              {

                if(valor_linha * aposta1 > 49)
                  {
                     q_acum = ac_atual_3;
                     sald_t_acum = 0;
                     ac_atual_3 = ac_min_3;
                     premio = premio + ac_atual_3;
                     grava_parametros_c();
                     apresenta_acumulado();
                  }
                else
                if(valor_linha * aposta1 < 50)
                  {
                     sald_t_acum = 0;
                     premio = premio + 200 * aposta1;
                     grava_parametros_c();
                  }
              }

           rest(200);
           GANHOU_ACUMULADO=0;
           __conta_bonus=0;
           __conta_jogadas=0;
           valor_comido = 0;
           valor_com1 = 0;
           mostra_leitura_ac(ac_atual_3, 360);
           mostra_leitura_ac(ac_atual_2, 90);
           mostra_leitura_ac(ac_atual_1, 590);    
           Linhas_Ace();
         }  

            
      if (premio>0 && blefe_bonus==0)
        {
          confere_linha();    
          if(premio>400)
            {              
              play_sample (sones[39].dat, 255, 128, 1000, 0);
              rest(400);
              play_sample (sones[40].dat, 255, 128, 1000, 0);
              rest(400);
              play_sample (sones[39].dat, 255, 128, 1000, 0);
              rest(400);
              play_sample (sones[40].dat, 255, 128, 1000, 0);
              rest(900);
            }  
          

          if(premio > (valor_linha * aposta1))
            { 
             _val_pr_valor = _val_pr_valor + ((premio * 20)/100);
            } 
          mostra_ganhos();                
        }   

        if (blefe_bonus>0)
           {
            play_sample (sones[3].dat, 255, 128, 1000, 0);
            rest(900);
            play_sample (sones[3].dat, 255, 128, 1000, 0);
            rest(900);
            play_sample (sones[3].dat, 255, 128, 1000, 0);
            rest(1150);
            __conta_bonus=0;  
            if(blefe_bonus==4)bonus_roleta();
            if(blefe_bonus==3)bonus_caldeirao2();
            if(blefe_bonus==2)bonus_morando();
            if(blefe_bonus==1)bonus_caldeirao();

            _val_pr_bonus = _val_pr_bonus + 1 + rand()%3;
            
            grava_valor_c();
            clear(buffer);
            draw_sprite(screen, imagens[85].dat, 0,0 );
            draw_sprite(screen, imagens[62].dat, 70,70 );
            atualiza_slots();
            mostra_num();
            atualiza_credito();
            atualiza_aposta();             
            itabela=0;
            icon_tabela=0;
            mostra_leitura_ac(ac_atual_3, 360);
            mostra_leitura_ac(ac_atual_2, 90);
            mostra_leitura_ac(ac_atual_1, 590);    
            atualiza_premio();
            Linhas_Ace();
            
            if(credito>0) 
              {
               mostra_ganhos();
               grava_valor_c();
              } 
            blefe_bonus = 0;
            __conta_bonus = 0;

           }


        if(key[KEY_Y] && taanimando==0 && credito > 0 && blefe_bonus==0 && itaok==0 && automatico==0 ) /* 1 LINHA*/
          {
           if (ilinha!=1)
             {
              sound(notes[1]);
              sound(0);
              valor_linha = 1;
              draw_sprite(screen, imagens[50].dat, 52,87 ); /* limpa tela central*/  
              draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
              atualiza_slots();
              mostra_num();
              atualiza_credito();
              atualiza_aposta();             
              itabela=0;
              icon_tabela=0;
              mostra_leitura_ac(ac_atual_3, 360);
              mostra_leitura_ac(ac_atual_2, 90);
              mostra_leitura_ac(ac_atual_1, 590);    
              play_sample (sones[19].dat, 255, 128, 1000, 0);
              atualiza_slots();
              cria_linha1();
              Linhas_Ace();
              ilinha = 1;
              rest(80);
              }
           }

        if(key[KEY_J] && taanimando==0 && credito > 0 && blefe_bonus==0 && itaok==0 && automatico==0 ) /* 5 LINHA */
          {
           if (ilinha!=5)
             {
               sound(notes[1]);
               sound(0);
               valor_linha = 5;
               draw_sprite(screen, imagens[50].dat, 52,87 );
               draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
               atualiza_slots();
               mostra_num();
               atualiza_credito();
               atualiza_aposta();             
               itabela=0;
               icon_tabela=0;
               mostra_leitura_ac(ac_atual_3, 360);
               mostra_leitura_ac(ac_atual_2, 90);
               mostra_leitura_ac(ac_atual_1, 590);    
               play_sample (sones[19].dat, 255, 128, 1000, 0);
               atualiza_slots();
               acquire_screen();
               cria_linha1(); cria_linha2(); cria_linha3();           
               cria_linha4(); cria_linha5(); 
               release_screen();
               ilinha = 5;
               Linhas_Ace();
               rest(80);
             }
           }

        if(key[KEY_H] && taanimando==0 && credito > 0 && blefe_bonus==0 && itaok==0 && automatico==0 ) /* 9 LINHA*/
          {
           if (ilinha!=9) 
             {
               sound(notes[1]);
               sound(0);
               atualiza_credito();
               valor_linha = 9;
               draw_sprite(screen, imagens[50].dat, 52,87 );
               draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
               atualiza_slots();
               mostra_num();
               atualiza_credito();
               atualiza_aposta();             
               itabela=0;
               icon_tabela=0;
               mostra_leitura_ac(ac_atual_3, 360);
               mostra_leitura_ac(ac_atual_2, 90);
               mostra_leitura_ac(ac_atual_1, 590);    
               play_sample (sones[19].dat, 255, 128, 1000, 0);
               atualiza_slots();
               acquire_screen();               
               cria_linha1(); cria_linha2(); cria_linha3();
               cria_linha4(); cria_linha5(); cria_linha6();
               cria_linha7(); cria_linha8(); cria_linha9();
               Linhas_Ace();
               release_screen();
               rest(80);
               ilinha =9;
              }
           } 

        if(key[KEY_M] && taanimando==0 && credito > 0 && blefe_bonus==0 && itaok==0 && automatico==0 ) /* 15 LINHAS*/
          {
           if (ilinha!=15)
             {
               sound(notes[1]);
               sound(0);
               valor_linha = 15;
               draw_sprite(screen, imagens[50].dat, 52,87 );
               draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
               atualiza_slots();
               mostra_num();
               atualiza_credito();
               atualiza_aposta();             
               itabela=0;
               icon_tabela=0;
               mostra_leitura_ac(ac_atual_3, 360);
               mostra_leitura_ac(ac_atual_2, 90);
               mostra_leitura_ac(ac_atual_1, 590);    
               play_sample (sones[19].dat, 255, 128, 1000, 0);
               atualiza_slots();
               acquire_screen();               
               cria_linha1();  cria_linha2();  cria_linha3();           
               cria_linha4();  cria_linha5();  cria_linha6();
               cria_linha7();  cria_linha8();  cria_linha9();                                            
               cria_linha10(); cria_linha11(); cria_linha12();
               cria_linha13(); cria_linha14(); cria_linha15();                                            
               Linhas_Ace();
               release_screen();
               rest(80);
               ilinha=15;
              }
           }


        if(key[KEY_N] && taanimando==0 && credito > 0 && blefe_bonus==0 && itaok==0 && automatico==0 ) /* 20 LINHA*/
          {
           if (ilinha!=20)
             {
               sound(notes[1]);
               sound(0);
               valor_linha = 25;
               draw_sprite(screen, imagens[50].dat, 52,87 );
               draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
               atualiza_slots();
               mostra_num();
               atualiza_credito();
               atualiza_aposta();             
               itabela=0;
               icon_tabela=0;
               mostra_leitura_ac(ac_atual_3, 360);
               mostra_leitura_ac(ac_atual_2, 90);
               mostra_leitura_ac(ac_atual_1, 590);    
               play_sample (sones[19].dat, 255, 128, 1000, 0);
               atualiza_slots();
               acquire_screen();
               cria_linha1();  cria_linha2();  cria_linha3();           
               cria_linha4();  cria_linha5();  cria_linha6();
               cria_linha7();  cria_linha8();  cria_linha9();                                            
               cria_linha10(); cria_linha11(); cria_linha12();
               cria_linha13(); cria_linha14(); cria_linha15();                                            
               cria_linha16(); cria_linha17(); cria_linha18();
               cria_linha19(); cria_linha20(); cria_linha21();
               cria_linha22(); cria_linha23(); cria_linha24();
               cria_linha25();
               Linhas_Ace();
               release_screen();
               rest(80);
               ilinha=20;
              } 
           }


        if(key[KEY_G] && taanimando==0  && automatico==0 && credito > 0 && blefe_bonus==0 && itaok==0)
           {
             sound(notes[3]);
             sound(0);
             __conta_bonus=rand()%6;
             __conta_jogadas=rand()%5;
            play_sample (sones[14].dat, 255, 128, 1000, 0);
            aposta1 = aposta1 + 1;
            if (aposta1>10)aposta1=1;

            mostra_num();
            atualiza_aposta();          
            mostra_leitura_ac(ac_atual_3, 360);
            mostra_leitura_ac(ac_atual_2, 90);
            mostra_leitura_ac(ac_atual_1, 590);    
            rest(550);    
           } 

        if(key[KEY_T] && taanimando==0 && credito>0 && automatico==0 )
          {
          sound(notes[1]);
          sound(0);
          if (itabela==0) itabela =1;
          
          if (itabela==1)  
             {
             draw_sprite(screen, imagens[83].dat, 0,0 );
             itabela=2;
             }
          else
          if (itabela==2)           
             {
             draw_sprite(screen, imagens[84].dat, 0,0 );
             itabela=3;
             }
          else
          if (itabela==3)           
             {
             clear(screen); 
             draw_sprite(screen, imagens[85].dat, 0,0 );
             draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
             atualiza_slots();
             mostra_num();
             atualiza_credito();
             atualiza_aposta();             
             itabela=0;
             icon_tabela=0;
             mostra_leitura_ac(ac_atual_3, 360);
             mostra_leitura_ac(ac_atual_2, 90);
             mostra_leitura_ac(ac_atual_1, 590);    
             } 
          rest(550);  
        }   

        if(key[KEY_B]  && taanimando==0 && itaok==0) /* JOGAR */
          { 
            sound(notes[2]);
            rest(5);
            sound(notes[4]);
            sound(0);
            
           _pres_jogar=1;
          }

        if (!key[KEY_B] && _pres_jogar==1 && credito > 0)
           {
             sound(notes[3]);
             sound(0);
             Linhas_Ace();
             tempo=12;
             animacao=0;
             play_sample (sones[0].dat, 255, 128, 1000, 0);
             valor_b_abobora=0;
             _pres_jogar=0;
             pr_jog_p    = pr_jog_p + 1;
             pr_aposta_p = pr_aposta_p + (valor_linha * aposta1);
             grava_parametros_c();
             automatico=0;
             blefe_bonus=0;
             rest(100);
             inicia_jogar();  
          }


       if ( taanimando==0 && itabela==0  && credito > 0)
          {
           credita_s_tempo();    
           i_TLinha=0;
           if (animacao==4)
             {
              credita_s_tempo();    
              acquire_screen();
              credita_s_tempo();    
              if (valor_linha==1)
                {
                  credita_s_tempo();    
                  confere_amarelo(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                }  
              if (valor_linha==5)
                {
                  credita_s_tempo();    
                  confere_amarelo(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_amarelo(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_amarelo(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  credita_s_tempo();    
                }  
              if (valor_linha==9)
                {
                  credita_s_tempo();    
                  confere_amarelo(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_amarelo(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_amarelo(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_amarelo(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_amarelo(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_amarelo(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_amarelo(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_amarelo(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                  credita_s_tempo();    
                }
        
              if (valor_linha==15)
                {
                  credita_s_tempo();
                  confere_amarelo(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_amarelo(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_amarelo(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_amarelo(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_amarelo(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_amarelo(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_amarelo(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_amarelo(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                  confere_amarelo(10,2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
                  confere_amarelo(11,3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(12,1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(13,1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_amarelo(14,3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
                  credita_s_tempo();
                 }
        
              if (valor_linha==25)
                {
                  credita_s_tempo();    
                  confere_amarelo(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_amarelo(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_amarelo(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_amarelo(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_amarelo(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_amarelo(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_amarelo(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_amarelo(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                  confere_amarelo(10,2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
                  confere_amarelo(11,3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_amarelo(12,1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_amarelo(13,1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_amarelo(14,3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
                  confere_amarelo(15,1, 1, 1, 1, 2, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);              
                  confere_amarelo(16,3, 3, 3, 3, 2, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);              
                  confere_amarelo(17,2, 1, 1, 1, 1, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);              
                  confere_amarelo(18,2, 3, 3, 3, 3, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);              
                  confere_amarelo(19,3, 2, 2, 2, 1, xca[3][1], xca[2][2],xca[2][3], xca[2][4], xca[1][5]);                            

                  confere_amarelo2(20,1, 2, 3, xca[1][1], xca[2][1],xca[3][1]);
                  confere_amarelo2(21,1, 2, 3, xca[1][2], xca[2][2],xca[3][2]);
                  confere_amarelo2(22,1, 2, 3, xca[1][3], xca[2][3],xca[3][3]);
                  confere_amarelo2(23,1, 2, 3, xca[1][4], xca[2][4],xca[3][4]);
                  confere_amarelo2(24,1, 2, 3, xca[1][5], xca[2][5],xca[3][5]);
      
                  credita_s_tempo();    
                 }
              credita_s_tempo();    
              release_screen();
              credita_s_tempo();    
              confere_linha();
             } 
        
           if (animacao==8)
             {
              credita_s_tempo();
              acquire_screen();
              credita_s_tempo();
              i_TLinha=1;
              if (valor_linha==1)
                {
                  credita_s_tempo();    
                  confere_verde(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                }  
              if (valor_linha==5)
                {
                  credita_s_tempo();    
                  confere_verde(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_verde(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_verde(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                }  
              if (valor_linha==9)
                {
                  credita_s_tempo();
                  confere_verde(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_verde(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_verde(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_verde(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_verde(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_verde(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_verde(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_verde(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                }
        
              if (valor_linha==15)
                {
                  credita_s_tempo();
                  confere_verde(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_verde(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_verde(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_verde(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_verde(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_verde(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_verde(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_verde(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                  confere_verde(10, 2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
                  confere_verde(11, 3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(12, 1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(13, 1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_verde(14, 3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
                 }
        
              if (valor_linha==25)
                {
                  credita_s_tempo();
                  confere_verde(0, 2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
                  confere_verde(1, 1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(2, 3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(3, 1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
                  confere_verde(4, 3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
                  credita_s_tempo();    
                  confere_verde(5, 1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
                  confere_verde(6, 3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
                  confere_verde(7, 2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
                  confere_verde(8, 2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
                  confere_verde(9, 2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
                  credita_s_tempo();    
                  confere_verde(10, 2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
                  confere_verde(11, 3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
                  confere_verde(12, 1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
                  confere_verde(13, 1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
                  confere_verde(14, 3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
                  confere_verde(15, 1, 1, 1, 1, 2, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);              
                  credita_s_tempo();    
                  confere_verde(16, 3, 3, 3, 3, 2, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);              
                  confere_verde(17, 2, 1, 1, 1, 1, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);              
                  confere_verde(18, 2, 3, 3, 3, 3, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);              
                  confere_verde(19, 3, 2, 2, 2, 1, xca[3][1], xca[2][2],xca[2][3], xca[2][4], xca[1][5]);     
		  credita_s_tempo(); 
                  confere_verde2(20,1, 2, 3, xca[1][1], xca[2][1],xca[3][1]);
                  confere_verde2(21,1, 2, 3, xca[1][2], xca[2][2],xca[3][2]);
                  confere_verde2(22,1, 2, 3, xca[1][3], xca[2][3],xca[3][3]);
                  confere_verde2(23,1, 2, 3, xca[1][4], xca[2][4],xca[3][4]);
                  confere_verde2(24,1, 2, 3, xca[1][5], xca[2][5],xca[3][5]);
                       
                  credita_s_tempo();    
                 }
               credita_s_tempo();    
               release_screen();
               credita_s_tempo();    
               confere_linha();
               credita_s_tempo();    
             } 

          } 

         if (animacao>11) animacao=0;

         if(key[KEY_F]  && taanimando==0 && credito > 199 && itaok==0 && automatico==0 )  /* APOSTA MAXIMA*/
           { 
            sound(notes[6]);
            sound(0);
            __conta_bonus=rand()%6;
            __conta_jogadas=rand()%5;
            automatico=0;
            valor_linha = 25;
            aposta1=10;
            mostra_leitura_ac(ac_atual_3, 360);
            mostra_leitura_ac(ac_atual_2, 90);
            mostra_leitura_ac(ac_atual_1, 590);    
            atualiza_aposta(); 
            mostra_num();
            blefe_bonus=0;
            Linhas_Ace();
            inicia_jogar();          
            rest(200);

           }

         if(key[KEY_B]  && taanimando==1  && itaok==0)
           {
             taanimando=0;
             iparametros=0;
             draw_sprite(screen, imagens[50].dat, 52,87 );
             draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
             atualiza_slots();
             descredito=0;
             mostra_num();
             atualiza_aposta();               
             atualiza_credito();
             itabela=0;
             icon_tabela=0;              
             mostra_leitura_ac(ac_atual_3, 360);
             mostra_leitura_ac(ac_atual_2, 90);
             mostra_leitura_ac(ac_atual_1, 590);    
             rest(100);             
            }        

        if(key[KEY_V] && automatico==0 && itaok==0) /* AUTOMATICO*/
           {
            _pres_jogar=2;
           }
 
        if(!key[KEY_V] && automatico==0 && itaok==0 && _pres_jogar==2) /* AUTOMATICO*/
         {
           valor_b_abobora=0;
           _pres_jogar=0;        
           automatico=1;
           rest(150);
         }   
   
        if (automatico==1)
           {
            play_sample (sones[0].dat, 255, 128, 1000, 0);
            blefe_bonus=0;
            rest(100); 
            Linhas_Ace();
            inicia_jogar();          
            rest(600);
           }
     

         if(key[KEY_P] && automatico==0 ) /* LEITURA*/
           {
            sound(notes[2]);
            sound(0);
             _pres_jogar=0;
             menu_leitura();
           }
         

       if(key[KEY_R] && credito > 0  && itaok==0 && automatico==0 ) /* DESCREDITO*/
         {
          sound(notes[2]);
          sound(0);
          _pres_jogar=4;
         }
       
       if(!key[KEY_R] && credito > 0  && itaok==0 && automatico==0 && _pres_jogar==4 ) /* DESCREDITO*/
        {
          _pres_jogar=0;
          at_descredito();
          if(credito==0)_ani_s_credito=0;
        }   

       if (ta_c_credito==1 && !key[KEY_6] && !key[KEY_5] && !key[KEY_4] && !key[KEY_3] && !key[KEY_2] && !key[KEY_1]) bota_credito();



        if (credito==0 && iparametros==0)
            {              
              credita_s_tempo();    
              _val_pr_valor = 500;
              automatico=0;
              _val_pr_bonus = 23;  
              credita_s_tempo();
              _pres_jogar = 0;
              if (_ani_s_credito  < 132 ){ anima_sem_credito();   }

              if (_ani_s_credito == 132 ){ roda_roleta_anima();  }
              if (_ani_s_credito == 200 ){ roda_roleta_anima();  }
              if (_ani_s_credito == 260 ){ bonus_roleta_Anima();atualiza_slots(); }
              if (_ani_s_credito == 320 ){ roda_roleta_anima();  }
              if (_ani_s_credito == 380 ){ bonus_morando_anima();atualiza_slots();}
              if (_ani_s_credito == 440 ){ roda_roleta_anima();  }
              if (_ani_s_credito == 490 ){ bonus_abobora_anima();atualiza_slots();}
              if (_ani_s_credito == 570 ){ roda_roleta_anima();  }
              if (_ani_s_credito == 630 ){ bonus_sinuca_anima();atualiza_slots(); }
              if (_ani_s_credito == 680 ){ roda_roleta_anima();  }
    
              credita_s_tempo();                  
            }        
  }

}

void carrega_slots() {
int i, _i, SLOS_OK[10] ;

    SLOS_OK[0]=4; SLOS_OK[1]=3; SLOS_OK[2]=2;
    SLOS_OK[3]=0; SLOS_OK[4]=6; SLOS_OK[5]=1;    
    SLOS_OK[6]=9; SLOS_OK[7]=8; SLOS_OK[8]=7;
    SLOS_OK[9]=5;                                        
    
    BITMAP *bmp_cria_sub1;
    bmp_cria_sub1  = imagens[115].dat; /*SLOTS*/
    _i=0;
    for (i=0;i<10;i++)
        {
         SLOT_AIMA1[SLOS_OK[i]]= create_sub_bitmap(bmp_cria_sub1, _i, 0,   bmp_cria_sub1->w/10, bmp_cria_sub1->h/5);
         SLOT_AIMA2[SLOS_OK[i]]= create_sub_bitmap(bmp_cria_sub1, _i, 128, bmp_cria_sub1->w/10, bmp_cria_sub1->h/5);
         SLOT_CIMA[SLOS_OK[i]]=  create_sub_bitmap(bmp_cria_sub1, _i, 256, bmp_cria_sub1->w/10, bmp_cria_sub1->h/5);
         SLOT_MEIO[SLOS_OK[i]]=  create_sub_bitmap(bmp_cria_sub1, _i, 384, bmp_cria_sub1->w/10, bmp_cria_sub1->h/5);
         SLOT_BAIXO[SLOS_OK[i]]= create_sub_bitmap(bmp_cria_sub1, _i, 512, bmp_cria_sub1->w/10, bmp_cria_sub1->h/5);

         _i=_i+128;
        }

    bmp_cria_sub1  = imagens[23].dat; /*SLOTS GIROS*/
    _i=0;
    for (i=0;i<10;i++)
        {
         BMP_ROLOS[i]= create_sub_bitmap(bmp_cria_sub1, _i, 0, bmp_cria_sub1->w/10, bmp_cria_sub1->h/1);
         _i=_i+128;
        }

}

void mostra_slots(void)
{

    struct slots_machine *pp;   
    struct slots_machine x;
    fseek(ft, 11 * sizeof(int), 0);
    fread(&x, sizeof(struct slots_machine), 1, ft);
   
    slots_top[1]=93;   slots_top[2]=221;
    slots_top[3]=349;  slots_left[1]=57;
    slots_left[2]=198; slots_left[3]=339;
    slots_left[4]=479; slots_left[5]=617;        

    xca[1][1]= x.ca1; 
    xca[2][1]= x.cb1; 
    xca[3][1]= x.cc1; 

    xca[1][2]= x.ca2; 
    xca[2][2]= x.cb2; 
    xca[3][2]= x.cc2; 

    xca[1][3]= x.ca3; 
    xca[2][3]= x.cb3; 
    xca[3][3]= x.cc3; 

    xca[1][4]= x.ca4; 
    xca[2][4]= x.cb4; 
    xca[3][4]= x.cc4; 

    xca[1][5]= x.ca5;        
    xca[2][5]= x.cb5;            
    xca[3][5]= x.cc5;        

    int i=0;
    for (i=1;i<6;i++)
      {
       draw_sprite(screen, SLOT_CIMA[xca[1][i]], slots_left[i],slots_top[1] );
       draw_sprite(screen, SLOT_MEIO[xca[2][i]], slots_left[i],slots_top[2] );         	
       draw_sprite(screen, SLOT_BAIXO[xca[3][i]], slots_left[i],slots_top[3] ); 
      }
      
}

void Gera_slots_machine(struct slots_machine *p)
{
p->ca1 = xca[1][1]; 
p->cb1 = xca[2][1];
p->cc1 = xca[3][1];

p->ca2 = xca[1][2];
p->cb2 = xca[2][2];
p->cc2 = xca[3][2];

p->ca3 = xca[1][3];
p->cb3 = xca[2][3];
p->cc3 = xca[3][3];

p->ca4 = xca[1][4];
p->cb4 = xca[2][4];
p->cc4 = xca[3][4];

p->ca5 = xca[1][5];
p->cb5 = xca[2][5];
p->cc5 = xca[3][5];

}  

void carrega_numeros(void)
{   
  
   BITMAP *bmp;
   bmp  = imagens[101].dat;
   int oi, io;
   io = 0; 
   for (oi=0;oi<12;oi++)
    { 
       NUM_APOSTA[oi]   = create_sub_bitmap(bmp,   io,   0, bmp->w/43, bmp->h/20);
       NUM_BRANCO_P1[oi]= create_sub_bitmap(bmp,   io,  50, bmp->w/20, bmp->h/12);
       NUM_PRETO_B[oi]  = create_sub_bitmap(bmp,   io, 100, bmp->w/20, bmp->h/12);
       NUM_BRANCO_P[oi] = create_sub_bitmap(bmp,   io, 150, bmp->w/24, bmp->h/12);
       NUM_PAGO[oi]     = create_sub_bitmap(bmp,   io, 200, bmp->w/40, bmp->h/21);
       NUM_CINUCA[oi]   = create_sub_bitmap(bmp,   io, 250, bmp->w/12, bmp->h/7);
       NUM_CIMA[oi]     = create_sub_bitmap(bmp,   io, 300, bmp->w/24, bmp->h/14);
       io = io + 40;
    }     

   io = 0; 
   bmp  = imagens[56].dat;   
   for (oi=0;oi<10;oi++)
    { 
       NUM_ACUMULADO[oi]= create_sub_bitmap(bmp,   io, 0, bmp->w/11, bmp->h/1);
       io = io + 20;
    } 

    NUM_ACUMULADO[10]=imagens[99].dat;       
    bmp  = imagens[58].dat;
    NUM_AMARELO[0]= create_sub_bitmap(bmp,     1, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[1]= create_sub_bitmap(bmp,     15, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[2]= create_sub_bitmap(bmp,     30, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[3]= create_sub_bitmap(bmp,     45, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[4]= create_sub_bitmap(bmp,     61, 1, bmp->w/17, bmp->h/1);    
    NUM_AMARELO[5]= create_sub_bitmap(bmp,     78, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[6]= create_sub_bitmap(bmp,     95, 1, bmp->w/17, bmp->h/1);    
    NUM_AMARELO[7]= create_sub_bitmap(bmp,    112, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[8]= create_sub_bitmap(bmp,    127, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[9]= create_sub_bitmap(bmp,    145, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[10]= create_sub_bitmap(bmp,   160, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[11]= create_sub_bitmap(bmp,   175, 1, bmp->w/17, bmp->h/1);    
    NUM_AMARELO[12]= create_sub_bitmap(bmp,   190, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[13]= create_sub_bitmap(bmp,   220, 1, bmp->w/14, bmp->h/1);    
    NUM_AMARELO[14]= create_sub_bitmap(bmp,   240, 1, bmp->w/17, bmp->h/1);
    NUM_AMARELO[15]= create_sub_bitmap(bmp,   255, 1, bmp->w/17, bmp->h/1);

    bmp  = imagens[59].dat;
    NUM_AZUL[0]= create_sub_bitmap(bmp,     1, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[1]= create_sub_bitmap(bmp,     15, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[2]= create_sub_bitmap(bmp,     30, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[3]= create_sub_bitmap(bmp,     45, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[4]= create_sub_bitmap(bmp,     61, 1, bmp->w/17, bmp->h/1);    
    NUM_AZUL[5]= create_sub_bitmap(bmp,     78, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[6]= create_sub_bitmap(bmp,     95, 1, bmp->w/17, bmp->h/1);    
    NUM_AZUL[7]= create_sub_bitmap(bmp,    112, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[8]= create_sub_bitmap(bmp,    127, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[9]= create_sub_bitmap(bmp,    145, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[10]= create_sub_bitmap(bmp,   160, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[11]= create_sub_bitmap(bmp,   175, 1, bmp->w/17, bmp->h/1);    
    NUM_AZUL[12]= create_sub_bitmap(bmp,   190, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[13]= create_sub_bitmap(bmp,   220, 1, bmp->w/14, bmp->h/1);    
    NUM_AZUL[14]= create_sub_bitmap(bmp,   240, 1, bmp->w/17, bmp->h/1);
    NUM_AZUL[15]= create_sub_bitmap(bmp,   255, 1, bmp->w/17, bmp->h/1);

    bmp  = imagens[60].dat;
    NUM_VERDE[0]=  create_sub_bitmap(bmp, 0, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[1]=  create_sub_bitmap(bmp, 44, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[2]=  create_sub_bitmap(bmp, 88, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[3]=  create_sub_bitmap(bmp, 134, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[4]=  create_sub_bitmap(bmp, 178, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[5]=  create_sub_bitmap(bmp, 224, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[6]=  create_sub_bitmap(bmp, 268, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[7]=  create_sub_bitmap(bmp, 314, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[8]=  create_sub_bitmap(bmp, 358, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[9]=  create_sub_bitmap(bmp, 404, 0, bmp->w/12, bmp->h/1);
    NUM_VERDE[10]= create_sub_bitmap(bmp, 450, 0, bmp->w/12, bmp->h/1);                                    
    NUM_VERDE[11]= create_sub_bitmap(bmp, 494, 0, bmp->w/12, bmp->h/1);                                    


}   

void atualiza_slots(void)
{
    draw_sprite(screen, imagens[45].dat, 186,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 326,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 466,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 606,90 );  /*  PRIMEIRA COLUNA */       	
    int i;
    for (i=1;i<6;i++)
      {
       draw_sprite(screen, SLOT_CIMA[xca[1][i]], slots_left[i],slots_top[1] );
       draw_sprite(screen, SLOT_MEIO[xca[2][i]], slots_left[i],slots_top[2] );         	
       draw_sprite(screen, SLOT_BAIXO[xca[3][i]], slots_left[i],slots_top[3] ); 
      }
     
}

void roda_roleta(void) 
{
/*    srand(time(NULL));*/
    int perc=0, sra=0, cont, slots, saldo=0, conta_slots_a;

    cont_jog++;

    if(cont_jog < 18 && aposta1==1 && valor_linha==25)_pganhou[cont_jog] = cont_jog;


    if(cont_jog == 18 && aposta1==2 && valor_linha==25)_pganhou[cont_jog] = 18;
    if(cont_jog == 19 && aposta1==3 && valor_linha==25)_pganhou[cont_jog] = 19;
    if(cont_jog == 20 && aposta1==4 && valor_linha==25)_pganhou[cont_jog] = 20;
    if(cont_jog == 21 && aposta1==2 && valor_linha==25)_pganhou[cont_jog] = 21;        
    if(cont_jog == 22 && aposta1==2 && valor_linha==15)_pganhou[cont_jog] = 22;
    if(cont_jog == 23 && aposta1==3 && valor_linha==15)_pganhou[cont_jog] = 23;
    if(cont_jog == 24 && aposta1==2 && valor_linha==25)_pganhou[cont_jog] = 24;
            
    xca[0][0]= 1; 
    xca[0][1]= 1; 
    xca[0][2]= 1; 
    xca[0][3]= 1; 
    xca[0][5]= 1; 
            
    saldo = ((pr_entrada_p - pr_saida_p) - credito);

    if(perc_ret==0)
       {
        perc = (((pr_entrada_p - credito)*50)/100);
       }
   else    
    if(perc_ret==1)
       {
        perc = (((pr_entrada_p - credito)*40)/100);
       }
   else    
    if(perc_ret==2)
       {
        perc = (((pr_entrada_p - credito)*30)/100);
       }
   else    
    if(perc_ret==3)
       {
        perc = (((pr_entrada_p - credito)*20)/100);
       }
   else    
    if(perc_ret==4)
       {
        perc = (((pr_entrada_p - credito)*10)/100);
       }
       
    
    conta_slots_a = rand() % 3900;  
    struct slots_machine x;

    fseek(ft, conta_slots_a * sizeof(struct slots_machine), 0);
    fread(&x, sizeof(struct slots_machine), 1, ft);

    slots=0;
    if(saldo<=perc)
       {            
         sra = 0;
         sra = rand()%52;    
         if(sra>33 && sra<45 && __conta_bonus > 41 && saldo > (4000*aposta1))
            {
             conta_slots_a = rand() % 3;
             if(conta_slots_a==0)conta_slots_a =        rand() % 780;
             if(conta_slots_a==1)conta_slots_a =  800 + rand() % 780;
             if(conta_slots_a==2)conta_slots_a = 1600 + rand() % 780;
             if(conta_slots_a==3)conta_slots_a = 2400 + rand() % 780;

             slots=1;
              fseek(fBonus, conta_slots_a * sizeof(struct slots_machine), 0);
              fread(&x, sizeof(struct slots_machine), 1, fBonus);   
            }
         else
         if(sra<23 && __conta_jogadas > 9)
            {
              conta_slots_a = rand() % 2900;  
              if(conta_slots_a <= 0)conta_slots_a=2;
              slots=1;
              __conta_jogadas=rand()%2;
              fseek(fPag, conta_slots_a * sizeof(struct slots_machine), 0);
              fread(&x, sizeof(struct slots_machine), 1, fPag);                
            }
         if(slots==0)
           {
             fseek(ft, conta_slots_a * sizeof(struct slots_machine), 0);
             fread(&x, sizeof(struct slots_machine), 1, ft);       
            }
       }
    if(saldo>perc)
      {
       sra = 0;
       sra = rand()%52;    
       if(sra>33 && sra<41 && __conta_bonus > _val_pr_bonus && (saldo-perc)>(1100*aposta1))
          {
            conta_slots_a = rand() % 4;
            if(conta_slots_a==0)conta_slots_a =        rand() % 780;
            if(conta_slots_a==1)conta_slots_a =  810 + rand() % 780;
            if(conta_slots_a==2)conta_slots_a = 1610 + rand() % 780;
            if(conta_slots_a==3)conta_slots_a = 2410 + rand() % 780;
            slots=1;
            fseek(fBonus, conta_slots_a * sizeof(struct slots_machine), 0);
            fread(&x, sizeof(struct slots_machine), 1, fBonus);   
          }
       else   
       if(sra>41 && valor_comido > (_val_pr_valor * aposta1) && (saldo-perc)>(1800 * aposta1))
          {
            slots=1;
            __conta_bonus=0;
            fseek(fAlt, conta_slots_a * sizeof(struct slots_machine), 0);
            fread(&x, sizeof(struct slots_machine), 1, fAlt);                
            valor_comido=0;
            grava_parametros_c();
          }
       else
       if(sra<26 && __conta_jogadas > 7)              
          {
            slots=1;

            if((saldo - perc) > (9000 * aposta1) && valor_com1 > (10000 * aposta1))
              {
               conta_slots_a = 3000 + rand() % 620;
               __conta_jogadas=rand()%3;
               fseek(fPag, conta_slots_a * sizeof(struct slots_machine), 0);
               fread(&x, sizeof(struct slots_machine), 1, fPag);
               valor_com1 = 0;
              } 
            else  
            if((saldo - perc)<(9001 * aposta1))
              {
               conta_slots_a = rand() % 2900;
               if(conta_slots_a<=0)conta_slots_a=2;
               __conta_jogadas=rand()%3;
               fseek(fPag, conta_slots_a * sizeof(struct slots_machine), 0);
               fread(&x, sizeof(struct slots_machine), 1, fPag);                
              } 
          }
       else   
       if(slots==0)
         {
         fseek(ft, conta_slots_a * sizeof(struct slots_machine), 0);
         fread(&x, sizeof(struct slots_machine), 1, ft);       
          }
      }    

    if (valor_linha == 25 && aposta1 > 1)
       {
         sra = 0;
         sra = rand()%52;    
         if(sald_t_acum > (30000) && (saldo-perc)>(32000*aposta1))
           {
             fseek(fAc1, conta_slots_a * sizeof(struct slots_machine), 0);
             fread(&x, sizeof(struct slots_machine), 1, fAc1);
           }

         if(sra>33  && sra < 52 && sald_s_acum > ac_atual_1 && (saldo-perc)>(ac_atual_1*aposta1) && cai_bonus > 0 )
           {
             conta_slots_a = rand() % 50;  
             fseek(fAc, conta_slots_a * sizeof(struct slots_machine), 0);
             fread(&x, sizeof(struct slots_machine), 1, fAc);
          }  
       }

   slots=1;
   if(cont_jog == 24)
     {
       for(cont=0;cont<25;cont++)
          {
           if (jog_cert[cont] == _pganhou[cont])slots++;    
          }
     }
          
   if(slots==26)
     {
       if(saldo > 30000)
         {        
           fseek(fAc1, conta_slots_a * sizeof(struct slots_machine), 0);
           fread(&x, sizeof(struct slots_machine), 1, fAc1);
         }
     }   

    xca[1][1]= x.ca1;
    xca[2][1]= x.cb1; 
    xca[3][1]= x.cc1; 
 
    xca[1][2]= x.ca2; 
    xca[2][2]= x.cb2; 
    xca[3][2]= x.cc2; 

    xca[1][3]= x.ca3; 
    xca[2][3]= x.cb3; 
    xca[3][3]= x.cc3; 

    xca[1][4]= x.ca4; 
    xca[2][4]= x.cb4; 
    xca[3][4]= x.cc4; 

    xca[1][5]= x.ca5;        
    xca[2][5]= x.cb5;            
    xca[3][5]= x.cc5;        

    for (cont=1;cont<4;cont++)
        {
         for(slots=1;slots<6;slots++)
             {
              if(xca[cont][slots]<0)  xca[cont][slots]=1;
              if(xca[cont][slots]>10) xca[cont][slots]=10;
             }              
        }

    draw_sprite(screen, imagens[45].dat, 186,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 326,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 466,90 );  /*  PRIMEIRA COLUNA */       	
    draw_sprite(screen, imagens[45].dat, 606,90 );  /*  PRIMEIRA COLUNA */  


    if (automatico==1)
      {
       draw_sprite(screen, BMP_MSN[2], 300,65 );/*  tela automatico*/
      }
    else   
    if (automatico==0)
      {
       draw_sprite(screen, BMP_MSN[1], 300,65 );/*  tela jogar*/
      }
    
       conta_morango=0; 
       _Slots=1;
       slots=0;
/*       set_volume(80,0);*/
       while(_Slots < 50) {

        play_sample (sones[30].dat, 255, 128, 1000, 0);  
        sound(notes[1]);
        sound(0);
        
        if (_Slots < 10) {
    		draw_sprite(screen, BMP_ROLOS[slots], 58,92 );

        }
        else
        {
        draw_sprite(screen, SLOT_CIMA[xca[1][1]],  slots_left[1],slots_top[1] );
        draw_sprite(screen, SLOT_MEIO[xca[2][1]],  slots_left[1],slots_top[2] );         	
        draw_sprite(screen, SLOT_BAIXO[xca[3][1]], slots_left[1],slots_top[3] ); 
        }  
        if (_Slots < 20) {
        draw_sprite(screen, BMP_ROLOS[slots], 198,92 );
        }
        else
        {
        draw_sprite(screen, SLOT_CIMA[xca[1][2]],  slots_left[2],slots_top[1] );
        draw_sprite(screen, SLOT_MEIO[xca[2][2]],  slots_left[2],slots_top[2] );         	
        draw_sprite(screen, SLOT_BAIXO[xca[3][2]], slots_left[2],slots_top[3] ); 
        }

        if (_Slots < 30) {
        draw_sprite(screen, BMP_ROLOS[slots], 338,92 );
        }
        else
        {
        draw_sprite(screen, SLOT_CIMA[xca[1][3]],  slots_left[3],slots_top[1] );
        draw_sprite(screen, SLOT_MEIO[xca[2][3]],  slots_left[3],slots_top[2] );         	
        draw_sprite(screen, SLOT_BAIXO[xca[3][3]], slots_left[3],slots_top[3] ); 
        }
        if (_Slots < 40) {
        draw_sprite(screen, BMP_ROLOS[slots], 478,92 );
        }
        else
        {
        draw_sprite(screen, SLOT_CIMA[xca[1][4]],  slots_left[4],slots_top[1] );
        draw_sprite(screen, SLOT_MEIO[xca[2][4]],  slots_left[4],slots_top[2] );         	
        draw_sprite(screen, SLOT_BAIXO[xca[3][4]], slots_left[4],slots_top[3] ); 
        }

        if (_Slots < 49) {
        draw_sprite(screen, BMP_ROLOS[slots], 618,92 );
        }
        else
        {
        draw_sprite(screen, SLOT_CIMA[xca[1][5]],  slots_left[5],slots_top[1] );
        draw_sprite(screen, SLOT_MEIO[xca[2][5]],  slots_left[5],slots_top[2] );         	
        draw_sprite(screen, SLOT_BAIXO[xca[3][5]], slots_left[5],slots_top[3] ); 
        }
         
		rest(10);              
        if (key[KEY_B]) conta_morango=1;
           
        
        if (!key[KEY_B] && conta_morango==1)
           { 
             if (tempo>20)
                {
                 automatico=0;
                 _Slots=51;
                 atualiza_slots(); 
                 conta_morango=0;
                } 
           }           
          

        if (key[KEY_V]) conta_morango=2;

        if (!key[KEY_V] && conta_morango==2)
           { 
             automatico=0; 
             conta_morango=0;
           }           
            
        slots ++;
        if (slots > 9) slots=0; 

       }

    play_sample (sones[28].dat, 255, 128, 1000, 0);
    draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
 }


void confere_premio(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5)
{

 int iganhou=0, iebonus=0, taz=0;

   if ( (a1==a2) && (a2==a3) && (a3==a4) && (a4==a5) && taz==0)
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       taz=1;
       premio = premio + PREMIOS[a1][2] * aposta1;

       if (a1==9) GANHOU_ACUMULADO=1;
       if (a1==8) GANHOU_ACUMULADO=3;
         
       if (BONUS[a1][2]>0)
          { 
            blefe_bonus  = BONUS[a1][2];
            valor_b_abobora=valor_b_abobora+3;
            iebonus=1;
          }
      }
   else   
   if ( (a1==a2) && (a2==a3) && (a3==a4) && (a1!=a5) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][1] * aposta1;

       if (a1==9) GANHOU_ACUMULADO=2;

       if (BONUS[a1][1]>0)
          {  
            blefe_bonus  = BONUS[a1][1];
            valor_b_abobora=valor_b_abobora+2;
            iebonus=1;
          }
      }
   else   
   if ( (a1==a2) && (a2==a3) && (a3==a5) && (a1!=a4) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);
       iganhou=1;
       premio = premio + PREMIOS[a1][1] * aposta1;
       if (a1==9) GANHOU_ACUMULADO=2;
       if (BONUS[a1][1]>0)
          {  
            blefe_bonus  = BONUS[a1][1];
            valor_b_abobora=valor_b_abobora+2;
            iebonus=1;
          }
      }
   else   
   if ( (a1==a3) && (a3==a4) && (a4==a5) && (a1!=a2) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][1] * aposta1;
       if (a1==9) GANHOU_ACUMULADO=2;

       if (BONUS[a1][1]>0)
          {  
           blefe_bonus  = BONUS[a1][1];
           valor_b_abobora=valor_b_abobora+2;
           iebonus=1;
          }
      }
   else   
   if ( (a2==a3) && (a3==a4) && (a4==a5) && (a2!=a1) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a2][1] * aposta1;
       if (BONUS[a2][1]>0)
          {  
            blefe_bonus  = BONUS[a2][1];
            valor_b_abobora=valor_b_abobora+2;
            iebonus=1;
          }

       if (a2==9) GANHOU_ACUMULADO=2;

      }
   else
   if ( (a1==a2) && (a2==a4) && (a4==a5) && (a2!=a3) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][1] * aposta1;
       if (BONUS[a1][1]>0)
          { 
           blefe_bonus  = BONUS[a1][1];
           valor_b_abobora=valor_b_abobora+2;          
           iebonus=1;
          }
       if (a1==9) GANHOU_ACUMULADO=2;

      }
   else
   if ( (a1==a2) && (a2==a3) && (a1!=a4) && (a1!=a5) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {
           blefe_bonus  = BONUS[a1][0];
           valor_b_abobora=valor_b_abobora+1;
           iebonus=1;
          }
      }
   else
   if ((a3==a4) && (a4==a5) && (a3!=a1) && (a3!=a2) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a3][0] * aposta1;

       if (BONUS[a3][0]>0)
         {  
           blefe_bonus  = BONUS[a3][0];
           valor_b_abobora=valor_b_abobora+1;
           iebonus=1;
         }
      }
   else
   if ( (a1==a2) && (a2==a4) && (a1!=a3) && (a1!=a5) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {  
            blefe_bonus  = BONUS[a1][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          }
      }
   else
   if ( (a1==a3) && (a3==a4) && (a1!=a5) && (a1!=a2) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {
           blefe_bonus  = BONUS[a1][0];
           valor_b_abobora=valor_b_abobora+1;
           iebonus=1;
          }
      }
   else
   if ( (a2==a4) && (a4==a5) && (a2!=a3) && (a2!=a1) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a2][0] * aposta1;

       if (BONUS[a2][0]>0)
          {  
            blefe_bonus  = BONUS[a2][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          }
      }
   else
   if ( (a1==a3) && (a3==a5)  && (a1!=a2) && (a1!=a4)&& taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {  
            blefe_bonus  = BONUS[a1][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          }
      }
   else
   if ( (a1==a2) && (a2==a5) && (a1!=a3) && (a1!=a4) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {  
            blefe_bonus  = BONUS[a1][0];
            valor_b_abobora=valor_b_abobora+1;          
            iebonus=1;
          }
      }         
   else     
   if ( (a2==a3) && (a3==a4) && (a2!=a1) && (a2!=a5) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       iganhou=1;
       premio = premio + PREMIOS[a2][0] * aposta1;

       if (BONUS[a2][0]>0)
          {  
            blefe_bonus  = BONUS[a2][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          }
      }         
   else
   if ( (a2==a3) && (a3==a5) && (a2!=a1) && (a2!=a4) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a2][0] * aposta1;

       if (BONUS[a2][0]>0)
          {  
            blefe_bonus  = BONUS[a2][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
           }
      }
   else
   if ( (a1==a4) && (a4==a5) && (a1!=a2) && (a1!=a3) && taz==0)
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
       iganhou=1;
       premio = premio + PREMIOS[a1][0] * aposta1;

       if (BONUS[a1][0]>0)
          {  
            blefe_bonus  = BONUS[a1][0];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   int i;
   if (iganhou==1)
     {
       marca_linhas[(_linha)] = 1;
       confere_linha();       
       stop_sample (sones[30].dat);     
       stop_sample (sones[28].dat);           
       atualiza_premio();
       if (iebonus==0)play_sample (sones[40].dat, 255, 128, 1000, 0);
       if (iebonus > 0) play_sample (sones[39].dat, 255, 128, 1000, 0);
       rest(600);
     }  

}  

void confere_premio2(int _linha, int col1, int col2, int col3, int b1, int b2, int b3)
{

 int iganhou=0, iebonus=0, taz=0;

   if ( (b1==b2) && (b2==b3) && (_linha==20))
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][1]], slots_left[1],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][1]], slots_left[1],slots_top[col3]);                         
       iganhou=1;
       premio = premio + PREMIOS[b1][3] * aposta1;
       if (BONUS[b1][3]>0)
          {  
            blefe_bonus  = BONUS[b1][3];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   if ( (b1==b2) && (b2==b3) && (_linha==21))
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][2]], slots_left[2],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][2]], slots_left[2],slots_top[col3]);                   
       iganhou=1;
       premio = premio + PREMIOS[b1][3] * aposta1;
       if (BONUS[b1][3]>0)
          {  
            blefe_bonus  = BONUS[b1][3];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   if ( (b1==b2) && (b2==b3) && (_linha==22))
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][3]], slots_left[3],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][3]], slots_left[3],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);           
       iganhou=1;
       premio = premio + PREMIOS[b1][3] * aposta1;
       if (BONUS[b1][3]>0)
          {  
            blefe_bonus  = BONUS[b1][3];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   if ( (b1==b2) && (b2==b3) && (_linha==23))
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][4]], slots_left[4],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][4]], slots_left[4],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][4]], slots_left[4],slots_top[col3]);                 
       iganhou=1;
       premio = premio + PREMIOS[b1][3] * aposta1;
       if (BONUS[b1][3]>0)
          {  
            blefe_bonus  = BONUS[b1][3];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   if ( (b1==b2) && (b2==b3) && (_linha==24))
      {
       taz=1;
       draw_sprite(screen, SLOT_AIMA1[xca[col1][5]], slots_left[5],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][5]], slots_left[5],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][5]], slots_left[5],slots_top[col3]);                
       iganhou=1;
       premio = premio + PREMIOS[b1][3] * aposta1;
       if (BONUS[b1][3]>0)
          {  
            blefe_bonus  = BONUS[b1][3];
            valor_b_abobora=valor_b_abobora+1;
            iebonus=1;
          } 
      }

   int i;
   if (iganhou==1)
     {
       marca_linhas[(_linha)] = 1;
       confere_linha();       
       stop_sample (sones[30].dat);     
       stop_sample (sones[28].dat);           
       atualiza_premio();
       if (iebonus==0)play_sample (sones[40].dat, 255, 128, 1000, 0);
       if (iebonus > 0) play_sample (sones[39].dat, 255, 128, 1000, 0);
       rest(600);
     }  

}
void confere_amarelo(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5)
{   
   if ( (a1==a2) && (a2==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else   
   if ( (a1==a2) && (a2==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else   
   if ( (a1==a2) && (a2==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);
      }
   else   
   if ( (a1==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else   
   if ( (a1==a2) && (a2==a3))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
      }
   else
   if ( (a2==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ((a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a2) && (a2==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a2) && (a2==a4))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else
   if ( (a1==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else
   if ( (a2==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a2) && (a2==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }         
   else
   if ( (a2==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }         
   else
   if ( (a2==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }         
   else
   if ( (a1==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }         

}
 
void confere_amarelo2(int _linha, int col1, int col2, int col3,int a1, int a2, int a3)
{ 
   if ( (a1==a2) && (a2==a3) && (_linha==20))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][1]], slots_left[1],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][1]], slots_left[1],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==21))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][2]], slots_left[2],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][2]], slots_left[2],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==22))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][3]], slots_left[3],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][3]], slots_left[3],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==23))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][4]], slots_left[4],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][4]], slots_left[4],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][4]], slots_left[4],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==24))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][5]], slots_left[5],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][5]], slots_left[5],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][5]], slots_left[5],slots_top[col3]);              
      }
}

void confere_verde(int _linha, int col1, int col2, int col3, int col4, int col5, int a1, int a2, int a3, int a4, int a5)
{
   if ( (a1==a2) && (a2==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else   

   if ( (a1==a2) && (a2==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else   
   if ( (a1==a2) && (a2==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);
      }
   else   
   if ( (a1==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else   
   if ( (a1==a2) && (a2==a3))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
      }
   else
   if ( (a2==a3) && (a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ((a3==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a2) && (a2==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a2) && (a2==a4))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else
   if ( (a1==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }
   else
   if ( (a2==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else
   if ( (a1==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }
   else   
   if ( (a1==a2) && (a2==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }         
   else
   if ( (a2==a3) && (a3==a4))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
      }         
   else
   if ( (a2==a3) && (a3==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col3][3]], slots_left[3],slots_top[col3]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }         
   else
   if ( (a1==a4) && (a4==a5))
      {
       draw_sprite(screen, SLOT_AIMA2[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col4][4]], slots_left[4],slots_top[col4]);              
       draw_sprite(screen, SLOT_AIMA2[xca[col5][5]], slots_left[5],slots_top[col5]);              
      }          

} 

void confere_verde2(int _linha, int col1, int col2, int col3,int a1, int a2, int a3)
{ 
   if ( (a1==a2) && (a2==a3) && (_linha==20))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][1]], slots_left[1],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][1]], slots_left[1],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][1]], slots_left[1],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==21))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][2]], slots_left[2],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][2]], slots_left[2],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][2]], slots_left[2],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==22))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][3]], slots_left[3],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][3]], slots_left[3],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][3]], slots_left[3],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==23))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][4]], slots_left[4],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][4]], slots_left[4],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][4]], slots_left[4],slots_top[col3]);              
      }

   if ( (a1==a2) && (a2==a3) && (_linha==24))
      {
       draw_sprite(screen, SLOT_AIMA1[xca[col1][5]], slots_left[5],slots_top[col1]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col2][5]], slots_left[5],slots_top[col2]);              
       draw_sprite(screen, SLOT_AIMA1[xca[col3][5]], slots_left[5],slots_top[col3]);              
      }
}

void confere_linha(void)
{
   if (marca_linhas[0]== 1)
      cria_linha1();

   if (marca_linhas[1]== 1)
      cria_linha2();
      
   if (marca_linhas[2]== 1)
      cria_linha3();
      
   if (marca_linhas[3]== 1)
      cria_linha4();
      
   if (marca_linhas[4]== 1)
      cria_linha5();
      
   if (marca_linhas[5]== 1)
      cria_linha6();
      
   if (marca_linhas[6]== 1)
      cria_linha7();
      
   if (marca_linhas[7]== 1)
      cria_linha8();
      
   if (marca_linhas[8]== 1)
      cria_linha9();
      
   if (marca_linhas[9]== 1)
      cria_linha10();
      
   if (marca_linhas[10]== 1)
      cria_linha11();
      
   if (marca_linhas[11]== 1)
      cria_linha12();
      
   if (marca_linhas[12]== 1)
      cria_linha13();
      
   if (marca_linhas[13]== 1)
      cria_linha14();
      
   if (marca_linhas[14]== 1)
      cria_linha15();
      
   if (marca_linhas[15]== 1)
      cria_linha16();
      
   if (marca_linhas[16]== 1)
      cria_linha17();
      
   if (marca_linhas[17]== 1)
      cria_linha18();
      
   if (marca_linhas[18]== 1)
      cria_linha19();

   if (marca_linhas[19]== 1)
      cria_linha20();

   if (marca_linhas[20]== 1)  
      cria_linha21();

   if (marca_linhas[21]== 1)
      cria_linha22();

   if (marca_linhas[22]== 1)
      cria_linha23();

   if (marca_linhas[23]== 1)
      cria_linha24();

   if (marca_linhas[24]== 1)
      cria_linha25();
}


void inicia_jogar(void)
{
   i_TLinha=0;
   if (credito < (valor_linha*aposta1))
      {
      draw_sprite(screen, BMP_MSN[3], 300,65 );/*  falta credito*/
      automatico=0;
      _ani_s_credito=0;
      }
   else                 
   if (credito == 0)
    {
      draw_sprite(screen, BMP_MSN[3], 300,65 );/*  falta credito*/
      _ani_s_credito=0;
      automatico=0;
    }
   else
    {  
     if (itabela>0)
       {
         clear(screen); 
         draw_sprite(screen, imagens[85].dat, 0,0 );  /*tela*/
         draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
         atualiza_slots();
         mostra_num();
         atualiza_credito();
         atualiza_aposta();
         itabela=0;
         icon_tabela=0;
         mostra_leitura_ac(ac_atual_3, 360);
         mostra_leitura_ac(ac_atual_2, 90);
         mostra_leitura_ac(ac_atual_1, 590);    
       }  
      ilinha=0;

                  
      int is;
      for (is=0;is<20;is++)
        {
         marca_linhas[is] = 0;
         marca_linhas[20] = 0;
         marca_linhas[21] = 0;
         marca_linhas[22] = 0;
         marca_linhas[23] = 0;
         marca_linhas[24] = 0;
        }  

      credito = credito - (valor_linha*aposta1);
      atualiza_credito();
      grava_valor_c();

      pago=0; 
      draw_sprite(screen, imagens[46].dat, 440,22 );  /*limpa premio*/
      roda_roleta(); 
            
      if (credito==0)
         {
          credito=0;
          valor_linha=1;
          aposta1=1;
          draw_sprite(screen, imagens[46].dat, 440,22 );/*limpa premio*/
          draw_sprite(screen, imagens[46].dat, 675,22 );  /*aposta*/
          draw_sprite(screen, imagens[46].dat, 160,22 );  /*credito*/
          draw_sprite(screen, imagens[46].dat, 190,22 );  /*credito*/
          mostra_num(); 
        }
      premio=0;
      valor_b_abobora=0;
      confere_linha;
      GANHOU_ACUMULADO=0;
      if (valor_linha==1)
       {              
        confere_premio(0,  2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
       }
      else  
      if (valor_linha==5)
        {
         confere_premio(0,  2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
         confere_premio(1,  1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
         confere_premio(2,  3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
         confere_premio(3,  1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
         confere_premio(4,  3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
       } 
      else 
      if (valor_linha==9)
        {
          confere_premio(0,  2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
          confere_premio(1,  1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
          confere_premio(2,  3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
          confere_premio(3,  1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
          confere_premio(4,  3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
          confere_premio(5,  1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
          confere_premio(6,  3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
          confere_premio(7,  2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
          confere_premio(8,  2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
          confere_premio(9,  2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
        }
      else  
      if (valor_linha==15)
        {

          confere_premio(0,  2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
          confere_premio(1,  1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
          confere_premio(2,  3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
          confere_premio(3,  1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
          confere_premio(4,  3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
          confere_premio(5,  1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
          confere_premio(6,  3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
          confere_premio(7,  2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
          confere_premio(8,  2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
          confere_premio(9,  2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
          confere_premio(10, 2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
          confere_premio(11, 3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
          confere_premio(12, 1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
          confere_premio(13, 1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
          confere_premio(14, 3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
        }
      else  
      if (valor_linha==25)
        {
          confere_premio(0,  2, 2, 2, 2, 2, xca[2][1], xca[2][2],xca[2][3], xca[2][4], xca[2][5]);
          confere_premio(1,  1, 1, 1, 1, 1, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);
          confere_premio(2,  3, 3, 3, 3, 3, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);
          confere_premio(3,  1, 2, 3, 2, 1, xca[1][1], xca[2][2],xca[3][3], xca[2][4], xca[1][5]);
          confere_premio(4,  3, 2, 1, 2, 3, xca[3][1], xca[2][2],xca[1][3], xca[2][4], xca[3][5]);
          confere_premio(5,  1, 1, 2, 3, 3, xca[1][1], xca[1][2],xca[2][3], xca[3][4], xca[3][5]);
          confere_premio(6,  3, 3, 2, 1, 1, xca[3][1], xca[3][2],xca[2][3], xca[1][4], xca[1][5]);
          confere_premio(7,  2, 3, 3, 3, 2, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);
          confere_premio(8,  2, 1, 1, 1, 2, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);
          confere_premio(9,  2, 1, 2, 3, 2, xca[2][1], xca[1][2],xca[2][3], xca[3][4], xca[2][5]);
          confere_premio(10, 2, 3, 2, 1, 2, xca[2][1], xca[3][2],xca[2][3], xca[1][4], xca[2][5]);
          confere_premio(11, 3, 2, 1, 1, 1, xca[3][1], xca[2][2],xca[1][3], xca[1][4], xca[1][5]);
          confere_premio(12, 1, 2, 3, 3, 3, xca[1][1], xca[2][2],xca[3][3], xca[3][4], xca[3][5]);
          confere_premio(13, 1, 1, 1, 2, 3, xca[1][1], xca[1][2],xca[1][3], xca[2][4], xca[3][5]);
          confere_premio(14, 3, 3, 3, 2, 1, xca[3][1], xca[3][2],xca[3][3], xca[2][4], xca[1][5]);              
          confere_premio(15, 1, 1, 1, 1, 2, xca[1][1], xca[1][2],xca[1][3], xca[1][4], xca[2][5]);              
          confere_premio(16, 3, 3, 3, 3, 2, xca[3][1], xca[3][2],xca[3][3], xca[3][4], xca[2][5]);              
          confere_premio(17, 2, 1, 1, 1, 1, xca[2][1], xca[1][2],xca[1][3], xca[1][4], xca[1][5]);              
          confere_premio(18, 2, 3, 3, 3, 3, xca[2][1], xca[3][2],xca[3][3], xca[3][4], xca[3][5]);              
          confere_premio(19, 3, 2, 2, 2, 1, xca[3][1], xca[2][2],xca[2][3], xca[2][4], xca[1][5]); 
	  confere_premio2(20,1, 2, 3, xca[1][1], xca[2][1],xca[3][1]);
          confere_premio2(21,1, 2, 3, xca[1][2], xca[2][2],xca[3][2]);
          confere_premio2(22,1, 2, 3, xca[1][3], xca[2][3],xca[3][3]);
          confere_premio2(23,1, 2, 3, xca[1][4], xca[2][4],xca[3][4]);
          confere_premio2(24,1, 2, 3, xca[1][5], xca[2][5],xca[3][5]);                           

         }

       if (premio==0)
          {
           if(valor_linha==25)
             {
               __conta_jogadas++;
               valor_comido = valor_comido + (valor_linha * aposta1);
               valor_com1   = valor_com1   + (valor_linha * aposta1);
               sald_t_acum  = sald_t_acum  + (valor_linha * aposta1)/2;
               sald_s_acum  = sald_s_acum  + (valor_linha * aposta1)/(ac_perc_1);
             }  
          } 

           if(valor_linha==25)
             {
               if (blefe_bonus==0) __conta_bonus++;
               ac_jogadas++;
             }  

       grava_parametros_c();

       if (vez_acumulado==0)
         {

          if (ac_atual_2 < ac_max_2)
            {
             ac_atual_2=(((valor_linha*aposta1)*ac_perc_1)/20)+ac_atual_2;
             mostra_leitura_ac(ac_atual_2, 90);
             grava_parametros_c();
            } 

           vez_acumulado=1;
         }
      else
       if (vez_acumulado==1)
        {
          if (ac_atual_1 < ac_max_1)
            {
             ac_atual_1=(((valor_linha*aposta1)*ac_perc_1)/20)+ac_atual_1;
             mostra_leitura_ac(ac_atual_1, 590);
             grava_parametros_c();
           }  
          vez_acumulado=2;
        }
      else
       if (vez_acumulado==2)
        {
          if (ac_atual_3 < ac_max_3)
            {
             ac_atual_3=(((valor_linha*aposta1)*ac_perc_1)/20)+ac_atual_3;
             mostra_leitura_ac(ac_atual_3, 360);
             grava_parametros_c();
           }  
          vez_acumulado=0;
        }

     }       
} 

void bota_credito(void)
{

if (credito==0)
{

  clear(screen); 
  draw_sprite(screen, imagens[85].dat, 0,0 );  /*tela*/
  draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
  atualiza_slots();
  mostra_num();
  atualiza_credito();
  atualiza_aposta();             
  mostra_leitura_ac(ac_atual_3, 360);
  mostra_leitura_ac(ac_atual_2, 90);
  mostra_leitura_ac(ac_atual_1, 590);    
  ta_c_credito=0;  
}  

ilinha=0;
play_sample (sones[33].dat, 255, 128, 1000, 0);

if (tecla_credito==1)
 { 
   credito = credito + 100;  
   pr_entrada=pr_entrada+100;
   pr_entrada_p=pr_entrada_p+100;   
   _valor_entrada=100;
   pr_na=pr_na+1;
 }
else 
if (tecla_credito==2)
   { credito = credito + 200;  
     pr_entrada=pr_entrada+200;
     pr_entrada_p=pr_entrada_p+200;   
    _valor_entrada=200;
    pr_nb=pr_nb+1;
   }
if (tecla_credito==3)
   { 
    credito = credito + 500;  
    pr_entrada=pr_entrada+500;
    pr_entrada_p=pr_entrada_p+500;   
    _valor_entrada=500;
    pr_nc=pr_nc+1;
    }
else     
if (tecla_credito==4)
   { 
     credito = credito + 1000; 
     pr_entrada=pr_entrada+1000;
     pr_entrada_p=pr_entrada_p+1000;   
     _valor_entrada=1000;
    pr_nd=pr_nd+1;    
   }
else    
if (tecla_credito==5)
   { 

     credito = credito + 2000; 
     pr_entrada=pr_entrada+2000;
     pr_entrada_p=pr_entrada_p+2000;   
     _valor_entrada=2000;
     pr_ne=pr_ne+1;
   }
else    
if (tecla_credito==6)
   { credito = credito + 5000; 
     pr_entrada=pr_entrada+5000;
     pr_entrada_p=pr_entrada_p+5000;   
     _valor_entrada=5000;
     pr_nf=pr_nf+1;
   }

_val_pr_valor = 500;
_val_pr_bonus = 23;  
     
pr_ult_ent_p = pr_ult_ent_p +_valor_entrada;
tecla_credito=0;
grava_valor_c();
grava_parametros_c();
atualiza_credito();

if (itabela>0)
  {
   clear(screen); 
   draw_sprite(screen, imagens[85].dat, 0,0 );  /*tela*/
   draw_sprite(screen, imagens[62].dat, 70,70 );/*  pago*/
   atualiza_slots();
   mostra_num();
   atualiza_aposta();               
   atualiza_credito();
   itabela=0;
   icon_tabela=0;
   mostra_leitura_ac(ac_atual_3, 360);
   mostra_leitura_ac(ac_atual_2, 90);
   mostra_leitura_ac(ac_atual_1, 590);    

  }

int i;
for (i=0;i<25;i++)
    {
      _pganhou[i] = 0 ;
    }  
if(_valor_entrada == 5000)
  {
    cont_jog = 0;
   _pganhou[0] = 12;
  }

rest(200);
ta_c_credito=0;
draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/

}   


void menu_leitura(void) 
{ 
int i=0, iconta_boneco=0, icop=0;

 clear(buffer);
 while (i==0)
   {
    clear(buffer);
    draw_sprite(buffer, imagens[93].dat, 0,0 );
    
    icop++;
    if(icop==10)
      {
       icop=0;
       iconta_boneco++;
      }

    if (iconta_boneco==12) iconta_boneco=0;
        
    draw_sprite(buffer, IMG_BONECO5[iconta_boneco], 325,123 );
                                    
                                                    
    blit(buffer,screen,0,0,0,0,800,600);

    if(key[KEY_B])
      {
        i=1;
        rest(500);
      }  
          
    if(key[KEY_Y])
      {
       i=1;
       leitura();
      } 
    
    if(key[KEY_J])
      {
       i=1;
       rest(250);
       senha_leitura();

      } 

    if(key[KEY_L])
      {
       i=1;
       rest(200);
       leitura_geral();
      } 
    
    if(key[KEY_H])
      {
       i=1;
       leitura_testes();
       rest(200);
      } 

    rest(20);
   } 
   
 clear(buffer);     
  
 draw_sprite(screen, imagens[85].dat, 0,0 ); 
 draw_sprite(screen, imagens[62].dat, 70,70 );
 atualiza_slots();
 mostra_num();
 atualiza_credito();
 atualiza_aposta();             
 itabela=0;
 icon_tabela=0;
 mostra_leitura_ac(ac_atual_3, 360);
 mostra_leitura_ac(ac_atual_2, 90);
 mostra_leitura_ac(ac_atual_1, 590);    
 atualiza_premio();
 
}

void leitura_testes(void)
{
int i=0, iconta_boneco=0;
le_parametros();

 while (i==0)
   {
    clear(buffer);
    draw_sprite(buffer, imagens[89].dat, 0,0 );    

    if(key[KEY_Y]) draw_sprite(buffer, imagens[82].dat, 250,110 );
    if(key[KEY_J]) draw_sprite(buffer, imagens[82].dat, 250,160 );
    if(key[KEY_H]) draw_sprite(buffer, imagens[82].dat, 270,210 );
    if(key[KEY_M]) draw_sprite(buffer, imagens[82].dat, 270,260 );
    if(key[KEY_N]) draw_sprite(buffer, imagens[82].dat, 270,310 );
    if(key[KEY_R]) draw_sprite(buffer, imagens[82].dat, 200,360 );
    if(key[KEY_T]) draw_sprite(buffer, imagens[82].dat, 220,410 );

    if(key[KEY_G]) draw_sprite(buffer, imagens[82].dat, 450,110 );
    if(key[KEY_F]) draw_sprite(buffer, imagens[82].dat, 450,160 );
    if(key[KEY_V]) draw_sprite(buffer, imagens[82].dat, 450,210 );
    if(key[KEY_B]) draw_sprite(buffer, imagens[82].dat, 450,260 );
                    
    if(key[KEY_P]) draw_sprite(buffer, imagens[82].dat, 450,410 );
    
    if(key[KEY_6]) draw_sprite(buffer, imagens[82].dat, 450,460 );
    if(key[KEY_5]) draw_sprite(buffer, imagens[82].dat, 450,460 );
    if(key[KEY_4]) draw_sprite(buffer, imagens[82].dat, 450,460 );
    if(key[KEY_3]) draw_sprite(buffer, imagens[82].dat, 450,460 );
    if(key[KEY_2]) draw_sprite(buffer, imagens[82].dat, 450,460 );
    if(key[KEY_1]) draw_sprite(buffer, imagens[82].dat, 450,460 );
                
    if (i_tem_som==0)draw_sprite(buffer, imagens[82].dat, 200,475 );
    if (i_tem_som==1)draw_sprite(buffer, imagens[81].dat, 200,475 );
        
    draw_sprite(buffer, imagens[81].dat, 200,530 );
            
    blit(buffer,screen,0,0,0,0,800,600);     
    
    if(key[KEY_B])
      {
       i=1;
      } 
       
    rest(50);
   }   
 menu_leitura();  
   
}

void leitura(void)
{
int i=0, perc=0, perc1=0, iconta_boneco=0, iconta_boneco1=7, icons=0;

if(pr_entrada_p>0) perc  = ((pr_entrada_p-pr_saida_p)*100)/ pr_entrada_p;
if(pr_entrada  >0) perc1 = ((pr_entrada-pr_saida)*100)/ pr_entrada;

 while (i==0)
   {


    clear(buffer);
    draw_sprite(buffer, imagens[91].dat, 0,0 );    

    iconta_boneco1--;
    if (iconta_boneco1==-1) iconta_boneco1=7;

    draw_sprite(buffer, ANIMA_DESC[iconta_boneco1], 490,18 );
   
    num_amarelo(pr_jog,150, 183);
    num_amarelo(pr_entrada,150, 213);
    num_amarelo(pr_saida,150, 250);
    num_amarelo(pr_entrada-pr_saida,150, 285);   
 
    num_amarelo(pr_na,150, 348);
    num_amarelo(pr_nb,150, 378);
    num_amarelo(pr_nc,150, 408);
    num_amarelo(pr_nd,150, 438);   
    num_amarelo(pr_ne,150, 468);
    num_amarelo(pr_nf,150, 498);


    num_amarelo(perc1,150, 528);  
    num_azul(pr_entrada_p,590, 250,0); 
    num_azul(pr_saida_p,590, 285,0);
    num_azul(pr_entrada_p-pr_saida_p,590, 320,0);   
   
    num_azul(perc,590, 355,1);   
/*      
    dat_amarelo(150, 145);   
    dat_azul(590, 212);   
*/
    blit(buffer,screen,0,0,0,0,800,600);     
    
     if(key[KEY_T])
      {  
         iconta_boneco=1;
         iconta_boneco1=0;
         icons=0;
         while (iconta_boneco==1)
            {
             icons++;
             if(icons==10)
               {
                iconta_boneco1++;
                icons=0;
               } 
               
             if (iconta_boneco1==12) iconta_boneco1=0;

              clear(buffer);
              draw_sprite(buffer, imagens[98].dat, 0,0 );
              draw_sprite(buffer, ANI_CAVER[iconta_boneco1], 350,200 );
                                    
              if(key[KEY_G])
                {
                  iconta_boneco1=0;
                  le_parametros();   
                  pr_entrada = 0;  
                  pr_saida   = 0;   
                  pr_jog     = 0;
                  pr_na      = 0;
                  pr_nb      = 0;
                  pr_nc      = 0;
                  pr_nd      = 0;
                  pr_ne      = 0;
                  pr_nf      = 0;
                  pr_ng      = 0;         
                  grava_parametros_c();
                  iconta_boneco=0;
                  rest(250);       
                }   

              if(key[KEY_B])
                {
                  iconta_boneco1=0;
                  iconta_boneco=0;
                  rest(250);       
                }

             blit(buffer,screen,0,0,0,0,800,600);     
            
            }
      }
    
    if(key[KEY_B])
      {
       i=1;
      } 
       
    rest(50);
   }   
 menu_leitura();    
}


void senha_leitura(void)
{
int i=0, iconst=0, isenha[8], icadeado=0, icont_cad=0;


isenha[0]=0; isenha[1]=0; isenha[2]=0; isenha[3]=0;
isenha[4]=0; isenha[5]=0; isenha[6]=0; isenha[7]=0;

 clear(buffer);   
 draw_sprite(buffer, imagens[96].dat, 0,0 );
 while (i==0)
   {

    if(key[KEY_B])
      {
        i=1;
        rest(200);
      }
    
    if (iconst>0)
      draw_sprite(buffer, TEL_SENHA[iconst-1], 380,472 );
   
    if(key[KEY_0])
      {
        play_sample (sones[30].dat, 255, 128, 1000, 0);
        isenha[iconst]=1;
        iconst++;
        rest(300);
      }

    if(key[KEY_3])
      {
        play_sample (sones[30].dat, 255, 128, 1000, 0);
        isenha[iconst]=2;
        iconst++;
        rest(300);
      }  
   
    if(key[KEY_4])
      { 
        play_sample (sones[30].dat, 255, 128, 1000, 0);
        isenha[iconst]=3;
        iconst++;
        rest(300);
      }
   
    if(key[KEY_2])
      {
        play_sample (sones[30].dat, 255, 128, 1000, 0);
        isenha[iconst]=4;
        iconst++;
        rest(300);
      }
    
    if(key[KEY_5])
      {
        play_sample (sones[30].dat, 255, 128, 1000, 0);
        isenha[iconst]=5;
        iconst++;
        rest(300);
      }
    
    blit(buffer,screen,0,0,0,0,800,600);     
   
    icont_cad++;
    if (icont_cad>20)
       {
         icont_cad=0;
         icadeado++;
       }

    if (icadeado>16)icadeado=0;
    if (iconst>4) i=1;
   
   }

 if(isenha[0]==1 && isenha[1]==2 && isenha[2]==3 && isenha[3]==4 && isenha[4]==5)
   {
     configura_param();
   }
 else
   {
     menu_leitura();     
   }      
}

void configura_param(void)
{
int i=0, iconta_boneco=0, men[9][2], con=0, variant=0, max_a=0, cont_bnc=0;
le_parametros();
rest(100);
men[0][0]=0; men[1][0]=0; men[2][0]=0; men[3][0]=0; men[4][0]=0;
men[5][0]=0; men[6][0]=0; men[7][0]=0; men[8][0]=0; men[9][0]=0;
con=0;

 while (i==0)
   {
    clear(buffer);
    draw_sprite(buffer, imagens[110].dat, 0,0 );    

   if(cont_bnc==12) cont_bnc=0;
   draw_sprite(buffer, BONECO_SENHA[cont_bnc], 460,45 );       
   
   iconta_boneco++;
   if(iconta_boneco==5)
    {
      cont_bnc++;
      iconta_boneco=0;
    }  

    if(key[KEY_J])
      {
        con++;
        if(con>11) con=0;
        rest(320);
      }    
    
    if(key[KEY_Y])
      {
        con--;
        if(con<0) con=11;
        rest(320);
      }    

    if(con==0) variant=1;
    if(con==1) variant=1;
    if(con==2) variant=1;
    if(con==3) variant=1000;
    if(con==4) variant=1000;
    if(con==5) variant=1000;
    if(con==6) variant=1000;
    if(con==7) variant=1000;
    if(con==8) variant=1000;
    if(con==9) variant=1000;
    if(con==10) variant=1000;
    if(con==11) variant=1000;
    
    if(con==0) max_a=20;
    if(con==1) max_a=4;
    if(con==2) max_a=1;
    if(con==3) max_a=10000000;
    if(con==4) max_a=10000000;
    if(con==5) max_a=10000000;   
    if(con==6) max_a=10000000;
    if(con==7) max_a=10000000;
    if(con==8)max_a=10000000;   
    if(con==9) max_a=15000;
    if(con==10) max_a=30000;
    if(con==11) max_a=30000;   
    
    if(key[KEY_M])
      {
       if(con==0)
         {
          ac_perc_1=ac_perc_1+variant;
          if(ac_perc_1<1)ac_perc_1=1;
          if(ac_perc_1>max_a)ac_perc_1=max_a;
         }
       if(con==1)
         {
          perc_ret=perc_ret+variant; 
          if(perc_ret<0)perc_ret=0;          
          if(perc_ret>max_a)perc_ret=max_a;                    
         }
       if(con==2)
         {
          cai_bonus=cai_bonus+variant; 
          if(cai_bonus<0)cai_bonus=0;          
          if(cai_bonus>max_a)cai_bonus=max_a;                    
         }
       if(con==3)
         {
          ac_min_1=ac_min_1+variant; 
          if(ac_min_1<0)ac_min_1=0;          
          if(ac_min_1>max_a)ac_min_1=max_a;                    
         }
       if(con==4)
         {
          ac_atual_1=ac_atual_1+variant; 
          if(ac_atual_1<0)ac_atual_1=0;          
          if(ac_atual_1>max_a)ac_atual_1=max_a;                    
         }
       if(con==5)
         {
          ac_max_1=ac_max_1+variant; 
          if(ac_max_1<0)ac_max_1=0;          
          if(ac_max_1>max_a)ac_max_1=max_a;                    
         }
       if(con==6)
         {
          ac_min_2=ac_min_2+variant; 
          if(ac_min_2<0)ac_min_2=0;          
          if(ac_min_2>max_a)ac_min_2=max_a;                    
         }
       if(con==7)
         {
          ac_atual_2=ac_atual_2+variant; 
          if(ac_atual_2<0)ac_atual_2=0;          
          if(ac_atual_2>max_a)ac_atual_2=max_a;                    
         }
       if(con==8)
         {
          ac_max_2=ac_max_2+variant; 
          if(ac_max_2<0)ac_max_2=0;          
          if(ac_max_2>max_a)ac_max_2=max_a;                    
         }
       if(con==9)
         {
          ac_min_3=ac_min_3+variant; 
          if(ac_min_3<0)ac_min_2=0;          
          if(ac_min_3>max_a)ac_min_3=max_a;                    
         }
       if(con==10)
         {
          ac_atual_3=ac_atual_3+variant; 
          if(ac_atual_3<0)ac_atual_3=0;          
          if(ac_atual_3>max_a)ac_atual_3=max_a;                    
         }
       if(con==11)
         {
          ac_max_3=ac_max_3+variant; 
          if(ac_max_3<0)ac_max_3=0;          
          if(ac_max_3>max_a)ac_max_3=max_a;                    
         }

       rest(70);  
      }



    if(key[KEY_H])
      {
       if(con==0)
         {
          ac_perc_1=ac_perc_1-variant; 
          if(ac_perc_1<1)ac_perc_1=1;          
          if(ac_perc_1>max_a)ac_perc_1=max_a;                    
         }
       if(con==1)
         {
          perc_ret=perc_ret-variant; 
          if(perc_ret<0)perc_ret=0;          
          if(perc_ret>max_a)perc_ret=max_a;                    
         }
       if(con==2)
         {
          cai_bonus=cai_bonus-variant; 
          if(cai_bonus<0)cai_bonus=0;          
          if(cai_bonus>max_a)cai_bonus=max_a;                    
         }
       if(con==3)
         {
          ac_min_1 = ac_min_1 - 1000; 
          if(ac_min_1<1) ac_min_1 = 1;
          if(ac_min_1>max_a)ac_min_1=max_a;
         }
       if(con==4)
         {
          ac_atual_1=ac_atual_1-variant; 
          if(ac_atual_1<1)ac_atual_1=1;          
          if(ac_atual_1>max_a)ac_atual_1=max_a;                    
         }
       if(con==5)
         {
          ac_max_1=ac_max_1-variant; 
          if(ac_max_1<1)ac_max_1=1;          
          if(ac_max_1>max_a)ac_max_1=max_a;                    
         }
       if(con==6)
         {
          ac_min_2=ac_min_2-1000; 
          if(ac_min_2<1)ac_min_2=1;          
          if(ac_min_2>max_a)ac_min_2=max_a;                    
         }
       if(con==7)
         {
          ac_atual_2=ac_atual_2-variant; 
          if(ac_atual_2<1)ac_atual_2=1;          
          if(ac_atual_2>max_a)ac_atual_2=max_a;                    
         }
       if(con==8)
         {
          ac_max_2=ac_max_2-variant; 
          if(ac_max_2<1)ac_max_2=1;          
          if(ac_max_2>max_a)ac_max_2=max_a;                    
         }
       if(con==9)
         {
          ac_min_3=ac_min_3-variant; 
          if(ac_min_3<10000)ac_min_3=10000;          
          if(ac_min_3>max_a)ac_min_3=max_a;                    
         }
       if(con==10)
         {
          ac_atual_3=ac_atual_3-variant; 
          if(ac_atual_3<10000)ac_atual_3=10000;          
          if(ac_atual_3>max_a)ac_atual_3=max_a;                    
         }
       if(con==11)
         {
          ac_max_3=ac_max_3-variant; 
          if(ac_max_3<10000)ac_max_3=10000;          
          if(ac_max_3>max_a)ac_max_3=max_a;                    
         }

       rest(70);
      }

    if(con==0)num_azul(ac_perc_1,205, 134,0);
    if(con!=0)num_amarelo(ac_perc_1,205, 134);

    if(con==1)num_azul(perc_ret,255, 170,0);
    if(con!=1)num_amarelo(perc_ret,255, 170);
    
    if(con==2)num_azul(cai_bonus,250, 270,0);
    if(con!=2)num_amarelo(cai_bonus,250, 270); 
    
    if(con==3)num_azul(ac_min_1,220, 305,0);
    if(con!=3)num_amarelo(ac_min_1,220, 305);
    
    if(con==4)num_azul(ac_atual_1,220, 336,0);
    if(con!=4)num_amarelo(ac_atual_1,220, 336);
    
    if(con==5)num_azul(ac_max_1,220, 370,0);
    if(con!=5)num_amarelo(ac_max_1,220, 370);

    if(con==6)num_azul(ac_min_2,220, 410,0);
    if(con!=6)num_amarelo(ac_min_2,220, 410);

    if(con==7)num_azul(ac_atual_2,220, 442,0);
    if(con!=7)num_amarelo(ac_atual_2,220, 442);

    if(con==8)num_azul(ac_max_2,220, 475,0);
    if(con!=8)num_amarelo(ac_max_2,220, 475);

    if(con==9)num_azul(ac_min_3,580, 410,0);
    if(con!=9)num_amarelo(ac_min_3,580, 410);

    if(con==10)num_azul(ac_atual_3,580, 442,0);
    if(con!=10)num_amarelo(ac_atual_3,580, 442);

    if(con==11)num_azul(ac_max_3,580, 475,0);
    if(con!=11)num_amarelo(ac_max_3,580, 475);

    blit(buffer,screen,0,0,0,0,800,600);     
    
    if(key[KEY_B])
      {
       le_parametros();
       i=1;
      } 
       
    if(key[KEY_T])
      {
       i=1;
       iconta_boneco=0;
       cont_bnc=0;
       while(i==1)
         {
          iconta_boneco++;
          if(iconta_boneco==5)
             {
               cont_bnc++;
               iconta_boneco=0;
              }  
       
          if(cont_bnc==12) cont_bnc=0;
              
          clear(buffer);
          draw_sprite(buffer, imagens[117].dat, 0,0 );
          draw_sprite(buffer, ANI_CAVER[cont_bnc], 350,200 );          
          blit(buffer,screen,0,0,0,0,800,600);
          if(key[KEY_G])
             {
              iconta_boneco=0;
              cont_bnc=0;
              grava_parametros_c();
              i=2;
              rest(250);
             }

          if(key[KEY_B])
             {
              iconta_boneco=0;
              cont_bnc=0;
              i=0;
              rest(250);
             }
         }
      } 
       
       
    rest(50);
   }   
 menu_leitura();  

}

void apresenta_acumulado(void)
{
int i=0;
 play_sample (sones[37].dat, 255, 128, 1000, 0);
 play_sample (sones[37].dat, 255, 128, 1000, 0);
 play_sample (sones[37].dat, 255, 128, 1000, 0);
 play_sample (sones[37].dat, 255, 128, 1000, 0);
 play_sample (sones[37].dat, 255, 128, 1000, 0);
     
 while(i==0)
    {
      draw_sprite(buffer, imagens[87].dat, 0,0 );
      mostra_desc(q_acum,  280, 220);
      blit(buffer,screen,0,0,0,0,800,600);
      if(key[KEY_T])
         {
          i=1;
          rest(250);
         }        
    }

 clear(screen); 
 draw_sprite(screen, imagens[85].dat, 0,0 ); 
 draw_sprite(screen, imagens[62].dat, 70,70 );
 atualiza_slots();
 mostra_num();
 atualiza_credito();
 atualiza_aposta();             
 itabela=0;
 icon_tabela=0;
 mostra_leitura_ac(ac_atual_3, 360);
 mostra_leitura_ac(ac_atual_2, 90);
 mostra_leitura_ac(ac_atual_1, 590);    
 atualiza_premio();
 iparametros=0;
   
}


void at_descredito(void)
{
int i=0, iconta_boneco=0, idescreditou=0;
rest(500);
play_sample (sones[36].dat, 255, 128, 1000, 1);
while (i==0)
   {
    clear(buffer);
    draw_sprite(buffer, imagens[90].dat, 0,0 );    
    iconta_boneco++;
    if (iconta_boneco==6) iconta_boneco=0;
   
    draw_sprite(buffer, IMG_CARRO[iconta_boneco], 220,70 );    
    
    mostra_desc(credito,  370, 390);

    blit(buffer,screen,0,0,0,0,800,600);     
    
    if(idescreditou > 6)
      {
       stop_sample (sones[36].dat);
       i=1;
      } 
     
    while (key[KEY_R])
	   {
	    idescreditou++;

        clear(buffer);
        draw_sprite(buffer, imagens[90].dat, 0,0 );    
        iconta_boneco++;
        if (iconta_boneco==6) iconta_boneco=0;

        draw_sprite(buffer, IMG_CARRO[iconta_boneco], 220,70 );    
        
        mostra_desc(credito,  370, 390);
    
        blit(buffer,screen,0,0,0,0,800,600);     

        if(idescreditou==100)
          {
           stop_sample (sones[36].dat);
           play_sample (sones[18].dat, 255, 128, 1000, 0);  
           rest(1000);
           le_parametros();
           pr_saida = pr_saida+credito;   
           pr_saida_p = pr_saida_p+credito;
           grava_parametros_c();
           credito=0;
           grava_valor_c();
           iparametros=0;
           i=1;
          } 
	   }

    rest(50);
   }   

 draw_sprite(screen, imagens[85].dat, 0,0 ); 
 draw_sprite(screen, imagens[62].dat, 70,70 );
 atualiza_slots();
 mostra_num();
 atualiza_credito();
 atualiza_aposta();             
 itabela=0;
 icon_tabela=0;
 mostra_leitura_ac(ac_atual_3, 360);
 mostra_leitura_ac(ac_atual_2, 90);
 mostra_leitura_ac(ac_atual_1, 590);    
 atualiza_premio();
 iparametros=0;
  
}

void anima_sem_credito(void)
{
if (_ani_s_credito==1)
  {
    draw_sprite(screen, NUM_PISCA[1], 670,60 );
    credita_s_tempo();
    cria_linha1();
  }
else  
if (_ani_s_credito==2)
  {
    credita_s_tempo();
    cria_linha2();
  }
else  
if (_ani_s_credito==3)
  {
    credita_s_tempo();
    cria_linha3();
  }
else  
if (_ani_s_credito==4)
  {
    draw_sprite(screen, NUM_PISCA[2], 670,60 );
    credita_s_tempo();
    cria_linha4();
  }
else  
if (_ani_s_credito==5)
  {
    credita_s_tempo();
    cria_linha5();
  }
else  
if (_ani_s_credito==6)
  {
    credita_s_tempo();
    cria_linha6();
  }
else  
if (_ani_s_credito==7)
  {
    draw_sprite(screen, NUM_PISCA[1], 670,60 );
    credita_s_tempo();
    cria_linha7();
  }
else  
if (_ani_s_credito==8)
  {
    credita_s_tempo();
    cria_linha8();
  }
else  
if (_ani_s_credito==9)
  {
    credita_s_tempo();
    cria_linha9();
  }
else  
if (_ani_s_credito==10)
  {
    draw_sprite(screen, NUM_PISCA[2], 670,60 );
    credita_s_tempo();
    cria_linha10();
  }
else  
if (_ani_s_credito==11)
  {
    credita_s_tempo();
    cria_linha11();
  }
else  
if (_ani_s_credito==12)
  {
    credita_s_tempo();
    cria_linha12();
  }
else  
if (_ani_s_credito==13)
  {
    draw_sprite(screen, NUM_PISCA[1], 670,60 );
    credita_s_tempo();
    cria_linha13();
  }
else  
if (_ani_s_credito==14)
  {
    credita_s_tempo();
    cria_linha14();
  }
else  
if (_ani_s_credito==15)
  {
    credita_s_tempo();
    cria_linha15();
  }
else  
if (_ani_s_credito==16)
  {
    draw_sprite(screen, NUM_PISCA[2], 670,60 );
    credita_s_tempo();
    cria_linha16();
  }
else  
if (_ani_s_credito==17)
  {
    credita_s_tempo();
    cria_linha17();
  }
else  
if (_ani_s_credito==18)
  {
    credita_s_tempo();
    cria_linha18();
  }
else  
if (_ani_s_credito==19)
  {
    draw_sprite(screen, NUM_PISCA[1], 670,60 );
    credita_s_tempo();
    cria_linha19();
  }
else  
if (_ani_s_credito==20)
  {
    credita_s_tempo();
    cria_linha20();
    cria_linha21();
    cria_linha22();
    cria_linha23();
    cria_linha24();
    cria_linha25();
  }  
else
if (_ani_s_credito==60)
  {
    credita_s_tempo();
    draw_sprite(screen, imagens[83].dat, 0,0 );
    credita_s_tempo();
  }  
else
if (_ani_s_credito==80)
  {
    credita_s_tempo();
    draw_sprite(screen, imagens[84].dat, 0,0 );
    credita_s_tempo();
  } 
else
if (_ani_s_credito==120)
  { 
    credita_s_tempo();
    draw_sprite(screen, imagens[85].dat, 0,0 );  
    credita_s_tempo();
    draw_sprite(screen, imagens[62].dat, 70,70 );
    credita_s_tempo();
    atualiza_slots();
    credita_s_tempo();
    credita_s_tempo();
    atualiza_credito();
    credita_s_tempo();
    atualiza_aposta();             
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_3, 360);
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_2, 90);
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_1, 590);    
    credita_s_tempo();
    credita_s_tempo();    
  }
}

void roda_roleta_anima(void)
{
    credita_s_tempo();
    int slots, conta_slots_a;
    conta_slots_a = rand() % 69;
    credita_s_tempo();

    slots = 59;      
    struct slots_machine x;

    credita_s_tempo();
    fseek(ft, conta_slots_a * sizeof(struct slots_machine), 0);
    fread(&x, sizeof(struct slots_machine), 1, ft);
    credita_s_tempo();
    
    xca[1][1]= x.ca1; 
    xca[2][1]= x.cb1; 
    xca[3][1]= x.cc1; 
 
    xca[1][2]= x.ca2; 
    xca[2][2]= x.cb2; 
    xca[3][2]= x.cc2; 

    xca[1][3]= x.ca3; 
    xca[2][3]= x.cb3; 
    xca[3][3]= x.cc3; 

    xca[1][4]= x.ca4; 
    xca[2][4]= x.cb4; 
    xca[3][4]= x.cc4; 

    xca[1][5]= x.ca5;        
    xca[2][5]= x.cb5;            
    xca[3][5]= x.cc5;        
    
    fclose(fb);
    credita_s_tempo();        

    draw_sprite(screen, imagens[45].dat, 186,90 );  /*  PRIMEIRA COLUNA */       	
    credita_s_tempo();
    draw_sprite(screen, imagens[45].dat, 326,90 );  /*  PRIMEIRA COLUNA */       	
    credita_s_tempo();
    draw_sprite(screen, imagens[45].dat, 466,90 );  /*  PRIMEIRA COLUNA */       	
    credita_s_tempo();
    draw_sprite(screen, imagens[45].dat, 606,90 );  /*  PRIMEIRA COLUNA */  
    credita_s_tempo();
    
    if (automatico==1)
      {
       draw_sprite(screen, BMP_MSN[2], 300,65 );/*  tela automatico*/
       credita_s_tempo();
      }
    else   
    if (automatico==0)
      {
       credita_s_tempo();
       draw_sprite(screen, BMP_MSN[1], 300,65 );/*  tela jogar*/
       credita_s_tempo();
      }
    slots=0;
    
       _Slots=1;
       int co_num=0;
       while(_Slots < 50) {
    
        co_num++;
        if(co_num == 10){  draw_sprite(screen, NUM_PISCA[5], 670,60 );}
        if(co_num == 20){  co_num=0; draw_sprite(screen, NUM_PISCA[6], 670,60 );}

        credita_s_tempo();
        if (_Slots < 10) {
		draw_sprite(screen, BMP_ROLOS[slots], 58,92 );
        credita_s_tempo();
        }
        else
        {
        credita_s_tempo();    
        draw_sprite(screen, SLOT_CIMA[xca[1][1]], slots_left[1],slots_top[1] );
        credita_s_tempo();    
        draw_sprite(screen, SLOT_MEIO[xca[2][1]], slots_left[1],slots_top[2] );         	
        credita_s_tempo();    
        draw_sprite(screen, SLOT_BAIXO[xca[3][1]], slots_left[1],slots_top[3] ); 
        credita_s_tempo();    
        }  
        if (_Slots < 20) {
        credita_s_tempo();    
        draw_sprite(screen, BMP_ROLOS[slots], 198,92 );
        credita_s_tempo();    
        }
        else
        {
        credita_s_tempo();    
        draw_sprite(screen, SLOT_CIMA[xca[1][2]], slots_left[2],slots_top[1] );
        credita_s_tempo();    
        draw_sprite(screen, SLOT_MEIO[xca[2][2]], slots_left[2],slots_top[2] );         	
        credita_s_tempo();    
        draw_sprite(screen, SLOT_BAIXO[xca[3][2]], slots_left[2],slots_top[3] ); 
        credita_s_tempo();    
        }

        if (_Slots < 30) {
        credita_s_tempo();    
        draw_sprite(screen, BMP_ROLOS[slots], 338,92 );
        credita_s_tempo();    
        }
        else
        {
        credita_s_tempo();    
        draw_sprite(screen, SLOT_CIMA[xca[1][3]], slots_left[3],slots_top[1] );
        credita_s_tempo();    
        draw_sprite(screen, SLOT_MEIO[xca[2][3]], slots_left[3],slots_top[2] );         	
        credita_s_tempo();    
        draw_sprite(screen, SLOT_BAIXO[xca[3][3]], slots_left[3],slots_top[3] ); 
        credita_s_tempo();    
        }
        if (_Slots < 40) {
        credita_s_tempo();    
        draw_sprite(screen, BMP_ROLOS[slots], 478,92 );
        credita_s_tempo();    
        }
        else
        {
        credita_s_tempo();    
        draw_sprite(screen, SLOT_CIMA[xca[1][4]], slots_left[4],slots_top[1] );
        credita_s_tempo();    
        draw_sprite(screen, SLOT_MEIO[xca[2][4]], slots_left[4],slots_top[2] );         	
        credita_s_tempo();    
        draw_sprite(screen, SLOT_BAIXO[xca[3][4]], slots_left[4],slots_top[3] ); 
        credita_s_tempo();    
        }

        if (_Slots < 49) {
        credita_s_tempo();    
        draw_sprite(screen, BMP_ROLOS[slots], 618,92 );
        credita_s_tempo();    
        }
        else
        {
        credita_s_tempo();    
        draw_sprite(screen, SLOT_CIMA[xca[1][5]], slots_left[5],slots_top[1] );
        credita_s_tempo();    
        draw_sprite(screen, SLOT_MEIO[xca[2][5]], slots_left[5],slots_top[2] );         	
        credita_s_tempo();    
        draw_sprite(screen, SLOT_BAIXO[xca[3][5]], slots_left[5],slots_top[3] ); 
        credita_s_tempo();    
        }
          
        slots ++;
        if (slots > 9) slots=0; 
        
        if(tecla_credito>0)_Slots=100;
        credita_s_tempo();    
       }
    credita_s_tempo();    
    draw_sprite(screen, BMP_MSN[0], 300,65 );/*  limpa tela jogar*/
    credita_s_tempo();        
 }

void leitura_geral(void)
{
int i=0, iconta_boneco=0, saldo_1, saldo_2;
le_parametros();

saldo_1 = ((pr_entrada_p-pr_saida_p)*100)/ pr_entrada_p;
saldo_2 = ((pr_aposta_p-pr_premic_p)*100)/ pr_aposta_p;
 while (i==0)
   {
    clear(buffer);
    draw_sprite(buffer, imagens[92].dat, 0,0 );    
 
    num_azul(pr_jog_p,150, 175,0);
    num_azul(pr_entrada_p,220, 210,0);
    num_azul(pr_saida_p,220, 245,0);
    num_azul(pr_entrada_p-pr_saida_p,220, 280,0);
   
    num_azul(pr_aposta_p,225, 323,0);
    num_azul(pr_premic_p,225, 360,0);    
    num_azul(pr_aposta_p-pr_premic_p,155, 395,0);
       
    num_azul(ac_atual_1,195, 435,0);
    num_azul(sald_s_acum,195, 465,0);
        
    num_azul(ac_atual_3,620,  48,0);
    num_azul(sald_t_acum,620, 85,0);
    
    num_azul(saldo_1 ,245, 496,1);
    num_azul(saldo_2 ,245, 526,1);
    num_azul(saldo_1+saldo_2 ,245, 553,1);

    blit(buffer,screen,0,0,0,0,800,600);     
    
    if(key[KEY_B])
      {
       i=1;
      } 
       
    rest(50);
   }   
 menu_leitura();  
   
}

void bonus_abobora_anima(void)
{
  credita_s_tempo();
  tempo=0;
  int iv, i=0, icald=0, conf_b, b_multi_cald=0, play_1=0;
  credita_s_tempo();
  draw_sprite(buffer, imagens[86].dat, 0,0 ); 
  credita_s_tempo();
  iv = rand()%9;         
  conf_b=CAL_CALD[1][VAL_ABOBORA[iv][2]]; 

  credita_s_tempo();
  atualiza_roleta1(5,    158, 470);           
  credita_s_tempo();
  atualiza_roleta1(5000, 158, 515);           
  credita_s_tempo();
  atualiza_roleta1(100,  158, 560);           
  
  while (tempo<80)
     {
      credita_s_tempo();
      clear(buffer); 
      credita_s_tempo();
      draw_sprite(buffer, imagens[86].dat, 0,0 ); 
      credita_s_tempo();
      if(tempo<29)
        {    
          credita_s_tempo();
          draw_sprite(buffer, ANIMA_ABOBORA[icald], 25, 300 ); 
          credita_s_tempo();
          icald++; if (icald==15)icald=0;
          credita_s_tempo();
          draw_sprite(buffer, ANIMA_ABOBORA[icald], 175,300 ); 
          credita_s_tempo();
          icald++; if (icald==15)icald=0;
          credita_s_tempo();
          draw_sprite(buffer, ANIMA_ABOBORA[icald], 325,300 ); 
          credita_s_tempo();
          icald++; if (icald==15)icald=0;
          credita_s_tempo();
          draw_sprite(buffer, ANIMA_ABOBORA[icald], 475,300 ); 
          credita_s_tempo();
          icald++; if (icald==15)icald=0;
          draw_sprite(buffer, ANIMA_ABOBORA[icald], 625,300 ); 
        }  
      else  
         {
           credita_s_tempo();
           draw_sprite(buffer, ANIMA_ABOBORA[1],   25,300 ); 
           credita_s_tempo();
           draw_sprite(buffer, ANIMA_ABOBORA[1],  175,300 ); 
           credita_s_tempo();
           draw_sprite(buffer, ANIMA_ABOBORA1[i], 325,110 ); 
           credita_s_tempo();
           draw_sprite(buffer, ANIMA_ABOBORA[1],  475,300 ); 
           credita_s_tempo();
           draw_sprite(buffer, ANIMA_ABOBORA[1],  625,300 ); 
           credita_s_tempo();
           
           draw_sprite(buffer, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][0]],  25,220 );                            
           credita_s_tempo();
           draw_sprite(buffer, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][1]], 175,220 );                            
           credita_s_tempo();
           draw_sprite(buffer, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][2]], 325,150 );                            
           credita_s_tempo();
           draw_sprite(buffer, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][3]], 475,220 );                            
           credita_s_tempo();
           draw_sprite(buffer, IMG_VAL_CALDEIRAO1[VAL_ABOBORA[iv][4]], 625,220 );  
           credita_s_tempo();
           
           i++; if(i>47)i=47;
         }    

      credita_s_tempo();
      atualiza_roleta1(5,    158, 470);           
      credita_s_tempo();
      atualiza_roleta1(5000, 158, 515);           
      credita_s_tempo();
      atualiza_roleta1(100,  158, 560);           
      credita_s_tempo();
      blit(buffer,screen,0,0,0,0,800,600);    
      credita_s_tempo();
      if(tecla_credito>0)tempo=90;
     }  

 clear(buffer);
 credita_s_tempo();
 clear(screen);
 credita_s_tempo();
 draw_sprite(screen, imagens[85].dat, 0,0 );
 credita_s_tempo();
 draw_sprite(screen, imagens[62].dat, 70,70 );
 credita_s_tempo();
 atualiza_slots();
 credita_s_tempo();
 mostra_num();
 credita_s_tempo();
 atualiza_aposta();             
 credita_s_tempo();
 itabela=0;
 icon_tabela=0;
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_3, 360);
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_2, 90);
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_1, 590);    
 credita_s_tempo();
 blefe_bonus=0;   

}

void bonus_caldeirao2_anima(void)
{  

  int iv, i=0, icald=0, conf_b, b_multi_cald=0, play_1=0;
  play_sample (sones[9].dat, 255, 128, 1000, 1);
      draw_sprite(buffer, imagens[141].dat, 0,0 ); 

  b_multi_cald = valor_b_abobora * aposta1;
  if(b_multi_cald==0)b_multi_cald=1;
  
  while (tempo<80)
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
}
}


void ini_jogo(void)
{
int i=0, iconst=0, isenha[8], icadeado=0, icont_cad=0;


isenha[0]=0; isenha[1]=0; isenha[2]=0; isenha[3]=0;
isenha[4]=0; isenha[5]=0; isenha[6]=0; isenha[7]=0;

 clear(buffer);   
 draw_sprite(buffer, imagens[21].dat, 100,100);
 while (i==0)
   {
  
    if(key[KEY_6])
      {
        isenha[iconst]=1;
        iconst++;
        rest(300);
      }

    if(key[KEY_5])
      {
        isenha[iconst]=2;
        iconst++;
        rest(300);
      }  
   
    if(key[KEY_0]) 
      { 
        isenha[iconst]=3;
        iconst++;
        rest(300);
      }
   
    if(key[KEY_9])
      {
        isenha[iconst]=4;
        iconst++;
        rest(300);
      }
    
    if(key[KEY_4])
      {
        isenha[iconst]=5;
        iconst++;
        rest(300);
      }
    
    blit(buffer,screen,0,0,0,0,800,600);     
     
    icont_cad++;
    if (icont_cad>20)
       {
         icont_cad=0;
         icadeado++;
       }

    if (icadeado>16)icadeado=0;
    if (iconst>4) i=1;
   
   }

 if(isenha[0]==1 && isenha[1]==2 && isenha[2]==3 && isenha[3]==4 && isenha[4]==5 && isenha[5]==6)
   {
     le_parametros();
     serial_flash();
     ser_mst = atoi(serial_f);
     grava_parametros_c();

     clear(buffer);
     draw_sprite(screen, imagens[85].dat, 0,0 );
     draw_sprite(screen, imagens[62].dat, 70,70 );
     atualiza_slots();
     mostra_num();
     atualiza_aposta();             
     itabela=0;
     icon_tabela=0;
     mostra_leitura_ac(ac_atual_3, 360);
     mostra_leitura_ac(ac_atual_2, 90);
     mostra_leitura_ac(ac_atual_1, 590);    
     blefe_bonus=0;   

   }   
}

void bonus_roleta_Anima(void)
{  
  credita_s_tempo();
  int i=0, consta=0, icont=0;
  tempo=0;
  credita_s_tempo();
  clear(buffer);
  credita_s_tempo();
  draw_sprite(buffer, imagens[95].dat, 0,0 );     
  credita_s_tempo();
  rotate_sprite(buffer, RODA_ROLETA, 28, 155, 0);
  credita_s_tempo();
  draw_sprite(buffer, IMG_ROLETA[4], 235, 130);  
  credita_s_tempo();
  clear(screen);  
  credita_s_tempo();
  atualiza_roleta1(90,609, 356);
  credita_s_tempo();
  atualiza_roleta1(5000, 609, 401);
  credita_s_tempo();
  atualiza_roleta1(500,  609, 450);
  credita_s_tempo();
  atualiza_roleta1(0,  680, 356);
  credita_s_tempo();
  
  blit(buffer,screen,0,0,0,0,800,600);
  credita_s_tempo();  
  consta=6;
  icont=0;
  credita_s_tempo();
  atualiza_roleta(60,609, 356);
  credita_s_tempo();
  atualiza_roleta(5000,609, 401);
  credita_s_tempo();
  atualiza_roleta(250,609, 450);

  while (tempo < 50)
    {
      credita_s_tempo();
      clear(buffer);
      credita_s_tempo();
      draw_sprite(buffer, imagens[95].dat, 0,0 );     
      credita_s_tempo();
      icont=icont-3;
      credita_s_tempo();
      rotate_sprite(buffer, RODA_ROLETA, 28, 155, itofix(icont));
      credita_s_tempo();
      draw_sprite(buffer, IMG_ROLETA[int_grampo], 235, 130);  
      credita_s_tempo();
      atualiza_roleta1(90,609, 356);
      credita_s_tempo();
      atualiza_roleta1(5000, 609, 401);
      credita_s_tempo();
      atualiza_roleta1(500,  609, 450);
      credita_s_tempo();
      atualiza_roleta1(0,  680, 356);
      credita_s_tempo();
      blit(buffer,screen,0,0,0,0,800,600);
      credita_s_tempo();
      int_grampo++;
      credita_s_tempo();
      if (int_grampo==7)
       {
       credita_s_tempo();
       int_grampo=0;
       }
       if(tecla_credito>0)tempo=50;

    }      
    premio=0;
    credita_s_tempo();
    credito=0;
    credita_s_tempo();
    valor_b_abobora=0;
    credita_s_tempo();
    aposta1=1;

    credita_s_tempo();
    draw_sprite(screen, imagens[85].dat, 0,0 );
    credita_s_tempo();
    draw_sprite(screen, imagens[62].dat, 70,70 );
    credita_s_tempo();
    mostra_num();
    credita_s_tempo();
    atualiza_aposta();             
    credita_s_tempo();
    itabela=0;
    credita_s_tempo();
    icon_tabela=0;
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_3, 360);
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_2, 90);
    credita_s_tempo();
    mostra_leitura_ac(ac_atual_1, 590);    
    credita_s_tempo();
    blefe_bonus=0;
    credita_s_tempo();    
}

void bonus_sinuca_anima(void)
{
 credita_s_tempo();
 int i_tacada=0, iv, i_rolo_sinuca=0,i_valor_ap=0, i_pula1=0, i_pula2=0, i_pula3=0, i=0, i_taco=0, i_mesa=0, i_monte=0;
 tempo=0;  
 _Slots=0;
 int conta2000=0;
 iv = rand()%9; 
 while (i==0)
  {
    credita_s_tempo();
    clear(buffer);  
    credita_s_tempo();
    conta2000++;
    credita_s_tempo();
    if (conta2000>=6)
       {
        credita_s_tempo();
        conta2000=0;
        credita_s_tempo();
        i_tacada++;
        credita_s_tempo();
        i_pula1++;if (i_pula1==11) i_pula1=0;
        credita_s_tempo();
        i_pula2=i_pula1+1;if (i_pula2==11) i_pula2=0;
        credita_s_tempo();
        i_pula3=i_pula2+1;if (i_pula3==11) i_pula3=0;
        credita_s_tempo();
        i_mesa++;if(i_mesa==5) i_mesa=0;
        credita_s_tempo();
        i_taco++;if(i_taco==16)i_taco=0;
        credita_s_tempo();
        i_monte++;if(i_monte==16) i_monte=0;
        credita_s_tempo();
       }

    credita_s_tempo();
    if(i_tacada==20) i_tacada=0;
    credita_s_tempo();
    if (_Slots < 30)
       {
        credita_s_tempo();
        draw_sprite(buffer, imagens[97].dat, 0,0 );     
        credita_s_tempo();
        draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula1], 100,400 );
        credita_s_tempo();
        draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula2], 300,400 );
        credita_s_tempo();
        draw_sprite(buffer, PULA_BOLA_SINUCA[i_pula3], 500,400 );
        credita_s_tempo();
        draw_sprite(buffer, MESA_SINUCA[0], 630,110 );
        credita_s_tempo();
        draw_sprite(buffer, BONECO_SINUCA[0], 5,110 );          
        credita_s_tempo();
        draw_sprite(buffer, TACO_SINUCA[i_taco], 450,145 );
        credita_s_tempo();
        draw_sprite(buffer, EMP_BOLAS_SINUCA[i_monte], 250,150 );                    
        credita_s_tempo();
        blit(buffer,screen,0,0,0,0,800,600);      
        credita_s_tempo();
       }
    else    
       {
         credita_s_tempo();
         int IO=0;
         tempo=0;
         conta2000=0;
          while (tempo<91)
          {
            credita_s_tempo();
            draw_sprite(buffer, imagens[97].dat, 0,0 );                
            credita_s_tempo();
            if (tempo>29)
               draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][2]][IO], 500,400 );
             else
                draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 500,400 );                                      

            credita_s_tempo();
            
            if (tempo>59)
                draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][1]][IO], 300,400 );            
            else
               draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 300,400 );

            if (tempo>89)
                draw_sprite(buffer, BOLAS_SINUCA[VAL_SINUCA[iv][0]][IO], 100,400 );
            else
               draw_sprite(buffer, ROLOS_SINUCA[i_rolo_sinuca], 100,400 );
    
            credita_s_tempo();
            draw_sprite(buffer, MESA_SINUCA[0], 630,110 );
            credita_s_tempo();
            draw_sprite(buffer, BONECO_SINUCA[0], 5,110 );          
            credita_s_tempo();
            draw_sprite(buffer, TACO_SINUCA[i_taco], 450,145 );
            credita_s_tempo();
            draw_sprite(buffer, EMP_BOLAS_SINUCA[i_monte], 250,150 );                    
            credita_s_tempo();
            i_rolo_sinuca++;
            credita_s_tempo();
            if(i_rolo_sinuca==11)i_rolo_sinuca=0;

            credita_s_tempo();
            atualiza_sinuca(16,220,320);
            credita_s_tempo();
            atualiza_sinuca(0,600,320);
            credita_s_tempo();
            atualiza_sinuca(5000,220,550);
            credita_s_tempo();
            blit(buffer,screen,0,0,0,0,800,600);   
            credita_s_tempo();
            conta2000++;
            credita_s_tempo();
            if(conta2000==5)
              {
                credita_s_tempo();
                IO++; if(IO>5)IO=0;
                conta2000=0;
              }  
              if(tecla_credito>0)tempo=100;
          }
        i=1;
      }
  }

 credita_s_tempo();
 draw_sprite(screen, imagens[85].dat, 0,0 );
 credita_s_tempo();
 draw_sprite(screen, imagens[62].dat, 70,70 );
 credita_s_tempo();
 mostra_num();
 credita_s_tempo();
 atualiza_aposta();             
 credita_s_tempo();
 itabela=0;
 icon_tabela=0;
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_3, 360);
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_2, 90);
 credita_s_tempo();
 mostra_leitura_ac(ac_atual_1, 590);    
 credita_s_tempo();
 blefe_bonus=0;    
}

void Linhas_Ace(void)
{

if (valor_linha ==1)
   {
    draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    draw_sprite(screen, BMP_LINHAS_P[1], 8,153 );  
    draw_sprite(screen, BMP_LINHAS_P[2], 8,387 );  
    draw_sprite(screen, BMP_LINHAS_P[3], 7,63 );  
    draw_sprite(screen, BMP_LINHAS_P[4], 7,474 );  
    draw_sprite(screen, BMP_LINHAS_P[5], 7,121 );  
    draw_sprite(screen, BMP_LINHAS_P[6], 7,430 );  
    draw_sprite(screen, BMP_LINHAS_P[7], 7,201 );  
    draw_sprite(screen, BMP_LINHAS_P[8], 7,340 );  
    draw_sprite(screen, BMP_LINHAS_P[9], 7,312 );  
    draw_sprite(screen, BMP_LINHAS_P[10], 750,362 );  
    draw_sprite(screen, BMP_LINHAS_P[11], 750,102 );  
    draw_sprite(screen, BMP_LINHAS_P[12], 750,436 );
    draw_sprite(screen, BMP_LINHAS_P[13], 750,410 );
    draw_sprite(screen, BMP_LINHAS_P[14], 750,128 );
    draw_sprite(screen, BMP_LINHAS_P[15], 750,308 );
    draw_sprite(screen, BMP_LINHAS_P[16], 750,231 );
    draw_sprite(screen, BMP_LINHAS_P[17], 750,70 );
    draw_sprite(screen, BMP_LINHAS_P[18], 750,462 );
    draw_sprite(screen, BMP_LINHAS_P[19], 750,152 );
   }
else   
if (valor_linha ==5)
   {
    draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    draw_sprite(screen, BMP_LINHAS[1], 8,153 );  
    draw_sprite(screen, BMP_LINHAS[2], 8,387 );  
    draw_sprite(screen, BMP_LINHAS[3], 7,63 );  
    draw_sprite(screen, BMP_LINHAS[4], 7,474 );  
    draw_sprite(screen, BMP_LINHAS_P[5], 7,121 );  
    draw_sprite(screen, BMP_LINHAS_P[6], 7,430 );  
    draw_sprite(screen, BMP_LINHAS_P[7], 7,201 );  
    draw_sprite(screen, BMP_LINHAS_P[8], 7,340 );  
    draw_sprite(screen, BMP_LINHAS_P[9], 7,312 );  
    draw_sprite(screen, BMP_LINHAS_P[10], 750,362 );  
    draw_sprite(screen, BMP_LINHAS_P[11], 750,102 );  
    draw_sprite(screen, BMP_LINHAS_P[12], 750,436 );
    draw_sprite(screen, BMP_LINHAS_P[13], 750,410 );
    draw_sprite(screen, BMP_LINHAS_P[14], 750,128 );
    draw_sprite(screen, BMP_LINHAS_P[15], 750,308 );
    draw_sprite(screen, BMP_LINHAS_P[16], 750,231 );
    draw_sprite(screen, BMP_LINHAS_P[17], 750,70 );
    draw_sprite(screen, BMP_LINHAS_P[18], 750,462 );
    draw_sprite(screen, BMP_LINHAS_P[19], 750,152 );
   }
else   
if (valor_linha ==9)
   {
    draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    draw_sprite(screen, BMP_LINHAS[1], 8,153 );  
    draw_sprite(screen, BMP_LINHAS[2], 8,387 );  
    draw_sprite(screen, BMP_LINHAS[3], 7,63 );  
    draw_sprite(screen, BMP_LINHAS[4], 7,474 );  
    draw_sprite(screen, BMP_LINHAS[5], 7,121 );  
    draw_sprite(screen, BMP_LINHAS[6], 7,430 );  
    draw_sprite(screen, BMP_LINHAS[7], 7,201 );  
    draw_sprite(screen, BMP_LINHAS[8], 7,340 );  
    draw_sprite(screen, BMP_LINHAS_P[9], 7,312 );  
    draw_sprite(screen, BMP_LINHAS_P[10], 750,362 );  
    draw_sprite(screen, BMP_LINHAS_P[11], 750,102 );  
    draw_sprite(screen, BMP_LINHAS_P[12], 750,436 );
    draw_sprite(screen, BMP_LINHAS_P[13], 750,410 );
    draw_sprite(screen, BMP_LINHAS_P[14], 750,128 );
    draw_sprite(screen, BMP_LINHAS_P[15], 750,308 );
    draw_sprite(screen, BMP_LINHAS_P[16], 750,231 );
    draw_sprite(screen, BMP_LINHAS_P[17], 750,70 );
    draw_sprite(screen, BMP_LINHAS_P[18], 750,462 );
    draw_sprite(screen, BMP_LINHAS_P[19], 750,152 );
   }
else   
if (valor_linha ==15)
   {
    draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    draw_sprite(screen, BMP_LINHAS[1], 8,153 );  
    draw_sprite(screen, BMP_LINHAS[2], 8,387 );  
    draw_sprite(screen, BMP_LINHAS[3], 7,63 );  
    draw_sprite(screen, BMP_LINHAS[4], 7,474 );  
    draw_sprite(screen, BMP_LINHAS[5], 7,121 );  
    draw_sprite(screen, BMP_LINHAS[6], 7,430 );  
    draw_sprite(screen, BMP_LINHAS[7], 7,201 );  
    draw_sprite(screen, BMP_LINHAS[8], 7,340 );  
    draw_sprite(screen, BMP_LINHAS[9], 7,312 );  
    draw_sprite(screen, BMP_LINHAS[10], 750,362 );  
    draw_sprite(screen, BMP_LINHAS[11], 750,102 );  
    draw_sprite(screen, BMP_LINHAS[12], 750,436 );
    draw_sprite(screen, BMP_LINHAS[13], 750,410 );
    draw_sprite(screen, BMP_LINHAS[14], 750,128 );
    draw_sprite(screen, BMP_LINHAS_P[15], 750,308 );
    draw_sprite(screen, BMP_LINHAS_P[16], 750,231 );
    draw_sprite(screen, BMP_LINHAS_P[17], 750,70 );
    draw_sprite(screen, BMP_LINHAS_P[18], 750,462 );
    draw_sprite(screen, BMP_LINHAS_P[19], 750,152 );
   }
else   
if (valor_linha ==25)
   {
    draw_sprite(screen, BMP_LINHAS[0], 8,273 );
    draw_sprite(screen, BMP_LINHAS[1], 8,153 );  
    draw_sprite(screen, BMP_LINHAS[2], 8,387 );  
    draw_sprite(screen, BMP_LINHAS[3], 7,63 );  
    draw_sprite(screen, BMP_LINHAS[4], 7,474 );  
    draw_sprite(screen, BMP_LINHAS[5], 7,121 );  
    draw_sprite(screen, BMP_LINHAS[6], 7,430 );  
    draw_sprite(screen, BMP_LINHAS[7], 7,201 );  
    draw_sprite(screen, BMP_LINHAS[8], 7,340 );  
    draw_sprite(screen, BMP_LINHAS[9], 7,312 );  
    draw_sprite(screen, BMP_LINHAS[10], 750,362 );  
    draw_sprite(screen, BMP_LINHAS[11], 750,102 );  
    draw_sprite(screen, BMP_LINHAS[12], 750,436 );
    draw_sprite(screen, BMP_LINHAS[13], 750,410 );
    draw_sprite(screen, BMP_LINHAS[14], 750,128 );
    draw_sprite(screen, BMP_LINHAS[15], 750,308 );
    draw_sprite(screen, BMP_LINHAS[16], 750,231 );
    draw_sprite(screen, BMP_LINHAS[17], 750,70 );
    draw_sprite(screen, BMP_LINHAS[18], 750,462 );
    draw_sprite(screen, BMP_LINHAS[19], 750,152 );
   }

}


