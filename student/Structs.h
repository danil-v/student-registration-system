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

//���������
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


//������
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


//�������
struct Predmet
{
	int id;
	string name;	//�������
	int specialId;		//����� �������������
	int semestr;	//�������
	int hours;		//���������� �����
	int hoursLec;		//���������� �����
	int hoursPract;		//���������� �����
	int hoursLab;		//���������� �����
	string teacher;	//�������������
	int teacherId;
	bool zachet;	//�����
	bool kursov;	//��������
	bool pract;	//������������ �������
	bool exam;	//�������
	int predmetId;
};

//������� � �������
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

//������������
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



//����������, ���������, �����
struct Work
{
	int id;
	string data;
	int status;
};
