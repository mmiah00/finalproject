#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <unistd.h>

void introscreen () { //thank you patorjk.com for the ASCII art
  printf ("██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗    ████████╗ ██████╗     \n");
  printf ("██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝    ╚══██╔══╝██╔═══██╗    \n");
  printf ("██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗         ██║   ██║   ██║    \n");
  printf ("██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝         ██║   ██║   ██║    \n");
  printf ("╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗       ██║   ╚██████╔╝    \n");
  printf (" ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝       ╚═╝    ╚═════╝     \n");
  printf ("                                                                                        \n");
  printf ("    ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗        \n");
  printf ("    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗       \n");
  printf ("    ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝       \n");
  printf ("    ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝        \n");
  printf ("    ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║            \n");
  printf ("    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝            \n");

  printf("\n\n");
  printf("                                )___( \n");
  printf("                          _______/__/_\n");
  printf("                 ___     /===========|   ___\n");
  printf("____       __   [\\\\]___/____________|__[///]   __\n");
  printf("\\   \\_____[\\]__/___________________________\\__[//]___\n");
  printf(" \40A                                                 |\n");
  printf("  \\                                                  /\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf ("\n\n");

  /*
  printf ("██████╗ ██████╗ ███████╗███████╗███████╗    ███████╗██████╗  █████╗  ██████╗███████╗    \n");
  printf ("██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝    ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝    \n");
  printf ("██████╔╝██████╔╝█████╗  ███████╗███████╗    ███████╗██████╔╝███████║██║     █████╗      \n");
  printf ("██╔═══╝ ██╔══██╗██╔══╝  ╚════██║╚════██║    ╚════██║██╔═══╝ ██╔══██║██║     ██╔══╝      \n");
  printf ("██║     ██║  ██║███████╗███████║███████║    ███████║██║     ██║  ██║╚██████╗███████╗    \n");
  printf ("╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝    ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝    \n");
  printf ("████████╗ ██████╗      ██████╗ ██████╗ ███╗   ██╗████████╗██╗███╗   ██╗██╗   ██╗███████╗\n");
  printf ("╚══██╔══╝██╔═══██╗    ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██║████╗  ██║██║   ██║██╔════╝\n");
  printf ("   ██║   ██║   ██║    ██║     ██║   ██║██╔██╗ ██║   ██║   ██║██╔██╗ ██║██║   ██║█████╗  \n");
  printf ("   ██║   ██║   ██║    ██║     ██║   ██║██║╚██╗██║   ██║   ██║██║╚██╗██║██║   ██║██╔══╝  \n");
  printf ("   ██║   ╚██████╔╝    ╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║██║ ╚████║╚██████╔╝███████╗\n");
  printf ("   ╚═╝    ╚═════╝      ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝\n");
  */
/*
  printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n");
  printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
  printf("| |   ______     | || |      __      | || |  _________   | || |  _________   | || |   _____      | || |  _________   | |\n");
  printf("| |  |_   _ \\    | || |     /  \\     | || | |  _   _  |  | || | |  _   _  |  | || |  |_   _|     | || | |_   ___  |  | |\n");
  printf("| |    | |_) |   | || |    / /\\ \\    | || | |_/ | | \\_|  | || | |_/ | | \\_|  | || |    | |       | || |   | |_  \\_|  | |\n");
  printf("| |    |  __'.   | || |   / ____ \\   | || |     | |      | || |     | |      | || |    | |   _   | || |   |  _|  _   | |\n");
  printf("| |   _| |__) |  | || | _/ /    \\ \\_ | || |    _| |_     | || |    _| |_     | || |   _| |__/ |  | || |  _| |___/ |  | |\n");
  printf("| |  |_______/   | || ||____|  |____|| || |   |_____|    | || |   |_____|    | || |  |________|  | || | |_________|  | |\n");
  printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
  printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
  printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
  printf("                     .----------------.  .----------------.  .----------------.  .----------------.                     \n");
  printf("                    | .--------------. || .--------------. || .--------------. || .--------------. |                    \n");
  printf("                    | |    _______   | || |  ____  ____  | || |     _____    | || |   ______     | |                    \n");
  printf("                    | |   /  ___  |  | || | |_   ||   _| | || |    |_   _|   | || |  |_   __ \\   | |                    \n");
  printf("                    | |  |  (__ \\_|  | || |   | |__| |   | || |      | |     | || |    | |__) |  | |                    \n");
  printf("                    | |   '.___`-.   | || |   |  __  |   | || |      | |     | || |    |  ___/   | |                    \n");
  printf("                    | |  |`\\____) |  | || |  _| |  | |_  | || |     _| |_    | || |   _| |_      | |                    \n");
  printf("                    | |  |_______.'  | || | |____||____| | || |    |_____|   | || |  |_____|     | |                    \n");
  printf("                    | |              | || |              | || |              | || |              | |                    \n");
  printf("                    | '--------------' || '--------------' || '--------------' || '--------------' |                    \n");
  printf("                     '----------------'  '----------------'  '----------------'  '----------------'      ");
  */
}

struct gameBoard{
  int player; //board of the specified player
  int board[8][8]; //ships only be visible to the owner of this board. otherwise it will look like an empty spot
};

struct coordinate  {
  int x,y;
};

int display(int user, struct gameBoard p1Board, struct gameBoard p2Board){
  if (user == p1Board.player){
    printf("printing your board\n");
    for (int r = 0; r < 8; r++){
      for (int c = 0; c < 8; c++){
        if (p1Board.board[r][c] == 0){
          printf("~");
        }
      }
      printf("\n");
    }
  }
  else{
    printf("printing enemy's board\n");
  }
}

int isValid(int xcoord, int ycoord, int shipSize, char * HorV, int board[8][8] ){
  if (strcmp(HorV, "vertical") == 0){//check vertically
    for (int r = xcoord; r < 8 && shipSize != 0; r++){
      if (board[r][ycoord] == 0){//if spot is empty
        shipSize--;//one coord of ship is valid
      }
    }
    if (shipSize == 0){
      return 1; //it is valid
    }
    else{
      return 0; //ship is too long to be placed here
    }
  }
  else if (strcmp(HorV, "horizontal") == 0){//check horizontally
    for (int c = ycoord; c < 8 && shipSize != 0; c++){
      if (board[xcoord][c] == 0){
        shipSize--;
      }
    }
    if (shipSize == 0){
      return 1; //it is valid
    }
    else{
      return 0; //ship is too long to be placed here
    }
  }
  else{
    return 0;//invalid arg
  }
}
int placeShip(int xcoord, int ycoord, int shipType, char * HorV, int board[8][8]){
  if (shipType < 1 || shipType > 5 || xcoord > 7 || xcoord < 0 || ycoord > 7 || ycoord < 0){//there are only 5 types of ships
    return 0;
  }
  int shipSize = 0;
  if (shipType == 1){
    shipSize = 2;
  }
  if (shipType == 2){
    shipSize = 3;
  }
  if (shipType == 3){
    shipSize = 3;
  }
  if (shipType == 4){
    shipSize = 4;
  }
  if (shipType == 5){
    shipSize = 5;
  }
  if (isValid(xcoord, ycoord, shipSize, HorV, board) == 0){//returns 0 if ship can't be placed
    return 0;//false
  }
  else{//ship location is valid
    if (strcmp(HorV, "vertical") == 0){
      for (int r = xcoord; shipSize != 0; r++){
        board[r][ycoord] = 1;
        shipSize--;
      }
    }
    else if (strcmp(HorV, "horizontal") == 0){
      for (int c = ycoord; shipSize != 0; c++){
        board[xcoord][c] = 1;
        shipSize--;
      }
    }
    return 1;//successfully placed
  }
}

int executeCommand(char * command, int currentPlayer, struct gameBoard p1Board, struct gameBoard p2Board){
  if (strcmp(command, "help") == 0){
    printf("Instructions\n");
    printf("...\n");
  }
  else if (strcmp(command, "history") == 0){
    printf("Displaying game history:\n");
    //history ();
  }
  else if (strcmp(command, "display ally") == 0){
    printf("Displaying your board and ships\n");
  }
  else if (strcmp(command, "display enemy") == 0){
    printf("Displaying enemy's board\n");
  }
  return 0;
}

char ** parse_args (char * line) {
  char ** ans = malloc (256);
  int i = 0;
  char * temp;
  while (temp) {
    temp = strsep(&line, " ");
    ans[i] = temp;
    i ++;
  }
  return ans;
}

int main () {
  introscreen ();
  int running = 1;

  struct gameBoard p1;
  p1.player = 1;
  for (int r = 0; r < 8; r++){
    for (int c = 0; c < 8; c++){
      p1.board[r][c] = 0;//0 represents water, -1 represents a ship, 1 represents a hit, 2 represents a miss
    }
  }

  struct gameBoard p2;
  p2.player = 2;
  for (int r = 0; r < 8; r++){
    for (int c = 0; c < 8; c++){
      p2.board[r][c] = 0;//0 represents water, -1 represents a ship, 1 represents a hit, 2 represents a miss
    }
  }

  //int historyFile = open("history.txt", O_CREAT, 0644);

  //filling board with ships
  int ship1placed = 0; //two coords long
  int ship2placed = 0; //three coords long
  int ship3placed = 0; //three coords long
  int ship4placed = 0; //four coords long
  int ship5placed = 0; //five coords long
  char input[1000];
  while (ship1placed != 1 && ship2placed != 1 && ship3placed != 1 && ship4placed != 1 && ship5placed != 1){//only continues to gameplay if all ships are placed
    printf("Please place your ships to continue\n");
    fgets(input,sizeof(input), stdin);
    char ** args = parse_args(input);
    if (strcmp(args[0], "place") == 0){
      int xcoord = atoi(args[1]);
      int ycoord = atoi(args[2]);
      int shipType = atoi(args[3]);
      //command is "$place xcoord ycoord shiptype verticalorhorizontal"
      if (placeShip(xcoord, ycoord, shipType, args[4], p1.board) == 0){ //p2.board if the current player is player 2
        printf("Ship placed unsuccessfully. Try again :(\n");
      }
      else{
        printf("Ship placed successfully :)\n");
        if (shipType == 1){
          ship1placed = 1;
        }
        if (shipType == 2){
          ship2placed = 1;
        }
        if (shipType == 3){
          ship3placed = 1;
        }
        if (shipType == 4){
          ship4placed = 1;
        }
        if (shipType == 5){
          ship5placed = 1;
        }
      }
    }
  }

  //gameplay commands
  char command[1000];
  while (running){
    printf("Awaiting your next command:");
    fgets(command, sizeof(command), stdin);
    command[strlen(command) - 1] = '\0';
    printf("Your command is %s\n\n", command);
    if (strcmp(command, "exit") == 0){
      running = 0;
    }
    else{
      executeCommand(command, -1, p1, p2);
    }
  }
  return 0;
}
