#pragma once
#include "MySQL.h"

namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Form1;
	/// <summary>
	/// Сводка для FormGroups
	/// </summary>
	public ref class FormGroups : public System::Windows::Forms::Form
	{
	public:
		FormGroups(Form1 ^mainForm, MySQL* mysql);
	private:
		Form1 ^mainForm;
		MySQL* mysql;
		vector<FakultetModel> *listFakultets;
		vector<KafedraModel> *listKafedras;
		vector<KafedraModel> *listKafedrasEdit;
		vector<NapravlenieModel> *listNapravlenie;
		vector<NapravlenieModel> *listNapravlenieEdit;

		String ^getGroupName();
	private: System::Windows::Forms::MaskedTextBox^  textBoxName;

			 vector<GroupModel> *listGroups;

		void loadFakultets();
		void loadKafedras();
		void loadNapravlenie();
		void loadGroups();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormGroups()
		{
			if (listFakultets)
				delete listFakultets;
			if (listKafedras)
				delete listKafedras;
			if (listKafedrasEdit)
				delete listKafedrasEdit;
			if (listNapravlenie)
				delete listNapravlenie;
			if (listNapravlenieEdit)
				delete listNapravlenieEdit;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonDelete;
	private: System::Windows::Forms::Button^  buttonEdit;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  textBoxNameEdit;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxIds;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::Button^  buttonAdd;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultet;
	private: System::Windows::Forms::ComboBox^  comboBoxKafedra;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBoxNapravlenie;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetEdit;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBoxKafedraEdit;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBoxNapravlenieEdit;

	private: System::Windows::Forms::Label^  label9;

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
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->textBoxNameEdit = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxIds = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultet = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxKafedra = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravlenie = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedraEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravlenieEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::MaskedTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonDelete->Location = System::Drawing::Point(353, 496);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 19;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &FormGroups::buttonDelete_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(353, 467);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 18;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &FormGroups::buttonEdit_Click);
			// 
			// textBoxNameEdit
			// 
			this->textBoxNameEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxNameEdit->Location = System::Drawing::Point(98, 496);
			this->textBoxNameEdit->Name = L"textBoxNameEdit";
			this->textBoxNameEdit->Size = System::Drawing::Size(223, 20);
			this->textBoxNameEdit->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 499);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Название";
			// 
			// comboBoxIds
			// 
			this->comboBoxIds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxIds->FormattingEnabled = true;
			this->comboBoxIds->Location = System::Drawing::Point(85, 437);
			this->comboBoxIds->Name = L"comboBoxIds";
			this->comboBoxIds->Size = System::Drawing::Size(81, 21);
			this->comboBoxIds->TabIndex = 15;
			this->comboBoxIds->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGroups::comboBoxIds_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 440);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 14;
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 139);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(572, 283);
			this->dataGridView1->TabIndex = 13;
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
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Факультет";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Кафедра";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Направление";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(383, 96);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 12;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &FormGroups::buttonAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Факультет";
			// 
			// comboBoxFakultet
			// 
			this->comboBoxFakultet->FormattingEnabled = true;
			this->comboBoxFakultet->Location = System::Drawing::Point(121, 18);
			this->comboBoxFakultet->Name = L"comboBoxFakultet";
			this->comboBoxFakultet->Size = System::Drawing::Size(163, 21);
			this->comboBoxFakultet->TabIndex = 20;
			this->comboBoxFakultet->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGroups::comboBoxFakultet_SelectedIndexChanged);
			// 
			// comboBoxKafedra
			// 
			this->comboBoxKafedra->FormattingEnabled = true;
			this->comboBoxKafedra->Location = System::Drawing::Point(121, 45);
			this->comboBoxKafedra->Name = L"comboBoxKafedra";
			this->comboBoxKafedra->Size = System::Drawing::Size(163, 21);
			this->comboBoxKafedra->TabIndex = 22;
			this->comboBoxKafedra->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGroups::comboBoxKafedra_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Кафедра";
			// 
			// comboBoxNapravlenie
			// 
			this->comboBoxNapravlenie->FormattingEnabled = true;
			this->comboBoxNapravlenie->Location = System::Drawing::Point(121, 72);
			this->comboBoxNapravlenie->Name = L"comboBoxNapravlenie";
			this->comboBoxNapravlenie->Size = System::Drawing::Size(163, 21);
			this->comboBoxNapravlenie->TabIndex = 24;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Направление";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(22, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(96, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Название группы";
			// 
			// comboBoxFakultetEdit
			// 
			this->comboBoxFakultetEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxFakultetEdit->FormattingEnabled = true;
			this->comboBoxFakultetEdit->Location = System::Drawing::Point(264, 437);
			this->comboBoxFakultetEdit->Name = L"comboBoxFakultetEdit";
			this->comboBoxFakultetEdit->Size = System::Drawing::Size(115, 21);
			this->comboBoxFakultetEdit->TabIndex = 27;
			this->comboBoxFakultetEdit->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGroups::comboBoxFakultetEdit_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(196, 440);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Факультет";
			// 
			// comboBoxKafedraEdit
			// 
			this->comboBoxKafedraEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxKafedraEdit->FormattingEnabled = true;
			this->comboBoxKafedraEdit->Location = System::Drawing::Point(469, 437);
			this->comboBoxKafedraEdit->Name = L"comboBoxKafedraEdit";
			this->comboBoxKafedraEdit->Size = System::Drawing::Size(115, 21);
			this->comboBoxKafedraEdit->TabIndex = 29;
			this->comboBoxKafedraEdit->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGroups::comboBoxKafedraEdit_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(401, 440);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Кафедра";
			// 
			// comboBoxNapravlenieEdit
			// 
			this->comboBoxNapravlenieEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxNapravlenieEdit->FormattingEnabled = true;
			this->comboBoxNapravlenieEdit->Location = System::Drawing::Point(98, 466);
			this->comboBoxNapravlenieEdit->Name = L"comboBoxNapravlenieEdit";
			this->comboBoxNapravlenieEdit->Size = System::Drawing::Size(102, 21);
			this->comboBoxNapravlenieEdit->TabIndex = 31;
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 469);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(75, 13);
			this->label9->TabIndex = 30;
			this->label9->Text = L"Направление";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(188, 102);
			this->textBoxName->Mask = L"L00-000-00";
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(96, 20);
			this->textBoxName->TabIndex = 32;
			this->textBoxName->Text = L"Б1600101";
			// 
			// FormGroups
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 528);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->comboBoxNapravlenieEdit);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBoxKafedraEdit);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBoxFakultetEdit);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBoxNapravlenie);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxKafedra);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxFakultet);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->textBoxNameEdit);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBoxIds);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->label1);
			this->Name = L"FormGroups";
			this->Text = L"Группы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxFakultet_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxKafedra_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxFakultetEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxKafedraEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

};
}
