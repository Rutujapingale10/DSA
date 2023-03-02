#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include "rapidjson/document.h"  //rapidjson's DOM style API
#include"rapidjson/prettywriter.h" //for strigify json
#include"rapidjson/filereadstream.h"
using namespace std;
using namespace rapidjson;

int main()
{


        FILE *file=fopen("data.json","r");

          char buff[5000];
          FileReadStream f(file,buff,sizeof(buff));
                Document d;
                d.ParseStream(f);
                fclose(file);

                assert(!d.HasParseError());
                assert(d.IsObject());

                assert(d.HasMember("EMP"));
                assert(d["EMP"].IsObject());

                printf("**************************************\n");
                assert(d["EMP"]["NAME"].IsString());
                printf("HELLO %s \n",d["EMP"]["NAME"].GetString());


                assert(d["EMP"]["ID"].IsInt());
                printf("your id is - %d\n",d["EMP"]["ID"].GetInt());

                assert(d["EMP"]["DEPT"].IsString());
                  printf("your dept is '%s'\n",d["EMP"]["DEPT"].GetString());


                  assert(d["EMP"]["LOCATION"].IsString());
                printf("your location is : %s\n",d["EMP"]["LOCATION"].GetString());

                assert(d["EMP"]["PHYSICALLY FIT"].IsBool());
                printf("PHYSICALLY fit y/n : %s\n",d["EMP"]["PHYSICALLY FIT"].GetBool() ? "yes" : "no");


                printf("**************************************\n");

                assert(d.HasMember("MOBILE"));
                assert(d["MOBILE"].IsObject());

                assert(d["MOBILE"]["NAME"].IsString());
                printf("Mobile : %s\n",d["MOBILE"]["NAME"].GetString());

                assert(d["MOBILE"]["RAM"].IsString());
                printf("RAM is %s\n",d["MOBILE"]["RAM"].GetString());

                assert(d["MOBILE"]["ROM"].IsString());
                printf("ROM is :%s\n",d["MOBILE"]["ROM"].GetString());

                assert(d["MOBILE"]["AI CAMERA"].IsBool());
                printf("AI CAMERA : %s\n",d["MOBILE"]["AI CAMERA"].GetBool()? "YES" :"NO");

                assert(d["MOBILE"]["5G"].IsBool());
                printf("5G : %s\n",d["MOBILE"]["5G"].GetBool()?"yes":"no");

        return 0;
}


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
