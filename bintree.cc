#include "bintreeplus.h"
#include <string.h>

using namespace btr;

Node::Node(char* wrd,Node *prnt){
	parent=prnt;
	left=NULL;
	right=NULL;
	word=new char[strlen(wrd)+1];
	strcpy(word,wrd);
}

Node::~Node(){
	delete []word;
}

void Node::set_left(Node* child){
	left=child;
}

void Node::set_right(Node* child){
	right=child;
}


Tree::Tree(){
	root=NULL;
}

Tree::~Tree(){
	clear(root);
}

void Tree::clear(Node* t){
	if(t!=NULL){
        clear(t->get_left());
        clear(t->get_right());
        delete t;
    }
}

void Tree::add(char *word){
    Node *tmp = root;
    Node *parent = NULL;
    int f = 0;
    while(tmp!=NULL){
    	if(strcmp(tmp->get_word(),word)<0){
    		parent = tmp;
        	tmp = tmp->get_right();
        	f = 2;
        } 
        else if(strcmp(tmp->get_word(),word)>0){
        	parent = tmp;
            tmp = tmp->get_left();
            f = 1;
        } 
		else
        	return;
    }
	
	Node* t=new Node(word,parent);
    if(f==2)
		parent->set_right(t);
    if(f==1)
		parent->set_left(t);
	if(f==0)
		root=t;
    
	return;
}


void Tree::writeToFile(Node* t, std::ofstream& out){
	if(t!=NULL){
        writeToFile(t->get_right(), out);
        out<<(t->get_word())<<"\n";
        writeToFile(t->get_left(), out);
    }
    return;
}
