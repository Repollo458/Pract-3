
#define HASHTABLE_H

#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

using namespace std;

template <typename V>

class HashTable: public Dict<V>{
	private:
		int n=0;
		int max=10;
		ListLinked<TableEntry<V>>* table;
		int h(string key){
			int asci= 0;
			for(int i = 0; i < key.length(); i++){
				asci+=int(key.at(i));
			}
			return asci%max;
		}
	public:
		HashTable(int size){
			n = 0;
			max = size;
			table = new ListLinked<TableEntry<V>>;
		}
		~HashTable(){
			delete table;
		}
	
		int capacity(){
			return max;
		}

		V search(string key) override {
			Node<TableEntry<V>>* aux = table->first;

			while (aux != nullptr) {
				if (aux->data.key == key) {
					return aux->data.value;
				}
				aux = aux->next;
			}// Elemento no encontrado

			return -1;
		}
		void insert(string key, V value) override {
			V status = search(key);
			if (status != -1){
				throw runtime_error("Elemento ya existente");
			}
			Node<TableEntry<V>>* nuevoNodo = new Node<TableEntry<V>>(TableEntry(key, value), nullptr);

			if (table->first == nullptr) {
				table->first = nuevoNodo;
			} else {
				Node<TableEntry<V>>* aux = table->first;
				while (aux->next != nullptr) {
					aux = aux->next;
				}
				aux->next = nuevoNodo;
			}

			n++;
		}

		V remove(string key) override{
			if(search(key) == -1){
				throw runtime_error("No existe esta entrada");
			}
			else{
				Node<TableEntry<V>>* aux = table->first;
				Node<TableEntry<V>>* prev = nullptr;
				while(aux->data.key != key){
					prev = aux;
					aux = aux->next;
				}
				prev->next = aux->next;
				n -= 1;
				return 1;
			}
			return -1;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			Node<TableEntry<V>>* aux = th.table->first;
			for (int i = 0; i < th.n; i++){
				out << aux->data.key << "\t" << aux->data.value << endl;
				aux = aux->next;
			}
			return out;
		}
		V operator[](std::string key){
			return search(key);
		}
		int entries() override{
			return n;
		}

};

