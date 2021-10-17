#include <iostream>
#include <cstring>

using namespace std;

struct book
{
	string title;
	int price,pages;
	string author_name;
	long int ISBN;
};

struct book inLibrary[20];
struct book borrowed[20];

int n=5,b=0;

void search_bk()
{
	int ch,i;
	long int ISBN;
	string title;
	int pos = -1;
	cout << "\nSearch using:\n";
	cout << "1. Title\n2. ISBN number\n";
	cin >> ch;
	do
    {
        switch (ch)
        {
            case 1:
                cout << "\nEnter the title of the book to be searched:\n";
                fflush(stdin);
                getline(cin,title);
                for(i=0;i<n;i++)
                {
                    if(inLibrary[i].title == title)
                        pos = i;
                }
            break;
            case 2:
                cout << "\nEnter the ISBN number of the book to be searched:\n";
                cin >> ISBN;
                for(i=0;i<n;i++)
                {
                    if(ISBN == inLibrary[i].ISBN)
                        pos = i;
                }
            break;
            default:
                cout << "\nPlease enter a valid option!";
            break;
        }
    }while (ch !=1 && ch !=2);
	if(pos == -1)
		cout << "\nBook not found!";
	else
    {
		cout << "\nBook found at position " << pos + 1 << endl;
		cout << "\nBook details:\n\n";
		cout << "Title: " << inLibrary[pos].title << endl;
		cout << "Author: " << inLibrary[pos].author_name << endl;
		cout << "Price/week: " << inLibrary[pos].price << endl;
		cout << "Pages: " << inLibrary[pos].pages << endl;
		cout << "ISBN number: " << inLibrary[pos].ISBN << endl;
    }
}

void sell_bk()
{
    int pos = -1,i,pages,sell_price,expected_price,ch=2;
    string title;
    cout << "\nEnter the title of the book: ";
    fflush(stdin);
    getline(cin,title);
    for(i=0;i<n;i++)
    {
        if(inLibrary[i].title == title)
            pos = i;
        if(borrowed[i].title == title)
            pos = i;
    }
    if(pos == -1)
    {
        cout << "Enter the number of pages in the book: ";
        cin >> pages;
        expected_price = pages + 30;
        do
        {
        cout << "Enter the selling price of the book: ";
        cin >> sell_price;
            if(sell_price <= expected_price)
            {
                cout << "\nThis book is eligible for purchase. Thank you.\n";
                inLibrary[n].title = title;
                cout << "\nEnter the name of Author: ";
                fflush(stdin);
                getline(cin,inLibrary[n].author_name);
                cout << "Enter the ISBN number of the book: ";
                cin >> inLibrary[n].ISBN;
                inLibrary[n].price = expected_price/10;
                inLibrary[n].pages = pages;
                ch++;
                n++;
            }
            else
            {
                cout << "\nThis price exceeds our maximum purchase rates for a for a book of " << pages << " pages." << endl;
                cout << "\nPlease consider selling the book under " << expected_price << endl;
                cout << "1. Bargain\n2. Cancel\n";
                cin >> ch;
            }
        }while(ch == 1);
    }
    else
        cout << "\nWe already possess this book!";
}

void borrow_bk()
{
	int ch,i;
	long int ISBN;
	string title;
	int pos = -1;
	do
    {
        cout << "\nSearch for book using:\n";
        cout << "1. Title\n2. ISBN number\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "\nEnter the title of the book to be borrowed:\n";
                fflush(stdin);
                getline(cin,title);
                for(i=0;i<n;i++)
                {
                    if(inLibrary[i].title == title)
                        pos = i;
                }
            break;
            case 2:
                cout << "\nEnter the ISBN number of the book to be borrowed:\n";
                cin >> ISBN;
                for(i=0;i<n;i++)
                {
                    if(ISBN == inLibrary[i].ISBN)
                        pos = i;
                }
            break;
            default:
                cout << "\nPlease enter a valid option!";
            break;
        }
    }while (ch != 1 && ch !=2);

	if(pos == -1)
		cout << "\nBook not found!";
	else
	{
		borrowed[b] = inLibrary[pos];
		cout << "\n" << inLibrary[pos].title << " has been moved to borrowed books section!";
		for(i=pos;i<n-1;i++)
		{
			inLibrary[i] = inLibrary[i+1];
		}
		b++;
        n--;
	}
}

