#pragma once
#include <string>

using namespace std;

struct Teacher
{
	int id;
	string fio;
	int kafedraId;
	string kafedra;
	string zvanie;
	string stepen;
};

//факультет
struct FakultetModel
{
	int id;
	string name;
};

struct KafedraModel
{
	int id;
	int fakultetId;
	string fakultetName;
	string name;
};

struct NapravlenieModel
{
	int id;
	int kafedraId;
	int fakultetId;
	string fakultetName;
	string kafedraName;
	string name;
};


//группа
struct GroupModel
{
	int id;
	int napravlenieId;
	int kafedraId;
	int fakultetId;
	string name;
	string fakultetName;
	string kafedraName;
	string napravlenieName;
};


//предмет
struct Predmet
{
	int id;
	string name;	//предмет
	int specialId;		//номер специальности
	int semestr;	//семестр
	int hours;		//количество часов
	int hoursLec;		//количество часов
	int hoursPract;		//количество часов
	int hoursLab;		//количество часов
	string teacher;	//преподаватель
	int teacherId;
	bool zachet;	//зачет
	bool kursov;	//курсовая
	bool pract;	//практическое задание
	bool exam;	//экзамен
	int predmetId;
};

//предмет с оценкой
struct PredmetsWithMarks
{
	int id;
	string fio;
	int number;
	int att1;
	int att2;
	int samost;
	int posesh;
	int recomend;
	int exam;
	int mark;

	int studentId;
	int predmetId;
	int teacherId;

	//int predmetId;
	string predmet;
	//string zachet;
	//string kursov;
	//string pract;
	//string exam;
	int hours;
	string teacher;
};

struct UspModel
{
	string fio;
	int userId;
	int number;
	float semestrs[8];
	float total;
};

//пользователь
struct User
{
	int id;

	string login;
	string pass;
	int access;
	int studentId;
	int teacherId;
	string student;
	string teacher;
};



//достижения, поручения, долги
struct Work
{
	int id;
	string data;
	int status;
};
