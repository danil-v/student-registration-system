#include "MySQL.h" 
#include <string>
#include <fstream>

using namespace std;

namespace Student
{

	MySQL::MySQL(void)
	{
	}

	MySQL::~MySQL(void)
	{
	}

	bool MySQL::init()
	{
		host = "localhost";
		base = "student";
		user = "root";
		pass = "";


		ifstream file("config.txt");
		string line;
		for (std::string line; getline(file, line);)
		{
			string name = line.substr(0, line.find('='));
			string value = line.substr(line.find('='));

			if (name == "host")
				host = value;
			if (name == "base")
				base = value;
			if (name == "user")
				user = value;
			if (name == "pass")
				pass = value;
		}

		conn = mysql_init(NULL);
		if (conn == NULL)
		{
			return false;
		}

		// Подключаемся к серверу
		if (!mysql_real_connect(conn, host.c_str(),
			user.c_str(), pass.c_str(), base.c_str(),
			NULL, NULL, 0))
		{
			return false;
		}

		if (mysql_query(conn, "SET NAMES 'cp1251'") != 0)
		{
			// Если кодировку установить невозможно - выводим 
			// сообщение об ошибке
			return false;
		}

		return true;
	}

	void MySQL::close()
	{
		// Закрываем соединение с сервером базы данных
		mysql_close(conn);
	}

