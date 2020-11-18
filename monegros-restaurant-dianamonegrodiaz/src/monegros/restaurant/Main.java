package monegros.restaurant.main;

import java.util.Optional;
import java.util.Scanner;
import java.util.Set;

import monegros.restaurant.core.ioc.IoC;
import monegros.restaurant.core.ioc.IoCServicesEnum;
import monegros.restaurant.entities.Cashier;
import monegros.restaurant.services.interfaces.ICashierService;

public class Main {

	public static void main(String[] args) {
		IoC ioc=IoC.getInstance();
		Scanner sc=new Scanner(System.in); 
		ICashierService cashierService= ioc.getFromPool(IoCServicesEnum.CASHIER_SERVICE.getValue());
		
		Cashier cashier=new Cashier();
		System.out.print("Introduzca su nombre: ");
		cashier.setName(sc.next());
		System.out.print("Introduzca sus apellidos: ");
		cashier.setLastName(sc.next());
		System.out.print("Introduzca su numero de telefono: ");
		cashier.setPhone(sc.next());
		System.out.print("Introduzca un codigo: ");
		cashier.setCode(sc.next());
		System.out.print("Introduzca su edad: ");
		cashier.setAge(sc.nextInt());
		System.out.print("Introduzca su direccion: ");
		cashier.setAddress(sc.next());
		System.out.print("Introduzca su cedula: ");
		cashier.setIdentification(sc.next());
		cashierService.insert(cashier);
		
		System.out.println("\nCashier #2, introducir datos\n");
		
		Cashier cashier1=new Cashier();
		System.out.print("Introduzca su nombre: ");
		cashier1.setName(sc.next());
		System.out.print("Introduzca sus apellidos: ");
		cashier1.setLastName(sc.next());
		System.out.print("Introduzca su numero de telefono: ");
		cashier1.setPhone(sc.next());
		System.out.print("Introduzca un codigo: ");
		cashier1.setCode(sc.next());
		System.out.print("Introduzca su edad: ");
		cashier1.setAge(sc.nextInt());
		System.out.print("Introduzca su direccion: ");
		cashier1.setAddress(sc.next());
		System.out.print("Introduzca su cedula: ");
		cashier1.setIdentification(sc.next());
		cashierService.insert(cashier1);
		
		System.out.println("\nActualizar cashier #1: \n");
		
		System.out.print("Introduzca su nombre: ");
		cashier.setName(sc.next());
		System.out.print("Introduzca sus apellidos: ");
		cashier.setLastName(sc.next());
		System.out.print("Introduzca su numero de telefono: ");
		cashier.setPhone(sc.next());
		System.out.print("Introduzca un codigo: ");
		cashier.setCode(sc.next());
		System.out.print("Introduzca su edad: ");
		cashier.setAge(sc.nextInt());
		System.out.print("Introduzca su direccion: ");
		cashier.setAddress(sc.next());
		System.out.print("Introduzca su cedula: ");
		cashier.setIdentification(sc.next());
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
