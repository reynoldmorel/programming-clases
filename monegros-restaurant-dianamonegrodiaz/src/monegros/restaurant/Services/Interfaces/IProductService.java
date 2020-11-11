package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Product;

public interface IProductService {
	Optional<Product> insert(Product product);
	Optional<Product> findById(Long id);
}
