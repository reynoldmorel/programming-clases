# KReyes Gourmet Cuisine 

## Description
KReyes Gourmet Cuisine  is an application project for a restaurant, which consists of a user interface to order their food, the same client can build the desired food, as long as it is a variety plate, once the food is requested, an order is created that goes up to the kitchen, and the client will be able to follow up step by step to the elaboration of his food, observing until the remaining times.

     
### General flow
                                           
* The client accesses the application and looks for the food menu.
* Choose the desired dish if it is available.
* Choose the characteristics of your food such as: ingredients, accompaniments, etc.
* Once you have chosen everything you want, the order is created.
* The customer now has access to see the preparation process.
* Once the order is ready, the customer is notified.
* The customer can choose between picking up their food or receiving by delivery.

## Setup

This project is being developed in java and in order to start its development
the following steps should be taken:

1. It is suggested to create an [Oracle](https://profile.oracle.com/myprofile/account/create-account.jspx) account  as this facilitates many services and it allows us to download the desired version of the JDK, in case of not creating the account, you can search for a free version.

2. Download and install the java developer kit [JDK_11](https://www.oracle.com/java/technologies/javase-jdk11-downloads.html).

3. Set the path variable of JDk 11 in windows:
    * Select Control Panel and then System.
    * Click Advanced and then Environment Variables.
    * Add the location of the bin folder of the JDK installation to the PATH variable in System Variables.

4. Download and install the Community version of [IntelliJ_IDEA](https://www.jetbrains.com/es-es/idea/download/#section=windows).

5. Download and install [GIT](https://git-scm.com/).
6. Setup you git credentials in the terminal:

    `git config user.name" [Name] [Last Name] "`
    
    `git config user.email" [Email] "`

7. It is recommended to use a project repository for better management such as:
    * [Github](https://github.com/)
    
    * [Bitbucket](https://bitbucket.org/)

8. It only remains to start developing.




## Project Structure

This project is divided into several sections to keep a better work flow, the following basic entities are sectioned for the main routines:

### Entities
**Cashier** is the user that manage the accounting operations.

**Chef** is the user that prepare the items to sell and updates the status of the same. 

**Client** is the application user that make an order.

**Employee**is an user type that generate a code for employee.

**FinalProduct** is the item option to sell for the client. 

**MeasureUnit** is one of the tool use to keep control of stock and  quantity  of any ingrediente of items to sell.

**Menu** is the list of all available items to sell.

**MenuItem** is each items to sell at list.

**Order** is the  items to sell request.

**OrderDetail** contains all detail that the client ordered.

**Product** is a list of products that can be prepared.

**Stock** is the inventory of ingredients.

**StockProduct** is the detailed product from the stock.

**User** is the general entity of any user.

