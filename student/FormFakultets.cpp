#include "stdafx.h"
#include "FormFakultets.h"

#include "FormMain.h"

namespace Student {

	FormFakultets::FormFakultets(Form1 ^formMain, MySQL *mysql)
	{
		this->mysql = mysql;
		this->formMain = formMain;

		if (formMain->access == 0)
		{
			buttonAdd->Enabled = false;
			buttonEdit->Enabled = false;
			buttonDelete->Enabled = false;
		}

		InitializeComponent();

		loadFakultets();
	}

	void FormFakultets::loadFakultets()
	{
		comboBoxIds->Items->Clear();


		vector<FakultetModel> *list = mysql->getFakultets();
		dataGridView1->RowCount = list->size();
		int i = 0;
		for (vector<FakultetModel>::iterator iter = list->begin(); iter != list->end(); iter++)
		{
			comboBoxIds->Items->Add((*iter).id.ToString());

			dataGridView1->Rows[i]->Cells[0]->Value = (*iter).id.ToString();
			dataGridView1->Rows[i]->Cells[1]->Value = gcnew String((*iter).name.c_str());

			i++;
		}

		comboBoxIds->SelectedIndex = -1;

		formMain->loadFakultets();

		delete list;
	}

	System::Void FormFakultets::FormFakultets_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		formMain->loadFakultets();
	}
}