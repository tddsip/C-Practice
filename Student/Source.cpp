#include<iostream>
#include<string>
#include<vector>
#include <fstream>

using namespace std;
const string file = "student.txt";
struct Student
{
	int id;
	string name;
	float score;
};

vector<Student> listSt;
void Input(int choose, vector<Student> &listSt);
void Output(vector<Student> &listSt);
int SaveFile(vector<Student> listSt);
int LoadFile(vector<Student> *listSt);
int checkID(int ID, vector<Student> listSt);
int checkScore(float score);

int main()
{
	int choose;
	char question;
	do {
	cout << "----------------MENU---------------\n";
	cout << "         1. Input\n";
	cout << "         2. Display\n";
	cout << "         3. Save to file\n";
	cout << "         4. Load from file\n";
	cout << "         0. exit\n";
	cout << "-----------------------------------\n";
	cout << "Chosse:  ";
	cin >> choose;
	switch (choose)
	{
	case 1: Input(choose, listSt);
		break;
	case 2: Output(listSt);
		break;
	case 3: if (SaveFile(listSt) == 1) cout << "Save file success!\n";
		else cout << "Save file Failed, Try it!\n";
		system("pause");
		break;
	case 4: 
		switch (LoadFile(&listSt))
	  {
		case 5: cout << "Load file to List Failed. Try it!\n";
		   break;
	    case 6: cout << "File empty!\n";
		   break;
	    case 7: cout << "Load file to List success!\n";
		   break;
	    default:
		   break;
	}
		system("pause");
		break;
	    default:
		   break;
	}
	cout << " you want to continue(y/n): ";
	cin >> question;
	system("cls");
  } while (question == 'y');

	system("pause");
	return 0;
}
void Input(int n, vector<Student>  &listSt)
{
	system("cls");
	Student temp;
	cout << "Input the number of listSt:  ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "\nInput id of student: " << i + 1 << ": ";
			cin.get();
			cin >> temp.id;
			if (checkID(temp.id, listSt) == -1)
				break;
			cout << "student id has already, press any key to try again!";
			system("pause>NULL");

		} while (checkID(temp.id, listSt) == 1);
		cout << "Input name of student: " << i + 1 << ": ";
		cin.get();
		getline(cin, temp.name);
		do {
			cout << "Input score of student: " << i + 1 << ": ";
			cin >> temp.score;
			cin.get();
			if (checkScore(temp.score) == -1) 
				break;
		} while (checkScore(temp.score) == 1);
		listSt.push_back(temp);
	}

}

int checkID(int ID, vector<Student> listSt)
{
	for (auto temp : listSt)
	{
		if (ID == temp.id) { return 1; break; }
	}
	return -1;
}
int checkScore(float score)
{
	if (score < 0 && score > 10) return 1;
	else return -1;
}
void Output(vector<Student>  &listSt)
{
	system("cls");
	cout << "   ID   |   Name    |    Score    \n";
	for (auto temp : listSt) {
		cout << "   " << temp.id << "|       " << temp.name << "|        " << temp.score << endl;
	}
}
int SaveFile(vector<Student> listSt)
{
		ofstream insert(file, std::ios::out);
		for (Student temp : listSt) 
		{
			insert << temp.id << "\n";
			insert << temp.name << "\n";
			insert << temp.score << "\n";
			if (insert.fail()) return -1;
		}
		insert.close();
		return 1;
}
int LoadFile(vector<Student> *listSt) {
	Student student;
	string line;
	int id;
	float score;
	int oldSize = listSt->size();
	ifstream fileToList(file);
	if (fileToList.fail()) return 5;
	int linenumber = 0;
	while (getline(fileToList, line))
	{
		linenumber++;
		switch (linenumber)
		{
		case 1:
			id = stoi(line);
			student.id = id;
			break;
		case 2:
			student.name = line;
			break;
		case 3:
			score = stof(line);
			student.score = score;
			linenumber = 0;
			listSt->push_back(student);
			break;
		default:
			break;
		}
	}
	fileToList.close();
	if (oldSize < listSt->size()) return 6;
	else return 7;
}
