#include "FormStudent.h"
#include "MySQL.h"
#include "FormMain.h"

namespace Student
{
	FormStudent::FormStudent(Form1 ^formMain, StudentModel *student, MySQL *mysql)
	{
		this->formMain = formMain;
		this->student = student;
		this->mysql = mysql;
		InitializeComponent();

		textBoxName->Text = gcnew String(student->name.c_str());
		textBoxSurname->Text = gcnew String(student->surName.c_str());
		textBoxMiddleName->Text = gcnew String(student->middleName.c_str());
		textBoxNumber->Text = student->number.ToString();
		radioButtonMale->Checked = student->sex == 0;
		radioButtonFemale->Checked = student->sex == 1;
		dateTimePickerBirth->Value = DateTime::ParseExact(gcnew String(student->birth.c_str()), gcnew String("yyyy-MM-dd"), CultureInfo::InvariantCulture,
			DateTimeStyles::None);
		textBoxMobile->Text = gcnew String(student->mobile.c_str());
		textBoxEmail->Text = gcnew String(student->email.c_str());
		textBoxAdres->Text = gcnew String(student->adres.c_str());
		comboBoxStudyForm->SelectedIndex = student->studyForm;

		fakultets = mysql->getFakultets();
		for (int i = 0; i < fakultets->size(); i++)
		{
			comboBoxFakultet->Items->Add( gcnew String(fakultets->at(i).name.c_str()) );
			if (fakultets->at(i).id == student->fakultetId)
				comboBoxFakultet->SelectedIndex = i;
		}

		kafedras = mysql->getKafedras(student->fakultetId);
		for (int i = 0; i < kafedras->size(); i++)
		{
			comboBoxKafedra->Items->Add(gcnew String(kafedras->at(i).name.c_str()));
			if (kafedras->at(i).id == student->kafedraId)
				comboBoxKafedra->SelectedIndex = i;
		}

		napravlenies = mysql->getNapravlenies(student->kafedraId);
		for (int i = 0; i < napravlenies->size(); i++)
		{
			comboBoxSpecial->Items->Add(gcnew String(napravlenies->at(i).name.c_str()));
			if (napravlenies->at(i).id == student->napravlenieId)
				comboBoxSpecial->SelectedIndex = i;
		}

		groups = mysql->getGroups(student->napravlenieId);
		for (int i = 0; i < groups->size(); i++)
		{
			comboBoxGroup->Items->Add(gcnew String(groups->at(i).name.c_str()));
			if (groups->at(i).id == student->groupId)
				comboBoxGroup->SelectedIndex = i;
		}
		
		numericUpDownKurs->Value = student->kurs;


		radioButtonPay->Checked = !student->payStudy;
		radioButtonPayNo->Checked = student->payStudy;
		textBoxPrevStudy->Text = gcnew String(student->prevStudy.c_str());
		textBoxFamily->Text = gcnew String(student->family.c_str());
		radioButtonChildren->Checked = student->isChildren;
		radioButtonChildrenNo->Checked = !student->isChildren;
		radioButtonNeedHostel->Checked = student->isNeedHostel;
		radioButtonNeedHostelNo->Checked = !student->isNeedHostel;
		textBoxNational->Text = gcnew String(student->natinality.c_str());
		radioButtonMilitary->Checked = student->isMilitary;
		radioButtonMilitaryNo->Checked = !student->isMilitary;
		textBoxSport->Text = gcnew String(student->sport.c_str());
		textBoxOlymp->Text = gcnew String(student->olymps.c_str());
		textBoxArt->Text = gcnew String(student->arts.c_str());
		dateTimePickerStudyStart->Value = DateTime::ParseExact(gcnew String(student->studyStart.c_str()), gcnew String("yyyy-MM-dd"), CultureInfo::InvariantCulture,
			DateTimeStyles::None);
		dateTimePickerStudyEnd->Value = DateTime::ParseExact(gcnew String(student->studyEnd.c_str()), "yyyy-MM-dd", CultureInfo::InvariantCulture,
			DateTimeStyles::None);

		poruchenia = NULL;
		dostigenia = NULL;
		dolgi = NULL;
		marks = NULL;

		loadDostig();
		loadPoruch();
		loadDolgi();

		if (formMain->access == 0)
		{
			buttonAddAchiev->Enabled = false;
			buttonDolgiAdd->Enabled = false;
			buttonPoruchAdd->Enabled = false;
		}
	}

