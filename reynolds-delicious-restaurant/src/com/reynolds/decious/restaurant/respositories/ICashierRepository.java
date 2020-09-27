package com.reynolds.decious.restaurant.respositories;

import com.reynolds.decious.restaurant.entities.Cashier;

import java.util.Set;

public interface ICashierRepository extends IEntityRepository<Cashier, Long> {
    Set<Cashier> findByName(String name);

    Set<Cashier> findByCriteria(String criteria);
}
