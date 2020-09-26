package com.reynolds.decious.restaurant.respositories.impl;

import com.reynolds.decious.restaurant.entities.Cashier;
import com.reynolds.decious.restaurant.respositories.ICashierRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

public class CashierRepository implements ICashierRepository {
    private final Set<Cashier> cashierStore = new HashSet<>();

    @Override
    public Optional<Cashier> insert(Cashier cashier) {
        cashier.setId(Instant.now().toEpochMilli());

        this.cashierStore.add(cashier);

        return Optional.of(cashier);
    }

    @Override
    public Optional<Cashier> update(Cashier cashier) {
        var existing = cashierStore.stream()
                .filter(c -> c.equals(cashier))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The cashier you are trying to update does not exist"));

        existing.setAddress(cashier.getAddress());
        existing.setAge(cashier.getAge());
        existing.setName(cashier.getName());

        return Optional.of(existing);
    }

    @Override
    public Optional<Boolean> delete(Long id) {
        var cashierToDelete = new Cashier(id);
        cashierStore.removeIf(c -> c.equals(cashierToDelete));

        return Optional.of(Boolean.TRUE);
    }

    public Set<Cashier> findByName(String name) {

        var nameOptional = Optional.ofNullable(name);

        return cashierStore.stream()
                .filter(c -> nameOptional.isEmpty() || c.getName().contains(nameOptional.get()))
                .collect(Collectors.toSet());
    }

    public Set<Cashier> findByCriteria(String criteria) {

        var criteriaOptional = Optional.ofNullable(criteria);

        return cashierStore.stream()
                .filter(c -> criteriaOptional.isEmpty() || c.getName().contains(criteriaOptional.get()))
                .filter(c -> criteriaOptional.isEmpty() || c.getLastName().contains(criteriaOptional.get()))
                .filter(c -> criteriaOptional.isEmpty() || c.getCode().contains(criteriaOptional.get()))
                .filter(c -> criteriaOptional.isEmpty() || c.getAddress().contains(criteriaOptional.get()))
                .filter(c -> criteriaOptional.isEmpty() || c.getIdentification().contains(criteriaOptional.get()))
                .collect(Collectors.toSet());
    }
}