	void MySQL::addUser(User *user)
	{
		string query = "INSERT INTO `users` (`id`, `login`, `password`, `access`, `teacherId`, `studentId`) "
			"VALUES (NULL, '" + user->login + "', '" + user->pass + "', '" + to_string(user->access) + 
			"', '" + to_string(user->teacherId) + "', '" + to_string(user->studentId) + "');";
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteUser(int id)
	{
		string query = "DELETE FROM `users` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	int MySQL::login(string login, string pass)
	{
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT access "
			" FROM users "
			" WHERE login='" + login + "' AND password='"+pass+"'";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						return atoi(row[0]);						
					}
				}
			}
		}

		return -1;
	}

	vector<User> *MySQL::getUsers()
	{
		vector<User> *result = new vector<User>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT users.id,users.login,users.password,users.access,"
			"teacher.fio,students.second_name,students.name,students.middle_name "
			" FROM users LEFT JOIN teacher ON teacher.id=users.teacherId LEFT JOIN students ON students.id=users.studentId"
			" WHERE 1";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						User pr;
						pr.id = atoi(row[0]);
						pr.login = row[1];
						pr.pass = row[2];
						pr.access = atoi(row[3]);
						pr.teacher = row[4] ? row[4] : "";
						if (row[5])
						{
							pr.student = row[5];	pr.student += " ";
							pr.student += row[6];	pr.student += " ";
							pr.student += row[7];
						}
						else
							pr.teacher = "";

						result->push_back(pr);
					}
				}
			}
		}

		return result;
	}

	vector<PredmetsWithMarks> *MySQL::getUserMarks(int userId, int kurs, int semestr)
	{
		vector<PredmetsWithMarks> *result = new vector<PredmetsWithMarks>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;
		//PredmetsWithMarks

		string query = "SELECT  predmet_semestr.name,marks.att1,marks.att2,marks.samost,marks.exam,marks.result,predmet.id,teacher.fio,predmet.hours FROM students,predmet_semestr,`group`,teacher,predmet LEFT JOIN marks ON marks.predmetSemestrId=predmet.id WHERE predmet_semestr.id=predmet.predmetKursId "
			" AND students.`group_id`=`group`.id AND `group`.napravlenieId = predmet_semestr.napravlenieId AND teacher.id = predmet.teacherId "
			" AND students.id = " + to_string(userId) + "  AND  predmet_semestr.semestr =" + to_string(kurs*2+semestr);
	
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						PredmetsWithMarks pr;
						//pr.id = atoi(row[0]);
						pr.predmet = row[0];
						pr.att1 = row[1] ? atoi(row[1]) : NULL;
						pr.att2 = row[2] ? atoi(row[2]) : NULL;
						pr.samost = row[3] ? atoi(row[3]) : NULL;
						pr.exam = row[4] ? atoi(row[4]) : NULL;
						pr.mark = row[5] ? atoi(row[5]) : NULL;
						pr.predmetId = row[2] ? atoi(row[6]) : NULL;
						pr.teacher = row[7];
						pr.hours = row[8] ? atoi(row[8]) : NULL;

						result->push_back(pr);
					}
				}
			}
		}

		return result;
	}

	vector<Work> *MySQL::loadArchiev(int userId)
	{
		vector<Work> *result = new vector<Work>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT id,descr,status FROM work WHERE userId="
			+ to_string(userId) + " AND status=1";

		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Work wk;
						wk.id = atoi(row[0]);
						wk.data = row[1];
						wk.status = atoi(row[2]);
						result->push_back(wk);
					}
				}
			}
		}

		return result;
	}

	vector<Work> *MySQL::loadPoruch(int userId)
	{
		vector<Work> *result = new vector<Work>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT id,descr,status FROM work WHERE userId="
			+ to_string(userId) + " AND (status=2 OR status=3)";

		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Work wk;
						wk.id = atoi(row[0]);
						wk.data = row[1];
						wk.status = atoi(row[2]);
						result->push_back(wk);
					}
				}
			}
		}

		return result;
	}

	vector<Work> *MySQL::loadDolgi(int userId)
	{
		vector<Work> *result = new vector<Work>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT id,descr,status FROM work WHERE userId="
			+ to_string(userId) + " AND (status=4 OR status=5)";

		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Work wk;
						wk.id = atoi(row[0]);
						wk.data = row[1];
						wk.status = atoi(row[2]);
						result->push_back(wk);
					}
				}
			}
		}

		return result;
	}

	vector<StudentModel> *MySQL::getStudents(int groupId)
	{
		vector<StudentModel> *result = new vector<StudentModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT students.*,"
			"`group`.name,"
			"napravlenie.id,kafedra.id,fakultet.id FROM students "
			"LEFT JOIN `group` ON students.group_id=`group`.id "
			"LEFT JOIN napravlenie ON napravlenie.id=`group`.napravlenieId "
			"LEFT JOIN kafedra ON kafedra.id=napravlenie.kafedraId "
			"LEFT JOIN fakultet ON fakultet.id=kafedra.fakultetId WHERE `group`.id=" + to_string(groupId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						StudentModel st;

						st.id = atoi(row[0]);
						st.name = row[1];
						st.surName = row[2];
						st.middleName = row[3];
						st.number = atoi(row[4]);
						st.sex = atoi(row[5]);
						st.birth = row[6];
						st.mobile = row[7];
						st.email = row[8];
						st.adres = row[9];
						st.studyForm = atoi(row[10]);
						st.groupId = atoi(row[11]);
						st.kurs = atoi(row[12]);
						st.payStudy = atoi(row[13]);
						st.prevStudy = row[14];
						st.family = row[15];
						st.isChildren = atoi(row[16]);
						st.isNeedHostel = atoi(row[17]);
						st.natinality = row[18];
						st.isMilitary = atoi(row[19]);
						st.sport = row[20];
						st.olymps = row[21];
						st.arts = row[22];
						st.studyStart = row[23];
						st.studyEnd = row[24];
						st.groupName = row[25] == NULL ? "" : row[25];

						if (row[26])
							st.napravlenieId = atoi(row[26]);
						if (row[27])
							st.kafedraId = atoi(row[27]);
						if (row[28])
							st.fakultetId = atoi(row[28]);

						result->push_back(st);
					}
				}
			}
		}

		return result;
	}

	vector<StudentModel> *MySQL::getStudents(int type, string text)
	{
		vector<StudentModel> *result = new vector<StudentModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string search;
		//фамилия
		//курс
		//группе

		if (type==0)
			search = " second_name LIKE '%" + text + "%' ";
		else if (type == 1)
			search = " course=" + text;
		else
			search = " `group` LIKE '%" + text + "%' ";

		

		string query = "SELECT students.*,"
			"`group`.name,"
			"napravlenie.id,kafedra.id,fakultet.id FROM students "
			"LEFT JOIN `group` ON students.group_id=`group`.id "
			"LEFT JOIN napravlenie ON napravlenie.id=`group`.napravlenieId "
			"LEFT JOIN kafedra ON kafedra.id=napravlenie.kafedraId "
			"LEFT JOIN fakultet ON fakultet.id=kafedra.fakultetId WHERE " + search;
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						StudentModel st;

						st.id = atoi(row[0]);
						st.name = row[1];
						st.surName = row[2];
						st.middleName = row[3];
						st.number = atoi(row[4]);
						st.sex = atoi(row[5]);
						st.birth = row[6];
						st.mobile = row[7];
						st.email = row[8];
						st.adres = row[9];
						st.studyForm = atoi(row[10]);
						st.groupId = atoi(row[11]);
						st.kurs = atoi(row[12]);
						st.payStudy = atoi(row[13]);
						st.prevStudy = row[14];
						st.family = row[15];
						st.isChildren = atoi(row[16]);
						st.isNeedHostel = atoi(row[17]);
						st.natinality = row[18];
						st.isMilitary = atoi(row[19]);
						st.sport = row[20];
						st.olymps = row[21];
						st.arts = row[22];
						st.studyStart = row[23];
						st.studyEnd = row[24];
						st.groupName = row[25] == NULL ? "" : row[25];

						if (row[26])
							st.napravlenieId = atoi(row[26]);
						if (row[27])
							st.kafedraId = atoi(row[27]);
						if (row[28])
							st.fakultetId = atoi(row[28]);

						result->push_back(st);
					}
				}
			}
		}

		return result;
	}

	vector<StudentModel> *MySQL::getStudents()
	{
		vector<StudentModel> *result = new vector<StudentModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT students.*,"
			"`group`.name,"
			"napravlenie.id,kafedra.id,fakultet.id FROM students "
			"LEFT JOIN `group` ON students.group_id=`group`.id "
			"LEFT JOIN napravlenie ON napravlenie.id=`group`.napravlenieId "
			"LEFT JOIN kafedra ON kafedra.id=napravlenie.kafedraId "
			"LEFT JOIN fakultet ON fakultet.id=kafedra.fakultetId WHERE 1";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						StudentModel st;

						st.id = atoi(row[0]);
						st.name = row[1];
						st.surName = row[2];
						st.middleName = row[3];
						st.number = atoi(row[4]);
						st.sex = atoi(row[5]);
						st.birth = row[6];
						st.mobile = row[7];
						st.email = row[8];
						st.adres = row[9];
						st.studyForm = atoi(row[10]);
						st.groupId = atoi(row[11]);
						st.kurs = atoi(row[12]);
						st.payStudy = atoi(row[13]);
						st.prevStudy = row[14];
						st.family = row[15];
						st.isChildren = atoi(row[16]);
						st.isNeedHostel = atoi(row[17]);
						st.natinality = row[18];
						st.isMilitary = atoi(row[19]);
						st.sport = row[20];
						st.olymps = row[21];
						st.arts = row[22];
						st.studyStart = row[23];
						st.studyEnd = row[24];
						st.groupName = row[25] == NULL ? "" : row[25];

						if (row[26])
							st.napravlenieId = atoi(row[26]);
						if (row[27])
							st.kafedraId = atoi(row[27]);
						if (row[28])
							st.fakultetId = atoi(row[28]);

						result->push_back(st);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addStudent(StudentModel *student)
	{
		string query = "INSERT INTO `students` (`id`, `name`, `second_name`, "
			"`middle_name`, `number`, `sex`, `birthday`, `mobile`, `email`, "
			"`adres`, `study_form`, `group_id`, `course`, `pay_study`, "
			"`prev_study`, `family`, `is_children`, `is_need_hostel`, "
			"`nationality`, `military`, `sport`, `olymps`, `arts`, "
			"`study_start`, `study_end`) VALUES (NULL, "
			"'" + student->name + "', '" + student->surName + "', '" + student->middleName + 
			"', '" + to_string(student->number) + "', '" + to_string(student->sex) +
			"', '" + student->birth + "', '" + student->mobile + "', '" + student->email + 
			"', '" + student->adres + "', '" + to_string(student->studyForm) + 
			"', '" + to_string(student->groupId) + "', '" + to_string(student->kurs) + 
			"', '" + to_string(student->payStudy) + "', '" + student->prevStudy + 
			"', '" + student->family + "', " + to_string(student->isChildren) + 
			", " + to_string(student->isNeedHostel) + 
			", '" + student->natinality + "', '" + to_string(student->isMilitary) + "', '" + student->sport +
			"', '" + student->olymps + "', '" + student->arts + "', '" + student->studyStart + "', '" + student->studyEnd + "');";

		mysql_query(conn, query.c_str());
	}

	void MySQL::updateStudent(StudentModel *student)
	{
		string query = "UPDATE `students` SET `name` = '" + student->name + "',"
			"`second_name` = '" + student->surName + "',"
			"`middle_name` = '" + student->middleName + "',"
			"`number` = '" + to_string(student->number) + "',"
			"`sex` = '" + to_string(student->sex) + "',"
			"`birthday` = '" + student->birth + "',"
			"`mobile` = '" + student->mobile + "',"
			"`email` = '" + student->email + "',"
			"`adres` = '" + student->adres + "',"
			"`study_form` = '" + to_string(student->studyForm) + "',"
			"`group_id` = '" + to_string(student->groupId) + "',"
			"`course` = '" + to_string(student->kurs) + "',"
			"`pay_study` = '" + to_string(student->payStudy) + "',"
			"`prev_study` = '" + student->prevStudy + "',"
			"`family` = '" + student->family + "',"
			"`is_children` = '" + to_string(student->isChildren) + "',"
			"`is_need_hostel` = '" + to_string(student->isNeedHostel) + "',"
			"`nationality` = '" + student->natinality + "',"
			"`military` = '" + to_string(student->isMilitary) + "',"
			"`sport` = '" + student->sport + "',"
			"`olymps` = '" + student->olymps + "',"
			"`arts` = '" + student->arts + "',"
			"`study_start` = '" + student->studyStart + "',"
			"`study_end` = '" + student->studyEnd + "' WHERE `id` = " + to_string(student->id) + ";";

		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteStudent(int id)
	{
		string query = "DELETE FROM students WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}


	vector<FakultetModel> *MySQL::getFakultets()		//получить список факультетов
	{
		vector<FakultetModel> *result = new vector<FakultetModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT id,name FROM fakultet WHERE 1";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						FakultetModel fk;
						fk.id = atoi(row[0]);
						fk.name = row[1];
						result->push_back(fk);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addFakultet(FakultetModel *fakultet)
	{
		string query = "INSERT INTO fakultet (id,name) VALUES (NULL, '" + fakultet->name + "')";
		mysql_query(conn, query.c_str());
	}

	void MySQL::updateFakultet(FakultetModel *fakultet)
	{
		string query = "UPDATE fakultet SET name='" + fakultet->name + "' WHERE id=" + to_string(fakultet->id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteFakultet(int id)
	{
		string query = "DELETE FROM fakultet WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}


	vector<KafedraModel> *MySQL::getKafedras()
	{
		vector<KafedraModel> *result = new vector<KafedraModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT kafedra.id,kafedra.fakultetId,kafedra.name,fakultet.name"
			" FROM kafedra,fakultet WHERE kafedra.fakultetId=fakultet.id";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						KafedraModel kaf;
						kaf.id = atoi(row[0]);
						kaf.fakultetId = atoi(row[1]);
						kaf.name = row[2];
						kaf.fakultetName = row[3];
						result->push_back(kaf);
					}
				}
			}
		}

		return result;
	}

	vector<KafedraModel>* MySQL::getKafedras(int fakultetId)
	{
		vector<KafedraModel> *result = new vector<KafedraModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT kafedra.id,kafedra.fakultetId,kafedra.name,fakultet.name"
			" FROM kafedra,fakultet WHERE kafedra.fakultetId=fakultet.id AND fakultetId=" + to_string(fakultetId);

		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						KafedraModel kaf;
						kaf.id = atoi(row[0]);
						kaf.fakultetId = atoi(row[1]);
						kaf.name = row[2];
						kaf.fakultetName = row[3];
						result->push_back(kaf);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addKafedra(KafedraModel *kafedra)
	{
		string query = "INSERT INTO kafedra (id,fakultetId,name) VALUES (NULL, " +
			to_string(kafedra->fakultetId) + ", '" + kafedra->name + "')";
		mysql_query(conn, query.c_str());
	}

	void MySQL::updateKafedra(KafedraModel *kafedra)
	{
		string query = "UPDATE kafedra SET fakultetId=" +
			to_string(kafedra->fakultetId) + ", name='" + kafedra->name +
			"' WHERE id=" + to_string(kafedra->id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteKafedra(int id)
	{
		string query = "DELETE FROM kafedra WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}



	vector<NapravlenieModel> *MySQL::getNapravlenies()
	{
		vector<NapravlenieModel> *result = new vector<NapravlenieModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT napravlenie.id,napravlenie.kafedraId,napravlenie.name,fakultet.name,fakultet.id,kafedra.name FROM napravlenie,fakultet,kafedra "
			"WHERE fakultet.id=kafedra.fakultetId AND kafedra.id=napravlenie.kafedraId";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						NapravlenieModel napr;
						napr.id = atoi(row[0]);
						napr.kafedraId = atoi(row[1]);
						napr.name = row[2];
						napr.fakultetName = row[3];
						napr.fakultetId = atoi(row[4]);
						napr.kafedraName = row[5];

						result->push_back(napr);
					}
				}
			}
		}

		return result;
	}

	vector<NapravlenieModel> *MySQL::getNapravlenies(int kafedraId)
	{
		vector<NapravlenieModel> *result = new vector<NapravlenieModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT napravlenie.id,napravlenie.kafedraId,napravlenie.name,fakultet.name,fakultet.id,kafedra.name FROM napravlenie,fakultet,kafedra "
			"WHERE fakultet.id=kafedra.fakultetId AND kafedra.id=napravlenie.kafedraId AND kafedra.id=" + to_string(kafedraId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						NapravlenieModel napr;
						napr.id = atoi(row[0]);
						napr.kafedraId = atoi(row[1]);
						napr.name = row[2];
						napr.fakultetName = row[3];
						napr.fakultetId = atoi(row[4]);
						napr.kafedraName = row[5];

						result->push_back(napr);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addNapravlenie(NapravlenieModel *data)
	{
		string query = "INSERT INTO napravlenie (id,name,kafedraId) VALUES (NULL, '" +
			data->name + "', " + to_string(data->kafedraId) + ")";
		mysql_query(conn, query.c_str());
	}

	void MySQL::updateNapravlenie(NapravlenieModel *data)
	{
		string query = "UPDATE napravlenie SET kafedraId=" + to_string(data->kafedraId) +
			", name='" + data->name + "' WHERE id=" + to_string(data->id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteNapravlenie(int id)
	{
		string query = "DELETE FROM napravlenie WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}


	vector<GroupModel> *MySQL::getGroups(int napravlenieId)		//получить список факультетов
	{
		vector<GroupModel> *result = new vector<GroupModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT `group`.id,`group`.napravlenieId,`group`.name, "
			" napravlenie.id,napravlenie.name,kafedra.id,kafedra.name,"
			" fakultet.id,fakultet.name "
			" FROM `group`,napravlenie,fakultet,kafedra"
			" WHERE fakultet.id=kafedra.fakultetId AND "
			" kafedra.id=napravlenie.kafedraId AND "
			" napravlenie.id=`group`.napravlenieId AND "
			" `group`.napravlenieId=" + to_string(napravlenieId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						GroupModel gr;
						gr.id = atoi(row[0]);
						gr.napravlenieId = atoi(row[1]);
						gr.name = row[2];
						gr.napravlenieId = atoi(row[3]);
						gr.napravlenieName = row[4];
						gr.kafedraId = atoi(row[5]);
						gr.kafedraName = row[6];
						gr.fakultetId = atoi(row[7]);
						gr.fakultetName = row[8];
						result->push_back(gr);
					}
				}
			}
		}

		return result;
	}

	vector<GroupModel> *MySQL::getGroups()		//получить список факультетов
	{
		vector<GroupModel> *result = new vector<GroupModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT `group`.id,`group`.napravlenieId,`group`.name, "
			" napravlenie.id,napravlenie.name,kafedra.id,kafedra.name,"
			" fakultet.id,fakultet.name "
			" FROM `group`,napravlenie,fakultet,kafedra"
			" WHERE fakultet.id=kafedra.fakultetId AND "
			" kafedra.id=napravlenie.kafedraId AND "
			" napravlenie.id=`group`.napravlenieId ";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						GroupModel gr;
						gr.id = atoi(row[0]);
						gr.napravlenieId = atoi(row[1]);
						gr.name = row[2];
						gr.napravlenieId = atoi(row[3]);
						gr.napravlenieName = row[4];
						gr.kafedraId = atoi(row[5]);
						gr.kafedraName = row[6];
						gr.fakultetId = atoi(row[7]);
						gr.fakultetName = row[8];
						result->push_back(gr);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addGroups(GroupModel *data)
	{
		string query = "INSERT INTO `group` (id,napravlenieId,name) VALUES (NULL, " +
			to_string(data->napravlenieId) + ", '" + data->name + "')";
		mysql_query(conn, query.c_str());
	}

	void MySQL::updateGroups(GroupModel *data)
	{
		string query = "UPDATE `group` SET napravlenieId=" + to_string(data->napravlenieId) +
			", name='" + data->name + "' WHERE id=" + to_string(data->id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteGroups(int id)
	{
		string query = "DELETE FROM `group` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::addWork(int userId, int type, string text)
	{
		string query = "INSERT INTO `work` SET descr='" + text + "',status="
			+ to_string(type) + " WHERE userId=" + to_string(userId);
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteWork(int id)
	{
		string query = "DELETE FROM `work` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::updateWork(int id, string text, int status)
	{
		string query = "UPDATE `work` SET descr='"+text+"',status="
			+to_string(status)+" WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	vector<Teacher> *MySQL::getTeachers()
	{
		vector<Teacher> *result = new vector<Teacher>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT teacher.*,kafedra.name "
			" FROM teacher,kafedra  "
			" WHERE teacher.kafedraId=kafedra.id ";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Teacher teach;
						teach.id = atoi(row[0]);
						teach.fio = row[1];
						teach.kafedraId = atoi(row[2]); 
						teach.zvanie = row[3];
						teach.stepen = row[4];
						teach.kafedra = row[5];
						
						result->push_back(teach);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addTeacer(Teacher *teacher)
	{
		string query = "INSERT INTO `teacher` (`id`, `fio`, `kafedraId`, `zvanie`, `stepen`) VALUES (NULL, "
			"'" + teacher->fio + "', " + to_string(teacher->kafedraId) + 
			", '" + teacher->zvanie + "', '" + teacher->stepen + "');";
		mysql_query(conn, query.c_str());
	}

	void MySQL::deleteTeacher(int id)
	{
		string query = "DELETE FROM `teacher` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	void MySQL::addPredmet(Predmet *predmet)
	{
		string query = "INSERT INTO `predmet_semestr` (`id`, `name`, `semestr`, `napravlenieId`) "
			"VALUES (NULL, '" + predmet->name + "', '" + 
			to_string(predmet->semestr) + "', '" + to_string(predmet->specialId) + "');";
		mysql_query(conn, query.c_str());
		
	}

	void MySQL::deletePredmet(int id)
	{
		string query = "DELETE FROM `predmet_semestr` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	vector<Predmet> *MySQL::getPredmets(int semestr, int specialId)
	{
		vector<Predmet> *result = new vector<Predmet>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT * "
			" FROM  `predmet_semestr`  "
			" WHERE semestr=" + to_string(semestr) + " AND napravlenieId=" + to_string(specialId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Predmet predmet;
						predmet.id = atoi(row[0]);
						predmet.name = row[1];
						predmet.semestr = atoi(row[2]);
						predmet.specialId = atoi(row[3]);

						result->push_back(predmet);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addPredmetPlan(Predmet *predmet)
	{
		string query = "INSERT INTO `predmet` (`id`, `predmetKursId`, `hours`, `hoursLec`, `hoursPract`,"
			" `hoursLabs`, `teacherId`, `zachet`, `kursov`, `exam`) VALUES (NULL, '" + 
			to_string(predmet->predmetId) + "', '" + to_string(predmet->hours) + "', '" + to_string(predmet->hoursLec) + 
			"', '" + to_string(predmet->hoursPract) + "', '" + to_string(predmet->hoursLab) + "', '" + to_string(predmet->teacherId) + 
			"', '" + to_string(predmet->zachet) + "', '" + to_string(predmet->kursov) + "', '" + to_string(predmet->exam) + "');";
		mysql_query(conn, query.c_str());
	}

	void MySQL::deletePredmetPlan(int id)
	{
		string query = "DELETE FROM `predmet` WHERE id=" + to_string(id);
		mysql_query(conn, query.c_str());
	}

	vector<Predmet> *MySQL::getPredmetsTeacher(int semestr, int specialId)
	{
		vector<Predmet> *result = new vector<Predmet>();
		// Дескриптор результирующей таблицы
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT predmet.id,predmet_semestr.name,"
			"hours,hoursLec,hoursPract,hoursLabs,teacher.fio,zachet,kursov,exam,predmet_semestr.id FROM `predmet`,predmet_semestr,teacher "
			"WHERE predmet_semestr.id = predmet.predmetKursId AND teacherId=teacher.id AND predmet_semestr.semestr=" + to_string(semestr) +
			" AND napravlenieId=" + to_string(specialId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Predmet pr;
						pr.id = atoi(row[0]);
						pr.name = row[1]; // query.value(1).toString();
						pr.hours = atoi(row[2]);
						pr.hoursLec = atoi(row[3]);
						pr.hoursPract = atoi(row[4]);
						pr.hoursLab = atoi(row[5]);
						pr.teacher = row[6];
						pr.zachet = row[7][0] == '1';
						pr.kursov = row[8][0] == '1';
						pr.exam = row[9][0] == '1';
						pr.predmetId = atoi(row[10]);
						pr.semestr = semestr;

						result->push_back(pr);
					}
				}
			}

		}

		return result;
	}

	vector<PredmetsWithMarks> *MySQL::getMarks(int semestr, int disciplineId, int groupId)
	{
		vector<PredmetsWithMarks> *result = new vector<PredmetsWithMarks>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;
		//PredmetsWithMarks

		string query = "SELECT students.second_name,students.name,students.middle_name,students.number,marks .*, "
			"students.id, predmet.id, predmet.teacherId "
			"FROM predmet_semestr, `predmet`, students LEFT JOIN marks ON students.id = marks.studentId "
			"WHERE predmet.`predmetKursId`=predmet_semestr.id AND predmet.id = "+to_string(disciplineId)+" AND predmet_semestr.semestr =" + to_string(semestr) +
			" AND students.group_id=" + to_string(groupId);
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						PredmetsWithMarks pr;
						
						pr.fio = row[0];
						pr.fio += row[1][0];
						pr.fio += ".";
						pr.fio += row[2][0];
						pr.fio += ".";

						pr.number = row[3] ? atoi(row[3]) : 0;
						pr.id = row[4] ? atoi(row[4]) : 0;

						pr.att1 = row[7] ? atoi(row[7]) : 0;
						pr.att2 = row[8] ? atoi(row[8]) : 0;
						pr.samost = row[9] ? atoi(row[9]) : 0;
						pr.posesh = row[10] ? atoi(row[10]) : 0;
						pr.recomend = (pr.att1 / 35.0 + pr.att2 / 35.0 + pr.samost / 10.0 + pr.posesh/10.0);
						if (pr.recomend != 0)
							pr.recomend++;
						pr.exam = row[14] ? atoi(row[14]) : 0;
						pr.mark = row[15] ? atoi(row[15]) : 0;

						pr.studentId = atoi(row[16]);
						pr.predmetId = atoi(row[17]);
						pr.teacherId = atoi(row[18]);
						
						result->push_back(pr);
					}
				}
			}
		}

		return result;
	}

	void MySQL::addMark(PredmetsWithMarks *mark)
	{
		string query = "INSERT INTO `marks` (`id`, `studentId`,"
			" `predmetSemestrId`, `att1`, `att2`, `samost`, `vizits`,"
			" `zachet`, `kurs`, `pract`, `exam`, `result`) VALUES (NULL, '" + 
			to_string(mark->studentId) + "', '" + to_string(mark->predmetId) + "', '" + to_string(mark->att1) + 
			"', '" + to_string(mark->att2) + "', '" + to_string(mark->samost) + 
			"', '" + to_string(mark->posesh) + "', '0', '0', '0', '" + to_string(mark->exam) + 
			"', '" + to_string(mark->mark) + "');";
		mysql_query(conn, query.c_str()); 
	}

	void MySQL::updateMark(PredmetsWithMarks *mark)
	{
		string query = "UPDATE `marks` SET "
			"`att1` = '" + to_string(mark->att1) + "',"
			"`att2` = '" + to_string(mark->att2) + "',"
			"`samost` = '" + to_string(mark->samost) + "',"
			"`vizits` = '" + to_string(mark->posesh) + "',"
			"`zachet` = '0',"
			"`kurs` = '0',"
			"`pract` = '0',"
			"`exam` = '" + to_string(mark->exam) + "',"
			"`result` = '" + to_string(mark->mark) +
			"' WHERE `marks`.`id` = " + to_string(mark->id) + "; ";
		mysql_query(conn, query.c_str());
	}

	vector<UspModel> *MySQL::getUserUspev(int groupId)
	{
		vector<UspModel> *result = new vector<UspModel>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;
		//PredmetsWithMarks

		string query = "SELECT students.second_name,students.name,students.middle_name,students.number,students.id "
			"FROM students WHERE group_id =" + to_string(groupId);
		
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						UspModel pr;
						ZeroMemory(&pr, sizeof(UspModel));
						
						pr.fio = row[0];
						pr.fio += row[1][0];
						pr.fio += ".";
						pr.fio += row[2][0];
						pr.fio += ".";
						pr.number = row[3] ? atoi(row[3]) : 0;
						pr.userId = atoi(row[4]);
						
						result->push_back(pr);
					}
				}
			}
		}

		for (int i = 0; i < result->size(); i++)
		{
			query = "SELECT AVG( marks.result ) , predmet_semestr.semestr "
				" FROM `marks`, predmet, predmet_semestr "
				" WHERE marks.predmetSemestrId = predmet.id "
				" AND studentId =" + to_string(result->at(i).userId ) +
				" GROUP BY semestr" ;

			if (mysql_query(conn, query.c_str()) == 0)
			{
				res = mysql_store_result(conn);
				if (res != NULL)
				{
					// Если имеется хотя бы одна запись - выводим список каталогов
					if (mysql_num_rows(res) > 0)
					{
						// В цикле перебираем все записи
						// результирующей таблицы
						while ((row = mysql_fetch_row(res)) != NULL)
						{
							result->at(i).semestrs[atoi(row[1])-3] = atof(row[0]);
						}
					}
				}
			}
		}

		return result;
	}

	vector<PredmetsWithMarks> *MySQL::getDolgi(int groupId, int semestr)
	{
		vector<PredmetsWithMarks> *result = new vector<PredmetsWithMarks>();
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;
		//PredmetsWithMarks

		string query = "SELECT students.second_name,students.name,students.middle_name,students.number "
			" FROM students, marks, predmet, predmet_semestr WHERE "
			" marks.studentId = students.id AND students.group_id =" + to_string(groupId) +
			" AND  predmet.id = marks.predmetSemestrId AND "
			" predmet.predmetKursId = predmet_semestr.id AND semestr =" + to_string(semestr) + " AND result < 2";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						PredmetsWithMarks pr;

						pr.fio = row[0];
						pr.fio += row[1][0];
						pr.fio += ".";
						pr.fio += row[2][0];
						pr.fio += ".";

						pr.number = row[3] ? atoi(row[3]) : 0;
						
						result->push_back(pr);
					}
				}
			}
		}

		return result;
	}

	string MySQL::getLastGroup(string pref)
	{
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT name FROM `group` "
			"WHERE name LIKE '"+pref+"%' ORDER BY id DESC LIMIT 1";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						return row[0];
					}
				}
			}
		}

		return pref+"-000-01";
	}

	/*
	vector<Predmet> *MySQL::getPredmetsTeacher()
	{
		vector<Predmet> *result = new vector<Predmet>();
		// Дескриптор результирующей таблицы
		MYSQL_RES *res;
		// Дескриптор строки
		MYSQL_ROW row;

		string query = "SELECT predmet.id,predmet_semestr.name,"
			"hours,hoursLec,hoursPract,hoursLabs,teacher.fio,zachet,kursov,exam,predmet_semestr.id FROM `predmet`,predmet_semestr,teacher "
			"WHERE predmet_semestr.id = predmet.predmetKursId AND teacherId=teacher.id ";
		if (mysql_query(conn, query.c_str()) == 0)
		{
			res = mysql_store_result(conn);
			if (res != NULL)
			{
				// Если имеется хотя бы одна запись - выводим список каталогов
				if (mysql_num_rows(res) > 0)
				{
					// В цикле перебираем все записи
					// результирующей таблицы
					while ((row = mysql_fetch_row(res)) != NULL)
					{
						Predmet pr;
						pr.id = atoi(row[0]);
						pr.name = row[1]; // query.value(1).toString();
						pr.hours = atoi(row[2]);
						pr.hoursLec = atoi(row[3]);
						pr.hoursPract = atoi(row[4]);
						pr.hoursLab = atoi(row[5]);
						pr.teacher = row[6];
						pr.zachet = row[7][0] == '1';
						pr.kursov = row[8][0] == '1';
						pr.exam = row[9][0] == '1';
						pr.predmetId = atoi(row[10]);

						result->push_back(pr);
					}
				}
			}

		}

		return result;
	}*/
}