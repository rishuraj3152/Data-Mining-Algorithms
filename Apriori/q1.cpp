#include<iostream>
#include<conio.h>

using namespace std;

int
main ()
{
  int i, j, t1, k, l, m, f, f1, f2, f3;

  int a[5][5];
  for (i = 0; i < 5; i++)
    {
      cout << "\n input items from transaction " << i + 1 << " :\n";
      for (j = 0; j < 5; j++)
    {
     cin >> a[i][j];
    }
    }

  int min;
  cout << "\n what is minimum support ? \n";
  cin >> min;

  cout << "\nInitial Input:\n";
  cout << "\nTrasaction\tItems\n";
  for (i = 0; i < 5; i++)
    {
      cout << i + 1 << ":\t";
      for (j = 0; j < 5; j++)
    {
     cout << a[i][j] << "\t";
    }
      cout << "\n";
    }
  cout << "\nAssume minimum support: " << min;

  int l1[5];
  for (i = 0; i < 5; i++)
    {
      t1 = 0;
      for (j = 0; j < 5; j++)
    {
     for (k = 0; k < 5; k++)
       {
         if (a[j][k] == i + 1)
        {
         t1++;
        }
       }
    }
      l1[i] = t1;
    }

  cout << "\n\nGenerating C1 from data\n";
  for (i = 0; i < 5; i++)
    {
      cout << i + 1 << ": " << l1[i] << "\n";
    }

  int p2pcount = 0;
  int p2items[5];
  int p2pos = 0;
  for (i = 0; i < 5; i++)
    {
      if (l1[i] >= min)
    {
     p2pcount++;
     p2items[p2pos] = i;
     p2pos++;
    }
    }

  cout << "\nGenerating L1 From C1\n";
  for (i = 0; i < p2pos; i++)
    {
      cout << p2items[i] + 1 << "\t" << l1[p2items[i]] << "\n";
    }

  getch ();
}

