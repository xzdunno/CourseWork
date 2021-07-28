#include <string>
#include <iostream>
#include <fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
int  numberOfStudentsOwn = 0, numberOfStudentsBase = 5;
fstream file;
string fileOwn = "Данные пользователя.txt", fileDataBase = "База данных.txt", fileBuf = "";
class Session {
public:
	int numberOfSubjects = 0;
	class Subject {
	public:
		string subjectName = "f";
		int mark = 0;
	};
	Subject subjects[10];
};
class Student {
	string surName, name, secondName;
	int admissionYear = 0;
	int date = 0, month = 0, year = 0;
	string faculty, department, group;
	string examBookNumber;
	char sex = ' ';
	int numberOfSessions = 0;
public: int numberOfStudentsOp = 0;
public:
	Session sessions[9];
	friend void DataBase();
	friend void printAllInfo(int);
	friend void printOne(string, int);
	friend void task(int, int, int);
	friend int keyboardInput(int);
	friend void dataBaseInput(int);
	friend int deleteStudent(string, int);
	friend void changeInfo(string, int);
	void operator[](const int index);
};
class Menu {
	void choice();
public:Menu() {
	choice();
}
	  ~Menu() {
		  if (true) {
			  system("cls");
		  }
		  cout << "Спасибо, что пользуетесь нашим продуктом! До свидания, всего хорошего!" << endl << endl;
	  }
};

