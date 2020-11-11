package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.OrderDetail;
import monegros.restaurant.entities.repository.IOrderDetailRepository;
import monegros.restaurant.services.interfaces.IOrderDetailService;

public class OrderDetailServiceImpl implements IOrderDetailService{
private final IOrderDetailRepository orderDetailRepository;
	
	public OrderDetailServiceImpl(IOrderDetailRepository orderDetailRepository) {
		this.orderDetailRepository=orderDetailRepository;
	}
	@Override
	public Optional<OrderDetail> insert(OrderDetail orderDetail) {
		return this.orderDetailRepository.insert(orderDetail);
	}
	@Override
	public Optional<OrderDetail> findById(Long id) {
		return this.orderDetailRepository.findById(id);
	}
}
