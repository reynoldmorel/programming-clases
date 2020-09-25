# DMD Monegros Restaurant:
 
## Description: 

DMD Monegros Restaurant is a sofware developep to be used in a restaurant in which the client would be able to decide what food he/she wants. Then, the order will go to the cashier to be paid, and then to the  kitchen to be prepared in a specific time period that will be calculated  depending on the experience and size of the order.
 
## Stack: 
 
*What you will need:*

- Windows Operative System of 64-Bits.
- Eclipse IDE.
- Java JDK 1.8.0 Development Kit.

## Setup

1. Download the JDK kit for your operative system. This the link of the version used in this project: https://www.oracle.com/java/technologies/javase/javase-jdk8-downloads.html
2. Download and install the Eclipse IDE. This is the link: https://www.eclipse.org/downloads/download.php?file=/oomph/epp/2020-06/R/eclipse-inst-win64.exe&mirror_id=576
3. Once it's installed, you will need to choose a specific workspace to have your projects. 
	- Go to File->Switch Workspace->Other
	- Click Browse, and create a folder wherever you desire to have all of your projects. Then, click OK, and Eclipse will restart.
4. Now go to Windows->Preferences->Java->Installed JREs
	- Click JRE 1.1.8 that appears, and then click EDIT.
	- Change the name "jre1.8.0_191" to "jdk1.8.0_191"
	- Go to directory-> ProgramFiles-> Java-> jdk1.8.0-> Finish-> Apply (the installed jdk)
5. Now go to Windows->Preferences->Java->Compiler
	- Select the compiler compliance level to 1.8
6. Now go to Help -> Install new sofware -> Add
	- In name, put whatever you want (preferible short, i put WBP). In location, paste this link: http://download.eclipse.org/windowbuilder/WB/release/4.6/. 
	- Click OK.
	- Select WindowBuilder, and click Next.
	- Click Next, Acept the terms and conditions, after everything is downloaded, Eclipse will restart.
7. The Eclipse IDE is ready to work.

## Project Structure:
	
This project is conformed by multiple entities.

## Entities

- **Cashier**: Is responsible for charging the order.
- **Chef**: Is responsible for cooking the food of the order, it has the properties of Employee as well as its experience.
- **Client**: Is responsible for ordering the food and paying.
- **Employee**: It's a general entity that has the properties of User. Every employee of the restaurant has the properties of Employee.
- **FinalProduct**: It's responsible to hold a list of products that conforms a plate.
- **MeasureUnit**: It holds the measurement name (grams, pounds, unit) of an specific Product or food.
- **Menu**: Entity that has the menu to be presented to the client so that he/she can choose.
- **MenuItem**: Entity that has a specific plate.
- **Order**: Entity that has all the plates or products that the client wants to order, the id of the order, the cashier,the final price.
- **OrderDetail**: Entity that has one plate, with it's name, price, how many of those plates the client wants.
- **Product**: Entity that has the information of an specific product. That product can be as simple as a loaf of bread and as complex as a pizza.
- **Stock**: Entity that has the information of each product (ingredient) that the restaurant has.
- **StockProduct**: Entity that has the information of ONE product in stock.
- **User**: Entity that has the information of all the different people that eat/work in the restaurant.
 