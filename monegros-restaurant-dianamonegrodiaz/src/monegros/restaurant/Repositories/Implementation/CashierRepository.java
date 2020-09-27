package monegros.restaurant.entities.repository.implementation;

import monegros.restaurant.entities.Cashier;
import monegros.restaurant.entities.repository.ICashierRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

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
        Cashier existing = cashierStore.stream()
                .filter(c -> c.equals(cashier))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The cashier you are trying to update does not exist"));

        existing.setAddress(cashier.getAddress());
        existing.setAge(cashier.getAge());
        existing.setName(cashier.getName());
        existing.setLastName(cashier.getLastName());
        existing.setPhone(cashier.getPhone());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        Cashier cashierToDelete = new Cashier(id);
        cashierStore.removeIf(c -> c.equals(cashierToDelete));

        return Optional.of(Boolean.TRUE);
    }
    public Optional<Cashier> findById(Long id) {

    	Cashier existing = cashierStore.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The cashier you are trying to find does not exist"));

        return Optional.of(existing);
    }

}
