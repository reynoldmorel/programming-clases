package com.reynolds.decious.restaurant;

import com.reynolds.decious.restaurant.entities.Cashier;
import com.reynolds.decious.restaurant.entities.Order;
import com.reynolds.decious.restaurant.respositories.IEntityRepository;
import com.reynolds.decious.restaurant.respositories.impl.CashierRepository;
import com.reynolds.decious.restaurant.respositories.impl.mysql.OrderMysqlRepository;

public class Main {

    public static void main(String[] args) {
        IEntityRepository entityRepository = new OrderMysqlRepository();

        entityRepository.insert(new Order());

        entityRepository = new CashierRepository();

        entityRepository.insert(new Cashier());
    }
}
