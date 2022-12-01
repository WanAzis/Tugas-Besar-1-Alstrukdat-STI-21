#include <stdio.h>
#include <stdlib.h>
#include "console.h"

array ListGame;
Queue QueueGame;
Stack HistoryGame;
arraymap ScoreBoardGame;
int fitur=1,mode=0;

/* Fitur-fitur pada BNMO */

void MENU(){
  printf("---------------|  MAIN MENU |---------------\n");
  printf("[1] START\n[2] LOAD <File Name>\n");
}
/* Tampilan awal mesin BNMO yang akan menampilkan pilihan START atau LOAD untuk playar */

void FITURE(){
  printf("-----------------------------------------------\n");
  printf("|  Ketik HELP untuk melihat penjelasan fitur  |\n");
  printf("-----------------------------------------------\n");
  printf("\nFitur pada BNMO yang bisa anda pilih :\n");
  printf(">> CREATE GAME\n");
  printf(">> LIST GAME\n");
  printf(">> DELETE GAME\n");
  printf(">> QUEUE GAME\n");
  printf(">> PLAY GAME\n");
  printf(">> SKIPGAME <n>\n");
  printf(">> HISTORY <n>\n");
  printf(">> RESET HISTORY\n");
  printf(">> SCOREBOARD\n");
  printf(">> RESET SCOREBOARD\n");
  printf(">> SAVE <File Name>\n");
  printf(">> HELP\n");
  printf(">> QUIT\n");
}
/* Perintah untuk menampilkan seluruh fitur BNMO yang dapat dipilih oleh user */

void CHOOSEMODE(int *mode, char *file){
  printf("Silahkan memilih mode START/LOAD <File Name>: "); STARTWORD();
  if(WordCompareString(currentWord, "START") && currentWord.Length==5){
    *mode=1;
  } else if (WordCompareString(currentWord, "LOAD")){
    ADVWORD();
    WordToString(currentWord, file);
    *mode=2;
  } else {
    printf("Ketikkan mode yang benar START/LOAD <File Name>\n\n");
  }
}
/* Memilih mode awal apakah player memilih START atau LOAD */

void STARTBNMO(){
  ListGame = Makearray(); CreateQueue(&QueueGame);
  CreateEmptystack(&HistoryGame); ScoreBoardGame = Makearraymap();
  char *fname = "..\\data\\config.txt";
  STARTWORDFILE(fname);
  int loop = currentWord.TabWord[0] - '0';
  ADVSENTENCE();
  while(loop--){
    InsertLast(&ListGame, currentWord);
    ADVSENTENCE();
  }
}
/* Memulai mesin BNMO dengan mengakses file konfigurasi default */

void LOADBNMO(char *fname){
  ListGame = Makearray(); CreateQueue(&QueueGame);
  CreateEmptystack(&HistoryGame); ScoreBoardGame = Makearraymap();
  Stack awal; CreateEmptystack(&awal);
  char file[25] = "../data/";
  ConcatString(file, fname);
  STARTWORDFILE(file);
  if (pita != NULL){
    int loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    } ADVSENTENCE();
    while(loop--){
      InsertLast(&ListGame, currentWord);
      ADVSENTENCE();
    } loop=0;
    for (int i = 0; i<currentWord.Length; i++){
      loop = (loop*10) + currentWord.TabWord[i]-'0';
    } ADVSENTENCE();
    while(loop--){
      Push(&awal, currentWord);
      ADVSENTENCE();
    } HistoryGame = Reversestack(&awal);
    keytype k; valuetype v; Map m;
    for (int j = 0; j<ListGame.Neff; j++){
      loop=0; CreateEmptymap(&m);
      for (int i = 0; i<currentWord.Length; i++){
        loop = (loop*10) + currentWord.TabWord[i]-'0';
      }
      while(loop--){
        ADVWORD(); k = currentWord;
        ADVWORD(); v = 0;
        for (int i = 0; i<currentWord.Length; i++){
          v = (v*10) + currentWord.TabWord[i]-'0';
        } Insertmap(&m, k, v);
      } InsertLastarrmap(&ScoreBoardGame,m); ADVSENTENCE();
    }
  } else {
    printf("\n"); mode = 0;
  }
}
/* Memulai mesin BNMO dengan mengakses file save player sebelumnya */

