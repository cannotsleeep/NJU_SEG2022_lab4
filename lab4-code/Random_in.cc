#include "Random_in.h"
using namespace std;
int randx(int l,int r){
    return (rand()%(r+1-l)+l);
}

void generate(char* formatname){
    string s;
    string str;
    string formatfile = formatname;
    string fileinPath = formatfile + "/stdin_format.txt";
    ifstream fin;
    fin.open(fileinPath);
    streambuf * backup_out = cout.rdbuf(); 
    cin.rdbuf(fin.rdbuf());

    string datafile = formatfile + dataprefix;
    while( cin>>str  ){
        s = str;
        int i = 0;
        if(s[0]=='i'){
            while(s[i]!=','){i++;};
            int l = stoi(s.substr(4,i-4));
            int r = stoi(s.substr(i+1,s.size()-2-i));
            for(int i =0;i<samples;i++) {
                freopen((datafile + std::to_string(i)).c_str(), "a", stdout);
                printf("%d\n",randx(l,r));
                fclose(stdout);
                fflush(stdout);
            };
        } else if(s[0]=='c'){
            for(int i =0;i<samples;i++) {
                freopen((datafile + std::to_string(i)).c_str(), "a", stdout);
                int t = randx(0,51);
                if(t < 26 ) t += 65; else t += 71;
                printf("%c\n",t);
                fclose(stdout);
                fflush(stdout);
            };
        } else if(s[0]=='s'){
            string re = "";
            while(s[i]!=','){i++;};
            int l = stoi(s.substr(7,i-7));
            int r = stoi(s.substr(i+1,s.size()-2-i));
            for(int y =0;y<samples;y++) {
                freopen((datafile + std::to_string(y)).c_str(), "a", stdout);
                int length = randx(l,r);
                for(int k = 0;k<length; k++){
                    int t = randx(0,51);
                    if(t < 26 ) t += 65; else t += 71;
                    printf("%c",t);
                };
                printf("\n");
                fclose(stdout);
                fflush(stdout);
            };
        };
    }
    cout.rdbuf(backup_out);
    fflush(stdout);
    fclose(stdin);
    return ;
}

void GetFileName(std::string path, std::vector<std::string> &files) {
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str()))) return;
    while ((ptr = readdir(pDir)) != 0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) {
            files.push_back( ptr->d_name);
        }
    }
    closedir(pDir);
    fflush(stdout);
}

int Ran_in(){
    vector<string> files;
    srand((unsigned)time(NULL));
    char* filePath =(char*) "./input";
    GetFileName(filePath, files);
    int size = files.size();
	for (int ii = 0; ii < size; ii++)
	{
        if(files[ii][0]!='.') {
            string current_path = filePath;
            string x = files[ii];
            current_path = current_path+ "/" + files[ii];
            generate((char*)(current_path).c_str());
            fflush(stdout);
            }
	}
    return 1;
}
