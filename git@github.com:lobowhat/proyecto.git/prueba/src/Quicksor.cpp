/*
 * Quicksor.cpp
 *
 *  Created on: 14/02/2013
 *      Author: howar
 */

//Codificado por sAfOrAs
	//Muestra la suma de filas y columnas de una matriz de 5x5
	??=include<iostream>
	??=include<iomanip>
	using namespace std;
	int main()
	??<
	    int n[5][5],i=0,j=0,k=0, sum=0, sumf=0,sumc=0;
	    cout<<"\t\t\tMuestra la suma de filas y columnas\n";
	    for(i=0;i<5;i++)
	    {
	        for(j=0;j<5;j++)
	        {
	            k++;
	            cout<<"Ingrese el valor "<<k<<" :";
	            cin>>n[i][j];

	        }

	    }
	    for(i=0;i<5;i++)
	    {
	        for(j=0;j<5;j++)
	        {
	        cout<<setw(3)<<n[i][j]<<"  ";
	        sumf=sumf+n[i][j];
	        sum=sumf;
	        }
	        sumf=0;
	        //setw(3)<<setfill('<caracter para completar> ') son controlados por la libreria iomanip
	        //cambian la anchura de caracteres y setfill se usa si la anchura
	        //especificada sea mayor de la necesaria

	        cout<<"= "<<sum;cout<<endl;
	    }
	        //cout<<setw(3)<<" -----------------------"<<"  "<<endl;
	    for(i=0;i<5;i++)
	    {
	        for(j=0;j<5;j++)
	        {
	            sumc=sumc+n[j][i];
	            sum=sumc;
	        }
	        sumc=0;

	        //cout<<setw(3)<<sum<<"  ";
	    }
	    cout<<endl<<endl;


	    cin.ignore(); return 0;

	??>