void CHOOSEFITURE(int *fitur, char *file){
  printf("Masukkan perintah: "); STARTWORD(); printf("\n");
  if (WordCompareString(currentWord,"CREATE")){
    ADVWORD();
    if (WordCompareString(currentWord,"GAME")){
      CREATEGAME(&ListGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"LIST")){
    ADVWORD();
    if (WordCompareString(currentWord,"GAME")){
      LISTGAME(ListGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"DELETE")){
    ADVWORD();
    if (WordCompareString(currentWord,"GAME")){
      DELETEGAME(&ListGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"QUEUE")){
    ADVWORD();
    if (WordCompareString(currentWord,"GAME")){
      QUEUEGAME(&QueueGame, ListGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"PLAY")){
    ADVWORD();
    if (WordCompareString(currentWord,"GAME")){
      PLAYGAME(&QueueGame, &ScoreBoardGame, &HistoryGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"SKIPGAME")){
    ADVWORD();
    if (currentChar!='\0'){
    int ctr=0;
    for (int i = 0; i<currentWord.Length; i++){
      ctr = (ctr * 10) + currentWord.TabWord[i] - '0';
    }
    SKIPGAME(&QueueGame, &ScoreBoardGame, &HistoryGame, ctr);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"SCOREBOARD")){
    SCOREBOARD(ScoreBoardGame, ListGame);
  } else if (WordCompareString(currentWord,"HISTORY")){
    ADVWORD();
    if (currentChar!='\0'){
      int ctr=0;
      for (int i = 0; i<currentWord.Length; i++){
        ctr = (ctr * 10) + currentWord.TabWord[i] - '0';
      }
      HISTORY(HistoryGame, ctr);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"RESET")){
    ADVWORD();
    if (WordCompareString(currentWord,"SCOREBOARD")){
      RESETSCOREBOARD(&ScoreBoardGame);
    } else if (WordCompareString(currentWord,"HISTORY")){
      RESETHISTORY(&HistoryGame);
    } else {COMMANDLAIN();}
  } else if (WordCompareString(currentWord,"SAVE")){
    ADVWORD();
    WordToString(currentWord, file);
    SAVE(file);
  } else if (WordCompareString(currentWord,"HELP")){
    HELP();
  } else if (WordCompareString(currentWord,"QUIT")){
    *fitur = 0;
  } else {
    COMMANDLAIN();
  }
}
/* Menerima perintah dari pengguna untuk menjalankan fitur yang diinginkan */

void SAVE(char *file){
  char fname[25] = "..\\data\\";
  ConcatString(fname, file);
  FILE *fp = fopen(fname, "w");
  fprintf(fp, "%d\n", ListGame.Neff);
  char *ftulis = (char*) malloc (sizeof(char) * currentWord.Length+1);
  for(int i=0; i<ListGame.Neff; i++){
    WordToString(ListGame.A[i], ftulis);
    fprintf(fp, "%s\n", ftulis);
  }
  fprintf(fp, "%d\n", Top(HistoryGame)+1); //HARUSNYA DI POP PRINT, TAPI TKT JADI PARAMETER OUTPUT SI STACK NYA, NANTI CEK AJA
  for (int i = Top(HistoryGame); i>=0; i--){
    WordToString(HistoryGame.T[i], ftulis);
    fprintf(fp, "%s\n", ftulis);
  }
  for (int i = 0; i<ScoreBoardGame.Neff; i++){
    if (IsEmptymap(ScoreBoardGame.A[i])){
      fprintf(fp, "0\n");
    } else {
      fprintf(fp, "%i\n", ScoreBoardGame.A[i].Count);
      for (int j = 0; j<ScoreBoardGame.A[i].Count; j++){
        WordToString(ScoreBoardGame.A[i].Elements[j].Key, ftulis);
        fprintf(fp, "%s %d\n", ftulis, ScoreBoardGame.A[i].Elements[j].Value);
      }
    }
  } fprintf(fp, ";");
  fclose(fp);
  printf("Berhasil menyimpan ke File!\n");
}
/* Menyimpan state terkini mesin BNMO kedalam file inputan player */

void CREATEGAME(array *ListGame){
  int i = 0;
  boolean found = false;

  printf("Masukkan nama game yang akan ditambahkan: "); STARTSENTENCE();
  char *g = (char*) malloc (sizeof(char) * currentWord.Length+1);
  WordToString(currentWord, g);
  while (i<(*ListGame).Neff && !found){
    if (WordCompareString((*ListGame).A[i], g)){
       found = true;
    } else {
      i++;
    }
  }
  if (!found){
    InsertLast(ListGame, currentWord);
    Map m; CreateEmptymap(&m); InsertLastarrmap(&ScoreBoardGame, m);
    printf("Game berhasil ditambahkan\n");
  } else {
    printf("Game sudah terdaftar\n");
  }
}
/* Membuat sebuah game baru inputan player */

void LISTGAME(array ListGame){
  printf("Berikut daftar game yang anda miliki : \n");
  for (int i = 0; i<ListGame.Neff; i++){
    printf("%i. ", i+1); PrintKata(ListGame.A[i]); printf("\n");
  }
}
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(array *ListGame){  //UBAH BATAS GAME DEFAULT //HAPUS SCOREBOARD DAN HISTORY GAME TSB
  LISTGAME(*ListGame); printf("\n");
  printf("Masukkan nomor game yang ingin dihapus : "); STARTWORD();
  int nmr = 0;
  for (int i = 0; i<currentWord.Length; i++){
    nmr = (nmr * 10) + currentWord.TabWord[i] - '0';
  }
  if ((*ListGame).Neff>6 && nmr>6){
    if (nmr<=(*ListGame).Neff){
      DeleteAt(ListGame, nmr-1);
      printf("Game berhasil dihapus!\n");
    }
    else {
      printf("Nomor game tidak valid!\n");
    }
  } else {
    printf("Game default tidak bisa dihapus!\n");
  }
}
/* Menghapus sebuah game yang dimiliki oleh player */

/*prosedur queuegame*/
void QUEUEGAME(Queue *QueueGame, array ListGame) {
  /*Menampilkan List Game*/
  LISTGAME(ListGame); printf("\n");
  /*Menampilkan Queue Game yang sudah ada*/
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  } printf("\n");
  /*Masukkan input nomor game yang mau dimasukkan kedalam queue*/
  printf("Nomor Game yang mau ditambahkan ke antrian: "); STARTWORD();
  int noGame = 0;
  for (int i = 0; i<currentWord.Length; i++){
    noGame = (noGame * 10) + currentWord.TabWord[i] - '0';
  }
  char *g = (char*) malloc (sizeof(char) * ListGame.A[noGame-1].Length+1);
  WordToString(ListGame.A[noGame-1], g);
  if (noGame <= ListGame.Neff){
    enqueue(QueueGame, ListGame.A[noGame-1]);
    printf("Game %s dimasukkan kedalam antrian.\n", g);
  } else {
    printf("No game yang diinput tidak valid!\n");
  }
}
/*
/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "QUEUE GAME", 
           intinya setiap dipanggil, akan memilih game pada list game, dan akan dimasukkan
           kedalam queue. 
           Catatan: - Memungkinkan untuk ada lebih dari satu game yang sama pada queue.
                    - Diasumsikan di file main udah dibuat queue kosong, jadi tinggal isi.
                    - Diasumsikan maksimum queue pada satu kali proses bermain adalah 10
I.S. input sudah valid, list game + queue game (jika sudah ada) di tampilkan
F.S. memasukkan game ke-n yang diminta user (jika input valid)
*/

/*prosedur playgame*/
void PLAYGAME(Queue *QueueGame, arraymap *ScoreBoardGame, Stack *HistoryGame) {  //TAMBAHKAN GAME YG BARU DIBUAT
                                   //MINTA NAMA PEMAIN DIAKHIR (NAMA GAK BOLEH SAMA WALAUPUN BEDA KAPITAL DOANG) 
                                   //PUSH HISTORY PERMAINAN, INSERT SCORE PEMAIN
                                   //TIAP GAME BIKIN PARAMETER OUTPUT SCORE
  int score;
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  } printf("\n");
  if (isEmpty(*QueueGame)) {
    printf("Tidak ada game di dalam antrian untuk dimainkan, silahkan masukkkan game kedalam antrian terlebih dahulu!\n");
  }
  else /*kasus queue tidak kosong*/{
    Word Game;
    dequeue(QueueGame, &Game);
    int i = 0;
    while (WordCompare(Game, ListGame.A[i])) {
      i++;
    }
    if (i>5) { /*kondisi kalau game yang dimainin itu game baru (diluar file config)*/
      char *stringGame = (char*) malloc (sizeof(char) * Game.Length+1);
      WordToString(Game, stringGame);
      printf("Game %s sedang dimainkan!\n", stringGame); /*ceritanya game nya lagi main*/
      srand(time(NULL)); /*ceritanya lagi ngitung skor*/
      int score = rand() % (100 - 1 +1) + 1;

      /*Game over, print score, minta nama pemain*/
      printf("GAME OVER!\n");
      EndGame(ScoreBoardGame, i, score);
      /*Push history game*/
      Push(HistoryGame, Game);
    }
    else { /*kondisi game nya udah ada di file config*/
      if (WordCompareString(Game, "RNG")) {
        printf("Loading...\n\n");
        RNG(); /*KASI OUTPUT SCORE!*/
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);
      }
      else if (WordCompareString(Game, "Diner DASH")) {
        printf("Loading...\n\n");
        Diner_Dash(); /*KASI OUTPUT SCORE!*/
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);        
      }
      else if (WordCompareString(Game, "HANGMAN")) {
        printf("Loading...\n\n");
        Hangman(); /*KASI OUTPUT SCORE!*/
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);      
      }
      else if (WordCompareString(Game, "TOWER OF HANOI")) {
        printf("Loading...\n\n");
        Tower_of_Hanoi(&score);
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);      
      }
      else if (WordCompareString(Game, "SNAKE ON METEOR")) {
        printf("Loading...\n\n");
        SnakeonMeteor(&score);
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);      
      }
      else if (WordCompareString(Game, "Jari Bocil")) {
        printf("Loading...\n\n");
        Jari_Bocil(&score);
        EndGame(ScoreBoardGame, i, score);
        /*Push history game*/
        Push(HistoryGame, Game);      
      }
    }
  }
}

