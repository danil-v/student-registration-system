#pragma once
#include "Structs.h"
#include <vector>


namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Form1;
	class MySQL;
	/// <summary>
	/// Сводка для FormKafedra
	/// </summary>
	public ref class FormKafedra : public System::Windows::Forms::Form
	{
	public:
		FormKafedra(Form1 ^form, MySQL *mysql);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormKafedra()
		{
			if (listFakultets)
				delete listFakultets;
			if (listKafedras)
				delete listKafedras;

			if (components)
			{
				delete components;
			}
		}

	private:
		Form1 ^form;
		MySQL *mysql;
		std::vector<FakultetModel> *listFakultets;
		std::vector<KafedraModel> *listKafedras;

		void loadKafedras();
		void loadFakultets();

	protected:
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetEdit;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetAdd;
	private: System::Windows::Forms::Button^  buttonEdit;


	private: System::Windows::Forms::ComboBox^  comboBoxIds;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  buttonAdd;



	private: System::Windows::Forms::TextBox^  textBoxKafedraAdd;

	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::TextBox^  textBoxKafedraEdit;
	private: System::Windows::Forms::Button^  buttonDelete;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetAdd = (gcnew System::Windows::Forms::ComboBox());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->comboBoxIds = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->textBoxKafedraAdd = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxKafedraEdit = (gcnew System::Windows::Forms::TextBox());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 441);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 13);
			this->label9->TabIndex = 49;
			this->label9->Text = L"Название";
			// 
			// comboBoxFakultetEdit
			// 
			this->comboBoxFakultetEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxFakultetEdit->FormattingEnabled = true;
			this->comboBoxFakultetEdit->Location = System::Drawing::Point(92, 411);
			this->comboBoxFakultetEdit->Name = L"comboBoxFakultetEdit";
			this->comboBoxFakultetEdit->Size = System::Drawing::Size(115, 21);
			this->comboBoxFakultetEdit->TabIndex = 46;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(24, 414);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 45;
			this->label7->Text = L"Факультет";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 13);
			this->label6->TabIndex = 44;
			this->label6->Text = L"Кафедра";
			// 
			// comboBoxFakultetAdd
			// 
			this->comboBoxFakultetAdd->FormattingEnabled = true;
			this->comboBoxFakultetAdd->Location = System::Drawing::Point(117, 6);
			this->comboBoxFakultetAdd->Name = L"comboBoxFakultetAdd";
			this->comboBoxFakultetAdd->Size = System::Drawing::Size(163, 21);
			this->comboBoxFakultetAdd->TabIndex = 39;
			this->comboBoxFakultetAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &FormKafedra::comboBoxFakultetAdd_SelectedIndexChanged);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(357, 409);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 38;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &FormKafedra::buttonEdit_Click);
			// 
			// comboBoxIds
			// 
			this->comboBoxIds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxIds->FormattingEnabled = true;
			this->comboBoxIds->Location = System::Drawing::Point(92, 384);
			this->comboBoxIds->Name = L"comboBoxIds";
			this->comboBoxIds->Size = System::Drawing::Size(81, 21);
			this->comboBoxIds->TabIndex = 37;
			this->comboBoxIds->SelectedIndexChanged += gcnew System::EventHandler(this, &FormKafedra::comboBoxIds_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 387);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 36;
			this->label2->Text = L"ID";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(8, 79);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(459, 287);
			this->dataGridView1->TabIndex = 35;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Название";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 200;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Факультет";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(378, 35);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 34;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &FormKafedra::button1_Click);
			// 
			// textBoxKafedraAdd
			// 
			this->textBoxKafedraAdd->Location = System::Drawing::Point(116, 38);
			this->textBoxKafedraAdd->Name = L"textBoxKafedraAdd";
			this->textBoxKafedraAdd->Size = System::Drawing::Size(244, 20);
			this->textBoxKafedraAdd->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Факультет";
			// 
			// textBoxKafedraEdit
			// 
			this->textBoxKafedraEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxKafedraEdit->Location = System::Drawing::Point(92, 438);
			this->textBoxKafedraEdit->Name = L"textBoxKafedraEdit";
			this->textBoxKafedraEdit->Size = System::Drawing::Size(223, 20);
			this->textBoxKafedraEdit->TabIndex = 50;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonDelete->Location = System::Drawing::Point(357, 436);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 51;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &FormKafedra::buttonDelete_Click);
			// 
			// FormKafedra
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(479, 490);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->textBoxKafedraEdit);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBoxFakultetEdit);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBoxFakultetAdd);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->comboBoxIds);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxKafedraAdd);
			this->Controls->Add(this->label1);
			this->Name = L"FormKafedra";
			this->Text = L"Кафедра";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormKafedra::FormKafedra_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void comboBoxFakultetAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: 
	System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (comboBoxIds->SelectedIndex != -1 && dataGridView1->RowCount > comboBoxIds->SelectedIndex)
	{
		textBoxKafedraEdit->Text = dataGridView1->Rows[comboBoxIds->SelectedIndex]->Cells[1]->Value->ToString();
		for (int i = 0; i < listFakultets->size(); i++)
		{
			if (listKafedras->at(comboBoxIds->SelectedIndex).fakultetId == listFakultets->at(i).id)
			{
				comboBoxFakultetEdit->SelectedIndex = i;
				break;
			}
		}
	}
}
private: System::Void FormKafedra_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}
