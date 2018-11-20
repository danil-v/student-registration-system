#pragma once
#include <string>

using namespace std;

class StudentModel
{
public:
	StudentModel();
	~StudentModel();

	int id;
	string name;
	string surName;
	string middleName;
	int number;
	int sex;
	string birth;
	string mobile;
	string email;
	string adres;
	int studyForm;
	int groupId;
	int kurs;
	int payStudy;
	string prevStudy;
	string family;
	bool isChildren;
	bool isNeedHostel;
	string natinality;
	bool isMilitary;
	string sport;
	string olymps;
	string arts;
	string studyStart;
	string studyEnd;
	string groupName;
	int fakultetId;
	int kafedraId;
	int napravlenieId;
};

