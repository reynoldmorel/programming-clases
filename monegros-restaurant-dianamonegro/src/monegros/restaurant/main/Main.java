package monegros.restaurant.main;

import java.util.Optional;
import java.util.Set;

import monegros.restaurant.core.ioc.IoC;
import monegros.restaurant.core.ioc.IoCServicesEnum;
import monegros.restaurant.entities.Cashier;
import monegros.restaurant.services.interfaces.ICashierService;

public class Main {

	public static void main(String[] args) {
		IoC ioc=IoC.getInstance();
		
		ICashierService cashierService= ioc.getFromPool(IoCServicesEnum.CASHIER_SERVICE.getValue());
		
		Cashier cashier=new Cashier();
		cashier.setCode("0000CE");
		cashier.setAge(20);
		cashier.setAddress("Gurabo");
		cashier.setIdentification("555555");
		cashier.setLastName("Diaz");
		cashier.setName("Diana");
		cashier.setPhone("8297664032");
		cashierService.insert(cashier);
		
		Cashier cashier1=new Cashier();
		cashier1.setCode("1111CE");
		cashier1.setAge(22);
		cashier1.setAddress("Los Jardines");
		cashier1.setIdentification("88888888");
		cashier1.setLastName("Peralta");
		cashier1.setName("Julia");
		cashier1.setPhone("8066124033");
		cashierService.insert(cashier1);
		
		cashier.setCode("0000CE");
		cashier.setAge(20);
		cashier.setAddress("Villa Olimpica");
		cashier.setIdentification("555555");
		cashier.setLastName("Diaz");
		cashier.setName("Diana Maria");
		cashier.setPhone("8297664000");
		cashierService.update(cashier);
		
		Optional<Cashier> cashierID=cashierService.findById((long) 1);
		if(cashierID.isPresent()==true) {
			System.out.println("Find by ID: "+cashier.getName()+" "+ cashier.getLastName());
		}
		else
			System.out.println("Cashier not found");
		
		Set<Cashier> allCashiers= (Set<Cashier>) cashierService.findAll();
		for (Cashier fullName : allCashiers) 
		{ 
			System.out.println("All: "+fullName.getName()+" "+fullName.getLastName()); 
		}
		
		cashierService.delete(cashier1.getId());
	}

}
