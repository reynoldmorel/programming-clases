package com.reynolds.decious.restaurant.respositories.impl.mysql;

import com.reynolds.decious.restaurant.entities.Order;
import com.reynolds.decious.restaurant.respositories.IOrderRepository;

import java.util.Optional;

public class OrderMysqlRepository implements IOrderRepository {

    @Override
    public Optional<Order> insert(Order order) {
        /* store in mysql db*/
        return Optional.of(order);
    }

    @Override
    public Optional<Order> update(Order order) {
        return Optional.empty();
    }

    @Override
    public Optional<Order> findById(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Optional<Boolean> delete(Long aLong) {
        return Optional.empty();
    }
}
