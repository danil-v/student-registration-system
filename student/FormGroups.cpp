
#include "FormGroups.h"
#include "FormMain.h"

namespace Student
{
	FormGroups::FormGroups(Form1 ^mainForm, MySQL* mysql)
	{
		this->mainForm = mainForm;
		this->mysql = mysql;

		InitializeComponent();

		listFakultets = NULL;
		listKafedras = NULL;
		listKafedrasEdit = NULL;
		listNapravlenie = NULL;
		listNapravlenieEdit = NULL;

		loadFakultets();
		loadGroups();

		if (mainForm->access == 0)
		{
			buttonAdd->Enabled = false;
			buttonDelete->Enabled = false;
			buttonEdit->Enabled = false;
		}
		
		textBoxName->Text = getGroupName();
	}

	String ^FormGroups::getGroupName()
	{
		int y = DateTime::Now.Year;
		String ^strY = y.ToString();
		strY = "Б" + strY->Substring(2);

		String ^oldGr = gcnew String( mysql->getLastGroup(msclr::interop::marshal_as<std::string>(strY) ).c_str());
		int num = Int32::Parse(oldGr->Substring(4, 3));
		num++;
		String ^numStr = num.ToString();
		while (numStr->Length < 3)
			numStr = "0" + numStr;

		String ^newGrNumber = strY + "-" + numStr + "-01";

		return newGrNumber;
	}

	void FormGroups::loadFakultets()
	{
		comboBoxFakultetEdit->Items->Clear();
		comboBoxFakultet->Items->Clear();

		if (listFakultets)
			delete listFakultets;

		listFakultets = mysql->getFakultets();
		int i = 0;
		for (vector<FakultetModel>::iterator iter = listFakultets->begin(); iter != listFakultets->end(); iter++)
		{
			comboBoxFakultet->Items->Add(gcnew String((*iter).name.c_str()));
			comboBoxFakultetEdit->Items->Add(gcnew String((*iter).name.c_str()));
		}
	}

	void FormGroups::loadKafedras()
	{
		if (listKafedras)
			delete listKafedras;

		listKafedras = mysql->getKafedras();
		int i = 0;
	}

	void FormGroups::loadNapravlenie()
	{
		if (listNapravlenie)
			delete listNapravlenie;

		listNapravlenie = mysql->getNapravlenies();
	}

	void FormGroups::loadGroups()
	{
		comboBoxIds->Items->Clear();

		if (listGroups)
			delete listGroups;

		listGroups = mysql->getGroups();
		dataGridView1->RowCount = listGroups->size();

		int i = 0;
		for (vector<GroupModel>::iterator iter = listGroups->begin(); iter != listGroups->end(); iter++)
		{
			comboBoxIds->Items->Add((*iter).id.ToString());

			dataGridView1->Rows[i]->Cells[0]->Value = (*iter).id;
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String((*iter).name.c_str());
			dataGridView1->Rows[i]->Cells[2]->Value = gcnew String((*iter).fakultetName.c_str());
			dataGridView1->Rows[i]->Cells[3]->Value = gcnew String((*iter).kafedraName.c_str());
			dataGridView1->Rows[i]->Cells[4]->Value = gcnew String((*iter).napravlenieName.c_str());

			i++;
		}

		comboBoxIds->SelectedIndex = -1;
	}

