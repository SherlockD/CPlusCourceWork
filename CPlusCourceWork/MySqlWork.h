#pragma once
namespace MySqlWorkNameSpace {
	using namespace MySql::Data::MySqlClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Security::Cryptography;
	using namespace System::Text;

	ref class MySqlWork
	{		

	public:
		MySqlWork();
	private:static String^ connectionInfo = "datasource=localhost;port=3306;username=root;password=admin;database=cpluscource";
	public: static
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

	public:static String^ GetHash(String^ str)
	{
		StringBuilder^ hash = gcnew StringBuilder();
		MD5^ md5provider = MD5::Create();
		auto bytes = md5provider->ComputeHash(Encoding::UTF8->GetBytes(str));

		for (int i = 0; i < bytes->Length; i++)
		{
			hash->Append(bytes[i].ToString("x2"));
		}
		return hash->ToString();
	}
	};
}
