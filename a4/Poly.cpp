#include<iostream>
#include<cassert>
#include<cmath>
#include"Poly.h"

using namespace std;

Poly::Poly()
{
    firstTerm=NULL;
    lastTerm=NULL;
    highestExp=-1;
}

Poly::~Poly()
{
    Node *temp;
    temp=firstTerm;
	do{
		delete temp;
		temp=temp->next;
	}while(temp != NULL);
    cout << "~Poly()"<<endl;
}

Poly::Poly(const Poly & p)
{
    firstTerm=NULL;
    lastTerm=NULL;
    highestExp=-1;
    Node *temp=p.firstTerm;

    while(temp != NULL){
        this->appendTerm(temp->coeff,temp->exp);
        temp=temp->next;
    }
}

const Poly & Poly::operator=(const Poly & p)
{
    Node *temp=firstTerm;
	do{
		delete temp;
		temp=temp->next;
	}while(temp != NULL);


    firstTerm=NULL;
    lastTerm=NULL;
    highestExp=-1;
    temp=p.firstTerm;

    while(temp != NULL){
        this->appendTerm(temp->coeff,temp->exp);
        temp=temp->next;
    }

    return *this;
}

bool Poly::empty()const
{
    return ( firstTerm==NULL && lastTerm==NULL );
}
    
int Poly::degree() const
{
    return highestExp;
}
    
void Poly::appendTerm(double coeff, int exp)
{
    assert( (exp > highestExp) && (coeff != 0) );
    Node* temp = new Node;
    temp->coeff=coeff;
    temp->exp=exp;
    temp->next=NULL;
    if( firstTerm == NULL )
    {
        firstTerm = temp;
        lastTerm = temp;
        lastTerm->next=NULL;
    }
    else
    {
        lastTerm->next=temp;
        lastTerm=temp;
    }
    highestExp=exp;
}

void Poly::display(std::ostream & out)
{
    Node* temp;
	temp=firstTerm;
	while(temp->next!=NULL)
	{
		if( temp->coeff != 1 ) out << temp->coeff;
        if( temp->exp!=0 && temp->exp!=1 ) out << "x^" << temp->exp;
        if( temp->exp==1 ) out << "x" ;
        out << " + ";
		temp=temp->next;
	}
	out << temp->coeff << "x^" << temp->exp << endl;
}

double Poly::evaluate(int x)
{
    int total=0;
    Node* temp;
	temp=firstTerm;
    do{
        total = total + (temp->coeff) * pow( x , temp->exp );
        temp=temp->next;
	}while(temp != NULL);
    
    return total;
}

Poly Poly::operator+(const Poly & p)
{
    Poly newPoly;
    Node* temp;
    
    int degree=max(p.degree(),highestExp);
    int exps[degree+1];
    
    for (int i=0; i<=degree; i++)
        exps[i]=0;
    
    for (int i=0; i<=degree; i++)
    {
        temp=firstTerm;
        do{
            if(temp->exp==i)
                exps[i]=temp->coeff;
            temp=temp->next;
        }while(temp != NULL);
        
        temp=p.firstTerm;
        do{
            if(temp->exp==i)
                exps[i]=exps[i]+temp->coeff;
            temp=temp->next;
        }while(temp != NULL);
    }
    
    for (int i=0; i<=degree; i++)
    {
        if( exps[i]!=0 )
            newPoly.appendTerm(exps[i], i);
    }

    return newPoly;
}