Student Students, Students1;
string less10(string k) {
	bool a = true;
	while (a) {
		if (k.length() > 9) {
			cout << "Число не может быть таким большим, введите нужное ";
			cin >> k;
		}
		else { a = false; }
	}
	return k;
};
int checkInt(string m) {
	int result = 0;
	bool a = true;
	m = less10(m);
	while (a) {
		int count = 0;
		for (int i = 0; i < m.length(); i++) {
			if (!((int(m[i]) <= 57) & (int(m[i]) >= 48))) {
				count++;
			}
		}
		if (count > 0) {
			cout << "Между требуемых цифр затесался символ. Введите число заново ";
			cin >> m;
			m = less10(m);
		}
		else { a = 0; }
	}
	for (int i = 0; i < m.length(); i++) {
		result += (int(m[i]) - 48) * pow(10, m.length() - i - 1);
	}
	return result;
}
void Student::operator[](const int index) {
	string xz;
	file.open(fileBuf, ios_base::in | ios_base::out);
	for (int l = 0; l < numberOfStudentsOp; l++) {
		getline(file, xz, '*');
		int number = checkInt(xz);
		if (number == index) {
			getline(file, name, '*');
			getline(file, surName, '*');
			getline(file, secondName, '*');
			getline(file, xz, '*');
			sex = xz[0];
			getline(file, xz, '*');
			date = checkInt(xz);
			getline(file, xz, '*');
			month = checkInt(xz);
			getline(file, xz, '*');
			year = checkInt(xz);
			getline(file, xz, '*');
			admissionYear = checkInt(xz);
			getline(file, faculty, '*');
			getline(file, department, '*');
			getline(file, group, '*');
			getline(file, examBookNumber, '*');
			getline(file, xz, '*');
			numberOfSessions = checkInt(xz);
			for (int sess = 0; sess < numberOfSessions; sess++) {
				getline(file, xz, '*');
				sessions[sess].numberOfSubjects = checkInt(xz);
				for (int sub = 0; sub < sessions[sess].numberOfSubjects; sub++) {
					getline(file, sessions[sess].subjects[sub].subjectName, '*');
					getline(file, xz, '*');
					sessions[sess].subjects[sub].mark = checkInt(xz);
				}
			}
			file.seekg(2, ios_base::cur);
		}
		else {
			getline(file, xz, '\n');
		}
	}
	file.close();
} string checkString(string checking) {
	int a = 1, count = 0;
	while (a) {
		count = 0;
		for (int i = 0; i < checking.length(); i++) {
			if (int(checking[i]) == 42) {
				count++;
			}
		}
		if (count > 0) {
			cout << "Нельзя использовать такие символы как *. Прошу ввести данные заново ";
			if (cin.get() != '\n')
				cin.unget();
			getline(cin, checking);
		}
		else { a = 0; }
	}
	return checking;

}
int keyboardInput(int numberOfStudents) {
	numberOfStudents++;
	Students.numberOfStudentsOp = numberOfStudents;
	if (numberOfStudents > 1) {
		file.open(fileBuf, ios_base::out | ios_base::in | ios_base::ate);
	}
	else { file.open(fileBuf, ios_base::out | ios_base::in | ios_base::trunc); }
	string checking;
	cout << "Введите данные о студенте. После каждого блока ввода жмите Enter! " << endl << endl;
	cout << "Введите фамилию ";
	cin >> Students.surName;
	cin.ignore(INT_MAX, '\n');
	Students.surName = checkString(Students.surName);
	cout << "Введите имя ";
	cin >> Students.name;
	cin.ignore(INT_MAX, '\n');
	Students.name = checkString(Students.name);
	cout << "Введите отчество ";
	cin >> Students.secondName;
	cin.ignore(INT_MAX, '\n');
	Students.secondName = checkString(Students.secondName);
	int a = 1;
	cout << "Введите м/М или ж/Ж. ";
	while (a) {
		cin >> Students.sex;
		cin.ignore(INT_MAX, '\n');
		if (!(Students.sex == -20 || Students.sex == -26 || Students.sex == -52 || Students.sex == -58)) {
			cout << "Введите м/М или ж/Ж! ";
		}
		else { a = 0; }
	}
	a = 1;
	cout << "Введите день рождения студента ";
	cin >> checking;
	cin.ignore(INT_MAX, '\n');
	Students.date = checkInt(checking);
	while (a) {
		if (Students.date < 1 || Students.date>31) {
			cout << "В месяце может быть от 1 до 31 дня, введите заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
		else { a = 0; }
	}
	cout << "Введите месяц, в который родился студент ";
	cin >> checking;
	cin.ignore(INT_MAX, '\n');
	Students.month = checkInt(checking);
	a = 1;
	while (a) {
		if (Students.month < 1 || Students.month>12) {
			cout << "Это число должно быть от 1 до 12, исправьтесь! ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.month = checkInt(checking);
		}
		else { a = 0; }
	}
	cout << "Введите год рождения ";
	cin >> checking;
	cin.ignore(INT_MAX, '\n');
	Students.year = checkInt(checking);
	a = 1;
	while (a) {
		if (!(Students.year > 1903)) {
			cout << "Да ладно, вы не настолько стары, введите свой настоящий год рождения ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.year = checkInt(checking);
		}
		else { a = 0; }
	}
	a = 1;
	while (a) {
		switch (Students.month) {
		case 1: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В январе 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 2:
		{
			if ((Students.year % 4 == 0) & (!((Students.date > 0) & (Students.date <= 29)))) {
				cout << "В феврале " << Students.year << " года 29 дней, а не " << Students.date << ". Введите день заново ";
				cin >> checking;
				cin.ignore(INT_MAX, '\n');
				Students.date = checkInt(checking);
			}
			else {
				if ((Students.year % 4 != 0) & (!((Students.date > 0) & (Students.date <= 28)))) {
					cout << "В феврале " << Students.year << " года 28 дней, а не " << Students.date << ". Введите день заново ";
					cin >> checking;
					cin.ignore(INT_MAX, '\n');
					Students.date = checkInt(checking);
				}
				else { a = 0; }
			}
			break; }
		case 3: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В марте 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 4: {if (!((Students.date > 0) & (Students.date <= 30))) {
			cout << "В апреле 30 дней, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 5: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В мае 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 6: {if (!((Students.date > 0) & (Students.date <= 30))) {
			cout << "В июне 30 дней, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 7: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В июле 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 8: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В августе 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 9: {if (!((Students.date > 0) & (Students.date <= 30))) {
			cout << "В сентябре 30 дней, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			  else { a = 0; }
			  break; }
		case 10: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В октябрк 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			   else { a = 0; }
			   break; }
		case 11: {if (!((Students.date > 0) & (Students.date <= 30))) {
			cout << "В ноябре 30 дней, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			   else { a = 0; }
			   break; }
		case 12: {if (!((Students.date > 0) & (Students.date <= 31))) {
			cout << "В декабре 31 день, а не " << Students.date << ". Введите день заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.date = checkInt(checking);
		}
			   else { a = 0; }
			   break; }
		default: {cout << "В году 12 месяцев, а не " << Students.month << ". Введите месяц заново ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.month = checkInt(checking); break; }
		}
	}
	a = 1;
	cout << "Введите год поступления в ВУЗ ";
	cin >> checking;
	cin.ignore(INT_MAX, '\n');
	Students.admissionYear = checkInt(checking);
	while (a) {
		if (!(Students.admissionYear > (Students.year + 7))) {
			cout << "Вы не могли поступить в ВУЗ раньше своего рождения или до школы. Введите год поступления ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.admissionYear = checkInt(checking);
		}
		else { a = 0; }
	}
	a = 1;
	cout << "Введите факультет ";
	if (cin.get() != '\n')
		cin.unget();
	getline(cin, Students.faculty);
	Students.faculty = checkString(Students.faculty);
	cout << "Введите кафедру ";
	if (cin.get() != '\n')
		cin.unget();
	getline(cin, Students.department);
	Students.department = checkString(Students.department);
	cout << "Введите группу ";
	if (cin.get() != '\n')
		cin.unget();
	getline(cin, Students.group);
	cout << "Введите номер зачётки ";
	cin >> Students.examBookNumber;
	Students.examBookNumber = checkString(Students.examBookNumber);
	cin.ignore(INT_MAX, '\n');
	a = numberOfStudents - 1;
	string* different = new string;
	*different = Students.examBookNumber;
	if (numberOfStudents > 1) {
		file.close();
		while (a) {
			for (int i = 0; i < numberOfStudents - 1; i++) {
				Students1.numberOfStudentsOp = numberOfStudents - 1;
				Students1[i + 1];
				if (Students1.examBookNumber == *different) {
					cout << "Номер зачётной книжки совпадает с номером другого студента. Введите заново ";
					cin >> *different;
					cin.ignore(INT_MAX, '\n');
					*different = checkString(*different);
					a = numberOfStudents - 1;
				}
				else { a--; }
			}
		}
		file.open(fileBuf, ios_base::out | ios_base::ate | ios_base::app);
	}
	Students.examBookNumber = *different;
	delete different;
	a = 1;
	cout << "Сколько сессий сдал студент? ";
	cin >> checking;
	cin.ignore(INT_MAX, '\n');
	Students.numberOfSessions = checkInt(checking);
	while (a) {
		if (!((Students.numberOfSessions > 0) & (Students.numberOfSessions <= 9))) {
			cout << "Максимум 9 сессий и не меньше 1. Исправьтесь! ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.numberOfSessions = checkInt(checking);
		}
		else { a = 0; }
	}
	for (int j = 0; j < Students.numberOfSessions; j++) {
		a = 1;
		cout << "Сколько предметов студент сдавал в " << j + 1 << " сессии? ";
		cin >> checking;
		cin.ignore(INT_MAX, '\n');
		Students.sessions[j].numberOfSubjects = checkInt(checking);
		while (a) {
			if (!((Students.sessions[j].numberOfSubjects > 0) & (Students.sessions[j].numberOfSubjects <= 10))) {
				cout << "Максимум 10 предметов, минимум 1. Исправьте ошибку! ";
				cin >> checking;
				cin.ignore(INT_MAX, '\n');
				Students.sessions[j].numberOfSubjects = checkInt(checking);
			}
			else { a = 0; }
		}
		for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
			cout << "Введите название предмета ";
			if (cin.get() != '\n')
				cin.unget();
			getline(cin, Students.sessions[j].subjects[k].subjectName);
			Students.sessions[j].subjects[k].subjectName = checkString(Students.sessions[j].subjects[k].subjectName);
			cout << "Введите оценку по этому предмету ";
			cin >> checking;
			cin.ignore(INT_MAX, '\n');
			Students.sessions[j].subjects[k].mark = checkInt(checking);
			a = 1;
			while (a) {
				if (!((Students.sessions[j].subjects[k].mark >= 2) & (Students.sessions[j].subjects[k].mark <= 5))) {
					cout << "Оценка должна быть от 2 до 5. Введите заново ";
					cin >> checking;
					cin.ignore(INT_MAX, '\n');
					Students.sessions[j].subjects[k].mark = checkInt(checking);
				}
				else { a = 0; }
			}
		}
	}
	file << numberOfStudents << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
	file << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
	for (int i = 0; i < Students.numberOfSessions; i++) {
		file << Students.sessions[i].numberOfSubjects << "*";
		for (int j = 0; j < Students.sessions[i].numberOfSubjects; j++) {
			file << Students.sessions[i].subjects[j].subjectName << "*" << Students.sessions[i].subjects[j].mark << "*";
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[i].subjects[j].subjectName = "f";
			Students.sessions[i].subjects[j].mark = 0;
		}
	}
	file << '\n';
	file.close();
	Students.numberOfStudentsOp = numberOfStudents;
	return numberOfStudents;
}
void dataBaseInput(int number) {
	file.open(fileBuf, ios_base::out | ios_base::ate | ios_base::app);
	file << number << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
	file << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
	for (int i = 0; i < 3; i++) {
		file << 5 << "*";
		for (int j = 0; j < 5; j++) {
			Students.sessions[i].subjects[j].mark = rand() % 4 + 2;
			file << Students.sessions[i].subjects[j].subjectName << "*" << Students.sessions[i].subjects[j].mark << "*";
		}
	}
	file << "\n";
	file.close();
}
void DataBase() {
	fileBuf = fileDataBase;
	file.open(fileBuf, ios_base::trunc | ios_base::out);
	file.close();
	Students.numberOfSessions = 3;
	for (int j = 0; j < 3; j++) {
		Students.sessions[j].subjects[0].subjectName = "ВВПД";
		Students.sessions[j].subjects[1].subjectName = "ОИБ";
		Students.sessions[j].subjects[2].subjectName = "СИБ";
		Students.sessions[j].subjects[3].subjectName = "УП";
		Students.sessions[j].subjects[4].subjectName = "ЯП";
	}
	Students.surName = "Алексеев";
	Students.name = "Денис";
	Students.secondName = "Иванович";
	Students.faculty = "А";
	Students.department = "А1";
	Students.group = "ААА1";
	Students.examBookNumber = "20Б0689";
	Students.sex = 'М';
	Students.date = 30;
	Students.month = 4;
	Students.year = 1985;
	Students.admissionYear = Students.year + 18;
	dataBaseInput(1);
	Students.surName = "Ефимова";
	Students.name = "Таисия";
	Students.secondName = "Платоновна";
	Students.faculty = "А";
	Students.department = "А1";
	Students.group = "ААА1";
	Students.examBookNumber = "20Б0784";
	Students.sex = 'Ж';
	Students.date = 18;
	Students.month = 7;
	Students.year = 1985;
	Students.admissionYear = Students.year + 18;
	dataBaseInput(2);
	Students.surName = "Котов";
	Students.name = "Фёдор";
	Students.secondName = "Артемович";
	Students.faculty = "А";
	Students.department = "А1";
	Students.group = "ААА1";
	Students.examBookNumber = "20Б0389";
	Students.sex = 'М';
	Students.date = 2;
	Students.month = 6;
	Students.year = 1987;
	Students.admissionYear = Students.year + 18;
	dataBaseInput(3);
	Students.surName = "Лазарева";
	Students.name = "Варвара";
	Students.secondName = "Михайловна";
	Students.faculty = "А";
	Students.department = "А1";
	Students.group = "ААА1";
	Students.examBookNumber = "20Б0289";
	Students.sex = 'Ж';
	Students.date = 8;
	Students.month = 2;
	Students.year = 1988;
	Students.admissionYear = Students.year + 18;
	dataBaseInput(4);
	Students.surName = "Мешкова";
	Students.name = "Полина";
	Students.secondName = "Львовна";
	Students.faculty = "А";
	Students.department = "А1";
	Students.group = "ААА1";
	Students.examBookNumber = "20Б0769";
	Students.sex = 'Ж';
	Students.date = 5;
	Students.month = 3;
	Students.year = 1991;
	Students.admissionYear = Students.year + 18;
	dataBaseInput(5);
	Students.surName = "Потапов";
	Students.name = "Александр";
	Students.secondName = "Платонович";
	Students.faculty = "В";
	Students.department = "В1";
	Students.group = "ВВВ1";
	Students.examBookNumber = "20Б0689";
	Students.sex = 'М';
	Students.date = 8;
	Students.month = 5;
	Students.year = 1993;
	Students.admissionYear = Students.year + 18;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[i].subjects[j].subjectName = "f";
			Students.sessions[i].subjects[j].mark = 0;
		}
	}
	numberOfStudentsBase = 5;
	Students.numberOfStudentsOp = 5;
}

