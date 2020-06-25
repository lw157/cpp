#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writefasta(string myname, string content);


int main( int argc, char **argv ){
  if (argc <= 1) {
    cerr << "Usage: " << argv[0] << " [infile]" << endl;
  }

  ifstream input(argv[1]);

  if(!input.good()){
    cerr << "Error openning '" << argv[1] << "'." << endl;
  }

  string line, name, content;
  int count = 0;
  while(getline(input, line).good() ) {
	 // cout << line << endl;
    if(line.empty() || line[0] == '>'){
      if (!name.empty() ){
		  //cout << count << "\t" << name << " : " << content << endl;
		  writefasta(name, content);
		  name.clear();
      }

      if(! line.empty()) {
		  name = line.substr(1);
      }
      content.clear();
	  
    } else if (!name.empty() ){
      if (line.find( ' ') != string::npos) {
		  name.clear();
		  content.clear();
      }else{
		  content += line;
      }
    }
	count += 1;
  }

  cout << "infile has " << count << " line" << endl;
  if (! name.empty() ) {
    //cout << count << "\t" << name << " : " << content << endl;
	  writefasta(name, content);
  }

  return 0;

}


// function writefasta
int writefasta(string myname, string content){
	
	// string appx = ".fa";
	string filename = myname.substr(0,myname.size() ) ; //+ ".fa"
	cout << "output to file: " << filename << " \tDNA length: " << content.size() << endl;

	ofstream myfile;// (filename + ".fa");
	myfile.open(filename + ".fa");
	
	if (! myfile){	
		cout << "unable to open file" << endl;
	} 
	
	 myfile << ">" << myname << "\n" << content << endl;
	 myfile.close();
	 return 0;
}


