#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray() {
    n = NULL;
    curr = NULL;
    t = NULL;
    node_size = 0;
}

DynamicArray::DynamicArray(int size) {
    n = NULL;
    curr = NULL;
    t = NULL;
    node_size = size;
    for (int i = 0; i < size; i++) {
        curr = new node;
        curr->value = 0;
        curr->next = NULL;
        if (n == NULL) {
            n = t = curr;
        }
        else {
            t->next = curr;
            t = curr;
        }
    }
    t = n;
    while (t != NULL) {
        cout << t->value << endl;
        t = t->next;
    }
}
DynamicArray::DynamicArray(int* arr, int size) {
    n = NULL;
    curr = NULL;
    t = NULL;
    node_size = size;
    for (int i = 0; i < size; i++) {
        curr = new node;
        curr->value = arr[i];
        curr->next = NULL;
        if (n == NULL) {
            n = t = curr;
        }
        else {
            t->next = curr;
            t = curr;
        }
    }
    t = n;
    while (t != NULL) {
        cout << t->value << endl;
        t = t->next;
    }
}

DynamicArray::DynamicArray(DynamicArray& D) {
    n = NULL;
    curr = NULL;
    t = NULL;
    node_size = D.node_size;
    D.t = D.n;
    for (int i = 0; i < node_size; i++) {
        curr = new node;
        curr->value = D.t->value;
        D.t = D.t->next;
        curr->next = NULL;
        if (n == NULL) {
            n = t = curr;
        }
        else {
            t->next = curr;
            t = curr;
        }
    }
    t = n;
    /*while (t != NULL) {
        cout << t->value << endl;
        t = t->next;
    }*/
}

const int DynamicArray :: operator[](int i) const {
    node* temp = new node;
    temp = n;
    for (int j = 0; j < i; j++) {
        //cout << t->value << endl;
        temp = temp->next;
    }
    return temp->value;
}

int& DynamicArray :: operator[](int i) {
	t = n;
	for (int j = 0; j < i; j++) {
		//cout << t->value << endl;
		t = t->next;
	}
	cout << "Enter Value: ";
	cin >> t->value;
	return t->value;
}

DynamicArray& DynamicArray :: operator()(int pos, int size) {
    node* t=new node;
    t = n;
    for (int j = 0; j < pos-1; j++) {
        //cout << t->value << endl;
        t = t->next;
    }
    DynamicArray* obj = new DynamicArray;
    obj->n = NULL;
    obj->curr = t;
    obj->t = NULL;
    t = t->next;
    obj->node_size = size - pos;
    for (int i = pos; i < size; i++) {
        obj->curr = new node;
        obj->curr->value = t->value;
        t = t->next;
        obj->curr->next = NULL;
        if (obj->n == NULL) {
            obj->n = obj->t = obj->curr;
        }
        else {
            obj->t->next = obj->curr;
            obj->t = obj->curr;
        }
        /*obj->t->next = obj->curr;
        obj->t = obj->curr;*/
    }
    //obj->t->next=NULL;
    obj->t = obj->n;
    while (obj->t != NULL) {
        cout << obj->t->value << endl;
        obj->t = obj->t->next;
    }
    //delete [] t;
    delete[] curr;
    //delete[]obj->t;
    delete[]obj->curr;
    return (*obj);
}

DynamicArray& DynamicArray :: operator()(int pos) {
    node* t=new node;
    t = n;
    for (int j = 0; j <= pos-1; j++) {
        //cout << t->value << endl;
        t = t->next;
    }
    //t = t->next;
    DynamicArray* obj = new DynamicArray;
    obj->n = NULL;
    obj->curr = t;
    obj->t = NULL;
    //t = t->next;
    obj->node_size = node_size - pos ;
    for (int i = pos; i < node_size; i++) {
        obj->curr = new node;
        obj->curr->value = t->value;
        t = t->next;
        obj->curr->next = NULL;
        if (obj->n == NULL) {
            obj->n = obj->t = obj->curr;
        }
        else {
            obj->t->next = obj->curr;
            obj->t = obj->curr;
        }
        /*obj->t->next = obj->curr;
        obj->t = obj->curr;*/
    }
    //obj->t->next = NULL;

    obj->t = obj->n;
    while (obj->t != NULL) {
        cout << obj->t->value << endl;
        obj->t = obj->t->next;
    }
    //t = n;
    //obj->t = obj->n;

    cout << "------\n";
    //delete[]curr;
    //delete[]t;
    //delete[]obj->t;
    //delete[]obj->curr;

    return (*obj);
}

void DynamicArray :: operator+=(int a) {
    curr = new node;
    curr->next = NULL;
    curr->value = a;
    t = n;
    while (t) {
        if (t->next == NULL) {
            t->next = curr;
            break;
        }
        t = t->next;
    }
    t = n;
    while (t != NULL) {
        cout << t->value << endl;
        t = t->next;
    }
}

//int DynamicArray :: operator-=(int) {
//	DynamicArray* obj = new DynamicArray;
//	//obj->arr = new int[arr_size - 1];
//	obj->n = new node[arr_size - 1];
//	int i;
//	for (i = 0; i < arr_size - 2; i++) {
//		//obj->arr[i] = arr[i];
//		obj->n[i].value = n[i].value;
//		obj->n[i].next = obj->n[i + 1].next;
//	}
//	obj->n[i].value = n[i].value;
//	obj->n[i].next = NULL;
//	//i = arr[arr_size - 1];
//	//arr = obj->arr;
//	i = n[arr_size - 1].value;
//	n = obj->n;
//
//	arr_size--;
//	//delete obj;
//	return i;
//}

DynamicArray :: operator string() {
    string out = "";
    t = n;
    while (t != NULL) {
        cout << t->value << endl;
        t = t->next;
    }
    return out;
}

DynamicArray :: operator int() {
    return node_size;
}

bool DynamicArray :: operator==(DynamicArray& D) {
    t = n;
    D.t = D.n;
    cout << D.node_size << endl;
    cout << node_size << endl;
    if (node_size == D.node_size) {
        for (int i = 0; i < node_size; i++) {
            if (t->value != D.t->value) {
                return false;
            }
            t = t->next;
            D.t = D.t->next;
        }
    }
    else {
        return false;
    }
    return true;
}

bool DynamicArray :: operator!=(DynamicArray& D) {
    if (node_size == D.node_size) { return false; }
    else { return true; }
}

DynamicArray::~DynamicArray() {
    
}
