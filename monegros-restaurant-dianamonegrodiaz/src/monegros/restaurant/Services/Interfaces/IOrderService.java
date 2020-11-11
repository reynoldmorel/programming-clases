package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Order;

public interface IOrderService {
	Optional<Order> insert(Order order);

	Optional<Order> findById(Long id);
}
