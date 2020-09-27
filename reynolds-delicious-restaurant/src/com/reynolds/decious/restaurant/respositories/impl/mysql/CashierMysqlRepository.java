package com.reynolds.decious.restaurant.respositories.impl.mysql;

import com.reynolds.decious.restaurant.entities.Cashier;
import com.reynolds.decious.restaurant.respositories.ICashierRepository;

import java.util.HashSet;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

public class CashierMysqlRepository implements ICashierRepository {
    private final Set<Cashier> cashierStore = new HashSet<>();
    private Long subSequentId = 0L;

    @Override
    public Optional<Cashier> insert(Cashier cashier) {
        this.subSequentId++;
        cashier.setId(this.subSequentId);

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

    @Override
    public Optional<Cashier> findById(Long id) {
        var cashierToFind = new Cashier(id);

        var cashierFound = cashierStore.stream()
                .filter(c -> c.equals(cashierToFind))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The cashier you are trying to update does not exist"));

        return Optional.of(cashierFound);
    }

    @Override
    public Set<Cashier> findByName(String name) {
        var nameOptional = Optional.ofNullable(name);

        return cashierStore.stream()
                .filter(c -> nameOptional.isEmpty() || c.getName().contains(nameOptional.get()))
                .collect(Collectors.toSet());
    }

    @Override
    public Set<Cashier> findByCriteria(String criteria) {
        var cleanedCriteria = Optional.ofNullable(criteria)
                .orElse("");

        return cashierStore.stream()
                .filter(c -> this.cashierCriteriaFilter(c, cleanedCriteria))
                .collect(Collectors.toSet());
    }

    private Boolean cashierCriteriaFilter(Cashier c, String criteria) {
        if (criteria.equals("")) {
            return true;
        }

        var containsName = c.getName().contains(criteria);
        var containsLastName = c.getLastName().contains(criteria);
        var containsAddress = c.getAddress().contains(criteria);
        var containsCode = c.getCode().contains(criteria);
        var containsIdentification = c.getIdentification().contains(criteria);

        return containsName || containsLastName || containsAddress || containsCode || containsIdentification;
    }
}
