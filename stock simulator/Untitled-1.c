#include <stdio.h>
#include <string.h>
struct Stock {
    char name[50];
    int price;
    int quantity;
};
void set_stock_price(struct Stock *stock, char *name, int price) {
    strcpy(stock->name, name);
    stock->price = price;
    stock->quantity = 0;
}
void purchase_stock(struct Stock *stock, int quantity) {
    if (quantity < 0) {
        printf("Invalid quantity\n");
        return;
    }
    if (stock->quantity == 0) {
        printf("You do not have any stocks of this type.\n");
        return;
    }
    if (quantity > stock->quantity) {
        printf("You do not have enough stocks to sell this amount.\n");
        return;
    }
    stock->quantity -= quantity;
}
void view_stock_portfolio(struct Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Price: %d\n", stock->price);
    printf("Quantity: %d\n", stock->quantity);
}
int main() {
    struct Stock stock1;
    set_stock_price(&stock1, "Google", 1000);
    purchase_stock(&stock1, 10);
    view_stock_portfolio(&stock1);
    return 0;
}



                              ##(**or**)



source code:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INITIAL_BALANCE 10000
#define STOCK_PRICE_RANGE 50
typedef struct {
    char symbol[10];
    int quantity;
    float price;
} Stock;
void printPortfolio(Stock *portfolio, int portfolioSize, float balance) {
    printf("\nPortfolio:\n");
    for (int i = 0; i < portfolioSize; ++i) {
        printf("%s: %d shares at $%.2f each\n", portfolio[i].symbol, portfolio[i].quantity, portfolio[i].price);
    }
    printf("Balance: $%.2f\n", balance);
}
void simulateStockMarket(Stock *portfolio, int portfolioSize, float *balance) {
    // Simulate stock price changes
    for (int i = 0; i < portfolioSize; ++i) {
        portfolio[i].price += (rand() % STOCK_PRICE_RANGE) / 10.0 - 2.5;
        if (portfolio[i].price < 1.0) {
            portfolio[i].price = 1.0;
        }
    }
    // Display current stock prices
    printf("\nCurrent Stock Prices:\n");
    for (int i = 0; i < portfolioSize; ++i) {
        printf("%s: $%.2f\n", portfolio[i].symbol, portfolio[i].price);
    }
    // Offer options to the user
    printf("\nOptions:\n");
    printf("1. Buy Stock\n");
    printf("2. Sell Stock\n");
    printf("3. Do Nothing\n");
    printf("Enter your choice (1-3): ");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            // Buy stock
            printf("Enter the stock symbol: ");
            char symbol[10];
            scanf("%s", symbol);
            for (int i = 0; i < portfolioSize; ++i) {
                if (strcmp(portfolio[i].symbol, symbol) == 0) {
                    printf("Enter the quantity to buy: ");
                    int quantity;
                    scanf("%d", &quantity);

                    if (*balance >= quantity * portfolio[i].price) {
                        *balance -= quantity * portfolio[i].price;
                        portfolio[i].quantity += quantity;
                        printf("Successfully bought %d shares of %s.\n", quantity, symbol);
                    } else {
                        printf("Insufficient funds to buy the specified quantity.\n");
                    }
                    break;
                }
            }
            break;
        case 2:
            // Sell stock
            printf("Enter the stock symbol: ");
            scanf("%s", symbol);

            for (int i = 0; i < portfolioSize; ++i) {
                if (strcmp(portfolio[i].symbol, symbol) == 0) {
                    printf("Enter the quantity to sell: ");
                    int quantity;
                    scanf("%d", &quantity);

                    if (quantity <= portfolio[i].quantity) {
                        *balance += quantity * portfolio[i].price;
                        portfolio[i].quantity -= quantity;
                        printf("Successfully sold %d shares of %s.\n", quantity, symbol);
                    } else {
                        printf("You don't have enough shares to sell.\n");
                    }
                    break;
                }
            }
            break;
        case 3:
            // Do nothing
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
    }
}
int main() {
    srand(time(NULL));
    int portfolioSize = 3;
    Stock portfolio[3] = {
        {"AAPL", 10, 150.0},
        {"GOOGL", 5, 1200.0},
        {"AMZN", 8, 3000.0}
    };
    float balance = INITIAL_BALANCE;
    printf("Welcome to the Stock Market Simulator!\n");
    while (1) {
        printPortfolio(portfolio, portfolioSize, balance);
        simulateStockMarket(portfolio, portfolioSize, &balance);
        printf("\nPress Enter to simulate the next day (or Ctrl+C to exit)...");
        getchar(); // Wait for user to press Enter
    }

    return 0;
}


