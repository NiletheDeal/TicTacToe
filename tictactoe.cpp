#include <iostream>
using namespace std;

char board[3][3];
char player = 'X';
int row;
int col;
char input;
int Owins = 0;
int Xwins = 0;
bool stillPlaying = true;
void print_board() {
   cout << "\t1\t2\t3" << endl;
   cout << "a\t" <<board[0][0] << "\t" << board[0][1] << "\t" << board[0][2] << endl;
   cout << "b\t" <<board[1][0] << "\t" << board[1][1] << "\t" << board[1][2] << endl;
   cout << "c\t" <<board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << endl;
}

bool is_valid_move(int row, int col) {
  if (board[row][col] == '-') {
     return true;
  }
   cout << "Please input a valid move" << endl;
   return false;
}
void place_player (int row, int col) {
  board[row][col] = player;
  }
bool checkWin() {
  
  //check rows
  for(int i = 0; i<3; i++) {
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
      return true;
    }
  }
  //check col
  for(int i = 0; i<3; i++) {
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
      return true;
    }
  }
  //check diagonal wins
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] !='-') {
    return true;
    
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] !='-') {
    return true;
    
  }
  return false;
}
bool checkTie() {
  for(int i = 0; i<3; i++) {
    for(int j = 0; j<3; j++) {
      if (board[i][j] == '-') {
	return false;
	cout << "tie" <<endl;
      }
    }
  }
  return true;
}
  
  main() {
    while(stillPlaying == true) {
      for(int i=0;i<3;i++) {
	for(int j=0;j<3;j++) {
	  board[i][j] = '-';
	}
      }
      player = 'O';
      cout << "O has " <<Owins << " wins. X has " << Xwins << " wins." << endl; 
      print_board();
      while (checkWin() == false && checkTie() == false) {
	do {
	  cout << player << "'s turn" << endl;
	  cout << "Please input row: ";
	  cin >> input;
	  row = input-'a';
	  cout << "Please input col: ";
	  cin >> input;
	  col = input - '1';
	}
	while (is_valid_move(row, col) == false);
	place_player (row, col);
	print_board();
	if (checkWin() == false) {
	  if (player == 'X') {
	    player = 'O';
	  }
	  else if (player == 'O') {
	    player ='X';
	  }
	}
      }
      if (checkWin() == true) {
	cout<< "Congrats! " << player << " Won!" << endl;
	if (player == 'X') {
	  Xwins++;
	}
	if (player == 'O') {
	  Owins++;
	}
      }
      else if (checkTie() == true) {
	cout << "It was a tie" << endl;
      }
      cout << "Do you wish to play again (y/n)?" <<endl;
      cin >> input;
      cin.ignore();
      //continue using
      if (input == 'y') {
	stillPlaying = true;
      }
      //Stop using
      if (input == 'n') {
	stillPlaying = false;
      }
    }
    cout << "Thanks for Playing" << endl;
  }
 
   
      
