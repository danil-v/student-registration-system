#include "FormAddition.h"

#include "FormMain.h"
#include "MySQL.h"

namespace Student
{
	FormAddition::FormAddition(Form1 ^form, StudentModel *student, MySQL *mysql)
	{
		this->form = form;
		this->student = student;
		this->mysql = mysql;

		InitializeComponent();

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

	}

	System::Void FormAddition::FormAddition_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (form->access == 1)
		{
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

		}

		
		//mysql->updateStudent(student);
	}
}