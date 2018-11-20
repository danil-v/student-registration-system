#pragma once
#include "StudentModel.h"

namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	ref class Form1;
	class MySQL;

	/// <summary>
	/// Сводка для FormAddition
	/// </summary>
	public ref class FormAddition : public System::Windows::Forms::Form
	{
	public:
		FormAddition(Form1 ^form, StudentModel *student, MySQL *mysql);

	private:
		Form1 ^form;
		StudentModel *student;
		MySQL *mysql;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormAddition()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonBack;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButtonPay;
	private: System::Windows::Forms::RadioButton^  radioButtonPayNo;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxPrevStudy;
	private: System::Windows::Forms::TextBox^  textBoxFamily;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  radioButtonChildrenNo;

	private: System::Windows::Forms::RadioButton^  radioButtonChildren;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButtonNeedHostelNo;

	private: System::Windows::Forms::RadioButton^  radioButtonNeedHostel;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBoxNational;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  radioButtonMilitaryNo;

	private: System::Windows::Forms::RadioButton^  radioButtonMilitary;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBoxArt;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBoxOlymp;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxSport;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerStudyStart;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerStudyEnd;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;

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
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButtonPay = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonPayNo = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrevStudy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFamily = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButtonChildrenNo = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonChildren = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButtonNeedHostelNo = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNeedHostel = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxNational = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radioButtonMilitaryNo = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMilitary = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxArt = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBoxOlymp = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxSport = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerStudyStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePickerStudyEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonBack
			// 
			this->buttonBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonBack->Location = System::Drawing::Point(226, 12);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(179, 31);
			this->buttonBack->TabIndex = 0;
			this->buttonBack->Text = L"Вернуться к основным данным";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &FormAddition::buttonBack_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Основа обучения";
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Предыдущее образование";
			// 
			// textBoxPrevStudy
			// 
			this->textBoxPrevStudy->Location = System::Drawing::Point(161, 83);
			this->textBoxPrevStudy->Name = L"textBoxPrevStudy";
			this->textBoxPrevStudy->Size = System::Drawing::Size(254, 20);
			this->textBoxPrevStudy->TabIndex = 5;
			// 
			// textBoxFamily
			// 
			this->textBoxFamily->Location = System::Drawing::Point(161, 109);
			this->textBoxFamily->Name = L"textBoxFamily";
			this->textBoxFamily->Size = System::Drawing::Size(254, 20);
			this->textBoxFamily->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Семейное положение";
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
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Наличие детей";
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
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Нуждается в общежитии";
			// 
			// textBoxNational
			// 
			this->textBoxNational->Location = System::Drawing::Point(161, 181);
			this->textBoxNational->Name = L"textBoxNational";
			this->textBoxNational->Size = System::Drawing::Size(254, 20);
			this->textBoxNational->TabIndex = 15;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 184);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Гражданство";
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
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 209);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(148, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Годность к военной службе";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBoxArt);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->textBoxOlymp);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textBoxSport);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Location = System::Drawing::Point(16, 230);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(389, 232);
			this->groupBox1->TabIndex = 19;
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
			// label10
			// 
			this->label10->Location = System::Drawing::Point(13, 130);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 45);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Художественная деятельность";
			// 
			// textBoxOlymp
			// 
			this->textBoxOlymp->Location = System::Drawing::Point(93, 73);
			this->textBoxOlymp->Multiline = true;
			this->textBoxOlymp->Name = L"textBoxOlymp";
			this->textBoxOlymp->Size = System::Drawing::Size(280, 48);
			this->textBoxOlymp->TabIndex = 19;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(13, 76);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(69, 36);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Участие в олимпиадах";
			// 
			// textBoxSport
			// 
			this->textBoxSport->Location = System::Drawing::Point(93, 19);
			this->textBoxSport->Multiline = true;
			this->textBoxSport->Name = L"textBoxSport";
			this->textBoxSport->Size = System::Drawing::Size(280, 48);
			this->textBoxSport->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 22);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Спортивные";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(21, 475);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(120, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Дата начала обучения";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(21, 505);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(138, 13);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Дата окончания обучения";
			// 
			// dateTimePickerStudyStart
			// 
			this->dateTimePickerStudyStart->Location = System::Drawing::Point(189, 475);
			this->dateTimePickerStudyStart->Name = L"dateTimePickerStudyStart";
			this->dateTimePickerStudyStart->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerStudyStart->TabIndex = 22;
			// 
			// dateTimePickerStudyEnd
			// 
			this->dateTimePickerStudyEnd->Location = System::Drawing::Point(189, 501);
			this->dateTimePickerStudyEnd->Name = L"dateTimePickerStudyEnd";
			this->dateTimePickerStudyEnd->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerStudyEnd->TabIndex = 23;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButtonPay);
			this->panel1->Controls->Add(this->radioButtonPayNo);
			this->panel1->Location = System::Drawing::Point(119, 53);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(270, 26);
			this->panel1->TabIndex = 24;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButtonChildren);
			this->panel2->Controls->Add(this->radioButtonChildrenNo);
			this->panel2->Location = System::Drawing::Point(164, 135);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 23);
			this->panel2->TabIndex = 25;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButtonNeedHostel);
			this->panel3->Controls->Add(this->radioButtonNeedHostelNo);
			this->panel3->Location = System::Drawing::Point(165, 159);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(114, 23);
			this->panel3->TabIndex = 26;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->radioButtonMilitary);
			this->panel4->Controls->Add(this->radioButtonMilitaryNo);
			this->panel4->Location = System::Drawing::Point(167, 206);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(112, 23);
			this->panel4->TabIndex = 27;
			// 
			// FormAddition
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 527);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dateTimePickerStudyEnd);
			this->Controls->Add(this->dateTimePickerStudyStart);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxNational);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxFamily);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxPrevStudy);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonBack);
			this->Name = L"FormAddition";
			this->Text = L"Дополнительные данные";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormAddition::FormAddition_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonBack_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: 
	System::Void FormAddition_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};


}
