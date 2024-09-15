# MarketFarmCpp

Welcome to **MarketFarmCpp**! This C++ application simulates a market environment where farmers manage farms specializing in cows, sheep, or chickens, and trade related products. The application utilizes the Observer design pattern for efficient communication and transaction management.

## Overview

In this simulation:
- **Cows** produce milk.
- **Sheep** produce wool.
- **Chickens** produce eggs.

Farmers trade these products based on their needs and use any remaining funds to purchase additional animals.

## Features

- **Farm Management**: Create and manage farms specializing in cows, sheep, or chickens.
- **Product Trading**: Buy and sell milk, wool, and eggs between farmers.
- **Animal Purchasing**: Expand farms by purchasing animals with available funds.
- **Market Simulation**: Simulate market days and track farm productivity and transactions.

## Requirements

- C++11 or later
- CMake 3.10 or later

## Installation

1. **Clone the Repository**

    ```bash
    git clone https://github.com/shaySitri/MarketFarmCpp.git
    cd MarketFarmCpp
    ```

2. **Build the Project**

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Application**

    ```bash
    ./MarketFarmCpp
    ```

## Components

### Farm

The `Farm` class represents a farm with:
- **Data Members**:
  - `ID`: Unique identifier for the farm.
  - `Money`: Amount of money the farm has.
  - `Animals`: List of animals in the farm.
  - `Products`: List of products available for sale.

- **Methods**:
  - Default constructor: Initializes with 3 animals of the farm's type and $10.
  - `Production()`: Calculates product amounts based on animal age.
  - `BuyProducts()`: Buys products from other farms.
  - `BuyAnimals()`: Purchases animals to expand the farm.
  - `PrintFarm()`: Prints farm details.

### Market

The `Market` class manages all farms and market operations:
- **Data Members**:
  - `year`: Number of years the market has existed.
  - `Farms`: List of farms in the market.

- **Methods**:
  - Default constructor: Initializes with 0 years and no farms.
  - `CreateFarms()`: Creates new farms based on user input.
  - `MarketDay()`: Manages trading and animal purchasing.
  - `NextYear()`: Advances to the next market year and performs transactions.
  - `FastForwardYears()`: Skips ahead by a specified number of years.
  - `PrintMarketFarms()`: Prints details of all farms in the market.

### Animal

The `Animal` class represents different types of animals:
- **Data Members**:
  - `Age`: Age of the animal.
  - `PurchasePrice`: Price of the animal.
  - `DeathAge`: Age at which the animal dies.

### Exceptions

The application handles errors with specific exceptions:
- `CowException`: Thrown for negative numbers of cow farms.
- `SheepException`: Thrown for negative numbers of sheep farms.
- `ChickenException`: Thrown for negative numbers of chicken farms.
- General exceptions for other issues (e.g., memory allocation) are also managed.

