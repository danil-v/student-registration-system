#pragma once



#include <vector>
#include <string>

#include <my_global.h>
#include <mysql.h>

#include "Structs.h"
#include "StudentModel.h"

using namespace std;

namespace Student
{
	class MySQL
	{
	public:
		MySQL(void);
		~MySQL(void);

		//конфигурация базы данных
		string host;
		string base;
		string user;
		string pass;

		MYSQL *conn;


		bool init();	//подключение к бд
		void close();

		void addPredmet(Predmet *predmet);
		void deletePredmet(int id);
		vector<Predmet> *getPredmets(int semestr, int specialId);

		void addPredmetPlan(Predmet *predmet);
		void deletePredmetPlan(int id);
		vector<Predmet> *getPredmetsTeacher(int semestr, int specialId);
		//vector<Predmet> *getPredmetsTeacher();

		vector<User> *getUsers();		//получить список пользователей
		void addUser(User *user);
		void deleteUser(int id);
		int login(string login, string pass);

		vector<PredmetsWithMarks> *getMarks(int semestr, int disciplineId, int groupId);	//получить оценки студента в указанном семестре
		vector<PredmetsWithMarks> *getUserMarks(int userId, int kurs, int semestr);	//получить оценки студента в указанном семестре
		vector<UspModel> *getUserUspev(int groupId);
		vector<PredmetsWithMarks> *getDolgi(int groupId, int semestr);

		void addMark(PredmetsWithMarks *mark);
		void updateMark(PredmetsWithMarks *mark);
		
		vector<Work> *loadArchiev(int userId);	//получить достижения, достижения и долги
		vector<Work> *loadPoruch(int userId);
		vector<Work> *loadDolgi(int userId);

		static const int ARCHIEVMENT = 1;
		static const int TASK = 2;
		static const int TASK_COMPLETE = 3;
		static const int DOLG = 4;
		static const int DOLG_COMPLETE = 5;

		void addWork(int userId, int type, string text);
		void deleteWork(int id);
		void updateWork(int id, string text, int status);
		
		vector<Teacher> *getTeachers();
		void addTeacer(Teacher *teacher);
		void deleteTeacher(int id);

		vector<StudentModel> *getStudents(int type, string text);
		vector<StudentModel> *getStudents(int groupId);
		vector<StudentModel> *getStudents();
		void addStudent(StudentModel *student);
		void updateStudent(StudentModel *student);
		void deleteStudent(int id);

		vector<FakultetModel> *getFakultets();		//получить список факультетов
		void addFakultet(FakultetModel *fakultet);
		void updateFakultet(FakultetModel *fakultet);
		void deleteFakultet(int id);

		vector<KafedraModel> *getKafedras(int fakultetId);
		vector<KafedraModel> *getKafedras();
		void addKafedra(KafedraModel *kafedra);
		void updateKafedra(KafedraModel *kafedra);
		void deleteKafedra(int id);


		vector<NapravlenieModel> *getNapravlenies();
		vector<NapravlenieModel> *getNapravlenies(int kafedraId);
		void addNapravlenie(NapravlenieModel *data);
		void updateNapravlenie(NapravlenieModel *data);
		void deleteNapravlenie(int id);

		vector<GroupModel> *getGroups(int napravlenieId);
		vector<GroupModel> *getGroups();
		void addGroups(GroupModel *data);
		void updateGroups(GroupModel *data);
		void deleteGroups(int id);

		string getLastGroup(string pref);
	};
}

 