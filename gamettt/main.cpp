#include<iostream>
#include<string>
using namespace std;

char ttt[3][3] = { '1','2', '3', '4', '5', '6', '7', '8', '9' };
string s1, s2;
int kt()
{
	if (ttt[0][0] == 'X' && ttt[0][1] == 'X' && ttt[0][2] == 'X' || ttt[1][0] == 'X' && ttt[1][1] == 'X' && ttt[1][2] == 'X' || ttt[2][0] == 'X' && ttt[2][1] == 'X' && ttt[2][2] == 'X' ||
	ttt[0][0] == 'X' && ttt[1][0] == 'X' && ttt[2][0] == 'X' || ttt[0][1] == 'X' && ttt[1][1] == 'X' && ttt[2][1] == 'X' || ttt[0][2] == 'X' && ttt[1][2] == 'X' && ttt[2][2] == 'X' ||
	ttt[0][0] == 'X' && ttt[1][1] == 'X' && ttt[2][2] == 'X' || ttt[2][0] == 'X' && ttt[1][1] == 'X' && ttt[0][2] == 'X')
	    return 1;
	else if (ttt[0][0] == 'O' && ttt[0][1] == 'O' && ttt[0][2] == 'O' || ttt[1][0] == 'O' && ttt[1][1] == 'O' && ttt[1][2] == 'O' || ttt[2][0] == 'X' && ttt[2][1] == 'X' && ttt[2][2] == 'X' ||
		ttt[0][0] == 'O' && ttt[1][0] == 'O' && ttt[2][0] == 'O' || ttt[0][1] == 'O' && ttt[1][1] == 'O' && ttt[2][1] == 'O' || ttt[0][2] == 'X' && ttt[1][2] == 'X' && ttt[2][2] == 'X' ||
		ttt[0][0] == 'O' && ttt[1][1] == 'O' && ttt[2][2] == 'O' || ttt[2][0] == 'O' && ttt[1][1] == 'O' && ttt[0][2] == 'O')
		return 2;
	else if (ttt[0][0] != '1' && ttt[0][1] != '2' && ttt[0][2] != '3' && ttt[1][0] != '4' && ttt[1][1] != '5' && ttt[1][2] != '6' && ttt[2][0] != '7' && ttt[2][1] != '8' && ttt[2][2] != '9')
		return 3;
}
void run()
    {
	
	cout << "\n\nXin chao " << s1 << " va " << s2;
	cout << endl << endl << endl << endl << endl;
	cout << "     TIC TAC TOE\n\n\n\n";
	for (int i = 0; i <3; i++)
	{
		cout << "     ";
		for (int j = 0; j <3; j++)
		{
			cout << ttt[i][j] << " | ";
		}
		cout << "\n     -----------\n";
	}
	int dem = 0;
	
	do{
		char s;
		int a, b, n;
		if (dem % 2 == 0)
		{
			s = 'X';
			cout << "\n\nToi luot " << s1 <<"\n\nmoi chon o : ";
			cin >> n;
		}
		else  
		{
			s = 'O';
			cout << "\n\nToi luot " << s2 <<"\n\nmoi chon o : ";
			cin >> n;
		}
		
		switch (n)
		{
		case 1: a = 0; b = 0;
			if (ttt[a][b] == '1')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 2: a = 0; b = 1;
			if (ttt[a][b] == '2')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 3: a = 0; b = 2;
			if (ttt[a][b] == '3')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 4: a = 1; b = 0;
			if (ttt[a][b] == '4')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 5: a = 1; b = 1;
			if (ttt[a][b] == '5')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 6: a = 1; b = 2;
			if (ttt[a][b] == '6')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 7: a = 2; b = 0;
			if (ttt[a][b] == '7')
			{
				ttt[a][b] = s;
				dem++;

			}
			break;
		case 8: a = 2; b = 1;
			if (ttt[a][b] == '8')
			{
				ttt[a][b] = s;
				dem++;
			}
			break;
		case 9: a = 2; b = 2;
			if (ttt[a][b] == '9')
			{
				ttt[a][b] = s;
				dem++;
			}

			break;
		default:
			break;
		}
		system("CLS");
		cout << "\n\nXin chao " << s1 << " va " << s2;
		cout << endl << endl << endl << endl << endl;
		cout << "     TIC TAC TOE\n\n\n\n";
		for (int i = 0; i <3; i++)
		{
			cout << "     ";
			for (int j = 0; j <3; j++)
			{
				cout << ttt[i][j] << " | ";
			}
			cout << "\n     -----------\n";
		}
		if (kt() == 1)
		{
			cout << s1 << " win\n";
			break;
		}
		else if (kt() == 2)
		{
			cout << s2 << " win\n";
			break;
		}
		else if (kt() == 3)
		{
			cout << "hoa\n";
			break;
		}
	}while (true);
	system("pause");


}
int main() {
	int p;
	cout << "Welcome To Tic-tac-toe game! Play with your way!";
	cout << "If you find any problem, please contact john.nguyen@gameloft.com\n";
	cout << "\n\nSELECT YOUR MODE(1 - PLAY GAME, OTHERS - EXIT GAME)\n";
	cin >> p;
	switch (p)
	{
	case 1: 
		cout << "nhap ten nguoi choi 1 : "; cin >> s1;
		cout << "\nnhap ten nguoi choi 2 : ";  cin >> s2;
		system("CLS");
		run(); break;
	default:
		break;
	}
	
}