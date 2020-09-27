package com.reynolds.decious.restaurant;

import com.reynolds.decious.restaurant.core.ioc.IoC;
import com.reynolds.decious.restaurant.core.ioc.IoCRepositoryEnum;
import com.reynolds.decious.restaurant.entities.Cashier;
import com.reynolds.decious.restaurant.respositories.ICashierRepository;
import com.reynolds.decious.restaurant.respositories.IOrderRepository;

public class Main {

    public static void main(String[] args) {
        var orderRepository =
                IoC.getInstance().<IOrderRepository>getFromPool(
                        IoCRepositoryEnum.ORDER_REPOSITORY
                );

        var cashierRepository =
                IoC.getInstance().<ICashierRepository>getFromPool(
                        IoCRepositoryEnum.CASHIER_REPOSITORY
                );

        var cashier = new Cashier();
        cashier.setName("NAME1");
        cashier.setLastName("LAST NAME1");
        cashier.setAddress("TESTING 123456");
        cashier.setCode("123456");
        cashier.setIdentification("123456");

        cashierRepository.insert(cashier);

        cashier = new Cashier();
        cashier.setName("NAME2");
        cashier.setLastName("LAST NAME2");
        cashier.setAddress("TESTING 123456");
        cashier.setCode("123456789");
        cashier.setIdentification("123456789");

        cashierRepository.insert(cashier);

        var cashiers = cashierRepository.findByCriteria("123456789");

        cashiers.forEach(System.out::println);
    }
}
