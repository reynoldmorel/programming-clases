package com.reynolds.decious.restaurant.respositories.impl;

import com.reynolds.decious.restaurant.entities.Order;
import com.reynolds.decious.restaurant.respositories.IOrderRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class OrderRepository implements IOrderRepository {
    private final Set<Order> orderStore = new HashSet<>();

    @Override
    public Optional<Order> insert(Order order) {
        order.setId(Instant.now().toEpochMilli());

        this.orderStore.add(order);

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
