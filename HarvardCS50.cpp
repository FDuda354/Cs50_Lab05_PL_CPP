#include <iostream>

using namespace std;


struct person
{
    struct person* parents[2];
    char blod[2];
};


const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person* create_family(int generations);
void print_family(person* p, int generation);
void free_family(person* p);
char random_allele();


int main(void)
{
    
    srand(time(NULL));

    
    person* p = create_family(GENERATIONS);

    
    print_family(p, 0);

    
    free_family(p);
}


person* create_family(int generations)
{
    
  
    person* w = new person;


    if (generations > 1)
    {      
       person* parent[2];
       
       parent[0] = create_family(generations - 1);
       parent[1] = create_family(generations - 1);

       w->parents[0] = parent[0];
       w->parents[1] = parent[1];

       w->krew[0] = parent[rand() % 2]->blod[0];
       w->krew[1] = parent[rand() % 2]->blod[1];
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL

        w->parents[0] = NULL;
        w->parents[1] = NULL;
        
        w->blod[0] = random_allele();
        w->blod[1] = random_allele();
    }

    return w;
}


void free_family(person* p)
{
    
    if (p == NULL) 
        return;

    
    free_family(p->parents[0]);
    free_family(p->parents[1]);
  
    delete(p);

}


void print_family(person* p, int generation)
{
    
    if (p == NULL)    
        return;
    
    for (int i = 0; i < generation * INDENT_LENGTH; i++)    
        cout<<(" ");
    
    if (generation == 0)   
        cout << "Child (Generation " << generation << "): blood type " << p->blod[0] << p->blod[1]<<endl;
    
    else if (generation == 1)    
        cout << "Parent (Generation " << generation << "): blood type " << p->blod[0] << p->blod[1] << endl;
    
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            cout<<("Great-");
        }
        cout<<"Grandparent (Generation " << generation << "): blood type " << p->blod[0] << p->blod[1] << endl;
    }

    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}


char random_allele()
{
   short int r = rand() % 3;
    if (r == 0)    
        return 'A';
    
    else if (r == 1)    
        return 'B';
    
    else   
        return 'O';
}
