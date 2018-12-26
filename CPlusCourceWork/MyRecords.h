#pragma once
#include <string>
#include <stdio.h>
#include <msclr\marshal_cppstd.h>

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для MyRecords
	/// </summary>
	public ref class MyRecords : public System::Windows::Forms::Form
	{
	public:
		MyRecords(String^ login)
		{
			InitializeComponent();
			MySqlDataReader^ dataReader = ExecuteQuery("SELECT user,doctor_name,record_date,record_time FROM records WHERE user = '"+login+"'");
			if (dataReader != nullptr) {
				while (dataReader->Read())
				{
					ListViewItem^ newitem = gcnew ListViewItem();
					newitem->Text = dataReader->GetString(0);
					newitem->SubItems->Add(dataReader->GetString(1));
					newitem->SubItems->Add(dataReader->GetString(2));
					newitem->SubItems->Add(dataReader->GetString(3));
					listView1->Items->Add(newitem);
				}
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyRecords()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: String^ connectionInfo = "datasource=localhost;port=3306;username=root;password=admin;database=cpluscource";
	private: System::Windows::Forms::ColumnHeader^  user;
	private: System::Windows::Forms::ColumnHeader^  doctor;
	private: System::Windows::Forms::ColumnHeader^  date;
	private: System::Windows::Forms::ColumnHeader^  time;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;


		MySqlDataReader^ ExecuteQuery(String^ query)
		{
			MySqlConnection^ connection = gcnew MySqlConnection(connectionInfo);
			MySqlCommand^ connectionCmd = gcnew MySqlCommand(query, connection);
			MySqlDataReader^ dataReader;

			try
			{
				connection->Open();
				dataReader = connectionCmd->ExecuteReader();

				if (dataReader->HasRows)
				{
					return dataReader;
				}
				else
				{
					return nullptr;
				}

				dataReader->Close();
			}
			catch (Exception^ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->user = (gcnew System::Windows::Forms::ColumnHeader());
			this->doctor = (gcnew System::Windows::Forms::ColumnHeader());
			this->date = (gcnew System::Windows::Forms::ColumnHeader());
			this->time = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->user, this->doctor,
					this->date, this->time
			});
			this->listView1->Location = System::Drawing::Point(23, 42);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(747, 311);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyRecords::listView1_SelectedIndexChanged);
			// 
			// user
			// 
			this->user->Text = L"Пользователь";
			this->user->Width = 246;
			// 
			// doctor
			// 
			this->doctor->Text = L"Имя врача";
			this->doctor->Width = 267;
			// 
			// date
			// 
			this->date->Text = L"Дата";
			this->date->Width = 125;
			// 
			// time
			// 
			this->time->Text = L"Время";
			this->time->Width = 105;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 360);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 53);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Отписаться от приема";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyRecords::button1_Click);
			// 
			// MyRecords
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 425);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Name = L"MyRecords";
			this->Text = L"MyRecords";
			this->ResumeLayout(false);

		}
		String^ getTimeStamp(DateTime^ date)
		{
			return date->ToString("yyyy-MM-dd");
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DateTime^ myDate = DateTime::ParseExact(listView1->FocusedItem->SubItems[2]->Text, "dd.MM.yyyy H:mm:ss",
			System::Globalization::CultureInfo::InvariantCulture);
		ExecuteQuery("DELETE FROM records WHERE user='" + listView1->FocusedItem->Text + "' AND doctor_name='" + listView1->FocusedItem->SubItems[1]->Text + "' AND record_date='" + getTimeStamp(myDate) + "' AND record_time = '" + listView1->FocusedItem->SubItems[3]->Text + "'");
		MessageBox::Show("Успешно удалено");
		this->Close();
	}


	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{

	}
};
}
