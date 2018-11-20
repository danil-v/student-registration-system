#pragma once

#include "FormFakultets.h"
#include "FormKafedra.h"
#include "FormNapravlenie.h"
#include "FormGroups.h"
#include "MySQL.h"
#include "FormAddition.h"
#include "FormDiscipline.h"
#include "FormStudent.h"

namespace Student {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(MySQL *mysql, int access);
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn12;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn23;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn24;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn26;

	public:












		int access;

		void loadStudents();
		void loadFakultets();
		void loadKafedras();
		void loadTeachers();
		void loadLogins();
	private:
		
		MySQL *mysql;
		DataGridView ^dataGridView1;

		vector<User>* logins;

		vector<KafedraModel> *kafedrasStudent;
		vector<NapravlenieModel> *napravleniaStudent;
		vector<GroupModel> *groupStudent;

		vector<PredmetsWithMarks> *marks;

		vector<StudentModel> *students;
		vector<Teacher> *teachers;

		vector<KafedraModel> *kafedrasVedomost;
		vector<NapravlenieModel> *napravleniaVedomost;
		vector<GroupModel> *groupVedomost;
		vector<Predmet> *disciplinaVedomost;

		vector<KafedraModel> *kafedrasUspevaemost;
		vector<NapravlenieModel> *napravleniaUspevaemost;
		vector<GroupModel> *groupUspevaemost;



		vector<KafedraModel> *kafedrasPredmets;
		vector<NapravlenieModel> *napravleniaPredmets;

		vector<KafedraModel> *kafedrasDisciplina;
		vector<NapravlenieModel> *napravleniaDisciplina;
		vector<Predmet> *predmetsDisciplina;

		vector<KafedraModel> *kafedrasDisciplinaShow;
		vector<NapravlenieModel> *napravleniaDisciplinaShow;
		
		StudentModel *student;
		StudentModel *studentAdd;
		vector<StudentModel> *listStudentGroups;
		vector<FakultetModel> *fakultets;
		vector<KafedraModel> *kafedrasAkadem;
		vector<NapravlenieModel> *napravleniaAkadem;
		vector<GroupModel> *groupsAkadem;
		vector<StudentModel> *studentsAkadem;

		vector<KafedraModel> *kafedrasAll;

		int tableType;
		StringFormat^ strFormat;    // to format the grid rows.  
		ArrayList^ arrColumnLefts;  // left coordinates of columns  
		ArrayList^ arrColumnWidths; // column widths  
		int iCellHeight;            // datagridview cell dimensions  
		int iTotalWidth;
		int iRow;                   // counter  
		bool bFirstPage;            // to check whether we are printing first page  
		bool bNewPage;              // to check whether we are printing a new page  
		int iHeaderHeight;          // header height  
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::Button^  buttonAddUser;


	private: System::Windows::Forms::Label^  label68;
	private: System::Windows::Forms::RadioButton^  radioButtonPreps;

	private: System::Windows::Forms::RadioButton^  radioButtonStudent;
	private: System::Windows::Forms::ComboBox^  comboBoxPrepsLogin;


	private: System::Windows::Forms::ComboBox^  comboBoxStudentsLogin;

	private: System::Windows::Forms::CheckBox^  checkBoxAccess;

	private: System::Windows::Forms::TextBox^  textBoxPass;

	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::TextBox^  textBoxLogin;

	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::DataGridView^  dataGridViewLogin;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn27;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn28;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn29;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn30;
	private: System::Windows::Forms::DataGridViewButtonColumn^  dataGridViewButtonColumn1;
			 static int iRowHeight = 0;
		int CalculateColWidth(int gridColWidth, int marginWidth);

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column18;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column17;
			 

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column10;
	private: System::Windows::Forms::ComboBox^  comboBoxTeacher;


	private: System::Windows::Forms::DataGridView^  dataGridViewAttestat;













	private: System::Windows::Forms::Button^  buttonPrintVed;

	private: System::Windows::Forms::Button^  buttonShowExam;

	private: System::Windows::Forms::Button^  buttonShowAt;
	private: System::Windows::Forms::DataGridView^  dataGridViewExam;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn11;
	private: System::Windows::Forms::Button^  buttonPrintCl;
	private: System::Windows::Forms::Button^  buttonPrintUsp;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::DataGridView^  dataGridViewDolg;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn18;
private: System::Windows::Forms::DataGridView^  dataGridViewUsp;













private: System::Drawing::Printing::PrintDocument^  printDocument1;



















	private: System::Windows::Forms::DataGridViewButtonColumn^  Column12;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1();
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Button^  buttonGroups;

	private: System::Windows::Forms::Button^  buttonNapravlenia;

	private: System::Windows::Forms::Button^  buttonKafedri;

	private: System::Windows::Forms::Button^  buttonFakultet;
	private: System::Windows::Forms::ComboBox^  comboBoxNapravlenieGroups;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBoxKafedriGroups;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetGroups;

	private: System::Windows::Forms::Label^  label1;





	private: System::Windows::Forms::ComboBox^  comboBoxGroupGroups;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DataGridView^  dataGridViewStudentList;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBoxMiddleName;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBoxName;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxSurname;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  dataGridViewStud;






	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Button^  buttonClearStud;

	private: System::Windows::Forms::Button^  buttonAddStudent;
	private: System::Windows::Forms::Button^  buttonAdditional;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownKurs;




	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::ComboBox^  comboBoxSpecial;

	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::ComboBox^  comboBoxKafedra;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::ComboBox^  comboBoxFakultetStudent;

	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::ComboBox^  comboBoxStudyForm;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBoxAdres;

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBoxEmail;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBoxMobilePhone;

	private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirth;

	private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::RadioButton^  radioButtonSexF;

private: System::Windows::Forms::RadioButton^  radioButtonSexM;

	private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  textBoxNumber;

	private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::TextBox^  textBoxSearch;

private: System::Windows::Forms::ComboBox^  comboBoxSearchType;

	private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Button^  buttonSearch;



	private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::TextBox^  textBoxUchStepPrep;



	private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::TextBox^  textBoxUchZvaniePrep;

private: System::Windows::Forms::TextBox^  textBoxFioPrep;

