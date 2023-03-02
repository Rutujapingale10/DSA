#include<iostream>
#include"rapidjson/document.h"
#include"rapidjson/prettywriter.h"
#include<cstdio>
using namespace rapidjson;
using namespace std;
int main()
{
        const char* json = "{\"name\": \"Rutuja\",\"age\":22,\"Physically fit\":true,\"Location\":\"PUNE\",\"a\":[1,3,9,70],\"Skills\":[\"C\",\"CPP\",\"JAVA\"]}";
        Document document;
        document.Parse(json);
        //Acess member in doc
        assert(!document.HasParseError());
//      assert(document.IsObject());

        assert(document.IsObject());

         printf("***************\n");

        assert(document.HasMember("name"));
        assert(document["name"].IsString());
        printf("Name : %s\n",document["name"].GetString());


        assert(document.HasMember("age"));
        assert(document["age"].IsInt());
        printf("Age : %d\n",document["age"].GetInt());

        assert(document.HasMember("Physically fit"));
        assert(document["Physically fit"].IsBool());
        printf("Physically fit : %s\n",document["Physically fit"].GetBool()?"true":"false");

        assert(document.HasMember("Location"));
        assert(document["Location"].IsString());
        printf("Location : %s\n",document["Location"].GetString());

          printf("***************\n");

        //using reference
        const Value &A = document["a"];
        assert(A.IsArray());
        for(SizeType i=0;i<A.Size();i++)
        {
                printf("numbers  - %d\n",A[i].GetInt());
        }


/*      for(auto& v :A.GetArray())
        {
                  printf("Skills are - %d",v.GetInt());

        }
*/
        printf("***************\n");
        const Value &S= document["Skills"];
        for(SizeType i=0;i<S.Size();i++)
        {
                printf("Skill  - %s\n",S[i].GetString());

        }


        return 0;

}
