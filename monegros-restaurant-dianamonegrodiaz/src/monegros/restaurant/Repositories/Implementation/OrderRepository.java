package monegros.restaurant.entities.repository.implementation;

import monegros.restaurant.entities.Order;
import monegros.restaurant.entities.repository.IOrderRepository;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class OrderRepository implements IOrderRepository {
    private final Set<Order> myOrders = new HashSet<>();

    @Override
    public Optional<Order> insert(Order order) {
        order.setId(Instant.now().toEpochMilli());
        this.myOrders.add(order);
        
        return Optional.of(order);
    }

    @Override
    public Optional<Order> update(Order order) {
    	Order existing = myOrders.stream()
                .filter(c -> c.equals(order))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Order you are trying to update does not exist"));

        existing.setCashier(order.getCashier());
        existing.setClient(order.getClient());
        existing.setOrderDetails(order.getOrderDetails());
        existing.setTotalAmount(order.getTotalAmount());
        existing.setTransactionDate(order.getTransactionDate());

        return Optional.of(existing);
    }
    @Override
    public Optional<Order> findById(Long id) {
    	Order existing = myOrders.stream()
                    .filter(c -> c.getId().equals(id))
                    .findFirst()
                    .orElseThrow(() -> new IllegalArgumentException("The Order you are trying to find does not exist"));

            return Optional.of(existing);
        
    }

    @Override
    public Optional<Boolean> delete(Long id) {
    	Order orderToDelete = new Order(id);
        myOrders.removeIf(c -> c.equals(orderToDelete));

        return Optional.of(Boolean.TRUE);
    }
}
