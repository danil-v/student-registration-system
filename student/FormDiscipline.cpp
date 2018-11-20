#include "stdafx.h"
#include "FormDiscipline.h"
#include "FormMain.h"

namespace Student
{
	void FormDiscipline::load()
	{
		if (predmets)
			delete predmets;

		predmets = mysql->getPredmetsTeacher(semestr, specialId);
		dataGridView1->RowCount = predmets->size();

		for (int i = 0; i < predmets->size(); i++)
		{
			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(predmets->at(i).name.c_str());
			dataGridView1->Rows[i]->Cells[1]->Value = predmets->at(i).hours.ToString();
			dataGridView1->Rows[i]->Cells[2]->Value = predmets->at(i).hoursLec.ToString();
			dataGridView1->Rows[i]->Cells[3]->Value = predmets->at(i).hoursPract.ToString();
			if (predmets->at(i).semestr % 2 == 0)
			{
				dataGridView1->Rows[i]->Cells[4]->Value = (predmets->at(i).semestr / 2 - 1).ToString();
				dataGridView1->Rows[i]->Cells[5]->Value = "2";
			}
			else
			{
				dataGridView1->Rows[i]->Cells[4]->Value = (predmets->at(i).semestr / 2).ToString();
				dataGridView1->Rows[i]->Cells[5]->Value = "1";
			}
			dataGridView1->Rows[i]->Cells[6]->Value = gcnew String(predmets->at(i).teacher.c_str());
			dataGridView1->Rows[i]->Cells[7]->Value = predmets->at(i).zachet ? "Есть" : "Нет";
			dataGridView1->Rows[i]->Cells[8]->Value = predmets->at(i).exam ? "Есть" : "Нет";
			dataGridView1->Rows[i]->Cells[9]->Value = predmets->at(i).kursov ? "Есть" : "Нет";

			dataGridView1->Rows[i]->Cells[10]->Value = "Удалить предмет из плана";
			dataGridView1->Rows[i]->Cells[11]->Value = "Удалить предмет";
		}
	}


	System::Void FormDiscipline::dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (form->access == 0)
			return;
		
		if (e->ColumnIndex == 10)
		{
			mysql->deletePredmetPlan(predmets->at(e->RowIndex).id);
		}
		else if (e->ColumnIndex == 11)
		{
			mysql->deletePredmet(predmets->at(e->RowIndex).predmetId);
		}

		load();
	}
}