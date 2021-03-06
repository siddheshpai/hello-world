#include <iostream>
#include "salesData72.h"

using namespace std;

//Call using a.out < input.txt > output.txt to read from input.txt and store output to output.txt
int main()
{
    salesData sales;    //Variable to hold data for next transaction
    
    //read the first transaction and ensure that there are data to process
    if(cin >> sales.bookNo >> sales.unitsSold >> sales.revenue)
    {
        salesData trans;    //Variable to hold running sum
        
        //Read and process remaining transactions
        while(cin >> trans.bookNo >> trans.unitsSold >> trans.revenue)
        {
            //If we are still processing the same book
            if(sales.isbn() == trans.isbn())
            {
                //sales.unitsSold += trans.unitsSold;
                //sales.revenue += trans.revenue;
                sales.combine(trans);
            }
            else
            {
                //Print results for previous book
                cout << "ISBN: " << sales.isbn() << endl
                     << "Units sold: " << sales.unitsSold << endl
                     << "Total revenue: " << sales.revenue << endl
                     << endl;
                     
                sales = trans;
            }
        }
        
        //Print the last transaction
        cout << "ISBN: " << sales.isbn() << endl
             << "Units sold: " << sales.unitsSold << endl
             << "Total revenue: " << sales.revenue << endl
             << endl;
    }
    else
    {
        //No input! warn the user
        cerr << "No data!" << endl;
        return -1;
    }
    
    return 0;
}
