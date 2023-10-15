/*
Creator: Aryamann Zutshi
Id Number: 3023609
Lab: Software Engineering Lab 5
Date: October 14, 2023
Sources used:
    - https://www.geeksforgeeks.org/bubble-sort/
    - 
*/

/*
The programming lab assignment requires 12 monthly sales to be read and a sales report to be generated.
The report should include (1) a title for the report, (2) a tabular report of the month and sales in two
columns, one for the month (January, February, etc.) and one for the corresponding sales, (2) the sales
summary, e.g., month with the lowest sales, month with the highest sales, and the average sales, (3) a 
six-month moving average also in a tabular format, and finally (4) a tabular listing of months and sales 
with the sales from the highest to the lowest.
*/

#include <stdio.h>
#include <string.h>
struct SaleData {
    //creating sle data structure
    char month[20]; //setting to 20 just to account for all the characters plus null
    double amount; //variable amount of type double
};

void printSales(struct SaleData sales[12]) { //12 bc 12 months
    
    /*
    printing out based on structure
    1. Print title
    2. Loop through each month
    3. For each month, print name and respective amount
    4. newline for formatting
    */
    printf("Monthly Sales Report for 2022:\n");
    //iterating through each month, printing respective data
    for (int i = 0; i < 12; i++) {
        printf("%s: $%.2f\n", sales[i].month, sales[i].amount);
    }
    printf("\n");
}

void printSummary(struct SaleData sales[12]) { //void, we don't want this to return anything, using array as our structure, setting size to 12
    double min = sales[0].amount; //all the zeros are initializing variables i wanted to create
    double max = sales[0].amount;
    double total = 0;
    int minIndex = 0;
    int maxIndex = 0; //these will all keep updating

    for (int i = 0; i < 12; i++) { //iterating 12 times
        //if current stored min less than latest i, replace as min by setting minIndex to it
        if (sales[i].amount < min) { 
            min = sales[i].amount;
            minIndex = i;
        }
        if (sales[i].amount > max) {
            //same logic, but for max
            max = sales[i].amount;
            maxIndex = i;
        }
        total += sales[i].amount; //simple total calculation
    }

    //print statements
    printf("Month with lowest sales: %s ($%.2f)\n", sales[minIndex].month, min);
    printf("Month with highest sales: %s ($%.2f)\n", sales[maxIndex].month, max);
    printf("Average Sales: $%.2f\n\n", total / 12);
}

void printSortedSales(struct SaleData sales[12]) {
    //bubble sort, had to watch a video on this
    //https://www.geeksforgeeks.org/bubble-sort/
    /*
    For each month (from January to December) as 'i':
    For each subsequent month after 'i' as 'j':
        If the sales amount of month 'i' is less than the sales amount of month 'j':
            Swap the sales amounts of month 'i' and month 'j'
            Swap the month names of month 'i' and month 'j'
    */
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[i].amount < sales[j].amount) {
                double tempAmount = sales[i].amount;
                sales[i].amount = sales[j].amount;
                sales[j].amount = tempAmount;

                char tempMonth[15];
                strcpy(tempMonth, sales[i].month);
                strcpy(sales[i].month, sales[j].month);
                strcpy(sales[j].month, tempMonth);
            }
        }
    }
    printf("Sales from Highest to Lowest:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s: $%.2f\n", sales[i].month, sales[i].amount);
    }
    printf("\n");
}

int main() {
    //wanted to use a dictionary bc I was thinking through python logic, this is what the internet told me to do as an equivalent
    struct SaleData sales[12] = {
        {"January", 23458.01},
        {"February", 40112.00},
        {"March", 56011.85},
        {"April", 37820.88},
        {"May", 37904.67},
        {"June", 60200.22},
        {"July", 72400.31},
        {"August", 56210.89},
        {"September", 67230.84},
        {"October", 68233.12},
        {"November", 80950.34},
        {"December", 95225.22}
    };
    //some print stuff
    printSales(sales);
    printSummary(sales);
    printSortedSales(sales);

    return 0;
}
