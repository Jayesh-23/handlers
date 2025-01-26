#include"Header.hxx"
using namespace std;


//vector<tag_t>createdObjectsTags;
//vector<string>IDRev;

bool checkIsDigit(string st1)
{
	for (char ch : st1)
	{

		if (isdigit(ch) != 0)
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}

int ITK_user_main(int argc, char** argv)
{
	string st1, st2, Line;
	tag_t objtag = NULLTAG;
	tag_t tagOfObj = NULLTAG;
	tag_t CreateInput = NULLTAG;
	const char* itemId = "1234";
	const char* revItemId = "a";
	tag_t itemtag = NULLTAG;

	/*char* username = ITK_ask_cli_argument("-u");
	char* Pass = ITK_ask_cli_argument("-p");
	char* group = ITK_ask_cli_argument("-g");*/

	int status = ITK_init_module("infodba", "infodba", "dba");

	if (status==0)
	{
		cout << "login is sucessful";
	}
	else
	{
		cout << "login is failed";
	}

	ifstream Rof("Items.txt");//
					
		while (Rof.eof()==0) 
		{

			TCTYPE_find_type("Item", NULL, &tagOfObj);//find the type of object

			TCTYPE_construct_create_input(tagOfObj, &CreateInput); // it is used to hold the input data for the object going to create

			getline(Rof, st1);//1234,A
			stringstream ss(st1);

			while (ss.good())
			{
				getline(ss, st1, ',');//1234 then A
				//IDRev.push_back(st1);
				bool result = checkIsDigit(st1);

				if (result == true)
				{
					//ITEM_find_item(st1.c_str(),&itemtag);
					//ITEM_ask_latest_rev();
					AOM_set_value_string(CreateInput, "item_id", st1.c_str());
				}
				else
				{
					AOM_set_value_string(CreateInput, "item_revision_id", st1.c_str());//---Needto check this one----//
				}
			}

			TCTYPE_create_object(CreateInput, &objtag);

			AOM_save_with_extensions(objtag);

			//createdObjectsTags.push_back(objtag);
		}


	return ITK_ok;
}