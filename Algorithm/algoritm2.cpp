
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include<string.h>
#include <iostream>
using namespace std;

FILE* f;
const char* fn = "db.bin";

int amount_of_apartments = 0;

struct kvartira {
	char kvnum[20];
	char rnum[20];
	char flrnum[20];
	char square[100];
	char balkon[3];
	char pricefactor[3];
};
void read_db();
void add_one_record();
void out_all_record();
void out_one_record(int);
void edit_one_record(int);
void delete_one_record(int);

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	read_db();
	cout << "Выберите функцию:\n";
	cout << "1. Вывести все записи на экран\n";
	cout << "2. Вывести отдельную запись на экран\n";
	cout << "3. Добавить в файл новую запись\n";
	cout << "4. Редактировать произвольную запись\n";
	cout << "5. Удалить из файла произвольную запись\n";
	cin >> choice;

	if (choice == 1) {
		out_all_record();
	}
	else if (choice == 2) {
		int num;
		cout << "Выберите запись:";
		cin >> num;
		out_one_record(num);
	}
	else if (choice == 3) {
		add_one_record;
	}
	else if (choice == 4) {
		int num;
		cout << "Выберите запись:";
		cin >> num;
		edit_one_record(num);
	}
	else if (choice == 5) {
		int num;
		cout << "Выберите запись:";
		cin >> num;
		delete_one_record(num);
	}

	return 0;
}

void delete_one_record(int number) {
	kvartira temp;
	int i = 0;

	FILE* ftempf;
	const char* temp_fn = "temp.bin";

	ftempf = fopen(temp_fn, "wb+");
	f = fopen(fn, "rb+");

	while (!feof(f)) {
		fread(&temp, sizeof(temp), 1, f);
		i++;
		if (i <= amount_of_apartments) {
			if (i != number) {
				if (ftempf != nullptr) {
					fwrite(&temp, sizeof(temp), 1, ftempf);
				}
			}
		}
		if (feof(f))
			break;
	}
	rewind(f);
	fclose(f);
	rewind(ftempf);
	fclose(ftempf);
	remove("db.bin");
	rename("temp.bin", "db.bin");
	cout << "Запись была успешно удалена" << endl;
}
void edit_one_record(int number) {
	cout << "Данные: " << endl;
	out_one_record(number);
	string tmp;
	kvartira temp;
	cout << "Введите номер квартиры: ";
	cin >> tmp;
	strcpy(temp.kvnum, tmp.c_str());
	cout << "Введите количество комнат: ";
	cin >> tmp;
	strcpy(temp.rnum, tmp.c_str());
	cout << "Введите номер этажа: ";
	cin >> tmp;
	strcpy(temp.flrnum, tmp.c_str());
	cout << "Введите площадь: ";
	cin >> tmp;
	strcpy(temp.square, tmp.c_str());
	cout << "Есть ли в этой квартире балкон?:да/нет";
	cin >> tmp;
	strcpy(temp.balkon, tmp.c_str());
	cout << "Есть ли признак влияния на цену?:да/нет";
	cin >> tmp;
	strcpy(temp.pricefactor, tmp.c_str());
	amount_of_apartments++;
	cout << "Новая запись была успешно создана" << endl;
	number--;
	f = fopen(fn, "r+");
	fseek(f, number * sizeof(temp), 0);
	if (f != nullptr) {
		fwrite(&temp, sizeof(temp), 1, f);
	}
	rewind(f);
	fclose(f);
}

void out_one_record(int number) {
	kvartira temp;
	int i = 0;
	number--;
	f = fopen(fn, "rb+");
	fseek(f, number * sizeof(temp), 0);
	while (!feof(f)) {
		fread(&temp, sizeof(temp), 1, f);
		cout << "Номер квартиры: " << temp.kvnum << endl;
		cout << "Количество комнат: " << temp.rnum << endl;
		cout << "Номер этажа: " << temp.flrnum << endl;
		cout << "Площадь м^2: " << temp.square << endl;
		cout << "Балкон: " << temp.balkon << endl;
		cout << "Признак влияния на цену:" << temp.pricefactor << endl;
		cout << endl;
		break;
	}
	rewind(f);
	fclose(f);
}

void read_db() {
	kvartira temp;
	f = fopen(fn, "ab+");
	int i = 0;
	while (!feof(f))
	{
		fread(&temp, sizeof(temp), 1, f);
		i++;
		if (feof(f))
			break;
	}
	amount_of_apartments = i - 1;
	rewind(f);
	fclose(f);
}

void add_one_record() {

	string tmp;
	kvartira temp;
	cout << "Номер квартиры: ";
	cin >> tmp;
	strcpy(temp.kvnum, tmp.c_str());
	cout << "Количество комнат: ";
	cin >> tmp;
	strcpy(temp.rnum, tmp.c_str());
	cout << "Этаж: ";
	cin >> tmp;
	strcpy(temp.flrnum, tmp.c_str());
	cout << "Площадь м^2: ";
	cin >> tmp;
	strcpy(temp.square, tmp.c_str());
	cout << "Есть ли в этой квартире балкон?:да/нет ";
	cin >> tmp;
	strcpy(temp.balkon, tmp.c_str());
	amount_of_apartments++;
	cout << "Есть ли признак влияния на цену?:да/нет ";
	cin >> tmp;
	strcpy(temp.pricefactor, tmp.c_str());
	cout << "Новая запись была успешно добавлена" << endl;

	f = fopen(fn, "ab+");

	if (f != nullptr) {
		fwrite(&temp, sizeof(temp), 1, f);
	}
	rewind(f);
	fclose(f);
}

void out_all_record() {
	kvartira temp;
	int i = 0;
	f = fopen(fn, "rb+");
	while (!feof(f)) {
		fread(&temp, sizeof(temp), 1, f);
		i++;
		if (i <= amount_of_apartments) {
			cout << "Номер квартиры: " << i << endl;
			cout << "Количество комнат: " << temp.rnum << endl;
			cout << "Номер этажа: " << temp.flrnum << endl;
			cout << "Площадь м^2: " << temp.square << endl;
			cout << "Балкон: " << temp.balkon << endl;
			cout << "Признак влияния на цену: " << temp.pricefactor << endl;
			cout << endl;
		}
		if (feof(f))
			break;
	}
	rewind(f);
	fclose(f);
}