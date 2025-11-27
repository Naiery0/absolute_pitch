#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>  // setlocale л熱蒂 餌辨ж晦 嬪п!
#define toner 1.059 // 擠薑 褻瞰= 033(0螟紫)縑憮 12廓培ж賊 1螟紫 24廓 培ж賊 2螟紫 
#define Cs 1 //紫#
#define D 2  //溯
#define Ds 3  //溯#
#define E 4  //嘐
#define F 5  //だ
#define	Fs 6  //だ#
#define G 7 //樂
#define Gs 8  //樂#
#define A 9  //塭
#define As 10  //塭#
#define B 11  //衛
#define OC 12  //螟顫粽UP
#define n025 125//16碟擠ル
#define n05 250//8碟擠ル
#define n1 500//4碟擠ル
#define n2 1000//2碟擠ル
#define n4 2000//螞擠ル

void piano(int play,char key,int i, char[100]);
void sounding(float tc, float delay);
void rest(float delay);
void printGame(int heart, int score, char name[64]);
int randSound(int score);
void menuPrint();
int gameStart(struct rank* header);
void gameReady();
void addList(struct rank* header, int score, char name[64]);
void addRank(struct rank* header, int score, char name[64]);
void addFile(struct rank* header);
void readFile(struct rank* header);
void printFile(struct rank* header);
void pianoPrint(int oc, int dotPrint, int del, char key);
void pianoSheet(int oc, int dotPrint, int del, char key,int i,char name[100]);
void writeSheet();
void singSheet();
void clearNODE(struct rank* header);
typedef struct player {   
	char name[64];        
	int score;             
}player;
typedef struct rank {
	player data;
	struct rank* link;
}rank;
FILE* fpR;
FILE* fpW;
int rankLen = 0; 
/**/
int main() {
	//system("mode con:cols=60 lines=28|title Щ煎薛お 瞰渠擠馬");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	struct rank* head = (rank*)malloc(sizeof(player));
	head->link = NULL;
	float tone = 0;
	int tc = 0;//toneControl
	float delay = 0;
	char menuPick;
	readFile(head);
	system("mode con:cols=60 lines=28");

	while (1) {
		menuPrint();
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		menuPick = getch();
		if (menuPick == '1')
		{
			while (1) {
				int re = gameStart(head);
				if (re == 49)continue;
				else if (re == 50)break;
			}
		}
		else if (menuPick == '2') {
			printFile(head);
		}
		else if (menuPick == '3') {
			piano(0, 0, 0, 0);
			system("mode con:cols=60 lines=28|title Щ煎薛お 瞰渠擠馬");
		}
		else if (menuPick == '4') {
			writeSheet();
		}
		else if (menuPick == '5') {
			singSheet();
		}
		else if (menuPick == '6') {
			clearNODE(head);
			break;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("        早﹥﹥早﹥﹥﹥早﹥﹥早﹥﹥﹥早﹥﹥早﹥﹥﹥早﹥﹥早\n");
	printf("        朴朴 朴 朴朴 朴 朴 朴朴 朴 朴朴 朴 朴 朴朴 朴 朴朴 朴 朴 朴朴 朴 朴 \n\n\n");
	printf("               Ｎ Щ煎斜極擊 謙猿м棲棻. Ｏ\n\n");
	return 0;
}

void menuPrint() {
	system("cls");
	printf("\n\n\n      ");
	printf("  早﹥﹥早﹥﹥﹥早﹥﹥早﹥﹥﹥早﹥﹥早﹥﹥﹥早﹥﹥早\n");
	printf("        朴朴 朴 朴朴 朴 朴 朴朴 朴 朴朴 朴 朴 朴朴 朴 朴朴 朴 朴 朴朴 朴 朴 \n\n");
	printf("                  Ｎ Project~ 瞰渠擠馬 Ｏ\n\n");
	printf("    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛                       MENU                     弛\n");
	printf("    弛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      1. 瞰渠擠馬 纔蝶お                        弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      2. 瞰渠擠馬 楨韁                          弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      3. 翱輿                                   弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      4. 喬擠ж晦                               弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      5. 學爾 營儅ж晦                          弛\n");
	printf("    弛                                                弛\n");
	printf("    弛      6. 謙猿                                   弛\n");
	printf("    弛                                                弛\n");
	printf("    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}
void sounding(float tc, float delay) {
	//float tone = pow(toner, tc);
	//int x = 32.7 * tone;
	//int tuning = (x - 20) / 38;
	//x = x + tuning;
	//Beep(x, delay);

	// GPT陛 ぅ棚 棻衛 п 遽 勒等 澀 蜃朝霞 賅葷	
	int midi = 24 + tc;

	double freq = 440.0 * pow(2.0, (midi - 69) / 12.0);

	if (freq < 37) freq = 37;
	if (freq > 32767) freq = 32767;

	Beep((DWORD)(freq + 0.5), delay);
}
void rest(float delay) {
	Sleep(delay);
	return;
}
void DB() {
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //delete buffer
	return;
}
int randSound(int score) {
	while (1) {
		srand(time(NULL));
		int d = 500;
		if (score > 100)d = 300;
		if (score > 250)d = 200;
		if (score > 400)d = 100;
		if (score > 500)d = 70;
		
		if ((rand() % 12 + 1) == 12) {
			printf("  Ｎ");
			sounding(OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 97;
		}
		else if ((rand() % 12 + 1) == 1) {
			printf("  Ｎ");
			sounding(Cs + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 119;
		}
		else if ((rand() % 12 + 1) == 2) {
			printf("  Ｎ");
			sounding(D + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 115;
		}
		else if ((rand() % 12 + 1) == 3) {
			printf("  Ｎ");
			sounding(Ds + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 101;
		}
		else if ((rand() % 12 + 1) == 4) {
			printf("  Ｎ");
			sounding(E + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 100;
		}
		else if ((rand() % 12 + 1) == 5) {
			printf("  Ｎ");
			sounding(F + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 102;
		}
		else if ((rand() % 12 + 1) == 6) {
			printf("  Ｎ");
			sounding(Fs + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 116;
		}
		else if ((rand() % 12 + 1) == 7) {
			printf("  Ｎ");
			sounding(G + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 103;
		}
		else if ((rand() % 12 + 1) == 8) {
			printf("  Ｎ");
			sounding(Gs + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 121;
		}
		else if ((rand() % 12 + 1) == 9) {
			printf("  Ｎ");
			sounding(A + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 104;
		}
		else if ((rand() % 12 + 1) == 10) {
			printf("  Ｎ");
			sounding(As + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 117;
		}
		else if ((rand() % 12 + 1) == 11) {
			printf("  Ｎ");
			sounding(B + OC * 3, d);
			printf("\b\b\b\b薑港擎?");
			return 116;
		}
		else {
			printf("煎註醞.");
			Sleep(333);
			printf(".");
			Sleep(333);
			printf(".");
			Sleep(333);
			printf("\b\b\b\b\b\b\b\b\b");
			printf("         ");
			printf("\b\b\b\b\b\b\b\b\b");
			continue;
		}
	}
	return;
}
void printGame(int heart, int score, char name[64]) {
	system("cls");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	if (heart == 3)printf("     Ⅵ Ⅵ Ⅵ");
	else if (heart == 2)printf("     Ⅵ Ⅵ   ");
	else if (heart == 1)printf("     Ⅵ      ");
	else if (heart == 0)printf("             ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("                                 SCORE:%d\n\n\n", score);
	printf("     Player : %-33s'A'=紫\n", name);
	printf("    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛   弛  弛   弛    弛    弛   弛  弛   弛  弛   弛    弛\n");
	printf("    弛    弛 W 弛  弛 E 弛    弛    弛 T 弛  弛 Y 弛  弛 U 弛    弛\n");
	printf("    弛    戌式式式戎  戌式式式戎    弛    戌式式式戎  戌式式式戎  戌式式式戎    弛\n");
	printf("    弛      弛      弛      弛      弛      弛      弛      弛\n");
	printf("    弛      弛      弛      弛      弛      弛      弛      弛\n");
	printf("    弛   A  弛   S  弛   D  弛   F  弛   G  弛   H  弛   J  弛\n");
	printf("    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n                          ");

	return;
}
void gameReady() {
	system("cls");
	printf("\n\n\n\n");
	printf("               瞰渠擠馬 纔蝶お蒂 衛濛м棲棻.\n\n\n\n\n\n\n\n");
	printf("               2~8濠曖 棣啻歜擊 殮溘п輿撮蹂.\n\n\n");
	printf("              棣啻歜 : ");
	return;
}
int gameStart(struct rank*header) {
	int score = 0;
	int heart = 3;
	char anser;
	char qz;
	char choise = 0;
	char name[64];
	while (1) {
		int nameLen = 0;
		gameReady();
		scanf("%s", name);
		for (int i = 0; name[i]; i++) {
			if (name[i] & 0x80)i++;
			nameLen++;
		}
		if (nameLen < 2 || nameLen>8) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n                 螢夥腦雖 彊擎 ⑽衝殮棲棻.\n\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			system("pause");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			getch();
		}
		else break;
	}
	printGame(heart, score, name);
	printf("  3\b\b\b");
	sounding(50, 200);
	Sleep(800);
	printf("  2\b\b\b");
	sounding(50, 200);
	Sleep(800);
	printf("  1\b\b\b");
	sounding(50, 200);
	Sleep(800);
	while (1) {
		printGame(heart, score, name);
		qz = randSound(score);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		anser = getch();
		printf("\b\b\b\b\b\b\b\b\b");
		if (anser & 0x80) {
			getch();
			printf("\b\b\b\b");
			printf("艙橫蒂 殮溘ж撮蹂.\n\n     ");
			system("pause");
			printGame(heart, score, name);
			printf("  3\b\b\b");
			sounding(50, 200);
			Sleep(800);
			printf("  2\b\b\b");
			sounding(50, 200);
			Sleep(800);
			printf("  1\b\b\b");
			sounding(50, 200);
			Sleep(800);
			continue;
		}
		if (qz == anser) {
			printf("         ");
			printf("\b\b\b\b\b\b\b\b\b");
			score = score + 10;
			printf("   薑港!", score);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b");
			printf("      ");
			printf("\b\b\b\b\b\b\b\b\b");
		}
		else {
			qz = qz - 32;
			printf("\b");
			printf("雄! '%c'殮棲棻! ", qz);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b");
			printf("      ");
			printf("\b\b\b\b\b\b\b");
			heart--;
		}
		if (heart == 0) {
			if(score>0)addList(header, score, name);
			printGame(heart, score, name);
			printf("\bGAME OVER\n\n");
			printf("                      1. 棻衛 衛濛\n");
			printf("                      2. 詭景煎 檜翕");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			while ((choise = getch()) != '1') {
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				if (choise == '2')break;
			}break;
		}
	}
	return choise;
}
void piano(int play, char key,int i,char name[100]) {
	int oc = 3;
	int delay = 500;
	int del=0;
	int dela=4;
	char keyP[3];
	if (play == 2)fpR = fopen(name, "r");
	while (key != 'p') {
		if (play == 1) {
			pianoSheet(oc - 2, del, dela, key, i, name);
			fpW = fopen(name, "a");
			DB();
			key = getch();
			if (key & 0x80) {
				printf("\n\n\      ");
				printf("艙橫蒂 殮溘ж撮蹂.\n\n     ");
				system("pause");
				continue;
			}
			i++;
			fprintf(fpW, "%c ", key);
			fclose(fpW);
			if (key == 'p') {
				system("cls");
				printf("\n\n\n\n");
				printf("               學爾蒂 盪濰ц蝗棲棻.\n\n\n\n\n      ");
				system("cls");
				system("mode con:cols=60 lines=28|title Щ煎薛お 瞰渠擠馬");
				break;
			}
		}
		else if (play == 0) {
			pianoPrint(oc - 2, del, dela, key);
			DB();
			key = getch();
			pianoPrint(oc - 2, del, dela, key);
			if (key & 0x80) {
				getch();
				printf("\b\b\b\b\b\b\b\b      ");
				printf("艙橫蒂 殮溘ж撮蹂.\n\n     ");
				system("pause");
				pianoPrint(oc - 2, del, dela, key);
				continue;
			}
		}
		else if (play == 2) {
			pianoSheet(oc - 2, del, dela, key, i, name);
			fscanf(fpR, "%s ", keyP);
			if (strcmp(keyP, "a") == 0)key = 'a';
			else if (strcmp(keyP, "w") == 0)key = 'w';
			else if (strcmp(keyP, "s") == 0)key = 's';
			else if (strcmp(keyP, "e") == 0)key = 'e';
			else if (strcmp(keyP, "f") == 0)key = 'f';
			else if (strcmp(keyP, "g") == 0)key = 'g';
			else if (strcmp(keyP, "t") == 0)key = 't';
			else if (strcmp(keyP, "d") == 0)key = 'd';
			else if (strcmp(keyP, "y") == 0)key = 'y';
			else if (strcmp(keyP, "h") == 0)key = 'h';
			else if (strcmp(keyP, "u") == 0)key = 'u';
			else if (strcmp(keyP, "j") == 0)key = 'j';
			else if (strcmp(keyP, "`") == 0)key = '`';
			else if (strcmp(keyP, ";") == 0)key = ';';
			else if (strcmp(keyP, "[") == 0)key = '[';
			else if (strcmp(keyP, "]") == 0)key = ']';
			else if (strcmp(keyP, "n") == 0)key = 'n';
			else if (strcmp(keyP, "m") == 0)key = 'm';
			else if (strcmp(keyP, "p") == 0){
				fclose(fpR);
				DB();
				system("cls");
				system("mode con:cols=60 lines=28|title Щ煎薛お 瞰渠擠馬");
				printf("\n\n\n\n");
				printf("                     翱輿陛 部陬蝗棲棻.\n\n\n\n\n\n\n            ");
				system("pause");
				return;
			}
		}
		if (key == 'n') {
			if (delay == n025) {
				continue;
			}
			if (delay == n4) { delay = n2; dela = 2; }
			else if (delay == n2) { delay = n1; dela = 4; }
			else if (delay == n1) { delay = n05; dela = 8; }
			else if (delay == n05) { delay = n025; dela = 16; }
			if (play == 1||play == 2) pianoSheet(oc - 2, del, dela, key, i, name);
			else
			pianoPrint(oc - 2, del, dela, key);
		}
		else if (key == 'm') {
			if (delay == n4) {
				continue;
			}
			if (delay == n2) { delay = n4; dela = 1; }
			else if (delay == n1) { delay = n2; dela = 2; }
			else if (delay == n05) { delay = n1; dela = 4; }
			else if (delay == n025) { delay = n05; dela = 8; }
			if (play == 1 || play == 2) pianoSheet(oc - 2, del, dela, key, i, name);
			else
			pianoPrint(oc - 2, del, dela, key);
		}
		else if (key == ']') {
			if (oc == 6) {
				continue;
			}
			oc++;
			if (play == 1 || play == 2) pianoSheet(oc - 2, del, dela, key, i, name);
			else
			pianoPrint(oc - 2, del, dela, key);
		}
		else if (key == '[') {
			if (oc == 2) {
				continue;
			}
			oc--;
			if (play == 1 || play == 2) pianoSheet(oc - 2, del, dela, key, i, name);
			else
			pianoPrint(oc - 2, del, dela, key);
		}
		else if (key == ';') {
			if (del == 0)del = 1;
			else if (del == 1)del = 0;
			if (play == 1 || play == 2) pianoSheet(oc - 2, del, dela, key, i, name);
			else
			pianoPrint(oc - 2, del, dela, key);
		}
		else if (key == 'a') {
			if(del == 1)sounding(OC * oc, delay*1.5);
			else sounding(OC * oc, delay);
		}
		else if (key == 'w') {
			if (del == 1)sounding(Cs + OC * oc, delay * 1.5);
			else sounding(Cs + OC * oc, delay);
		}
		else if (key == 's') {
			if (del == 1)sounding(D + OC * oc, delay * 1.5);
			else sounding(D + OC * oc, delay);
		}
		else if (key == 'e') {
			if (del == 1)sounding(Ds + OC * oc, delay * 1.5);
			else sounding(Ds + OC * oc, delay);
		}
		else if (key == 'd') {
			if (del == 1)sounding(E + OC * oc, delay * 1.5);
			else sounding(E + OC * oc, delay);
		}
		else if (key == 'f') {
			if (del == 1)sounding(F + OC * oc, delay * 1.5);
			else sounding(F + OC * oc, delay);
		}
		else if (key == 't') {
			if (del == 1)sounding(Fs + OC * oc, delay * 1.5);
			else sounding(Fs + OC * oc, delay);
		}
		else if (key == 'g') {
			if (del == 1)sounding(G + OC * oc, delay * 1.5);
			else sounding(G + OC * oc, delay);
		}
		else if (key == 'y') {
			if (del == 1)sounding(Gs + OC * oc, delay * 1.5);
			else sounding(Gs + OC * oc, delay);
		}
		else if (key == 'h') {
			if (del == 1)sounding(A + OC * oc, delay * 1.5);
			else sounding(A + OC * oc, delay);
		}
		else if (key == 'u') {
			if (del == 1)sounding(As + OC * oc, delay * 1.5);
			else sounding(As + OC * oc, delay);
		}
		else if (key == 'j') {
			if (del == 1)sounding(B + OC * oc, delay * 1.5);
			else sounding(B + OC * oc, delay);
		}
	}
	return;
}
void addList(struct rank* header, int score, char name[64]) {
	if (header->link == NULL) {
		addRank(header, score, name);
		addFile(header);
	}
	else if (header->link != NULL) {
		rank* curr = header->link;
		rank* curr2 = header;
		while (curr != NULL) {
			if (score > curr->data.score) {
				if (curr->link == NULL) {
					addRank(header, score, name);
					addFile(header);
					return;
				}
				else if (curr->data.score > curr->link->data.score) {
					addRank(header, score, name);
					addFile(header);
					return;
				}
			}
			else if (score <= curr->data.score) {

				for (int i = 0; i < 10; i++) {
					if (curr == NULL) {
						addRank(curr2, score, name);
						addFile(header);
						return;
					}
					else if (curr->data.score > score) {
						curr = curr->link;
						curr2 = curr2->link;
						continue;
					}
					else
					{
						addRank(curr2, score, name);
						addFile(header);
						return;
					}
				}
				break;
			}
			curr = curr->link;
			if (curr == NULL)break;
		}
	}
	return;
}
void addRank(struct rank* header, int score, char name[64]) {
	struct rank* list = malloc(sizeof(rank));
	rank* curr = header->link;
	list->link = header->link;
	strcpy(list->data.name, name);
	list->data.score = score;
	header->link = list;
	rankLen++;
	if (rankLen > 10) {
		while (curr->link->link != NULL) {
			curr = curr->link;
		}
		curr->link = curr->link->link;
		curr = curr->link;
		free(curr);
		rankLen = 10;
		return;
	}
	return;
}
void addFile(struct rank* header) {
	int player = rankLen;
	rank* curr = header->link;
	fpW = fopen("Player.txt", "w");
	fprintf(fpW, "%d", rankLen);
	fclose(fpW);
	fpW = fopen("GameRank.txt", "w");
	while (player != 0) {
		fprintf(fpW, "%s %d\n", curr->data.name, curr->data.score);
		curr = curr->link;
		player--;
	}
	fclose(fpW);
	return;
}
void readFile(struct rank* header) {
	int player;
	int score;
	wchar_t name[64];
	setlocale(LC_ALL, "ko-KR");
	if ((fpR = fopen("Player.txt", "r")) == NULL)return;
	fscanf(fpR, "%d", &player);
	fclose(fpR);
	if ((fpR = fopen("GameRank.txt", "r")) == NULL)return;
	while (player != 0) {
		fscanf(fpR, "%s %d\n", name, &score);
		addList(header, score, name);
		player--;
	}
	fclose(fpR);
	return;
}
void printFile(struct rank* header) {
	if (rankLen == 1||rankLen == 0) system("mode con:cols=60 lines=12");
	if (rankLen == 2) system("mode con:cols=60 lines=14");
	if (rankLen == 3) system("mode con:cols=60 lines=16");
	if (rankLen == 4) system("mode con:cols=60 lines=18");
	if (rankLen == 5) system("mode con:cols=60 lines=20");
	if (rankLen == 6) system("mode con:cols=60 lines=22");
	if (rankLen == 7) system("mode con:cols=60 lines=24");
	if (rankLen == 8) system("mode con:cols=60 lines=26");
	if (rankLen == 9) system("mode con:cols=60 lines=28");
	if(rankLen==10) system("mode con:cols=60 lines=30");
	int ranking=1;
	int tie = 1;
	int temp=1;
	rank* curr = header->link;
	system("cls");
	printf("\n\n    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛                     RANKING                    弛\n");
	printf("    弛式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式弛\n");
	printf("    弛                                                弛\n");
	while (curr != NULL) {
		if (temp != curr->data.score&&tie!=1)ranking=tie;
		tie++;
		printf("    弛   %4d嬪%19s%16d    弛\n", ranking, curr->data.name, curr->data.score);
		printf("    弛                                                弛\n");
		temp = curr->data.score;
		curr = curr->link;
	}
	if (rankLen == 0) printf("    弛                       - -                      弛\n");
	printf("    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	system("pause");
	system("mode con:cols=60 lines=28");
	return;
}
void pianoPrint(int oc, int dotPrint, int del,char key) {
	system("mode con:cols=90 lines=22");
	system("cls");
	char* dela = "\0";
	char* dot = "\0";
	if (dotPrint == 1)dot = "薄";
	else dot = " ";
	if (del == 1)dela = "螞";
	if (del == 2)dela = "2碟";
	if (del == 4)dela = "4碟";
	if (del == 8)dela = "8碟";
	if (del == 16)dela = "16碟";
	char a[3] = "A", w[3] = "W", s[3] = "S", e[3] = "E", d[3] = "D", f[3] = "F", g[3] = "G", t[3] = "T", y[3] = "Y", h[3] = "H", u[3] = "U", j[3] = "J";
	if (key == 'a')strcpy(a, "≠");
	else if (key == 'w')strcpy(w,"≠");
	else if (key == 's')strcpy(s,"≠");
	else if (key == 'e')strcpy(e,"≠");
	else if (key == 'd')strcpy(d,"≠");
	else if (key == 'f')strcpy(f,"≠");
	else if (key == 't')strcpy(t,"≠");
	else if (key == 'g')strcpy(g,"≠");
	else if (key == 'h')strcpy(h,"≠");
	else if (key == 'y')strcpy(y,"≠");
	else if (key == 'u')strcpy(u,"≠");
	else if (key == 'j')strcpy(j,"≠");
	printf("\n\n");
	printf("\n    Ｍ=120                                       \n");
	printf("    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     p -> 詭景煎 給嬴陛晦\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     [,] -> 螟顫粽 褻瞰\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     n,m -> 夢濠 褻瞰\n");
	printf("    弛     弛 %2s 弛  弛 %2s 弛    弛    弛 %2s 弛  弛 %2s 弛  弛 %2s 弛     弛\n",w,e,t,y,u);
	printf("    弛     戌式式式式戎  戌式式式式戎    弛    戌式式式式戎  戌式式式式戎  戌式式式式戎     弛     ; -> 薄擠ル on/off\n");
	printf("    弛       弛       弛       弛       弛       弛       弛       弛\n");
	printf("    弛       弛       弛       弛       弛       弛       弛       弛     \n");
	printf("    弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛\n",a,s,d,f,g,h,j);
	printf("    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("     ⑷營 鼻鷓 : %d螟顫粽  %27s%4s擠ル\n\n", oc, dot, dela);
	return;
}
void pianoSheet(int oc, int dotPrint, int del,char key,int i, char name[100]) {
	system("mode con:cols=90 lines=22");
	system("cls");
	char* dela = "\0";
	char* dot = "\0";
	char keyP[3];
	if (dotPrint == 1)dot = "薄";
	else dot = " ";
	if (del == 1)dela = "螞";
	if (del == 2)dela = "2碟";
	if (del == 4)dela = "4碟";
	if (del == 8)dela = "8碟";
	if (del == 16)dela = "16碟";
	char a[3] = "A", w[3] = "W", s[3] = "S", e[3] = "E", d[3] = "D", f[3] = "F", g[3] = "G", t[3] = "T", y[3] = "Y", h[3] = "H", u[3] = "U", j[3] = "J";
	if (key == 'a')strcpy(a, "≠");
	else if (key == 'w')strcpy(w, "≠");
	else if (key == 's')strcpy(s, "≠");
	else if (key == 'e')strcpy(e, "≠");
	else if (key == 'd')strcpy(d, "≠");
	else if (key == 'f')strcpy(f, "≠");
	else if (key == 't')strcpy(t, "≠");
	else if (key == 'g')strcpy(g, "≠");
	else if (key == 'h')strcpy(h, "≠");
	else if (key == 'y')strcpy(y, "≠");
	else if (key == 'u')strcpy(u, "≠");
	else if (key == 'j')strcpy(j, "≠");
	printf("\n\n");
	printf("\n    Ｍ=120                                       \n");
	printf("    忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     p -> 詭景煎 給嬴陛晦\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     [,] -> 螟顫粽 褻瞰\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛\n");
	printf("    弛     弛    弛  弛    弛    弛    弛    弛  弛    弛  弛    弛     弛     n,m -> 夢濠 褻瞰\n");
	printf("    弛     弛 %2s 弛  弛 %2s 弛    弛    弛 %2s 弛  弛 %2s 弛  弛 %2s 弛     弛\n", w, e, t, y, u);
	printf("    弛     戌式式式式戎  戌式式式式戎    弛    戌式式式式戎  戌式式式式戎  戌式式式式戎     弛     ; -> 薄擠ル on/off\n");
	printf("    弛       弛       弛       弛       弛       弛       弛       弛\n");
	printf("    弛       弛       弛       弛       弛       弛       弛       弛     ` -> 蔑ル\n");
	printf("    弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛   %2s  弛\n", a, s, d, f, g, h, j);
	printf("    戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("     ⑷營 鼻鷓 : %d螟顫粽  %27s%4s擠ル\n\n", oc, dot, dela);
	printf("      ");
	if (i != 0) {
		fpR = fopen(name, "r");
		for (int j = 0; j != i; j++) {
			fscanf(fpR, "%s ", keyP);
			printf("%s ", keyP);
		}
		fclose(fpR);
	}
	return;
}
void writeSheet() { 
	system("cls");
	printf("\n\n\n\n");
	printf("                 學爾 檜葷擊 殮溘п輿撮蹂.\n\n\n\n\n\n\n\n");
	printf("             學爾 檜葷 : ");
	int i = 0;
	char name[50];
	char key;
	gets(name);
	strcat(name, ".txt");
	DB();
	piano(1, 0,0,name);
	return;
}
void singSheet() {
	system("cls");
	printf("\n\n\n\n");
	printf("              營儅й 學爾 檜葷擊 殮溘п輿撮蹂.\n\n\n\n\n\n\n\n");
	printf("            學爾 檜葷 : ");
	int i = 0;
	char name[50];
	char keyP[3];
	gets(name);
	strcat(name, ".txt");
	if ((fpR = fopen(name, "r")) == NULL) {
		system("cls");
		printf("\n\n\n\n");
		printf("             營儅ж溥朝 學爾陛 橈蝗棲棻.\n\n\n\n\n\n\n\n");
		system("pause");
		return;
	}
	fclose(fpR);
	piano(2,0,0,name);
	return;
}
void clearNODE(struct rank* header) {
	rank* clear = header->link;
	rank* LINK;
	while (clear != NULL) {
		LINK = clear->link;
		free(clear);
		clear = LINK;
	}
	return;
}