	System::Void FormGroups::buttonAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxName->Text == "")
		{
			MessageBox::Show("Введите название");
			return;
		}

		if (comboBoxFakultet->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете факультет");
			return;
		}

		if (comboBoxKafedra->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете кафедру");
			return;
		}

		if (comboBoxNapravlenie->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете направление");
			return;
		}

		GroupModel group;
		group.name = msclr::interop::marshal_as<std::string>(textBoxName->Text);
		group.fakultetId = listFakultets->at(comboBoxFakultet->SelectedIndex).id;
		group.kafedraId = listKafedras->at(comboBoxKafedra->SelectedIndex).id;
		group.napravlenieId = listNapravlenie->at(comboBoxNapravlenie->SelectedIndex).id;
		mysql->addGroups(&group);

		textBoxName->Text = getGroupName();

		MessageBox::Show("Группа добавлена");

		loadGroups();
	}

	System::Void FormGroups::buttonEdit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxNameEdit->Text == "")
		{
			MessageBox::Show("Введите название");
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

		if (comboBoxNapravlenieEdit->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете направление");
			return;
		}

		GroupModel group;
		group.id = Int32::Parse(comboBoxIds->Text);
		group.name = msclr::interop::marshal_as<std::string>(textBoxNameEdit->Text);
		group.fakultetId = listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id;
		group.kafedraId = listKafedrasEdit->at(comboBoxKafedraEdit->SelectedIndex).id;
		group.napravlenieId = listNapravlenieEdit->at(comboBoxNapravlenieEdit->SelectedIndex).id;
		mysql->updateGroups(&group);

		textBoxNameEdit->Text = "";

		MessageBox::Show("Группа изменена");

		loadGroups();
	}

	System::Void FormGroups::buttonDelete_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBoxIds->SelectedIndex == -1)
		{
			MessageBox::Show("Выберете id");
			return;
		}

		int id = Int32::Parse(comboBoxIds->Text);
		mysql->deleteGroups(id);

		comboBoxIds->SelectedIndex = -1;
		comboBoxFakultetEdit->SelectedIndex = -1;
		comboBoxKafedraEdit->SelectedIndex = -1;
		textBoxNameEdit->Text = "";

		MessageBox::Show("Группа удалена");

		loadGroups();
	}

	System::Void FormGroups::comboBoxFakultet_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listKafedras = mysql->getKafedras(listFakultets->at(comboBoxFakultet->SelectedIndex).id);
		comboBoxKafedra->Items->Clear();
		for (int i = 0; i < listKafedras->size(); i++)
			comboBoxKafedra->Items->Add(gcnew String(listKafedras->at(i).name.c_str()));

		comboBoxKafedra->SelectedIndex = -1;
		comboBoxKafedra->Text = "";
	}

	System::Void FormGroups::comboBoxKafedra_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listNapravlenie = mysql->getNapravlenies(listKafedras->at(comboBoxKafedra->SelectedIndex).id);
		comboBoxNapravlenie->Items->Clear();
		for (int i = 0; i < listNapravlenie->size(); i++)
			comboBoxNapravlenie->Items->Add(gcnew String(listNapravlenie->at(i).name.c_str()));

		comboBoxNapravlenie->SelectedIndex = -1;
		comboBoxNapravlenie->Text = "";
	}

	System::Void FormGroups::comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBoxIds->SelectedIndex != -1 && dataGridView1->RowCount > comboBoxIds->SelectedIndex)
		{
			textBoxNameEdit->Text = dataGridView1->Rows[comboBoxIds->SelectedIndex]->Cells[1]->Value->ToString();
			for (int i = 0; i < listFakultets->size(); i++)
			{
				if (listGroups->at(comboBoxIds->SelectedIndex).fakultetId == listFakultets->at(i).id)
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
				if (listGroups->at(comboBoxIds->SelectedIndex).kafedraId == listKafedrasEdit->at(i).id)
				{
					comboBoxKafedraEdit->SelectedIndex = i;
					break;
				}
			}

			//направление
			listNapravlenieEdit = mysql->getNapravlenies(listKafedrasEdit->at(comboBoxKafedraEdit->SelectedIndex).id);
			comboBoxNapravlenieEdit->Items->Clear();
			for (int i = 0; i < listNapravlenieEdit->size(); i++)
				comboBoxNapravlenieEdit->Items->Add(gcnew String(listNapravlenieEdit->at(i).name.c_str()));

			comboBoxNapravlenieEdit->SelectedIndex = -1;
			comboBoxNapravlenieEdit->Text = "";
			for (int i = 0; i < listNapravlenieEdit->size(); i++)
			{
				if (listGroups->at(comboBoxIds->SelectedIndex).napravlenieId == listNapravlenieEdit->at(i).id)
				{
					comboBoxNapravlenieEdit->SelectedIndex = i;
					break;
				}
			}
		}
	}

	System::Void FormGroups::comboBoxFakultetEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listKafedrasEdit = mysql->getKafedras(listFakultets->at(comboBoxFakultetEdit->SelectedIndex).id);
		comboBoxKafedraEdit->Items->Clear();
		for (int i = 0; i < listKafedrasEdit->size(); i++)
			comboBoxKafedraEdit->Items->Add(gcnew String(listKafedrasEdit->at(i).name.c_str()));

		comboBoxKafedraEdit->SelectedIndex = -1;
		comboBoxKafedraEdit->Text = "";
	}

	System::Void FormGroups::comboBoxKafedraEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		listNapravlenieEdit = mysql->getNapravlenies(listKafedrasEdit->at(comboBoxKafedraEdit->SelectedIndex).id);
		comboBoxNapravlenieEdit->Items->Clear();
		for (int i = 0; i < listNapravlenieEdit->size(); i++)
			comboBoxNapravlenieEdit->Items->Add(gcnew String(listNapravlenieEdit->at(i).name.c_str()));

		comboBoxNapravlenieEdit->SelectedIndex = -1;
		comboBoxNapravlenieEdit->Text = "";
	}
}
