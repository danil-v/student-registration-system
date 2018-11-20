#pragma once
#include "StudentModel.h"
#include <vector>
#include "Structs.h"



namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	ref class Form1;
	class MySQL;

	/// <summary>
	/// Сводка для FormStudent
	/// </summary>
	public ref class FormStudent : public System::Windows::Forms::Form
	{
	public:
		FormStudent(Form1 ^formMain, StudentModel *student, MySQL *mysql);

	private:
		Form1 ^formMain;
		StudentModel *student;
		MySQL *mysql;
		vector<FakultetModel> *fakultets;
		vector<KafedraModel> *kafedras;
		vector<NapravlenieModel> *napravlenies;
		vector<GroupModel> *groups;
		vector<PredmetsWithMarks> *marks;

		vector<Work> *dostigenia;
		vector<Work> *poruchenia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewButtonColumn1;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewButtonColumn2;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewButtonColumn3;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewButtonColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;




			 vector<Work> *dolgi;

		void loadDostig();
		void loadPoruch();
		void loadDolgi();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormStudent()
		{
			if (fakultets)
				delete fakultets;
			if (kafedras)
				delete kafedras;
			if (napravlenies)
				delete napravlenies;
			if (groups)
				delete groups;
			if (marks)
				delete marks;

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::RadioButton^  radioButtonMilitary;
	private: System::Windows::Forms::RadioButton^  radioButtonMilitaryNo;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  radioButtonNeedHostel;
	private: System::Windows::Forms::RadioButton^  radioButtonNeedHostelNo;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  radioButtonChildren;
	private: System::Windows::Forms::RadioButton^  radioButtonChildrenNo;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButtonPay;
	private: System::Windows::Forms::RadioButton^  radioButtonPayNo;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerStudyEnd;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerStudyStart;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBoxArt;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBoxOlymp;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::TextBox^  textBoxSport;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBoxNational;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::TextBox^  textBoxFamily;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::TextBox^  textBoxPrevStudy;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;

			 			


	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::NumericUpDown^  numericUpDownKurs;

	private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::ComboBox^  comboBoxGroup;

	private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::ComboBox^  comboBoxSpecial;

	private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::ComboBox^  comboBoxKafedra;

	private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::ComboBox^  comboBoxFakultet;

	private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::ComboBox^  comboBoxStudyForm;

	private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TextBox^  textBoxAdres;

	private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::TextBox^  textBoxEmail;

	private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TextBox^  textBoxMobile;

	private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirth;

	private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::RadioButton^  radioButtonFemale;

private: System::Windows::Forms::RadioButton^  radioButtonMale;

	private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  textBoxNumber;

	private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::TextBox^  textBoxMiddleName;

	private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::TextBox^  textBoxName;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxSurname;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::ComboBox^  comboBoxMarksSemestr;

	private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::ComboBox^  comboBoxMarksKurs;

	private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Button^  buttonMarksShow;
private: System::Windows::Forms::DataGridView^  dataGridViewMarks;







private: System::Windows::Forms::Button^  buttonSave;
private: System::Windows::Forms::Button^  buttonAddAchiev;
private: System::Windows::Forms::DataGridView^  dataGridViewAchiev;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewTextBoxColumn3;
private: System::Windows::Forms::TextBox^  textBoxAchiev;

	private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Button^  buttonPoruchAdd;
private: System::Windows::Forms::DataGridView^  dataGridViewPoruch;







private: System::Windows::Forms::TextBox^  textBoxPoruch;

	private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Button^  buttonDolgiAdd;
private: System::Windows::Forms::DataGridView^  dataGridViewDolgi;





private: System::Windows::Forms::TextBox^  textBoxDolgi;

	private: System::Windows::Forms::Label^  label5;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonMilitary = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMilitaryNo = (gcnew System::Windows::Forms::RadioButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonNeedHostel = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNeedHostelNo = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonChildren = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonChildrenNo = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonPay = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPayNo = (gcnew System::Windows::Forms::RadioButton());
			this->dateTimePickerStudyEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePickerStudyStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxArt = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBoxOlymp = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->textBoxSport = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBoxNational = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->textBoxFamily = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrevStudy = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownKurs = (gcnew System::Windows::Forms::NumericUpDown());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSpecial = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedra = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultet = (gcnew System::Windows::Forms::ComboBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->comboBoxStudyForm = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBoxAdres = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBoxMobile = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->radioButtonFemale = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMale = (gcnew System::Windows::Forms::RadioButton());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumber = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBoxMiddleName = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->dataGridViewMarks = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonMarksShow = (gcnew System::Windows::Forms::Button());
			this->comboBoxMarksSemestr = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxMarksKurs = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->buttonAddAchiev = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAchiev = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBoxAchiev = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->buttonPoruchAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridViewPoruch = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBoxPoruch = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->buttonDolgiAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridViewDolgi = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBoxDolgi = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKurs))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMarks))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAchiev))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPoruch))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDolgi))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(774, 518);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->panel4);
			this->tabPage1->Controls->Add(this->panel3);
			this->tabPage1->Controls->Add(this->panel2);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->dateTimePickerStudyEnd);
			this->tabPage1->Controls->Add(this->dateTimePickerStudyStart);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label23);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->label27);
			this->tabPage1->Controls->Add(this->textBoxNational);
			this->tabPage1->Controls->Add(this->label28);
			this->tabPage1->Controls->Add(this->label29);
			this->tabPage1->Controls->Add(this->label30);
			this->tabPage1->Controls->Add(this->textBoxFamily);
			this->tabPage1->Controls->Add(this->label31);
			this->tabPage1->Controls->Add(this->textBoxPrevStudy);
			this->tabPage1->Controls->Add(this->label32);
			this->tabPage1->Controls->Add(this->label33);
			this->tabPage1->Controls->Add(this->numericUpDownKurs);
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->comboBoxGroup);
			this->tabPage1->Controls->Add(this->label21);
			this->tabPage1->Controls->Add(this->comboBoxSpecial);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->comboBoxKafedra);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->comboBoxFakultet);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->comboBoxStudyForm);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBoxAdres);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->textBoxEmail);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->textBoxMobile);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->dateTimePickerBirth);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->radioButtonFemale);
			this->tabPage1->Controls->Add(this->radioButtonMale);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->textBoxNumber);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->textBoxMiddleName);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->textBoxName);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->textBoxSurname);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(766, 492);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Общие сведения";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->radioButtonMilitary);
			this->panel4->Controls->Add(this->radioButtonMilitaryNo);
			this->panel4->Location = System::Drawing::Point(512, 185);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(112, 23);
			this->panel4->TabIndex = 82;
			// 
			// radioButtonMilitary
			// 
			this->radioButtonMilitary->AutoSize = true;
			this->radioButtonMilitary->Checked = true;
			this->radioButtonMilitary->Location = System::Drawing::Point(3, 3);
			this->radioButtonMilitary->Name = L"radioButtonMilitary";
			this->radioButtonMilitary->Size = System::Drawing::Size(40, 17);
			this->radioButtonMilitary->TabIndex = 17;
			this->radioButtonMilitary->TabStop = true;
			this->radioButtonMilitary->Text = L"Да";
			this->radioButtonMilitary->UseVisualStyleBackColor = true;
			// 
			// radioButtonMilitaryNo
			// 
			this->radioButtonMilitaryNo->AutoSize = true;
			this->radioButtonMilitaryNo->Location = System::Drawing::Point(53, 3);
			this->radioButtonMilitaryNo->Name = L"radioButtonMilitaryNo";
			this->radioButtonMilitaryNo->Size = System::Drawing::Size(44, 17);
			this->radioButtonMilitaryNo->TabIndex = 18;
			this->radioButtonMilitaryNo->Text = L"Нет";
			this->radioButtonMilitaryNo->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButtonNeedHostel);
			this->panel3->Controls->Add(this->radioButtonNeedHostelNo);
			this->panel3->Location = System::Drawing::Point(510, 122);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(114, 23);
			this->panel3->TabIndex = 81;
			// 
			// radioButtonNeedHostel
			// 
			this->radioButtonNeedHostel->AutoSize = true;
			this->radioButtonNeedHostel->Checked = true;
			this->radioButtonNeedHostel->Location = System::Drawing::Point(3, 3);
			this->radioButtonNeedHostel->Name = L"radioButtonNeedHostel";
			this->radioButtonNeedHostel->Size = System::Drawing::Size(40, 17);
			this->radioButtonNeedHostel->TabIndex = 12;
			this->radioButtonNeedHostel->TabStop = true;
			this->radioButtonNeedHostel->Text = L"Да";
			this->radioButtonNeedHostel->UseVisualStyleBackColor = true;
			// 
			// radioButtonNeedHostelNo
			// 
			this->radioButtonNeedHostelNo->AutoSize = true;
			this->radioButtonNeedHostelNo->Location = System::Drawing::Point(53, 3);
			this->radioButtonNeedHostelNo->Name = L"radioButtonNeedHostelNo";
			this->radioButtonNeedHostelNo->Size = System::Drawing::Size(44, 17);
			this->radioButtonNeedHostelNo->TabIndex = 13;
			this->radioButtonNeedHostelNo->Text = L"Нет";
			this->radioButtonNeedHostelNo->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButtonChildren);
			this->panel2->Controls->Add(this->radioButtonChildrenNo);
			this->panel2->Location = System::Drawing::Point(509, 90);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 23);
			this->panel2->TabIndex = 80;
			// 
			// radioButtonChildren
			// 
			this->radioButtonChildren->AutoSize = true;
			this->radioButtonChildren->Checked = true;
			this->radioButtonChildren->Location = System::Drawing::Point(3, 3);
			this->radioButtonChildren->Name = L"radioButtonChildren";
			this->radioButtonChildren->Size = System::Drawing::Size(40, 17);
			this->radioButtonChildren->TabIndex = 9;
			this->radioButtonChildren->TabStop = true;
			this->radioButtonChildren->Text = L"Да";
			this->radioButtonChildren->UseVisualStyleBackColor = true;
			// 
			// radioButtonChildrenNo
			// 
			this->radioButtonChildrenNo->AutoSize = true;
			this->radioButtonChildrenNo->Location = System::Drawing::Point(53, 3);
			this->radioButtonChildrenNo->Name = L"radioButtonChildrenNo";
			this->radioButtonChildrenNo->Size = System::Drawing::Size(44, 17);
			this->radioButtonChildrenNo->TabIndex = 10;
			this->radioButtonChildrenNo->Text = L"Нет";
			this->radioButtonChildrenNo->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButtonPay);
			this->panel1->Controls->Add(this->radioButtonPayNo);
			this->panel1->Location = System::Drawing::Point(464, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(270, 26);
			this->panel1->TabIndex = 79;
			// 
			// radioButtonPay
			// 
			this->radioButtonPay->AutoSize = true;
			this->radioButtonPay->Checked = true;
			this->radioButtonPay->Location = System::Drawing::Point(3, 3);
			this->radioButtonPay->Name = L"radioButtonPay";
			this->radioButtonPay->Size = System::Drawing::Size(83, 17);
			this->radioButtonPay->TabIndex = 2;
			this->radioButtonPay->TabStop = true;
			this->radioButtonPay->Text = L"Бюджетная";
			this->radioButtonPay->UseVisualStyleBackColor = true;
			// 
			// radioButtonPayNo
			// 
			this->radioButtonPayNo->AutoSize = true;
			this->radioButtonPayNo->Location = System::Drawing::Point(108, 3);
			this->radioButtonPayNo->Name = L"radioButtonPayNo";
			this->radioButtonPayNo->Size = System::Drawing::Size(101, 17);
			this->radioButtonPayNo->TabIndex = 3;
			this->radioButtonPayNo->Text = L"Внебюджетная";
			this->radioButtonPayNo->UseVisualStyleBackColor = true;
			// 
			// dateTimePickerStudyEnd
			// 
			this->dateTimePickerStudyEnd->Location = System::Drawing::Point(534, 456);
			this->dateTimePickerStudyEnd->Name = L"dateTimePickerStudyEnd";
			this->dateTimePickerStudyEnd->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerStudyEnd->TabIndex = 78;
			// 
			// dateTimePickerStudyStart
			// 
			this->dateTimePickerStudyStart->Location = System::Drawing::Point(534, 430);
			this->dateTimePickerStudyStart->Name = L"dateTimePickerStudyStart";
			this->dateTimePickerStudyStart->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerStudyStart->TabIndex = 77;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(366, 460);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(138, 13);
			this->label7->TabIndex = 76;
			this->label7->Text = L"Дата окончания обучения";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(366, 430);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(120, 13);
			this->label23->TabIndex = 75;
			this->label23->Text = L"Дата начала обучения";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxArt);
			this->groupBox1->Controls->Add(this->label24);
			this->groupBox1->Controls->Add(this->textBoxOlymp);
			this->groupBox1->Controls->Add(this->label25);
			this->groupBox1->Controls->Add(this->textBoxSport);
			this->groupBox1->Controls->Add(this->label26);
			this->groupBox1->Location = System::Drawing::Point(361, 210);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(389, 204);
			this->groupBox1->TabIndex = 74;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Достижения";
			// 
			// textBoxArt
			// 
			this->textBoxArt->Location = System::Drawing::Point(120, 127);
			this->textBoxArt->Multiline = true;
			this->textBoxArt->Name = L"textBoxArt";
			this->textBoxArt->Size = System::Drawing::Size(253, 66);
			this->textBoxArt->TabIndex = 21;
			// 
			// label24
			// 
			this->label24->Location = System::Drawing::Point(13, 130);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(101, 45);
			this->label24->TabIndex = 20;
			this->label24->Text = L"Художественная деятельность";
			// 
			// textBoxOlymp
			// 
			this->textBoxOlymp->Location = System::Drawing::Point(93, 73);
			this->textBoxOlymp->Multiline = true;
			this->textBoxOlymp->Name = L"textBoxOlymp";
			this->textBoxOlymp->Size = System::Drawing::Size(280, 48);
			this->textBoxOlymp->TabIndex = 19;
			// 
			// label25
			// 
			this->label25->Location = System::Drawing::Point(13, 76);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(69, 36);
			this->label25->TabIndex = 18;
			this->label25->Text = L"Участие в олимпиадах";
			// 
			// textBoxSport
			// 
			this->textBoxSport->Location = System::Drawing::Point(93, 19);
			this->textBoxSport->Multiline = true;
			this->textBoxSport->Name = L"textBoxSport";
			this->textBoxSport->Size = System::Drawing::Size(280, 48);
			this->textBoxSport->TabIndex = 17;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(13, 22);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(69, 13);
			this->label26->TabIndex = 16;
			this->label26->Text = L"Спортивные";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(358, 188);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(148, 13);
			this->label27->TabIndex = 73;
			this->label27->Text = L"Годность к военной службе";
			// 
			// textBoxNational
			// 
			this->textBoxNational->Location = System::Drawing::Point(506, 155);
			this->textBoxNational->Name = L"textBoxNational";
			this->textBoxNational->Size = System::Drawing::Size(254, 20);
			this->textBoxNational->TabIndex = 72;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(358, 158);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(74, 13);
			this->label28->TabIndex = 71;
			this->label28->Text = L"Гражданство";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(358, 123);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(133, 13);
			this->label29->TabIndex = 70;
			this->label29->Text = L"Нуждается в общежитии";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(358, 92);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(82, 13);
			this->label30->TabIndex = 69;
			this->label30->Text = L"Наличие детей";
			// 
			// textBoxFamily
			// 
			this->textBoxFamily->Location = System::Drawing::Point(506, 64);
			this->textBoxFamily->Name = L"textBoxFamily";
			this->textBoxFamily->Size = System::Drawing::Size(254, 20);
			this->textBoxFamily->TabIndex = 68;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(358, 67);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(117, 13);
			this->label31->TabIndex = 67;
			this->label31->Text = L"Семейное положение";
			// 
			// textBoxPrevStudy
			// 
			this->textBoxPrevStudy->Location = System::Drawing::Point(506, 38);
			this->textBoxPrevStudy->Name = L"textBoxPrevStudy";
			this->textBoxPrevStudy->Size = System::Drawing::Size(254, 20);
			this->textBoxPrevStudy->TabIndex = 66;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(358, 41);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(142, 13);
			this->label32->TabIndex = 65;
			this->label32->Text = L"Предыдущее образование";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(358, 12);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(94, 13);
			this->label33->TabIndex = 64;
			this->label33->Text = L"Основа обучения";
			// 
			// numericUpDownKurs
			// 
			this->numericUpDownKurs->Location = System::Drawing::Point(133, 410);
			this->numericUpDownKurs->Name = L"numericUpDownKurs";
			this->numericUpDownKurs->Size = System::Drawing::Size(77, 20);
			this->numericUpDownKurs->TabIndex = 63;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(21, 412);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(31, 13);
			this->label22->TabIndex = 62;
			this->label22->Text = L"Курс";
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxGroup->Location = System::Drawing::Point(133, 381);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(200, 21);
			this->comboBoxGroup->TabIndex = 61;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(21, 386);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(42, 13);
			this->label21->TabIndex = 60;
			this->label21->Text = L"Группа";
			// 
			// comboBoxSpecial
			// 
			this->comboBoxSpecial->FormattingEnabled = true;
			this->comboBoxSpecial->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxSpecial->Location = System::Drawing::Point(133, 354);
			this->comboBoxSpecial->Name = L"comboBoxSpecial";
			this->comboBoxSpecial->Size = System::Drawing::Size(200, 21);
			this->comboBoxSpecial->TabIndex = 59;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(21, 359);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(85, 13);
			this->label20->TabIndex = 58;
			this->label20->Text = L"Специальность";
			// 
			// comboBoxKafedra
			// 
			this->comboBoxKafedra->FormattingEnabled = true;
			this->comboBoxKafedra->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxKafedra->Location = System::Drawing::Point(133, 327);
			this->comboBoxKafedra->Name = L"comboBoxKafedra";
			this->comboBoxKafedra->Size = System::Drawing::Size(200, 21);
			this->comboBoxKafedra->TabIndex = 57;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(21, 332);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(52, 13);
			this->label19->TabIndex = 56;
			this->label19->Text = L"Кафедра";
			// 
			// comboBoxFakultet
			// 
			this->comboBoxFakultet->FormattingEnabled = true;
			this->comboBoxFakultet->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxFakultet->Location = System::Drawing::Point(133, 300);
			this->comboBoxFakultet->Name = L"comboBoxFakultet";
			this->comboBoxFakultet->Size = System::Drawing::Size(200, 21);
			this->comboBoxFakultet->TabIndex = 55;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(21, 305);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(63, 13);
			this->label18->TabIndex = 54;
			this->label18->Text = L"Факультет";
			// 
			// comboBoxStudyForm
			// 
			this->comboBoxStudyForm->FormattingEnabled = true;
			this->comboBoxStudyForm->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxStudyForm->Location = System::Drawing::Point(133, 273);
			this->comboBoxStudyForm->Name = L"comboBoxStudyForm";
			this->comboBoxStudyForm->Size = System::Drawing::Size(200, 21);
			this->comboBoxStudyForm->TabIndex = 53;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(21, 278);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(93, 13);
			this->label17->TabIndex = 52;
			this->label17->Text = L"Форма обучения";
			// 
			// textBoxAdres
			// 
			this->textBoxAdres->Location = System::Drawing::Point(98, 247);
			this->textBoxAdres->Name = L"textBoxAdres";
			this->textBoxAdres->Size = System::Drawing::Size(235, 20);
			this->textBoxAdres->TabIndex = 51;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(21, 250);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(38, 13);
			this->label16->TabIndex = 50;
			this->label16->Text = L"Адрес";
			// 
			// textBoxEmail
			// 
			this->textBoxEmail->Location = System::Drawing::Point(98, 221);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(235, 20);
			this->textBoxEmail->TabIndex = 49;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(21, 224);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 13);
			this->label15->TabIndex = 48;
			this->label15->Text = L"Email";
			// 
			// textBoxMobile
			// 
			this->textBoxMobile->Location = System::Drawing::Point(153, 195);
			this->textBoxMobile->Name = L"textBoxMobile";
			this->textBoxMobile->Size = System::Drawing::Size(180, 20);
			this->textBoxMobile->TabIndex = 47;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(21, 198);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(112, 13);
			this->label14->TabIndex = 46;
			this->label14->Text = L"Мобильный телефон";
			// 
			// dateTimePickerBirth
			// 
			this->dateTimePickerBirth->Location = System::Drawing::Point(133, 169);
			this->dateTimePickerBirth->Name = L"dateTimePickerBirth";
			this->dateTimePickerBirth->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerBirth->TabIndex = 45;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(21, 171);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(86, 13);
			this->label13->TabIndex = 44;
			this->label13->Text = L"Дата рождения";
			// 
			// radioButtonFemale
			// 
			this->radioButtonFemale->AutoSize = true;
			this->radioButtonFemale->Location = System::Drawing::Point(206, 143);
			this->radioButtonFemale->Name = L"radioButtonFemale";
			this->radioButtonFemale->Size = System::Drawing::Size(51, 17);
			this->radioButtonFemale->TabIndex = 43;
			this->radioButtonFemale->TabStop = true;
			this->radioButtonFemale->Text = L"ЖЕН";
			this->radioButtonFemale->UseVisualStyleBackColor = true;
			// 
			// radioButtonMale
			// 
			this->radioButtonMale->AutoSize = true;
			this->radioButtonMale->Location = System::Drawing::Point(117, 143);
			this->radioButtonMale->Name = L"radioButtonMale";
			this->radioButtonMale->Size = System::Drawing::Size(53, 17);
			this->radioButtonMale->TabIndex = 42;
			this->radioButtonMale->TabStop = true;
			this->radioButtonMale->Text = L"МУЖ";
			this->radioButtonMale->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(21, 143);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(27, 13);
			this->label12->TabIndex = 41;
			this->label12->Text = L"Пол";
			// 
			// textBoxNumber
			// 
			this->textBoxNumber->Location = System::Drawing::Point(153, 113);
			this->textBoxNumber->Name = L"textBoxNumber";
			this->textBoxNumber->Size = System::Drawing::Size(180, 20);
			this->textBoxNumber->TabIndex = 40;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(21, 116);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 13);
			this->label11->TabIndex = 39;
			this->label11->Text = L"Номер зачетки";
			// 
			// textBoxMiddleName
			// 
			this->textBoxMiddleName->Location = System::Drawing::Point(98, 87);
			this->textBoxMiddleName->Name = L"textBoxMiddleName";
			this->textBoxMiddleName->Size = System::Drawing::Size(235, 20);
			this->textBoxMiddleName->TabIndex = 38;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(21, 90);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 37;
			this->label10->Text = L"Отчество";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(98, 61);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(235, 20);
			this->textBoxName->TabIndex = 36;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(21, 64);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 13);
			this->label9->TabIndex = 35;
			this->label9->Text = L"Имя";
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Location = System::Drawing::Point(98, 35);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(235, 20);
			this->textBoxSurname->TabIndex = 34;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(18, 38);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Фамилия";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 12);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(197, 13);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Добавление информации о студенте:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->buttonSave);
			this->tabPage2->Controls->Add(this->dataGridViewMarks);
			this->tabPage2->Controls->Add(this->buttonMarksShow);
			this->tabPage2->Controls->Add(this->comboBoxMarksSemestr);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->comboBoxMarksKurs);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(766, 492);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Оценки";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonSave
			// 
			this->buttonSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonSave->Location = System::Drawing::Point(289, 421);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 23);
			this->buttonSave->TabIndex = 38;
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &FormStudent::buttonSave_Click);
			// 
			// dataGridViewMarks
			// 
			this->dataGridViewMarks->AllowUserToAddRows = false;
			this->dataGridViewMarks->AllowUserToDeleteRows = false;
			this->dataGridViewMarks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewMarks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMarks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column4,
					this->Column5, this->Column6, this->Column7, this->Column8, this->Column2
			});
			this->dataGridViewMarks->Location = System::Drawing::Point(21, 52);
			this->dataGridViewMarks->Name = L"dataGridViewMarks";
			this->dataGridViewMarks->RowHeadersVisible = false;
			this->dataGridViewMarks->Size = System::Drawing::Size(652, 363);
			this->dataGridViewMarks->TabIndex = 37;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Предмет";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Атт1";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Атт2";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Самостоятельная работа";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Экзамен";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Оценка";
			this->Column2->Name = L"Column2";
			// 
			// buttonMarksShow
			// 
			this->buttonMarksShow->Location = System::Drawing::Point(411, 14);
			this->buttonMarksShow->Name = L"buttonMarksShow";
			this->buttonMarksShow->Size = System::Drawing::Size(75, 23);
			this->buttonMarksShow->TabIndex = 4;
			this->buttonMarksShow->Text = L"Показать";
			this->buttonMarksShow->UseVisualStyleBackColor = true;
			this->buttonMarksShow->Click += gcnew System::EventHandler(this, &FormStudent::buttonMarksShow_Click);
			// 
			// comboBoxMarksSemestr
			// 
			this->comboBoxMarksSemestr->FormattingEnabled = true;
			this->comboBoxMarksSemestr->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxMarksSemestr->Location = System::Drawing::Point(269, 16);
			this->comboBoxMarksSemestr->Name = L"comboBoxMarksSemestr";
			this->comboBoxMarksSemestr->Size = System::Drawing::Size(121, 21);
			this->comboBoxMarksSemestr->TabIndex = 3;
			this->comboBoxMarksSemestr->SelectedIndexChanged += gcnew System::EventHandler(this, &FormStudent::comboBox2_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(212, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Семестр";
			// 
			// comboBoxMarksKurs
			// 
			this->comboBoxMarksKurs->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxMarksKurs->FormattingEnabled = true;
			this->comboBoxMarksKurs->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxMarksKurs->Location = System::Drawing::Point(69, 16);
			this->comboBoxMarksKurs->Name = L"comboBoxMarksKurs";
			this->comboBoxMarksKurs->Size = System::Drawing::Size(121, 21);
			this->comboBoxMarksKurs->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Курс";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->buttonAddAchiev);
			this->tabPage3->Controls->Add(this->dataGridViewAchiev);
			this->tabPage3->Controls->Add(this->textBoxAchiev);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(766, 492);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Достижения";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// buttonAddAchiev
			// 
			this->buttonAddAchiev->Location = System::Drawing::Point(556, 42);
			this->buttonAddAchiev->Name = L"buttonAddAchiev";
			this->buttonAddAchiev->Size = System::Drawing::Size(75, 23);
			this->buttonAddAchiev->TabIndex = 39;
			this->buttonAddAchiev->Text = L"Добавить";
			this->buttonAddAchiev->UseVisualStyleBackColor = true;
			this->buttonAddAchiev->Click += gcnew System::EventHandler(this, &FormStudent::buttonAddAchiev_Click);
			// 
			// dataGridViewAchiev
			// 
			this->dataGridViewAchiev->AllowUserToAddRows = false;
			this->dataGridViewAchiev->AllowUserToDeleteRows = false;
			this->dataGridViewAchiev->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewAchiev->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAchiev->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridViewAchiev->Location = System::Drawing::Point(20, 93);
			this->dataGridViewAchiev->Name = L"dataGridViewAchiev";
			this->dataGridViewAchiev->RowHeadersVisible = false;
			this->dataGridViewAchiev->Size = System::Drawing::Size(725, 373);
			this->dataGridViewAchiev->TabIndex = 38;
			this->dataGridViewAchiev->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormStudent::dataGridViewAchiev_CellClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Достижение";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 400;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// textBoxAchiev
			// 
			this->textBoxAchiev->Location = System::Drawing::Point(97, 22);
			this->textBoxAchiev->Multiline = true;
			this->textBoxAchiev->Name = L"textBoxAchiev";
			this->textBoxAchiev->Size = System::Drawing::Size(431, 65);
			this->textBoxAchiev->TabIndex = 36;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Достижение";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->buttonPoruchAdd);
			this->tabPage4->Controls->Add(this->dataGridViewPoruch);
			this->tabPage4->Controls->Add(this->textBoxPoruch);
			this->tabPage4->Controls->Add(this->label4);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(766, 492);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Поручения";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// buttonPoruchAdd
			// 
			this->buttonPoruchAdd->Location = System::Drawing::Point(558, 43);
			this->buttonPoruchAdd->Name = L"buttonPoruchAdd";
			this->buttonPoruchAdd->Size = System::Drawing::Size(75, 23);
			this->buttonPoruchAdd->TabIndex = 42;
			this->buttonPoruchAdd->Text = L"Добавить";
			this->buttonPoruchAdd->UseVisualStyleBackColor = true;
			this->buttonPoruchAdd->Click += gcnew System::EventHandler(this, &FormStudent::buttonPoruchAdd_Click);
			// 
			// dataGridViewPoruch
			// 
			this->dataGridViewPoruch->AllowUserToAddRows = false;
			this->dataGridViewPoruch->AllowUserToDeleteRows = false;
			this->dataGridViewPoruch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewPoruch->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPoruch->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewButtonColumn1, this->dataGridViewButtonColumn2, this->Column1
			});
			this->dataGridViewPoruch->Location = System::Drawing::Point(22, 94);
			this->dataGridViewPoruch->Name = L"dataGridViewPoruch";
			this->dataGridViewPoruch->RowHeadersVisible = false;
			this->dataGridViewPoruch->Size = System::Drawing::Size(725, 374);
			this->dataGridViewPoruch->TabIndex = 41;
			this->dataGridViewPoruch->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormStudent::dataGridViewPoruch_CellClick);
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Поручения";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 400;
			// 
			// dataGridViewButtonColumn1
			// 
			this->dataGridViewButtonColumn1->HeaderText = L"Статус";
			this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
			this->dataGridViewButtonColumn1->ReadOnly = true;
			this->dataGridViewButtonColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// dataGridViewButtonColumn2
			// 
			this->dataGridViewButtonColumn2->HeaderText = L"";
			this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
			this->dataGridViewButtonColumn2->ReadOnly = true;
			this->dataGridViewButtonColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewButtonColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"";
			this->Column1->Name = L"Column1";
			// 
			// textBoxPoruch
			// 
			this->textBoxPoruch->Location = System::Drawing::Point(99, 23);
			this->textBoxPoruch->Multiline = true;
			this->textBoxPoruch->Name = L"textBoxPoruch";
			this->textBoxPoruch->Size = System::Drawing::Size(436, 65);
			this->textBoxPoruch->TabIndex = 40;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 39;
			this->label4->Text = L"Поручение";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->buttonDolgiAdd);
			this->tabPage5->Controls->Add(this->dataGridViewDolgi);
			this->tabPage5->Controls->Add(this->textBoxDolgi);
			this->tabPage5->Controls->Add(this->label5);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(766, 492);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Долги";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// buttonDolgiAdd
			// 
			this->buttonDolgiAdd->Location = System::Drawing::Point(558, 43);
			this->buttonDolgiAdd->Name = L"buttonDolgiAdd";
			this->buttonDolgiAdd->Size = System::Drawing::Size(75, 23);
			this->buttonDolgiAdd->TabIndex = 46;
			this->buttonDolgiAdd->Text = L"Добавить";
			this->buttonDolgiAdd->UseVisualStyleBackColor = true;
			this->buttonDolgiAdd->Click += gcnew System::EventHandler(this, &FormStudent::buttonDolgiAdd_Click);
			// 
			// dataGridViewDolgi
			// 
			this->dataGridViewDolgi->AllowUserToAddRows = false;
			this->dataGridViewDolgi->AllowUserToDeleteRows = false;
			this->dataGridViewDolgi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewDolgi->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDolgi->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewButtonColumn3, this->dataGridViewButtonColumn4
			});
			this->dataGridViewDolgi->Location = System::Drawing::Point(22, 94);
			this->dataGridViewDolgi->Name = L"dataGridViewDolgi";
			this->dataGridViewDolgi->RowHeadersVisible = false;
			this->dataGridViewDolgi->Size = System::Drawing::Size(725, 374);
			this->dataGridViewDolgi->TabIndex = 45;
			this->dataGridViewDolgi->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormStudent::dataGridViewDolgi_CellClick);
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Долги";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 400;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Статус";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			this->dataGridViewTextBoxColumn6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// dataGridViewButtonColumn3
			// 
			this->dataGridViewButtonColumn3->HeaderText = L"";
			this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
			this->dataGridViewButtonColumn3->ReadOnly = true;
			this->dataGridViewButtonColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewButtonColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// dataGridViewButtonColumn4
			// 
			this->dataGridViewButtonColumn4->HeaderText = L"";
			this->dataGridViewButtonColumn4->Name = L"dataGridViewButtonColumn4";
			// 
			// textBoxDolgi
			// 
			this->textBoxDolgi->Location = System::Drawing::Point(99, 23);
			this->textBoxDolgi->Multiline = true;
			this->textBoxDolgi->Name = L"textBoxDolgi";
			this->textBoxDolgi->Size = System::Drawing::Size(436, 65);
			this->textBoxDolgi->TabIndex = 44;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 43;
			this->label5->Text = L"Долг";
			// 
			// FormStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(774, 518);
			this->Controls->Add(this->tabControl1);
			this->Name = L"FormStudent";
			this->Text = L"Студенты";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormStudent::FormStudent_FormClosing);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKurs))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMarks))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAchiev))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPoruch))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDolgi))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
	}

private: 
	System::Void FormStudent_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	System::Void buttonAddAchiev_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPoruchAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonDolgiAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void dataGridViewAchiev_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	System::Void dataGridViewPoruch_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	System::Void dataGridViewDolgi_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	System::Void buttonMarksShow_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e);
};
}
