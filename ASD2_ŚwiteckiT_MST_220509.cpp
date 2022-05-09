#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <math.h>
#include <fstream>
using namespace std;

struct Krawedz
{
	int wierzcholek1_id;
	int wierzcholek2_id;
	int waga;
	bool czyOdwiedzona;
	
	Krawedz()
	{
	wierzcholek1_id=0;
	wierzcholek2_id=0;
	waga=0;
	}
	
	Krawedz(int id1,int id2,int _waga)
	{
	wierzcholek1_id=id1;
	wierzcholek2_id=id2;
	waga=_waga;
		
	}
};

struct wezel
{
	string opis;
	int identyfikator;
	vector <Krawedz> edges;
	bool czyOdwiedzony;
};

class Prim
{
	vector <wezel> GRAF;
	vector <Krawedz> Krawedzie;
	vector <wezel> VisitedNodes;
	public:
	Prim()
	{
	fstream plik;
	plik.open("mst.in");
	if (plik.is_open() == false)
	{
		EXIT_FAILURE;
	}
	while (!plik.eof())
	{

		int liczba_wierzcholkow;
		plik>>liczba_wierzcholkow;
		for(int i=0;i<liczba_wierzcholkow;i++)
		{  
		wezel pomocniczy_wezel;
		plik>>pomocniczy_wezel.identyfikator;
		plik>>pomocniczy_wezel.opis;
		GRAF.push_back(pomocniczy_wezel);
		}
		int liczba_krawedzi_w_grafie;
		plik>>liczba_krawedzi_w_grafie;
		for(int i=0;i<liczba_krawedzi_w_grafie;i++)
		{  
		Krawedz pomocnicza_krawedz;
		plik>>pomocnicza_krawedz.wierzcholek1_id>>pomocnicza_krawedz.wierzcholek2_id>>pomocnicza_krawedz.waga;
		Krawedzie.push_back(pomocnicza_krawedz);
		}
	}
	plik.close();
		
		/*
		int liczba_wierzcholkow=4;
		wezel pomocniczy_wezel;
		pomocniczy_wezel.identyfikator=1;
		pomocniczy_wezel.opis="AA";
		GRAF.push_back(pomocniczy_wezel);
		pomocniczy_wezel.identyfikator=2;
		pomocniczy_wezel.opis="BB";
		GRAF.push_back(pomocniczy_wezel);
		pomocniczy_wezel.identyfikator=3;
		pomocniczy_wezel.opis="CC";
		GRAF.push_back(pomocniczy_wezel);
		pomocniczy_wezel.identyfikator=4;
		pomocniczy_wezel.opis="DD";
		GRAF.push_back(pomocniczy_wezel);
		

		int liczba_krawedzi_w_grafie=5;
		Krawedzie.push_back(Krawedz(1,2,3));
		Krawedzie.push_back(Krawedz(2,3,5));
		Krawedzie.push_back(Krawedz(4,1,6));
		Krawedzie.push_back(Krawedz(3,4,2));
		Krawedzie.push_back(Krawedz(2,4,3));
		*/
	}
	
