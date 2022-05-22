#include <iostream>
#include<cassert>
using namespace std;
#include"Computer.h"
#include"CompStore.h"
int main()
{
   
    Computer* c1= new Computer("Model1", "White", 2019, "Intel", 8, 256);
    Computer* c2=new Computer("Model2", "Black", 2020, "AMD", 16, 1000);
    Computer* c3= new Computer("Model3", "Black", 2003, "Intel", 32, 750);
    Computer* c4=new Computer;
    c4 = c1;
    Computer** cmps = new Computer * [] {c1, c2, c3,c4};
    CompStore* store = new CompStore("Our Store", cmps);
    Computer** sameColor= store->getComputersByColor("Black");

    store->print();

    // store->getComputerById(3)->print();

    /*for (size_t i = 0;sameColor[i]!=nullptr; i++)
    {
        sameColor[i]->print();
    }*/

    // store->printComputersRAMGreaterThan(16);

    //store->printComputersYearBetween(2000, 2020); 

}


