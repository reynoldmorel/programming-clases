package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.OrderDetail;

public interface IOrderDetailService {
	Optional<OrderDetail> insert(OrderDetail orderDetail);

	Optional<OrderDetail> findById(Long id);
}
