#pragma once
#include "MySQL.h"
#include <vector>

using namespace std;

namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Form1;

	/// <summary>
	/// Сводка для FormNapravlenie
	/// </summary>
	public ref class FormNapravlenie : public System::Windows::Forms::Form
	{
	public:
		FormNapravlenie(Form1 ^mainForm, MySQL *mysql);
	private:
		Form1 ^mainForm;
		MySQL *mysql;
		vector<FakultetModel> *listFakultets;
		vector<KafedraModel> *listKafedras;
		vector<KafedraModel> *listKafedrasEdit;
		vector<NapravlenieModel> *listNapravlenie;

		void loadFakultets();
		//void loadKafedras();
		void loadNapravlenie();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormNapravlenie()
		{
			if (listFakultets)
				delete listFakultets;
			if (listKafedras)
				delete listKafedras;
			if (listKafedrasEdit)
				delete listKafedrasEdit;
			if (listNapravlenie)
				delete listNapravlenie;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBoxKafedraEdit;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetEdit;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBoxKafedras;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultets;
	private: System::Windows::Forms::Button^  buttonDelete;


	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::TextBox^  textBoxEdit;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxIds;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Button^  buttonAdd;

	private: System::Windows::Forms::TextBox^  textBoxNameAdd;

	private: System::Windows::Forms::Label^  label1;

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
			this->comboBoxKafedraEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetEdit = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedras = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultets = (gcnew System::Windows::Forms::ComboBox());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->textBoxEdit = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxIds = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->textBoxNameAdd = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBoxKafedraEdit
			// 
			this->comboBoxKafedraEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxKafedraEdit->FormattingEnabled = true;
			this->comboBoxKafedraEdit->Location = System::Drawing::Point(84, 409);
			this->comboBoxKafedraEdit->Name = L"comboBoxKafedraEdit";
			this->comboBoxKafedraEdit->Size = System::Drawing::Size(115, 21);
			this->comboBoxKafedraEdit->TabIndex = 51;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(16, 412);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 13);
			this->label8->TabIndex = 50;
			this->label8->Text = L"Кафедра";
			// 
			// comboBoxFakultetEdit
			// 
			this->comboBoxFakultetEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxFakultetEdit->FormattingEnabled = true;
			this->comboBoxFakultetEdit->Location = System::Drawing::Point(84, 382);
			this->comboBoxFakultetEdit->Name = L"comboBoxFakultetEdit";
			this->comboBoxFakultetEdit->Size = System::Drawing::Size(115, 21);
			this->comboBoxFakultetEdit->TabIndex = 49;
			this->comboBoxFakultetEdit->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNapravlenie::comboBoxFakultetEdit_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 385);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 13);
			this->label7->TabIndex = 48;
			this->label7->Text = L"Факультет";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 45;
			this->label5->Text = L"Направление";
			// 
			// comboBoxKafedras
			// 
			this->comboBoxKafedras->FormattingEnabled = true;
			this->comboBoxKafedras->Location = System::Drawing::Point(121, 38);
			this->comboBoxKafedras->Name = L"comboBoxKafedras";
			this->comboBoxKafedras->Size = System::Drawing::Size(163, 21);
			this->comboBoxKafedras->TabIndex = 44;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 43;
			this->label4->Text = L"Кафедра";
			// 
			// comboBoxFakultets
			// 
			this->comboBoxFakultets->FormattingEnabled = true;
			this->comboBoxFakultets->Location = System::Drawing::Point(121, 11);
			this->comboBoxFakultets->Name = L"comboBoxFakultets";
			this->comboBoxFakultets->Size = System::Drawing::Size(163, 21);
			this->comboBoxFakultets->TabIndex = 42;
			this->comboBoxFakultets->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNapravlenie::comboBoxFakultets_SelectedIndexChanged);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonDelete->Location = System::Drawing::Point(330, 463);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 41;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &FormNapravlenie::buttonDelete_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(330, 434);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 40;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &FormNapravlenie::buttonEdit_Click);
			// 
			// textBoxEdit
			// 
			this->textBoxEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxEdit->Location = System::Drawing::Point(85, 436);
			this->textBoxEdit->Name = L"textBoxEdit";
			this->textBoxEdit->Size = System::Drawing::Size(223, 20);
			this->textBoxEdit->TabIndex = 39;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 436);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 38;
			this->label3->Text = L"Название";
			// 
			// comboBoxIds
			// 
			this->comboBoxIds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxIds->FormattingEnabled = true;
			this->comboBoxIds->Location = System::Drawing::Point(85, 355);
			this->comboBoxIds->Name = L"comboBoxIds";
			this->comboBoxIds->Size = System::Drawing::Size(81, 21);
			this->comboBoxIds->TabIndex = 37;
			this->comboBoxIds->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNapravlenie::comboBoxIds_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 358);
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 91);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(451, 258);
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
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(388, 62);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 34;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &FormNapravlenie::buttonAdd_Click);
			// 
			// textBoxNameAdd
			// 
			this->textBoxNameAdd->Location = System::Drawing::Point(121, 65);
			this->textBoxNameAdd->Name = L"textBoxNameAdd";
			this->textBoxNameAdd->Size = System::Drawing::Size(244, 20);
			this->textBoxNameAdd->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Факультет";
			// 
			// FormNapravlenie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 495);
			this->Controls->Add(this->comboBoxKafedraEdit);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBoxFakultetEdit);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxKafedras);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxFakultets);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->textBoxEdit);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBoxIds);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxNameAdd);
			this->Controls->Add(this->label1);
			this->Name = L"FormNapravlenie";
			this->Text = L"Направление";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxFakultetEdit_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBoxFakultets_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}
