#include "bintreeplus.h"
#include <iostream>

int main(int argc, char *argv[]){

	if(argc<3){
		std::cerr<<"Error, required 2 arguments"<<std::endl;
		return 0;
	}

	std::ifstream in(argv[1]);
	if(!in.is_open()){
		std::cerr<<"Error, cant open first file"<<std::endl;
		return 0;
	}

	std::ofstream out(argv[2]);
	if(!out.is_open()){
		std::cerr<<"Error, cant open second file"<<std::endl;
		in.close();
		return 0;
	}

	btr::Tree* tree = new btr::Tree();
	char *s = new char[64];

	while((in>>s))
		tree->add(s);

	tree->writeToFile(tree->get_root(), out);

	delete tree;
	delete []s;
	
	in.close();
	out.close();

	return 0;	
}
