#include <unistd.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

/*
 * BOTÕES
 * LEGENDA ->
 * BTN 1 SUBIR
 * BTN 2 - DESCER
 * BTN 3 - SELECIONAR
 * BTN 4 - VOLTAR
 * 0 - > SELECIONADO
 * 1 - > NÃO SELECIONADO
 * B1 	B2 	B3 	B4
 * 0	0	0	0 == IGNORADO
 * 0	0	0	1 == IGNORADO
 * 0	0	1	0 == IGNORADO
 * 0	0	1	1 == IGNORADO
 * 0	1	0	0 == IGNORADO
 * 0	1	0	1 == IGNORADO
 * 0	1	1	0 == IGNORADO
 * 0	1	1	1 == B1 SELECIONADO
 * 1	0	0	0 == IGNORADO
 * 1	0	0	1 == IGNORADO
 * 1	0	1	0 == IGNORADO
 * 1	0	1	1 == B2 SELECIONADO
 * 1	1	0	0 == IGNORADO
 * 1	1	0	1 == SELECIONAR
 * 1	1	1	0 == VOLTAR, SÓ TEM AÇÃO SE SUBMENU ATIVO
 * 1	1	1	1  == NENHUM BOTÃO SELECIONADO
 *
 * 0000
 * 0001 - 1
 * 0010 - 2
 * 0100 - 4
 * 1000 - 8
 */

void init() { //Método para a inicialização
	usleep(15000);
	ALT_CI_LCD(0,0x38);

	usleep(4100);
	ALT_CI_LCD(0,0x38);

	usleep(100);
	ALT_CI_LCD(0,0x38);

	usleep(5000);
	ALT_CI_LCD(0,0x38);

	usleep(100);
	ALT_CI_LCD(0,0x08);

	usleep(100);
	ALT_CI_LCD(0,0x0C);

	usleep(100);
	ALT_CI_LCD(0,0x06);

	usleep(100);
	ALT_CI_LCD(0,0x02);

	usleep(2000);
	ALT_CI_LCD(0,0x01);

	usleep(2000);
}

void print(char m[16], int n) {
	usleep(2000);
	ALT_CI_LCD(0,0x02);

	usleep(2000);
	ALT_CI_LCD(0,0x01);

	for(int i = 0; i < n; i++) {
		usleep(2000);
		ALT_CI_LCD(1,m[i]);
	}

	usleep(2000);
	ALT_CI_LCD(0,0x00);
}

int main() {
	init();

	char opcoes[5][7] = {"Menu 01", "Menu 02", "Menu 03", "Menu 04", "Menu 05"};
	char submenu[5][11] = {"Mensagem 01", "Mensagem 02", "Mensagem 03", "Mensagem 04", "Mensagem 05"};

	int isSubMenu = 0;
	int estadoBotao = 0;
	int estado = 0;
	int menu = 0;

	while(1){
		estadoBotao = IORD(PI_BASE,0);
		usleep(100000);

		switch(estadoBotao){
			case 7:
				if(!isSubMenu) {
					if(menu < 4)
						menu += 1;
					else
						menu = 1;

					estado = 1;
				}

				break;

			case 11:
				if(!isSubMenu){
					if(menu > 0)
						menu -= 1;
					else
						menu = 4;

					estado = 1;
				}

				break;

			case 13:
				if(!isSubMenu) {
					isSubMenu = 1;
					estado = 1;
				}

				break;

			case 14:
				if(isSubMenu) {
					isSubMenu = 0;
					estado = 1;
				}

				break;
		}

		if(estado) {
			if(isSubMenu) {
				print(submenu[menu], 11);
				IOWR(PO_BASE, 0, menu);
			}else {
				print(opcoes[menu], 7);
				IOWR(PO_BASE, 0, 15);
			}

			estado = 0;
		}
	}

	return 0;
}
