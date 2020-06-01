#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <chrono>

using namespace std;

HANDLE d = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));

	const int size = 100;
	int arr[size] = {};

	/*
		fill & sort + chrono
	*/	

	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 99;
	}

	cout << "Исходный массив: " << endl;
	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl << endl;

	auto start = chrono::high_resolution_clock::now();

	for (int i = size - 1; i >= 0; --i) {
		for (int n = 0; n < i; ++n) {
			if (arr[n] > arr[n + 1]) {
				swap(arr[n], arr[n + 1]);
			}
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float>res = end - start;
	cout.precision(2);

	cout << "Затраченое время на сортировку: \x1b[36m" << res.count() << "\x1b[37m секунд" << endl;
	cout.precision(2);

	cout << "Отсортированный массив: " << endl;

	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl << endl;

	/* 
		min & max + chrono
	*/

	int min = arr[0];
	int max = arr[0];

	auto startMin = chrono::high_resolution_clock::now();

		for (int i = 0; i < size; ++i) {
			if (arr[i] < min) min = arr[i];
			if (arr[i] > max) max = arr[i];
		}

	auto endMax = chrono::high_resolution_clock::now();

	chrono::duration<float>mmRes = endMax - startMin;

	cout << "Затраченое время на нахождение минимального и максимального элемента: \x1b[36m" << mmRes.count() << "\x1b[37m секунд" << endl;
	cout << "Минимальный элемент: \x1b[36m" << min << "\x1b[37m" << endl;
	cout << "Максимальный элемент: \x1b[36m" << max << "\x1b[37m" << endl << endl;
	
	/*
		find middle value
	*/

	int mid;
	int pos = 0;

	for (int i = 0; i < size; ++i) {
		 pos += arr[i];
		 mid = pos / size;
	}

	cout << "Среднее значение массива: \x1b[36m" << mid << "\x1b[37m" << endl << endl;

	/*
		arr[i] < a
		arr[i] > b
	*/

	int a, b;
	cout << "Введите число '\x1b[32ma\x1b[37m': \x1b[31m"; cin >> a; cout << "\x1b[37m";
	cout << "Введите число '\x1b[32mb\x1b[37m': \x1b[31m"; cin >> b; cout << "\x1b[37m";

	cout << endl << "Числа, которые меньше '\x1b[32ma\x1b[37m': " << endl;
	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		if (arr[i] > a) continue;
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl << endl;

	cout << "Числа, которые больше '\x1b[32mb\x1b[37m': " << endl;
	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		if (arr[i] < b) continue;
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl << endl;

	/*
		find user value
	*/

	int user, indx;

	cout << "Введите число, которое нужно найти: \x1b[31m"; cin >> user; cout << "\x1b[37m";

	for (int i = 0; i < size; ++i) {
		if (user == arr[i]) { indx = i; break; }
	}

	if (indx) {
		cout << "Ваш элемент присутствует в массиве, его индекс: \x1b[36m" << indx << "\x1b[37m" << endl;
		cout << "Значение индекса: \x1b[36m" << arr[indx] << "\x1b[37m" << endl;
	}
	if (!indx) {
		cout << "Вашего элемента нет в массиве." << endl;
	}

	/*
		replace elems
	*/

	int ord;
	cout << endl << "Введите кол-во индексов, которые будут переставлены: \x1b[31m"; cin >> ord; cout << "\x1b[37m";

	int* arr1 = new int[ord];
	int* arr2 = new int[ord];

	for (int i = 0; i < ord; ++i) {
		cout << "Заполните 1-ый массив: \x1b[31m"; cin >> arr1[i]; cout << "\x1b[37m";
	}
	cout << endl;

	for (int i = 0; i < ord; ++i) {
		cout << "Заполните 2-ой массив: \x1b[31m"; cin >> arr2[i]; cout << "\x1b[37m";
		swap(arr[arr1[i]], arr[arr2[i]]);
	}
	
	cout << "Массив, после переставления индексов: " << endl;
	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl;

	/*
		Lab 2
	*/

	cout << endl << endl << "\x1b[32m//Lab 2//\x1b[37m" << endl << endl;

	int userMinus;
	int umnVal = rand() % 9;

	cout << endl << "Введите значение, на которое каждый не четный элемент, будет уменьшен: \x1b[31m"; cin >> userMinus; cout << "\x1b[37m";
	cout << "Значение, на которое четные элементы, будут умножены: \x1b[36m" << umnVal << "\x1b[37m" << endl;
	
	cout << "Массив, после манипуляций: " << endl;
	SetConsoleTextAttribute(d, 14);
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0 || arr[i] % 9 == 0) {
			continue;
		}
		arr[i] *= umnVal;
	}

	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 0) {
			continue;
		}
		arr[i] -= userMinus;
	}

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << '\t';
	}
	cout << "\x1b[37m" << endl;
}