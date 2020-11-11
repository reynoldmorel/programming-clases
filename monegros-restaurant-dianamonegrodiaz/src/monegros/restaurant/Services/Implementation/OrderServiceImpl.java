package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Order;
import monegros.restaurant.entities.repository.IOrderRepository;
import monegros.restaurant.services.interfaces.IOrderService;

public class OrderServiceImpl implements IOrderService{
	private final IOrderRepository orderRepository;
	
	public OrderServiceImpl(IOrderRepository orderRepository) {
		this.orderRepository=orderRepository;
	}
	@Override
	public Optional<Order> insert(Order order) {
		return this.orderRepository.insert(order);
	}
	@Override
	public Optional<Order> findById(Long id) {
		return this.orderRepository.findById(id);
	}
}
