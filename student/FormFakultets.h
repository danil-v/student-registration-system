#pragma once
#include "MySQL.h"

#include <msclr\marshal_cppstd.h>

namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Form1;

	/// <summary>
	/// Сводка для FormFakultets
	/// </summary>
	public ref class FormFakultets : public System::Windows::Forms::Form
	{
	private:
		MySQL *mysql;
		Form1 ^formMain;

	public:
		FormFakultets(Form1 ^formMain, MySQL *mysql);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormFakultets()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxNameAdd;

	private: System::Windows::Forms::Button^  buttonAdd;
	protected:


	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBoxIds;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxNameEdit;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Button^  buttonDelete;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxNameAdd = (gcnew System::Windows::Forms::TextBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxIds = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxNameEdit = (gcnew System::Windows::Forms::TextBox());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Факультет";
			// 
			// textBoxNameAdd
			// 
			this->textBoxNameAdd->Location = System::Drawing::Point(81, 13);
			this->textBoxNameAdd->Name = L"textBoxNameAdd";
			this->textBoxNameAdd->Size = System::Drawing::Size(244, 20);
			this->textBoxNameAdd->TabIndex = 1;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(343, 13);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &FormFakultets::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 52);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(434, 234);
			this->dataGridView1->TabIndex = 3;
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
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 311);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"ID";
			// 
			// comboBoxIds
			// 
			this->comboBoxIds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxIds->FormattingEnabled = true;
			this->comboBoxIds->Location = System::Drawing::Point(81, 308);
			this->comboBoxIds->Name = L"comboBoxIds";
			this->comboBoxIds->Size = System::Drawing::Size(117, 21);
			this->comboBoxIds->TabIndex = 5;
			this->comboBoxIds->SelectedIndexChanged += gcnew System::EventHandler(this, &FormFakultets::comboBoxIds_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 343);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Название";
			// 
			// textBoxNameEdit
			// 
			this->textBoxNameEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBoxNameEdit->Location = System::Drawing::Point(81, 340);
			this->textBoxNameEdit->Name = L"textBoxNameEdit";
			this->textBoxNameEdit->Size = System::Drawing::Size(236, 20);
			this->textBoxNameEdit->TabIndex = 7;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEdit->Location = System::Drawing::Point(334, 337);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 23);
			this->buttonEdit->TabIndex = 8;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &FormFakultets::buttonEdit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonDelete->Location = System::Drawing::Point(334, 366);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 9;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &FormFakultets::buttonDelete_Click);
			// 
			// FormFakultets
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 413);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->textBoxNameEdit);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBoxIds);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxNameAdd);
			this->Controls->Add(this->label1);
			this->Name = L"FormFakultets";
			this->Text = L"Факультеты";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormFakultets::FormFakultets_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxNameAdd->Text == "")
		{
			MessageBox::Show("Введите название");			
			return;
		}

		FakultetModel fakultet;
		fakultet.name = msclr::interop::marshal_as<std::string>(textBoxNameAdd->Text);
		mysql->addFakultet(&fakultet);
		textBoxNameAdd->Text = "";

		MessageBox::Show("Факультет добавлен");

		loadFakultets();
	}

	void loadFakultets();

private: System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBoxNameEdit->Text == "")
	{
		MessageBox::Show("Введите название");
		return;
	}

	if (comboBoxIds->Text == "")
	{
		MessageBox::Show("Выберете id");		
		return;
	}

	FakultetModel fakultet;
	fakultet.id = Int32::Parse(comboBoxIds->Text);
	fakultet.name = msclr::interop::marshal_as<std::string>(textBoxNameEdit->Text);  
	mysql->updateFakultet(&fakultet);

	comboBoxIds->SelectedIndex = -1;
	textBoxNameEdit->Text = "";

	MessageBox::Show("Факультет изменен");

	loadFakultets();
}
private: System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBoxIds->Text == "")
	{
		MessageBox::Show("Выберете id");
		return;
	}

	int id = Int32::Parse(comboBoxIds->Text);
	mysql->deleteFakultet(id);

	comboBoxIds->SelectedIndex = -1;
	textBoxNameEdit->Text = "";

	MessageBox::Show("Факультет удален");

	loadFakultets();
}
private: System::Void comboBoxIds_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (comboBoxIds->SelectedIndex != -1 && dataGridView1->RowCount > comboBoxIds->SelectedIndex)
	{
		textBoxNameEdit->Text = dataGridView1->Rows[comboBoxIds->SelectedIndex]->Cells[1]->Value->ToString();
			
	}
}

private: System::Void FormFakultets_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
};
}
