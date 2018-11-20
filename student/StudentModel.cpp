#include "StudentModel.h"


StudentModel::StudentModel()
{
	name = "";
	surName = "";
	middleName = "";
	number = 0;
	sex = 0;
	birth = "1990-01-01";
	mobile = "";
	email = "";
	adres = "";
	studyForm = 0;
	groupId = 0;
	kurs = 0;

	payStudy = false;
	prevStudy = "";
	family = "";
	isChildren = true;
	isNeedHostel = true;
	natinality = "";
	isMilitary = true;
	sport = "";
	olymps = "";
	arts = "";
	studyStart = "1990-01-01";
	studyEnd = "1990-01-01";
	groupName = "";

	fakultetId = 0;
	kafedraId = 0;
	napravlenieId = 0;
}


StudentModel::~StudentModel()
{
} 
 