	System::Void FormStudent::FormStudent_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (formMain->access == 0)
		{
			return;
		}

		student->name = msclr::interop::marshal_as<std::string>(textBoxName->Text);
		student->surName = msclr::interop::marshal_as<std::string>(textBoxSurname->Text);
		student->middleName = msclr::interop::marshal_as<std::string>(textBoxMiddleName->Text);
		student->number = Int32::Parse(textBoxNumber->Text);
		student->sex = radioButtonFemale->Checked;
		student->birth = msclr::interop::marshal_as<std::string>(dateTimePickerBirth->Value.ToString("yyyy-MM-dd"));
		student->mobile = msclr::interop::marshal_as<std::string>(textBoxMobile->Text);
		student->email = msclr::interop::marshal_as<std::string>(textBoxEmail->Text);
		student->adres = msclr::interop::marshal_as<std::string>(textBoxAdres->Text);
		student->studyForm = comboBoxStudyForm->SelectedIndex;
		if (comboBoxFakultet->SelectedIndex != -1)
			student->fakultetId = fakultets->at(comboBoxFakultet->SelectedIndex).id;
		if (comboBoxKafedra->SelectedIndex != -1)
			student->kafedraId = kafedras->at(comboBoxKafedra->SelectedIndex).id;
		if (comboBoxSpecial->SelectedIndex != -1)
			student->napravlenieId = napravlenies->at(comboBoxSpecial->SelectedIndex).id;
		if (comboBoxGroup->SelectedIndex != -1)
			student->groupId = groups->at(comboBoxGroup->SelectedIndex).id;		
		student->kurs = (int)numericUpDownKurs->Value;
		
