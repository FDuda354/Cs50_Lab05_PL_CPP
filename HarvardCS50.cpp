#include <iostream>

using namespace std;


struct osoba
{
    struct osoba* rodzice[2];
    char krew[2];
};


const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

osoba* create_family(int generations);
void print_family(osoba* p, int generation);
void free_family(osoba* p);
char random_allele();


int main(void)
{
    
    srand(time(NULL));

    
    osoba* p = create_family(GENERATIONS);

    
    print_family(p, 0);

    
    free_family(p);
}


osoba* create_family(int generations)
{
    
  
    osoba* w = new osoba;


    if (generations > 1)
    {
      
       osoba* parent[2];
       parent[0] = create_family(generations - 1);
       parent[1] = create_family(generations - 1);

  



        w->rodzice[0] = parent[0];
        w->rodzice[1] = parent[1];


 

        w->krew[0] = parent[rand() % 2]->krew[0];
        w->krew[1] = parent[rand() % 2]->krew[1];

        

    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        
        
        w->rodzice[0] = NULL;
        w->rodzice[1] = NULL;

        
        w->krew[0] = random_allele();
        w->krew[1] = random_allele();
    }

   
    return w;
}


void free_family(osoba* p)
{
    
    if (p == NULL) {
        return;
    }

    
    free_family(p->rodzice[0]);
    free_family(p->rodzice[1]);

    
    delete(p);

}


void print_family(osoba* p, int generation)
{
    
    if (p == NULL)
    {
        return;
    }

    
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        cout<<(" ");
    }

    
    if (generation == 0)
    {
        cout << "Child (Generation " << generation << "): blood type " << p->krew[0] << p->krew[1]<<endl;
    }
    else if (generation == 1)
    {
        cout << "Parent (Generation " << generation << "): blood type " << p->krew[0] << p->krew[1] << endl;
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            cout<<("Great-");
        }
        cout<<"Grandparent (Generation " << generation << "): blood type " << p->krew[0] << p->krew[1] << endl;
    }

   
    print_family(p->rodzice[0], generation + 1);
    print_family(p->rodzice[1], generation + 1);
}


char random_allele()
{
   short int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
