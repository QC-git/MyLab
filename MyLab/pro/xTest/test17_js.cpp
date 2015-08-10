
#include "xTest.h"

#include "jsoncpp-master\include\json\json.h"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

#pragma comment(lib, "lib_json_d.lib")

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace space_test_js 
{

//���ַ�������json
	
// int ParseJsonFromString()  
// {  
// 	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  
// 
// 	Json::Value root;  
// 	Json::Reader *pJsonParser = new Json::Reader(Json::Features::strictMode()); 
// 	
// 	if (!pJsonParser->parse(str, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��   
// 	{  
// 		return -1;
// 	}  
// 
// 	std::string upload_id = root["uploadid"].asString();  // ���ʽڵ㣬upload_id = "UP000000"   
// 	int code = root["code"].asInt();    // ���ʽڵ㣬code = 100   
// 
// 	//delete reader;
// 
// 	return 0;  
// }  
// 
// void test1()
// {
// 	ParseJsonFromString();
// }

//���ļ�����json

// int ParseJsonFromFile(const char* filename)
// {
// 	// ����json��Json::Reader
// 	Json::Reader reader;
// 	// Json::Value��һ�ֺ���Ҫ�����ͣ����Դ����������͡���int, string, object, array...
// 	Json::Value root;       
// 
// 	std::ifstream is;
// 	is.open (filename, std::ios::binary );  
// 	if (reader.parse(is, root))
// 	{
// 		std::string code;
// 		if (!root["files"].isNull())  // ���ʽڵ㣬Access an object value by name, create a null member if it does not exist.
// 			code = root["uploadid"].asString();
// 
// 		// ���ʽڵ㣬Return the member named key if it exist, defaultValue otherwise.
// 		code = root.get("uploadid", "null").asString();
// 
// 		// �õ�"files"���������
// 		int file_size = root["files"].size();
// 
// 		// ��������
// 		for(int i = 0; i < file_size; ++i)
// 		{
// 			Json::Value val_image = root["files"][i]["images"];
// 			int image_size = val_image.size();
// 			for(int j = 0; j < image_size; ++j)
// 			{
// 				std::string type = val_image[j]["type"].asString();
// 				std::string url = val_image[j]["url"].asString();
// 			}
// 		}
// 	}
// 	is.close();
// 	return 0;
// }
// 
// void test2()
// {
// 	char* sFileName = "E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_js\\test_cfg.json";   
// 
// 	ParseJsonFromFile(sFileName);
// 
// }

//��json�ṹ�в���json

// void test3()
// {
// 	Json::Value root;   
// 
// 	Json::Value arrayObj;   // ��������
// 	Json::Value new_item, new_item1;
// 	new_item["date"] = "2011-12-28";
// 	new_item1["time"] = "22:30:36";
// 	arrayObj.append(new_item);  // ���������Ա
// 	arrayObj.append(new_item1); // ���������Ա
// 	int file_size = root["files"].size();
// 	for(int i = 0; i < file_size; ++i)
// 		root["files"][i]["exifs"] = arrayObj;   // ����ԭjson��
// 
// 
// 	// ת��Ϊ�ַ���������ʽ��
// 	std::string out = root.toStyledString();
// 	// ����޸�ʽjson�ַ���
// 	Json::FastWriter writer;
// 	std::string out2 = writer.write(root);
// 
// }


// ʹ��boost����
// http://blog.csdn.net/flyfish1986/article/details/44808157

const std::string file_path= "E:\\QC-nd\\svn\\MyLab\\trunk\\MyLab\\pro\\xTest\\test_js\\test_cfg2.json";

void generate_user()  
{  
	boost::property_tree::ptree root;   
	boost::property_tree::ptree items;  



	boost::property_tree::ptree item1;  
	item1.put("ID","1");  
	item1.put("Name","wang");  
	items.push_back(std::make_pair("1",item1));  




	boost::property_tree::ptree item2;  
	item2.put("ID","2");  
	item2.put("Name","zhang");  
	items.push_back(std::make_pair("2",item2));  


	boost::property_tree::ptree item3;  
	item3.put("ID","3");  
	item3.put("Name","li");  
	items.push_back(std::make_pair("3",item3));  


	root.put_child("user",items);  
	boost::property_tree::write_json(file_path,root);  
}  

void read_user()  
{  

	boost::property_tree::ptree root;  
	boost::property_tree::ptree items;  
	boost::property_tree::read_json<boost::property_tree::ptree>(file_path,root);  


	items=root.get_child("user");  
	for (boost::property_tree::ptree::iterator it=items.begin();it!=items.end();++it)  
	{  
		//������������  
		std::string key=it->first;//key ID  
		std::string ID=it->second.get<std::string>("ID");  
		std::string Name=it->second.get<std::string>("Name");  


	}  
}  

void test4()
{
	//generate_user();
	read_user();
}

}


void test_js()
{	
// 	space_test_js::test1();   //��bug
// 	space_test_js::test2();
// 	space_test_js::test3();
	space_test_js::test4();

	getchar(); 
}