/*fungsi penunjang PlayGame()*/
void EndGame(arraymap *ScoreBoardGame, int Game, int score) {
  printf("SKOR AKHIR : %i\n", score);
  label : printf("NAMA: "); STARTWORD(); printf("\n");
  boolean found = false; int j = 0;
  while (!found && j<ScoreBoardGame->A[Game].Count) {
    if (WordCompare(currentWord, ScoreBoardGame->A[Game].Elements[j].Key)) {
      found = true; /*kondisi kalau ketemu yang sama namanya*/
      j++;
    }
    else {
      j++; /*kondisi kalau nama nya gaada yang sama*/
    }
  }
  if (found == true) { /*ketemu nama yang sama*/
    printf("Nama yang di Input sudah ada, silahkan masukkan nama lain!\n");
    goto label;
  }
  else { /*Nama yang di input tidak ada di ScoreBoard*/
    Insertmap(ScoreBoardGame->A[Game].Elements, currentWord, score); 
  }
}

/*
Deskripsi: function akan dijalankan ketika menerima input dari user berupa "PLAY GAME"
           ketika dipanggil, akan mengecek apakah queue game kosong atau tidak, jika kosong,
           maka akan menampilkan list game, lalu meminta input game yang akan dimainkan. Jika
           queue game tidak kosong, maka akan menjalankan game pertama yang ada di queue.
           Catatan - Dilakukan pengecekan valid/tidak nya input (jika queue kosong)
                   - 
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). 
F.S. game dimainkan (memanggil game jika dia RNG/Dinner Dash)
*/

