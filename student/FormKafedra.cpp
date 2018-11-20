#include "FormKafedra.h"
#include "FormMain.h"
#include <msclr\marshal_cppstd.h>
#include "MySQL.h"

namespace Student
{

	FormKafedra::FormKafedra(Form1 ^form, MySQL *mysql)
	{
		InitializeComponent();

		this->form = form;
		this->mysql = mysql;

		listFakultets = NULL;
		listKafedras = NULL;

		loadFakultets();
		loadKafedras();

		if (form->access == 0)
		{
			buttonAdd->Enabled = false;
			buttonDelete->Enabled = false;
			buttonEdit->Enabled = false;
		}
	}

	void FormKafedra::loadFakultets()
	{
		comboBoxFakultetAdd->Items->Clear();
		comboBoxFakultetEdit->Items->Clear();

		if (listFakultets)
			delete listFakultets;
		listFakultets = mysql->getFakultets();

		int i = 0;
		for (vector<FakultetModel>::iterator iter = listFakultets->begin(); iter != listFakultets->end(); iter++)
		{
			comboBoxFakultetAdd->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetEdit->Items->Add(gcnew String((*iter).name.c_str()));
		}

		comboBoxFakultetAdd->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
	}

	System::Void FormKafedra::FormKafedra_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		form->loadKafedras();
	}

	void FormKafedra::loadKafedras()
	{
		comboBoxIds->Items->Clear();

		if (listKafedras)
			delete listKafedras;
		listKafedras = mysql->getKafedras();
		dataGridView1->RowCount = listKafedras->size();
		int i = 0;
		for (vector<KafedraModel>::iterator iter = listKafedras->begin(); iter != listKafedras->end(); iter++)
		{
			comboBoxIds->Items->Add((*iter).id.ToString());

			dataGridView1->Rows[i]->Cells[0]->Value = (*iter).id.ToString();
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String((*iter).name.c_str());
			dataGridView1->Rows[i]->Cells[2]->Value = gcnew String((*iter).fakultetName.c_str());
						
			i++;
		}
		
		comboBoxIds->SelectedIndex = -1;
	}

	System::Void FormKafedra::button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxKafedraAdd->Text == "")
		{
			MessageBox::Show("Введите название");
			return;
		}

		if (comboBoxFakultetAdd->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете факультет");
			return;
		}

		KafedraModel kafedra;
		kafedra.name = msclr::interop::marshal_as<std::string>(textBoxKafedraAdd->Text);
		kafedra.fakultetId = listFakultets->at(comboBoxFakultetAdd->SelectedIndex).id;
		mysql->addKafedra(&kafedra);
		textBoxKafedraAdd->Text = "";

		MessageBox::Show("Кафедра добавлена");

		loadKafedras();
	}

	System::Void FormKafedra::buttonEdit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxKafedraEdit->Text == "")
		{
			MessageBox::Show("Введите название");
			return;
		}

		if (comboBoxIds->Text == "")
		{
			MessageBox::Show("Выберете id");
			return;
		}

		if (comboBoxFakultetEdit->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете факультет");
			return;
		}

		KafedraModel kafedra;
		kafedra.id = Int32::Parse(comboBoxIds->Text);
		kafedra.name = msclr::interop::marshal_as<std::string>(textBoxKafedraEdit->Text);
		kafedra.fakultetId = listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id;
		mysql->updateKafedra(&kafedra);

		comboBoxIds->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
		textBoxKafedraEdit->Text = "";

		MessageBox::Show("Кафедра изменена");

		loadKafedras();
	}

	System::Void FormKafedra::buttonDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxIds->Text == "")
		{
			MessageBox::Show("Выберете id");
			return;
		}

		int id = Int32::Parse(comboBoxIds->Text);
		mysql->deleteKafedra(id);

		comboBoxIds->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
		textBoxKafedraEdit->Text = "";

		MessageBox::Show("Кафедра удалена");

		loadKafedras();
	}
}