		student->payStudy = radioButtonPayNo->Checked;
		student->prevStudy = msclr::interop::marshal_as<std::string>(textBoxPrevStudy->Text);
		student->family = msclr::interop::marshal_as<std::string>(textBoxFamily->Text);
		student->isChildren = radioButtonChildren->Checked;
		student->isNeedHostel = radioButtonNeedHostel->Checked;;
		student->natinality = msclr::interop::marshal_as<std::string>(textBoxNational->Text);
		student->isMilitary = radioButtonMilitary->Checked;
		student->sport = msclr::interop::marshal_as<std::string>(textBoxSport->Text);
		student->olymps = msclr::interop::marshal_as<std::string>(textBoxOlymp->Text);
		student->arts = msclr::interop::marshal_as<std::string>(textBoxArt->Text);
		student->studyStart = msclr::interop::marshal_as<std::string>(dateTimePickerStudyStart->Value.ToString("yyyy-MM-dd"));
		student->studyEnd = msclr::interop::marshal_as<std::string>(dateTimePickerStudyEnd->Value.ToString("yyyy-MM-dd"));

		
		mysql->updateStudent(student);
		formMain->loadStudents();
	}

	void FormStudent::loadDostig()
	{
		if (dostigenia)
			delete dostigenia;

		dostigenia = mysql->loadArchiev(student->id);
		dataGridViewAchiev->RowCount = dostigenia->size();
		for (int i = 0; i < dostigenia->size(); i++)
		{
			dataGridViewAchiev->Rows[i]->Cells[0]->Value = gcnew String(dostigenia->at(i).data.c_str());
			dataGridViewAchiev->Rows[i]->Cells[1]->Value = "Изменить";
			dataGridViewAchiev->Rows[i]->Cells[2]->Value = "Удалить";
		}
	}

	void FormStudent::loadPoruch()
	{
		if (poruchenia)
			delete poruchenia;

		poruchenia = mysql->loadPoruch(student->id);
		dataGridViewPoruch->RowCount = poruchenia->size();
		for (int i = 0; i < poruchenia->size(); i++)
		{
			dataGridViewPoruch->Rows[i]->Cells[0]->Value = gcnew String(poruchenia->at(i).data.c_str());
			if (poruchenia->at(i).status == 2)
			{
				dataGridViewPoruch->Rows[i]->Cells[1] = gcnew DataGridViewButtonCell();
				dataGridViewPoruch->Rows[i]->Cells[1]->Value = "Выполнить";
			}
			else
			{
				dataGridViewPoruch->Rows[i]->Cells[1] = gcnew DataGridViewTextBoxCell();
				dataGridViewPoruch->Rows[i]->Cells[1]->Value = "Выполнено";
			}

			dataGridViewPoruch->Rows[i]->Cells[2]->Value = "Удалить";
		}
	}

	void FormStudent::loadDolgi()
	{
		if (dolgi)
			delete dolgi;

		dolgi = mysql->loadDolgi(student->id);
		dataGridViewDolgi->RowCount = dolgi->size();
		for (int i = 0; i < dolgi->size(); i++)
		{
			dataGridViewDolgi->Rows[i]->Cells[0]->Value = gcnew String(dolgi->at(i).data.c_str());
			if (dolgi->at(i).status == 2)
			{
				dataGridViewDolgi->Rows[i]->Cells[1] = gcnew DataGridViewButtonCell();
				dataGridViewDolgi->Rows[i]->Cells[1]->Value = "Сдать";
			}
			else
			{
				dataGridViewDolgi->Rows[i]->Cells[1] = gcnew DataGridViewTextBoxCell();
				dataGridViewDolgi->Rows[i]->Cells[1]->Value = "Сдан";
			}

			dataGridViewDolgi->Rows[i]->Cells[2]->Value = "Удалить";
		}
	}

	System::Void FormStudent::buttonAddAchiev_Click(System::Object^  sender, System::EventArgs^  e) {

		if (textBoxAchiev->Text == "")
		{
			MessageBox::Show("Введите текст достижения");
			return;
		}
			
		mysql->addWork(student->id, MySQL::ARCHIEVMENT,
					msclr::interop::marshal_as<std::string>(textBoxAchiev->Text) );

		loadDostig();
		textBoxAchiev->Text = "";
		MessageBox::Show("Добавлено");
	}

	System::Void FormStudent::buttonPoruchAdd_Click(System::Object^  sender, System::EventArgs^  e) {

		if (textBoxPoruch->Text == "")
		{
			MessageBox::Show("Введите текст поручения");
			return;
		}

		mysql->addWork(student->id, MySQL::TASK,
			msclr::interop::marshal_as<std::string>(textBoxAchiev->Text));

		loadPoruch();
		textBoxPoruch->Text = "";
		MessageBox::Show("Добавлено");
	}

	System::Void FormStudent::buttonDolgiAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (textBoxDolgi->Text == "")
		{
			MessageBox::Show("Введите текст долга");
			return;
		}

		mysql->addWork(student->id, MySQL::DOLG,
			msclr::interop::marshal_as<std::string>(textBoxDolgi->Text));

		loadPoruch();
		textBoxDolgi->Text = "";
		MessageBox::Show("Добавлено");
	}

	System::Void FormStudent::dataGridViewAchiev_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (formMain->access == 0)
		{
			return;
		}
		
		//изменить
		if (e->ColumnIndex == 1)
		{
			mysql->updateWork( dostigenia->at(e->RowIndex).id, 
				msclr::interop::marshal_as<std::string>(dataGridViewAchiev->Rows[e->RowIndex]->Cells[1]->Value->ToString()),
				MySQL::ARCHIEVMENT);
			MessageBox::Show("Изменено");
		}
		else if (e->ColumnIndex == 2) //удалить
		{
			mysql->deleteWork(dostigenia->at(e->RowIndex).id);
			MessageBox::Show("Удалено");
		}

		loadDostig();
	}

	System::Void FormStudent::dataGridViewPoruch_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		
		if (formMain->access == 0)
		{
			return;
		}
		
		if (e->ColumnIndex == 1)
		{
			mysql->updateWork(poruchenia->at(e->RowIndex).id,
				msclr::interop::marshal_as<std::string>(
					dataGridViewPoruch->Rows[e->RowIndex]->Cells[1]->Value->ToString()),
				MySQL::TASK_COMPLETE);
		}
		else if (e->ColumnIndex == 2)
		{
			mysql->updateWork(poruchenia->at(e->RowIndex).id,
				msclr::interop::marshal_as<std::string>(
					dataGridViewPoruch->Rows[e->RowIndex]->Cells[1]->Value->ToString()),
					poruchenia->at(e->RowIndex).status);
			MessageBox::Show("Изменено");
		}
		else if (e->ColumnIndex == 3) //удалить
		{
			mysql->deleteWork(poruchenia->at(e->RowIndex).id);
			MessageBox::Show("Удалено");
		}

		loadPoruch();
	}

	System::Void FormStudent::dataGridViewDolgi_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		
		if (formMain->access == 0)
		{
			return;
		}
		
		if (e->ColumnIndex == 1)
		{
			mysql->updateWork(dolgi->at(e->RowIndex).id,
				msclr::interop::marshal_as<std::string>(
				dataGridViewDolgi->Rows[e->RowIndex]->Cells[1]->Value->ToString()),
				MySQL::DOLG_COMPLETE);
		}
		else if (e->ColumnIndex == 2)
		{
			mysql->updateWork(dolgi->at(e->RowIndex).id,
				msclr::interop::marshal_as<std::string>(
				dataGridViewDolgi->Rows[e->RowIndex]->Cells[1]->Value->ToString()),
				dolgi->at(e->RowIndex).status);
			MessageBox::Show("Изменено");
		}
		else if (e->ColumnIndex == 3) //удалить
		{
			mysql->deleteWork(dolgi->at(e->RowIndex).id);
			MessageBox::Show("Удалено");
		}

		loadDolgi();
	}

	System::Void FormStudent::buttonMarksShow_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxMarksKurs->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете курс");
			return;
		}
		if (comboBoxMarksSemestr->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете семестр");
			return;
		}

		marks = mysql->getUserMarks(student->id, comboBoxMarksKurs->SelectedIndex + 1, comboBoxMarksSemestr->SelectedIndex + 1);
		dataGridViewMarks->RowCount = marks->size();
		for (int i = 0; i < marks->size(); i++)
		{
			dataGridViewMarks->Rows[i]->Cells[0]->Value = gcnew String(marks->at(i).predmet.c_str());
			dataGridViewMarks->Rows[i]->Cells[1]->Value = marks->at(i).att1.ToString();
			dataGridViewMarks->Rows[i]->Cells[2]->Value = marks->at(i).att2.ToString();
			dataGridViewMarks->Rows[i]->Cells[3]->Value = marks->at(i).samost.ToString();
			dataGridViewMarks->Rows[i]->Cells[4]->Value = marks->at(i).exam.ToString();
			dataGridViewMarks->Rows[i]->Cells[5]->Value = marks->at(i).mark.ToString();
		}

	}

	System::Void FormStudent::buttonSave_Click(System::Object^  sender, System::EventArgs^  e) {
		if (marks==NULL || marks->size() == 0)
		{
			MessageBox::Show("Таблица пуста");
			return;
		}

		
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
		saveFileDialog1->Filter = "csv files (*.csv)|*.csv|All files (*.*)|*.*";
		saveFileDialog1->FilterIndex = 2;
		saveFileDialog1->RestoreDirectory = true;

		saveFileDialog1->ShowDialog();
		if (saveFileDialog1->FileName != "")
		{
			StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);

			sw->WriteLine("Предмет;Атт1;Атт2;Самостоятельная работа;Экзамен;Оценка");

			for (int i = 0; i < marks->size(); i++)
			{
				sw->WriteLine(gcnew String(marks->at(i).predmet.c_str()) + ";" +
					marks->at(i).att1.ToString() + ";" +
					marks->at(i).att2.ToString() + ";" +
					marks->at(i).samost.ToString() + ";" +
					marks->at(i).exam.ToString() + ";" + 
					marks->at(i).mark.ToString());
			}

			sw->Close();

		}
	}

	
}