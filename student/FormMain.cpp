#include "FormMain.h"

namespace Student
{
	Form1::Form1(MySQL *mysql, int access)
	{
		this->access = access;
		this->mysql = mysql;

		InitializeComponent();

		
		students = NULL;
		fakultets = NULL;
		listStudentGroups = NULL;
		student = NULL;

		studentAdd = new StudentModel();

		kafedrasAkadem = NULL;
		napravleniaAkadem = NULL;
		groupsAkadem = NULL;
		studentsAkadem = NULL;
		teachers = NULL;

		kafedrasPredmets = NULL;
		napravleniaPredmets = NULL;

		kafedrasDisciplina = NULL;
		napravleniaDisciplina = NULL;
		predmetsDisciplina = NULL;

		kafedrasDisciplinaShow = NULL;
		napravleniaDisciplinaShow = NULL;


		kafedrasVedomost = NULL;
		napravleniaVedomost = NULL;
		groupVedomost = NULL;
		disciplinaVedomost = NULL;

		marks = NULL;

		kafedrasUspevaemost = NULL;
		napravleniaUspevaemost = NULL;
		groupUspevaemost = NULL;

		logins = NULL;

		kafedrasStudent = NULL;
		napravleniaStudent = NULL;
		groupStudent = NULL;

		dataGridViewAttestat->Visible = false;
		dataGridViewExam->Visible = false;

		arrColumnLefts = gcnew ArrayList();
		arrColumnWidths = gcnew ArrayList();
		iCellHeight = 0;
		iTotalWidth = 0;
		iRow = 0;
		bFirstPage = false;
		bNewPage = false;
		iHeaderHeight = 0;

		tableType = 0;

		loadFakultets();
		loadStudents();
		loadTeachers();
		loadLogins();

		if (access==0)
		{
			buttonAddStudent->Enabled = false;
			buttonAdditional->Enabled = false;
			buttonClearStud->Enabled = false;
			buttonPrepAdd->Enabled = false;
			buttonPlanAdd->Enabled = false;
			buttonDisciplinAdd->Enabled = false;
			tabControl1->TabPages->RemoveAt(6);
		}

		
	}

	Form1::~Form1()
	{
		if (kafedrasStudent)
			delete kafedrasStudent;
		if (napravleniaStudent)
			delete napravleniaStudent;
		if (groupStudent)
			delete groupStudent;

		if (kafedrasUspevaemost)
			delete kafedrasUspevaemost;
		if (napravleniaUspevaemost)
			delete napravleniaUspevaemost;
		if (groupUspevaemost)
			delete groupUspevaemost;

		if (marks)
			delete marks;

		if (kafedrasVedomost)
			delete kafedrasVedomost;
		if (napravleniaVedomost)
			delete napravleniaVedomost;
		if (groupVedomost)
			delete groupVedomost;
		if (disciplinaVedomost)
			delete disciplinaVedomost;


		if (kafedrasPredmets)
			delete kafedrasPredmets;
		if (napravleniaPredmets)
			delete napravleniaPredmets;

		if (kafedrasDisciplina)
			delete kafedrasDisciplina;

		if (napravleniaDisciplina)
			delete predmetsDisciplina;

		if (kafedrasDisciplinaShow)
			delete kafedrasDisciplinaShow;
		if (napravleniaDisciplinaShow)
			delete napravleniaDisciplinaShow;

		if (kafedrasAll)
			delete kafedrasAll;
		if (studentsAkadem)
			delete studentsAkadem;
		if (kafedrasAkadem)
			delete kafedrasAkadem;
		if (napravleniaAkadem)
			delete napravleniaAkadem;
		if (groupsAkadem)
			delete groupsAkadem;

		delete studentAdd;
		if (fakultets)
			delete fakultets;
		if (students)
			delete students;
		if (listStudentGroups)
			delete listStudentGroups;

		delete mysql;
		if (components)
		{
			delete components;
		}
	}

	void Form1::loadLogins()
	{
		if (logins)
			delete logins;

		logins = mysql->getUsers();
		dataGridViewLogin->RowCount = logins->size();
		
		for (int i = 0; i < logins->size(); i++)
		{
			dataGridViewLogin->Rows[i]->Cells[0]->Value = gcnew String(logins->at(i).login.c_str());
			dataGridViewLogin->Rows[i]->Cells[1]->Value = gcnew String(logins->at(i).pass.c_str());
			if (logins->at(i).student != "")
				dataGridViewLogin->Rows[i]->Cells[2]->Value = gcnew String(logins->at(i).student.c_str());
			else if (logins->at(i).teacher != "")
				dataGridViewLogin->Rows[i]->Cells[2]->Value = gcnew String(logins->at(i).teacher.c_str());
			else
				dataGridViewLogin->Rows[i]->Cells[2]->Value = "";
			
			if (logins->at(i).access == 0)
				dataGridViewLogin->Rows[i]->Cells[3]->Value = "Чтение";
			else if (logins->at(i).access == 1)
				dataGridViewLogin->Rows[i]->Cells[3]->Value = "Запись";
						
			dataGridViewLogin->Rows[i]->Cells[4]->Value = "Удалить";

		}
	}

	void Form1::loadTeachers()
	{
		if (teachers)
			delete teachers;

		teachers = mysql->getTeachers();
		dataGridViewPreps->RowCount = teachers->size();
		comboBoxTeacher->Items->Clear();
		comboBoxPrepsLogin->Items->Clear();

		for (int i = 0; i < teachers->size(); i++)
		{
			dataGridViewPreps->Rows[i]->Cells[0]->Value = gcnew String(teachers->at(i).fio.c_str());
			dataGridViewPreps->Rows[i]->Cells[1]->Value = gcnew String(teachers->at(i).kafedra.c_str());
			dataGridViewPreps->Rows[i]->Cells[2]->Value = gcnew String(teachers->at(i).zvanie.c_str());
			dataGridViewPreps->Rows[i]->Cells[3]->Value = gcnew String(teachers->at(i).stepen.c_str());
			dataGridViewPreps->Rows[i]->Cells[4]->Value = "Удалить";

			comboBoxTeacher->Items->Add(gcnew String(teachers->at(i).fio.c_str()));
			comboBoxPrepsLogin->Items->Add(gcnew String(teachers->at(i).fio.c_str()));
		}

		comboBoxTeacher->SelectedIndex = -1;
		comboBoxTeacher->Text = "";

		comboBoxPrepsLogin->SelectedIndex = -1;
		comboBoxPrepsLogin->Text = "";
	}