void printAllInfo(int numberOfStudents) {
	Students.numberOfStudentsOp = numberOfStudents;
	for (int i = 0; i < numberOfStudents; i++) {
		Students[i + 1];
		int longest = 8, longest2 = 9;
		if (longest < Students.surName.length())
			longest = Students.surName.length();
		if (longest < Students.secondName.length())
			longest = Students.secondName.length();
		if (longest < Students.name.length())
			longest = Students.name.length();
		int maxSubject = 0;
		for (int sub = 0; sub < Students.numberOfSessions; sub++) {
			if (maxSubject < Students.sessions[sub].numberOfSubjects) {
				maxSubject = Students.sessions[sub].numberOfSubjects;
			}
		}
		longest++;
		cout.setf(ios::fixed);
		cout << left;
		cout << setw(4) << "№" << setw(longest) << "Фамилия" << setw(longest) << "Имя" << setw(longest) << "Отчество" << setw(5) << "Пол" << setw(12) << "Дата рожд." << setw(12) << "Год поступ." << left;
		for (int k = 0; k < numberOfStudents; k++) {
			if (longest2 < Students.faculty.length())
				longest2 = Students.faculty.length();
			if (longest2 < Students.department.length())
				longest2 = Students.department.length();
			if (longest2 < Students.group.length()) {
				longest2 = Students.group.length();
			}
		}
		longest2++;
		cout << setw(longest2) << "Факультет" << setw(longest2) << "Кафедра" << setw(longest2) << "Группа" << setw(11) << "Номер зач." << left;
		cout << endl;
		cout << setw(4) << i + 1 << setw(longest) << Students.name << setw(longest) << Students.surName << setw(longest) << Students.secondName << setw(5) << Students.sex;
		if (Students.date < 10)
			cout << "0" << Students.date << ".";
		else
			cout << Students.date << "." << left;
		if (Students.month < 10)
			cout << "0" << Students.month << "." << left;
		else
			cout << Students.month << "." << left;
		cout << setw(6) << Students.year << left;
		cout << setw(12) << Students.admissionYear << setw(longest2) << Students.faculty << setw(longest2) << Students.department << setw(longest2) << Students.group << setw(11) << Students.examBookNumber << left;
		cout << endl;
		longest = 6;
		cout << endl;
		for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
			for (int subnum = 0; subnum < Students.sessions[sesnum].numberOfSubjects; subnum++) {
				if (longest < Students.sessions[sesnum].subjects[subnum].subjectName.length()) {
					longest = Students.sessions[sesnum].subjects[subnum].subjectName.length();
				}
			}
		}
		longest++;
		for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
			cout << setw(7) << "Сессия " << setw(2) << sesnum + 1 << setw(longest - 6) << " " << "|" << setw(2) << " " << left;
		}
		cout << endl;
		for (int subnum = 0; subnum < maxSubject; subnum++) {
			for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
				if (Students.sessions[sesnum].subjects[subnum].subjectName != "f") {
					cout << setw(longest + 1) << Students.sessions[sesnum].subjects[subnum].subjectName << setw(2) << Students.sessions[sesnum].subjects[subnum].mark << setw(3) << "|" << left;

				}
				else {
					cout << setw(longest + 6) << left;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[i].subjects[j].subjectName = "f";
			Students.sessions[i].subjects[j].mark = 0;
		}
	}
}
void printOne(string book, int numberOfStudents) {
	int number = 0, a = 1;
	cout.setf(ios::fixed);
	cout << left;
	Students.numberOfStudentsOp = numberOfStudents;
	while (a) {
		for (int i = 0; i < numberOfStudents; i++) {
			Students[i + 1];
			if (Students.examBookNumber == book) {
				number = i + 1;
			}
		}
		if (number == 0) {
			cout << "Студента с таким номером зачётной книжки нет. Введите номер заново ";
			cin >> book;
			cin.ignore(INT_MAX, '\n');
		}
		else { a = 0; }
	}
	number = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		Students[i + 1];
		if (Students.examBookNumber == book) {
			int longest = 8, longest2 = 9;

			for (int k = 0; k < numberOfStudents; k++) {
				if (longest < Students.surName.length())
					longest = Students.surName.length();
				if (longest < Students.secondName.length())
					longest = Students.secondName.length();
			}
			int maxSubject = 0;
			for (int sub = 0; sub < Students.numberOfSessions; sub++) {
				if (maxSubject < Students.sessions[sub].numberOfSubjects) {
					maxSubject = Students.sessions[sub].numberOfSubjects;
				}
			}
			longest++;
			cout.setf(ios::fixed);
			cout << left;
			cout << setw(4) << "№" << setw(longest) << "Фамилия" << setw(longest) << "Имя" << setw(longest) << "Отчество" << setw(5) << "Пол" << setw(12) << "Дата рожд." << setw(12) << "Год поступ." << left;
			for (int k = 0; k < numberOfStudents; k++) {
				if (longest2 < Students.faculty.length())
					longest2 = Students.faculty.length();
				if (longest2 < Students.department.length())
					longest2 = Students.department.length();
				if (longest2 < Students.group.length()) {
					longest2 = Students.group.length();
				}
			}
			longest2++;
			cout << setw(longest2) << "Факультет" << setw(longest2) << "Кафедра" << setw(longest2) << "Группа" << setw(11) << "Номер зач." << left;
			cout << endl;
			cout << setw(4) << i + 1 << setw(longest) << Students.name << setw(longest) << Students.surName << setw(longest) << Students.secondName << setw(5) << Students.sex;
			if (Students.date < 10)
				cout << "0" << Students.date << ".";
			else
				cout << Students.date << "." << left;
			if (Students.month < 10)
				cout << "0" << Students.month << "." << left;
			else
				cout << Students.month << "." << left;
			cout << setw(6) << Students.year << left;
			cout << setw(12) << Students.admissionYear << setw(longest2) << Students.faculty << setw(longest2) << Students.department << setw(longest2) << Students.group << setw(11) << Students.examBookNumber << left;
			cout << endl;
			longest = 6;
			cout << endl;
			for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
				for (int subnum = 0; subnum < Students.sessions[sesnum].numberOfSubjects; subnum++) {
					if (longest < Students.sessions[sesnum].subjects[subnum].subjectName.length()) {
						longest = Students.sessions[sesnum].subjects[subnum].subjectName.length();
					}
				}
			}
			longest++;
			for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
				cout << setw(7) << "Сессия " << setw(2) << sesnum + 1 << setw(longest - 6) << " " << "|" << setw(2) << " " << left;
			}
			cout << endl;
			for (int subnum = 0; subnum < maxSubject; subnum++) {
				for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
					if (Students.sessions[sesnum].subjects[subnum].subjectName != "f") {
						cout << setw(longest + 1) << Students.sessions[sesnum].subjects[subnum].subjectName << setw(2) << Students.sessions[sesnum].subjects[subnum].mark << setw(3) << "|" << left;

					}
					else {
						cout << setw(longest + 6) << left;
					}
				}
				cout << endl;
			}

			for (int subnum = 0; subnum < maxSubject; subnum++) {
				for (int sesnum = 0; sesnum < Students.numberOfSessions; sesnum++) {
					Students.sessions[sesnum].subjects[subnum].subjectName = "f";
					Students.sessions[sesnum].subjects[subnum].mark = 0;
				}
			}
			cout << endl;
		}
		else {
			for (int k = 0; k < 9; k++) {
				for (int j = 0; j < 10; j++) {
					Students.sessions[k].subjects[j].subjectName = "f";
					Students.sessions[k].subjects[j].mark = 0;
				}
			}
		}
	}
}
void task(int first, int second, int numberOfStudents) {
	cout << left;
	Students.numberOfStudentsOp = numberOfStudents;
	int count2 = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		Students[i + 1];
		int count = 0, count3 = 0;
		if ((Students.year >= first) & (Students.year <= second)) {
			for (int j = 0; j < Students.numberOfSessions; j++) {
				for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
					if ((Students.sessions[j].subjects[k].mark > 1) & (Students.sessions[j].subjects[k].mark < 6)) {
						count++;
						if (Students.sessions[j].subjects[k].mark == 3)
							count3++;
					}
				}
			}
		}
		if (double(count3) / double(count) <= 0.25) {
			count2++;
			if (count2 == 1)
				cout << "У этих учеников меньше 25% троек:" << endl;
			cout << Students.name << " " << Students.surName << " " << Students.secondName << " " << Students.examBookNumber << left << endl;
		}
	}

	if (count2 == 0) {
		cout << "Все студенты хорошо учились или родились в другой временной промежуток" << endl;
	}
	for (int k = 0; k < 9; k++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[k].subjects[j].subjectName = "f";
			Students.sessions[k].subjects[j].mark = 0;
		}
	}

}
int deleteStudent(string book, int numberOfStudents) {
	int number = 0, a = 1;
	fstream file1;
	string buffer, filename = fileBuf;
	file1.open(fileBuf, ios_base::in | ios_base::app);
	file.open("Буффер.txt", ios_base::out);
	for (int i = 0; i < numberOfStudents; i++) {
		getline(file1, buffer, '\n');
		file << buffer << "\n";
	}
	file1.close();
	fileBuf = "Буффер.txt";
	file.close();
	while (a) {
		for (int i = 0; i < numberOfStudents; i++) {
			Students[i + 1];
			if (Students.examBookNumber == book) {
				number = i + 1;
			}
		}
		if (number == 0) {
			cout << "Студента с таким номером зачётной книжки нет. Введите номер заново ";
			cin >> book;
			cin.ignore(INT_MAX, '\n');
		}
		else { a = 0; }
	}
	number = 0;
	file1.open(filename, ios_base::out | ios_base::trunc);
	for (int i = 0; i < numberOfStudents; i++) {
		Students[i + 1];
		if (Students.examBookNumber == book) {
			number = i + 1;
		}
		else {
			if (number == 0) {
				file1 << i + 1 << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
				file1 << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
				for (int j = 0; j < Students.numberOfSessions; j++) {
					file1 << Students.sessions[j].numberOfSubjects << "*";
					for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
						Students.sessions[j].subjects[k].mark = rand() % 4 + 2;
						file1 << Students.sessions[j].subjects[k].subjectName << "*" << Students.sessions[j].subjects[k].mark << "*";
					}
				}
				file1 << "\n";
			}
			else {
				file1 << i << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
				file1 << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
				for (int j = 0; j < Students.numberOfSessions; j++) {
					file1 << Students.sessions[j].numberOfSubjects << "*";
					for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
						Students.sessions[j].subjects[k].mark = rand() % 4 + 2;
						file1 << Students.sessions[j].subjects[k].subjectName << "*" << Students.sessions[j].subjects[k].mark << "*";
					}
				}
				file1 << "\n";
			}
		}

	}
	file1.close();
	remove("Буффер.txt");
	fileBuf = filename;
	return --numberOfStudents;
	for (int k = 0; k < 9; k++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[k].subjects[j].subjectName = "f";
			Students.sessions[k].subjects[j].mark = 0;
		}
	}

}
void changeInfo(string book, int numberOfStudents) {
	int number = 0, a = 1;
	fstream file1;
	string buffer, filename;
	filename = fileBuf;
	Students.numberOfStudentsOp = numberOfStudents;
	file1.open(fileBuf, ios_base::in | ios_base::app);
	file.open("Буффер.txt", ios_base::out);
	for (int i = 0; i < numberOfStudents; i++) {
		getline(file1, buffer, '\n');
		file << buffer << "\n";
	}
	file1.close();
	fileBuf = "Буффер.txt";
	file.close();
	while (a) {
		for (int i = 0; i < numberOfStudents; i++) {
			Students[i + 1];
			if (Students.examBookNumber == book) {
				number = i + 1;
			}
		}
		if (number == 0) {
			cout << "Студента с таким номером зачётной книжки нет. Введите номер заново ";
			cin >> book;
			cin.ignore(INT_MAX, '\n');
		}
		else { a = 0; }
	}
	number = 0;
	file1.open(filename, ios_base::out | ios_base::trunc);
	for (int i = 0; i < numberOfStudents; i++) {
		Students[i + 1];
		if (Students.examBookNumber == book) {
			number = i + 1;
			Students1 = Students;
		}
		else {
			if (number == 0) {
				file1 << i + 1 << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
				file1 << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
				for (int j = 0; j < Students.numberOfSessions; j++) {
					file1 << Students.sessions[j].numberOfSubjects << "*";
					for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
						file1 << Students.sessions[j].subjects[k].subjectName << "*" << Students.sessions[j].subjects[k].mark << "*";
					}
				}
				file1 << "\n";
			}
			else {
				file1 << i << "*" << Students.surName << "*" << Students.name << "*" << Students.secondName << "*" << Students.sex << "*" << Students.date << "*" << Students.month << "*" << Students.year << "*" << Students.admissionYear << "*" << Students.faculty << "*" << Students.department << "*" << Students.group << "*";
				file1 << Students.examBookNumber << "*" << Students.numberOfSessions << "*";
				for (int j = 0; j < Students.numberOfSessions; j++) {
					file1 << Students.sessions[j].numberOfSubjects << "*";
					for (int k = 0; k < Students.sessions[j].numberOfSubjects; k++) {
						file1 << Students.sessions[j].subjects[k].subjectName << "*" << Students.sessions[j].subjects[k].mark << "*";
					}
				}
				file1 << "\n";
			}
		}

	}

	file1.close();
	remove("Буффер.txt");
	fileBuf = filename;
	keyboardInput(numberOfStudents - 1);
	for (int k = 0; k < 9; k++) {
		for (int j = 0; j < 10; j++) {
			Students.sessions[k].subjects[j].subjectName = "f";
			Students.sessions[k].subjects[j].mark = 0;
		}
	}
}
void save(int numberOfStudents) {
	fstream file1;
	string buffer, fileName;
	cout << "Введите название файла, куда желаете сохранить информацию о студентах(без расширения) ";
	if (cin.get() != '\n')
		cin.unget();
	getline(cin, fileName);
	fileName += ".txt";
	Students.numberOfStudentsOp = numberOfStudents;
	file1.open(fileBuf, ios_base::in | ios_base::app);
	file.open(fileName, ios_base::out);
	for (int i = 0; i < numberOfStudents; i++) {
		getline(file1, buffer, '\n');
		file << buffer << "\n";
	}
	file1.close();
	file.close();
}
void Menu::choice() {
	string decision;
	int a = 1, decisionInt;
	while (a) {
		system("cls");
		cout << "Добро пожаловать! Работу выполнил Дудников Антон Алексеевич, БББО-05-20. Номер книжки: 20Б0789. Вариант 89." << left << endl << endl;
	l:cout << "Выберите действие:" << endl;
		cout << "Б/б, если хотите работать с базой данных" << endl;
		cout << "С/с, если хотите работать со своими данными" << endl;
		cout << "К/к, если хотите завершить работу с программой" << endl << ">";
		cin >> decision;
		cin.ignore(INT_MAX, '\n');
		if (decision == "к" || decision == "К") {
			break;
		}
		else {
			if (decision == "б" || decision == "Б") {
				system("cls");
				if (numberOfStudentsBase == 5) {
					DataBase();
				}
				fileBuf = fileDataBase;
				cout << "Следующие студенты есть в базе данных:" << endl << endl;
				printAllInfo(numberOfStudentsBase);
				int base = 1;
				while (base) {
					cout << "Выберите действие:" << left << endl;
					cout << "1)Добавление студента" << left << endl;
					cout << "2)Изменение информации о студенте" << left << endl;
					cout << "3)Вывод информации о конкретном студенте по номеру зачётной книжки" << left << endl;
					cout << "4)Удаление студента из базы данных" << left << endl;
					cout << "5)Вывод студентов, у которых меньше 25% троек за всё время обучения с указанием года рождения" << left << endl;
					cout << "6)Вывести информацию о всех студентах" << endl << left;
					cout << "7)Сохранить данные в файл, название которого зададите вы" << endl;
					cout << "8)Вернуться в главное меню " << left << endl << ">";
					cin >> decision;
					cin.ignore(INT_MAX, '\n');
					decisionInt = checkInt(decision);
					switch (decisionInt) {
					case(1): {
						int b = 1;
						while (b) {
							system("cls");
							cout << "Желаете добавить студента? 1.Да 0.Нет ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							decisionInt = checkInt(decision);
							if (decisionInt == 1) {
								numberOfStudentsBase = keyboardInput(numberOfStudentsBase);
							}
							else {
								if (decisionInt == 0) {
									b = 0;
								}
								else {
									cout << "Нет такого варианта. Выберите заново> ";
								}
							}
						}
						break;
					}
					case(2): {
						if (numberOfStudentsBase != 0) {
							cout << "Введите номер зачётной книжки студента, информацию о котором хотите изменить> ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							changeInfo(decision, numberOfStudentsBase);
							system("cls");
						}
						else {
							system("cls");
							cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
						}
						break; }
					case(3): {
						if (numberOfStudentsBase != 0) {
							cout << "Введите номер зачётной книжки студента, информацию о котором хотите вывести> ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							printOne(decision, numberOfStudentsBase);
						}
						else {
							system("cls");
							cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
						}
						break;
					}
					case(4): {
						if (numberOfStudentsBase != 0) {
							cout << "Введите номер зачётной книжки студента, информацию о котором хотите удалить> ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							numberOfStudentsBase = deleteStudent(decision, numberOfStudentsBase);
							system("cls");
						}
						else {
							system("cls");
							cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
						}
						break;
					}
					case(5): {

						if (numberOfStudentsBase != 0) {
							system("cls");
							int first, second;
							cout << "Введите первый год ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							first = checkInt(decision);
							cout << "Введите второй год ";
							cin >> decision;
							cin.ignore(INT_MAX, '\n');
							second = checkInt(decision);
							if (second < first) {
								int c = second;
								second = first;
								first = c;
							}
							task(first, second, numberOfStudentsBase);
						}
						else {
							system("cls");
							cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
						}
						break;
					}
					case(6): {
						if (numberOfStudentsBase != 0) {
							system("cls");
							printAllInfo(numberOfStudentsBase);
						}
						else { cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left; }
						break; }
					case(7): {
						if (numberOfStudentsBase != 0) {
							save(numberOfStudentsBase);
							system("cls");
							cout << "Данные успешно сохранены" << endl;
						}
						else {
							system("cls");
							cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
						}
						break; }
					case(8): {base = 0; break; }
					default: {cout << "Такого варианта нет!" << endl;
						break;
					}
					}
				}

			}
			else {
				if (decision == "с" || decision == "С") {
					int own = 1;
					system("cls");
					while (own) {
						fileBuf = fileOwn;
						cout << "Выберите действие:" << left << endl;
						cout << "1)Добавление студента" << left << endl;
						cout << "2)Изменение информации о студенте" << left << endl;
						cout << "3)Вывод информации о конкретном студенте по номеру зачётной книжки" << left << endl;
						cout << "4)Удаление студента" << left << endl;
						cout << "5)Вывод студентов, у которых меньше 25% троек за всё время обучения с указанием интервала года рождения" << left << endl;
						cout << "6)Вывести информацию о всех студентах" << left << endl;
						cout << "7)Сохранить данные в файл, название которого зададите вы" << left << endl;
						cout << "8)Работа с файлом, название которого зададите вы" << endl;
						cout << "9)Вернуться в главное меню " << left << endl << ">";
						cin >> decision;
						cin.ignore(INT_MAX, '\n');
						decisionInt = checkInt(decision);
						switch (decisionInt) {
						case(1): {
							int b = 1;
							while (b) {
								system("cls");
								cout << "Желаете добавить студента? 1.Да 0.Нет ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								decisionInt = checkInt(decision);
								if (decisionInt == 1) {
									numberOfStudentsOwn = keyboardInput(numberOfStudentsOwn);
								}
								else {
									if (decisionInt == 0) {
										b = 0;
									}
									else {
										cout << "Нет такого варианта. Выберите заново ";
									}
								}
							}
							break;
						}
						case(2): {
							if (numberOfStudentsOwn != 0) {
								cout << "Введите номер зачётной книжки студента, информацию о котором хотите изменить> ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								changeInfo(decision, numberOfStudentsOwn);
								system("cls");
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(3): {
							if (numberOfStudentsOwn != 0) {
								cout << "Введите номер зачётной книжки студента, информацию о котором хотите вывести> ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								printOne(decision, numberOfStudentsOwn);
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(4): {
							if (numberOfStudentsOwn != 0) {
								cout << "Введите номер зачётной книжки студента, информацию о котором хотите удалить> ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								numberOfStudentsOwn = deleteStudent(decision, numberOfStudentsOwn);
								system("cls");
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(5): {
							if (numberOfStudentsOwn != 0) {
								int first, second;
								cout << "Введите первый год ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								first = checkInt(decision);
								cout << "Введите второй год ";
								cin >> decision;
								cin.ignore(INT_MAX, '\n');
								second = checkInt(decision);
								if (second < first) {
									int c = second;
									second = first;
									first = c;
								}
								task(first, second, numberOfStudentsOwn);
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(6): {
							system("cls");
							if (numberOfStudentsOwn != 0) {
								printAllInfo(numberOfStudentsOwn);
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(7): {
							if (numberOfStudentsOwn != 0) {
								save(numberOfStudentsOwn);
							}
							else {
								system("cls");
								cout << "Студентов в базе пока нет, добавьте хотя бы одного" << endl << left;
							}
							break;
						}
						case(8): {
							string fileName, number;
							cout << "Введите название файла, с которым желаете работать(без расширения)> ";
							if (cin.get() != '\n')
								cin.unget();
							getline(cin, fileName);
							fileName += ".txt";
							file.open(fileName, ios_base::in);
							if (file.is_open()) {
								while (!file.eof()) {
									getline(file, number, '*');
									if (number != "") {
										numberOfStudentsOwn = checkInt(number);
										Students.numberOfStudentsOp = checkInt(number);
										getline(file, number, '\n');
									}
								}
								fileOwn = fileName;
								file.close();
								system("cls");
								cout << "Файл выбран успешно" << endl;
							}
							else {
								system("cls");
								cout << "Такого файла нет! Попробуйте снова или выберите другое действие. " << endl << endl;
							}

							break;
						}
						case(9): {own = 0; break; }
						default: {cout << "Такого варианта нет! " << endl;
							break;
						}
						}
					}
				}
				else {
					system("cls");
					cout << "Такого варианта нет, выберите заново!\n>";
					goto l;
				}
			}
		}
	}

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	setlocale(0, "Rus");
	Menu menu;
	
}
