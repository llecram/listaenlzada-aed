#include <iostream>
#include <stdio.h>
using namespace std;
template<class T>
struct Cnode{
    T m_data;
    Cnode<T>* m_next;
    Cnode(T x){
        m_data=x;
        m_next=nullptr;
    }
};
template<class T, class C>
struct Clist{
    Cnode<T>* m_head;
    Clist(){
        m_head=nullptr;
    }
    bool busca(T x, Cnode<T>**&p){
        p=&m_head;
        while(*p&&(*p)->m_data<x){
            p=&((*p)->m_next);
        }
        return *p&&(*p)->m_data==x;
    }
    bool inserta(T x){
        Cnode<T>** p;
        if(busca(x,p)){
            return 0;
        }
        Cnode<T>* n=new Cnode<T>(x);
        n->m_next=*p;
        *p=n;
        return 1;
    }
    bool saca(T x){
        Cnode<T>** p;
        if(!busca(x,p)){
            return 0;
        }
        Cnode<T>* t=*p;
        *p=t->m_next;
        delete t;
        return 1;
    }
    void print(Cnode<T>* h){
        if(h){
            cout<<" Valor: "<<h->m_data;
            if(h->m_next)cout<<" ";
        }
        print(h->m_next);
    }
    void imprimir(){
        print(m_head);
    }
};

int main()
{
    Clist<int,less<int>> L1;
    L1.inserta(156);
    L1.inserta(7);
    L1.inserta(8);
    L1.inserta(9);
    L1.imprimir();
}
