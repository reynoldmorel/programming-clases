package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.OrderDetail;
import monegros.restaurant.entities.repository.IOrderDetailRepository;

public class OrderDetailRepository implements IOrderDetailRepository{
	private final Set<OrderDetail> myOrderDetail = new HashSet<>();

    @Override
    public Optional<OrderDetail> insert(OrderDetail orderDetail) {
        orderDetail.setId(Instant.now().toEpochMilli());
        this.myOrderDetail.add(orderDetail);
        
        return Optional.of(orderDetail);
    }
    @Override
    public Optional<OrderDetail> update(OrderDetail orderDetail) {
    	OrderDetail existing = myOrderDetail.stream()
                .filter(c -> c.equals(orderDetail))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Order Detail you are trying to update does not exist"));

        existing.setOrder(orderDetail.getOrder());
        existing.setPrice(orderDetail.getPrice());
        existing.setProduct(orderDetail.getProduct());
        existing.setQuantity(orderDetail.getQuantity());
        
        return Optional.of(existing);
    }
    @Override
    public Optional<OrderDetail> findById(Long id) {
    	OrderDetail existing = myOrderDetail.stream()
                    .filter(c -> c.getId().equals(id))
                    .findFirst()
                    .orElseThrow(() -> new IllegalArgumentException("The Order Detail you are trying to find does not exist"));

            return Optional.of(existing);
    }

    @Override
    public Optional<Boolean> delete(Long id) {
    	OrderDetail orderDetailToDelete = new OrderDetail(id);
        myOrderDetail.removeIf(c -> c.equals(orderDetailToDelete));

        return Optional.of(Boolean.TRUE);
    }
}
