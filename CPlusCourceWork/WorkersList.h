#include "MySqlWork.h"
#pragma once

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySqlWorkNameSpace;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// —водка дл€ WorkersList
	/// </summary>
	public ref class WorkersList : public System::Windows::Forms::Form
	{
	public:
		WorkersList(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~WorkersList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:

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
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 21);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(346, 290);
			this->listBox1->TabIndex = 0;
			// 
			// WorkersList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(370, 319);
			this->Controls->Add(this->listBox1);
			this->Name = L"WorkersList";
			this->Text = L"WorkersList";
			this->Load += gcnew System::EventHandler(this, &WorkersList::WorkersList_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void WorkersList_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("SELECT user_login,user_role,doctor_fio FROM users INNER JOIN doctors ON users.user_login=doctors.login WHERE user_role='doctor'");
		while (dataReader->Read()) 
		{
			listBox1->Items->Add(dataReader->GetString(0)+" "+dataReader->GetString(2)+" ("+ dataReader->GetString(1)+")");
		}
	}
	};
}
