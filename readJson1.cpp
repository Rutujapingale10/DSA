#include"rapidjson/filereadstream.h"
#include"rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;

int main()
{
FILE *file;
//      fstream file;
        file=fopen("data.json","r");
//      file.open("data.json",ios::in); //ios::in - to read from file
        if(!file)
        {
                printf("File is not present");

        }
        else
        {
                ifstream file1("data.json");
                IStreamWrapper f(file1);
//        char buff[5000];
//        FileReadStream f(file,buff,sizeof(buff));
                Document d;
                d.ParseStream(f);

                assert(d.IsObject());
                printf("file is ready to open in read mode\n ");
                assert(d.HasMember("EMP"));
                assert(d["EMP"].IsObject());
                assert(d["EMP"]["NAME"].IsString());
                printf("HELLO %s \n",d["EMP"]["NAME"].GetString());
        }
//      fclose();

        return 0;
}
