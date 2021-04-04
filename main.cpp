//#include<algorithm>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
//#define BSD

using namespace std;


class TextBuffer{
  private:
   vector<string> lines;

  public:
   int get_length(){
     return this->lines.size();
   }

   string get_line(int idx){
     return this->lines[idx];
   }

   vector<string> get_lines(){
     return this->lines;
   }

   void set_line(string input){
     input.append("\n");
     this->lines.push_back(input);
   }

   void print(){
     for (int i = 0; i < this->get_length(); ++i){
       cout << this->lines[i];
     }
   }

} text_buffer;


void clean_input(int argc){
    if (argc > 2){
        cout << "Only provide one argument" << endl;
        exit(1);
    } else if (argc != 2){
        cout << "Provide a target file" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[]){
    clean_input(argc);

    // get outfile
    string target = argv[1];
#ifdef BSD
    std::__fs::filesystem::path targetpath = std::__fs::filesystem::current_path();
#else
    std::filesystem::path targetpath = std::filesystem::current_path();
#endif
    targetpath /= target;
    ofstream outfile(targetpath, ios::out | ios::binary);

    // parse input
    string input;
    do {
        getline(cin, input);
        if (input == "p"){
          text_buffer.print();
        } else {
          text_buffer.set_line(input);
        }
    } while (input != ".");

    // write and tidy up
    for (int i = 0; i < text_buffer.get_length() - 1; ++i){
        outfile << text_buffer.get_line(i);
    }
    outfile.close();

    return 0;
}
