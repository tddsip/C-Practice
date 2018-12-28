#include<iostream>
using namespace std;

char square[3][3] = { '1','2', '3', '4', '5', '6', '7', '8', '9' };
char square2[3][3] = { '1','2', '3', '4', '5', '6', '7', '8', '9' };
char player1[20], player2[20];
char question;
char temp;
int row, column;
int input;


int check()
{
	if (square[0][0] == 'X' && square[0][1] == 'X' && square[0][2] == 'X' || square[1][0] == 'X' && square[1][1] == 'X' && square[1][2] == 'X' || square[2][0] == 'X' && square[2][1] == 'X' && square[2][2] == 'X' ||
	square[0][0] == 'X' && square[1][0] == 'X' && square[2][0] == 'X' || square[0][1] == 'X' && square[1][1] == 'X' && square[2][1] == 'X' || square[0][2] == 'X' && square[1][2] == 'X' && square[2][2] == 'X' ||
	square[0][0] == 'X' && square[1][1] == 'X' && square[2][2] == 'X' || square[2][0] == 'X' && square[1][1] == 'X' && square[0][2] == 'X')
	    return 1;
	else if (square[0][0] == 'O' && square[0][1] == 'O' && square[0][2] == 'O' || square[1][0] == 'O' && square[1][1] == 'O' && square[1][2] == 'O' || square[2][0] == 'X' && square[2][1] == 'X' && square[2][2] == 'X' ||
		square[0][0] == 'O' && square[1][0] == 'O' && square[2][0] == 'O' || square[0][1] == 'O' && square[1][1] == 'O' && square[2][1] == 'O' || square[0][2] == 'X' && square[1][2] == 'X' && square[2][2] == 'X' ||
		square[0][0] == 'O' && square[1][1] == 'O' && square[2][2] == 'O' || square[2][0] == 'O' && square[1][1] == 'O' && square[0][2] == 'O')
		return 2;
	else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' && square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')
		return 3;
}

void playgame()
    {
	
	cout << "\n\nHello " << player1 << " and " << player2;
	cout << endl << endl << endl << endl << endl;
	cout << "     TIC TAC TOE\n\n\n\n";
	for (int i = 0; i <3; i++)
	{
		cout << "     ";
		for (int j = 0; j <3; j++)
		{
			cout << square[i][j] << " | ";
		}
		cout << "\n     -----------\n";
	}
	int count = 0;
	do{
		if (count % 2 == 0)
		{
			temp = 'X';
			cout << "\n\nTurn " << player1 <<"\n\nplease choose : ";
			cin >> input;
		}
		else  
		{
			temp = 'O';
			cout << "\n\nTurn " << player2 <<"\n\nplease choose : ";
			cin >> input;
		}
		row = input / 10 -1 ;
		column = input % 10 -1 ;
		if (square[row][column] != 'X' && square[row][column] != 'O') 
		{
			square[row][column] = temp;
			count++;
			system("CLS");
			cout << "\n\nHello " << player1 << " and " << player2;
			cout << endl << endl << endl << endl << endl;
			cout << "     TIC TAC TOE\n\n\n\n";
			for (int i = 0; i <3; i++)
			{
				cout << "     ";
				for (int j = 0; j <3; j++)
				{
					cout << square[i][j] << " | ";
				}
				cout << "\n     -----------\n";
			}
		}
		//system("CLS");
		if (check() == 1)
		{
			cout << player1 << " win !\n";
			break;
		}
		else if (check() == 2)
		{
			cout << player2 << " win !\n";
			break;
		}
		else if (check() == 3)
		{
			cout << "Draw\n";
			break;
		}
	}while (true);
}
int main() {
	int run;
	cout << "Welcome To Tic-tac-toe game! Play with your way!";
	cout << "If you find any problem, please contact truongddsip@gmail.com\n";
	cout << "\n\nSELECT YOUR MODE(1 - PLAY GAME, OTHERS - EXIT GAME)\n";
	cin >> run;
	switch (run)
	{
	case 1: 
		cout << "Enter Player 1 Name:  "; cin >> player1;
		cout << "\Enter Player 2 Name:  ";  cin >> player2;
		system("CLS");
		do {
			playgame();
			cout << "End game !\n"; 
			cout << "Do you want to continue (y/n)?";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					square[i][j] = square2[i][j];
			}
			cin >> question;
		} while (question == 'y');
		break;
	default:
		break;
	}
	system("pause");
}