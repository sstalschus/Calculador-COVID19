#include <allegro.h>
#include <math.h>

//funções
void sair();

//Início da declaração para colisão
int colidir(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh);

//Variáveis Globais
int sai=0;
int width=1000;
int height=700;
int x=300,y=300;
int parte=0;
int menus[26] , i;
int sairr=0;
float idades[3];
float sexodoenca[4];
float resultado[2];


int main() {

    //Iniciação
	allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_color_depth(32);
	set_window_title("Calculadora COVID-19");
	set_close_button_callback(sair);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);

	//Carregando o ponteiro buffer
	BITMAP *buffer = create_bitmap(width, height);

	//Carregando o ponteiro fonte
	FONT* fontetest = load_font("midias/fonte/fonteteste.pcx", NULL , NULL);

	//Inserir imagens
	BITMAP *fundo=load_bitmap("midias/Imagens/fundo.bmp", NULL);
	BITMAP *fundod=load_bitmap("midias/Imagens/fundod.bmp", NULL);
	BITMAP *menuq=load_bitmap("midias/Imagens/menuq.bmp", NULL);
	BITMAP *sobre=load_bitmap("midias/Imagens/sobre.bmp", NULL);
	BITMAP *fundocalculadora=load_bitmap("midias/Imagens/fundocalculadora.bmp", NULL);
	BITMAP *menucalcular=load_bitmap("midias/Imagens/menucalcular.bmp", NULL);
	BITMAP *menusexo=load_bitmap("midias/Imagens/menusexo.bmp", NULL);
	BITMAP *simenao=load_bitmap("midias/Imagens/simenao.bmp", NULL);
	BITMAP *menuidade=load_bitmap("midias/Imagens/menuidade.bmp", NULL);
	BITMAP *menup=load_bitmap("midias/Imagens/menup.bmp", NULL);
    BITMAP *telaresultado=load_bitmap("midias/Imagens/telaresultado.bmp", NULL);

    //Inserir música
	SAMPLE *musicaf = load_sample("midias/musica/musicaf.wav");

	//Colocar música para tocar
	play_sample(musicaf, 100, 128,1000, 1);

	//preencher o vetor de menus sexo e idade de seleção com zero
	for(i=0;i<26;i++)menus[i]=0;
	for(i=0;i<4;i++)sexodoenca[i]=0;
	for(i=0;i<3;i++)idades[i]=0;

	while (!(sai || key[KEY_ESC] || sairr==1))
	{
		switch(parte)
		{
		//menu principal
		case 0:
		//Colocando a imagem que estava salva na pasta do projeto no plano de fundo
		draw_sprite(buffer, fundo , 0 , 0);
		//menu - começar
		if(colidir (mouse_x , mouse_y , 380 , 205 , 10/*mouse*/ , 10 , 180/*Tamanho mascara*/ , 90))
		{menus[0]=200; if(mouse_b == 1){parte = 1;}} else {menus[0]=0;}
		{masked_blit(menup , buffer , menus[0], 0 , 380 , 200 , 200 , 100 );}
		//menu - sobre
		if(colidir (mouse_x , mouse_y , 380 , 305 , 10/*mouse*/ , 10 , 180/*Tamanho mascara*/ , 90))
		{menus[1]=200; if(mouse_b==1){parte=2;}} else {menus[1]=0; }
		{masked_blit(menup , buffer , menus[1], 100 , 380 , 300 , 200 , 100 );}
		//menu - sair
		if(colidir (mouse_x , mouse_y , 380 , 405 , 10/*mouse*/ , 10 , 180/*Tamanho mascara*/ , 90))
		{menus[2]=200; if(mouse_b==1){sairr=mouse_b;}} else {menus[2]=0; }
		{masked_blit(menup , buffer , menus[2], 200 , 380 , 400 , 200 , 100 );}
			break;

		//Calculadora
		case 1:
		//imagem de fundo da calculadora
		draw_sprite(buffer, fundocalculadora , 0 , 0);

		//botão de menu para retornar ao menu
		if(colidir (mouse_x , mouse_y , 450 , 0 , 10/*mouse*/ , 10 , 80/*Tamanho mascara*/ , 40))
		{menus[4]=100; if(mouse_b == 1){parte = 0; for(i=4; i<26 ; i++){menus[i]=0;}}} else {menus[4]=0;}
		{masked_blit(menuq , buffer , menus[4], 0 , 450 , 0 , 100 , 50 );}

		//botão de calcular para calcular o resultado
		if(colidir (mouse_x , mouse_y , 450 , 650 , 10/*mouse*/ , 10 , 80/*Tamanho mascara*/ , 40))
		{menus[3]=100; if(mouse_b == 1){parte = 3;}} else {menus[3]=0;}
		{masked_blit(menucalcular , buffer , menus[3], 0 , 450 , 650 , 100 , 50 );}

		//menu do sexo masculino e feminino
		//if(colidir (mouse_x , mouse_y , 125 , 222 , 10 , 10 , 110 , 40)){menus[5]=120;}
		if(mouse_b == 1 && colidir (mouse_x , mouse_y , 125 , 222 , 10 , 10 , 110 , 40) && menus[5]==0){menus[5]=120; if(menus[6]==120)menus[6]=0; if(menus[5]==120){sexodoenca[0]=1.0;}}
		masked_blit(menusexo , buffer , menus[5], 0 , 125 , 222 , 120 , 50 );
		if(menus[6]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 255 , 222 , 10 , 10 , 110 , 40)){menus[6]=120; if(menus[5]==120)menus[5]=0; if(menus[6]==120){sexodoenca[0]=0.0;}}
		masked_blit(menusexo , buffer , menus[6], 50 , 255 , 222 , 120 , 50 );

		//menu do sim e não - diabetes
		if(menus[8]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 650 , 222 , 10 , 10 , 90 , 40)){menus[8]=50; if(menus[8]==50){menus[23]=0; sexodoenca[1]=1.0;} }
		masked_blit(simenao , buffer , 0 , menus[8] , 650 , 222 , 100 , 50 );
		if(menus[23]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 765 , 222 , 10 , 10 , 90 , 40)){menus[23]=50; if(menus[23]==50){menus[8]=0; sexodoenca[1]=0.0;}}
		masked_blit(simenao , buffer , 100, menus[23] , 765 , 222 , 100 , 50 );

		//menu do sim e não - hipertensão
		if(menus[9]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 650 , 325 , 10 , 10 , 90 , 40)){menus[9]=50;if(menus[9]==50){menus[24]=0; sexodoenca[2]=1.0;}}
		masked_blit(simenao , buffer ,0 , menus[9] , 650 , 325 , 100 , 50 );
		if(menus[24]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 765 , 325 , 10 , 10 , 90 , 40)){menus[24]=50;if(menus[24]==50){menus[9]=0; sexodoenca[2]=0.0;}}
		masked_blit(simenao , buffer , 100 , menus[24] , 765 , 325 , 100 , 50 );

		//menu do sim e não - obesidade
		if(menus[10]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 650 , 428 , 10 , 10 , 90 , 40)){menus[10]=50;if(menus[10]==50){menus[25]=0; sexodoenca[3]=1.0;} }
		masked_blit(simenao , buffer , 0 ,  menus[10] , 650 , 428 , 100 , 50 );
		if(menus[25]==0 && mouse_b == 1 && colidir (mouse_x , mouse_y , 765 , 428 , 10 , 10 , 90 , 40)){menus[25]=50;if(menus[25]==50){menus[10]=0; sexodoenca[3]=0.0;} }
		masked_blit(simenao , buffer , 100 ,  menus[25] , 765 , 428 , 100 , 50 );

		//menu de idades
		//-1
		if(mouse_b==1 && colidir (mouse_x , mouse_y , 90 , 330 , 10, 10 , 95, 45) && menus[11]==0)
		{menus[11]=100; if(menus[11]=100){ idades[0]=1.0; for(i=12;i<23;i++){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[11], 0 , 90 , 330 , 100 , 50 );

		//1 à 10
		if(colidir (mouse_x , mouse_y , 205 , 330 , 10, 10 , 95, 45) && mouse_b==1 && menus[12]==0)
		{menus[12]=100; if(menus[12]=100){ idades[0]=5.0; for(i=13;i<23;i++){menus[i]=0;} for(i=11;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[12], 50 , 205 , 330 , 100 , 50 );

		//11 à 20
		if(colidir (mouse_x , mouse_y , 320 , 330 , 10, 10 , 95, 45) && mouse_b==1 && menus[13]==0)
		{menus[13]=100; if(menus[13]==100){idades[0]=15.0; for(i=14;i<23;i++){menus[i]=0;} for(i=12;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[13], 100 , 320 , 330 , 100 , 50 );

		//21 à 30
		if(colidir (mouse_x , mouse_y , 90 , 395 , 10, 10 , 95, 45) && mouse_b==1 && menus[14]==0)
		{menus[14]=100; if(menus[14]==100){idades[0]=25.0; for(i=15;i<23;i++){menus[i]=0;} for(i=13;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[14], 150 , 90 , 395 , 100 , 50 );

		//31 à 40
		if(colidir (mouse_x , mouse_y , 205 , 395 , 10, 10 , 95, 45) && mouse_b==1 && menus[15]==0)
		{menus[15]=100; if(menus[15]=100){idades[0]=35.0; for(i=16;i<23;i++){menus[i]=0;} for(i=14;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[15], 200 , 205 , 395 , 100 , 50 );

		//41 à 50
		if(colidir (mouse_x , mouse_y , 320 , 395 , 10, 10 , 95, 45) && mouse_b==1 && menus[16]==0)
		{menus[16]=100; if(menus[16]=100){idades[0]=45.0; for(i=17;i<23;i++){menus[i]=0;} for(i=15;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[16], 250 , 320 , 395 , 100 , 50 );

		//51 à 60
		if(colidir (mouse_x , mouse_y , 90 , 460 , 10, 10 , 95, 45) && mouse_b==1 && menus[17]==0)
		{menus[17]=100; if(menus[17]=100){idades[0]=60.0; for(i=18;i<23;i++){menus[i]=0;} for(i=16;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[17], 300 , 90 , 460 , 100 , 50 );

		//61 à 70
		if(colidir (mouse_x , mouse_y , 205 , 460 , 10, 10 , 95, 45) && mouse_b==1 && menus[18]==0)
		{menus[18]=100; if(menus[18]=100){ idades[0]=65.0; for(i=19;i<23;i++){menus[i]=0;} for(i=17;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[18], 350 , 205 , 460 , 100 , 50 );

		//71 à 80
		if(colidir (mouse_x , mouse_y , 320 , 460 , 10, 10 , 95, 45) && mouse_b==1 && menus[19]==0)
		{menus[19]=100; if(menus[19]=100){idades[0]=75.0; for(i=20;i<23;i++){menus[i]=0;} for(i=18;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[19], 400 , 320 , 460 , 100 , 50 );

		//81 à 90
		if(colidir (mouse_x , mouse_y , 90 , 525 , 10, 10 , 95, 45) && mouse_b==1 && menus[20]==0)
		{menus[20]=100; if(menus[20]=100){idades[0]=85.0; for(i=21;i<23;i++){menus[i]=0;} for(i=19;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[20], 450 , 90 , 525 , 100 , 50 );

		//91 à 100
		if(colidir (mouse_x , mouse_y , 205 , 525 , 10, 10 , 95, 45) && mouse_b==1 && menus[21]==0)
		{menus[21]=100; if(menus[21]=100){idades[0]=95.0;  for(i=22;i<23;i++){menus[i]=0;} for(i=20;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[21], 500 , 205 , 525 , 100 , 50 );

		//100+
		if(colidir (mouse_x , mouse_y , 320 , 525 , 10, 10 , 95, 45) && mouse_b==1 && menus[22]==0)
		{menus[22]=100; if(menus[22]=100){idades[0]=100.0; for(i=21;i>10;i--){menus[i]=0;}}}
		masked_blit(menuidade , buffer , menus[22], 550 , 320 , 525 , 100 , 50 );


 			break;

		 //Sobre
		case 2:
		//plano de fundo
		draw_sprite(buffer, fundod , 0 , 0);
		//botão de menu para retornar ao menu
		if(colidir (mouse_x , mouse_y , 450 , 0 , 10/*mouse*/ , 10 , 80/*Tamanho mascara*/ , 40))
		{menus[4]=100; if(mouse_b == 1){parte = 0;}} else {menus[4]=0;}
		{masked_blit(menuq , buffer , menus[4], 0 , 450 , 0 , 100 , 50 );}


		//Painel para o sobre
		draw_sprite(buffer, sobre , 150 , 80);

			break;

		//resultado
		case 3:
        //Fundo de tela
        draw_sprite(buffer, telaresultado , 0 , 0);

		//botão de menu para retornar ao menu
		if(colidir (mouse_x , mouse_y , 450 , 0 , 10/*mouse*/ , 10 , 80/*Tamanho mascara*/ , 40))
		{menus[4]=100; if(mouse_b == 1){parte = 0; for(i=4; i<26 ; i++){menus[i]=0;}}} else {menus[4]=0;}
		{masked_blit(menuq , buffer , menus[4], 0 , 450 , 0 , 100 , 50 );}

		//fórmula para calculo das chances de morrer
		if(idades[0]>60)idades[1]=1; //para definir idoso

		resultado[0]=1.0/(1.0+(pow(2.71828183 , (-1.0*(-7.09
		+0.4456* sexodoenca[0] + 0.058* idades[0] + 0.9866*sexodoenca[1]+0.9176*sexodoenca[2]
		+0.5628*idades[1] + 1.6053*sexodoenca[3])))));

		resultado[0]=resultado[0]*100;

        resultado[1]=100.00-resultado[0];

        //saída das chances de morrer
		textprintf_centre_ex(buffer , fontetest , 495 ,515 , makecol(255 ,255 ,255), -1 , "%.4f%%" , resultado[0]);

        //saída chances de sobreviver
		textprintf_centre_ex(buffer , fontetest , 495 ,170 , makecol(255 ,255 ,255), -1 , "%.4f%%" , resultado[1]);

			break;

		}

		//Declarando mouse
		show_mouse(buffer);

		draw_sprite(screen, buffer, 0, 0);
		rest(0);
		clear(buffer);

	}

	//Finalização
	destroy_bitmap(buffer);
	destroy_bitmap(fundo);
	destroy_bitmap(simenao);
	destroy_sample(musicaf);
	destroy_bitmap(sobre);
	destroy_bitmap(fundocalculadora);
	destroy_bitmap(menucalcular);
	destroy_bitmap(menusexo);
	destroy_bitmap(menuidade);
	destroy_bitmap(menup);
	destroy_font(fontetest);
    destroy_bitmap(telaresultado);

	return 0;
}
END_OF_MAIN();
void sair(){sai= 1;}
END_OF_FUNCTION(sair);

//Fim da declaração de colisão
int colidir(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh){
if(Ax + Aw > Bx && Ax < Bx + Bw && Ay + Ah > By && Ay < By + Bh)return 1;

return 0;
}