/*prosedur skipGame*/
void SKIPGAME(Queue *QueueGame, arraymap *ScoreBoardGame, Stack *HistoryGame,int ctr) {
  printf("Berikut adalah daftar antrian game-mu: \n");
  for (int i = 0; i<=IDX_TAIL(*QueueGame); i++){
    printf("%i. ", i+1); PrintKata(QueueGame->buffer[i]); printf("\n");
  }
  if (ctr <= IDX_TAIL(*QueueGame) && ctr >= 0) {
    Word Game;
    for (int i=0; i<ctr;i++) {dequeue(QueueGame, &Game);}
    PLAYGAME(QueueGame, ScoreBoardGame, HistoryGame);
  }
  else /*kasus kalau input salah*/ {
    CreateQueue(QueueGame);
    printf("\nTidak ada permainan lagi dalam daftar game-mu\n");
  }
}
/*
Deskripsi: function akan dilakukan ketika queue game sudah ada dan user memberika input
           berupa "SKIP GAME n". Jika n>length queue, maka muncul pesan error, jika n valid,
           maka akan mengeskip game sebanyak n kali(dequeue sebanyak n kali) lalu menjalankan 
           function playgame
           Catatan: -
I.S. list game ditampilkan (bisa berupa queue jika sudah ada, kalau queue kosong, tampilkan
list game awal). n sudah di dapat dari input command
F.S. game di skip, lalu dimainkan
*/