	void Prim_Algorithm()
	{
		/*
		FindAllEdges(1);
		cout<<endl;
		FindAllEdges(2);
		cout<<endl;
		FindAllEdges(3);
		cout<<endl;
		FindAllEdges(4);
		*/
		
		wezel obecny_wezel=GRAF[0];
		VisitedNodes.push_back(obecny_wezel);

		for(int i=0;i<VisitedNodes.size();i++)
		{
			if(VisitedNodes.size()<4)
			{
				int minimum=findMin();
				//cout<<"min node: "<<minimum<<" "<<endl;
				for(int i=0;i<GRAF.size();i++)
				{
					if(GRAF[i].identyfikator==minimum)
					{
						VisitedNodes.push_back(GRAF[i]);
					}
				}
			}
			else
			{
//				for(int i=0;i<VisitedNodes.size();i++)
//				{
//				cout<<VisitedNodes[i].opis;
//
//				}	
				for(int i=0;i<Krawedzie.size();i++)
				{
					
					if(Krawedzie[i].czyOdwiedzona==true)
					{
						

					int w1=Krawedzie[i].wierzcholek1_id;
					int w2=Krawedzie[i].wierzcholek2_id;
					for(int j=0;j<VisitedNodes.size();j++)
					{
						if(VisitedNodes[j].identyfikator==w1)
						{
							cout<<VisitedNodes[j].opis<<" ";
						}
						if(VisitedNodes[j].identyfikator==w2)
						{
							cout<<VisitedNodes[j].opis<<" ";
						}
					}
					//cout<<" "<<Krawedzie[i].wierzcholek2_id<<" ";
					cout<<" "<<Krawedzie[i].waga<<" "<<endl;


					}

				}
				

			}

			
		}
		


	}
	
	
	
	
	int findMin()
	{
	int min=32768;
	int min_node_id;
	int prev_min_edge=-1;
	for (int j=0;j<VisitedNodes.size();j++)
	{
		for(int i=0;i<Krawedzie.size();i++)
			{
				
				if(Krawedzie[i].wierzcholek1_id==VisitedNodes[j].identyfikator && Krawedzie[i].czyOdwiedzona==false)
				{
					//cout<<Krawedzie[i].waga<<" ";
					//cout<<min<<" ";
					 //&& VisitedNodes[j].czyOdwiedzony==false 
					if(Krawedzie[i].waga<=min && VisitedNodes[j].czyOdwiedzony==false )
					{
						
						min=Krawedzie[i].waga;
						min_node_id=Krawedzie[i].wierzcholek2_id;
						
	
						if(prev_min_edge!=-1)
						{
							Krawedzie[prev_min_edge].czyOdwiedzona=false;
							Krawedzie[i].czyOdwiedzona=true;
							//VisitedNodes[j].czyOdwiedzony=false; 
							prev_min_edge=i;
						}
						else
						{
						Krawedzie[i].czyOdwiedzona=true;

						//VisitedNodes[j].czyOdwiedzony=true; 
						prev_min_edge=i;
						}
					}
				}
				if(Krawedzie[i].wierzcholek2_id==VisitedNodes[j].identyfikator && Krawedzie[i].czyOdwiedzona==false)
				{
					//cout<<Krawedzie[i].waga<<" ";
					//cout<<min<<" ";
					 //&& VisitedNodes[j].czyOdwiedzony==false 
					if(Krawedzie[i].waga<=min && VisitedNodes[j].czyOdwiedzony==false )
					{
						
						min=Krawedzie[i].waga;
						min_node_id=Krawedzie[i].wierzcholek1_id;
						
	
						if(prev_min_edge!=-1)
						{
							Krawedzie[prev_min_edge].czyOdwiedzona=false;
							Krawedzie[i].czyOdwiedzona=true;
							//VisitedNodes[j].czyOdwiedzony=false; 
							prev_min_edge=i;
						}
						else
						{
						Krawedzie[i].czyOdwiedzona=true;
						//VisitedNodes[j].czyOdwiedzony=true; 
						prev_min_edge=i;
						}
					}
				}
				

				
			}	
		
		}
		for (int i=0;i<VisitedNodes.size();i++)
		{
			if(VisitedNodes[i].identyfikator==min_node_id)
			{
				VisitedNodes[i].czyOdwiedzony=true;
			}
		}
		//cout<<"Min waga:"<<min;
		return min_node_id;
	}
	
	void FindAllEdges(int id)
	{
		for(int i=0;i<Krawedzie.size();i++)
		{
			if(Krawedzie[i].wierzcholek1_id==id || Krawedzie[i].wierzcholek2_id==id )
			{
				cout<<Krawedzie[i].wierzcholek1_id<<" "<<Krawedzie[i].wierzcholek2_id<<" "<<Krawedzie[i].waga<<endl;
			}
		}
	}
};



int main()
{

	Prim prim;
	prim.Prim_Algorithm();
	return 0;
}