	private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Button^  buttonPrepAdd;

private: System::Windows::Forms::ComboBox^  comboBoxKafedraPrep;

private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::DataGridView^  dataGridViewPreps;







private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::NumericUpDown^  numericUpDownLectionTime;

private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::NumericUpDown^  numericUpDownTotalTime;

private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::CheckBox^  checkBoxKursProj;

private: System::Windows::Forms::CheckBox^  checkBoxExam;

private: System::Windows::Forms::CheckBox^  checkBoxZachet;

private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::ComboBox^  comboBoxDisciplin;
private: System::Windows::Forms::Button^  buttonDisciplinAdd;





private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::ComboBox^  comboBoxSemestrDisciplinAdd;

private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::ComboBox^  comboBoxKursDisciplinAdd;

private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::ComboBox^  comboBoxNapravlenieDisciplinAdd;

private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::ComboBox^  comboBoxKafedraDisciplinAdd;

private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::ComboBox^  comboBoxFakultetDisciplinAdd;

private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Button^  buttonPlanAdd;

private: System::Windows::Forms::TextBox^  textBoxDisciplPlanAdd;

private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::ComboBox^  comboBoxSemestrPlanAdd;

private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::ComboBox^  comboBoxKursPlanAdd;

private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::ComboBox^  comboBoxNapravleniePlanAdd;

private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::ComboBox^  comboBoxKafedraPlanAdd;

private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::ComboBox^  comboBoxFakultetPlanAdd;

private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::NumericUpDown^  numericUpDownPractTime;

private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::NumericUpDown^  numericUpDownLabTime;

private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Button^  buttonDisciplinShow;

private: System::Windows::Forms::ComboBox^  comboBoxSemestrDisciplinShow;

private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::ComboBox^  comboBoxKursDisciplinShow;

private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::ComboBox^  comboBoxNaprDisciplinShow;

private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::ComboBox^  comboBoxKafedriDisciplinShow;

private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::ComboBox^  comboBoxFakultetDisciplinShow;

private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::GroupBox^  groupBox4;



private: System::Windows::Forms::ComboBox^  comboBoxNapravlVedomost;

private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::ComboBox^  comboBoxKafedraVedomost;

private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::ComboBox^  comboBoxFakultetVedomost;

private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::ComboBox^  comboBoxDisciplinVedomost;

private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::ComboBox^  comboBoxGroupVedomost;

private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::ComboBox^  comboBoxSemestrVedomost;

private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::ComboBox^  comboBoxKursVedomost;

private: System::Windows::Forms::Label^  label57;


private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Button^  buttonShowUspevaemost;
private: System::Windows::Forms::ComboBox^  comboBoxGroupUspevaemost;


private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::ComboBox^  comboBoxSemestrUspevaemost;

private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::ComboBox^  comboBoxKursUspevaemost;

private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::ComboBox^  comboBoxNaprUspevaemost;

private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::ComboBox^  comboBoxKafedraUspevaemost;

private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::ComboBox^  comboBoxFakultetUspevaemost;

private: System::Windows::Forms::Label^  label67;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxSearchType = (gcnew System::Windows::Forms::ComboBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->dataGridViewStud = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->buttonClearStud = (gcnew System::Windows::Forms::Button());
			this->buttonAddStudent = (gcnew System::Windows::Forms::Button());
			this->buttonAdditional = (gcnew System::Windows::Forms::Button());
			this->numericUpDownKurs = (gcnew System::Windows::Forms::NumericUpDown());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSpecial = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedra = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetStudent = (gcnew System::Windows::Forms::ComboBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->comboBoxStudyForm = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBoxAdres = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBoxMobilePhone = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->radioButtonSexF = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonSexM = (gcnew System::Windows::Forms::RadioButton());
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
			this->dataGridViewStudentList = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroupGroups = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravlenieGroups = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedriGroups = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetGroups = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonGroups = (gcnew System::Windows::Forms::Button());
			this->buttonNapravlenia = (gcnew System::Windows::Forms::Button());
			this->buttonKafedri = (gcnew System::Windows::Forms::Button());
			this->buttonFakultet = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewPreps = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->buttonPrepAdd = (gcnew System::Windows::Forms::Button());
			this->comboBoxKafedraPrep = (gcnew System::Windows::Forms::ComboBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBoxUchStepPrep = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBoxUchZvaniePrep = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFioPrep = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDisciplinShow = (gcnew System::Windows::Forms::Button());
			this->comboBoxSemestrDisciplinShow = (gcnew System::Windows::Forms::ComboBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKursDisciplinShow = (gcnew System::Windows::Forms::ComboBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNaprDisciplinShow = (gcnew System::Windows::Forms::ComboBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedriDisciplinShow = (gcnew System::Windows::Forms::ComboBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetDisciplinShow = (gcnew System::Windows::Forms::ComboBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxTeacher = (gcnew System::Windows::Forms::ComboBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownLabTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownPractTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownLectionTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownTotalTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->checkBoxKursProj = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxExam = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxZachet = (gcnew System::Windows::Forms::CheckBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->comboBoxDisciplin = (gcnew System::Windows::Forms::ComboBox());
			this->buttonDisciplinAdd = (gcnew System::Windows::Forms::Button());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSemestrDisciplinAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKursDisciplinAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravlenieDisciplinAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedraDisciplinAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetDisciplinAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonPlanAdd = (gcnew System::Windows::Forms::Button());
			this->textBoxDisciplPlanAdd = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSemestrPlanAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKursPlanAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravleniePlanAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedraPlanAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetPlanAdd = (gcnew System::Windows::Forms::ComboBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewExam = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonPrintVed = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAttestat = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column17 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonShowExam = (gcnew System::Windows::Forms::Button());
			this->buttonShowAt = (gcnew System::Windows::Forms::Button());
			this->comboBoxDisciplinVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroupVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSemestrVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKursVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNapravlVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedraVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetVedomost = (gcnew System::Windows::Forms::ComboBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->buttonPrintCl = (gcnew System::Windows::Forms::Button());
			this->buttonPrintUsp = (gcnew System::Windows::Forms::Button());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDolg = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewUsp = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonShowUspevaemost = (gcnew System::Windows::Forms::Button());
			this->comboBoxGroupUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSemestrUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKursUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNaprUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKafedraUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFakultetUspevaemost = (gcnew System::Windows::Forms::ComboBox());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->buttonAddUser = (gcnew System::Windows::Forms::Button());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->radioButtonPreps = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonStudent = (gcnew System::Windows::Forms::RadioButton());
			this->comboBoxPrepsLogin = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxStudentsLogin = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxAccess = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewLogin = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn29 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn30 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStud))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKurs))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudentList))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPreps))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLabTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownPractTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLectionTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownTotalTime))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewExam))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAttestat))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDolg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewUsp))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLogin))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(927, 544);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textBoxSearch);
			this->tabPage1->Controls->Add(this->comboBoxSearchType);
			this->tabPage1->Controls->Add(this->label24);
			this->tabPage1->Controls->Add(this->buttonSearch);
			this->tabPage1->Controls->Add(this->dataGridViewStud);
			this->tabPage1->Controls->Add(this->label23);
			this->tabPage1->Controls->Add(this->buttonClearStud);
			this->tabPage1->Controls->Add(this->buttonAddStudent);
			this->tabPage1->Controls->Add(this->buttonAdditional);
			this->tabPage1->Controls->Add(this->numericUpDownKurs);
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->comboBoxGroup);
			this->tabPage1->Controls->Add(this->label21);
			this->tabPage1->Controls->Add(this->comboBoxSpecial);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->comboBoxKafedra);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->comboBoxFakultetStudent);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->comboBoxStudyForm);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBoxAdres);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->textBoxEmail);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->textBoxMobilePhone);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->dateTimePickerBirth);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->radioButtonSexF);
			this->tabPage1->Controls->Add(this->radioButtonSexM);
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
			this->tabPage1->Size = System::Drawing::Size(919, 518);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Личные дела учащихся";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxSearch->Location = System::Drawing::Point(566, 474);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(245, 20);
			this->textBoxSearch->TabIndex = 41;
			// 
			// comboBoxSearchType
			// 
			this->comboBoxSearchType->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->comboBoxSearchType->FormattingEnabled = true;
			this->comboBoxSearchType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Фамилии", L"Курсу", L"Группе" });
			this->comboBoxSearchType->Location = System::Drawing::Point(439, 474);
			this->comboBoxSearchType->Name = L"comboBoxSearchType";
			this->comboBoxSearchType->Size = System::Drawing::Size(121, 21);
			this->comboBoxSearchType->TabIndex = 40;
			// 
			// label24
			// 
			this->label24->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(376, 477);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(57, 13);
			this->label24->TabIndex = 39;
			this->label24->Text = L"Поиск по:";
			// 
			// buttonSearch
			// 
			this->buttonSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonSearch->Location = System::Drawing::Point(817, 474);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(94, 23);
			this->buttonSearch->TabIndex = 38;
			this->buttonSearch->Text = L"Найти";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &Form1::buttonSearch_Click);
			// 
			// dataGridViewStud
			// 
			this->dataGridViewStud->AllowUserToAddRows = false;
			this->dataGridViewStud->AllowUserToDeleteRows = false;
			this->dataGridViewStud->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewStud->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStud->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column4,
					this->Column5, this->Column6, this->Column8, this->Column7, this->Column12
			});
			this->dataGridViewStud->Location = System::Drawing::Point(363, 44);
			this->dataGridViewStud->Name = L"dataGridViewStud";
			this->dataGridViewStud->RowHeadersVisible = false;
			this->dataGridViewStud->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewStud->Size = System::Drawing::Size(548, 363);
			this->dataGridViewStud->TabIndex = 36;
			this->dataGridViewStud->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridViewStud_CellClick);
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Фамилия";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Имя";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Отчество";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Группа";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Курс";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"";
			this->Column12->Name = L"Column12";
			this->Column12->ReadOnly = true;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(360, 16);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(315, 13);
			this->label23->TabIndex = 35;
			this->label23->Text = L"Кликните по студенту для открытия детальной информации:";
			// 
			// buttonClearStud
			// 
			this->buttonClearStud->Location = System::Drawing::Point(187, 474);
			this->buttonClearStud->Name = L"buttonClearStud";
			this->buttonClearStud->Size = System::Drawing::Size(120, 23);
			this->buttonClearStud->TabIndex = 34;
			this->buttonClearStud->Text = L"Очистить данные";
			this->buttonClearStud->UseVisualStyleBackColor = true;
			this->buttonClearStud->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// buttonAddStudent
			// 
			this->buttonAddStudent->Location = System::Drawing::Point(24, 474);
			this->buttonAddStudent->Name = L"buttonAddStudent";
			this->buttonAddStudent->Size = System::Drawing::Size(149, 23);
			this->buttonAddStudent->TabIndex = 33;
			this->buttonAddStudent->Text = L"Добавить данные";
			this->buttonAddStudent->UseVisualStyleBackColor = true;
			this->buttonAddStudent->Click += gcnew System::EventHandler(this, &Form1::buttonAddStudent_Click);
			// 
			// buttonAdditional
			// 
			this->buttonAdditional->Location = System::Drawing::Point(24, 445);
			this->buttonAdditional->Name = L"buttonAdditional";
			this->buttonAdditional->Size = System::Drawing::Size(283, 23);
			this->buttonAdditional->TabIndex = 32;
			this->buttonAdditional->Text = L"Дополнительные сведения";
			this->buttonAdditional->UseVisualStyleBackColor = true;
			this->buttonAdditional->Click += gcnew System::EventHandler(this, &Form1::buttonAdditional_Click);
			// 
			// numericUpDownKurs
			// 
			this->numericUpDownKurs->Location = System::Drawing::Point(136, 415);
			this->numericUpDownKurs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDownKurs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownKurs->Name = L"numericUpDownKurs";
			this->numericUpDownKurs->Size = System::Drawing::Size(77, 20);
			this->numericUpDownKurs->TabIndex = 31;
			this->numericUpDownKurs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(24, 417);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(31, 13);
			this->label22->TabIndex = 30;
			this->label22->Text = L"Курс";
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Location = System::Drawing::Point(136, 386);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(200, 21);
			this->comboBoxGroup->TabIndex = 29;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(24, 391);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(42, 13);
			this->label21->TabIndex = 28;
			this->label21->Text = L"Группа";
			// 
			// comboBoxSpecial
			// 
			this->comboBoxSpecial->FormattingEnabled = true;
			this->comboBoxSpecial->Location = System::Drawing::Point(136, 359);
			this->comboBoxSpecial->Name = L"comboBoxSpecial";
			this->comboBoxSpecial->Size = System::Drawing::Size(200, 21);
			this->comboBoxSpecial->TabIndex = 27;
			this->comboBoxSpecial->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxSpecial_SelectedIndexChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(24, 364);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(85, 13);
			this->label20->TabIndex = 26;
			this->label20->Text = L"Специальность";
			// 
			// comboBoxKafedra
			// 
			this->comboBoxKafedra->FormattingEnabled = true;
			this->comboBoxKafedra->Location = System::Drawing::Point(136, 332);
			this->comboBoxKafedra->Name = L"comboBoxKafedra";
			this->comboBoxKafedra->Size = System::Drawing::Size(200, 21);
			this->comboBoxKafedra->TabIndex = 25;
			this->comboBoxKafedra->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedra_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(24, 337);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(52, 13);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Кафедра";
			// 
			// comboBoxFakultetStudent
			// 
			this->comboBoxFakultetStudent->FormattingEnabled = true;
			this->comboBoxFakultetStudent->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxFakultetStudent->Location = System::Drawing::Point(136, 305);
			this->comboBoxFakultetStudent->Name = L"comboBoxFakultetStudent";
			this->comboBoxFakultetStudent->Size = System::Drawing::Size(200, 21);
			this->comboBoxFakultetStudent->TabIndex = 23;
			this->comboBoxFakultetStudent->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetStudent_SelectedIndexChanged);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(24, 310);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(63, 13);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Факультет";
			// 
			// comboBoxStudyForm
			// 
			this->comboBoxStudyForm->FormattingEnabled = true;
			this->comboBoxStudyForm->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"очная", L"заочная" });
			this->comboBoxStudyForm->Location = System::Drawing::Point(136, 278);
			this->comboBoxStudyForm->Name = L"comboBoxStudyForm";
			this->comboBoxStudyForm->Size = System::Drawing::Size(200, 21);
			this->comboBoxStudyForm->TabIndex = 21;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(24, 283);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(93, 13);
			this->label17->TabIndex = 20;
			this->label17->Text = L"Форма обучения";
			// 
			// textBoxAdres
			// 
			this->textBoxAdres->Location = System::Drawing::Point(101, 252);
			this->textBoxAdres->Name = L"textBoxAdres";
			this->textBoxAdres->Size = System::Drawing::Size(235, 20);
			this->textBoxAdres->TabIndex = 19;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(24, 255);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(38, 13);
			this->label16->TabIndex = 18;
			this->label16->Text = L"Адрес";
			// 
			// textBoxEmail
			// 
			this->textBoxEmail->Location = System::Drawing::Point(101, 226);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(235, 20);
			this->textBoxEmail->TabIndex = 17;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(24, 229);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 13);
			this->label15->TabIndex = 16;
			this->label15->Text = L"Email";
			// 
			// textBoxMobilePhone
			// 
			this->textBoxMobilePhone->Location = System::Drawing::Point(156, 200);
			this->textBoxMobilePhone->Name = L"textBoxMobilePhone";
			this->textBoxMobilePhone->Size = System::Drawing::Size(180, 20);
			this->textBoxMobilePhone->TabIndex = 15;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(24, 203);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(112, 13);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Мобильный телефон";
			// 
			// dateTimePickerBirth
			// 
			this->dateTimePickerBirth->Location = System::Drawing::Point(136, 174);
			this->dateTimePickerBirth->Name = L"dateTimePickerBirth";
			this->dateTimePickerBirth->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerBirth->TabIndex = 13;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(24, 176);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(86, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Дата рождения";
			// 
			// radioButtonSexF
			// 
			this->radioButtonSexF->AutoSize = true;
			this->radioButtonSexF->Location = System::Drawing::Point(209, 148);
			this->radioButtonSexF->Name = L"radioButtonSexF";
			this->radioButtonSexF->Size = System::Drawing::Size(51, 17);
			this->radioButtonSexF->TabIndex = 11;
			this->radioButtonSexF->TabStop = true;
			this->radioButtonSexF->Text = L"ЖЕН";
			this->radioButtonSexF->UseVisualStyleBackColor = true;
			// 
			// radioButtonSexM
			// 
			this->radioButtonSexM->AutoSize = true;
			this->radioButtonSexM->Location = System::Drawing::Point(120, 148);
			this->radioButtonSexM->Name = L"radioButtonSexM";
			this->radioButtonSexM->Size = System::Drawing::Size(53, 17);
			this->radioButtonSexM->TabIndex = 10;
			this->radioButtonSexM->TabStop = true;
			this->radioButtonSexM->Text = L"МУЖ";
			this->radioButtonSexM->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(24, 148);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(27, 13);
			this->label12->TabIndex = 9;
			this->label12->Text = L"Пол";
			// 
			// textBoxNumber
			// 
			this->textBoxNumber->Location = System::Drawing::Point(156, 118);
			this->textBoxNumber->Name = L"textBoxNumber";
			this->textBoxNumber->Size = System::Drawing::Size(180, 20);
			this->textBoxNumber->TabIndex = 8;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 121);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Номер зачетки";
			// 
			// textBoxMiddleName
			// 
			this->textBoxMiddleName->Location = System::Drawing::Point(101, 92);
			this->textBoxMiddleName->Name = L"textBoxMiddleName";
			this->textBoxMiddleName->Size = System::Drawing::Size(235, 20);
			this->textBoxMiddleName->TabIndex = 6;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(24, 95);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Отчество";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(101, 66);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(235, 20);
			this->textBoxName->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 69);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Имя";
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Location = System::Drawing::Point(101, 40);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(235, 20);
			this->textBoxSurname->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 43);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Фамилия";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 17);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(197, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Добавление информации о студенте:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridViewStudentList);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->comboBoxGroupGroups);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->comboBoxNapravlenieGroups);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->comboBoxKafedriGroups);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->comboBoxFakultetGroups);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->buttonGroups);
			this->tabPage2->Controls->Add(this->buttonNapravlenia);
			this->tabPage2->Controls->Add(this->buttonKafedri);
			this->tabPage2->Controls->Add(this->buttonFakultet);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(919, 518);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Академические группы";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridViewStudentList
			// 
			this->dataGridViewStudentList->AllowUserToAddRows = false;
			this->dataGridViewStudentList->AllowUserToDeleteRows = false;
			this->dataGridViewStudentList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudentList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridViewStudentList->Location = System::Drawing::Point(18, 171);
			this->dataGridViewStudentList->Name = L"dataGridViewStudentList";
			this->dataGridViewStudentList->RowHeadersVisible = false;
			this->dataGridViewStudentList->Size = System::Drawing::Size(454, 284);
			this->dataGridViewStudentList->TabIndex = 17;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Фамилия";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Имя";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Отчество";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 145);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(137, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Список студентов группы";
			// 
			// comboBoxGroupGroups
			// 
			this->comboBoxGroupGroups->FormattingEnabled = true;
			this->comboBoxGroupGroups->Location = System::Drawing::Point(87, 105);
			this->comboBoxGroupGroups->Name = L"comboBoxGroupGroups";
			this->comboBoxGroupGroups->Size = System::Drawing::Size(121, 21);
			this->comboBoxGroupGroups->TabIndex = 11;
			this->comboBoxGroupGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxGroupGroups_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Группа";
			// 
			// comboBoxNapravlenieGroups
			// 
			this->comboBoxNapravlenieGroups->FormattingEnabled = true;
			this->comboBoxNapravlenieGroups->Location = System::Drawing::Point(573, 67);
			this->comboBoxNapravlenieGroups->Name = L"comboBoxNapravlenieGroups";
			this->comboBoxNapravlenieGroups->Size = System::Drawing::Size(121, 21);
			this->comboBoxNapravlenieGroups->TabIndex = 9;
			this->comboBoxNapravlenieGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxNapravlenieGroups_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(480, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Направление";
			// 
			// comboBoxKafedriGroups
			// 
			this->comboBoxKafedriGroups->FormattingEnabled = true;
			this->comboBoxKafedriGroups->Location = System::Drawing::Point(314, 67);
			this->comboBoxKafedriGroups->Name = L"comboBoxKafedriGroups";
			this->comboBoxKafedriGroups->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedriGroups->TabIndex = 7;
			this->comboBoxKafedriGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedriGroups_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(245, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Кафедра";
			// 
			// comboBoxFakultetGroups
			// 
			this->comboBoxFakultetGroups->FormattingEnabled = true;
			this->comboBoxFakultetGroups->Location = System::Drawing::Point(87, 67);
			this->comboBoxFakultetGroups->Name = L"comboBoxFakultetGroups";
			this->comboBoxFakultetGroups->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetGroups->TabIndex = 5;
			this->comboBoxFakultetGroups->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetGroups_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Факультет";
			// 
			// buttonGroups
			// 
			this->buttonGroups->Location = System::Drawing::Point(414, 16);
			this->buttonGroups->Name = L"buttonGroups";
			this->buttonGroups->Size = System::Drawing::Size(126, 35);
			this->buttonGroups->TabIndex = 3;
			this->buttonGroups->Text = L"Группы...";
			this->buttonGroups->UseVisualStyleBackColor = true;
			this->buttonGroups->Click += gcnew System::EventHandler(this, &Form1::buttonGroups_Click);
			// 
			// buttonNapravlenia
			// 
			this->buttonNapravlenia->Location = System::Drawing::Point(282, 16);
			this->buttonNapravlenia->Name = L"buttonNapravlenia";
			this->buttonNapravlenia->Size = System::Drawing::Size(126, 35);
			this->buttonNapravlenia->TabIndex = 2;
			this->buttonNapravlenia->Text = L"Направления...";
			this->buttonNapravlenia->UseVisualStyleBackColor = true;
			this->buttonNapravlenia->Click += gcnew System::EventHandler(this, &Form1::buttonNapravlenia_Click);
			// 
			// buttonKafedri
			// 
			this->buttonKafedri->Location = System::Drawing::Point(150, 16);
			this->buttonKafedri->Name = L"buttonKafedri";
			this->buttonKafedri->Size = System::Drawing::Size(126, 35);
			this->buttonKafedri->TabIndex = 1;
			this->buttonKafedri->Text = L"Кафедры...";
			this->buttonKafedri->UseVisualStyleBackColor = true;
			this->buttonKafedri->Click += gcnew System::EventHandler(this, &Form1::buttonKafedri_Click);
			// 
			// buttonFakultet
			// 
			this->buttonFakultet->Location = System::Drawing::Point(18, 16);
			this->buttonFakultet->Name = L"buttonFakultet";
			this->buttonFakultet->Size = System::Drawing::Size(126, 35);
			this->buttonFakultet->TabIndex = 0;
			this->buttonFakultet->Text = L"Факультеты...";
			this->buttonFakultet->UseVisualStyleBackColor = true;
			this->buttonFakultet->Click += gcnew System::EventHandler(this, &Form1::buttonFakultet_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridViewPreps);
			this->tabPage3->Controls->Add(this->buttonPrepAdd);
			this->tabPage3->Controls->Add(this->comboBoxKafedraPrep);
			this->tabPage3->Controls->Add(this->label28);
			this->tabPage3->Controls->Add(this->label27);
			this->tabPage3->Controls->Add(this->textBoxUchStepPrep);
			this->tabPage3->Controls->Add(this->label26);
			this->tabPage3->Controls->Add(this->textBoxUchZvaniePrep);
			this->tabPage3->Controls->Add(this->textBoxFioPrep);
			this->tabPage3->Controls->Add(this->label25);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(919, 518);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Преподаватели";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridViewPreps
			// 
			this->dataGridViewPreps->AllowUserToAddRows = false;
			this->dataGridViewPreps->AllowUserToDeleteRows = false;
			this->dataGridViewPreps->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPreps->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->Column9, this->Column10
			});
			this->dataGridViewPreps->Location = System::Drawing::Point(22, 139);
			this->dataGridViewPreps->Name = L"dataGridViewPreps";
			this->dataGridViewPreps->RowHeadersVisible = false;
			this->dataGridViewPreps->Size = System::Drawing::Size(889, 371);
			this->dataGridViewPreps->TabIndex = 18;
			this->dataGridViewPreps->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridViewPreps_CellClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"ФИО";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Кафедра";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Ученое звание";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Ученая степень";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"";
			this->Column10->Name = L"Column10";
			// 
			// buttonPrepAdd
			// 
			this->buttonPrepAdd->Location = System::Drawing::Point(428, 43);
			this->buttonPrepAdd->Name = L"buttonPrepAdd";
			this->buttonPrepAdd->Size = System::Drawing::Size(75, 23);
			this->buttonPrepAdd->TabIndex = 8;
			this->buttonPrepAdd->Text = L"Добавить";
			this->buttonPrepAdd->UseVisualStyleBackColor = true;
			this->buttonPrepAdd->Click += gcnew System::EventHandler(this, &Form1::buttonPrepAdd_Click);
			// 
			// comboBoxKafedraPrep
			// 
			this->comboBoxKafedraPrep->FormattingEnabled = true;
			this->comboBoxKafedraPrep->Location = System::Drawing::Point(130, 46);
			this->comboBoxKafedraPrep->Name = L"comboBoxKafedraPrep";
			this->comboBoxKafedraPrep->Size = System::Drawing::Size(246, 21);
			this->comboBoxKafedraPrep->TabIndex = 7;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(19, 49);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(52, 13);
			this->label28->TabIndex = 6;
			this->label28->Text = L"Кафедра";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(19, 106);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(88, 13);
			this->label27->TabIndex = 5;
			this->label27->Text = L"Ученая степень";
			// 
			// textBoxUchStepPrep
			// 
			this->textBoxUchStepPrep->Location = System::Drawing::Point(130, 103);
			this->textBoxUchStepPrep->Name = L"textBoxUchStepPrep";
			this->textBoxUchStepPrep->Size = System::Drawing::Size(246, 20);
			this->textBoxUchStepPrep->TabIndex = 4;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(19, 77);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(83, 13);
			this->label26->TabIndex = 3;
			this->label26->Text = L"Ученое звание";
			// 
			// textBoxUchZvaniePrep
			// 
			this->textBoxUchZvaniePrep->Location = System::Drawing::Point(130, 77);
			this->textBoxUchZvaniePrep->Name = L"textBoxUchZvaniePrep";
			this->textBoxUchZvaniePrep->Size = System::Drawing::Size(246, 20);
			this->textBoxUchZvaniePrep->TabIndex = 2;
			// 
			// textBoxFioPrep
			// 
			this->textBoxFioPrep->Location = System::Drawing::Point(123, 12);
			this->textBoxFioPrep->Name = L"textBoxFioPrep";
			this->textBoxFioPrep->Size = System::Drawing::Size(253, 20);
			this->textBoxFioPrep->TabIndex = 1;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(19, 19);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(34, 13);
			this->label25->TabIndex = 0;
			this->label25->Text = L"ФИО";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->groupBox3);
			this->tabPage4->Controls->Add(this->groupBox2);
			this->tabPage4->Controls->Add(this->groupBox1);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(919, 518);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Учебные планы";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->buttonDisciplinShow);
			this->groupBox3->Controls->Add(this->comboBoxSemestrDisciplinShow);
			this->groupBox3->Controls->Add(this->label50);
			this->groupBox3->Controls->Add(this->comboBoxKursDisciplinShow);
			this->groupBox3->Controls->Add(this->label51);
			this->groupBox3->Controls->Add(this->comboBoxNaprDisciplinShow);
			this->groupBox3->Controls->Add(this->label49);
			this->groupBox3->Controls->Add(this->comboBoxKafedriDisciplinShow);
			this->groupBox3->Controls->Add(this->label48);
			this->groupBox3->Controls->Add(this->comboBoxFakultetDisciplinShow);
			this->groupBox3->Controls->Add(this->label47);
			this->groupBox3->Location = System::Drawing::Point(8, 348);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(903, 162);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Перечень изучаемых дисциплин";
			// 
			// buttonDisciplinShow
			// 
			this->buttonDisciplinShow->Location = System::Drawing::Point(277, 83);
			this->buttonDisciplinShow->Name = L"buttonDisciplinShow";
			this->buttonDisciplinShow->Size = System::Drawing::Size(163, 23);
			this->buttonDisciplinShow->TabIndex = 14;
			this->buttonDisciplinShow->Text = L"Показать дисциплины";
			this->buttonDisciplinShow->UseVisualStyleBackColor = true;
			this->buttonDisciplinShow->Click += gcnew System::EventHandler(this, &Form1::buttonDisciplinShow_Click);
			// 
			// comboBoxSemestrDisciplinShow
			// 
			this->comboBoxSemestrDisciplinShow->FormattingEnabled = true;
			this->comboBoxSemestrDisciplinShow->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxSemestrDisciplinShow->Location = System::Drawing::Point(349, 53);
			this->comboBoxSemestrDisciplinShow->Name = L"comboBoxSemestrDisciplinShow";
			this->comboBoxSemestrDisciplinShow->Size = System::Drawing::Size(66, 21);
			this->comboBoxSemestrDisciplinShow->TabIndex = 13;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(286, 56);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(51, 13);
			this->label50->TabIndex = 12;
			this->label50->Text = L"Семестр";
			// 
			// comboBoxKursDisciplinShow
			// 
			this->comboBoxKursDisciplinShow->FormattingEnabled = true;
			this->comboBoxKursDisciplinShow->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxKursDisciplinShow->Location = System::Drawing::Point(349, 26);
			this->comboBoxKursDisciplinShow->Name = L"comboBoxKursDisciplinShow";
			this->comboBoxKursDisciplinShow->Size = System::Drawing::Size(66, 21);
			this->comboBoxKursDisciplinShow->TabIndex = 11;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(286, 29);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(31, 13);
			this->label51->TabIndex = 10;
			this->label51->Text = L"Курс";
			// 
			// comboBoxNaprDisciplinShow
			// 
			this->comboBoxNaprDisciplinShow->FormattingEnabled = true;
			this->comboBoxNaprDisciplinShow->Location = System::Drawing::Point(116, 80);
			this->comboBoxNaprDisciplinShow->Name = L"comboBoxNaprDisciplinShow";
			this->comboBoxNaprDisciplinShow->Size = System::Drawing::Size(121, 21);
			this->comboBoxNaprDisciplinShow->TabIndex = 6;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(20, 83);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(75, 13);
			this->label49->TabIndex = 5;
			this->label49->Text = L"Направление";
			// 
			// comboBoxKafedriDisciplinShow
			// 
			this->comboBoxKafedriDisciplinShow->FormattingEnabled = true;
			this->comboBoxKafedriDisciplinShow->Location = System::Drawing::Point(116, 53);
			this->comboBoxKafedriDisciplinShow->Name = L"comboBoxKafedriDisciplinShow";
			this->comboBoxKafedriDisciplinShow->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedriDisciplinShow->TabIndex = 4;
			this->comboBoxKafedriDisciplinShow->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedriDisciplinShow_SelectedIndexChanged);
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(20, 56);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(52, 13);
			this->label48->TabIndex = 3;
			this->label48->Text = L"Кафедра";
			// 
			// comboBoxFakultetDisciplinShow
			// 
			this->comboBoxFakultetDisciplinShow->FormattingEnabled = true;
			this->comboBoxFakultetDisciplinShow->Location = System::Drawing::Point(116, 26);
			this->comboBoxFakultetDisciplinShow->Name = L"comboBoxFakultetDisciplinShow";
			this->comboBoxFakultetDisciplinShow->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetDisciplinShow->TabIndex = 2;
			this->comboBoxFakultetDisciplinShow->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetDisciplinShow_SelectedIndexChanged);
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(20, 29);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(63, 13);
			this->label47->TabIndex = 0;
			this->label47->Text = L"Факультет";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBoxTeacher);
			this->groupBox2->Controls->Add(this->label46);
			this->groupBox2->Controls->Add(this->numericUpDownLabTime);
			this->groupBox2->Controls->Add(this->label45);
			this->groupBox2->Controls->Add(this->numericUpDownPractTime);
			this->groupBox2->Controls->Add(this->label44);
			this->groupBox2->Controls->Add(this->numericUpDownLectionTime);
			this->groupBox2->Controls->Add(this->label43);
			this->groupBox2->Controls->Add(this->numericUpDownTotalTime);
			this->groupBox2->Controls->Add(this->label42);
			this->groupBox2->Controls->Add(this->checkBoxKursProj);
			this->groupBox2->Controls->Add(this->checkBoxExam);
			this->groupBox2->Controls->Add(this->checkBoxZachet);
			this->groupBox2->Controls->Add(this->label41);
			this->groupBox2->Controls->Add(this->comboBoxDisciplin);
			this->groupBox2->Controls->Add(this->buttonDisciplinAdd);
			this->groupBox2->Controls->Add(this->label35);
			this->groupBox2->Controls->Add(this->comboBoxSemestrDisciplinAdd);
			this->groupBox2->Controls->Add(this->label36);
			this->groupBox2->Controls->Add(this->comboBoxKursDisciplinAdd);
			this->groupBox2->Controls->Add(this->label37);
			this->groupBox2->Controls->Add(this->comboBoxNapravlenieDisciplinAdd);
			this->groupBox2->Controls->Add(this->label38);
			this->groupBox2->Controls->Add(this->comboBoxKafedraDisciplinAdd);
			this->groupBox2->Controls->Add(this->label39);
			this->groupBox2->Controls->Add(this->comboBoxFakultetDisciplinAdd);
			this->groupBox2->Controls->Add(this->label40);
			this->groupBox2->Location = System::Drawing::Point(8, 137);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(903, 205);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Учебные дисциплины";
			// 
			// comboBoxTeacher
			// 
			this->comboBoxTeacher->FormattingEnabled = true;
			this->comboBoxTeacher->Location = System::Drawing::Point(377, 137);
			this->comboBoxTeacher->Name = L"comboBoxTeacher";
			this->comboBoxTeacher->Size = System::Drawing::Size(194, 21);
			this->comboBoxTeacher->TabIndex = 27;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(263, 140);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(86, 13);
			this->label46->TabIndex = 26;
			this->label46->Text = L"Преподаватель";
			// 
			// numericUpDownLabTime
			// 
			this->numericUpDownLabTime->Location = System::Drawing::Point(419, 110);
			this->numericUpDownLabTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownLabTime->Name = L"numericUpDownLabTime";
			this->numericUpDownLabTime->Size = System::Drawing::Size(62, 20);
			this->numericUpDownLabTime->TabIndex = 25;
			this->numericUpDownLabTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(260, 112);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(137, 13);
			this->label45->TabIndex = 24;
			this->label45->Text = L"На лабораторные работы";
			// 
			// numericUpDownPractTime
			// 
			this->numericUpDownPractTime->Location = System::Drawing::Point(419, 83);
			this->numericUpDownPractTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownPractTime->Name = L"numericUpDownPractTime";
			this->numericUpDownPractTime->Size = System::Drawing::Size(62, 20);
			this->numericUpDownPractTime->TabIndex = 23;
			this->numericUpDownPractTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(260, 85);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(138, 13);
			this->label44->TabIndex = 22;
			this->label44->Text = L"На практические занятия";
			// 
			// numericUpDownLectionTime
			// 
			this->numericUpDownLectionTime->Location = System::Drawing::Point(419, 56);
			this->numericUpDownLectionTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownLectionTime->Name = L"numericUpDownLectionTime";
			this->numericUpDownLectionTime->Size = System::Drawing::Size(62, 20);
			this->numericUpDownLectionTime->TabIndex = 21;
			this->numericUpDownLectionTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(260, 58);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(60, 13);
			this->label43->TabIndex = 20;
			this->label43->Text = L"На лекции";
			// 
			// numericUpDownTotalTime
			// 
			this->numericUpDownTotalTime->Location = System::Drawing::Point(419, 29);
			this->numericUpDownTotalTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownTotalTime->Name = L"numericUpDownTotalTime";
			this->numericUpDownTotalTime->Size = System::Drawing::Size(62, 20);
			this->numericUpDownTotalTime->TabIndex = 19;
			this->numericUpDownTotalTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(260, 31);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(135, 13);
			this->label42->TabIndex = 18;
			this->label42->Text = L"Общее количество часов";
			// 
			// checkBoxKursProj
			// 
			this->checkBoxKursProj->AutoSize = true;
			this->checkBoxKursProj->Location = System::Drawing::Point(263, 170);
			this->checkBoxKursProj->Name = L"checkBoxKursProj";
			this->checkBoxKursProj->Size = System::Drawing::Size(152, 17);
			this->checkBoxKursProj->TabIndex = 17;
			this->checkBoxKursProj->Text = L"Курсовая работа/проект";
			this->checkBoxKursProj->UseVisualStyleBackColor = true;
			// 
			// checkBoxExam
			// 
			this->checkBoxExam->AutoSize = true;
			this->checkBoxExam->Location = System::Drawing::Point(186, 169);
			this->checkBoxExam->Name = L"checkBoxExam";
			this->checkBoxExam->Size = System::Drawing::Size(71, 17);
			this->checkBoxExam->TabIndex = 16;
			this->checkBoxExam->Text = L"Экзамен";
			this->checkBoxExam->UseVisualStyleBackColor = true;
			// 
			// checkBoxZachet
			// 
			this->checkBoxZachet->AutoSize = true;
			this->checkBoxZachet->Location = System::Drawing::Point(120, 169);
			this->checkBoxZachet->Name = L"checkBoxZachet";
			this->checkBoxZachet->Size = System::Drawing::Size(55, 17);
			this->checkBoxZachet->TabIndex = 15;
			this->checkBoxZachet->Text = L"Зачет";
			this->checkBoxZachet->UseVisualStyleBackColor = true;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(20, 170);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(94, 13);
			this->label41->TabIndex = 14;
			this->label41->Text = L"Форма контроля";
			// 
			// comboBoxDisciplin
			// 
			this->comboBoxDisciplin->FormattingEnabled = true;
			this->comboBoxDisciplin->Location = System::Drawing::Point(116, 139);
			this->comboBoxDisciplin->Name = L"comboBoxDisciplin";
			this->comboBoxDisciplin->Size = System::Drawing::Size(121, 21);
			this->comboBoxDisciplin->TabIndex = 13;
			// 
			// buttonDisciplinAdd
			// 
			this->buttonDisciplinAdd->Location = System::Drawing::Point(593, 135);
			this->buttonDisciplinAdd->Name = L"buttonDisciplinAdd";
			this->buttonDisciplinAdd->Size = System::Drawing::Size(95, 29);
			this->buttonDisciplinAdd->TabIndex = 12;
			this->buttonDisciplinAdd->Text = L"Добавить";
			this->buttonDisciplinAdd->UseVisualStyleBackColor = true;
			this->buttonDisciplinAdd->Click += gcnew System::EventHandler(this, &Form1::buttonDisciplinAdd_Click);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(17, 142);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(70, 13);
			this->label35->TabIndex = 10;
			this->label35->Text = L"Дисциплина";
			// 
			// comboBoxSemestrDisciplinAdd
			// 
			this->comboBoxSemestrDisciplinAdd->FormattingEnabled = true;
			this->comboBoxSemestrDisciplinAdd->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxSemestrDisciplinAdd->Location = System::Drawing::Point(186, 109);
			this->comboBoxSemestrDisciplinAdd->Name = L"comboBoxSemestrDisciplinAdd";
			this->comboBoxSemestrDisciplinAdd->Size = System::Drawing::Size(51, 21);
			this->comboBoxSemestrDisciplinAdd->TabIndex = 9;
			this->comboBoxSemestrDisciplinAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxSemestrDisciplinAdd_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(129, 112);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(51, 13);
			this->label36->TabIndex = 8;
			this->label36->Text = L"Семестр";
			// 
			// comboBoxKursDisciplinAdd
			// 
			this->comboBoxKursDisciplinAdd->FormattingEnabled = true;
			this->comboBoxKursDisciplinAdd->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxKursDisciplinAdd->Location = System::Drawing::Point(54, 109);
			this->comboBoxKursDisciplinAdd->Name = L"comboBoxKursDisciplinAdd";
			this->comboBoxKursDisciplinAdd->Size = System::Drawing::Size(53, 21);
			this->comboBoxKursDisciplinAdd->TabIndex = 7;
			this->comboBoxKursDisciplinAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKursDisciplinAdd_SelectedIndexChanged);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(17, 112);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(31, 13);
			this->label37->TabIndex = 6;
			this->label37->Text = L"Курс";
			// 
			// comboBoxNapravlenieDisciplinAdd
			// 
			this->comboBoxNapravlenieDisciplinAdd->FormattingEnabled = true;
			this->comboBoxNapravlenieDisciplinAdd->Location = System::Drawing::Point(116, 82);
			this->comboBoxNapravlenieDisciplinAdd->Name = L"comboBoxNapravlenieDisciplinAdd";
			this->comboBoxNapravlenieDisciplinAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxNapravlenieDisciplinAdd->TabIndex = 5;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(17, 85);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(75, 13);
			this->label38->TabIndex = 4;
			this->label38->Text = L"Направление";
			// 
			// comboBoxKafedraDisciplinAdd
			// 
			this->comboBoxKafedraDisciplinAdd->FormattingEnabled = true;
			this->comboBoxKafedraDisciplinAdd->Location = System::Drawing::Point(116, 55);
			this->comboBoxKafedraDisciplinAdd->Name = L"comboBoxKafedraDisciplinAdd";
			this->comboBoxKafedraDisciplinAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedraDisciplinAdd->TabIndex = 3;
			this->comboBoxKafedraDisciplinAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedraDisciplinAdd_SelectedIndexChanged);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(17, 58);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(52, 13);
			this->label39->TabIndex = 2;
			this->label39->Text = L"Кафедра";
			// 
			// comboBoxFakultetDisciplinAdd
			// 
			this->comboBoxFakultetDisciplinAdd->FormattingEnabled = true;
			this->comboBoxFakultetDisciplinAdd->Location = System::Drawing::Point(116, 28);
			this->comboBoxFakultetDisciplinAdd->Name = L"comboBoxFakultetDisciplinAdd";
			this->comboBoxFakultetDisciplinAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetDisciplinAdd->TabIndex = 1;
			this->comboBoxFakultetDisciplinAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetDisciplinAdd_SelectedIndexChanged);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(17, 31);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(63, 13);
			this->label40->TabIndex = 0;
			this->label40->Text = L"Факультет";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonPlanAdd);
			this->groupBox1->Controls->Add(this->textBoxDisciplPlanAdd);
			this->groupBox1->Controls->Add(this->label34);
			this->groupBox1->Controls->Add(this->comboBoxSemestrPlanAdd);
			this->groupBox1->Controls->Add(this->label33);
			this->groupBox1->Controls->Add(this->comboBoxKursPlanAdd);
			this->groupBox1->Controls->Add(this->label32);
			this->groupBox1->Controls->Add(this->comboBoxNapravleniePlanAdd);
			this->groupBox1->Controls->Add(this->label31);
			this->groupBox1->Controls->Add(this->comboBoxKafedraPlanAdd);
			this->groupBox1->Controls->Add(this->label30);
			this->groupBox1->Controls->Add(this->comboBoxFakultetPlanAdd);
			this->groupBox1->Controls->Add(this->label29);
			this->groupBox1->Location = System::Drawing::Point(8, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(903, 119);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Учебные дисциплины";
			// 
			// buttonPlanAdd
			// 
			this->buttonPlanAdd->Location = System::Drawing::Point(579, 55);
			this->buttonPlanAdd->Name = L"buttonPlanAdd";
			this->buttonPlanAdd->Size = System::Drawing::Size(95, 29);
			this->buttonPlanAdd->TabIndex = 12;
			this->buttonPlanAdd->Text = L"Добавить";
			this->buttonPlanAdd->UseVisualStyleBackColor = true;
			this->buttonPlanAdd->Click += gcnew System::EventHandler(this, &Form1::buttonPlanAdd_Click);
			// 
			// textBoxDisciplPlanAdd
			// 
			this->textBoxDisciplPlanAdd->Location = System::Drawing::Point(364, 60);
			this->textBoxDisciplPlanAdd->Name = L"textBoxDisciplPlanAdd";
			this->textBoxDisciplPlanAdd->Size = System::Drawing::Size(195, 20);
			this->textBoxDisciplPlanAdd->TabIndex = 11;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(274, 63);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(70, 13);
			this->label34->TabIndex = 10;
			this->label34->Text = L"Дисциплина";
			// 
			// comboBoxSemestrPlanAdd
			// 
			this->comboBoxSemestrPlanAdd->FormattingEnabled = true;
			this->comboBoxSemestrPlanAdd->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxSemestrPlanAdd->Location = System::Drawing::Point(493, 28);
			this->comboBoxSemestrPlanAdd->Name = L"comboBoxSemestrPlanAdd";
			this->comboBoxSemestrPlanAdd->Size = System::Drawing::Size(66, 21);
			this->comboBoxSemestrPlanAdd->TabIndex = 9;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(430, 31);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(51, 13);
			this->label33->TabIndex = 8;
			this->label33->Text = L"Семестр";
			// 
			// comboBoxKursPlanAdd
			// 
			this->comboBoxKursPlanAdd->FormattingEnabled = true;
			this->comboBoxKursPlanAdd->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxKursPlanAdd->Location = System::Drawing::Point(337, 28);
			this->comboBoxKursPlanAdd->Name = L"comboBoxKursPlanAdd";
			this->comboBoxKursPlanAdd->Size = System::Drawing::Size(66, 21);
			this->comboBoxKursPlanAdd->TabIndex = 7;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(274, 31);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(31, 13);
			this->label32->TabIndex = 6;
			this->label32->Text = L"Курс";
			// 
			// comboBoxNapravleniePlanAdd
			// 
			this->comboBoxNapravleniePlanAdd->FormattingEnabled = true;
			this->comboBoxNapravleniePlanAdd->Location = System::Drawing::Point(116, 82);
			this->comboBoxNapravleniePlanAdd->Name = L"comboBoxNapravleniePlanAdd";
			this->comboBoxNapravleniePlanAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxNapravleniePlanAdd->TabIndex = 5;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(17, 85);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(75, 13);
			this->label31->TabIndex = 4;
			this->label31->Text = L"Направление";
			// 
			// comboBoxKafedraPlanAdd
			// 
			this->comboBoxKafedraPlanAdd->FormattingEnabled = true;
			this->comboBoxKafedraPlanAdd->Location = System::Drawing::Point(116, 55);
			this->comboBoxKafedraPlanAdd->Name = L"comboBoxKafedraPlanAdd";
			this->comboBoxKafedraPlanAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedraPlanAdd->TabIndex = 3;
			this->comboBoxKafedraPlanAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedraPlanAdd_SelectedIndexChanged);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(17, 58);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(52, 13);
			this->label30->TabIndex = 2;
			this->label30->Text = L"Кафедра";
			// 
			// comboBoxFakultetPlanAdd
			// 
			this->comboBoxFakultetPlanAdd->FormattingEnabled = true;
			this->comboBoxFakultetPlanAdd->Location = System::Drawing::Point(116, 28);
			this->comboBoxFakultetPlanAdd->Name = L"comboBoxFakultetPlanAdd";
			this->comboBoxFakultetPlanAdd->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetPlanAdd->TabIndex = 1;
			this->comboBoxFakultetPlanAdd->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetPlanAdd_SelectedIndexChanged);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(17, 31);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(63, 13);
			this->label29->TabIndex = 0;
			this->label29->Text = L"Факультет";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->dataGridViewExam);
			this->tabPage5->Controls->Add(this->buttonPrintVed);
			this->tabPage5->Controls->Add(this->dataGridViewAttestat);
			this->tabPage5->Controls->Add(this->groupBox4);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(919, 518);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Аттестационная ведомость";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// dataGridViewExam
			// 
			this->dataGridViewExam->AllowUserToAddRows = false;
			this->dataGridViewExam->AllowUserToDeleteRows = false;
			this->dataGridViewExam->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewExam->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn8,
					this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10, this->dataGridViewTextBoxColumn11
			});
			this->dataGridViewExam->Location = System::Drawing::Point(8, 119);
			this->dataGridViewExam->Name = L"dataGridViewExam";
			this->dataGridViewExam->RowHeadersVisible = false;
			this->dataGridViewExam->Size = System::Drawing::Size(390, 362);
			this->dataGridViewExam->TabIndex = 26;
			this->dataGridViewExam->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridViewExam_CellEndEdit);
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"№";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->ReadOnly = true;
			this->dataGridViewTextBoxColumn8->Width = 50;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"Фамилия И.О.";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->ReadOnly = true;
			this->dataGridViewTextBoxColumn9->Width = 120;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"Номер зачетки";
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn11
			// 
			this->dataGridViewTextBoxColumn11->HeaderText = L"Оценка";
			this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
			this->dataGridViewTextBoxColumn11->Width = 50;
			// 
			// buttonPrintVed
			// 
			this->buttonPrintVed->Location = System::Drawing::Point(359, 487);
			this->buttonPrintVed->Name = L"buttonPrintVed";
			this->buttonPrintVed->Size = System::Drawing::Size(181, 23);
			this->buttonPrintVed->TabIndex = 24;
			this->buttonPrintVed->Text = L"Печать";
			this->buttonPrintVed->UseVisualStyleBackColor = true;
			this->buttonPrintVed->Click += gcnew System::EventHandler(this, &Form1::buttonPrintVed_Click);
			// 
			// dataGridViewAttestat
			// 
			this->dataGridViewAttestat->AllowUserToAddRows = false;
			this->dataGridViewAttestat->AllowUserToDeleteRows = false;
			this->dataGridViewAttestat->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAttestat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(12) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6, this->Column13, this->Column18, this->dataGridViewTextBoxColumn7,
					this->Column11, this->Column19, this->Column14, this->Column15, this->Column16, this->Column17
			});
			this->dataGridViewAttestat->Location = System::Drawing::Point(8, 119);
			this->dataGridViewAttestat->Name = L"dataGridViewAttestat";
			this->dataGridViewAttestat->RowHeadersVisible = false;
			this->dataGridViewAttestat->Size = System::Drawing::Size(903, 362);
			this->dataGridViewAttestat->TabIndex = 19;
			this->dataGridViewAttestat->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridViewAttestat_CellEndEdit);
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"№";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 50;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Фамилия И.О.";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 120;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Номер зачетки";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"Атт1 (35б)";
			this->Column13->Name = L"Column13";
			this->Column13->Width = 50;
			// 
			// Column18
			// 
			this->Column18->HeaderText = L"Атт2 (35б)";
			this->Column18->Name = L"Column18";
			this->Column18->Width = 50;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Сам.работа (10б)";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 70;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Посещаем. (10б)";
			this->Column11->Name = L"Column11";
			this->Column11->Width = 70;
			// 
			// Column19
			// 
			this->Column19->HeaderText = L"∑";
			this->Column19->Name = L"Column19";
			this->Column19->Width = 50;
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"Реком. оценка";
			this->Column14->Name = L"Column14";
			this->Column14->Width = 70;
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"Баллы за экз. (20б)";
			this->Column15->Name = L"Column15";
			this->Column15->Width = 60;
			// 
			// Column16
			// 
			this->Column16->HeaderText = L"Сумма баллов";
			this->Column16->Name = L"Column16";
			this->Column16->Width = 70;
			// 
			// Column17
			// 
			this->Column17->HeaderText = L"Оценка (отл, хор, удов, неуд)";
			this->Column17->Name = L"Column17";
			this->Column17->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column17->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->buttonShowExam);
			this->groupBox4->Controls->Add(this->buttonShowAt);
			this->groupBox4->Controls->Add(this->comboBoxDisciplinVedomost);
			this->groupBox4->Controls->Add(this->label59);
			this->groupBox4->Controls->Add(this->comboBoxGroupVedomost);
			this->groupBox4->Controls->Add(this->label58);
			this->groupBox4->Controls->Add(this->comboBoxSemestrVedomost);
			this->groupBox4->Controls->Add(this->label56);
			this->groupBox4->Controls->Add(this->comboBoxKursVedomost);
			this->groupBox4->Controls->Add(this->label57);
			this->groupBox4->Controls->Add(this->comboBoxNapravlVedomost);
			this->groupBox4->Controls->Add(this->label52);
			this->groupBox4->Controls->Add(this->comboBoxKafedraVedomost);
			this->groupBox4->Controls->Add(this->label53);
			this->groupBox4->Controls->Add(this->comboBoxFakultetVedomost);
			this->groupBox4->Controls->Add(this->label54);
			this->groupBox4->Location = System::Drawing::Point(8, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(903, 110);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			// 
			// buttonShowExam
			// 
			this->buttonShowExam->Location = System::Drawing::Point(592, 52);
			this->buttonShowExam->Name = L"buttonShowExam";
			this->buttonShowExam->Size = System::Drawing::Size(181, 37);
			this->buttonShowExam->TabIndex = 25;
			this->buttonShowExam->Text = L"Показать экзаменационную ведомость";
			this->buttonShowExam->UseVisualStyleBackColor = true;
			this->buttonShowExam->Click += gcnew System::EventHandler(this, &Form1::buttonShowExam_Click);
			// 
			// buttonShowAt
			// 
			this->buttonShowAt->Location = System::Drawing::Point(592, 10);
			this->buttonShowAt->Name = L"buttonShowAt";
			this->buttonShowAt->Size = System::Drawing::Size(181, 37);
			this->buttonShowAt->TabIndex = 24;
			this->buttonShowAt->Text = L"Показать аттестационную ведомость";
			this->buttonShowAt->UseVisualStyleBackColor = true;
			this->buttonShowAt->Click += gcnew System::EventHandler(this, &Form1::buttonShowAt_Click);
			// 
			// comboBoxDisciplinVedomost
			// 
			this->comboBoxDisciplinVedomost->FormattingEnabled = true;
			this->comboBoxDisciplinVedomost->Location = System::Drawing::Point(324, 76);
			this->comboBoxDisciplinVedomost->Name = L"comboBoxDisciplinVedomost";
			this->comboBoxDisciplinVedomost->Size = System::Drawing::Size(121, 21);
			this->comboBoxDisciplinVedomost->TabIndex = 21;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(247, 79);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(70, 13);
			this->label59->TabIndex = 20;
			this->label59->Text = L"Дисциплина";
			// 
			// comboBoxGroupVedomost
			// 
			this->comboBoxGroupVedomost->FormattingEnabled = true;
			this->comboBoxGroupVedomost->Location = System::Drawing::Point(324, 19);
			this->comboBoxGroupVedomost->Name = L"comboBoxGroupVedomost";
			this->comboBoxGroupVedomost->Size = System::Drawing::Size(121, 21);
			this->comboBoxGroupVedomost->TabIndex = 19;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(247, 22);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(42, 13);
			this->label58->TabIndex = 18;
			this->label58->Text = L"Группа";
			// 
			// comboBoxSemestrVedomost
			// 
			this->comboBoxSemestrVedomost->FormattingEnabled = true;
			this->comboBoxSemestrVedomost->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxSemestrVedomost->Location = System::Drawing::Point(476, 49);
			this->comboBoxSemestrVedomost->Name = L"comboBoxSemestrVedomost";
			this->comboBoxSemestrVedomost->Size = System::Drawing::Size(66, 21);
			this->comboBoxSemestrVedomost->TabIndex = 17;
			this->comboBoxSemestrVedomost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxSemestrVedomost_SelectedIndexChanged);
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(417, 50);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(51, 13);
			this->label56->TabIndex = 16;
			this->label56->Text = L"Семестр";
			// 
			// comboBoxKursVedomost
			// 
			this->comboBoxKursVedomost->FormattingEnabled = true;
			this->comboBoxKursVedomost->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxKursVedomost->Location = System::Drawing::Point(324, 49);
			this->comboBoxKursVedomost->Name = L"comboBoxKursVedomost";
			this->comboBoxKursVedomost->Size = System::Drawing::Size(66, 21);
			this->comboBoxKursVedomost->TabIndex = 15;
			this->comboBoxKursVedomost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKursVedomost_SelectedIndexChanged);
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(247, 53);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(31, 13);
			this->label57->TabIndex = 14;
			this->label57->Text = L"Курс";
			// 
			// comboBoxNapravlVedomost
			// 
			this->comboBoxNapravlVedomost->FormattingEnabled = true;
			this->comboBoxNapravlVedomost->Location = System::Drawing::Point(110, 73);
			this->comboBoxNapravlVedomost->Name = L"comboBoxNapravlVedomost";
			this->comboBoxNapravlVedomost->Size = System::Drawing::Size(121, 21);
			this->comboBoxNapravlVedomost->TabIndex = 11;
			this->comboBoxNapravlVedomost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxNapravlVedomost_SelectedIndexChanged);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(11, 76);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(75, 13);
			this->label52->TabIndex = 10;
			this->label52->Text = L"Направление";
			// 
			// comboBoxKafedraVedomost
			// 
			this->comboBoxKafedraVedomost->FormattingEnabled = true;
			this->comboBoxKafedraVedomost->Location = System::Drawing::Point(110, 46);
			this->comboBoxKafedraVedomost->Name = L"comboBoxKafedraVedomost";
			this->comboBoxKafedraVedomost->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedraVedomost->TabIndex = 9;
			this->comboBoxKafedraVedomost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedraVedomost_SelectedIndexChanged);
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(11, 49);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(52, 13);
			this->label53->TabIndex = 8;
			this->label53->Text = L"Кафедра";
			// 
			// comboBoxFakultetVedomost
			// 
			this->comboBoxFakultetVedomost->FormattingEnabled = true;
			this->comboBoxFakultetVedomost->Location = System::Drawing::Point(110, 19);
			this->comboBoxFakultetVedomost->Name = L"comboBoxFakultetVedomost";
			this->comboBoxFakultetVedomost->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetVedomost->TabIndex = 7;
			this->comboBoxFakultetVedomost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetVedomost_SelectedIndexChanged);
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(11, 22);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(63, 13);
			this->label54->TabIndex = 6;
			this->label54->Text = L"Факультет";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->buttonPrintCl);
			this->tabPage6->Controls->Add(this->buttonPrintUsp);
			this->tabPage6->Controls->Add(this->label60);
			this->tabPage6->Controls->Add(this->label5);
			this->tabPage6->Controls->Add(this->dataGridViewDolg);
			this->tabPage6->Controls->Add(this->dataGridViewUsp);
			this->tabPage6->Controls->Add(this->groupBox5);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(919, 518);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Успеваемость студентов";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// buttonPrintCl
			// 
			this->buttonPrintCl->Location = System::Drawing::Point(759, 485);
			this->buttonPrintCl->Name = L"buttonPrintCl";
			this->buttonPrintCl->Size = System::Drawing::Size(75, 23);
			this->buttonPrintCl->TabIndex = 32;
			this->buttonPrintCl->Text = L"Печать";
			this->buttonPrintCl->UseVisualStyleBackColor = true;
			this->buttonPrintCl->Click += gcnew System::EventHandler(this, &Form1::buttonPrintCl_Click);
			// 
			// buttonPrintUsp
			// 
			this->buttonPrintUsp->Location = System::Drawing::Point(237, 485);
			this->buttonPrintUsp->Name = L"buttonPrintUsp";
			this->buttonPrintUsp->Size = System::Drawing::Size(75, 23);
			this->buttonPrintUsp->TabIndex = 31;
			this->buttonPrintUsp->Text = L"Печать";
			this->buttonPrintUsp->UseVisualStyleBackColor = true;
			this->buttonPrintUsp->Click += gcnew System::EventHandler(this, &Form1::buttonPrintUsp_Click);
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(27, 149);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(82, 13);
			this->label60->TabIndex = 30;
			this->label60->Text = L"Успеваемость";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(645, 151);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(123, 13);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Не закрывшие сессию";
			// 
			// dataGridViewDolg
			// 
			this->dataGridViewDolg->AllowUserToAddRows = false;
			this->dataGridViewDolg->AllowUserToDeleteRows = false;
			this->dataGridViewDolg->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDolg->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn16,
					this->dataGridViewTextBoxColumn17, this->dataGridViewTextBoxColumn18
			});
			this->dataGridViewDolg->Location = System::Drawing::Point(648, 168);
			this->dataGridViewDolg->Name = L"dataGridViewDolg";
			this->dataGridViewDolg->RowHeadersVisible = false;
			this->dataGridViewDolg->Size = System::Drawing::Size(268, 310);
			this->dataGridViewDolg->TabIndex = 28;
			// 
			// dataGridViewTextBoxColumn16
			// 
			this->dataGridViewTextBoxColumn16->HeaderText = L"№";
			this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
			this->dataGridViewTextBoxColumn16->ReadOnly = true;
			this->dataGridViewTextBoxColumn16->Width = 50;
			// 
			// dataGridViewTextBoxColumn17
			// 
			this->dataGridViewTextBoxColumn17->HeaderText = L"Фамилия И.О.";
			this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
			this->dataGridViewTextBoxColumn17->ReadOnly = true;
			this->dataGridViewTextBoxColumn17->Width = 120;
			// 
			// dataGridViewTextBoxColumn18
			// 
			this->dataGridViewTextBoxColumn18->HeaderText = L"Номер зачетки";
			this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
			this->dataGridViewTextBoxColumn18->ReadOnly = true;
			// 
			// dataGridViewUsp
			// 
			this->dataGridViewUsp->AllowUserToAddRows = false;
			this->dataGridViewUsp->AllowUserToDeleteRows = false;
			this->dataGridViewUsp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewUsp->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(12) {
				this->dataGridViewTextBoxColumn12,
					this->dataGridViewTextBoxColumn13, this->dataGridViewTextBoxColumn14, this->dataGridViewTextBoxColumn15, this->dataGridViewTextBoxColumn19,
					this->dataGridViewTextBoxColumn20, this->dataGridViewTextBoxColumn21, this->dataGridViewTextBoxColumn22, this->dataGridViewTextBoxColumn23,
					this->dataGridViewTextBoxColumn24, this->dataGridViewTextBoxColumn25, this->dataGridViewTextBoxColumn26
			});
			this->dataGridViewUsp->Location = System::Drawing::Point(17, 168);
			this->dataGridViewUsp->Name = L"dataGridViewUsp";
			this->dataGridViewUsp->RowHeadersVisible = false;
			this->dataGridViewUsp->Size = System::Drawing::Size(602, 310);
			this->dataGridViewUsp->TabIndex = 27;
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->HeaderText = L"№";
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			this->dataGridViewTextBoxColumn12->ReadOnly = true;
			this->dataGridViewTextBoxColumn12->Width = 50;
			// 
			// dataGridViewTextBoxColumn13
			// 
			this->dataGridViewTextBoxColumn13->HeaderText = L"Фамилия И.О.";
			this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
			this->dataGridViewTextBoxColumn13->ReadOnly = true;
			this->dataGridViewTextBoxColumn13->Width = 120;
			// 
			// dataGridViewTextBoxColumn14
			// 
			this->dataGridViewTextBoxColumn14->HeaderText = L"Номер зачетки";
			this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
			this->dataGridViewTextBoxColumn14->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn15
			// 
			this->dataGridViewTextBoxColumn15->HeaderText = L"1-1";
			this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
			this->dataGridViewTextBoxColumn15->Width = 50;
			// 
			// dataGridViewTextBoxColumn19
			// 
			this->dataGridViewTextBoxColumn19->HeaderText = L"1-2";
			this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
			this->dataGridViewTextBoxColumn19->Width = 50;
			// 
			// dataGridViewTextBoxColumn20
			// 
			this->dataGridViewTextBoxColumn20->HeaderText = L"2-1";
			this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
			this->dataGridViewTextBoxColumn20->Width = 50;
			// 
			// dataGridViewTextBoxColumn21
			// 
			this->dataGridViewTextBoxColumn21->HeaderText = L"2-2";
			this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
			this->dataGridViewTextBoxColumn21->Width = 50;
			// 
			// dataGridViewTextBoxColumn22
			// 
			this->dataGridViewTextBoxColumn22->HeaderText = L"3-1";
			this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
			this->dataGridViewTextBoxColumn22->Width = 50;
			// 
			// dataGridViewTextBoxColumn23
			// 
			this->dataGridViewTextBoxColumn23->HeaderText = L"3-2";
			this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
			this->dataGridViewTextBoxColumn23->Width = 50;
			// 
			// dataGridViewTextBoxColumn24
			// 
			this->dataGridViewTextBoxColumn24->HeaderText = L"4-1";
			this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
			this->dataGridViewTextBoxColumn24->Width = 50;
			// 
			// dataGridViewTextBoxColumn25
			// 
			this->dataGridViewTextBoxColumn25->HeaderText = L"4-2";
			this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
			this->dataGridViewTextBoxColumn25->Width = 50;
			// 
			// dataGridViewTextBoxColumn26
			// 
			this->dataGridViewTextBoxColumn26->HeaderText = L"Общий %";
			this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
			this->dataGridViewTextBoxColumn26->Width = 50;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->buttonShowUspevaemost);
			this->groupBox5->Controls->Add(this->comboBoxGroupUspevaemost);
			this->groupBox5->Controls->Add(this->label61);
			this->groupBox5->Controls->Add(this->comboBoxSemestrUspevaemost);
			this->groupBox5->Controls->Add(this->label62);
			this->groupBox5->Controls->Add(this->comboBoxKursUspevaemost);
			this->groupBox5->Controls->Add(this->label63);
			this->groupBox5->Controls->Add(this->comboBoxNaprUspevaemost);
			this->groupBox5->Controls->Add(this->label65);
			this->groupBox5->Controls->Add(this->comboBoxKafedraUspevaemost);
			this->groupBox5->Controls->Add(this->label66);
			this->groupBox5->Controls->Add(this->comboBoxFakultetUspevaemost);
			this->groupBox5->Controls->Add(this->label67);
			this->groupBox5->Location = System::Drawing::Point(3, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(903, 141);
			this->groupBox5->TabIndex = 1;
			this->groupBox5->TabStop = false;
			// 
			// buttonShowUspevaemost
			// 
			this->buttonShowUspevaemost->Location = System::Drawing::Point(263, 64);
			this->buttonShowUspevaemost->Name = L"buttonShowUspevaemost";
			this->buttonShowUspevaemost->Size = System::Drawing::Size(177, 37);
			this->buttonShowUspevaemost->TabIndex = 22;
			this->buttonShowUspevaemost->Text = L"Загрузить";
			this->buttonShowUspevaemost->UseVisualStyleBackColor = true;
			this->buttonShowUspevaemost->Click += gcnew System::EventHandler(this, &Form1::buttonShowUspevaemost_Click);
			// 
			// comboBoxGroupUspevaemost
			// 
			this->comboBoxGroupUspevaemost->FormattingEnabled = true;
			this->comboBoxGroupUspevaemost->Location = System::Drawing::Point(110, 100);
			this->comboBoxGroupUspevaemost->Name = L"comboBoxGroupUspevaemost";
			this->comboBoxGroupUspevaemost->Size = System::Drawing::Size(121, 21);
			this->comboBoxGroupUspevaemost->TabIndex = 19;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(11, 103);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(42, 13);
			this->label61->TabIndex = 18;
			this->label61->Text = L"Группа";
			// 
			// comboBoxSemestrUspevaemost
			// 
			this->comboBoxSemestrUspevaemost->FormattingEnabled = true;
			this->comboBoxSemestrUspevaemost->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->comboBoxSemestrUspevaemost->Location = System::Drawing::Point(489, 22);
			this->comboBoxSemestrUspevaemost->Name = L"comboBoxSemestrUspevaemost";
			this->comboBoxSemestrUspevaemost->Size = System::Drawing::Size(66, 21);
			this->comboBoxSemestrUspevaemost->TabIndex = 17;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(430, 23);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(51, 13);
			this->label62->TabIndex = 16;
			this->label62->Text = L"Семестр";
			// 
			// comboBoxKursUspevaemost
			// 
			this->comboBoxKursUspevaemost->FormattingEnabled = true;
			this->comboBoxKursUspevaemost->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBoxKursUspevaemost->Location = System::Drawing::Point(337, 22);
			this->comboBoxKursUspevaemost->Name = L"comboBoxKursUspevaemost";
			this->comboBoxKursUspevaemost->Size = System::Drawing::Size(66, 21);
			this->comboBoxKursUspevaemost->TabIndex = 15;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(260, 26);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(31, 13);
			this->label63->TabIndex = 14;
			this->label63->Text = L"Курс";
			// 
			// comboBoxNaprUspevaemost
			// 
			this->comboBoxNaprUspevaemost->FormattingEnabled = true;
			this->comboBoxNaprUspevaemost->Location = System::Drawing::Point(110, 73);
			this->comboBoxNaprUspevaemost->Name = L"comboBoxNaprUspevaemost";
			this->comboBoxNaprUspevaemost->Size = System::Drawing::Size(121, 21);
			this->comboBoxNaprUspevaemost->TabIndex = 11;
			this->comboBoxNaprUspevaemost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxNaprUspevaemost_SelectedIndexChanged);
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(11, 76);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(75, 13);
			this->label65->TabIndex = 10;
			this->label65->Text = L"Направление";
			// 
			// comboBoxKafedraUspevaemost
			// 
			this->comboBoxKafedraUspevaemost->FormattingEnabled = true;
			this->comboBoxKafedraUspevaemost->Location = System::Drawing::Point(110, 46);
			this->comboBoxKafedraUspevaemost->Name = L"comboBoxKafedraUspevaemost";
			this->comboBoxKafedraUspevaemost->Size = System::Drawing::Size(121, 21);
			this->comboBoxKafedraUspevaemost->TabIndex = 9;
			this->comboBoxKafedraUspevaemost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxKafedraUspevaemost_SelectedIndexChanged);
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(11, 49);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(52, 13);
			this->label66->TabIndex = 8;
			this->label66->Text = L"Кафедра";
			// 
			// comboBoxFakultetUspevaemost
			// 
			this->comboBoxFakultetUspevaemost->FormattingEnabled = true;
			this->comboBoxFakultetUspevaemost->Location = System::Drawing::Point(110, 19);
			this->comboBoxFakultetUspevaemost->Name = L"comboBoxFakultetUspevaemost";
			this->comboBoxFakultetUspevaemost->Size = System::Drawing::Size(121, 21);
			this->comboBoxFakultetUspevaemost->TabIndex = 7;
			this->comboBoxFakultetUspevaemost->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxFakultetUspevaemost_SelectedIndexChanged);
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(11, 22);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(63, 13);
			this->label67->TabIndex = 6;
			this->label67->Text = L"Факультет";
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->buttonAddUser);
			this->tabPage7->Controls->Add(this->label68);
			this->tabPage7->Controls->Add(this->radioButtonPreps);
			this->tabPage7->Controls->Add(this->radioButtonStudent);
			this->tabPage7->Controls->Add(this->comboBoxPrepsLogin);
			this->tabPage7->Controls->Add(this->comboBoxStudentsLogin);
			this->tabPage7->Controls->Add(this->checkBoxAccess);
			this->tabPage7->Controls->Add(this->textBoxPass);
			this->tabPage7->Controls->Add(this->label64);
			this->tabPage7->Controls->Add(this->textBoxLogin);
			this->tabPage7->Controls->Add(this->label55);
			this->tabPage7->Controls->Add(this->dataGridViewLogin);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Size = System::Drawing::Size(919, 518);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Права доступа";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// buttonAddUser
			// 
			this->buttonAddUser->Location = System::Drawing::Point(711, 53);
			this->buttonAddUser->Name = L"buttonAddUser";
			this->buttonAddUser->Size = System::Drawing::Size(165, 35);
			this->buttonAddUser->TabIndex = 48;
			this->buttonAddUser->Text = L"Добавить пользователя";
			this->buttonAddUser->UseVisualStyleBackColor = true;
			this->buttonAddUser->Click += gcnew System::EventHandler(this, &Form1::buttonAddUser_Click);
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(310, 26);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(66, 13);
			this->label68->TabIndex = 47;
			this->label68->Text = L"Привязка к";
			// 
			// radioButtonPreps
			// 
			this->radioButtonPreps->AutoSize = true;
			this->radioButtonPreps->Location = System::Drawing::Point(341, 71);
			this->radioButtonPreps->Name = L"radioButtonPreps";
			this->radioButtonPreps->Size = System::Drawing::Size(106, 17);
			this->radioButtonPreps->TabIndex = 46;
			this->radioButtonPreps->TabStop = true;
			this->radioButtonPreps->Text = L"Преподавателю";
			this->radioButtonPreps->UseVisualStyleBackColor = true;
			// 
			// radioButtonStudent
			// 
			this->radioButtonStudent->AutoSize = true;
			this->radioButtonStudent->Location = System::Drawing::Point(341, 48);
			this->radioButtonStudent->Name = L"radioButtonStudent";
			this->radioButtonStudent->Size = System::Drawing::Size(70, 17);
			this->radioButtonStudent->TabIndex = 45;
			this->radioButtonStudent->TabStop = true;
			this->radioButtonStudent->Text = L"Студенту";
			this->radioButtonStudent->UseVisualStyleBackColor = true;
			// 
			// comboBoxPrepsLogin
			// 
			this->comboBoxPrepsLogin->FormattingEnabled = true;
			this->comboBoxPrepsLogin->Location = System::Drawing::Point(464, 71);
			this->comboBoxPrepsLogin->Name = L"comboBoxPrepsLogin";
			this->comboBoxPrepsLogin->Size = System::Drawing::Size(192, 21);
			this->comboBoxPrepsLogin->TabIndex = 44;
			// 
			// comboBoxStudentsLogin
			// 
			this->comboBoxStudentsLogin->FormattingEnabled = true;
			this->comboBoxStudentsLogin->Location = System::Drawing::Point(464, 45);
			this->comboBoxStudentsLogin->Name = L"comboBoxStudentsLogin";
			this->comboBoxStudentsLogin->Size = System::Drawing::Size(192, 21);
			this->comboBoxStudentsLogin->TabIndex = 43;
			// 
			// checkBoxAccess
			// 
			this->checkBoxAccess->AutoSize = true;
			this->checkBoxAccess->Location = System::Drawing::Point(84, 86);
			this->checkBoxAccess->Name = L"checkBoxAccess";
			this->checkBoxAccess->Size = System::Drawing::Size(207, 17);
			this->checkBoxAccess->TabIndex = 42;
			this->checkBoxAccess->Text = L"Права на запись и редактирование";
			this->checkBoxAccess->UseVisualStyleBackColor = true;
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(84, 50);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->Size = System::Drawing::Size(100, 20);
			this->textBoxPass->TabIndex = 41;
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(29, 53);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(45, 13);
			this->label64->TabIndex = 40;
			this->label64->Text = L"Пароль";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(84, 24);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 20);
			this->textBoxLogin->TabIndex = 39;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(29, 27);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(38, 13);
			this->label55->TabIndex = 38;
			this->label55->Text = L"Логин";
			// 
			// dataGridViewLogin
			// 
			this->dataGridViewLogin->AllowUserToAddRows = false;
			this->dataGridViewLogin->AllowUserToDeleteRows = false;
			this->dataGridViewLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewLogin->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLogin->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn27,
					this->dataGridViewTextBoxColumn28, this->dataGridViewTextBoxColumn29, this->dataGridViewTextBoxColumn30, this->dataGridViewButtonColumn1
			});
			this->dataGridViewLogin->Location = System::Drawing::Point(8, 150);
			this->dataGridViewLogin->Name = L"dataGridViewLogin";
			this->dataGridViewLogin->RowHeadersVisible = false;
			this->dataGridViewLogin->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewLogin->Size = System::Drawing::Size(743, 360);
			this->dataGridViewLogin->TabIndex = 37;
			this->dataGridViewLogin->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridViewLogin_CellClick);
			// 
			// dataGridViewTextBoxColumn27
			// 
			this->dataGridViewTextBoxColumn27->HeaderText = L"Логин";
			this->dataGridViewTextBoxColumn27->Name = L"dataGridViewTextBoxColumn27";
			this->dataGridViewTextBoxColumn27->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn28
			// 
			this->dataGridViewTextBoxColumn28->HeaderText = L"Пароль";
			this->dataGridViewTextBoxColumn28->Name = L"dataGridViewTextBoxColumn28";
			this->dataGridViewTextBoxColumn28->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn29
			// 
			this->dataGridViewTextBoxColumn29->HeaderText = L"Пользователь";
			this->dataGridViewTextBoxColumn29->Name = L"dataGridViewTextBoxColumn29";
			this->dataGridViewTextBoxColumn29->ReadOnly = true;
			this->dataGridViewTextBoxColumn29->Width = 300;
			// 
			// dataGridViewTextBoxColumn30
			// 
			this->dataGridViewTextBoxColumn30->HeaderText = L"Права доступа";
			this->dataGridViewTextBoxColumn30->Name = L"dataGridViewTextBoxColumn30";
			this->dataGridViewTextBoxColumn30->ReadOnly = true;
			// 
			// dataGridViewButtonColumn1
			// 
			this->dataGridViewButtonColumn1->HeaderText = L"";
			this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
			this->dataGridViewButtonColumn1->ReadOnly = true;
			// 
			// printDocument1
			// 
			this->printDocument1->BeginPrint += gcnew System::Drawing::Printing::PrintEventHandler(this, &Form1::printDocument1_BeginPrint);
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Form1::printDocument1_PrintPage);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 544);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Students";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStud))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownKurs))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudentList))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPreps))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLabTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownPractTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLectionTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownTotalTime))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewExam))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAttestat))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDolg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewUsp))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLogin))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void buttonAddStudent_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void buttonAdditional_Click(System::Object^  sender, System::EventArgs^  e) {
	FormAddition ^form = gcnew FormAddition(this, studentAdd, mysql);
	form->Show();
}
private: System::Void buttonFakultet_Click(System::Object^  sender, System::EventArgs^  e) {
	FormFakultets ^form = gcnew FormFakultets(this, mysql);
	form->Show();
}
private: System::Void buttonKafedri_Click(System::Object^  sender, System::EventArgs^  e) {
	FormKafedra ^form = gcnew FormKafedra(this, mysql);
	form->Show();
}
	System::Void comboBoxFakultetGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void buttonNapravlenia_Click(System::Object^  sender, System::EventArgs^  e) {
	FormNapravlenie ^form = gcnew FormNapravlenie(this, mysql);
	form->Show();
}
private: System::Void buttonGroups_Click(System::Object^  sender, System::EventArgs^  e) {
	FormGroups ^form = gcnew FormGroups(this, mysql);
	form->Show();
}
	System::Void buttonDisciplinShow_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonVedomostShow_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
	System::Void dataGridViewStud_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
}
	System::Void buttonSearch_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxNapravlenieGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxGroupGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedriGroups_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPrepAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void dataGridViewPreps_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	System::Void comboBoxFakultetPlanAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedraPlanAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxFakultetDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedraDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKursDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxSemestrDisciplinAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxFakultetDisciplinShow_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedriDisciplinShow_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPlanAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonDisciplinAdd_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxFakultetVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedraVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxNapravlVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKursVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxSemestrVedomost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonShowAt_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonShowExam_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPrintVed_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxFakultetUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedraUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxNaprUspevaemost_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonShowUspevaemost_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPrintUsp_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void buttonPrintCl_Click(System::Object^  sender, System::EventArgs^  e);	
	System::Void dataGridViewAttestat_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	System::Void dataGridViewExam_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

	System::Void printDocument1_BeginPrint(System::Object^  sender, System::Drawing::Printing::PrintEventArgs^  e);
	System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e);
	System::Void buttonAddUser_Click(System::Object^  sender, System::EventArgs^  e);

	System::Void dataGridViewLogin_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	exit(0);
}
	System::Void comboBoxFakultetStudent_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxKafedra_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void comboBoxSpecial_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}

