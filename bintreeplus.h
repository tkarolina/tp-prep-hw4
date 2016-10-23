#include <fstream>

namespace btr { 

class Node {
    private:
        char* word;
        Node* parent;
        Node* left;
        Node* right;
    public:
		Node(char*,Node*);
		~Node();	
		Node* get_left(){return left;}
        Node* get_right(){return right;}
        Node* get_parent(){return parent;}
		char* get_word(){return word;}
		void  set_left(Node*);
		void  set_right(Node*);
};

class Tree {
    private:
        Node* root;
	public:
		Tree();
		~Tree();
		Node* get_root(){return root;}
		void clear(Node*);
        void add(char*);
		void writeToFile(Node*, std::ofstream &);
};

}