void SCOREBOARD(arraymap ScoreBoardGame, array ListGame){
  for(int i=0; i< ScoreBoardGame.Neff ; i++){
    printf("**** SCOREBOARD GAME ") ; PrintKata(ListGame.A[i]); printf(" ****\n");
    printf("|     Nama     |     Score     |\n");
    printf("| ---------------------------- |\n");
    for (int j = 0; j < ScoreBoardGame.A[i].Count; j++)
    {
      printf("|     "); PrintKata(ScoreBoardGame.A[i].Elements[j].Key); printf("     |  %d  |\n", ScoreBoardGame.A[i].Elements[j].Value); 
    }
    printf("| ---------------------------- |\n\n");
  }
}
/* Menampilkan ScoreBoard pemain ditiap game */


void RESETSCOREBOARD(arraymap* ScoreBoardGame){
  for(int i=0; i< ScoreBoardGame->Neff ; i++){
    ScoreBoardGame->A[i].Count = 0;
  }
}
/* ScoreBoard permainan direset sesuai keinginan player */

void HISTORY(Stack HistoryGame, int n){
  printf("Berikut adalah daftar Game yang telah dimainkan\n");
  Word simpan;
  if (n < Top(HistoryGame)+1) {
    for (int j = 0; j < n; j++) {
      printf("%d. ", j+1); PrintKata(InfoTop(HistoryGame)); printf("\n");
      Pop(&HistoryGame, &simpan);
    }
  }
  else {
    int loop = Top(HistoryGame);
    for (int i = 0; i <= loop; i++) {
      printf("%d. ", i+1); PrintKata(InfoTop(HistoryGame)); printf("\n");
      Pop(&HistoryGame, &simpan);
    }
  }
}
/* Menampilkan History permainan pemain */

void RESETHISTORY(Stack* HistoryGame){
  printf("APAKAH KAMU INGIN MELAKUKAN RESET HISTORY? [YA/TIDAK]\n");
  STARTWORD();
  if (WordCompareString(currentWord, "YA")) {
    printf("History berhasil di-reset.\n");
    CreateEmptystack(HistoryGame);
  }
  else {
    int T = Top(*HistoryGame)+1;
    HISTORY(*HistoryGame, T);
  }
}
/* Mereset history permainan pemain */

void QUIT(){
  printf("Apakah anda ingin save? (Y/N)\n"); STARTWORD();
  if (WordCompareString(currentWord, "Y")){
    printf("Masukkan nama file yang ingin disimpan: "); STARTWORD();
    char *file = (char*) malloc (sizeof(char) * currentWord.Length+1);
    WordToString(currentWord, file);
    SAVE(file);
    printf("Data berhasil di save\n");
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
  }
  else {
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
  }
}
/* Player keluar dari mesin BNMO */

void HELP(){ //TAMBAHKAN INFORMASI FITUR BARU
  printf("FITUR-FITUR BNMO:\n");
  printf("1. START \t-> merupakan menu awal untuk memulai BNMO dengan pilihan game default.\n");
  printf("2. LOAD \t-> merupakan menu awal untuk membaca dan membuka file save yang berisikan history permainan dari player.\n");
  printf("3. SAVE \t-> merupakan menu untuk menyimpan data setelah adanya perubahan dari player.\n");
  printf("4. CREATE GAME \t-> merupakan menu untuk menambahkan game baru pada daftar game.\n");
  printf("5. LIST GAME \t-> merupakan menu untuk menampilkan daftar game yang tersedia untuk player.\n");
  printf("6. DELETE GAME \t-> merupakan menu untuk menghapus sebuah game dari daftar game, dengan syarat:\n");
  printf("\t\t   game yang dihapus adalah game tambahan dan game yang terdapat pada queue saat itu tidak bisa dihapus.\n");
  printf("7. QUEUE GAME \t-> merupakan menu untuk mendaftarkan game kedalam list queue game yang akan dimainkan oleh player.\n");
  printf("8. PLAY GAME \t-> merupakan menu untuk memainkan game.\n");
  printf("9. SKIP GAME \t-> merupakan menu untuk melewati game yang tidak ingin dimainkan, sebanyak yang diinginkan.\n");
  printf("10. QUIT \t-> merupakan menu untuk keluar dari BNMO.\n");
}
/* Menampilkan menu fitur-fitur yang dimiliki oleh mesin BNMO serta penjelasannya */

void COMMANDLAIN(){
  printf("Command tidak dikenali, silahkan masukkan command yang valid!\n");
}
/* Mengeluarkan pesan kesalahan serta meminta inputan ulang ketika player memberi perintah yang tidak valid */
