const int N=20;
template <class tipo>
class POLINOMIO
{
	tipo polinomio[N];
public:
	POLINOMIO(void);// menor a ,mayor
	POLINOMIO<tipo> operator +(POLINOMIO<tipo> B);
	POLINOMIO<tipo> operator -(POLINOMIO<tipo> B);
	POLINOMIO<tipo> operator *(POLINOMIO<tipo> B);
	//POLINOMIO<tipo> operator /(POLINOMIO<tipo> B);
    //POLINOMIO<tipo> Integrar();
	//POLINOMIO<tipo> Derivar();
	//POLINOMIO<tipo> Ordenar();
	//tipo Evaluar();
	tipo Polinomio(int);
	void Polinomio(int, tipo);
	void Objeto_polinomio_this(POLINOMIO x)
	{
	  *this=x;
	}
	POLINOMIO Objeto_polinomio_this()
	{
	 return *this;
	}
};
template<class tipo>
POLINOMIO<tipo>::POLINOMIO(void)
{
	int i;
	i=0;
	while(i<N)
	{
	  polinomio[i]=0;
	  i++;
	 }
	polinomio[0]=0;
}
template<class tipo>
tipo POLINOMIO<tipo>::Polinomio(int i)
{
  return polinomio[i];
}
template<class tipo>
void POLINOMIO<tipo>::Polinomio(int i, tipo v)
{
  polinomio[i]=v;
}
template<class tipo>
POLINOMIO<tipo> POLINOMIO<tipo>::operator +(POLINOMIO<tipo> B)
{
    int i,j,k;
	POLINOMIO<tipo> C;
	i=1;
	j=1;
	k=1;
  while((i<this->polinomio[0]*2)&&(j<B.polinomio[0]*2))
  {
     if(this->polinomio[i+1]==B.polinomio[j+1])
	 {
	    C.polinomio[k]=this->polinomio[i]+B.polinomio[j];
		C.polinomio[k+1]=this->polinomio[i+1];
		i=i+2; j=j+2; k=k+2;
	 }
	 else 
		 { if(this->polinomio[i+1]<B.polinomio[j+1])
	 
			{
				C.polinomio[k+1]=this->polinomio[i+1];
				C.polinomio[k]=this->polinomio[i];
				i=i+2; k=k+2;
			}
			else
			{
				if(this->polinomio[i+1]>B.polinomio[j+1])
				{
					C.polinomio[k+1]=B.polinomio[j+1];
					C.polinomio[k]=B.polinomio[j];
					j=j+2; k=k+2;
				}
			}
		}
  }
   while(i<this->polinomio[0]*2)
	 {
	    C.polinomio[k+1]=this->polinomio[i+1];
		C.polinomio[k]=this->polinomio[i];
		i=i+2; k=k+2;
	 }
  while(j<B.polinomio[0]*2)
	 {
	    C.polinomio[k+1]=B.polinomio[j+1];
		C.polinomio[k]=B.polinomio[j];
		j=j+2; k=k+2;
	 }
  C.polinomio[0]=k/2;
  return C;
}
template<class tipo>
POLINOMIO<tipo> POLINOMIO<tipo>::operator -(POLINOMIO<tipo> B)
{
    int i,j,k;
	POLINOMIO<tipo> C;
	i=1;
	j=1;
	k=1;
  while((i<this->polinomio[0]*2)&&(j<B.polinomio[0]*2))
  {
     if(this->polinomio[i+1]==B.polinomio[j+1])
	 {
	    C.polinomio[k]=this->polinomio[i]-B.polinomio[j];
		C.polinomio[k+1]=this->polinomio[i+1];
		i=i+2; j=j+2; k=k+2;
	 }
	 else 
		 { if(this->polinomio[i+1]<B.polinomio[j+1])
	 
			{
				C.polinomio[k+1]=this->polinomio[i+1];
				C.polinomio[k]=this->polinomio[i];
				i=i+2; k=k+2;
			}
			else
			{
				if(this->polinomio[i+1]>B.polinomio[j+1])
				{
					C.polinomio[k+1]=B.polinomio[j+1];
					C.polinomio[k]=-1*B.polinomio[j];
					j=j+2; k=k+2;
				}
			}
		}
  }
   while(i<this->polinomio[0]*2)
	 {
	    C.polinomio[k+1]=this->polinomio[i+1];
		C.polinomio[k]=this->polinomio[i];
		i=i+2; k=k+2;
	 }
  while(j<B.polinomio[0]*2)
	 {
	    C.polinomio[k+1]=B.polinomio[j+1];
		C.polinomio[k]=-1*B.polinomio[j];
		j=j+2; k=k+2;
	 }
  C.polinomio[0]=k/2;
  return C;
}
template<class tipo>
POLINOMIO<tipo> POLINOMIO<tipo>::operator *(POLINOMIO<tipo> B)
{
    int i,j;
	POLINOMIO<tipo> C;
	i=1;
  while(i<this->polinomio[0]*2)
  {	  
	  j=1;
	  POLINOMIO<tipo> AUX;
	  while(j<B.polinomio[0]*2)
		{
			
				AUX.polinomio[j]=this->polinomio[i]*B.polinomio[j];
				AUX.polinomio[j+2]=this->polinomio[i+1]+B.polinomio[j+1];
				j=j+2; //k=k+2;
		}
	    AUX.Polinomio(j/2);
		C=AUX;
		i=i+2;
	}
  return C;
}