	System::Void Form1::buttonPrepAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxFioPrep->Text == "")
		{
			MessageBox::Show("Введите ФИО");
			return;
		}
		if (comboBoxKafedraPrep->Text == "" || comboBoxKafedraPrep->SelectedIndex==-1)
		{
			MessageBox::Show("Выберете кафедру");
			return;
		}
		if (textBoxUchStepPrep->Text == "")
		{
			MessageBox::Show("Введите учебную степень");
			return;
		}
		if (textBoxUchZvaniePrep->Text == "")
		{
			MessageBox::Show("Введите звание");
			return;
		}

		Teacher t;
		t.fio = msclr::interop::marshal_as<std::string>(textBoxFioPrep->Text);
		t.kafedraId = kafedrasAll->at(comboBoxKafedraPrep->SelectedIndex).id;
		t.stepen = msclr::interop::marshal_as<std::string>(textBoxUchStepPrep->Text);
		t.zvanie = msclr::interop::marshal_as<std::string>(textBoxUchZvaniePrep->Text);
		mysql->addTeacer(&t);

		textBoxFioPrep->Text = "";
		comboBoxKafedraPrep->Text = "";
		textBoxUchStepPrep->Text = "";
		textBoxUchZvaniePrep->Text = "";
		comboBoxKafedraPrep->SelectedIndex = -1;
	
		loadTeachers();
	}

	System::Void Form1::dataGridViewPreps_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (access == 0)
			return;
		
		if (e->ColumnIndex == 4)
		{
			mysql->deleteTeacher(teachers->at(e->RowIndex).id);
			loadTeachers();
		}
	}

	void Form1::loadKafedras()
	{
		if (kafedrasAll)
			delete kafedrasAll;

		kafedrasAll = mysql->getKafedras();
		comboBoxKafedraPrep->Items->Clear();

		for (int i = 0; i < kafedrasAll->size(); i++)
		{
			comboBoxKafedraPrep->Items->Add(gcnew String(kafedrasAll->at(i).name.c_str()));
		}
	}

	void Form1::loadStudents()
	{
		if (students)
			delete students;

		students = mysql->getStudents();
		dataGridViewStud->RowCount = students->size();

		comboBoxStudentsLogin->Items->Clear();

		for (int i = 0; i < students->size(); i++)
		{
			dataGridViewStud->Rows[i]->Cells[0]->Value = gcnew String(students->at(i).surName.c_str());
			dataGridViewStud->Rows[i]->Cells[1]->Value = gcnew String(students->at(i).name.c_str());
			dataGridViewStud->Rows[i]->Cells[2]->Value = gcnew String(students->at(i).middleName.c_str());
			dataGridViewStud->Rows[i]->Cells[3]->Value = gcnew String(students->at(i).groupName.c_str());
			dataGridViewStud->Rows[i]->Cells[4]->Value = students->at(i).kurs.ToString();
			dataGridViewStud->Rows[i]->Cells[5]->Value = "Удалить";

			comboBoxStudentsLogin->Items->Add(gcnew String((students->at(i).surName + " " +
				students->at(i).name + " " + students->at(i).middleName ).c_str()));
		}
	}

	void Form1::loadFakultets()
	{

		comboBoxFakultetDisciplinAdd->Items->Clear();
		comboBoxFakultetDisciplinShow->Items->Clear();
		comboBoxFakultetGroups->Items->Clear();
		comboBoxFakultetPlanAdd->Items->Clear();
		comboBoxFakultetStudent->Items->Clear();
		comboBoxFakultetUspevaemost->Items->Clear();
		comboBoxFakultetVedomost->Items->Clear();

		if (fakultets)
			delete fakultets;

		fakultets = mysql->getFakultets();
		for (vector<FakultetModel>::iterator iter = fakultets->begin(); iter != fakultets->end(); iter++)
		{
			comboBoxFakultetDisciplinAdd->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetDisciplinShow->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetGroups->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetPlanAdd->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetStudent->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetUspevaemost->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetVedomost->Items->Add(gcnew String((*iter).name.c_str()));
		}

		comboBoxFakultetDisciplinAdd->SelectedIndex = -1;
		comboBoxFakultetDisciplinShow->SelectedIndex = -1;
		comboBoxFakultetGroups->SelectedIndex = -1;
		comboBoxFakultetPlanAdd->SelectedIndex = -1;
		comboBoxFakultetStudent->SelectedIndex = -1;
		comboBoxFakultetUspevaemost->SelectedIndex = -1;
		comboBoxFakultetVedomost->SelectedIndex = -1;

		loadKafedras();
	}

	System::Void Form1::buttonAddStudent_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (textBoxName->Text == "")
		{
			MessageBox::Show("Введите имя");
			return;
		}

		if (textBoxSurname->Text == "")
		{
			MessageBox::Show("Введите фамилию");
			return;
		}

		int number = 0;
		if (textBoxNumber->Text == "" || !Int32::TryParse(textBoxNumber->Text, number))
		{
			MessageBox::Show("Введите номер зачетки цифрами");
			return;
		}

		int groupId = 0;
		if (comboBoxGroup->SelectedIndex >= 0)
		{
			groupId = groupStudent->at(comboBoxGroup->SelectedIndex).id;
		}
		
		studentAdd->name = msclr::interop::marshal_as<std::string>(textBoxName->Text);
		studentAdd->surName = msclr::interop::marshal_as<std::string>(textBoxSurname->Text);
		studentAdd->middleName = msclr::interop::marshal_as<std::string>(textBoxMiddleName->Text);
		studentAdd->number = number;
		studentAdd->sex = !radioButtonSexM->Checked;
		studentAdd->birth = msclr::interop::marshal_as<std::string>(dateTimePickerBirth->Value.ToString("yyyy-MM-dd"));
		studentAdd->mobile = msclr::interop::marshal_as<std::string>(textBoxMobilePhone->Text);
		studentAdd->email = msclr::interop::marshal_as<std::string>(textBoxEmail->Text);
		studentAdd->adres = msclr::interop::marshal_as<std::string>(textBoxAdres->Text);
		studentAdd->studyForm = comboBoxStudyForm->SelectedIndex;
		studentAdd->groupId = groupId;
		studentAdd->kurs = (int)numericUpDownKurs->Value;

		mysql->addStudent(studentAdd);

		loadStudents();

		MessageBox::Show("Студент добавлен");
	}

	System::Void Form1::button7_Click(System::Object^  sender, System::EventArgs^  e) {
		delete studentAdd;
		studentAdd = new StudentModel();

		textBoxName->Text = "";
		textBoxSurname->Text = "";
		textBoxMiddleName->Text = "";
		textBoxNumber->Text = "";
		radioButtonSexM->Checked = true;
		radioButtonSexF->Checked = false;
		textBoxMobilePhone->Text = "";
		textBoxEmail->Text = "";
		textBoxAdres->Text = "";
		comboBoxStudyForm->SelectedIndex = -1;
		numericUpDownKurs->Value = 1;
		comboBoxFakultetStudent->SelectedIndex = -1;
		comboBoxKafedra->SelectedIndex = -1;
		comboBoxSpecial->SelectedIndex = -1;
		comboBoxGroup->SelectedIndex = -1;
	}

	System::Void Form1::dataGridViewStud_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->ColumnIndex == 5)
		{
			if (access == 0)
				return;

			mysql->deleteStudent(students->at(e->RowIndex).id);
			loadStudents();
		}
		else
		{
			student = &students->at(e->RowIndex);

			FormStudent ^form = gcnew FormStudent(this, student, mysql);
			form->Show();
		}
		
		
	}

	System::Void  Form1::buttonSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxSearch->Text == "")
		{
			loadStudents();
			return;
		}
		
		
		if (students)
			delete students;

		students = mysql->getStudents( comboBoxSearchType->SelectedIndex, msclr::interop::marshal_as<std::string>(textBoxSearch->Text) );
		dataGridViewStud->RowCount = students->size();

		for (int i = 0; i < students->size(); i++)
		{
			dataGridViewStud->Rows[i]->Cells[0]->Value = gcnew String(students->at(i).surName.c_str());
			dataGridViewStud->Rows[i]->Cells[1]->Value = gcnew String(students->at(i).name.c_str());
			dataGridViewStud->Rows[i]->Cells[2]->Value = gcnew String(students->at(i).middleName.c_str());
			dataGridViewStud->Rows[i]->Cells[3]->Value = gcnew String(students->at(i).groupName.c_str());
			dataGridViewStud->Rows[i]->Cells[4]->Value = students->at(i).kurs.ToString();
			dataGridViewStud->Rows[i]->Cells[5]->Value = "Удалить";
		}
	}

	System::Void Form1::comboBoxFakultetGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (kafedrasAkadem)
			delete kafedrasAkadem;
		kafedrasAkadem = mysql->getKafedras( fakultets->at(comboBoxFakultetGroups->SelectedIndex).id );
		comboBoxKafedriGroups->Items->Clear();

		for (int i = 0; i < kafedrasAkadem->size(); i++)
			comboBoxKafedriGroups->Items->Add( gcnew String(kafedrasAkadem->at(i).name.c_str()) );
		
		comboBoxKafedriGroups->SelectedIndex = -1;
		comboBoxKafedriGroups->Text = "";
	}

	System::Void Form1::comboBoxKafedriGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaAkadem)
			delete napravleniaAkadem;
		napravleniaAkadem = mysql->getNapravlenies(kafedrasAkadem->at(comboBoxKafedriGroups->SelectedIndex).id);
		comboBoxNapravlenieGroups->Items->Clear();

		for (int i = 0; i < napravleniaAkadem->size(); i++)
			comboBoxNapravlenieGroups->Items->Add(gcnew String(napravleniaAkadem->at(i).name.c_str()));

		comboBoxNapravlenieGroups->SelectedIndex = -1;
		comboBoxNapravlenieGroups->Text = "";
	}

	System::Void Form1::comboBoxNapravlenieGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (groupsAkadem)
			delete groupsAkadem;
		groupsAkadem = mysql->getGroups(napravleniaAkadem->at(comboBoxNapravlenieGroups->SelectedIndex).id);
		comboBoxGroupGroups->Items->Clear();

		for (int i = 0; i < groupsAkadem->size(); i++)
			comboBoxGroupGroups->Items->Add(gcnew String(groupsAkadem->at(i).name.c_str()));

		comboBoxGroupGroups->SelectedIndex = -1;
		comboBoxGroupGroups->Text = "";
	}

	System::Void Form1::comboBoxGroupGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (studentsAkadem)
			delete studentsAkadem;
		studentsAkadem = mysql->getStudents(groupsAkadem->at(comboBoxGroupGroups->SelectedIndex).id);
		dataGridViewStudentList->RowCount = studentsAkadem->size();

		for (int i = 0; i < studentsAkadem->size(); i++)
		{
			dataGridViewStudentList->Rows[i]->Cells[0]->Value = gcnew String(studentsAkadem->at(i).surName.c_str());
			dataGridViewStudentList->Rows[i]->Cells[1]->Value = gcnew String(studentsAkadem->at(i).name.c_str());
			dataGridViewStudentList->Rows[i]->Cells[2]->Value = gcnew String(studentsAkadem->at(i).middleName.c_str());
		}
	}

	System::Void Form1::comboBoxFakultetPlanAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (kafedrasPredmets)
			delete kafedrasPredmets;
		comboBoxKafedraPlanAdd->Items->Clear();

		kafedrasPredmets = mysql->getKafedras(fakultets->at(comboBoxFakultetPlanAdd->SelectedIndex).id);
		for (int i = 0; i < kafedrasPredmets->size(); i++)
		{
			comboBoxKafedraPlanAdd->Items->Add(gcnew String(kafedrasPredmets->at(i).name.c_str()));
		}
		comboBoxKafedraPlanAdd->SelectedIndex = -1;
		comboBoxKafedraPlanAdd->Text = "";
	}

	System::Void Form1::comboBoxKafedraPlanAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaPredmets)
			delete napravleniaPredmets;

		comboBoxNapravleniePlanAdd->Items->Clear();
		napravleniaPredmets = mysql->getNapravlenies(kafedrasPredmets->at(comboBoxKafedraPlanAdd->SelectedIndex).id);
		for (int i = 0; i < napravleniaPredmets->size(); i++)
		{
			comboBoxNapravleniePlanAdd->Items->Add(gcnew String(napravleniaPredmets->at(i).name.c_str()));
		}
		comboBoxNapravleniePlanAdd->SelectedIndex = -1;
		comboBoxNapravleniePlanAdd->Text = "";

	}

	System::Void Form1::comboBoxFakultetDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		
		if (kafedrasDisciplina)
			delete kafedrasDisciplina;
		comboBoxKafedraDisciplinAdd->Items->Clear();

		kafedrasDisciplina = mysql->getKafedras(fakultets->at(comboBoxFakultetDisciplinAdd->SelectedIndex).id);
		for (int i = 0; i < kafedrasDisciplina->size(); i++)
		{
			comboBoxKafedraDisciplinAdd->Items->Add(gcnew String(kafedrasDisciplina->at(i).name.c_str()));
		}
		comboBoxKafedraDisciplinAdd->SelectedIndex = -1;
		comboBoxKafedraDisciplinAdd->Text = "";
	}

	System::Void Form1::comboBoxKafedraDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaDisciplina)
			delete napravleniaDisciplina;

		comboBoxNapravlenieDisciplinAdd->Items->Clear();
		napravleniaDisciplina = mysql->getNapravlenies(kafedrasDisciplina->at(comboBoxKafedraDisciplinAdd->SelectedIndex).id);
		for (int i = 0; i < napravleniaDisciplina->size(); i++)
		{
			comboBoxNapravlenieDisciplinAdd->Items->Add(gcnew String(napravleniaDisciplina->at(i).name.c_str()));
		}
		comboBoxNapravlenieDisciplinAdd->SelectedIndex = -1;
		comboBoxNapravlenieDisciplinAdd->Text = "";

	}

	System::Void Form1::comboBoxKursDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursDisciplinAdd->SelectedIndex == -1 || comboBoxSemestrDisciplinAdd->SelectedIndex == -1)
		{
			return;
		}
		
		if (predmetsDisciplina)
			delete predmetsDisciplina;

		predmetsDisciplina = mysql->getPredmets((comboBoxKursDisciplinAdd->SelectedIndex + 1) * 2 + comboBoxSemestrDisciplinAdd->SelectedIndex + 1,
			napravleniaDisciplina->at(comboBoxNapravlenieDisciplinAdd->SelectedIndex).id);
			 
		comboBoxDisciplin->Items->Clear();
		for (int i = 0; i < predmetsDisciplina->size(); i++)
		{
			comboBoxDisciplin->Items->Add(gcnew String(predmetsDisciplina->at(i).name.c_str()));
		}
		comboBoxDisciplin->SelectedIndex = -1;
		comboBoxDisciplin->Text = "";
		
	}

	System::Void Form1::comboBoxSemestrDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursDisciplinAdd->SelectedIndex == -1 || comboBoxSemestrDisciplinAdd->SelectedIndex == -1)
		{
			return;
		}

		if (predmetsDisciplina)
			delete predmetsDisciplina;

		predmetsDisciplina = mysql->getPredmets((comboBoxKursDisciplinAdd->SelectedIndex + 1) * 2 + comboBoxSemestrDisciplinAdd->SelectedIndex + 1,
			napravleniaDisciplina->at(comboBoxNapravlenieDisciplinAdd->SelectedIndex).id);

		comboBoxDisciplin->Items->Clear();
		for (int i = 0; i < predmetsDisciplina->size(); i++)
		{
			comboBoxDisciplin->Items->Add(gcnew String(predmetsDisciplina->at(i).name.c_str()));
		}
		comboBoxDisciplin->SelectedIndex = -1;
		comboBoxDisciplin->Text = "";

		
	}

	System::Void Form1::comboBoxFakultetDisciplinShow_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 if (kafedrasDisciplinaShow)
			 delete kafedrasDisciplinaShow;
		 comboBoxKafedriDisciplinShow->Items->Clear();

		 kafedrasDisciplinaShow = mysql->getKafedras(fakultets->at(comboBoxFakultetDisciplinShow->SelectedIndex).id);
		for (int i = 0; i < kafedrasDisciplinaShow->size(); i++)
		{
			comboBoxKafedriDisciplinShow->Items->Add(gcnew String(kafedrasDisciplinaShow->at(i).name.c_str()));
		}
		comboBoxKafedriDisciplinShow->SelectedIndex = -1;
		comboBoxKafedriDisciplinShow->Text = "";
	}

	System::Void Form1::comboBoxKafedriDisciplinShow_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 if (napravleniaDisciplinaShow)
			 delete napravleniaDisciplinaShow;

		 comboBoxNaprDisciplinShow->Items->Clear();
		 napravleniaDisciplinaShow = mysql->getNapravlenies(kafedrasDisciplinaShow->at(comboBoxKafedriDisciplinShow->SelectedIndex).id);
		for (int i = 0; i < napravleniaDisciplinaShow->size(); i++)
		{
			comboBoxNaprDisciplinShow->Items->Add(gcnew String(napravleniaDisciplinaShow->at(i).name.c_str()));
		}
		comboBoxNaprDisciplinShow->SelectedIndex = -1;
		comboBoxNaprDisciplinShow->Text = "";
	}

	System::Void Form1::buttonPlanAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		Predmet predmet;

		if (textBoxDisciplPlanAdd->Text == "")
		{
			MessageBox::Show("Введите название предмета");
			return;
		}

		if (comboBoxKursPlanAdd->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете курс");
			return;
		}

		if (comboBoxSemestrPlanAdd->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете семестр");
			return;
		}

		predmet.name = msclr::interop::marshal_as<std::string>(textBoxDisciplPlanAdd->Text);
		predmet.semestr = (comboBoxKursPlanAdd->SelectedIndex + 1) * 2 + comboBoxSemestrPlanAdd->SelectedIndex + 1;
		predmet.specialId = napravleniaPredmets->at(comboBoxNapravleniePlanAdd->SelectedIndex).id;

		mysql->addPredmet(&predmet);

		MessageBox::Show("Предмет добавлен");
		predmet.name = "";
	}

	System::Void Form1::buttonDisciplinAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxTeacher->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете учителя");
			return;
		}
		if (comboBoxDisciplin->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете дисциплину");
			return;
		}

		Predmet predmet;
		predmet.predmetId = predmetsDisciplina->at(comboBoxDisciplin->SelectedIndex).id;
		predmet.hours = (int)numericUpDownTotalTime->Value;
		predmet.hoursLec = (int)numericUpDownLectionTime->Value;
		predmet.hoursPract = (int)numericUpDownPractTime->Value;
		predmet.hoursLab = (int)numericUpDownLabTime->Value;
		predmet.teacherId = teachers->at(comboBoxTeacher->SelectedIndex).id;
		predmet.zachet = checkBoxZachet->Checked;
		predmet.kursov = checkBoxKursProj->Checked;
		predmet.exam = checkBoxExam->Checked;
		
		mysql->addPredmetPlan(&predmet);

		MessageBox::Show("Предмет добавлен в план специальности");

		comboBoxTeacher->SelectedIndex = -1;
		comboBoxTeacher->Text = "";
		comboBoxDisciplin->SelectedIndex = -1;
		comboBoxDisciplin->Text = "";
	}

	System::Void Form1::buttonDisciplinShow_Click(System::Object^  sender, System::EventArgs^  e) {
		FormDiscipline ^form = gcnew FormDiscipline(this, mysql, napravleniaDisciplinaShow->at(comboBoxNaprDisciplinShow->SelectedIndex).id,
			(comboBoxKursDisciplinShow->SelectedIndex + 1)*2 + comboBoxSemestrDisciplinShow->SelectedIndex + 1);
		form->Show();

		//comboBoxKursDisciplinAdd_SelectedIndexChanged
	}

	System::Void Form1::comboBoxFakultetVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (kafedrasVedomost)
			delete kafedrasVedomost;
		comboBoxKafedraVedomost->Items->Clear();

		kafedrasVedomost = mysql->getKafedras(fakultets->at(comboBoxFakultetVedomost->SelectedIndex).id);
		for (int i = 0; i < kafedrasVedomost->size(); i++)
		{
			comboBoxKafedraVedomost->Items->Add(gcnew String(kafedrasVedomost->at(i).name.c_str()));
		}
		comboBoxKafedraVedomost->SelectedIndex = -1;
		comboBoxKafedraVedomost->Text = "";
	}

	System::Void Form1::comboBoxKafedraVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaVedomost)
			delete napravleniaVedomost;

		comboBoxNapravlVedomost->Items->Clear();
		napravleniaVedomost = mysql->getNapravlenies(kafedrasVedomost->at(comboBoxKafedraVedomost->SelectedIndex).id);
		for (int i = 0; i < napravleniaVedomost->size(); i++)
		{
			comboBoxNapravlVedomost->Items->Add(gcnew String(napravleniaVedomost->at(i).name.c_str()));
		}
		comboBoxNapravlVedomost->SelectedIndex = -1;
		comboBoxNapravlVedomost->Text = "";
	}

	System::Void Form1::comboBoxNapravlVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (groupVedomost)
			delete groupVedomost;

		comboBoxGroupVedomost->Items->Clear();
		groupVedomost = mysql->getGroups(napravleniaVedomost->at(comboBoxNapravlVedomost->SelectedIndex).id);
		for (int i = 0; i < groupVedomost->size(); i++)
		{
			comboBoxGroupVedomost->Items->Add(gcnew String(groupVedomost->at(i).name.c_str()));
		}
		comboBoxGroupVedomost->SelectedIndex = -1;
		comboBoxGroupVedomost->Text = "";
	}

	System::Void Form1::comboBoxKursVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursVedomost->SelectedIndex == -1 || comboBoxSemestrVedomost->SelectedIndex == -1)
			return;

		if (disciplinaVedomost)
			delete disciplinaVedomost;

		disciplinaVedomost = mysql->getPredmetsTeacher(
			(comboBoxKursVedomost->SelectedIndex + 1) * 2 + comboBoxSemestrVedomost->SelectedIndex + 1,
			napravleniaVedomost->at(comboBoxNapravlVedomost->SelectedIndex).id);
		comboBoxDisciplinVedomost->Items->Clear();
		for (int i = 0; i < disciplinaVedomost->size(); i++)
		{
			comboBoxDisciplinVedomost->Items->Add( gcnew String(disciplinaVedomost->at(i).name.c_str()) );
		}
		comboBoxDisciplinVedomost->SelectedIndex = -1;
		comboBoxDisciplinVedomost->Text = "";
	}

	System::Void Form1::comboBoxSemestrVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursVedomost->SelectedIndex == -1 || comboBoxSemestrVedomost->SelectedIndex == -1)
			return;

		if (disciplinaVedomost)
			delete disciplinaVedomost;

		disciplinaVedomost = mysql->getPredmetsTeacher(
			(comboBoxKursVedomost->SelectedIndex + 1) * 2 + comboBoxSemestrVedomost->SelectedIndex + 1,
			napravleniaVedomost->at(comboBoxNapravlVedomost->SelectedIndex).id);
		comboBoxDisciplinVedomost->Items->Clear();
		for (int i = 0; i < disciplinaVedomost->size(); i++)
		{
			comboBoxDisciplinVedomost->Items->Add(gcnew String(disciplinaVedomost->at(i).name.c_str()));
		}
		comboBoxDisciplinVedomost->SelectedIndex = -1;
		comboBoxDisciplinVedomost->Text = "";
	}

	System::Void Form1::buttonShowAt_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursVedomost->SelectedIndex == -1 || comboBoxSemestrVedomost->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете курс и семестр");
			return;
		}
		if (comboBoxDisciplinVedomost->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете дисциплину");
			return;
		}

		dataGridViewAttestat->Visible = true;
		dataGridViewExam->Visible = false;

		marks = mysql->getMarks((comboBoxKursVedomost->SelectedIndex + 1) * 2 + comboBoxSemestrVedomost->SelectedIndex + 1,
			disciplinaVedomost->at(comboBoxDisciplinVedomost->SelectedIndex).id,
			groupVedomost->at(comboBoxGroupVedomost->SelectedIndex).id);

		dataGridViewAttestat->RowCount = marks->size();
		DataGridViewComboBoxColumn ^column = (DataGridViewComboBoxColumn ^)dataGridViewAttestat->Columns[11];
		column->Items->Clear();
		//new DataGridViewComboBoxColumn();
		column->Items->Add("");
		column->Items->Add("Неуд");
		column->Items->Add("Удов");
		column->Items->Add("Хор");
		column->Items->Add("Отл");

		for (int i = 0; i < marks->size(); i++)
		{
			dataGridViewAttestat->Rows[i]->Cells[0]->Value = (i+1);
			dataGridViewAttestat->Rows[i]->Cells[1]->Value = gcnew String(marks->at(i).fio.c_str());
			dataGridViewAttestat->Rows[i]->Cells[2]->Value = marks->at(i).number;
			dataGridViewAttestat->Rows[i]->Cells[3]->Value = marks->at(i).att1.ToString();
			dataGridViewAttestat->Rows[i]->Cells[4]->Value = marks->at(i).att2.ToString();
			dataGridViewAttestat->Rows[i]->Cells[5]->Value = marks->at(i).samost.ToString();
			dataGridViewAttestat->Rows[i]->Cells[6]->Value = marks->at(i).posesh.ToString();
			dataGridViewAttestat->Rows[i]->Cells[7]->Value = (marks->at(i).att1 + marks->at(i).att2 + 
				marks->at(i).samost + marks->at(i).posesh).ToString();
			dataGridViewAttestat->Rows[i]->Cells[8]->Value = marks->at(i).recomend;
			dataGridViewAttestat->Rows[i]->Cells[9]->Value = marks->at(i).exam.ToString();
			dataGridViewAttestat->Rows[i]->Cells[10]->Value = (marks->at(i).att1 + marks->at(i).att2 +
				marks->at(i).samost + marks->at(i).posesh + marks->at(i).exam).ToString();

			if (marks->at(i).mark == 0)
				dataGridViewAttestat->Rows[i]->Cells[11]->Value = "";
			else if (marks->at(i).mark == 1)
				dataGridViewAttestat->Rows[i]->Cells[11]->Value = "Неуд";
			else if (marks->at(i).mark == 2)
				dataGridViewAttestat->Rows[i]->Cells[11]->Value = "Удов";
			else if (marks->at(i).mark == 3)
				dataGridViewAttestat->Rows[i]->Cells[11]->Value = "Хор";
			else if (marks->at(i).mark == 4)
				dataGridViewAttestat->Rows[i]->Cells[11]->Value = "Отл";
		}
	}

	System::Void Form1::buttonShowExam_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxKursVedomost->SelectedIndex == -1 || comboBoxSemestrVedomost->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете курс и семестр");
			return;
		}
		if (comboBoxDisciplinVedomost->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете дисциплину");
			return;
		}
		
		dataGridViewAttestat->Visible = false;
		dataGridViewExam->Visible = true;


		marks = mysql->getMarks((comboBoxKursVedomost->SelectedIndex + 1) * 2 + comboBoxSemestrVedomost->SelectedIndex + 1,
			disciplinaVedomost->at(comboBoxDisciplinVedomost->SelectedIndex).id,
			groupVedomost->at(comboBoxGroupVedomost->SelectedIndex).id);

		dataGridViewExam->RowCount = marks->size();

		for (int i = 0; i < marks->size(); i++)
		{
			dataGridViewExam->Rows[i]->Cells[0]->Value = (i + 1);
			dataGridViewExam->Rows[i]->Cells[1]->Value = gcnew String(marks->at(i).fio.c_str());
			dataGridViewExam->Rows[i]->Cells[2]->Value = marks->at(i).number;
			dataGridViewExam->Rows[i]->Cells[3]->Value = (marks->at(i).exam / 4).ToString();
		}
	}

	System::Void Form1::dataGridViewAttestat_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (access == 0)
			return;
		
		PredmetsWithMarks *mark = &marks->at(e->RowIndex);
		
		mark->att1 = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[3]->Value->ToString());
		mark->att2 = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[4]->Value->ToString());
		mark->samost = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[5]->Value->ToString());
		mark->posesh = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[6]->Value->ToString());
		mark->recomend = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[8]->Value->ToString());
		mark->exam = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[9]->Value->ToString());
		mark->mark = Int32::Parse(dataGridViewAttestat->Rows[e->RowIndex]->Cells[10]->Value->ToString());

		String ^s = (String^)dataGridViewAttestat->Rows[e->RowIndex]->Cells[11]->Value;
		if (s->Equals(""))
			mark->mark = 0;
		else if (s->Equals("Неуд"))
			mark->mark = 1;
		else if (s->Equals("Удов"))
			mark->mark = 2;
		else if (s->Equals("Хор"))
			mark->mark = 3;
		else if (s->Equals("Отл"))
			mark->mark = 4;
			
		if (marks->at(e->RowIndex).id == 0)
		{
			//добавить
			mysql->addMark(mark);
		}
		else
		{
			//обновить
			mysql->updateMark(mark);
		}

		buttonShowAt_Click(this, gcnew EventArgs());
	}

	System::Void Form1::dataGridViewExam_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (access == 0)
			return;
		
		PredmetsWithMarks *mark = &marks->at(e->RowIndex);

		mark->exam = (int)dataGridViewExam->Rows[e->RowIndex]->Cells[3]->Value * 4;	

		if (marks->at(e->RowIndex).id == 0)
		{
			//добавить
			mysql->addMark(mark);
		}
		else
		{
			//обновить
			mysql->updateMark(mark);
		}

		buttonShowExam_Click(this, gcnew EventArgs());
	}

	System::Void Form1::buttonPrintVed_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dataGridViewAttestat->Visible)
		{
			dataGridView1 = dataGridViewAttestat;	
			tableType = 1;
		}
		else if (dataGridViewExam->Visible)
		{
			dataGridView1 = dataGridViewExam;
			tableType = 2;
		}

		// open the print dialog  
		PrintDialog^ printDialog = gcnew PrintDialog();
		printDialog->Document = printDocument1;
		printDialog->UseEXDialog = true;

		// get the document  
		if (System::Windows::Forms::DialogResult::OK == printDialog->ShowDialog()){
			printDocument1->DocumentName = "Patient Page Print";
			printDocument1->Print();
		}

	}

	System::Void Form1::comboBoxFakultetUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (kafedrasUspevaemost)
			delete kafedrasUspevaemost;
		comboBoxKafedraUspevaemost->Items->Clear();

		kafedrasUspevaemost = mysql->getKafedras(fakultets->at(comboBoxFakultetUspevaemost->SelectedIndex).id);
		for (int i = 0; i < kafedrasUspevaemost->size(); i++)
		{
			comboBoxKafedraUspevaemost->Items->Add(gcnew String(kafedrasUspevaemost->at(i).name.c_str()));
		}
		comboBoxKafedraUspevaemost->SelectedIndex = -1;
		comboBoxKafedraUspevaemost->Text = "";
	}

	System::Void Form1::comboBoxKafedraUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaUspevaemost)
			delete napravleniaUspevaemost;
		comboBoxNaprUspevaemost->Items->Clear();

		napravleniaUspevaemost = mysql->getNapravlenies(kafedrasUspevaemost->at(comboBoxKafedraUspevaemost->SelectedIndex).id);
		for (int i = 0; i < napravleniaUspevaemost->size(); i++)
		{
			comboBoxNaprUspevaemost->Items->Add(gcnew String(napravleniaUspevaemost->at(i).name.c_str()));
		}
		comboBoxNaprUspevaemost->SelectedIndex = -1;
		comboBoxNaprUspevaemost->Text = "";
	}

	System::Void Form1::comboBoxNaprUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (groupUspevaemost)
			delete groupUspevaemost;
		comboBoxGroupUspevaemost->Items->Clear();

		groupUspevaemost = mysql->getGroups(napravleniaUspevaemost->at(comboBoxNaprUspevaemost->SelectedIndex).id);
		for (int i = 0; i < groupUspevaemost->size(); i++)
		{
			comboBoxGroupUspevaemost->Items->Add(gcnew String(groupUspevaemost->at(i).name.c_str()));
		}
		comboBoxGroupUspevaemost->SelectedIndex = -1;
		comboBoxGroupUspevaemost->Text = "";
	}

	System::Void Form1::buttonShowUspevaemost_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxGroupUspevaemost->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете группу");
			return;
		}

		vector<PredmetsWithMarks> *dolgi = mysql->getDolgi(groupUspevaemost->at(comboBoxGroupUspevaemost->SelectedIndex).id,
			(comboBoxKursUspevaemost->SelectedIndex + 1) * 2 + comboBoxSemestrUspevaemost->SelectedIndex+1);
		dataGridViewDolg->RowCount = dolgi->size();
		for (int i = 0; i < dolgi->size(); i++)
		{
			dataGridViewDolg->Rows[i]->Cells[0]->Value = (i + 1).ToString();
			dataGridViewDolg->Rows[i]->Cells[1]->Value = gcnew String(dolgi->at(i).fio.c_str());
			dataGridViewDolg->Rows[i]->Cells[2]->Value = dolgi->at(i).number.ToString();
			
			
		}

		vector<UspModel> *usp = mysql->getUserUspev(groupUspevaemost->at(comboBoxGroupUspevaemost->SelectedIndex).id);
		dataGridViewUsp->RowCount = usp->size();
		for (int i = 0; i < usp->size(); i++)
		{
			dataGridViewUsp->Rows[i]->Cells[0]->Value = (i + 1).ToString();
			dataGridViewUsp->Rows[i]->Cells[1]->Value = gcnew String(usp->at(i).fio.c_str());
			dataGridViewUsp->Rows[i]->Cells[2]->Value = usp->at(i).number.ToString();
			float sum = 0;
			float cnt = 0;
			for (int j = 0; j < 8; j++)
			{
				if (usp->at(i).semestrs[j] == 0)
				{
					dataGridViewUsp->Rows[i]->Cells[3 + j]->Value = 0;
				}
				else
				{
					dataGridViewUsp->Rows[i]->Cells[3 + j]->Value = (usp->at(i).semestrs[j] + 1.0f).ToString();
					cnt += 1;
				}
				sum += usp->at(i).semestrs[j] ;
			}

			if (sum == 0)
				dataGridViewUsp->Rows[i]->Cells[11]->Value = 0;
			else
				dataGridViewUsp->Rows[i]->Cells[11]->Value = ( (sum / cnt + 1.0)/5.0*100.0f ).ToString();
		}


	}

	
	System::Void Form1::buttonPrintUsp_Click(System::Object^  sender, System::EventArgs^  e) {
		// open the print dialog  
		PrintDialog^ printDialog = gcnew PrintDialog();
		printDialog->Document = printDocument1;
		printDialog->UseEXDialog = true;

		dataGridView1 = dataGridViewUsp;
		tableType = 3;
		// get the document  
		if (System::Windows::Forms::DialogResult::OK == printDialog->ShowDialog()){
			printDocument1->DocumentName = "Patient Page Print";
			printDocument1->Print();
		}
	}

	System::Void Form1::buttonPrintCl_Click(System::Object^  sender, System::EventArgs^  e) {
		// open the print dialog  
		PrintDialog^ printDialog = gcnew PrintDialog();
		printDialog->Document = printDocument1;
		printDialog->UseEXDialog = true;
		tableType = 4;

		dataGridView1 = dataGridViewDolg;
		// get the document  
		if (System::Windows::Forms::DialogResult::OK == printDialog->ShowDialog()){
			printDocument1->DocumentName = "Patient Page Print";
			printDocument1->Print();
		}
	}

	System::Void Form1::printDocument1_BeginPrint(System::Object^  sender, System::Drawing::Printing::PrintEventArgs^  e) {
		try{
			strFormat = gcnew StringFormat();
			// horizontal alignment  
			strFormat->Alignment = StringAlignment::Near;
			// vertical alignment  
			strFormat->LineAlignment = StringAlignment::Center;
			// text needs trimming to the nearest character, and an ellipsis is inserted at the end of a trimmed line  
			strFormat->Trimming = StringTrimming::EllipsisCharacter;

			arrColumnLefts->Clear();
			arrColumnWidths->Clear();
			iCellHeight = 0;
			iRow = 0;
			bFirstPage = true;
			bNewPage = true;

			// calculating total width  
			iTotalWidth = 0;
			for each(DataGridViewColumn^ dgvGridCol in dataGridView1->Columns){
				iTotalWidth += dgvGridCol->Width;
			}
		}
		catch (Exception^ e){
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	System::Void Form1::printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
		try{
			// e->MarginBounds gives printed page dimensions within the margins  
			int iLeftMargin = e->MarginBounds.Left;
			int iTopMargin = e->MarginBounds.Top;
			// flag to indicate more pages need printing:  
			bool bMorePagesToPrint = false;
			int iTmpWidth = 0;

			// for the first page, set cell width and header height  
			if (bFirstPage){
				for each (DataGridViewColumn ^ GridCol in dataGridView1->Columns){
					// set column widths relative to the margin bounds:  
					iTmpWidth = CalculateColWidth(GridCol->Width, e->MarginBounds.Width);
					// MeasureString measure string when drawn with specified font  
					iHeaderHeight = (int)(e->Graphics->MeasureString(
						GridCol->HeaderText,
						GridCol->InheritedStyle->Font,
						iTmpWidth).Height) + 11;
					// save width and height of headers  
					arrColumnLefts->Add(iLeftMargin);
					arrColumnWidths->Add(iTmpWidth);
					// move the margin  
					iLeftMargin += iTmpWidth;
				}
			}

			// loop through each line of the DataGridView  
			while (iRow < dataGridView1->Rows->Count){
				DataGridViewRow ^ gridRow = dataGridView1->Rows[iRow];
				// set cell height  
				iCellHeight = (gridRow->Height * (iRowHeight)) + 14; // 7 is margin  
				int iCount = 0;
				// set some flags when page needs changing:  
				if (iTopMargin + iCellHeight >= e->MarginBounds.Height + e->MarginBounds.Top){
					bNewPage = true;
					bFirstPage = false;
					bMorePagesToPrint = true;
					break;
				}
				else{
					if (bNewPage){
						String ^ strHeader = "";
						if (tableType == 1)
							strHeader = "Аттестационная ведомость";
						else if (tableType == 2)
							strHeader = "Экзаменационная ведомость";

						iTopMargin += iCellHeight;

						if (tableType == 1 || tableType == 2)
						{
							e->Graphics->DrawString(
								strHeader,
								gcnew System::Drawing::Font(dataGridView1->Font->Name, 16, FontStyle::Bold),
								Brushes::Black,
								((float)e->MarginBounds.Left + (e->MarginBounds.Width - e->Graphics->MeasureString(
								strHeader,
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								e->MarginBounds.Width).Width)) / 2,
								(float)e->MarginBounds.Top - e->Graphics->MeasureString(
								strHeader,
								gcnew System::Drawing::Font(dataGridView1->Font->Name, 16, FontStyle::Bold),
								e->MarginBounds.Width).Height - (float)13.0
								);

							iTopMargin += iCellHeight;
							iTopMargin += iCellHeight;


							// draw the header   
							e->Graphics->DrawString(
								"Дисциплина:",
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								Brushes::Black,
								(float)e->MarginBounds.Left,
								(float)iTopMargin - e->Graphics->MeasureString(
								"Дисциплина:",
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								e->MarginBounds.Width).Height - (float)13.0
								);

							e->Graphics->DrawString(
								"гр. " + comboBoxGroupVedomost->Text,
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								Brushes::Black,
								e->MarginBounds.Left + (e->MarginBounds.Width - e->Graphics->MeasureString(
								"гр. " + comboBoxGroupVedomost->Text,
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								e->MarginBounds.Width).Width),
								iTopMargin - e->Graphics->MeasureString(
								"Patient Details Summary",
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								e->MarginBounds.Width).Height - 13
								);

							iTopMargin += iCellHeight;

							e->Graphics->DrawString(
								comboBoxDisciplinVedomost->Text,
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								Brushes::Black,
								(float)e->MarginBounds.Left,
								(float)iTopMargin - e->Graphics->MeasureString(
								comboBoxDisciplinVedomost->Text,
								gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
								e->MarginBounds.Width).Height - (float)13.0
								);

							iTopMargin += iCellHeight;
							iTopMargin += iCellHeight;

							if (tableType == 2)
							{
								// draw today's dateTime  
								String ^ strDate = "Дата " + DateTime::Now.ToLongDateString() + " " + DateTime::Now.ToShortTimeString();
								e->Graphics->DrawString(
									strDate,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									Brushes::Black,
									e->MarginBounds.Left + (e->MarginBounds.Width - e->Graphics->MeasureString(
									strDate,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									e->MarginBounds.Width).Width),
									iTopMargin - e->Graphics->MeasureString(
									"Patient Details Summary",
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									e->MarginBounds.Width).Height - 13
									);
							}


							if (tableType == 1)
							{
								String ^teacher = "";
								for (int t = 0; t < teachers->size(); t++)
								{
									if (teachers->at(t).id == marks->at(0).teacherId)
									{
										teacher = gcnew String(teachers->at(t).fio.c_str());
										break;
									}
								}
								e->Graphics->DrawString(
									"Преподаватель: " + teacher,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									Brushes::Black,
									(float)e->MarginBounds.Left,
									(float)iTopMargin - e->Graphics->MeasureString(
									"Преподаватель: " + teacher,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									e->MarginBounds.Width).Height - (float)13.0
									);
							}
							else if (tableType == 2)
							{
								e->Graphics->DrawString(
									"Экзаменатор: " + comboBoxTeacher->Text,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									Brushes::Black,
									(float)e->MarginBounds.Left,
									(float)iTopMargin - e->Graphics->MeasureString(
									"Экзаменатор: " + comboBoxDisciplinVedomost->Text,
									gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
									e->MarginBounds.Width).Height - (float)13.0
									);
							}
						}
						
						


						iTopMargin += iCellHeight;
						iTopMargin += iCellHeight;

						// Draw the DataGridView's header row  
						//iTopMargin = e->MarginBounds.Top;
						for each(DataGridViewColumn ^ gridCol in dataGridView1->Columns)
						{
							// Fill the header rectangle  
							e->Graphics->FillRectangle(
								gcnew SolidBrush(Color::LightGray),
								System::Drawing::Rectangle(
								(int)arrColumnLefts[iCount],
								iTopMargin,
								(int)arrColumnWidths[iCount],
								iHeaderHeight
								)
								);
							// Draw the header rectangle  
							e->Graphics->DrawRectangle(
								Pens::Black,
								System::Drawing::Rectangle(
								(int)arrColumnLefts[iCount],
								iTopMargin,
								(int)arrColumnWidths[iCount],
								iHeaderHeight
								)
								);
							// Draw the header text  
							e->Graphics->DrawString(
								gridCol->HeaderText,
								gridCol->InheritedStyle->Font,
								gcnew SolidBrush(
								gridCol->InheritedStyle->ForeColor),
								System::Drawing::Rectangle(
								(int)arrColumnLefts[iCount],
								iTopMargin,
								(int)arrColumnWidths[iCount],
								iHeaderHeight
								),
								strFormat
								);

							iCount++;
						}
						bNewPage = false;
						iTopMargin += iHeaderHeight;
					} // END if(bNewPage)  

					iCount = 0;

					// Draw text of subsequent rows on this page  
					for each(DataGridViewCell ^ cel in gridRow->Cells)
					{
						if (cel->Value != nullptr){
							e->Graphics->DrawString(
								cel->Value->ToString(),
								cel->InheritedStyle->Font,
								gcnew SolidBrush(cel->InheritedStyle->ForeColor),
								System::Drawing::Rectangle(
								(int)arrColumnLefts[iCount],
								iTopMargin,
								(int)arrColumnWidths[iCount],
								iCellHeight
								),
								strFormat
								);
						}

						// Draw cell borders  
						e->Graphics->DrawRectangle(
							Pens::Black,
							System::Drawing::Rectangle(
								(int)arrColumnLefts[iCount],
								iTopMargin,
								(int)arrColumnWidths[iCount],
								iCellHeight
							)
							);
						iCount++;
					}

					


				} // END else  
				iRow++;
				iTopMargin += iCellHeight;
			} // END while  

			// if more lines are present, // if more lines are present, invoke printDocument1_PrintPage() again  
			if (bMorePagesToPrint){
				e->HasMorePages = true;
			}
			else{
				e->HasMorePages = false;
			}


			iTopMargin += iCellHeight*5;
			if (tableType == 1 || tableType == 2)
			{
				int sum = 0;
				int novizit = 0;
				int nedopusk = 0;
				int otl = 0;
				int hor = 0;
				int udv = 0;
				int neud = 0;

				for (int i = 0; i < marks->size(); i++)
				{
					if (marks->at(i).exam != 0)
					{
						sum++;
						if (marks->at(i).exam / 5 == 0)
							neud++;
						else if (marks->at(i).exam / 5 == 1)
							udv++;
						else if (marks->at(i).exam / 5 == 3)
							hor++;
						else if (marks->at(i).exam / 5 >= 4)
							otl++;
					}
					else
					{
						if (marks->at(i).att1 + marks->at(i).att2 +
							marks->at(i).samost + marks->at(i).posesh < 30)
							nedopusk++;
						else
							novizit++;
					}
				}

				String ^text = "Число студентов на экзамене (зачете)  " + sum;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "Из них получивших \"отлично\"  " + otl;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "                  \"хорошо\"  " + hor;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "                  \"удовлетворительно\"  " + udv;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "                  \"неудовлетворительно\"  " + neud;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "Число студентов, не явившихся на экзамен (зачет)   " + novizit;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;

				text = "Число студентов, не допущенных к экзамену (зачету)  " + nedopusk;
				e->Graphics->DrawString(
					text,
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					Brushes::Black,
					e->MarginBounds.Left ,
					iTopMargin - e->Graphics->MeasureString(
					"Patient Details Summary",
					gcnew System::Drawing::Font(dataGridView1->Font, FontStyle::Bold),
					e->MarginBounds.Width).Height - 13
					);
				iTopMargin += iCellHeight;
			}
		} // END try  

		catch (Exception ^ e){
			MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	int Form1::CalculateColWidth(int gridColWidth, int marginWidth)
	{

		int thisWidth = 1;
		// Math::Floor returns the largest integer less than or equal to the specified double.  
		thisWidth = (int)(System::Math::Floor(
			(double)(
			(double)gridColWidth / (double)iTotalWidth * (double)marginWidth
			)
			)
			);
		return thisWidth;
	}

	System::Void Form1::buttonAddUser_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxLogin->Text == "")
		{
			MessageBox::Show("Введите логин");
			return;
		}
		if (textBoxPass->Text == "")
		{
			MessageBox::Show("Введите пароль");
			return;
		}
		User user;
		user.login = msclr::interop::marshal_as<std::string>(textBoxLogin->Text);
		user.pass = msclr::interop::marshal_as<std::string>(textBoxPass->Text);
		user.access = checkBoxAccess->Checked ? 1 : 0;
		user.teacherId = 0;
		user.studentId = 0;

		if (radioButtonPreps->Checked && comboBoxPrepsLogin->SelectedIndex != -1)
			user.teacherId = teachers->at(comboBoxPrepsLogin->SelectedIndex).id;
		else if (radioButtonStudent->Checked && comboBoxStudentsLogin->SelectedIndex != -1)
			user.studentId = students->at(comboBoxStudentsLogin->SelectedIndex).id;

		
		mysql->addUser(&user);

		textBoxLogin->Text = "";
		textBoxPass->Text = "";
		MessageBox::Show("Пользователь добавлен");

		loadLogins();
	}

	System::Void Form1::dataGridViewLogin_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (access == 0)
			return;
		
		if (e->ColumnIndex == 4)
		{
			mysql->deleteUser(logins->at(e->RowIndex).id);
			MessageBox::Show("Пользователь удален");

			loadLogins();
		}
	}

	System::Void Form1::comboBoxFakultetStudent_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (kafedrasStudent)
			delete kafedrasStudent;
		kafedrasStudent = mysql->getKafedras(fakultets->at(comboBoxFakultetStudent->SelectedIndex).id);
		comboBoxKafedra->Items->Clear();

		for (int i = 0; i < kafedrasStudent->size(); i++)
			comboBoxKafedra->Items->Add(gcnew String(kafedrasStudent->at(i).name.c_str()));

		comboBoxKafedra->SelectedIndex = -1;
		comboBoxKafedra->Text = "";
	}

	System::Void Form1::comboBoxKafedra_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (napravleniaStudent)
			delete napravleniaStudent;
		napravleniaStudent = mysql->getNapravlenies(kafedrasStudent->at(comboBoxKafedra->SelectedIndex).id);
		comboBoxSpecial->Items->Clear();

		for (int i = 0; i < napravleniaStudent->size(); i++)
			comboBoxSpecial->Items->Add(gcnew String(napravleniaStudent->at(i).name.c_str()));

		comboBoxSpecial->SelectedIndex = -1;
		comboBoxSpecial->Text = "";
	}

	System::Void Form1::comboBoxSpecial_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (groupStudent)
			delete groupStudent;
		groupStudent = mysql->getGroups(napravleniaStudent->at(comboBoxSpecial->SelectedIndex).id);
		comboBoxGroup->Items->Clear();

		for (int i = 0; i < groupStudent->size(); i++)
			comboBoxGroup->Items->Add(gcnew String(groupStudent->at(i).name.c_str()));

		comboBoxGroup->SelectedIndex = -1;
		comboBoxGroup->Text = "";
	}
}