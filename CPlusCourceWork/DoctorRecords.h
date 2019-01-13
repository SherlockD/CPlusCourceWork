#include "MysqlWork.h"
#pragma once

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySqlWorkNameSpace;
	using namespace MySql::Data;

	/// <summary>
	/// —водка дл€ DoctorRecords
	/// </summary>
	public ref class DoctorRecords : public System::Windows::Forms::Form
	{
	public:
		DoctorRecords(String^ login)
		{
			InitializeComponent();
			user_login = login;
			//
			//TODO: добавьте код конструктора
			//
		}
	private: String^ user_login;
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DoctorRecords()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 61);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(406, 238);
			this->listBox1->TabIndex = 0;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 26);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &DoctorRecords::dateTimePicker1_ValueChanged);
			// 
			// DoctorRecords
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 326);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->listBox1);
			this->Name = L"DoctorRecords";
			this->Text = L"DoctorRecords";
			this->Load += gcnew System::EventHandler(this, &DoctorRecords::DoctorRecords_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		String^ getTimeStamp(DateTime date)
		{
			return date.ToString("yyyy-MM-dd");
		}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		listBox1->Items->Clear();
		String^ query = "SELECT * FROM records INNER JOIN doctors ON records.doctor_name = doctors.doctor_fio WHERE records.record_date ='" + getTimeStamp(dateTimePicker1->Value) + "' AND doctors.login = '"+user_login+"'";
		MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery(query);
		if (dataReader != nullptr) {
			while (dataReader->Read())
			{
				listBox1->Items->Add(getTimeStamp(dataReader->GetDateTime(3)) + "  " + dataReader->GetString(4));
			}
		}
	}
	private: System::Void DoctorRecords_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		listBox1->Items->Clear();
		String^ query = "SELECT * FROM records INNER JOIN doctors ON records.doctor_name = doctors.doctor_fio WHERE doctors.login = '" + user_login + "'";
		MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery(query);
		if (dataReader != nullptr) {
			while (dataReader->Read())
			{
				listBox1->Items->Add(getTimeStamp(dataReader->GetDateTime(3)) + "  " + dataReader->GetString(4));
			}
		}
	}
	};
}