void display_inLibrary()
{
  int i;
  if(n!=0)
  {
      for(i=0;i<n;i++)
      {
        cout << "\nBook " << i+1 << " Details:\n\n";
        cout << "Title: " << inLibrary[i].title << endl;
        cout << "Author: " << inLibrary[i].author_name << endl;
        cout << "Price/week: " << inLibrary[i].price << endl;
        cout << "Pages: " << inLibrary[i].pages << endl;
        cout << "ISBN number: " << inLibrary[i].ISBN << endl;
      }
  }
  else
    cout << "\nNo books in the library!";
}

void display_borrowed()
{
  int i;
  if(b!=0)
  {
      for(i=0;i<b;i++)
      {
        cout << "\nBook " << i+1 << " Details:\n\n";
        cout << "Title: " << borrowed[i].title << endl;
        cout << "Author: " << borrowed[i].author_name << endl;
        cout << "Price/week: " << borrowed[i].price << endl;
        cout << "Pages: " << borrowed[i].pages << endl;
        cout << "ISBN number: " << borrowed[i].ISBN << endl;
      }
  }
  else
    cout << "\nNo books borrowed at the moment!";
}

int main()
{
    int ch,format = 0;

    inLibrary[0].title = "Think and Grow Rich";
    inLibrary[0].author_name = "Napoleon Hill";
    inLibrary[0].ISBN = 337609265;
    inLibrary[0].pages = 238;
    inLibrary[0].price = (inLibrary[0].pages+30)/10;

    inLibrary[1].title = "Atomic Habits";
    inLibrary[1].author_name = "James Clear";
    inLibrary[1].ISBN = 337609266;
    inLibrary[1].pages = 320;
    inLibrary[1].price = (inLibrary[1].pages+30)/10;

    inLibrary[2].title = "Rich Dad Poor Dad";
    inLibrary[2].author_name = "Robert Kiyosaki";
    inLibrary[2].ISBN = 337609267;
    inLibrary[2].pages = 207;
    inLibrary[2].price = (inLibrary[2].pages+30)/10;

    inLibrary[3].title = "Percy Jackson and the Lightning Thief";
    inLibrary[3].author_name = "Rick Riordan";
    inLibrary[3].ISBN = 337609268;
    inLibrary[3].pages = 377;
    inLibrary[3].price = (inLibrary[3].pages+30)/10;

    inLibrary[4].title = "Harry Potter and the Deathly Hallows";
    inLibrary[4].author_name = "J.K. Rowling";
    inLibrary[4].ISBN = 337609269;
    inLibrary[4].pages = 607;
    inLibrary[4].price = (inLibrary[4].pages+30)/10;

    do
    {
        if(format != 0)
            cout << "\n\n";

        cout << "***MENU***\n";
        cout << "\nWhat action do you wish to perform?\n";
        cout << "1. Search a book\n";
        cout << "2. Sell us a book\n";
        cout << "3. Borrow a book\n";
        cout << "4. Display books in the library\n";
        cout << "5. Display books borrowed at present\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                search_bk();
            break;
            case 2:
                sell_bk();
            break;
            case 3:
                borrow_bk();
            break;
            case 4:
                display_inLibrary();
            break;
            case 5:
                display_borrowed();
            break;
            case 6:
                cout << "\nThank You for choosing us!\n";
            break;
            default:
                cout << "\nChoose a valid action!";
            break;
        }
        format++;
    }while(ch!=6);

	return 0;
}