#include "stdafx.h"
#include "FormNapravlenie.h"
#include "FormMain.h"

namespace Student
{
	FormNapravlenie::FormNapravlenie(Form1 ^mainForm, MySQL *mysql)
	{
		this->mainForm = mainForm;
		this->mysql = mysql;

		InitializeComponent();

		listFakultets = NULL;
		listKafedras = NULL;
		listKafedrasEdit = NULL;
		listNapravlenie = NULL;

		loadFakultets();
		//loadKafedras();
		loadNapravlenie();

		if (mainForm->access==0)
		{
			buttonAdd->Enabled = false;
			buttonDelete->Enabled = false;
			buttonEdit->Enabled = false;
		}
	}

	void FormNapravlenie::loadFakultets()
	{
		comboBoxFakultetEdit->Items->Clear();
		comboBoxFakultets->Items->Clear();

		if (listFakultets)
			delete listFakultets;

		listFakultets = mysql->getFakultets();
		int i = 0;
		for (vector<FakultetModel>::iterator iter = listFakultets->begin(); iter != listFakultets->end(); iter++)
		{
			comboBoxFakultets->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetEdit->Items->Add(gcnew String((*iter).name.c_str()));
		}

		//comboBoxFakultet->setCurrentIndex(-1);
		//comboBoxFakultetEdit->setCurrentIndex(-1);
	}

	/*
	void FormNapravlenie::loadKafedras()
	{
		if (listKafedras)
			delete listKafedras;

		listKafedras = mysql->getKafedras();
		int i = 0;

		//comboBoxKafedra->setCurrentIndex(-1);
		//comboBoxKafedraEdit->setCurrentIndex(-1);
	}*/

	void FormNapravlenie::loadNapravlenie()
	{
		comboBoxIds->Items->Clear();
		
		if (listNapravlenie)
			delete listNapravlenie;

		listNapravlenie = mysql->getNapravlenies();
		dataGridView1->RowCount = listNapravlenie->size();
		
		int i = 0;
		for (vector<NapravlenieModel>::iterator iter = listNapravlenie->begin(); iter != listNapravlenie->end(); iter++)
		{
			comboBoxIds->Items->Add((*iter).id.ToString());

			dataGridView1->Rows[i]->Cells[0]->Value = (*iter).id;
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String((*iter).name.c_str());
			dataGridView1->Rows[i]->Cells[2]->Value = gcnew String((*iter).fakultetName.c_str());
			dataGridView1->Rows[i]->Cells[3]->Value = gcnew String((*iter).kafedraName.c_str());

			i++;
		}
		
		comboBoxIds->SelectedIndex = -1;
	}

	System::Void FormNapravlenie::buttonAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxNameAdd->Text == "")
		{
			MessageBox::Show("Введите название");			
			return;
		}

		if (comboBoxFakultets->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете факультет");
			return;
		}

		if (comboBoxKafedras->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете кафедру");
			return;
		}

		NapravlenieModel napravlenie;
		napravlenie.name = msclr::interop::marshal_as<std::string>(textBoxNameAdd->Text);
		napravlenie.fakultetId = listFakultets->at(comboBoxFakultets->SelectedIndex).id;
		napravlenie.kafedraId = listKafedras->at(comboBoxKafedras->SelectedIndex).id;
		mysql->addNapravlenie(&napravlenie);
		textBoxNameAdd->Text = "";

		MessageBox::Show("Направление добавлено");

		loadNapravlenie();
	}

	System::Void FormNapravlenie::buttonEdit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxEdit->Text)
		{
			MessageBox::Show("Введите название");
			return;
		}

		if (comboBoxIds->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете id");
			return;
		}

		if (comboBoxFakultetEdit->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете факультет");
			return;
		}

		if (comboBoxKafedraEdit->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете кафедру");			
			return;
		}

		NapravlenieModel napravlenie;
		napravlenie.id = Int32::Parse(comboBoxIds->Text);
		napravlenie.name = msclr::interop::marshal_as<std::string>(textBoxEdit->Text);
		napravlenie.fakultetId = listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id;
		napravlenie.kafedraId = listKafedrasEdit->at(comboBoxKafedraEdit->SelectedIndex).id;
		mysql->updateNapravlenie(&napravlenie);

		comboBoxIds->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
		textBoxEdit->Text = "";

		MessageBox::Show("Направление изменено");

		loadNapravlenie();
	}

	System::Void FormNapravlenie::buttonDelete_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBoxIds->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете id");
			return;
		}

		int id = Int32::Parse(comboBoxIds->Text);
		mysql->deleteNapravlenie(id);

		comboBoxIds->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
		comboBoxKafedraEdit->SelectedIndex = -1;
		textBoxEdit->Text = "";

		MessageBox::Show("Кафедра удалена");

		loadNapravlenie();
	}

	System::Void FormNapravlenie::comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBoxIds->SelectedIndex != -1 && dataGridView1->RowCount > comboBoxIds->SelectedIndex)
		{
			textBoxEdit->Text = dataGridView1->Rows[comboBoxIds->SelectedIndex]->Cells[1]->Value->ToString();
			for (int i = 0; i < listFakultets->size(); i++)
			{
				if (listNapravlenie->at(comboBoxIds->SelectedIndex).fakultetId == listFakultets->at(i).id)
				{
					comboBoxFakultetEdit->SelectedIndex = i;
					break;
				}
			}

			listKafedrasEdit = mysql->getKafedras(listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id);
			comboBoxKafedraEdit->Items->Clear();
			for (int i = 0; i < listKafedrasEdit->size(); i++)
				comboBoxKafedraEdit->Items->Add(gcnew String(listKafedrasEdit->at(i).name.c_str()));

			comboBoxKafedraEdit->SelectedIndex = -1;
			comboBoxKafedraEdit->Text = "";
			for (int i = 0; i < listKafedrasEdit->size(); i++)
			{
				if (listNapravlenie->at(comboBoxIds->SelectedIndex).kafedraId == listKafedrasEdit->at(i).id)
				{
					comboBoxKafedraEdit->SelectedIndex = i;
					break;
				}
			}
		}
	}

	System::Void FormNapravlenie::comboBoxFakultetEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listKafedrasEdit = mysql->getKafedras(listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id);
		comboBoxKafedraEdit->Items->Clear();
		for (int i = 0; i < listKafedrasEdit->size(); i++)
			comboBoxKafedraEdit->Items->Add(gcnew String(listKafedrasEdit->at(i).name.c_str()));

		comboBoxKafedraEdit->SelectedIndex = -1;
		comboBoxKafedraEdit->Text = "";
	}

	System::Void FormNapravlenie::comboBoxFakultets_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listKafedras = mysql->getKafedras(listFakultets->at(comboBoxFakultets->SelectedIndex).id);
		comboBoxKafedras->Items->Clear();
		for (int i = 0; i < listKafedras->size(); i++)
			comboBoxKafedras->Items->Add(gcnew String(listKafedras->at(i).name.c_str()));

		comboBoxKafedras->SelectedIndex = -1;
		comboBoxKafedras->Text = "";
	}
}